/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_PAKU_TAB_H_INCLUDED
# define YY_YY_PAKU_TAB_H_INCLUDED
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
    PLUS = 258,                    /* PLUS  */
    MINUS = 259,                   /* MINUS  */
    DIVIDE = 260,                  /* DIVIDE  */
    TIMES = 261,                   /* TIMES  */
    EQUALS = 262,                  /* EQUALS  */
    TYPE = 263,                    /* TYPE  */
    EOL = 264,                     /* EOL  */
    END = 265,                     /* END  */
    P_LEFT = 266,                  /* P_LEFT  */
    P_RIGHT = 267,                 /* P_RIGHT  */
    PRINT = 268,                   /* PRINT  */
    READ = 269,                    /* READ  */
    IF = 270,                      /* IF  */
    ELSE = 271,                    /* ELSE  */
    BRACES_LEFT = 272,             /* BRACES_LEFT  */
    BRACES_RIGHT = 273,            /* BRACES_RIGHT  */
    GREATER_THAN_EQUAL = 274,      /* GREATER_THAN_EQUAL  */
    LESS_THAN_EQUAL = 275,         /* LESS_THAN_EQUAL  */
    NOT_EQUAL = 276,               /* NOT_EQUAL  */
    LESS_THAN = 277,               /* LESS_THAN  */
    GREATER_THAN = 278,            /* GREATER_THAN  */
    EQUALS_DOUBLE = 279,           /* EQUALS_DOUBLE  */
    NUMBER = 280,                  /* NUMBER  */
    IDENTIFIER = 281               /* IDENTIFIER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "paku.y"

    char *s;
    double d;
    int b;

#line 96 "paku.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PAKU_TAB_H_INCLUDED  */
