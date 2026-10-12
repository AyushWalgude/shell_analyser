/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "parser.y"

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

#line 98 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_WORD = 3,                       /* "word"  */
  YYSYMBOL_NUMBER = 4,                     /* "number"  */
  YYSYMBOL_STRING = 5,                     /* "string"  */
  YYSYMBOL_VAR = 6,                        /* "variable"  */
  YYSYMBOL_BACKTICK = 7,                   /* "`command`"  */
  YYSYMBOL_ARITH = 8,                      /* "arithmetic expression"  */
  YYSYMBOL_ASSIGN = 9,                     /* "assignment (NAME=value)"  */
  YYSYMBOL_ASSIGN_EMPTY = 10,              /* "assignment (NAME=)"  */
  YYSYMBOL_BUILTIN = 11,                   /* "builtin command"  */
  YYSYMBOL_IO_NUMBER = 12,                 /* "file descriptor"  */
  YYSYMBOL_IF = 13,                        /* "if"  */
  YYSYMBOL_THEN = 14,                      /* "then"  */
  YYSYMBOL_ELIF = 15,                      /* "elif"  */
  YYSYMBOL_ELSE = 16,                      /* "else"  */
  YYSYMBOL_FI = 17,                        /* "fi"  */
  YYSYMBOL_WHILE = 18,                     /* "while"  */
  YYSYMBOL_UNTIL = 19,                     /* "until"  */
  YYSYMBOL_FOR = 20,                       /* "for"  */
  YYSYMBOL_IN = 21,                        /* "in"  */
  YYSYMBOL_DO = 22,                        /* "do"  */
  YYSYMBOL_DONE = 23,                      /* "done"  */
  YYSYMBOL_CASE = 24,                      /* "case"  */
  YYSYMBOL_ESAC = 25,                      /* "esac"  */
  YYSYMBOL_FUNCTION = 26,                  /* "function"  */
  YYSYMBOL_AND_IF = 27,                    /* "&&"  */
  YYSYMBOL_OR_IF = 28,                     /* "||"  */
  YYSYMBOL_PIPE = 29,                      /* "|"  */
  YYSYMBOL_AMP = 30,                       /* "&"  */
  YYSYMBOL_SEMI = 31,                      /* ";"  */
  YYSYMBOL_DSEMI = 32,                     /* ";;"  */
  YYSYMBOL_LPAREN = 33,                    /* "("  */
  YYSYMBOL_RPAREN = 34,                    /* ")"  */
  YYSYMBOL_LBRACE = 35,                    /* "{"  */
  YYSYMBOL_RBRACE = 36,                    /* "}"  */
  YYSYMBOL_BANG = 37,                      /* "!"  */
  YYSYMBOL_NEWLINE = 38,                   /* "end of line"  */
  YYSYMBOL_LESS = 39,                      /* "<"  */
  YYSYMBOL_GREAT = 40,                     /* ">"  */
  YYSYMBOL_DGREAT = 41,                    /* ">>"  */
  YYSYMBOL_LESSAND = 42,                   /* "<&"  */
  YYSYMBOL_GREATAND = 43,                  /* ">&"  */
  YYSYMBOL_DOLLAR_LPAREN = 44,             /* "$("  */
  YYSYMBOL_LBRACKET = 45,                  /* "["  */
  YYSYMBOL_RBRACKET = 46,                  /* "]"  */
  YYSYMBOL_DLBRACKET = 47,                 /* "[["  */
  YYSYMBOL_DRBRACKET = 48,                 /* "]]"  */
  YYSYMBOL_TEST_UNARY = 49,                /* "unary test operator"  */
  YYSYMBOL_TEST_BINARY = 50,               /* "binary test operator"  */
  YYSYMBOL_TEST_AND = 51,                  /* "-a"  */
  YYSYMBOL_TEST_OR = 52,                   /* "-o"  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_program = 54,                   /* program  */
  YYSYMBOL_term = 55,                      /* term  */
  YYSYMBOL_and_or = 56,                    /* and_or  */
  YYSYMBOL_pipeline = 57,                  /* pipeline  */
  YYSYMBOL_pipe_sequence = 58,             /* pipe_sequence  */
  YYSYMBOL_command = 59,                   /* command  */
  YYSYMBOL_compound_command = 60,          /* compound_command  */
  YYSYMBOL_compound_list = 61,             /* compound_list  */
  YYSYMBOL_subshell = 62,                  /* subshell  */
  YYSYMBOL_brace_group = 63,               /* brace_group  */
  YYSYMBOL_do_group = 64,                  /* do_group  */
  YYSYMBOL_for_clause = 65,                /* for_clause  */
  YYSYMBOL_name = 66,                      /* name  */
  YYSYMBOL_wordlist = 67,                  /* wordlist  */
  YYSYMBOL_while_clause = 68,              /* while_clause  */
  YYSYMBOL_until_clause = 69,              /* until_clause  */
  YYSYMBOL_if_clause = 70,                 /* if_clause  */
  YYSYMBOL_else_part = 71,                 /* else_part  */
  YYSYMBOL_case_clause = 72,               /* case_clause  */
  YYSYMBOL_case_list_ns = 73,              /* case_list_ns  */
  YYSYMBOL_case_list = 74,                 /* case_list  */
  YYSYMBOL_case_item_ns = 75,              /* case_item_ns  */
  YYSYMBOL_case_item = 76,                 /* case_item  */
  YYSYMBOL_pattern = 77,                   /* pattern  */
  YYSYMBOL_function_def = 78,              /* function_def  */
  YYSYMBOL_test_command = 79,              /* test_command  */
  YYSYMBOL_test_expr = 80,                 /* test_expr  */
  YYSYMBOL_test_and = 81,                  /* test_and  */
  YYSYMBOL_test_not = 82,                  /* test_not  */
  YYSYMBOL_test_primary = 83,              /* test_primary  */
  YYSYMBOL_simple_command = 84,            /* simple_command  */
  YYSYMBOL_cmd_name = 85,                  /* cmd_name  */
  YYSYMBOL_cmd_prefix = 86,                /* cmd_prefix  */
  YYSYMBOL_cmd_suffix = 87,                /* cmd_suffix  */
  YYSYMBOL_assignment = 88,                /* assignment  */
  YYSYMBOL_word = 89,                      /* word  */
  YYSYMBOL_cmdsub = 90,                    /* cmdsub  */
  YYSYMBOL_redirect_list = 91,             /* redirect_list  */
  YYSYMBOL_io_redirect = 92,               /* io_redirect  */
  YYSYMBOL_io_file = 93,                   /* io_file  */
  YYSYMBOL_newline_list = 94,              /* newline_list  */
  YYSYMBOL_linebreak = 95,                 /* linebreak  */
  YYSYMBOL_separator_op = 96,              /* separator_op  */
  YYSYMBOL_separator = 97,                 /* separator  */
  YYSYMBOL_sequential_sep = 98             /* sequential_sep  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   400

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    63,    64,    68,    69,    73,    74,    75,
      79,    80,    84,    85,    89,    90,    91,    92,    93,    97,
      98,    99,   100,   101,   102,   103,   109,   110,   114,   118,
     122,   128,   129,   130,   131,   135,   139,   140,   144,   148,
     152,   153,   157,   158,   159,   163,   164,   165,   169,   170,
     174,   175,   179,   180,   184,   185,   189,   190,   196,   197,
     198,   204,   205,   209,   210,   211,   215,   216,   217,   221,
     222,   226,   227,   228,   229,   235,   236,   237,   238,   239,
     243,   247,   248,   249,   250,   254,   255,   256,   257,   258,
     259,   263,   264,   268,   269,   270,   271,   272,   273,   274,
     275,   279,   285,   286,   290,   291,   295,   296,   297,   298,
     299,   305,   306,   310,   311,   315,   316,   320,   321,   325,
     326
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"word\"",
  "\"number\"", "\"string\"", "\"variable\"", "\"`command`\"",
  "\"arithmetic expression\"", "\"assignment (NAME=value)\"",
  "\"assignment (NAME=)\"", "\"builtin command\"", "\"file descriptor\"",
  "\"if\"", "\"then\"", "\"elif\"", "\"else\"", "\"fi\"", "\"while\"",
  "\"until\"", "\"for\"", "\"in\"", "\"do\"", "\"done\"", "\"case\"",
  "\"esac\"", "\"function\"", "\"&&\"", "\"||\"", "\"|\"", "\"&\"",
  "\";\"", "\";;\"", "\"(\"", "\")\"", "\"{\"", "\"}\"", "\"!\"",
  "\"end of line\"", "\"<\"", "\">\"", "\">>\"", "\"<&\"", "\">&\"",
  "\"$(\"", "\"[\"", "\"]\"", "\"[[\"", "\"]]\"",
  "\"unary test operator\"", "\"binary test operator\"", "\"-a\"",
  "\"-o\"", "$accept", "program", "term", "and_or", "pipeline",
  "pipe_sequence", "command", "compound_command", "compound_list",
  "subshell", "brace_group", "do_group", "for_clause", "name", "wordlist",
  "while_clause", "until_clause", "if_clause", "else_part", "case_clause",
  "case_list_ns", "case_list", "case_item_ns", "case_item", "pattern",
  "function_def", "test_command", "test_expr", "test_and", "test_not",
  "test_primary", "simple_command", "cmd_name", "cmd_prefix", "cmd_suffix",
  "assignment", "word", "cmdsub", "redirect_list", "io_redirect",
  "io_file", "newline_list", "linebreak", "separator_op", "separator",
  "sequential_sep", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
#endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-121)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -32,  -135,    25,    -7,   246,  -135,  -135,     9,  -135,  -135,
    -135,  -135,  -135,   148,  -135,  -135,   234,   -32,   -32,   -32,
      32,   148,    36,   -32,   -32,   291,   148,   148,   148,   148,
     148,   -32,    75,    75,    58,   -11,  -135,    42,  -135,     6,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
     336,   336,  -135,  -135,  -135,  -135,  -135,    31,  -135,  -135,
    -135,    61,   246,    63,    63,  -135,    39,   -32,    64,    71,
      97,    42,  -135,  -135,  -135,  -135,  -135,    73,    75,   124,
     148,    -9,    11,  -135,  -135,    91,     2,  -135,  -135,    -7,
     -32,   246,   -32,   -32,   -32,     6,  -135,   336,  -135,  -135,
    -135,   336,  -135,  -135,   -32,   -32,    58,   -32,  -135,  -135,
     -32,  -135,    62,    90,    63,   137,   129,   130,  -135,  -135,
    -135,    35,  -135,  -135,    75,  -135,    75,    75,    75,   148,
    -135,  -135,   -11,   246,   246,   291,  -135,  -135,  -135,  -135,
     336,   204,   122,   246,   143,  -135,   139,  -135,   -32,   -32,
    -135,  -135,    11,    11,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,   -32,   -32,  -135,   150,  -135,   139,  -135,    -7,    63,
     346,   204,   155,  -135,  -135,  -135,    63,  -135,  -135,   151,
     356,  -135,  -135,    80,  -135,  -135,   -32,  -135,  -135,  -135,
    -135,  -135,   148,   -32,    37,  -135,   146,   201,  -135,   -32,
     -32,  -135,  -135
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
     113,   111,     0,   114,     2,     1,   112,    93,    94,    95,
      96,    98,    99,     0,    92,    97,     0,   113,   113,   113,
       0,     0,     0,   113,   113,     0,     0,     0,     0,     0,
       0,   113,     0,     0,     3,     5,     7,    10,    12,    15,
      20,    19,    21,    22,    23,    24,    25,    17,    18,    14,
      79,    77,    82,    80,   100,    81,   104,     0,    93,    91,
     105,     0,     0,     0,     0,    35,   113,   113,   113,     0,
       0,    11,   106,   107,   108,   109,   110,     0,     0,     0,
       0,     0,    63,    66,    69,    71,     0,   115,   116,   118,
     113,     4,   113,   113,   113,    16,   102,    78,    86,    87,
      85,    76,    84,    83,   113,   113,    26,   113,    38,    39,
     113,    31,   114,     0,     0,     0,     0,     0,    28,    29,
     101,     0,    70,    72,     0,    61,     0,     0,     0,     0,
      62,   117,     6,     0,     0,     0,   103,    89,    90,    88,
      75,     0,     0,    27,     0,   119,     0,    32,   113,   113,
      59,    74,    64,    65,    67,    68,    73,     8,     9,    13,
      58,   113,   113,    41,     0,    30,     0,    36,   120,     0,
       0,     0,     0,    44,    40,    37,     0,    33,    47,     0,
       0,    49,    51,     0,    56,    60,   113,    34,    46,    45,
      48,    50,     0,   113,    42,    57,    53,    52,    43,   113,
     113,    55,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,   171,   -86,    -8,   154,    45,  -131,    10,  -135,
      65,   -63,  -135,  -135,  -135,  -135,  -135,  -135,   -13,  -135,
    -135,  -135,     4,     5,  -135,  -135,  -135,   -22,   -25,    34,
     108,  -135,   138,  -135,    87,   -42,    -6,  -135,  -135,   -37,
     174,   -30,     0,  -135,    85,  -134
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   106,    35,    36,    37,    38,    39,    61,    40,
      41,   108,    42,    66,   166,    43,    44,    45,   164,    46,
     179,   180,   181,   182,   183,    47,    48,    81,    82,    83,
      84,    49,    50,    51,    97,    52,    53,    54,    95,    55,
      56,     3,    62,    90,    91,   114
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       4,   109,    96,   111,    89,   132,     1,    59,    98,   102,
     160,    86,   169,   100,   103,    67,    92,    93,    16,   124,
      72,    73,    74,    75,    76,     5,    85,    85,    63,    64,
     124,     6,   176,    69,    70,    65,   112,   125,   127,    68,
     185,    77,    57,   126,    99,    26,    27,    28,    29,    30,
     130,   147,   161,   162,   126,   137,   121,   132,   136,    98,
     139,   107,   128,   124,   100,   104,   113,   115,   117,   151,
     110,    94,    85,    85,   123,   105,    89,     1,    58,     8,
       9,    10,    11,    12,  -120,   107,    15,   126,    87,    88,
     131,   138,   133,   134,   135,    99,     1,   116,   137,   152,
       6,   153,     1,   139,   141,   118,   177,   120,    78,   192,
     145,   146,    79,   187,   193,   142,   168,   144,    85,    31,
      85,    85,    85,   156,    80,   157,   158,    58,     8,     9,
      10,    11,    12,   119,   138,    15,   168,   161,   162,   163,
     167,   129,    58,     8,     9,    10,    11,    12,   170,   171,
      15,    58,     8,     9,    10,    11,    12,    78,   148,    15,
     175,   154,   155,   149,   184,    24,   165,   174,    31,   186,
     110,   172,   173,    80,   184,    34,   188,     1,   199,    71,
     159,   198,   150,    31,   190,   191,   195,   122,   140,   101,
      60,   143,    31,   197,     0,     0,   194,     0,     0,   201,
     202,     0,     0,   196,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     0,     0,    17,     0,    18,
      19,    20,    18,    19,    20,    21,     0,    22,    21,     0,
       0,     0,     0,   200,    23,     0,    24,    23,    25,    24,
      26,    27,    28,    29,    30,    31,    32,     0,    33,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       0,     0,     0,     0,    18,    19,    20,     0,     0,     0,
      21,     0,    22,    26,    27,    28,    29,    30,     0,    23,
       0,    24,     0,    25,     0,    26,    27,    28,    29,    30,
      31,    32,     0,    33,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     0,     0,     0,     0,    18,
      19,    20,     0,     0,     0,    21,     0,    22,     0,     0,
       0,     0,     0,     0,    23,     0,    24,     0,     0,     0,
      26,    27,    28,    29,    30,    31,    32,     0,    33,    58,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    58,
       8,     9,    10,    11,    12,     0,     0,    15,     0,    58,
       8,     9,    10,    11,    12,     0,     0,    15,     0,     0,
       0,   178,     0,     0,     0,    26,    27,    28,    29,    30,
      31,   189,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31
};

static const yytype_int16 yycheck[] =
{
       0,    64,    39,    66,    34,    91,    38,    13,    50,    51,
     141,    33,   146,    50,    51,    21,    27,    28,    12,    28,
      26,    27,    28,    29,    30,     0,    32,    33,    18,    19,
      28,    38,   166,    23,    24,     3,    66,    46,    27,     3,
     171,    31,    33,    52,    50,    39,    40,    41,    42,    43,
      48,   114,    15,    16,    52,    97,    78,   143,    95,   101,
      97,    22,    51,    28,   101,    34,    66,    67,    68,    34,
      31,    29,    78,    79,    80,    14,   106,    38,     3,     4,
       5,     6,     7,     8,    22,    22,    11,    52,    30,    31,
      90,    97,    92,    93,    94,   101,    38,    33,   140,   124,
      38,   126,    38,   140,   104,    34,   169,    34,    33,    29,
     110,    21,    37,   176,    34,   105,   146,   107,   124,    44,
     126,   127,   128,   129,    49,   133,   134,     3,     4,     5,
       6,     7,     8,    36,   140,    11,   166,    15,    16,    17,
     146,    50,     3,     4,     5,     6,     7,     8,   148,   149,
      11,     3,     4,     5,     6,     7,     8,    33,    21,    11,
     166,   127,   128,    34,   170,    35,    23,    17,    44,    14,
      31,   161,   162,    49,   180,     4,    25,    38,    32,    25,
     135,   194,   117,    44,   180,   180,   192,    79,   101,    51,
      16,   106,    44,   193,    -1,    -1,   186,    -1,    -1,   199,
     200,    -1,    -1,   193,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    13,    -1,    18,
      19,    20,    18,    19,    20,    24,    -1,    26,    24,    -1,
      -1,    -1,    -1,    32,    33,    -1,    35,    33,    37,    35,
      39,    40,    41,    42,    43,    44,    45,    -1,    47,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,
      24,    -1,    26,    39,    40,    41,    42,    43,    -1,    33,
      -1,    35,    -1,    37,    -1,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    24,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    35,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    -1,    47,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     3,
       4,     5,     6,     7,     8,    -1,    -1,    11,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    11,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    54,    94,    95,     0,    38,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    18,    19,
      20,    24,    26,    33,    35,    37,    39,    40,    41,    42,
      43,    44,    45,    47,    55,    56,    57,    58,    59,    60,
      62,    63,    65,    68,    69,    70,    72,    78,    79,    84,
      85,    86,    88,    89,    90,    92,    93,    33,     3,    89,
      93,    61,    95,    61,    61,     3,    66,    89,     3,    61,
      61,    58,    89,    89,    89,    89,    89,    61,    33,    37,
      49,    80,    81,    82,    83,    89,    80,    30,    31,    94,
      96,    97,    27,    28,    29,    91,    92,    87,    88,    89,
      92,    85,    88,    92,    34,    14,    55,    22,    64,    64,
      31,    64,    94,    95,    98,    95,    33,    95,    34,    36,
      34,    80,    83,    89,    28,    46,    52,    27,    51,    50,
      48,    95,    56,    95,    95,    95,    92,    88,    89,    92,
      87,    95,    61,    97,    61,    95,    21,    64,    21,    34,
      63,    34,    81,    81,    82,    82,    89,    57,    57,    59,
      60,    15,    16,    17,    71,    23,    67,    89,    94,    98,
      95,    95,    61,    61,    17,    89,    98,    64,    25,    73,
      74,    75,    76,    77,    89,    60,    14,    64,    25,    25,
      75,    76,    29,    34,    61,    89,    61,    95,    71,    32,
      32,    95,    95
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    54,    55,    55,    56,    56,    56,
      57,    57,    58,    58,    59,    59,    59,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    61,    61,    62,    63,
      64,    65,    65,    65,    65,    66,    67,    67,    68,    69,
      70,    70,    71,    71,    71,    72,    72,    72,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      78,    79,    79,    80,    80,    80,    81,    81,    81,    82,
      82,    83,    83,    83,    83,    84,    84,    84,    84,    84,
      85,    86,    86,    86,    86,    87,    87,    87,    87,    87,
      87,    88,    88,    89,    89,    89,    89,    89,    89,    89,
      89,    90,    91,    91,    92,    92,    93,    93,    93,    93,
      93,    94,    94,    95,    95,    96,    96,    97,    97,    98,
      98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     1,     3,     1,     4,     4,
       1,     2,     1,     4,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     3,
       3,     3,     4,     6,     7,     1,     1,     2,     3,     3,
       6,     5,     4,     5,     2,     7,     7,     6,     2,     1,
       2,     1,     3,     3,     5,     5,     1,     3,     5,     4,
       6,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       2,     1,     2,     3,     3,     3,     2,     1,     2,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     2,     1,     2,     2,     2,     2,     2,
       2,     1,     2,     0,     1,     1,     1,     2,     1,     2,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 8: /* and_or: and_or "&&" linebreak pipeline  */
