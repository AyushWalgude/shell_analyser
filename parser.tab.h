/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    WORD = 258,                    /* "word"  */
    NUMBER = 259,                  /* "number"  */
    STRING = 260,                  /* "string"  */
    VAR = 261,                     /* "variable"  */
    BACKTICK = 262,                /* "`command`"  */
    ARITH = 263,                   /* "arithmetic expression"  */
    ASSIGN = 264,                  /* "assignment (NAME=value)"  */
    ASSIGN_EMPTY = 265,            /* "assignment (NAME=)"  */
    BUILTIN = 266,                 /* "builtin command"  */
    IO_NUMBER = 267,               /* "file descriptor"  */
    IF = 268,                      /* "if"  */
    THEN = 269,                    /* "then"  */
    ELIF = 270,                    /* "elif"  */
    ELSE = 271,                    /* "else"  */
    FI = 272,                      /* "fi"  */
    WHILE = 273,                   /* "while"  */
    UNTIL = 274,                   /* "until"  */
    FOR = 275,                     /* "for"  */
    IN = 276,                      /* "in"  */
    DO = 277,                      /* "do"  */
    DONE = 278,                    /* "done"  */
    CASE = 279,                    /* "case"  */
    ESAC = 280,                    /* "esac"  */
    FUNCTION = 281,                /* "function"  */
    AND_IF = 282,                  /* "&&"  */
    OR_IF = 283,                   /* "||"  */
    PIPE = 284,                    /* "|"  */
    AMP = 285,                     /* "&"  */
    SEMI = 286,                    /* ";"  */
    DSEMI = 287,                   /* ";;"  */
    LPAREN = 288,                  /* "("  */
    RPAREN = 289,                  /* ")"  */
    LBRACE = 290,                  /* "{"  */
    RBRACE = 291,                  /* "}"  */
    BANG = 292,                    /* "!"  */
    NEWLINE = 293,                 /* "end of line"  */
    LESS = 294,                    /* "<"  */
    GREAT = 295,                   /* ">"  */
    DGREAT = 296,                  /* ">>"  */
    LESSAND = 297,                 /* "<&"  */
    GREATAND = 298,                /* ">&"  */
    DOLLAR_LPAREN = 299,           /* "$("  */
    LBRACKET = 300,                /* "["  */
    RBRACKET = 301,                /* "]"  */
    DLBRACKET = 302,               /* "[["  */
    DRBRACKET = 303,               /* "]]"  */
    TEST_UNARY = 304,              /* "unary test operator"  */
    TEST_BINARY = 305,             /* "binary test operator"  */
    TEST_AND = 306,                /* "-a"  */
    TEST_OR = 307                  /* "-o"  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
