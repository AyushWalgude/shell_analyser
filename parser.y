/* =====================================================================
 *  parser.y  -  Syntax Analyser (Parser) for a Shell Scripting Language
 *  Tool      :  Bison (win_bison on Windows)
 *  Grammar   :  simplified POSIX/Bash shell grammar (LALR(1))
 * ===================================================================== */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  yylex(void);
void yyerror(const char *msg);

/* shared with lexer.l */
extern int   token_mode, lex_errors, tok_line, var_count;
extern long  tok_count;
extern char *var_names[];
extern int   yylineno;

typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string(const char *str);
extern void yy_delete_buffer(YY_BUFFER_STATE b);

/* ---------- statistics + optional parse trace ---------- */
static int verbose = 0;
static int n_simple, n_pipe, n_andor, n_if, n_while, n_until, n_for, n_case,
           n_func, n_subshell, n_group, n_test, n_assign, n_redir, n_cmdsub;

#define RULE(counter, msg) do { counter++; \
        if (verbose) printf("  [line %-3d] %s\n", tok_line, msg); } while (0)
%}

%define parse.error verbose

/* ---------------- tokens (string aliases give readable errors) ---------------- */
%token WORD "word"  NUMBER "number"  STRING "string"  VAR "variable"
%token BACKTICK "`command`"  ARITH "arithmetic expression"
%token ASSIGN "assignment (NAME=value)"  ASSIGN_EMPTY "assignment (NAME=)"
%token BUILTIN "builtin command"  IO_NUMBER "file descriptor"

%token IF "if"  THEN "then"  ELIF "elif"  ELSE "else"  FI "fi"
%token WHILE "while"  UNTIL "until"  FOR "for"  IN "in"  DO "do"  DONE "done"
%token CASE "case"  ESAC "esac"  FUNCTION "function"

%token AND_IF "&&"  OR_IF "||"  PIPE "|"  AMP "&"  SEMI ";"  DSEMI ";;"
%token LPAREN "("  RPAREN ")"  LBRACE "{"  RBRACE "}"  BANG "!"  NEWLINE "end of line"

%token LESS "<"  GREAT ">"  DGREAT ">>"  LESSAND "<&"  GREATAND ">&"
%token DOLLAR_LPAREN "$("
%token LBRACKET "["  RBRACKET "]"  DLBRACKET "[["  DRBRACKET "]]"
%token TEST_UNARY "unary test operator"  TEST_BINARY "binary test operator"
%token TEST_AND "-a"  TEST_OR "-o"

%start program

%%

/* ========================= top level ========================= */

program
    : linebreak
    | linebreak term
    | linebreak term separator
    ;

term
    : and_or
    | term separator and_or
    ;

and_or
    : pipeline
    | and_or AND_IF linebreak pipeline      { RULE(n_andor, "AND list  (cmd && cmd)"); }
    | and_or OR_IF  linebreak pipeline      { RULE(n_andor, "OR list   (cmd || cmd)"); }
    ;

pipeline
    : pipe_sequence
    | BANG pipe_sequence
    ;

pipe_sequence
    : command
    | pipe_sequence PIPE linebreak command  { RULE(n_pipe, "pipeline  (cmd | cmd)"); }
    ;

command
    : simple_command
    | compound_command
    | compound_command redirect_list
    | function_def
    | test_command
    ;

compound_command
    : brace_group
    | subshell
    | for_clause
    | while_clause
    | until_clause
    | if_clause
    | case_clause
    ;

/* ========================= lists ========================= */

compound_list
    : linebreak term
    | linebreak term separator
    ;

subshell
    : LPAREN compound_list RPAREN           { RULE(n_subshell, "subshell  ( ... )"); }
    ;

brace_group
    : LBRACE compound_list RBRACE           { RULE(n_group, "command group  { ...; }"); }
    ;

do_group
    : DO compound_list DONE
    ;

/* ========================= control structures ========================= */

for_clause
    : FOR name do_group                                       { RULE(n_for, "for loop"); }
    | FOR name sequential_sep do_group                        { RULE(n_for, "for loop"); }
    | FOR name linebreak IN sequential_sep do_group           { RULE(n_for, "for loop (empty list)"); }
    | FOR name linebreak IN wordlist sequential_sep do_group  { RULE(n_for, "for ... in loop"); }
    ;