#line 74 "parser.y"
                                            { RULE(n_andor, "AND list  (cmd && cmd)"); }
#line 1647 "parser.tab.c"
    break;

  case 9: /* and_or: and_or "||" linebreak pipeline  */
#line 75 "parser.y"
                                            { RULE(n_andor, "OR list   (cmd || cmd)"); }
#line 1653 "parser.tab.c"
    break;

  case 13: /* pipe_sequence: pipe_sequence "|" linebreak command  */
#line 85 "parser.y"
                                            { RULE(n_pipe, "pipeline  (cmd | cmd)"); }
#line 1659 "parser.tab.c"
    break;

  case 28: /* subshell: "(" compound_list ")"  */
#line 114 "parser.y"
                                            { RULE(n_subshell, "subshell  ( ... )"); }
#line 1665 "parser.tab.c"
    break;

  case 29: /* brace_group: "{" compound_list "}"  */
#line 118 "parser.y"
                                            { RULE(n_group, "command group  { ...; }"); }
#line 1671 "parser.tab.c"
    break;

  case 31: /* for_clause: "for" name do_group  */
#line 128 "parser.y"
                                                              { RULE(n_for, "for loop"); }
#line 1677 "parser.tab.c"
    break;

  case 32: /* for_clause: "for" name sequential_sep do_group  */
