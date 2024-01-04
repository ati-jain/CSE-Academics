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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    AUTO = 258,                    /* AUTO  */
    ENUM = 259,                    /* ENUM  */
    RESTRICT = 260,                /* RESTRICT  */
    UNSIGNED = 261,                /* UNSIGNED  */
    BREAK = 262,                   /* BREAK  */
    EXTERN = 263,                  /* EXTERN  */
    RETURN = 264,                  /* RETURN  */
    VOID = 265,                    /* VOID  */
    CASE = 266,                    /* CASE  */
    FLOAT = 267,                   /* FLOAT  */
    SHORT = 268,                   /* SHORT  */
    VOLATILE = 269,                /* VOLATILE  */
    CHAR = 270,                    /* CHAR  */
    FOR = 271,                     /* FOR  */
    SIGNED = 272,                  /* SIGNED  */
    WHILE = 273,                   /* WHILE  */
    CONST = 274,                   /* CONST  */
    GOTO = 275,                    /* GOTO  */
    SIZEOF = 276,                  /* SIZEOF  */
    BOOL = 277,                    /* BOOL  */
    CONTINUE = 278,                /* CONTINUE  */
    IF = 279,                      /* IF  */
    STATIC = 280,                  /* STATIC  */
    COMPLEX = 281,                 /* COMPLEX  */
    DEFAULT = 282,                 /* DEFAULT  */
    INLINE = 283,                  /* INLINE  */
    STRUCT = 284,                  /* STRUCT  */
    IMAGINARY = 285,               /* IMAGINARY  */
    DO = 286,                      /* DO  */
    INT = 287,                     /* INT  */
    SWITCH = 288,                  /* SWITCH  */
    DOUBLE = 289,                  /* DOUBLE  */
    LONG = 290,                    /* LONG  */
    TYPEDEF = 291,                 /* TYPEDEF  */
    ELSE = 292,                    /* ELSE  */
    REGISTER = 293,                /* REGISTER  */
    UNION = 294,                   /* UNION  */
    IDENTIFIER = 295,              /* IDENTIFIER  */
    INTEGER_CONSTANT = 296,        /* INTEGER_CONSTANT  */
    FLOATING_CONSTANT = 297,       /* FLOATING_CONSTANT  */
    CHARACTER_CONSTANT = 298,      /* CHARACTER_CONSTANT  */
    ENUMERATION_CONSTANT = 299,    /* ENUMERATION_CONSTANT  */
    STRING_LITERAL = 300,          /* STRING_LITERAL  */
    SQBRAOPEN = 301,               /* SQBRAOPEN  */
    SQBRACLOSE = 302,              /* SQBRACLOSE  */
    ROBRAOPEN = 303,               /* ROBRAOPEN  */
    ROBRACLOSE = 304,              /* ROBRACLOSE  */
    CURBRAOPEN = 305,              /* CURBRAOPEN  */
    CURBRACLOSE = 306,             /* CURBRACLOSE  */
    DOT = 307,                     /* DOT  */
    ACC = 308,                     /* ACC  */
    INC = 309,                     /* INC  */
    DEC = 310,                     /* DEC  */
    AMP = 311,                     /* AMP  */
    MUL = 312,                     /* MUL  */
    ADD = 313,                     /* ADD  */
    SUB = 314,                     /* SUB  */
    NEG = 315,                     /* NEG  */
    EXCLAIM = 316,                 /* EXCLAIM  */
    DIV = 317,                     /* DIV  */
    MODULO = 318,                  /* MODULO  */
    SHL = 319,                     /* SHL  */
    SHR = 320,                     /* SHR  */
    BITSHL = 321,                  /* BITSHL  */
    BITSHR = 322,                  /* BITSHR  */
    LTE = 323,                     /* LTE  */
    GTE = 324,                     /* GTE  */
    EQ = 325,                      /* EQ  */
    NEQ = 326,                     /* NEQ  */
    BITXOR = 327,                  /* BITXOR  */
    BITOR = 328,                   /* BITOR  */
    AND = 329,                     /* AND  */
    OR = 330,                      /* OR  */
    QUESTION = 331,                /* QUESTION  */
    COLON = 332,                   /* COLON  */
    SEMICOLON = 333,               /* SEMICOLON  */
    DOTS = 334,                    /* DOTS  */
    ASSIGN = 335,                  /* ASSIGN  */
    STAREQ = 336,                  /* STAREQ  */
    DIVEQ = 337,                   /* DIVEQ  */
    MODEQ = 338,                   /* MODEQ  */
    PLUSEQ = 339,                  /* PLUSEQ  */
    MINUSEQ = 340,                 /* MINUSEQ  */
    SHLEQ = 341,                   /* SHLEQ  */
    SHREQ = 342,                   /* SHREQ  */
    BINANDEQ = 343,                /* BINANDEQ  */
    BINXOREQ = 344,                /* BINXOREQ  */
    BINOREQ = 345,                 /* BINOREQ  */
    COMMA = 346,                   /* COMMA  */
    HASH = 347,                    /* HASH  */
    THEN = 348                     /* THEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define AUTO 258
#define ENUM 259
#define RESTRICT 260
#define UNSIGNED 261
#define BREAK 262
#define EXTERN 263
#define RETURN 264
#define VOID 265
#define CASE 266
#define FLOAT 267
#define SHORT 268
#define VOLATILE 269
#define CHAR 270
#define FOR 271
#define SIGNED 272
#define WHILE 273
#define CONST 274
#define GOTO 275
#define SIZEOF 276
#define BOOL 277
#define CONTINUE 278
#define IF 279
#define STATIC 280
#define COMPLEX 281
#define DEFAULT 282
#define INLINE 283
#define STRUCT 284
#define IMAGINARY 285
#define DO 286
#define INT 287
#define SWITCH 288
#define DOUBLE 289
#define LONG 290
#define TYPEDEF 291
#define ELSE 292
#define REGISTER 293
#define UNION 294
#define IDENTIFIER 295
#define INTEGER_CONSTANT 296
#define FLOATING_CONSTANT 297
#define CHARACTER_CONSTANT 298
#define ENUMERATION_CONSTANT 299
#define STRING_LITERAL 300
#define SQBRAOPEN 301
#define SQBRACLOSE 302
#define ROBRAOPEN 303
#define ROBRACLOSE 304
#define CURBRAOPEN 305
#define CURBRACLOSE 306
#define DOT 307
#define ACC 308
#define INC 309
#define DEC 310
#define AMP 311
#define MUL 312
#define ADD 313
#define SUB 314
#define NEG 315
#define EXCLAIM 316
#define DIV 317
#define MODULO 318
#define SHL 319
#define SHR 320
#define BITSHL 321
#define BITSHR 322
#define LTE 323
#define GTE 324
#define EQ 325
#define NEQ 326
#define BITXOR 327
#define BITOR 328
#define AND 329
#define OR 330
#define QUESTION 331
#define COLON 332
#define SEMICOLON 333
#define DOTS 334
#define ASSIGN 335
#define STAREQ 336
#define DIVEQ 337
#define MODEQ 338
#define PLUSEQ 339
#define MINUSEQ 340
#define SHLEQ 341
#define SHREQ 342
#define BINANDEQ 343
#define BINXOREQ 344
#define BINOREQ 345
#define COMMA 346
#define HASH 347
#define THEN 348

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "ass6_20CS10067_20CS30008.y"

	int intval;
	char* charval;
	int instr;
	sym* symp;
	symtype* symtp;
	expr* E;
	statement* S;
	Array* A;
	char unaryOperator;

#line 265 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