name
    : WORD
    ;

wordlist
    : word
    | wordlist word
    ;

while_clause
    : WHILE compound_list do_group          { RULE(n_while, "while loop"); }
    ;

until_clause
    : UNTIL compound_list do_group          { RULE(n_until, "until loop"); }
    ;

if_clause
    : IF compound_list THEN compound_list else_part FI   { RULE(n_if, "if / elif / else statement"); }
    | IF compound_list THEN compound_list FI             { RULE(n_if, "if statement"); }
    ;

else_part
    : ELIF compound_list THEN compound_list
    | ELIF compound_list THEN compound_list else_part
    | ELSE compound_list
    ;

case_clause
    : CASE word linebreak IN linebreak case_list    ESAC   { RULE(n_case, "case statement"); }
    | CASE word linebreak IN linebreak case_list_ns ESAC   { RULE(n_case, "case statement"); }
    | CASE word linebreak IN linebreak              ESAC   { RULE(n_case, "case statement (no branches)"); }
    ;

case_list_ns
    : case_list case_item_ns
    | case_item_ns
    ;

case_list
    : case_list case_item
    | case_item
    ;

case_item_ns
    : pattern RPAREN linebreak
    | pattern RPAREN compound_list
    ;

case_item
    : pattern RPAREN linebreak DSEMI linebreak
    | pattern RPAREN compound_list DSEMI linebreak
    ;

pattern
    : word
    | pattern PIPE word
    ;

/* ========================= functions ========================= */

function_def
    : WORD LPAREN RPAREN linebreak compound_command                { RULE(n_func, "function definition  name() { }"); }
    | FUNCTION WORD linebreak brace_group                           { RULE(n_func, "function definition  function name { }"); }
    | FUNCTION WORD LPAREN RPAREN linebreak compound_command       { RULE(n_func, "function definition  function name() { }"); }
    ;

/* ========================= test expressions  [ ... ]  [[ ... ]] ========================= */

test_command
    : LBRACKET  test_expr RBRACKET          { RULE(n_test, "test expression  [ ... ]"); }
    | DLBRACKET test_expr DRBRACKET         { RULE(n_test, "test expression  [[ ... ]]"); }
    ;

test_expr
    : test_and
    | test_expr OR_IF  test_and
    | test_expr TEST_OR test_and
    ;

test_and
    : test_not
    | test_and AND_IF  test_not
    | test_and TEST_AND test_not
    ;

test_not
    : test_primary
    | BANG test_primary
    ;

test_primary
    : word
    | TEST_UNARY word
    | word TEST_BINARY word
    | LPAREN test_expr RPAREN
    ;

/* ========================= simple commands ========================= */

simple_command
    : cmd_prefix cmd_name cmd_suffix        { RULE(n_simple, "simple command (with prefix and arguments)"); }
    | cmd_prefix cmd_name                   { RULE(n_simple, "simple command (with prefix)"); }
    | cmd_prefix                            { RULE(n_simple, "assignment statement"); }
    | cmd_name cmd_suffix                   { RULE(n_simple, "simple command with arguments"); }
    | cmd_name                              { RULE(n_simple, "simple command"); }
    ;

cmd_name
    : word
    ;

cmd_prefix
    : io_redirect
    | assignment
    | cmd_prefix io_redirect
    | cmd_prefix assignment
    ;

cmd_suffix
    : io_redirect
    | assignment
    | word
    | cmd_suffix io_redirect
    | cmd_suffix assignment
    | cmd_suffix word
    ;

assignment
    : ASSIGN word                           { RULE(n_assign, "variable assignment"); }
    | ASSIGN_EMPTY                          { RULE(n_assign, "variable assignment (empty value)"); }
    ;

word
    : WORD
    | NUMBER
    | STRING
    | VAR
    | BUILTIN
    | BACKTICK
    | ARITH
    | cmdsub
    ;

cmdsub
    : DOLLAR_LPAREN compound_list RPAREN    { RULE(n_cmdsub, "command substitution  $( ... )"); }
    ;

/* ========================= redirections ========================= */

redirect_list
    : io_redirect
    | redirect_list io_redirect
    ;

io_redirect
    : io_file
    | IO_NUMBER io_file
    ;