#line 129 "parser.y"
                                                              { RULE(n_for, "for loop"); }
#line 1683 "parser.tab.c"
    break;

  case 33: /* for_clause: "for" name linebreak "in" sequential_sep do_group  */
#line 130 "parser.y"
                                                              { RULE(n_for, "for loop (empty list)"); }
#line 1689 "parser.tab.c"
    break;

  case 34: /* for_clause: "for" name linebreak "in" wordlist sequential_sep do_group  */
#line 131 "parser.y"
                                                              { RULE(n_for, "for ... in loop"); }
#line 1695 "parser.tab.c"
    break;

  case 38: /* while_clause: "while" compound_list do_group  */
#line 144 "parser.y"
                                            { RULE(n_while, "while loop"); }
#line 1701 "parser.tab.c"
    break;

  case 39: /* until_clause: "until" compound_list do_group  */
#line 148 "parser.y"
                                            { RULE(n_until, "until loop"); }
#line 1707 "parser.tab.c"
    break;

  case 40: /* if_clause: "if" compound_list "then" compound_list else_part "fi"  */
#line 152 "parser.y"
                                                         { RULE(n_if, "if / elif / else statement"); }
#line 1713 "parser.tab.c"
    break;

  case 41: /* if_clause: "if" compound_list "then" compound_list "fi"  */
