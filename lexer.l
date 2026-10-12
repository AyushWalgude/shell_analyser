/* =====================================================================
 *  lexer.l  -  Lexical Analyser for a Shell Scripting Language (Bash subset)
 *  Tool     :  Flex (win_flex on Windows)
 * ===================================================================== */

%option noyywrap nounistd never-interactive yylineno
%s TEST

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

/* ---------- globals shared with parser.y ---------- */
int  token_mode = 0;      /* 1 => print every token (lexer-only mode)   */
int  lex_errors = 0;      /* number of lexical errors found             */
int  tok_line   = 1;      /* line on which the current token STARTS     */
long tok_count  = 0;      /* total tokens produced                      */

#define MAX_VARS 512
char *var_names[MAX_VARS];  /* "symbol table" of assigned variables     */
int   var_count = 0;

static void add_var(const char *text, int len)
{
    int i;
    for (i = 0; i < var_count; i++)
        if ((int)strlen(var_names[i]) == len && strncmp(var_names[i], text, len) == 0)
            return;
    if (var_count < MAX_VARS) {
        var_names[var_count] = (char *)malloc(len + 1);
        memcpy(var_names[var_count], text, len);
        var_names[var_count][len] = '\0';
        var_count++;
    }
}

/* record token start line (multi-line strings advance yylineno) */
static void mark_line(void)
{
    int i, nl = 0;
    for (i = 0; i < yyleng; i++) if (yytext[i] == '\n') nl++;
    tok_line = yylineno - nl;
}

static int emit(int tok, const char *category)
{
    mark_line();
    tok_count++;
    if (token_mode) {
        char buf[80]; int i, j = 0;
        for (i = 0; yytext[i] && j < 60; i++) {
            if (yytext[i] == '\n')      { buf[j++] = '\\'; buf[j++] = 'n'; }
            else if (yytext[i] == '\t') { buf[j++] = '\\'; buf[j++] = 't'; }
            else                          buf[j++] = yytext[i];
        }
        buf[j] = '\0';
        printf("%-5d %-14s %s\n", tok_line, category, buf);
    }
    return tok;
}

static void lex_error(const char *msg)
{
    mark_line();
    lex_errors++;
    fprintf(stderr, "Lexical error at line %d: %s ('%s')\n", tok_line, msg, yytext);
    if (token_mode) printf("%-5d %-14s %s\n", tok_line, "ERROR", msg);
}

#define T(tok, cat)  return emit(tok, cat)
%}

ID        [A-Za-z_][A-Za-z0-9_]*
WORDCH    [A-Za-z0-9_./~*?:@%+,^-]

%%

[ \t\r]+                    { /* skip blanks (\r handles Windows CRLF) */ }
\\\r?\n                     { /* line continuation */ }
"#"[^\n]*                   { /* comment */ }
\n                          { T(NEWLINE, "NEWLINE"); }

 /* ---------------- reserved words ---------------- */
"if"                        { T(IF,       "KEYWORD"); }
"then"                      { T(THEN,     "KEYWORD"); }
"elif"                      { T(ELIF,     "KEYWORD"); }
"else"                      { T(ELSE,     "KEYWORD"); }
"fi"                        { T(FI,       "KEYWORD"); }
"while"                     { T(WHILE,    "KEYWORD"); }
"until"                     { T(UNTIL,    "KEYWORD"); }
"for"                       { T(FOR,      "KEYWORD"); }
"in"                        { T(IN,       "KEYWORD"); }
"do"                        { T(DO,       "KEYWORD"); }
"done"                      { T(DONE,     "KEYWORD"); }
"case"                      { T(CASE,     "KEYWORD"); }
"esac"                      { T(ESAC,     "KEYWORD"); }
"function"                  { T(FUNCTION, "KEYWORD"); }

 /* ---------------- built-in commands ---------------- */
"echo"|"printf"|"read"|"cd"|"pwd"|"export"|"unset"|"local"|"declare"|"readonly"|"shift"|"exit"|"return"|"break"|"continue"|"source"|"eval"|"exec"|"set"|"trap"|"wait"|"alias"|"unalias"|"test" {
                              T(BUILTIN, "BUILTIN"); }

 /* ---------------- test-expression operators (only inside [ ] / [[ ]]) ---------------- */