io_file
    : LESS     word     { RULE(n_redir, "input redirection  <"); }
    | GREAT    word     { RULE(n_redir, "output redirection  >"); }
    | DGREAT   word     { RULE(n_redir, "append redirection  >>"); }
    | LESSAND  word     { RULE(n_redir, "input fd duplication  <&"); }
    | GREATAND word     { RULE(n_redir, "output fd duplication  >&"); }
    ;

/* ========================= separators ========================= */

newline_list
    : NEWLINE
    | newline_list NEWLINE
    ;

linebreak
    : %empty
    | newline_list
    ;

separator_op
    : AMP
    | SEMI
    ;

separator
    : separator_op linebreak
    | newline_list
    ;

sequential_sep
    : SEMI linebreak
    | newline_list
    ;

%%

/* ===================================================================== */

void yyerror(const char *msg)
{
    fprintf(stderr, "Syntax error at line %d: %s\n", tok_line, msg);
}

static char *read_file(const char *path)
{
    FILE *fp = fopen(path, "rb");
    long size; char *buf;
    if (!fp) return NULL;
    fseek(fp, 0, SEEK_END);  size = ftell(fp);  rewind(fp);
    buf = (char *)malloc(size + 2);
    if (!buf) { fclose(fp); return NULL; }
    size = (long)fread(buf, 1, size, fp);
    buf[size] = '\n';            /* guarantee a trailing newline */
    buf[size + 1] = '\0';
    fclose(fp);
    return buf;
}

static void print_variables(void)
{
    int i;
    printf("\nVariables assigned (%d):", var_count);
    if (var_count == 0) printf(" none");
    for (i = 0; i < var_count; i++) printf(" %s", var_names[i]);
    printf("\n");
}

static void print_summary(void)
{
    printf("\n---------------- Parse summary ----------------\n");
    printf(" simple commands    : %d\n", n_simple);
    printf(" assignments        : %d\n", n_assign);
    printf(" pipelines (|)      : %d\n", n_pipe);
    printf(" && / || lists      : %d\n", n_andor);
    printf(" if statements      : %d\n", n_if);
    printf(" while / until      : %d / %d\n", n_while, n_until);
    printf(" for loops          : %d\n", n_for);
    printf(" case statements    : %d\n", n_case);
    printf(" functions          : %d\n", n_func);
    printf(" test expressions   : %d\n", n_test);
    printf(" subshells / groups : %d / %d\n", n_subshell, n_group);
    printf(" command substs     : %d\n", n_cmdsub);
    printf(" redirections       : %d\n", n_redir);
    printf(" total tokens       : %ld\n", tok_count);
    print_variables();
}

static void usage(const char *prog)
{
    fprintf(stderr,
        "Usage: %s [-t] [-v] script.sh\n"
        "  -t   lexer only: print the token table\n"
        "  -v   parser: print every grammar construct recognised\n", prog);
}

int main(int argc, char **argv)
{
    const char *file = NULL;
    char *src;
    int i, rc;
    YY_BUFFER_STATE buf;

    for (i = 1; i < argc; i++) {
        if      (strcmp(argv[i], "-t") == 0) token_mode = 1;
        else if (strcmp(argv[i], "-v") == 0) verbose = 1;
        else if (argv[i][0] == '-')          { usage(argv[0]); return 2; }
        else                                 file = argv[i];
    }
    if (!file) { usage(argv[0]); return 2; }

    src = read_file(file);
    if (!src) { fprintf(stderr, "Cannot open file: %s\n", file); return 2; }

    buf = yy_scan_string(src);

    if (token_mode) {
        printf("%-5s %-14s %s\n", "LINE", "TOKEN TYPE", "LEXEME");
        printf("--------------------------------------------\n");
        while (yylex() != 0) { }
        printf("--------------------------------------------\n");
        printf("Total tokens: %ld   Lexical errors: %d\n", tok_count, lex_errors);
        print_variables();
        rc = lex_errors ? 1 : 0;
    } else {
        rc = yyparse();
        if (rc == 0 && lex_errors == 0) {
            printf("RESULT: %s -> syntax is VALID\n", file);
            print_summary();
        } else {
            printf("RESULT: %s -> syntax is INVALID (%d lexical error(s))\n", file, lex_errors);
            rc = 1;
        }
    }
    yy_delete_buffer(buf);
    free(src);
    return rc;
}