#line 153 "parser.y"
                                                         { RULE(n_if, "if statement"); }
#line 1719 "parser.tab.c"
    break;

  case 45: /* case_clause: "case" word linebreak "in" linebreak case_list "esac"  */
#line 163 "parser.y"
                                                           { RULE(n_case, "case statement"); }
#line 1725 "parser.tab.c"
    break;

  case 46: /* case_clause: "case" word linebreak "in" linebreak case_list_ns "esac"  */
#line 164 "parser.y"
                                                           { RULE(n_case, "case statement"); }
#line 1731 "parser.tab.c"
    break;

  case 47: /* case_clause: "case" word linebreak "in" linebreak "esac"  */
#line 165 "parser.y"
                                                           { RULE(n_case, "case statement (no branches)"); }
#line 1737 "parser.tab.c"
    break;

  case 58: /* function_def: "word" "(" ")" linebreak compound_command  */
#line 196 "parser.y"
                                                                   { RULE(n_func, "function definition  name() { }"); }
#line 1743 "parser.tab.c"
    break;

  case 59: /* function_def: "function" "word" linebreak brace_group  */
#line 197 "parser.y"
                                                                    { RULE(n_func, "function definition  function name { }"); }
#line 1749 "parser.tab.c"
    break;

  case 60: /* function_def: "function" "word" "(" ")" linebreak compound_command  */