<TEST>"-"(eq|ne|lt|gt|le|ge|nt|ot|ef)   { T(TEST_BINARY, "TEST_OP"); }
<TEST>"=="|"!="|"=~"|"="|"<"|">"        { T(TEST_BINARY, "TEST_OP"); }
<TEST>"-"[zn]|"-"[fdeLrwxsbcpSugkOGN]   { T(TEST_UNARY,  "TEST_OP"); }
<TEST>"-a"                              { T(TEST_AND,    "TEST_OP"); }
<TEST>"-o"                              { T(TEST_OR,     "TEST_OP"); }
<TEST>"]]"                              { BEGIN(INITIAL); T(DRBRACKET, "BRACKET"); }
<TEST>"]"                               { BEGIN(INITIAL); T(RBRACKET,  "BRACKET"); }

"[["/[ \t\r\n]              { BEGIN(TEST); T(DLBRACKET, "BRACKET"); }
"["/[ \t\r\n]               { BEGIN(TEST); T(LBRACKET,  "BRACKET"); }

 /* ---------------- assignments  NAME=value ---------------- */
{ID}"="/[^ \t\r\n;|&)]      { add_var(yytext, yyleng - 1); T(ASSIGN,       "ASSIGN"); }
{ID}"="/[ \t\r\n;|&)]       { add_var(yytext, yyleng - 1); T(ASSIGN_EMPTY, "ASSIGN"); }

 /* ---------------- numbers / file descriptors ---------------- */
[0-9]+/[<>]                 { T(IO_NUMBER, "IO_NUMBER"); }
[0-9]+                      { T(NUMBER,    "NUMBER"); }

 /* ---------------- variables and substitutions ---------------- */
"$"{ID}                     { T(VAR, "VARIABLE"); }
"${"[^}\n]*"}"              { T(VAR, "VARIABLE"); }
"$"[?#@*!$0-9]              { T(VAR, "VARIABLE"); }
"$(("([^)]|\)[^)])*"))"     { T(ARITH, "ARITHMETIC"); }
"(("([^)]|\)[^)])*"))"      { T(ARITH, "ARITHMETIC"); }
"$("                        { T(DOLLAR_LPAREN, "CMD_SUBST"); }
`[^`]*`                     { T(BACKTICK, "CMD_SUBST"); }

 /* ---------------- strings ---------------- */
\"([^\"\\]|\\(.|\n))*\"     { T(STRING, "STRING"); }
'[^']*'                     { T(STRING, "STRING"); }
\"                          { lex_error("unterminated double-quoted string"); }
'                           { lex_error("unterminated single-quoted string"); }
`                           { lex_error("unterminated backquote"); }

 /* ---------------- operators ---------------- */
"&&"                        { T(AND_IF,   "OPERATOR"); }
"||"                        { T(OR_IF,    "OPERATOR"); }
"|"                         { T(PIPE,     "OPERATOR"); }
"&"                         { T(AMP,      "OPERATOR"); }
";;"                        { T(DSEMI,    "OPERATOR"); }
";"                         { T(SEMI,     "OPERATOR"); }
"("                         { T(LPAREN,   "OPERATOR"); }
")"                         { T(RPAREN,   "OPERATOR"); }
"{"/[ \t\r\n]               { T(LBRACE,   "OPERATOR"); }
"}"                         { T(RBRACE,   "OPERATOR"); }
"!"                         { T(BANG,     "OPERATOR"); }

 /* ---------------- redirections ---------------- */
">>"                        { T(DGREAT,   "REDIRECT"); }
">&"                        { T(GREATAND, "REDIRECT"); }
"<&"                        { T(LESSAND,  "REDIRECT"); }
">"                         { T(GREAT,    "REDIRECT"); }
"<"                         { T(LESS,     "REDIRECT"); }
"<<"|"<<-"|"<<<"            { lex_error("here-documents / here-strings are not supported"); }

 /* ---------------- words ---------------- */
"-"{1,2}[A-Za-z][A-Za-z0-9_-]*"="[^ \t\r\n;|&()<>]*   { T(WORD, "WORD"); }
({WORDCH}|\\.)+             { T(WORD, "WORD"); }

.                           { lex_error("illegal character"); }

%%