#line 198 "parser.y"
                                                                   { RULE(n_func, "function definition  function name() { }"); }
#line 1755 "parser.tab.c"
    break;

  case 61: /* test_command: "[" test_expr "]"  */
#line 204 "parser.y"
                                            { RULE(n_test, "test expression  [ ... ]"); }
#line 1761 "parser.tab.c"
    break;

  case 62: /* test_command: "[[" test_expr "]]"  */
#line 205 "parser.y"
                                            { RULE(n_test, "test expression  [[ ... ]]"); }
#line 1767 "parser.tab.c"
    break;

  case 75: /* simple_command: cmd_prefix cmd_name cmd_suffix  */
#line 235 "parser.y"
                                            { RULE(n_simple, "simple command (with prefix and arguments)"); }
#line 1773 "parser.tab.c"
    break;

  case 76: /* simple_command: cmd_prefix cmd_name  */
#line 236 "parser.y"
                                            { RULE(n_simple, "simple command (with prefix)"); }
#line 1779 "parser.tab.c"
    break;

  case 77: /* simple_command: cmd_prefix  */
#line 237 "parser.y"
                                            { RULE(n_simple, "assignment statement"); }
#line 1785 "parser.tab.c"
    break;

  case 78: /* simple_command: cmd_name cmd_suffix  */
#line 238 "parser.y"
                                            { RULE(n_simple, "simple command with arguments"); }
#line 1791 "parser.tab.c"
    break;

  case 79: /* simple_command: cmd_name  */
#line 239 "parser.y"
                                            { RULE(n_simple, "simple command"); }
#line 1797 "parser.tab.c"
    break;

  case 91: /* assignment: "assignment (NAME=value)" word  */
#line 263 "parser.y"
                                            { RULE(n_assign, "variable assignment"); }
#line 1803 "parser.tab.c"
    break;

  case 92: /* assignment: "assignment (NAME=)"  */
#line 264 "parser.y"
                                            { RULE(n_assign, "variable assignment (empty value)"); }
#line 1809 "parser.tab.c"
    break;

  case 101: /* cmdsub: "$(" compound_list ")"  */
#line 279 "parser.y"
                                            { RULE(n_cmdsub, "command substitution  $( ... )"); }
#line 1815 "parser.tab.c"
    break;

  case 106: /* io_file: "<" word  */
#line 295 "parser.y"
                        { RULE(n_redir, "input redirection  <"); }
#line 1821 "parser.tab.c"
    break;

  case 107: /* io_file: ">" word  */
#line 296 "parser.y"
                        { RULE(n_redir, "output redirection  >"); }
#line 1827 "parser.tab.c"
    break;

  case 108: /* io_file: ">>" word  */
#line 297 "parser.y"
                        { RULE(n_redir, "append redirection  >>"); }
#line 1833 "parser.tab.c"
    break;

  case 109: /* io_file: "<&" word  */
#line 298 "parser.y"
                        { RULE(n_redir, "input fd duplication  <&"); }
#line 1839 "parser.tab.c"
    break;

  case 110: /* io_file: ">&" word  */
#line 299 "parser.y"
                        { RULE(n_redir, "output fd duplication  >&"); }
#line 1845 "parser.tab.c"
    break;


#line 1849 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 329 "parser.y"


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
