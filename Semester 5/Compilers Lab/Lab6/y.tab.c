/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "ass6_20CS10067_20CS30008.y"

	#include <iostream>
	#include <cstdlib>
	#include <string>
	#include <stdio.h>
	#include <sstream>
	#include "ass6_20CS10067_20CS30008_translator.h"

	extern int yylex();
	void yyerror(string s);
	extern string Type;
	vector <string> allstrings;

	using namespace std;

#line 87 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 338 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AUTO = 3,                       /* AUTO  */
  YYSYMBOL_ENUM = 4,                       /* ENUM  */
  YYSYMBOL_RESTRICT = 5,                   /* RESTRICT  */
  YYSYMBOL_UNSIGNED = 6,                   /* UNSIGNED  */
  YYSYMBOL_BREAK = 7,                      /* BREAK  */
  YYSYMBOL_EXTERN = 8,                     /* EXTERN  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_VOID = 10,                      /* VOID  */
  YYSYMBOL_CASE = 11,                      /* CASE  */
  YYSYMBOL_FLOAT = 12,                     /* FLOAT  */
  YYSYMBOL_SHORT = 13,                     /* SHORT  */
  YYSYMBOL_VOLATILE = 14,                  /* VOLATILE  */
  YYSYMBOL_CHAR = 15,                      /* CHAR  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_SIGNED = 17,                    /* SIGNED  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_CONST = 19,                     /* CONST  */
  YYSYMBOL_GOTO = 20,                      /* GOTO  */
  YYSYMBOL_SIZEOF = 21,                    /* SIZEOF  */
  YYSYMBOL_BOOL = 22,                      /* BOOL  */
  YYSYMBOL_CONTINUE = 23,                  /* CONTINUE  */
  YYSYMBOL_IF = 24,                        /* IF  */
  YYSYMBOL_STATIC = 25,                    /* STATIC  */
  YYSYMBOL_COMPLEX = 26,                   /* COMPLEX  */
  YYSYMBOL_DEFAULT = 27,                   /* DEFAULT  */
  YYSYMBOL_INLINE = 28,                    /* INLINE  */
  YYSYMBOL_STRUCT = 29,                    /* STRUCT  */
  YYSYMBOL_IMAGINARY = 30,                 /* IMAGINARY  */
  YYSYMBOL_DO = 31,                        /* DO  */
  YYSYMBOL_INT = 32,                       /* INT  */
  YYSYMBOL_SWITCH = 33,                    /* SWITCH  */
  YYSYMBOL_DOUBLE = 34,                    /* DOUBLE  */
  YYSYMBOL_LONG = 35,                      /* LONG  */
  YYSYMBOL_TYPEDEF = 36,                   /* TYPEDEF  */
  YYSYMBOL_ELSE = 37,                      /* ELSE  */
  YYSYMBOL_REGISTER = 38,                  /* REGISTER  */
  YYSYMBOL_UNION = 39,                     /* UNION  */
  YYSYMBOL_IDENTIFIER = 40,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER_CONSTANT = 41,          /* INTEGER_CONSTANT  */
  YYSYMBOL_FLOATING_CONSTANT = 42,         /* FLOATING_CONSTANT  */
  YYSYMBOL_CHARACTER_CONSTANT = 43,        /* CHARACTER_CONSTANT  */
  YYSYMBOL_ENUMERATION_CONSTANT = 44,      /* ENUMERATION_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 45,            /* STRING_LITERAL  */
  YYSYMBOL_SQBRAOPEN = 46,                 /* SQBRAOPEN  */
  YYSYMBOL_SQBRACLOSE = 47,                /* SQBRACLOSE  */
  YYSYMBOL_ROBRAOPEN = 48,                 /* ROBRAOPEN  */
  YYSYMBOL_ROBRACLOSE = 49,                /* ROBRACLOSE  */
  YYSYMBOL_CURBRAOPEN = 50,                /* CURBRAOPEN  */
  YYSYMBOL_CURBRACLOSE = 51,               /* CURBRACLOSE  */
  YYSYMBOL_DOT = 52,                       /* DOT  */
  YYSYMBOL_ACC = 53,                       /* ACC  */
  YYSYMBOL_INC = 54,                       /* INC  */
  YYSYMBOL_DEC = 55,                       /* DEC  */
  YYSYMBOL_AMP = 56,                       /* AMP  */
  YYSYMBOL_MUL = 57,                       /* MUL  */
  YYSYMBOL_ADD = 58,                       /* ADD  */
  YYSYMBOL_SUB = 59,                       /* SUB  */
  YYSYMBOL_NEG = 60,                       /* NEG  */
  YYSYMBOL_EXCLAIM = 61,                   /* EXCLAIM  */
  YYSYMBOL_DIV = 62,                       /* DIV  */
  YYSYMBOL_MODULO = 63,                    /* MODULO  */
  YYSYMBOL_SHL = 64,                       /* SHL  */
  YYSYMBOL_SHR = 65,                       /* SHR  */
  YYSYMBOL_BITSHL = 66,                    /* BITSHL  */
  YYSYMBOL_BITSHR = 67,                    /* BITSHR  */
  YYSYMBOL_LTE = 68,                       /* LTE  */
  YYSYMBOL_GTE = 69,                       /* GTE  */
  YYSYMBOL_EQ = 70,                        /* EQ  */
  YYSYMBOL_NEQ = 71,                       /* NEQ  */
  YYSYMBOL_BITXOR = 72,                    /* BITXOR  */
  YYSYMBOL_BITOR = 73,                     /* BITOR  */
  YYSYMBOL_AND = 74,                       /* AND  */
  YYSYMBOL_OR = 75,                        /* OR  */
  YYSYMBOL_QUESTION = 76,                  /* QUESTION  */
  YYSYMBOL_COLON = 77,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 78,                 /* SEMICOLON  */
  YYSYMBOL_DOTS = 79,                      /* DOTS  */
  YYSYMBOL_ASSIGN = 80,                    /* ASSIGN  */
  YYSYMBOL_STAREQ = 81,                    /* STAREQ  */
  YYSYMBOL_DIVEQ = 82,                     /* DIVEQ  */
  YYSYMBOL_MODEQ = 83,                     /* MODEQ  */
  YYSYMBOL_PLUSEQ = 84,                    /* PLUSEQ  */
  YYSYMBOL_MINUSEQ = 85,                   /* MINUSEQ  */
  YYSYMBOL_SHLEQ = 86,                     /* SHLEQ  */
  YYSYMBOL_SHREQ = 87,                     /* SHREQ  */
  YYSYMBOL_BINANDEQ = 88,                  /* BINANDEQ  */
  YYSYMBOL_BINXOREQ = 89,                  /* BINXOREQ  */
  YYSYMBOL_BINOREQ = 90,                   /* BINOREQ  */
  YYSYMBOL_COMMA = 91,                     /* COMMA  */
  YYSYMBOL_HASH = 92,                      /* HASH  */
  YYSYMBOL_THEN = 93,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 94,                  /* $accept  */
  YYSYMBOL_primary_expression = 95,        /* primary_expression  */
  YYSYMBOL_constant = 96,                  /* constant  */
  YYSYMBOL_postfix_expression = 97,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 98,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 99,          /* unary_expression  */
  YYSYMBOL_unary_operator = 100,           /* unary_operator  */
  YYSYMBOL_cast_expression = 101,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 102, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 103,      /* additive_expression  */
  YYSYMBOL_shift_expression = 104,         /* shift_expression  */
  YYSYMBOL_relational_expression = 105,    /* relational_expression  */
  YYSYMBOL_equality_expression = 106,      /* equality_expression  */
  YYSYMBOL_AND_expression = 107,           /* AND_expression  */
  YYSYMBOL_exclusive_OR_expression = 108,  /* exclusive_OR_expression  */
  YYSYMBOL_inclusive_OR_expression = 109,  /* inclusive_OR_expression  */
  YYSYMBOL_logical_AND_expression = 110,   /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 111,    /* logical_OR_expression  */
  YYSYMBOL_M = 112,                        /* M  */
  YYSYMBOL_N = 113,                        /* N  */
  YYSYMBOL_conditional_expression = 114,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 115,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 116,      /* assignment_operator  */
  YYSYMBOL_expression = 117,               /* expression  */
  YYSYMBOL_constant_expression = 118,      /* constant_expression  */
  YYSYMBOL_declaration = 119,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 120,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 121,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 122,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 123,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 124,           /* type_specifier  */
  YYSYMBOL_specifier_qualifier_list = 125, /* specifier_qualifier_list  */
  YYSYMBOL_enum_specifier = 126,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 127,          /* enumerator_list  */
  YYSYMBOL_enumerator = 128,               /* enumerator  */
  YYSYMBOL_type_qualifier = 129,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 130,       /* function_specifier  */
  YYSYMBOL_declarator = 131,               /* declarator  */
  YYSYMBOL_direct_declarator = 132,        /* direct_declarator  */
  YYSYMBOL_CT = 133,                       /* CT  */
  YYSYMBOL_pointer = 134,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 135,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 136,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 137,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 138,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 139,          /* identifier_list  */
  YYSYMBOL_type_name = 140,                /* type_name  */
  YYSYMBOL_initializer = 141,              /* initializer  */
  YYSYMBOL_initializer_list = 142,         /* initializer_list  */
  YYSYMBOL_designation = 143,              /* designation  */
  YYSYMBOL_designator_list = 144,          /* designator_list  */
  YYSYMBOL_designator = 145,               /* designator  */
  YYSYMBOL_statement = 146,                /* statement  */
  YYSYMBOL_labeled_statement = 147,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 148,       /* compound_statement  */
  YYSYMBOL_block_item_list = 149,          /* block_item_list  */
  YYSYMBOL_block_item = 150,               /* block_item  */
  YYSYMBOL_expression_statement = 151,     /* expression_statement  */
  YYSYMBOL_selection_statement = 152,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 153,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 154,           /* jump_statement  */
  YYSYMBOL_translation_unit = 155,         /* translation_unit  */
  YYSYMBOL_external_declaration = 156,     /* external_declaration  */
  YYSYMBOL_function_definition = 157,      /* function_definition  */
  YYSYMBOL_declaration_list = 158          /* declaration_list  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int16 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  211
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  365

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   348


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   175,   175,   181,   187,   203,   211,   221,   226,   227,
     236,   244,   279,   280,   292,   293,   294,   306,   318,   325,
     335,   341,   350,   355,   363,   371,   412,   413,   417,   422,
     426,   430,   434,   438,   445,   450,   458,   479,   492,   505,
     521,   526,   539,   555,   560,   572,   587,   592,   608,   623,
     638,   656,   661,   680,   701,   706,   726,   731,   751,   756,
     777,   782,   803,   808,   828,   835,   844,   849,   877,   882,
     906,   907,   908,   909,   910,   911,   912,   913,   914,   915,
     916,   920,   925,   929,   933,   934,   939,   940,   941,   942,
     943,   944,   945,   946,   950,   951,   955,   956,   965,   966,
     967,   968,   972,   973,   974,   975,   976,   977,   978,   979,
     980,   981,   982,   983,   984,   988,   989,   990,   991,   995,
     996,   997,   998,   999,  1003,  1004,  1008,  1009,  1013,  1014,
    1015,  1019,  1023,  1032,  1037,  1043,  1048,  1049,  1050,  1076,
    1098,  1099,  1100,  1101,  1102,  1120,  1121,  1143,  1159,  1160,
    1165,  1166,  1174,  1175,  1179,  1180,  1184,  1185,  1189,  1193,
    1197,  1198,  1202,  1206,  1211,  1212,  1217,  1218,  1219,  1220,
    1224,  1228,  1229,  1233,  1234,  1238,  1239,  1244,  1250,  1255,
    1260,  1268,  1273,  1278,  1286,  1291,  1299,  1304,  1313,  1318,
    1326,  1331,  1339,  1349,  1360,  1364,  1385,  1399,  1420,  1445,
    1446,  1447,  1448,  1454,  1463,  1464,  1468,  1469,  1473,  1474,
    1484,  1485
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AUTO", "ENUM",
  "RESTRICT", "UNSIGNED", "BREAK", "EXTERN", "RETURN", "VOID", "CASE",
  "FLOAT", "SHORT", "VOLATILE", "CHAR", "FOR", "SIGNED", "WHILE", "CONST",
  "GOTO", "SIZEOF", "BOOL", "CONTINUE", "IF", "STATIC", "COMPLEX",
  "DEFAULT", "INLINE", "STRUCT", "IMAGINARY", "DO", "INT", "SWITCH",
  "DOUBLE", "LONG", "TYPEDEF", "ELSE", "REGISTER", "UNION", "IDENTIFIER",
  "INTEGER_CONSTANT", "FLOATING_CONSTANT", "CHARACTER_CONSTANT",
  "ENUMERATION_CONSTANT", "STRING_LITERAL", "SQBRAOPEN", "SQBRACLOSE",
  "ROBRAOPEN", "ROBRACLOSE", "CURBRAOPEN", "CURBRACLOSE", "DOT", "ACC",
  "INC", "DEC", "AMP", "MUL", "ADD", "SUB", "NEG", "EXCLAIM", "DIV",
  "MODULO", "SHL", "SHR", "BITSHL", "BITSHR", "LTE", "GTE", "EQ", "NEQ",
  "BITXOR", "BITOR", "AND", "OR", "QUESTION", "COLON", "SEMICOLON", "DOTS",
  "ASSIGN", "STAREQ", "DIVEQ", "MODEQ", "PLUSEQ", "MINUSEQ", "SHLEQ",
  "SHREQ", "BINANDEQ", "BINXOREQ", "BINOREQ", "COMMA", "HASH", "THEN",
  "$accept", "primary_expression", "constant", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "AND_expression", "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression", "M", "N",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "specifier_qualifier_list",
  "enum_specifier", "enumerator_list", "enumerator", "type_qualifier",
  "function_specifier", "declarator", "direct_declarator", "CT", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "statement", "labeled_statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-265)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-148)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1092,  -265,    11,  -265,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,  -265,  -265,    85,  1092,  1092,  -265,  1092,  1092,  1056,
    -265,  -265,   -35,   -18,  -265,    -1,    36,  -265,    48,  -265,
     287,   -12,    25,  -265,  -265,  -265,  -265,  -265,  -265,   -18,
     -36,     1,  -265,    -3,  -265,  -265,    36,  -265,    -1,   869,
    -265,    85,    17,  1092,   664,    43,   -12,    40,   944,  -265,
      94,  -265,  -265,  -265,  -265,    86,   969,  -265,  -265,  -265,
    -265,  -265,  -265,   556,   843,   994,   994,  -265,  -265,  -265,
    -265,  -265,  -265,  -265,  -265,   152,    88,   944,  -265,    89,
      41,    95,    87,   131,   123,   113,   115,   119,   141,  -265,
    -265,  -265,   366,  -265,  -265,    17,   728,  -265,   150,   162,
     696,  -265,   787,   -38,  -265,   110,  -265,  -265,  -265,  -265,
    -265,   556,  -265,  -265,    -9,  1127,  -265,  1127,   172,   944,
     171,  -265,    46,   869,    84,  -265,   556,  -265,  -265,   944,
     894,   190,   195,  -265,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,  -265,  -265,  -265,  -265,  -265,   944,  -265,   944,   944,
     944,   944,   944,   944,   944,   944,   944,   944,   944,   944,
     944,   944,   944,   944,   165,   144,   163,   581,   944,   192,
    -265,   202,   166,   199,   176,  -265,   206,   179,  -265,  -265,
      57,  -265,  -265,  -265,  -265,   207,  -265,  -265,  -265,  -265,
    -265,  -265,   210,   728,  -265,  -265,  -265,   212,   213,  -265,
      -1,   214,   170,  -265,  -265,   222,  -265,   215,  -265,   944,
    -265,  -265,   919,   218,  -265,  -265,   789,  -265,  -265,  -265,
     217,   -34,  -265,    -7,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,    89,    89,    41,    41,    95,    95,    95,    95,    87,
      87,   131,   123,   113,  -265,  -265,  -265,  -265,  -265,    66,
     193,   606,   223,   196,  -265,   944,   498,   498,   944,   498,
    -265,  -265,   442,  -265,   226,  -265,  -265,  -265,  -265,   326,
    -265,   225,  -265,   843,  -265,  -265,  -265,  -265,   869,   225,
    -265,  -265,   944,   944,   944,   944,  -265,   498,  -265,   944,
    -265,   186,  -265,  -265,    -6,  -265,  -265,  -265,  -265,  -265,
      47,  -265,  -265,   115,   119,   186,  -265,   606,    -4,   230,
     263,   498,  -265,   817,   208,   235,  -265,  -265,   239,  -265,
    -265,  -265,  -265,   944,   498,   498,   944,   944,   498,   186,
    -265,  -265,     5,  -265,  -265,   245,   251,   220,  -265,  -265,
    -265,   498,   498,  -265,  -265
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   100,     0,   129,   110,    98,   102,   107,   104,   130,
     103,   109,   128,   111,    99,   112,   131,   113,   105,   108,
     106,   101,   207,     0,    87,    89,   114,    91,    93,     0,
     204,   206,   123,     0,   134,     0,   149,    85,     0,    94,
      96,   133,     0,    86,    88,    90,    92,     1,   205,     0,
     126,     0,   124,     0,   152,   151,   148,    84,     0,     0,
     210,     0,     0,   147,     0,   147,   132,     0,     0,   120,
       0,   135,   153,   150,    95,    96,     0,     2,     6,     7,
       9,     8,     4,     0,     0,     0,     0,    28,    29,    30,
      31,    32,    33,    10,     3,    22,    34,     0,    36,    40,
      43,    46,    51,    54,    56,    58,    60,    62,    66,    68,
     163,    97,     0,   209,   211,     0,     0,   139,    29,     0,
       0,   160,     0,     0,   119,     0,    34,    83,   127,   122,
     125,     0,    26,    81,     0,   116,   162,   118,     0,     0,
       0,   167,     0,     0,     0,   171,     0,    23,    24,     0,
       0,     0,     0,    16,    17,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,     0,     0,     0,     0,    64,     0,     2,   185,   191,
       0,   188,   189,   175,   176,    64,   186,   177,   178,   179,
     180,   208,     0,     0,   143,   138,   137,    29,     0,   146,
     159,     0,   154,   156,   145,     0,   121,     0,     5,     0,
     115,   117,     0,     0,   174,   164,     0,   166,   170,   172,
       0,     0,    12,     0,    20,    14,    15,    69,    37,    38,
      39,    41,    42,    44,    45,    47,    48,    49,    50,    52,
      53,    55,    57,    59,    64,    64,    64,   201,   203,     0,
       0,     0,     0,     0,   200,     0,     0,     0,     0,     0,
     190,   184,     0,   141,     0,   142,   136,   158,   144,     0,
     161,    27,    82,     0,    35,   173,   165,   169,     0,     0,
      11,    13,     0,     0,     0,     0,   202,     0,    64,     0,
     199,    65,   183,    64,     0,   181,   187,   140,   155,   157,
       0,   168,    21,    61,    63,    65,   182,     0,     0,     0,
       0,     0,    18,     0,     0,    64,    64,    64,     0,   194,
      19,    64,    64,     0,     0,     0,     0,     0,     0,    65,
     195,    65,     0,    67,   197,     0,   192,     0,    64,    64,
     196,     0,     0,   198,   193
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -265,  -265,  -265,  -265,  -265,   -67,  -265,   -91,    52,    58,
      51,    54,   122,   114,   125,     2,     6,  -265,  -146,  -103,
     -65,   -26,  -265,   -60,  -118,   -32,     0,  -265,   253,  -265,
     -71,    45,  -265,   265,   -44,    12,  -265,   -21,   274,   129,
     -19,   -54,  -265,  -265,    29,  -265,  -111,   -55,    27,  -204,
    -265,   180,   -93,  -265,   -46,  -265,    44,  -264,  -265,  -265,
    -265,  -265,   294,  -265,  -265
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    93,    94,    95,   243,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   272,   184,
     109,   133,   166,   200,   128,    22,    61,    38,    39,    24,
      25,   136,    26,    51,    52,    27,    28,    75,    41,    62,
      42,    56,   221,   222,   223,   123,   138,   141,   142,   143,
     144,   145,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    29,    30,    31,    63
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,   126,    40,   127,   111,   185,   167,   308,    60,   132,
     120,   224,   135,   300,    53,    49,   113,    55,   147,   148,
     227,   233,    50,   134,    43,    44,   130,    45,    46,    23,
     126,   114,   298,   110,    64,   240,    65,    73,   119,    34,
     228,     3,   301,   331,    68,   336,    71,    35,    54,   277,
       9,    32,    69,   225,   357,    12,    36,   229,   110,   282,
     135,    33,   213,   335,   135,    34,   135,   112,    72,   211,
     270,   134,   126,    35,   127,   135,    54,   248,   249,   250,
     201,   130,   229,   121,   302,   229,   134,   229,   237,   241,
     212,   124,    70,    36,   218,   137,   229,   235,   332,   171,
     172,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   110,   303,   304,
     305,   126,   220,   127,   244,    34,    57,   269,    54,   298,
     139,   125,    72,    35,    50,   280,   140,   236,   333,    58,
     247,   294,    36,   137,   306,   129,   168,   137,   229,   137,
      50,   169,   170,   175,   176,   177,   178,   229,   137,   173,
     174,   226,   327,    37,   238,   126,    59,   330,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   181,
     230,   297,   231,   312,   313,   182,   315,   284,   183,   343,
     344,   345,   115,   -65,   122,   347,   348,   214,   149,   287,
     150,   179,   180,   292,   151,   152,   153,   154,   329,   215,
     110,   234,   361,   362,   326,   311,   -65,   -65,   314,   265,
     266,   232,   334,   251,   252,    72,   255,   256,   257,   258,
     245,   253,   254,   259,   260,   246,   126,   126,   339,   264,
     271,   267,   273,   321,   274,   325,   355,   275,   356,   328,
     201,   350,   351,   276,   278,   354,   279,   283,   281,   285,
     286,   289,   290,   288,   291,   295,   299,   110,   363,   364,
     307,   309,   110,   317,   310,   293,   322,   229,   297,   337,
     126,   338,   353,   349,   342,   341,   352,   346,   359,   220,
       1,     2,     3,     4,   358,     5,   262,     6,   360,     7,
       8,     9,    10,   261,    11,   323,    12,   110,   263,    13,
     324,    74,    14,    15,    67,    16,    66,    17,   319,    18,
     320,    19,    20,    48,   239,    21,   316,     0,     0,     1,
       2,     3,     4,     0,     5,     0,     6,  -147,     7,     8,
       9,    10,     0,    11,     0,    12,     0,     0,    13,     0,
       0,    14,    15,     0,    16,     0,    17,     0,    18,     0,
      19,    20,     0,     0,    21,     0,     0,    59,     0,     1,
       2,     3,     4,   186,     5,   187,     6,   188,     7,     8,
       9,    10,   189,    11,   190,    12,   191,    76,    13,   192,
     193,    14,    15,   194,    16,     0,    17,   195,    18,   196,
      19,    20,     0,     0,    21,   318,   197,    78,    79,    80,
      81,    82,     0,     0,    83,     0,   112,   198,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   199,     1,     2,     3,     4,   186,
       5,   187,     6,   188,     7,     8,     9,    10,   189,    11,
     190,    12,   191,    76,    13,   192,   193,    14,    15,   194,
      16,     0,    17,   195,    18,   196,    19,    20,     0,     0,
      21,     0,   197,    78,    79,    80,    81,    82,     0,     0,
      83,     0,   112,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,     0,   186,     0,   187,     0,   188,
       0,     0,     0,     0,   189,     0,   190,     0,   191,    76,
     199,   192,   193,     0,     0,   194,     0,     0,     0,   195,
       0,   196,     0,     0,     0,     0,     0,     0,   197,    78,
      79,    80,    81,    82,     0,     0,    83,     0,   112,     0,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
       2,     3,     4,     0,     0,     0,     6,     0,     7,     8,
       9,    10,     0,    11,     0,    12,   199,    76,    13,     0,
       0,     0,    15,     0,     0,     0,    17,     0,    18,     0,
      19,    20,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    76,     0,    83,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    76,     0,    83,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,    77,    78,    79,    80,
      81,    82,     0,     0,    83,     0,     0,     0,     0,   268,
      85,    86,    87,    88,    89,    90,    91,    92,     0,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     9,     0,
       0,     0,     0,    12,   199,    76,     0,     0,     0,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     0,    77,    78,    79,    80,    81,    82,
       9,   117,    83,     0,     0,    12,     0,    76,    85,    86,
      87,   118,    89,    90,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     3,     0,     0,    77,    78,    79,    80,
      81,    82,     9,   216,    83,     0,     0,    12,     0,    76,
      85,    86,    87,   217,    89,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    78,
      79,    80,    81,    82,     0,     0,    83,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
       1,     2,     3,     4,     0,     5,     0,     6,     0,     7,
       8,     9,    10,     0,    11,     0,    12,     0,     0,    13,
      76,     0,    14,    15,     0,    16,     0,    17,     0,    18,
       0,    19,    20,     0,     0,    21,     0,     0,     0,    77,
      78,    79,    80,    81,    82,   139,   219,    83,    76,    84,
     296,   140,     0,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,    82,   139,    76,    83,     0,    84,   340,   140,
       0,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,   139,
      76,    83,     0,    84,     0,   140,     0,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    76,     0,    83,     0,    84,
       0,     0,     0,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      76,     0,    83,   242,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    76,     0,    83,     0,   293,
       0,     0,     0,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      76,     0,    83,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    76,     0,   131,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,    77,    78,    79,    80,    81,    82,
       0,     0,   146,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,    47,     0,     0,     1,
       2,     3,     4,     0,     5,     0,     6,     0,     7,     8,
       9,    10,     0,    11,     0,    12,     0,     0,    13,     0,
       0,    14,    15,     0,    16,     0,    17,     0,    18,     0,
      19,    20,     0,     0,    21,     1,     2,     3,     4,     0,
       5,     0,     6,     0,     7,     8,     9,    10,     0,    11,
       0,    12,     0,     0,    13,     0,     0,    14,    15,     0,
      16,     0,    17,     0,    18,     0,    19,    20,     0,     0,
      21,     2,     3,     4,     0,     0,     0,     6,     0,     7,
       8,     9,    10,     0,    11,     0,    12,     0,     0,    13,
       0,     0,     0,    15,     0,     0,     0,    17,     0,    18,
       0,    19,    20
};

static const yytype_int16 yycheck[] =
{
       0,    68,    23,    68,    59,   108,    97,   271,    40,    76,
      64,    49,    83,    47,    35,    50,    62,    36,    85,    86,
     131,   139,    40,    83,    24,    25,    70,    27,    28,    29,
      97,    63,   236,    59,    46,   146,    48,    56,    64,    40,
      49,     5,    49,    49,    80,    49,    49,    48,    36,   195,
      14,    40,    51,    91,    49,    19,    57,    91,    84,   205,
     131,    50,   116,   327,   135,    40,   137,    50,    56,   115,
     188,   131,   139,    48,   139,   146,    64,   168,   169,   170,
     112,   125,    91,    40,    91,    91,   146,    91,   143,   149,
     116,    51,    91,    57,   120,    83,    91,    51,    51,    58,
      59,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   143,   264,   265,
     266,   188,   122,   188,   150,    40,    78,   187,   116,   333,
      46,    91,   120,    48,    40,    78,    52,    91,    91,    91,
     166,   232,    57,   131,    78,    51,    57,   135,    91,   137,
      40,    62,    63,    66,    67,    68,    69,    91,   146,    64,
      65,    51,   308,    78,    80,   232,    80,   313,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    56,
     135,   236,   137,   276,   277,    72,   279,   213,    73,   335,
     336,   337,    63,    74,    65,   341,   342,    47,    46,   220,
      48,    70,    71,   229,    52,    53,    54,    55,   311,    47,
     236,    40,   358,   359,   307,   275,    75,    76,   278,    75,
      76,    49,   325,   171,   172,   213,   175,   176,   177,   178,
      40,   173,   174,   179,   180,    40,   303,   304,   331,    74,
      48,    78,    40,   298,    78,   305,   349,    48,   351,   309,
     282,   344,   345,    77,    48,   348,    77,    47,    51,    47,
      47,    91,    40,    49,    49,    47,    49,   293,   361,   362,
      77,    48,   298,    47,    78,    50,   302,    91,   333,    49,
     347,    18,   347,   343,    49,    77,   346,    48,    37,   289,
       3,     4,     5,     6,    49,     8,   182,    10,    78,    12,
      13,    14,    15,   181,    17,   303,    19,   333,   183,    22,
     304,    58,    25,    26,    49,    28,    42,    30,   289,    32,
     293,    34,    35,    29,   144,    38,   282,    -1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    10,    50,    12,    13,
      14,    15,    -1,    17,    -1,    19,    -1,    -1,    22,    -1,
      -1,    25,    26,    -1,    28,    -1,    30,    -1,    32,    -1,
      34,    35,    -1,    -1,    38,    -1,    -1,    80,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    -1,    -1,    38,    79,    40,    41,    42,    43,
      44,    45,    -1,    -1,    48,    -1,    50,    51,    -1,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    -1,    -1,
      38,    -1,    40,    41,    42,    43,    44,    45,    -1,    -1,
      48,    -1,    50,    -1,    -1,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,     7,    -1,     9,    -1,    11,
      -1,    -1,    -1,    -1,    16,    -1,    18,    -1,    20,    21,
      78,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    -1,    50,    -1,
      -1,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
       4,     5,     6,    -1,    -1,    -1,    10,    -1,    12,    13,
      14,    15,    -1,    17,    -1,    19,    78,    21,    22,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    30,    -1,    32,    -1,
      34,    35,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    21,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    21,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,    78,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    -1,    19,    78,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,    -1,    -1,    40,    41,    42,    43,    44,    45,
      14,    47,    48,    -1,    -1,    19,    -1,    21,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,    -1,    -1,    40,    41,    42,    43,
      44,    45,    14,    47,    48,    -1,    -1,    19,    -1,    21,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
       3,     4,     5,     6,    -1,     8,    -1,    10,    -1,    12,
      13,    14,    15,    -1,    17,    -1,    19,    -1,    -1,    22,
      21,    -1,    25,    26,    -1,    28,    -1,    30,    -1,    32,
      -1,    34,    35,    -1,    -1,    38,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    49,    48,    21,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    21,    48,    -1,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      21,    48,    -1,    50,    -1,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    21,    -1,    48,    -1,    50,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      21,    -1,    48,    49,    -1,    -1,    -1,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    21,    -1,    48,    -1,    50,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      21,    -1,    48,    -1,    -1,    -1,    -1,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    21,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,     0,    -1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    10,    -1,    12,    13,
      14,    15,    -1,    17,    -1,    19,    -1,    -1,    22,    -1,
      -1,    25,    26,    -1,    28,    -1,    30,    -1,    32,    -1,
      34,    35,    -1,    -1,    38,     3,     4,     5,     6,    -1,
       8,    -1,    10,    -1,    12,    13,    14,    15,    -1,    17,
      -1,    19,    -1,    -1,    22,    -1,    -1,    25,    26,    -1,
      28,    -1,    30,    -1,    32,    -1,    34,    35,    -1,    -1,
      38,     4,     5,     6,    -1,    -1,    -1,    10,    -1,    12,
      13,    14,    15,    -1,    17,    -1,    19,    -1,    -1,    22,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    -1,    32,
      -1,    34,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,    10,    12,    13,    14,
      15,    17,    19,    22,    25,    26,    28,    30,    32,    34,
      35,    38,   119,   120,   123,   124,   126,   129,   130,   155,
     156,   157,    40,    50,    40,    48,    57,    78,   121,   122,
     131,   132,   134,   120,   120,   120,   120,     0,   156,    50,
      40,   127,   128,   131,   129,   134,   135,    78,    91,    80,
     119,   120,   133,   158,    46,    48,   132,   127,    80,    51,
      91,    49,   129,   134,   122,   131,    21,    40,    41,    42,
      43,    44,    45,    48,    50,    54,    55,    56,    57,    58,
      59,    60,    61,    95,    96,    97,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   114,
     115,   141,    50,   148,   119,   133,    25,    47,    57,   115,
     135,    40,   133,   139,    51,    91,    99,   114,   118,    51,
     128,    48,    99,   115,   117,   124,   125,   129,   140,    46,
      52,   141,   142,   143,   144,   145,    48,    99,    99,    46,
      48,    52,    53,    54,    55,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   116,   101,    57,    62,
      63,    58,    59,    64,    65,    66,    67,    68,    69,    70,
      71,    56,    72,    73,   113,   113,     7,     9,    11,    16,
      18,    20,    23,    24,    27,    31,    33,    40,    51,    78,
     117,   119,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   148,   115,   135,    47,    47,    47,    57,   115,    49,
     120,   136,   137,   138,    49,    91,    51,   140,    49,    91,
     125,   125,    49,   118,    40,    51,    91,   141,    80,   145,
     140,   117,    49,    98,   115,    40,    40,   115,   101,   101,
     101,   102,   102,   103,   103,   104,   104,   104,   104,   105,
     105,   106,   107,   108,    74,    75,    76,    78,    78,   117,
     118,    48,   112,    40,    78,    48,    77,   112,    48,    77,
      78,    51,   112,    47,   115,    47,    47,   131,    49,    91,
      40,    49,   115,    50,   101,    47,    51,   141,   143,    49,
      47,    49,    91,   112,   112,   112,    78,    77,   151,    48,
      78,   117,   146,   146,   117,   146,   150,    47,    79,   138,
     142,   141,   115,   109,   110,   117,   146,   112,   117,   113,
     112,    49,    51,    91,   113,   151,    49,    49,    18,   146,
      51,    77,    49,   112,   112,   112,    48,   112,   112,   117,
     146,   146,   117,   114,   146,   113,   113,    49,    49,    37,
      78,   112,   112,   146,   146
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    95,    95,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      98,    98,    99,    99,    99,    99,    99,    99,   100,   100,
     100,   100,   100,   100,   101,   101,   102,   102,   102,   102,
     103,   103,   103,   104,   104,   104,   105,   105,   105,   105,
     105,   106,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   113,   114,   114,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   117,   117,   118,   119,   119,   120,   120,   120,   120,
     120,   120,   120,   120,   121,   121,   122,   122,   123,   123,
     123,   123,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   125,   125,   125,   125,   126,
     126,   126,   126,   126,   127,   127,   128,   128,   129,   129,
     129,   130,   131,   131,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   133,   134,   134,
     134,   134,   135,   135,   136,   136,   137,   137,   138,   138,
     139,   139,   140,   141,   141,   141,   142,   142,   142,   142,
     143,   144,   144,   145,   145,   146,   146,   146,   146,   146,
     146,   147,   147,   147,   148,   148,   149,   149,   150,   150,
     151,   151,   152,   152,   152,   153,   153,   153,   153,   154,
     154,   154,   154,   154,   155,   155,   156,   156,   157,   157,
     158,   158
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     4,     3,     4,     3,     3,     2,     2,     6,     7,
       1,     3,     1,     2,     2,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     5,     0,     0,     1,     9,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     2,     2,     1,     2,     1,
       2,     1,     2,     1,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     1,     5,
       4,     6,     5,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     1,     3,     5,     4,     4,     3,
       6,     5,     5,     4,     5,     4,     4,     0,     2,     1,
       3,     2,     1,     2,     1,     3,     1,     3,     2,     1,
       1,     3,     1,     1,     3,     4,     2,     1,     4,     3,
       2,     1,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     3,     2,     1,     3,     1,     1,
       2,     1,     8,    11,     5,     7,     9,     8,    11,     3,
       2,     2,     3,     2,     1,     2,     1,     1,     5,     4,
       1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* primary_expression: IDENTIFIER  */
#line 176 "ass6_20CS10067_20CS30008.y"
        {
		(yyval.E) = new expr();					// Create a new expression and store pointer to ST entry in the location
		(yyval.E)->loc = (yyvsp[0].symp);
		(yyval.E)->type = "NONBOOL";
	}
#line 1921 "y.tab.c"
    break;

  case 3: /* primary_expression: constant  */
#line 182 "ass6_20CS10067_20CS30008.y"
        {
		// Create a new expression and store the value of the constant in a temporary
		(yyval.E) = new expr();
		(yyval.E)->loc = (yyvsp[0].symp);
	}
#line 1931 "y.tab.c"
    break;

  case 4: /* primary_expression: STRING_LITERAL  */
#line 188 "ass6_20CS10067_20CS30008.y"
        {
		// Create a new expression and store the value of the constant in a temporary
		(yyval.E) = new expr();
		symtype* tmp = new symtype("PTR");
		(yyval.E)->loc = gentemp(tmp, (yyvsp[0].charval));
		(yyval.E)->loc->type->ptr = new symtype("CHAR");

		allstrings.push_back((yyvsp[0].charval));
		stringstream strs;
		strs << allstrings.size()-1;
		string temp_str = strs.str();
		char* intStr = (char*) temp_str.c_str();
		string str = string(intStr);
		emit("EQUALSTR", (yyval.E)->loc->name, str);
	}
#line 1951 "y.tab.c"
    break;

  case 5: /* primary_expression: ROBRAOPEN expression ROBRACLOSE  */
#line 204 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equal to expression
		(yyval.E) = (yyvsp[-1].E);
	}
#line 1960 "y.tab.c"
    break;

  case 6: /* constant: INTEGER_CONSTANT  */
#line 212 "ass6_20CS10067_20CS30008.y"
        {
		stringstream strs;
		strs << (yyvsp[0].intval);
		string temp_str = strs.str();
		char* intStr = (char*) temp_str.c_str();
		string str = string(intStr);
		(yyval.symp) = gentemp(new symtype("INTEGER"), str);
		emit("EQUAL", (yyval.symp)->name, (yyvsp[0].intval));
	}
#line 1974 "y.tab.c"
    break;

  case 7: /* constant: FLOATING_CONSTANT  */
#line 222 "ass6_20CS10067_20CS30008.y"
        {
		(yyval.symp) = gentemp(new symtype("DOUBLE"), string((yyvsp[0].charval)));
		emit("EQUAL", (yyval.symp)->name, string((yyvsp[0].charval)));
	}
#line 1983 "y.tab.c"
    break;

  case 8: /* constant: ENUMERATION_CONSTANT  */
#line 226 "ass6_20CS10067_20CS30008.y"
                               {}
#line 1989 "y.tab.c"
    break;

  case 9: /* constant: CHARACTER_CONSTANT  */
#line 228 "ass6_20CS10067_20CS30008.y"
        {
		(yyval.symp) = gentemp(new symtype("CHAR"),(yyvsp[0].charval));
		emit("EQUALCHAR", (yyval.symp)->name, string((yyvsp[0].charval)));
	}
#line 1998 "y.tab.c"
    break;

  case 10: /* postfix_expression: primary_expression  */
#line 237 "ass6_20CS10067_20CS30008.y"
        {
		// Create new Array and store the location of primary expression in it
		(yyval.A) = new Array ();
		(yyval.A)->Array = (yyvsp[0].E)->loc;
		(yyval.A)->loc = (yyval.A)->Array;
		(yyval.A)->type = (yyvsp[0].E)->loc->type;
	}
#line 2010 "y.tab.c"
    break;

  case 11: /* postfix_expression: postfix_expression SQBRAOPEN expression SQBRACLOSE  */
#line 245 "ass6_20CS10067_20CS30008.y"
        {
		(yyval.A) = new Array();
		
		(yyval.A)->Array = (yyvsp[-3].A)->loc;							// Copy the base
		(yyval.A)->type = (yyvsp[-3].A)->type->ptr;						// Type = type of element
		(yyval.A)->loc = gentemp(new symtype("INTEGER"));		// Store computed address
		
		// New address = (if only) already computed + $3 * new width
		if ((yyvsp[-3].A)->cat=="ARR") 
		{						
			// If already arr, multiply the size of the sub-type of Array with the expression value and add
			sym* t = gentemp(new symtype("INTEGER"));
			stringstream strs;
		    strs <<size_type((yyval.A)->type);
		    string temp_str = strs.str();
		    char* intStr = (char*) temp_str.c_str();
			string str = string(intStr);				
 			emit("MULT", t->name, (yyvsp[-1].E)->loc->name, str);
			emit("ADD", (yyval.A)->loc->name, (yyvsp[-3].A)->loc->name, t->name);
		}
 		else 
		{
			// If a 1D Array, simply calculate size
 			stringstream strs;
		    strs <<size_type((yyval.A)->type);
		    string temp_str = strs.str();
		    char* intStr1 = (char*) temp_str.c_str();
			string str1 = string(intStr1);		
	 		emit("MULT", (yyval.A)->loc->name, (yyvsp[-1].E)->loc->name, str1);
 		}

 		// Mark that it contains Array address and first time computation is done
		(yyval.A)->cat = "ARR";
	}
#line 2049 "y.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression ROBRAOPEN ROBRACLOSE  */
#line 279 "ass6_20CS10067_20CS30008.y"
                                                 {}
#line 2055 "y.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression ROBRAOPEN argument_expression_list ROBRACLOSE  */
#line 281 "ass6_20CS10067_20CS30008.y"
        {
		// Call the function with number of parameters from argument_expression_list_opt
		(yyval.A) = new Array();
		(yyval.A)->Array = gentemp((yyvsp[-3].A)->type);
		stringstream strs;
	    strs <<(yyvsp[-1].intval);
	    string temp_str = strs.str();
	    char* intStr = (char*) temp_str.c_str();
		string str = string(intStr);		
		emit("CALL", (yyval.A)->Array->name, (yyvsp[-3].A)->Array->name, str);
	}
#line 2071 "y.tab.c"
    break;

  case 14: /* postfix_expression: postfix_expression DOT IDENTIFIER  */
#line 292 "ass6_20CS10067_20CS30008.y"
                                           {}
#line 2077 "y.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression ACC IDENTIFIER  */
#line 293 "ass6_20CS10067_20CS30008.y"
                                           {}
#line 2083 "y.tab.c"
    break;

  case 16: /* postfix_expression: postfix_expression INC  */
#line 295 "ass6_20CS10067_20CS30008.y"
        {
		// Generate new temporary, equate it to old one and then add 1
		(yyval.A) = new Array();

		// Copy $1 to $$
		(yyval.A)->Array = gentemp((yyvsp[-1].A)->Array->type);
		emit("EQUAL", (yyval.A)->Array->name, (yyvsp[-1].A)->Array->name);

		// Increment $1
		emit("ADD", (yyvsp[-1].A)->Array->name, (yyvsp[-1].A)->Array->name, "1");
	}
#line 2099 "y.tab.c"
    break;

  case 17: /* postfix_expression: postfix_expression DEC  */
#line 307 "ass6_20CS10067_20CS30008.y"
        {
		// Generate new temporary, equate it to old one and then subtract 1
		(yyval.A) = new Array();

		// Copy $1 to $$
		(yyval.A)->Array = gentemp((yyvsp[-1].A)->Array->type);
		emit("EQUAL", (yyval.A)->Array->name, (yyvsp[-1].A)->Array->name);

		// Decrement $1
		emit("SUB", (yyvsp[-1].A)->Array->name, (yyvsp[-1].A)->Array->name, "1");
	}
#line 2115 "y.tab.c"
    break;

  case 18: /* postfix_expression: ROBRAOPEN type_name ROBRACLOSE CURBRAOPEN initializer_list CURBRACLOSE  */
#line 319 "ass6_20CS10067_20CS30008.y"
        {
		// Later to be added more
		(yyval.A) = new Array();
		(yyval.A)->Array = gentemp(new symtype("INTEGER"));
		(yyval.A)->loc = gentemp(new symtype("INTEGER"));
	}
#line 2126 "y.tab.c"
    break;

  case 19: /* postfix_expression: ROBRAOPEN type_name ROBRACLOSE CURBRAOPEN initializer_list COMMA CURBRACLOSE  */
#line 326 "ass6_20CS10067_20CS30008.y"
        {
		// Later to be added more
		(yyval.A) = new Array();
		(yyval.A)->Array = gentemp(new symtype("INTEGER"));
		(yyval.A)->loc = gentemp(new symtype("INTEGER"));
	}
#line 2137 "y.tab.c"
    break;

  case 20: /* argument_expression_list: assignment_expression  */
#line 336 "ass6_20CS10067_20CS30008.y"
        {
		// One argument and emitparam
		emit("PARAM", (yyvsp[0].E)->loc->name);
		(yyval.intval) = 1;
	}
#line 2147 "y.tab.c"
    break;

  case 21: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 342 "ass6_20CS10067_20CS30008.y"
        {
		// One more argument and emitparam
		emit("PARAM", (yyvsp[0].E)->loc->name);
		(yyval.intval) = (yyvsp[-2].intval)+1;
	}
#line 2157 "y.tab.c"
    break;

  case 22: /* unary_expression: postfix_expression  */
#line 351 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.A) = (yyvsp[0].A);
	}
#line 2166 "y.tab.c"
    break;

  case 23: /* unary_expression: INC unary_expression  */
#line 356 "ass6_20CS10067_20CS30008.y"
        {
		// Increment $2
		emit("ADD", (yyvsp[0].A)->Array->name, (yyvsp[0].A)->Array->name, "1");

		// Use the same value as $2
		(yyval.A) = (yyvsp[0].A);
	}
#line 2178 "y.tab.c"
    break;

  case 24: /* unary_expression: DEC unary_expression  */
#line 364 "ass6_20CS10067_20CS30008.y"
        {
		// Decrement $2
		emit("SUB", (yyvsp[0].A)->Array->name, (yyvsp[0].A)->Array->name, "1");

		// Use the same value as $2
		(yyval.A) = (yyvsp[0].A);
	}
#line 2190 "y.tab.c"
    break;

  case 25: /* unary_expression: unary_operator cast_expression  */
#line 372 "ass6_20CS10067_20CS30008.y"
        {
		// If it is of this type, where unary operator is involved{
		(yyval.A) = new Array();
		switch ((yyvsp[-1].unaryOperator)) {
			case '&':
				// Address of something, then generate a pointer temporary and emitthe quad
				(yyval.A)->Array = gentemp((new symtype("PTR")));
				(yyval.A)->Array->type->ptr = (yyvsp[0].A)->Array->type; 
				emit("ADDRESS", (yyval.A)->Array->name, (yyvsp[0].A)->Array->name);
				break;
			case '*':
				// Value of something, then generate a temporary of the corresponding type and emitthe quad
				(yyval.A)->cat = "PTR";
				(yyval.A)->loc = gentemp((yyvsp[0].A)->Array->type->ptr);
				emit("PTRR", (yyval.A)->loc->name, (yyvsp[0].A)->Array->name);
				(yyval.A)->Array = (yyvsp[0].A)->Array;
				break;
			case '+':
				// Unary plus
				(yyval.A) = (yyvsp[0].A);
				break;
			case '-':
				// Unary minus 
				(yyval.A)->Array = gentemp(new symtype((yyvsp[0].A)->Array->type->type));
				emit("UMINUS", (yyval.A)->Array->name, (yyvsp[0].A)->Array->name);
				break;
			case '~':
				// Bitwise not, generate new temporary of the same base type and make it negative of current one
				(yyval.A)->Array = gentemp(new symtype((yyvsp[0].A)->Array->type->type));
				emit("BNOT", (yyval.A)->Array->name, (yyvsp[0].A)->Array->name);
				break;
			case '!':
				// Logical not, generate new temporary of the same base type and make it negative of current one
				(yyval.A)->Array = gentemp(new symtype((yyvsp[0].A)->Array->type->type));
				emit("LNOT", (yyval.A)->Array->name, (yyvsp[0].A)->Array->name);
				break;
			default:
				break;
		}
	}
#line 2235 "y.tab.c"
    break;

  case 26: /* unary_expression: SIZEOF unary_expression  */
#line 412 "ass6_20CS10067_20CS30008.y"
                                 {}
#line 2241 "y.tab.c"
    break;

  case 27: /* unary_expression: SIZEOF ROBRAOPEN type_name ROBRACLOSE  */
#line 413 "ass6_20CS10067_20CS30008.y"
                                               {}
#line 2247 "y.tab.c"
    break;

  case 28: /* unary_operator: AMP  */
#line 418 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate to the corresponding operator
		(yyval.unaryOperator) = '&';
	}
#line 2256 "y.tab.c"
    break;

  case 29: /* unary_operator: MUL  */
#line 423 "ass6_20CS10067_20CS30008.y"
        {
		(yyval.unaryOperator) = '*';
	}
#line 2264 "y.tab.c"
    break;

  case 30: /* unary_operator: ADD  */
#line 427 "ass6_20CS10067_20CS30008.y"
        {
		(yyval.unaryOperator) = '+';
	}
#line 2272 "y.tab.c"
    break;

  case 31: /* unary_operator: SUB  */
#line 431 "ass6_20CS10067_20CS30008.y"
        {
		(yyval.unaryOperator) = '-';
	}
#line 2280 "y.tab.c"
    break;

  case 32: /* unary_operator: NEG  */
#line 435 "ass6_20CS10067_20CS30008.y"
        {
		(yyval.unaryOperator) = '~';
	}
#line 2288 "y.tab.c"
    break;

  case 33: /* unary_operator: EXCLAIM  */
#line 439 "ass6_20CS10067_20CS30008.y"
        {
		(yyval.unaryOperator) = '!';
	}
#line 2296 "y.tab.c"
    break;

  case 34: /* cast_expression: unary_expression  */
#line 446 "ass6_20CS10067_20CS30008.y"
        {
		// Unary expression, simply equate
		(yyval.A)=(yyvsp[0].A);
	}
#line 2305 "y.tab.c"
    break;

  case 35: /* cast_expression: ROBRAOPEN type_name ROBRACLOSE cast_expression  */
#line 451 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.A)=(yyvsp[0].A);
	}
#line 2314 "y.tab.c"
    break;

  case 36: /* multiplicative_expression: cast_expression  */
#line 459 "ass6_20CS10067_20CS30008.y"
        {
		(yyval.E) = new expr();		// Generate new expression
		if ((yyvsp[0].A)->cat=="ARR") 
		{ 
			// Array
			(yyval.E)->loc = gentemp((yyvsp[0].A)->loc->type);
			emit("ARR", (yyval.E)->loc->name, (yyvsp[0].A)->Array->name, (yyvsp[0].A)->loc->name);		
			// Emitwith Array right
		}
		else if ((yyvsp[0].A)->cat=="PTR") 
		{ 
			// If it is of type ptr
			(yyval.E)->loc = (yyvsp[0].A)->loc;
		}
		else 
		{ 
			// Otherwise
			(yyval.E)->loc = (yyvsp[0].A)->Array;
		}
	}
#line 2339 "y.tab.c"
    break;

  case 37: /* multiplicative_expression: multiplicative_expression MUL cast_expression  */
#line 480 "ass6_20CS10067_20CS30008.y"
        {
		// If we have multiplication
		if (typecheck ((yyvsp[-2].E)->loc, (yyvsp[0].A)->Array) ) 
		{
			// If types are compatible, generate new temporary and equate to the product
			(yyval.E) = new expr();
			(yyval.E)->loc = gentemp(new symtype((yyvsp[-2].E)->loc->type->type));
			emit("MULT", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].A)->Array->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
#line 2356 "y.tab.c"
    break;

  case 38: /* multiplicative_expression: multiplicative_expression DIV cast_expression  */
#line 493 "ass6_20CS10067_20CS30008.y"
        {
		// If we have division
		if (typecheck ((yyvsp[-2].E)->loc, (yyvsp[0].A)->Array) ) 
		{
			// If types are compatible, generate new temporary and equate to the quotient
			(yyval.E) = new expr();
			(yyval.E)->loc = gentemp(new symtype((yyvsp[-2].E)->loc->type->type));
			emit("DIVIDE", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].A)->Array->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
#line 2373 "y.tab.c"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression MODULO cast_expression  */
#line 506 "ass6_20CS10067_20CS30008.y"
        {
		// If we have mod
		if (typecheck ((yyvsp[-2].E)->loc, (yyvsp[0].A)->Array) ) 
		{
			// If types are compatible, generate new temporary and equate to the quotient
			(yyval.E) = new expr();
			(yyval.E)->loc = gentemp(new symtype((yyvsp[-2].E)->loc->type->type));
			emit("MODOP", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].A)->Array->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
#line 2390 "y.tab.c"
    break;

  case 40: /* additive_expression: multiplicative_expression  */
#line 522 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.E)=(yyvsp[0].E);
	}
#line 2399 "y.tab.c"
    break;

  case 41: /* additive_expression: additive_expression ADD multiplicative_expression  */
#line 527 "ass6_20CS10067_20CS30008.y"
        {	
		// For addition
		if (typecheck ((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc) ) 
		{
			// If types are compatible, generate new temporary and equate to the sum
			(yyval.E) = new expr();
			(yyval.E)->loc = gentemp(new symtype((yyvsp[-2].E)->loc->type->type));
			emit("ADD", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
#line 2416 "y.tab.c"
    break;

  case 42: /* additive_expression: additive_expression SUB multiplicative_expression  */
#line 540 "ass6_20CS10067_20CS30008.y"
        {
		// For subtraction
		if (typecheck((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc)) 
		{
			// If types are compatible, generate new temporary and equate to the difference
			(yyval.E) = new expr();
			(yyval.E)->loc = gentemp(new symtype((yyvsp[-2].E)->loc->type->type));
			emit("SUB", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
#line 2433 "y.tab.c"
    break;

  case 43: /* shift_expression: additive_expression  */
#line 556 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.E)=(yyvsp[0].E);
	}
#line 2442 "y.tab.c"
    break;

  case 44: /* shift_expression: shift_expression SHL additive_expression  */
#line 561 "ass6_20CS10067_20CS30008.y"
        {
		// If base type is int, generate new temporary and equate to the shifted value
		if ((yyvsp[0].E)->loc->type->type == "INTEGER") 
		{
			(yyval.E) = new expr();
			(yyval.E)->loc = gentemp(new symtype("INTEGER"));
			emit("LEFTOP", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
#line 2458 "y.tab.c"
    break;

  case 45: /* shift_expression: shift_expression SHR additive_expression  */
#line 573 "ass6_20CS10067_20CS30008.y"
        {
		// If base type is int, generate new temporary and equate to the shifted value
		if ((yyvsp[0].E)->loc->type->type == "INTEGER") 
		{
			(yyval.E) = new expr();
			(yyval.E)->loc = gentemp(new symtype("INTEGER"));
			emit("RIGHTOP", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
#line 2474 "y.tab.c"
    break;

  case 46: /* relational_expression: shift_expression  */
#line 588 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.E)=(yyvsp[0].E);
	}
#line 2483 "y.tab.c"
    break;

  case 47: /* relational_expression: relational_expression BITSHL shift_expression  */
#line 593 "ass6_20CS10067_20CS30008.y"
        {
		// Check compatible types
		if (typecheck((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc)) 
		{
			(yyval.E) = new expr();
			(yyval.E)->type = "BOOL";

			(yyval.E)->truelist = makelist (nextinstr());					// Make truelist
			(yyval.E)->falselist = makelist (nextinstr()+1);				// Make falselist
			emit("LT", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);			// Emitstatement if a < b goto ...
			emit("GOTOOP", "");										// Emitgoto ...
		}
		// Error
		else cout << "Type Error" << endl;
	}
#line 2503 "y.tab.c"
    break;

  case 48: /* relational_expression: relational_expression BITSHR shift_expression  */
#line 609 "ass6_20CS10067_20CS30008.y"
        {
		// Check compatible types
		if (typecheck((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc)) 
		{
			(yyval.E) = new expr();
			(yyval.E)->type = "BOOL";
			(yyval.E)->truelist = makelist(nextinstr());					// Make truelist
			(yyval.E)->falselist = makelist(nextinstr()+1);				// Make falselist
			emit("GT", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);			// Emitstatement if a > b goto ...
			emit("GOTOOP", "");										// Emitgoto ...
		}
		// Error
		else cout << "Type Error" << endl;
	}
#line 2522 "y.tab.c"
    break;

  case 49: /* relational_expression: relational_expression LTE shift_expression  */
#line 624 "ass6_20CS10067_20CS30008.y"
        {
		// Check compatible types, make truelist and falselist, emitthe required statement
		if (typecheck((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc)) 
		{
			(yyval.E) = new expr();
			(yyval.E)->type = "BOOL";
			(yyval.E)->truelist = makelist(nextinstr());					// Make truelist
			(yyval.E)->falselist = makelist(nextinstr()+1);				// Make falselist
			emit("LE", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);			// Emitstatement if a > b goto ...
			emit("GOTOOP", "");										// Emitgoto ...
		}
		// Error
		else cout << "Type Error" << endl;
	}
#line 2541 "y.tab.c"
    break;

  case 50: /* relational_expression: relational_expression GTE shift_expression  */
#line 639 "ass6_20CS10067_20CS30008.y"
        {
		// Check compatible types, make truelist and falselist, emitthe required statement
		if (typecheck((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc)) 
		{
			(yyval.E) = new expr();
			(yyval.E)->type = "BOOL";
			(yyval.E)->truelist = makelist(nextinstr());					// Make truelist
			(yyval.E)->falselist = makelist(nextinstr()+1);				// Make falselist
			emit("GE", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);			// Emitstatement if a > b goto ...
			emit("GOTOOP", "");										// Emitgoto ...
		}
		// Error
		else cout << "Type Error" << endl;
	}
#line 2560 "y.tab.c"
    break;

  case 51: /* equality_expression: relational_expression  */
#line 657 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.E)=(yyvsp[0].E);
	}
#line 2569 "y.tab.c"
    break;

  case 52: /* equality_expression: equality_expression EQ relational_expression  */
#line 662 "ass6_20CS10067_20CS30008.y"
        {
		// Check compatibility, make list and emit
		if (typecheck((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc))         
		{
			// Convert bool to int
			convertBool2Int((yyvsp[-2].E));			
			convertBool2Int((yyvsp[0].E));

			(yyval.E) = new expr();
			(yyval.E)->type = "BOOL";
			(yyval.E)->truelist = makelist(nextinstr());					// Make truelist
			(yyval.E)->falselist = makelist(nextinstr()+1);				// Make falselist
			emit("EQOP", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);			// Emitstatement if a > b goto ...
			emit("GOTOOP", "");									// Emitgoto ...
		}
		// Error
		else cout << "Type Error" << endl;
	}
#line 2592 "y.tab.c"
    break;

  case 53: /* equality_expression: equality_expression NEQ relational_expression  */
#line 681 "ass6_20CS10067_20CS30008.y"
        {
		// Check compatibility, convert bool to int, make list and emit
		if (typecheck((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc)) 
		{
			convertBool2Int((yyvsp[-2].E));
			convertBool2Int((yyvsp[0].E));

			(yyval.E) = new expr();
			(yyval.E)->type = "BOOL";
			(yyval.E)->truelist = makelist(nextinstr());					// Make truelist
			(yyval.E)->falselist = makelist(nextinstr()+1);				// Make falselist
			emit("NEOP", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);			// Emitstatement if a > b goto ...
			emit("GOTOOP", "");										// Emitgoto ...
		}
		// Error
		else cout << "Type Error" << endl;
	}
#line 2614 "y.tab.c"
    break;

  case 54: /* AND_expression: equality_expression  */
#line 702 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.E)=(yyvsp[0].E);
	}
#line 2623 "y.tab.c"
    break;

  case 55: /* AND_expression: AND_expression AMP equality_expression  */
#line 707 "ass6_20CS10067_20CS30008.y"
        {
		// Check compatible types, make non-boolean expression and convert bool to int and emit
		if (typecheck((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc)) 
		{
			// Convert bool to int
			convertBool2Int((yyvsp[-2].E));
			convertBool2Int((yyvsp[0].E));
			
			(yyval.E) = new expr();
			(yyval.E)->type = "NONBOOL";
			(yyval.E)->loc = gentemp(new symtype("INTEGER"));
			emit("BAND", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
#line 2644 "y.tab.c"
    break;

  case 56: /* exclusive_OR_expression: AND_expression  */
#line 727 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.E)=(yyvsp[0].E);
	}
#line 2653 "y.tab.c"
    break;

  case 57: /* exclusive_OR_expression: exclusive_OR_expression BITXOR AND_expression  */
#line 732 "ass6_20CS10067_20CS30008.y"
        {
		// Same as AND_expression: check compatible types, make non-boolean expression and convert bool to int and emit
		if (typecheck((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc)) 
		{
			convertBool2Int((yyvsp[-2].E));
			convertBool2Int((yyvsp[0].E));
			
			(yyval.E) = new expr();
			(yyval.E)->type = "NONBOOL";

			(yyval.E)->loc = gentemp(new symtype("INTEGER"));
			emit("XOR", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
#line 2674 "y.tab.c"
    break;

  case 58: /* inclusive_OR_expression: exclusive_OR_expression  */
#line 752 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.E)=(yyvsp[0].E);
	}
#line 2683 "y.tab.c"
    break;

  case 59: /* inclusive_OR_expression: inclusive_OR_expression BITOR exclusive_OR_expression  */
#line 757 "ass6_20CS10067_20CS30008.y"
        {
		// Same as and_expression: check compatible types, make non-boolean expression and convert bool to int and emit
		if (typecheck((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc)) 
		{
			// If any is bool get its value
			convertBool2Int((yyvsp[-2].E));
			convertBool2Int((yyvsp[0].E));
			
			(yyval.E) = new expr();
			(yyval.E)->type = "NONBOOL";

			(yyval.E)->loc = gentemp(new symtype("INTEGER"));
			emit("INOR", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
#line 2705 "y.tab.c"
    break;

  case 60: /* logical_AND_expression: inclusive_OR_expression  */
#line 778 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.E)=(yyvsp[0].E);
	}
#line 2714 "y.tab.c"
    break;

  case 61: /* logical_AND_expression: logical_AND_expression N AND M inclusive_OR_expression  */
#line 783 "ass6_20CS10067_20CS30008.y"
        {
		// Involves back-patching
		// Convert int to bool
		convertInt2Bool((yyvsp[0].E));

		// Convert $1 to bool and backpatch using N
		backpatch((yyvsp[-3].S)->nextlist, nextinstr());
		convertInt2Bool((yyvsp[-4].E));

		(yyval.E) = new expr();
		(yyval.E)->type = "BOOL";

		// Standard back-patching principles
		backpatch((yyvsp[-4].E)->truelist, (yyvsp[-1].instr));
		(yyval.E)->truelist = (yyvsp[0].E)->truelist;
		(yyval.E)->falselist = merge((yyvsp[-4].E)->falselist, (yyvsp[0].E)->falselist);
	}
#line 2736 "y.tab.c"
    break;

  case 62: /* logical_OR_expression: logical_AND_expression  */
#line 804 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate 
		(yyval.E)=(yyvsp[0].E);
	}
#line 2745 "y.tab.c"
    break;

  case 63: /* logical_OR_expression: logical_OR_expression N OR M logical_AND_expression  */
#line 809 "ass6_20CS10067_20CS30008.y"
        {
		// Convert (if) int to bool
		convertInt2Bool((yyvsp[0].E));

		// Convert $1 to bool and backpatch using N
		backpatch((yyvsp[-3].S)->nextlist, nextinstr());
		convertInt2Bool((yyvsp[-4].E));

		(yyval.E) = new expr();
		(yyval.E)->type = "BOOL";

		// Standard back-patching principles involved
		backpatch((yyvsp[-4].E)->falselist, (yyvsp[-1].instr));
		(yyval.E)->truelist = merge((yyvsp[-4].E)->truelist, (yyvsp[0].E)->truelist);
		(yyval.E)->falselist = (yyvsp[0].E)->falselist;
	}
#line 2766 "y.tab.c"
    break;

  case 64: /* M: %empty  */
#line 829 "ass6_20CS10067_20CS30008.y"
        {	
		// To store the address of the next instruction
		(yyval.instr) = nextinstr();
	}
#line 2775 "y.tab.c"
    break;

  case 65: /* N: %empty  */
#line 836 "ass6_20CS10067_20CS30008.y"
        { 	
		// Guard against fallthrough by emitting a goto
		(yyval.S)  = new statement();
		(yyval.S)->nextlist = makelist(nextinstr());
		emit("GOTOOP","");
	}
#line 2786 "y.tab.c"
    break;

  case 66: /* conditional_expression: logical_OR_expression  */
#line 845 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.E)=(yyvsp[0].E);
	}
#line 2795 "y.tab.c"
    break;

  case 67: /* conditional_expression: logical_OR_expression N QUESTION M expression N COLON M conditional_expression  */
#line 850 "ass6_20CS10067_20CS30008.y"
        {
		// Generate temporary for expression
		(yyval.E)->loc = gentemp((yyvsp[-4].E)->loc->type);
		(yyval.E)->loc->update((yyvsp[-4].E)->loc->type);
		
		// Make it equal to the conditional expression
		emit("EQUAL", (yyval.E)->loc->name, (yyvsp[0].E)->loc->name);
		list<int> l = makelist(nextinstr());
		emit("GOTOOP", "");				// Prevent fallthrough

		// Necessary back-patching 
		backpatch((yyvsp[-3].S)->nextlist, nextinstr());
		emit("EQUAL", (yyval.E)->loc->name, (yyvsp[-4].E)->loc->name);
		list<int> m = makelist(nextinstr());
		l = merge(l, m);					// Mergethe next instruction list
		emit("GOTOOP", "");				// Prevent fallthrough

		// Necessary back-patching w.r.t logical_OR_expression
		backpatch((yyvsp[-7].S)->nextlist, nextinstr());
		convertInt2Bool((yyvsp[-8].E));
		backpatch((yyvsp[-8].E)->truelist, (yyvsp[-5].instr));
		backpatch((yyvsp[-8].E)->falselist, (yyvsp[-1].instr));
		backpatch(l, nextinstr());
	}
#line 2824 "y.tab.c"
    break;

  case 68: /* assignment_expression: conditional_expression  */
#line 878 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.E)=(yyvsp[0].E);
	}
#line 2833 "y.tab.c"
    break;

  case 69: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 883 "ass6_20CS10067_20CS30008.y"
        {
		// If type is arr, simply check if we need to convert and emit
		if((yyvsp[-2].A)->cat=="ARR") 
		{
			(yyvsp[0].E)->loc = conv((yyvsp[0].E)->loc, (yyvsp[-2].A)->type->type);
			emit("ARRL", (yyvsp[-2].A)->Array->name, (yyvsp[-2].A)->loc->name, (yyvsp[0].E)->loc->name);	
		}
		// If type is ptr, simply emit
		else if((yyvsp[-2].A)->cat=="PTR") 
		{
			emit("PTRL", (yyvsp[-2].A)->Array->name, (yyvsp[0].E)->loc->name);	
		}
		// Otherwise assignment
		else
		{
			(yyvsp[0].E)->loc = conv((yyvsp[0].E)->loc, (yyvsp[-2].A)->Array->type->type);
			emit("EQUAL", (yyvsp[-2].A)->Array->name, (yyvsp[0].E)->loc->name);
		}
		(yyval.E) = (yyvsp[0].E);
	}
#line 2858 "y.tab.c"
    break;

  case 70: /* assignment_operator: ASSIGN  */
#line 906 "ass6_20CS10067_20CS30008.y"
               {}
#line 2864 "y.tab.c"
    break;

  case 71: /* assignment_operator: STAREQ  */
#line 907 "ass6_20CS10067_20CS30008.y"
                {}
#line 2870 "y.tab.c"
    break;

  case 72: /* assignment_operator: DIVEQ  */
#line 908 "ass6_20CS10067_20CS30008.y"
               {}
#line 2876 "y.tab.c"
    break;

  case 73: /* assignment_operator: MODEQ  */
#line 909 "ass6_20CS10067_20CS30008.y"
               {}
#line 2882 "y.tab.c"
    break;

  case 74: /* assignment_operator: PLUSEQ  */
#line 910 "ass6_20CS10067_20CS30008.y"
                {}
#line 2888 "y.tab.c"
    break;

  case 75: /* assignment_operator: MINUSEQ  */
#line 911 "ass6_20CS10067_20CS30008.y"
                 {}
#line 2894 "y.tab.c"
    break;

  case 76: /* assignment_operator: SHLEQ  */
#line 912 "ass6_20CS10067_20CS30008.y"
               {}
#line 2900 "y.tab.c"
    break;

  case 77: /* assignment_operator: SHREQ  */
#line 913 "ass6_20CS10067_20CS30008.y"
               {}
#line 2906 "y.tab.c"
    break;

  case 78: /* assignment_operator: BINANDEQ  */
#line 914 "ass6_20CS10067_20CS30008.y"
                  {}
#line 2912 "y.tab.c"
    break;

  case 79: /* assignment_operator: BINXOREQ  */
#line 915 "ass6_20CS10067_20CS30008.y"
                  {}
#line 2918 "y.tab.c"
    break;

  case 80: /* assignment_operator: BINOREQ  */
#line 916 "ass6_20CS10067_20CS30008.y"
                 {}
#line 2924 "y.tab.c"
    break;

  case 81: /* expression: assignment_expression  */
#line 921 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.E)=(yyvsp[0].E);
	}
#line 2933 "y.tab.c"
    break;

  case 82: /* expression: expression COMMA assignment_expression  */
#line 925 "ass6_20CS10067_20CS30008.y"
                                                {}
#line 2939 "y.tab.c"
    break;

  case 83: /* constant_expression: conditional_expression  */
#line 929 "ass6_20CS10067_20CS30008.y"
                               {}
#line 2945 "y.tab.c"
    break;

  case 84: /* declaration: declaration_specifiers init_declarator_list SEMICOLON  */
#line 933 "ass6_20CS10067_20CS30008.y"
                                                              {	}
#line 2951 "y.tab.c"
    break;

  case 85: /* declaration: declaration_specifiers SEMICOLON  */
#line 934 "ass6_20CS10067_20CS30008.y"
                                          {	}
#line 2957 "y.tab.c"
    break;

  case 86: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 939 "ass6_20CS10067_20CS30008.y"
                                                       {}
#line 2963 "y.tab.c"
    break;

  case 87: /* declaration_specifiers: storage_class_specifier  */
#line 940 "ass6_20CS10067_20CS30008.y"
                                 {}
#line 2969 "y.tab.c"
    break;

  case 88: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 941 "ass6_20CS10067_20CS30008.y"
                                               {}
#line 2975 "y.tab.c"
    break;

  case 89: /* declaration_specifiers: type_specifier  */
#line 942 "ass6_20CS10067_20CS30008.y"
                        {}
#line 2981 "y.tab.c"
    break;

  case 90: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 943 "ass6_20CS10067_20CS30008.y"
                                               {}
#line 2987 "y.tab.c"
    break;

  case 91: /* declaration_specifiers: type_qualifier  */
#line 944 "ass6_20CS10067_20CS30008.y"
                        {}
#line 2993 "y.tab.c"
    break;

  case 92: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 945 "ass6_20CS10067_20CS30008.y"
                                                   {}
#line 2999 "y.tab.c"
    break;

  case 93: /* declaration_specifiers: function_specifier  */
#line 946 "ass6_20CS10067_20CS30008.y"
                            {}
#line 3005 "y.tab.c"
    break;

  case 94: /* init_declarator_list: init_declarator  */
#line 950 "ass6_20CS10067_20CS30008.y"
                        {}
#line 3011 "y.tab.c"
    break;

  case 95: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 951 "ass6_20CS10067_20CS30008.y"
                                                    {}
#line 3017 "y.tab.c"
    break;

  case 96: /* init_declarator: declarator  */
#line 955 "ass6_20CS10067_20CS30008.y"
                   {(yyval.symp)=(yyvsp[0].symp);}
#line 3023 "y.tab.c"
    break;

  case 97: /* init_declarator: declarator ASSIGN initializer  */
#line 957 "ass6_20CS10067_20CS30008.y"
        {
		// Get the initial value and emitit
		if ((yyvsp[0].symp)->initial_value!="") (yyvsp[-2].symp)->initial_value=(yyvsp[0].symp)->initial_value;
		emit("EQUAL", (yyvsp[-2].symp)->name, (yyvsp[0].symp)->name);
	}
#line 3033 "y.tab.c"
    break;

  case 98: /* storage_class_specifier: EXTERN  */
#line 965 "ass6_20CS10067_20CS30008.y"
               {}
#line 3039 "y.tab.c"
    break;

  case 99: /* storage_class_specifier: STATIC  */
#line 966 "ass6_20CS10067_20CS30008.y"
                 {}
#line 3045 "y.tab.c"
    break;

  case 100: /* storage_class_specifier: AUTO  */
#line 967 "ass6_20CS10067_20CS30008.y"
               {}
#line 3051 "y.tab.c"
    break;

  case 101: /* storage_class_specifier: REGISTER  */
#line 968 "ass6_20CS10067_20CS30008.y"
                   {}
#line 3057 "y.tab.c"
    break;

  case 102: /* type_specifier: VOID  */
#line 972 "ass6_20CS10067_20CS30008.y"
             {Type="VOID";}
#line 3063 "y.tab.c"
    break;

  case 103: /* type_specifier: CHAR  */
#line 973 "ass6_20CS10067_20CS30008.y"
               {Type="CHAR";}
#line 3069 "y.tab.c"
    break;

  case 104: /* type_specifier: SHORT  */
#line 974 "ass6_20CS10067_20CS30008.y"
                {}
#line 3075 "y.tab.c"
    break;

  case 105: /* type_specifier: INT  */
#line 975 "ass6_20CS10067_20CS30008.y"
              {Type="INTEGER";}
#line 3081 "y.tab.c"
    break;

  case 106: /* type_specifier: LONG  */
#line 976 "ass6_20CS10067_20CS30008.y"
               {}
#line 3087 "y.tab.c"
    break;

  case 107: /* type_specifier: FLOAT  */
#line 977 "ass6_20CS10067_20CS30008.y"
                {}
#line 3093 "y.tab.c"
    break;

  case 108: /* type_specifier: DOUBLE  */
#line 978 "ass6_20CS10067_20CS30008.y"
                 {Type="DOUBLE";}
#line 3099 "y.tab.c"
    break;

  case 109: /* type_specifier: SIGNED  */
#line 979 "ass6_20CS10067_20CS30008.y"
                 {}
#line 3105 "y.tab.c"
    break;

  case 110: /* type_specifier: UNSIGNED  */
#line 980 "ass6_20CS10067_20CS30008.y"
                   {}
#line 3111 "y.tab.c"
    break;

  case 111: /* type_specifier: BOOL  */
#line 981 "ass6_20CS10067_20CS30008.y"
               {}
#line 3117 "y.tab.c"
    break;

  case 112: /* type_specifier: COMPLEX  */
#line 982 "ass6_20CS10067_20CS30008.y"
                  {}
#line 3123 "y.tab.c"
    break;

  case 113: /* type_specifier: IMAGINARY  */
#line 983 "ass6_20CS10067_20CS30008.y"
                    {}
#line 3129 "y.tab.c"
    break;

  case 114: /* type_specifier: enum_specifier  */
#line 984 "ass6_20CS10067_20CS30008.y"
                         {}
#line 3135 "y.tab.c"
    break;

  case 115: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 988 "ass6_20CS10067_20CS30008.y"
                                                {}
#line 3141 "y.tab.c"
    break;

  case 116: /* specifier_qualifier_list: type_specifier  */
#line 989 "ass6_20CS10067_20CS30008.y"
                         {}
#line 3147 "y.tab.c"
    break;

  case 117: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 990 "ass6_20CS10067_20CS30008.y"
                                                  {}
#line 3153 "y.tab.c"
    break;

  case 118: /* specifier_qualifier_list: type_qualifier  */
#line 991 "ass6_20CS10067_20CS30008.y"
                         {}
#line 3159 "y.tab.c"
    break;

  case 119: /* enum_specifier: ENUM IDENTIFIER CURBRAOPEN enumerator_list CURBRACLOSE  */
#line 995 "ass6_20CS10067_20CS30008.y"
                                                               {}
#line 3165 "y.tab.c"
    break;

  case 120: /* enum_specifier: ENUM CURBRAOPEN enumerator_list CURBRACLOSE  */
#line 996 "ass6_20CS10067_20CS30008.y"
                                                     {}
#line 3171 "y.tab.c"
    break;

  case 121: /* enum_specifier: ENUM IDENTIFIER CURBRAOPEN enumerator_list COMMA CURBRACLOSE  */
#line 997 "ass6_20CS10067_20CS30008.y"
                                                                      {}
#line 3177 "y.tab.c"
    break;

  case 122: /* enum_specifier: ENUM CURBRAOPEN enumerator_list COMMA CURBRACLOSE  */
#line 998 "ass6_20CS10067_20CS30008.y"
                                                           {}
#line 3183 "y.tab.c"
    break;

  case 123: /* enum_specifier: ENUM IDENTIFIER  */
#line 999 "ass6_20CS10067_20CS30008.y"
                         {}
#line 3189 "y.tab.c"
    break;

  case 124: /* enumerator_list: enumerator  */
#line 1003 "ass6_20CS10067_20CS30008.y"
                   {}
#line 3195 "y.tab.c"
    break;

  case 125: /* enumerator_list: enumerator_list COMMA enumerator  */
#line 1004 "ass6_20CS10067_20CS30008.y"
                                          {}
#line 3201 "y.tab.c"
    break;

  case 126: /* enumerator: IDENTIFIER  */
#line 1008 "ass6_20CS10067_20CS30008.y"
                   {}
#line 3207 "y.tab.c"
    break;

  case 127: /* enumerator: IDENTIFIER ASSIGN constant_expression  */
#line 1009 "ass6_20CS10067_20CS30008.y"
                                               {}
#line 3213 "y.tab.c"
    break;

  case 128: /* type_qualifier: CONST  */
#line 1013 "ass6_20CS10067_20CS30008.y"
              {}
#line 3219 "y.tab.c"
    break;

  case 129: /* type_qualifier: RESTRICT  */
#line 1014 "ass6_20CS10067_20CS30008.y"
                  {}
#line 3225 "y.tab.c"
    break;

  case 130: /* type_qualifier: VOLATILE  */
#line 1015 "ass6_20CS10067_20CS30008.y"
                  {}
#line 3231 "y.tab.c"
    break;

  case 131: /* function_specifier: INLINE  */
#line 1019 "ass6_20CS10067_20CS30008.y"
               {}
#line 3237 "y.tab.c"
    break;

  case 132: /* declarator: pointer direct_declarator  */
#line 1024 "ass6_20CS10067_20CS30008.y"
        {
		// For multidimensional arrays
		// Move in depth till you get the base type
		symtype * t = (yyvsp[-1].symtp);
		while (t->ptr !=NULL) t = t->ptr;
		t->ptr = (yyvsp[0].symp)->type;
		(yyval.symp) = (yyvsp[0].symp)->update((yyvsp[-1].symtp));
	}
#line 3250 "y.tab.c"
    break;

  case 133: /* declarator: direct_declarator  */
#line 1032 "ass6_20CS10067_20CS30008.y"
                           {}
#line 3256 "y.tab.c"
    break;

  case 134: /* direct_declarator: IDENTIFIER  */
#line 1038 "ass6_20CS10067_20CS30008.y"
        {
		// If identifier, simply add a new variable of var_type
		(yyval.symp) = (yyvsp[0].symp)->update(new symtype(Type));
		currentSymbol = (yyval.symp);
	}
#line 3266 "y.tab.c"
    break;

  case 135: /* direct_declarator: ROBRAOPEN declarator ROBRACLOSE  */
#line 1044 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.symp)=(yyvsp[-1].symp);
	}
#line 3275 "y.tab.c"
    break;

  case 136: /* direct_declarator: direct_declarator SQBRAOPEN type_qualifier_list assignment_expression SQBRACLOSE  */
#line 1048 "ass6_20CS10067_20CS30008.y"
                                                                                           {}
#line 3281 "y.tab.c"
    break;

  case 137: /* direct_declarator: direct_declarator SQBRAOPEN type_qualifier_list SQBRACLOSE  */
#line 1049 "ass6_20CS10067_20CS30008.y"
                                                                     {}
#line 3287 "y.tab.c"
    break;

  case 138: /* direct_declarator: direct_declarator SQBRAOPEN assignment_expression SQBRACLOSE  */
#line 1051 "ass6_20CS10067_20CS30008.y"
        {
		symtype * t = (yyvsp[-3].symp) -> type;
		symtype * prev = NULL;
		// Keep moving recursively to get basetype
		while (t->type == "ARR") 
		{
			prev = t;
			t = t->ptr;
		}
		if (prev==NULL) 
		{
			// Get initial value
			int temp = atoi((yyvsp[-1].E)->loc->initial_value.c_str());
			// Create new symbol table with that initial value
			symtype* s = new symtype("ARR", (yyvsp[-3].symp)->type, temp);
			// Update the symbol table			
			(yyval.symp) = (yyvsp[-3].symp)->update(s);
		}
		else 
		{
			// Similar arguments as above	
			prev->ptr =  new symtype("ARR", t, atoi((yyvsp[-1].E)->loc->initial_value.c_str()));
			(yyval.symp) = (yyvsp[-3].symp)->update ((yyvsp[-3].symp)->type);
		}
	}
#line 3317 "y.tab.c"
    break;

  case 139: /* direct_declarator: direct_declarator SQBRAOPEN SQBRACLOSE  */
#line 1077 "ass6_20CS10067_20CS30008.y"
        {
		symtype * t = (yyvsp[-2].symp) -> type;
		symtype * prev = NULL;
		// Keep moving recursively to get basetype
		while (t->type == "ARR") 
		{
			prev = t;
			t = t->ptr;
		}
		if (prev==NULL) 
		{
			// No initial value - simply keep zero
			symtype* s = new symtype("ARR", (yyvsp[-2].symp)->type, 0);
			(yyval.symp) = (yyvsp[-2].symp)->update(s);
		}
		else 
		{
			prev->ptr =  new symtype("ARR", t, 0);
			(yyval.symp) = (yyvsp[-2].symp)->update ((yyvsp[-2].symp)->type);
		}
	}
#line 3343 "y.tab.c"
    break;

  case 140: /* direct_declarator: direct_declarator SQBRAOPEN STATIC type_qualifier_list assignment_expression SQBRACLOSE  */
#line 1098 "ass6_20CS10067_20CS30008.y"
                                                                                                  {}
#line 3349 "y.tab.c"
    break;

  case 141: /* direct_declarator: direct_declarator SQBRAOPEN STATIC assignment_expression SQBRACLOSE  */
#line 1099 "ass6_20CS10067_20CS30008.y"
                                                                              {}
#line 3355 "y.tab.c"
    break;

  case 142: /* direct_declarator: direct_declarator SQBRAOPEN type_qualifier_list MUL SQBRACLOSE  */
#line 1100 "ass6_20CS10067_20CS30008.y"
                                                                         {}
#line 3361 "y.tab.c"
    break;

  case 143: /* direct_declarator: direct_declarator SQBRAOPEN MUL SQBRACLOSE  */
#line 1101 "ass6_20CS10067_20CS30008.y"
                                                     {}
#line 3367 "y.tab.c"
    break;

  case 144: /* direct_declarator: direct_declarator ROBRAOPEN CT parameter_type_list ROBRACLOSE  */
#line 1103 "ass6_20CS10067_20CS30008.y"
        {
		table->name = (yyvsp[-4].symp)->name;

		if ((yyvsp[-4].symp)->type->type !="VOID") 
		{
			// Lookup for return value
			sym *s = table->lookup("return");
			s->update((yyvsp[-4].symp)->type);		
		}
		(yyvsp[-4].symp)->nested=table;
		(yyvsp[-4].symp)->category = "function";
		table->parent = globalTable;

		// Come back to globalsymbol table
		changeTable(globalTable);				
		currentSymbol = (yyval.symp);
	}
#line 3389 "y.tab.c"
    break;

  case 145: /* direct_declarator: direct_declarator ROBRAOPEN identifier_list ROBRACLOSE  */
#line 1120 "ass6_20CS10067_20CS30008.y"
                                                                 {}
#line 3395 "y.tab.c"
    break;

  case 146: /* direct_declarator: direct_declarator ROBRAOPEN CT ROBRACLOSE  */
#line 1122 "ass6_20CS10067_20CS30008.y"
        {
		table->name = (yyvsp[-3].symp)->name;

		if ((yyvsp[-3].symp)->type->type != "VOID") 
		{
			// Lookup for return value
			sym *s = table->lookup("return");
			s->update((yyvsp[-3].symp)->type);		
		}
		(yyvsp[-3].symp)->nested=table;
		(yyvsp[-3].symp)->category = "function";
		
		table->parent = globalTable;

		// Come back to globalsymbol table
		changeTable(globalTable);				
		currentSymbol = (yyval.symp);
	}
#line 3418 "y.tab.c"
    break;

  case 147: /* CT: %empty  */
#line 1144 "ass6_20CS10067_20CS30008.y"
        { 															
		// Used for changing to symbol table for a function

		// Function symbol table doesn't already exist
		if (currentSymbol->nested==NULL) changeTable(new symtable(""));	
		// Function symbol table already exists
		else 
		{
			changeTable(currentSymbol ->nested);						
			emit("FUNC", table->name);
		}
	}
#line 3435 "y.tab.c"
    break;

  case 148: /* pointer: MUL type_qualifier_list  */
#line 1159 "ass6_20CS10067_20CS30008.y"
                                {}
#line 3441 "y.tab.c"
    break;

  case 149: /* pointer: MUL  */
#line 1161 "ass6_20CS10067_20CS30008.y"
        {
		// Create new pointer
		(yyval.symtp) = new symtype("PTR");
	}
#line 3450 "y.tab.c"
    break;

  case 150: /* pointer: MUL type_qualifier_list pointer  */
#line 1165 "ass6_20CS10067_20CS30008.y"
                                         {}
#line 3456 "y.tab.c"
    break;

  case 151: /* pointer: MUL pointer  */
#line 1167 "ass6_20CS10067_20CS30008.y"
        {
		// Create new pointer
		(yyval.symtp) = new symtype("PTR", (yyvsp[0].symtp));
	}
#line 3465 "y.tab.c"
    break;

  case 152: /* type_qualifier_list: type_qualifier  */
#line 1174 "ass6_20CS10067_20CS30008.y"
                       {}
#line 3471 "y.tab.c"
    break;

  case 153: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 1175 "ass6_20CS10067_20CS30008.y"
                                            {}
#line 3477 "y.tab.c"
    break;

  case 154: /* parameter_type_list: parameter_list  */
#line 1179 "ass6_20CS10067_20CS30008.y"
                       {}
#line 3483 "y.tab.c"
    break;

  case 155: /* parameter_type_list: parameter_list COMMA DOTS  */
#line 1180 "ass6_20CS10067_20CS30008.y"
                                   {}
#line 3489 "y.tab.c"
    break;

  case 156: /* parameter_list: parameter_declaration  */
#line 1184 "ass6_20CS10067_20CS30008.y"
                              {}
#line 3495 "y.tab.c"
    break;

  case 157: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 1185 "ass6_20CS10067_20CS30008.y"
                                                    {}
#line 3501 "y.tab.c"
    break;

  case 158: /* parameter_declaration: declaration_specifiers declarator  */
#line 1190 "ass6_20CS10067_20CS30008.y"
        {
		(yyvsp[0].symp)->category = "param";
	}
#line 3509 "y.tab.c"
    break;

  case 159: /* parameter_declaration: declaration_specifiers  */
#line 1193 "ass6_20CS10067_20CS30008.y"
                                {}
#line 3515 "y.tab.c"
    break;

  case 160: /* identifier_list: IDENTIFIER  */
#line 1197 "ass6_20CS10067_20CS30008.y"
                   {}
#line 3521 "y.tab.c"
    break;

  case 161: /* identifier_list: identifier_list COMMA IDENTIFIER  */
#line 1198 "ass6_20CS10067_20CS30008.y"
                                          {}
#line 3527 "y.tab.c"
    break;

  case 162: /* type_name: specifier_qualifier_list  */
#line 1202 "ass6_20CS10067_20CS30008.y"
                                 {}
#line 3533 "y.tab.c"
    break;

  case 163: /* initializer: assignment_expression  */
#line 1207 "ass6_20CS10067_20CS30008.y"
        {
		// Assignment
		(yyval.symp) = (yyvsp[0].E)->loc;
	}
#line 3542 "y.tab.c"
    break;

  case 164: /* initializer: CURBRAOPEN initializer_list CURBRACLOSE  */
#line 1211 "ass6_20CS10067_20CS30008.y"
                                                 {}
#line 3548 "y.tab.c"
    break;

  case 165: /* initializer: CURBRAOPEN initializer_list COMMA CURBRACLOSE  */
#line 1212 "ass6_20CS10067_20CS30008.y"
                                                       {}
#line 3554 "y.tab.c"
    break;

  case 166: /* initializer_list: designation initializer  */
#line 1217 "ass6_20CS10067_20CS30008.y"
                                {}
#line 3560 "y.tab.c"
    break;

  case 167: /* initializer_list: initializer  */
#line 1218 "ass6_20CS10067_20CS30008.y"
                     {}
#line 3566 "y.tab.c"
    break;

  case 168: /* initializer_list: initializer_list COMMA designation initializer  */
#line 1219 "ass6_20CS10067_20CS30008.y"
                                                        {}
#line 3572 "y.tab.c"
    break;

  case 169: /* initializer_list: initializer_list COMMA initializer  */
#line 1220 "ass6_20CS10067_20CS30008.y"
                                            {}
#line 3578 "y.tab.c"
    break;

  case 170: /* designation: designator_list ASSIGN  */
#line 1224 "ass6_20CS10067_20CS30008.y"
                               {}
#line 3584 "y.tab.c"
    break;

  case 171: /* designator_list: designator  */
#line 1228 "ass6_20CS10067_20CS30008.y"
                   {}
#line 3590 "y.tab.c"
    break;

  case 172: /* designator_list: designator_list designator  */
#line 1229 "ass6_20CS10067_20CS30008.y"
                                    {}
#line 3596 "y.tab.c"
    break;

  case 173: /* designator: SQBRAOPEN constant_expression SQBRACLOSE  */
#line 1233 "ass6_20CS10067_20CS30008.y"
                                                 {}
#line 3602 "y.tab.c"
    break;

  case 174: /* designator: DOT IDENTIFIER  */
#line 1234 "ass6_20CS10067_20CS30008.y"
                        {}
#line 3608 "y.tab.c"
    break;

  case 175: /* statement: labeled_statement  */
#line 1238 "ass6_20CS10067_20CS30008.y"
                          {}
#line 3614 "y.tab.c"
    break;

  case 176: /* statement: compound_statement  */
#line 1240 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.S)=(yyvsp[0].S);
	}
#line 3623 "y.tab.c"
    break;

  case 177: /* statement: expression_statement  */
#line 1245 "ass6_20CS10067_20CS30008.y"
        {
		// Create new statement with same nextlist
		(yyval.S) = new statement();
		(yyval.S)->nextlist = (yyvsp[0].E)->nextlist;
	}
#line 3633 "y.tab.c"
    break;

  case 178: /* statement: selection_statement  */
#line 1251 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.S)=(yyvsp[0].S);
	}
#line 3642 "y.tab.c"
    break;

  case 179: /* statement: iteration_statement  */
#line 1256 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.S)=(yyvsp[0].S);
	}
#line 3651 "y.tab.c"
    break;

  case 180: /* statement: jump_statement  */
#line 1261 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.S)=(yyvsp[0].S);
	}
#line 3660 "y.tab.c"
    break;

  case 181: /* labeled_statement: IDENTIFIER COLON statement  */
#line 1269 "ass6_20CS10067_20CS30008.y"
        {
		// Create new statement
		(yyval.S) = new statement();
	}
#line 3669 "y.tab.c"
    break;

  case 182: /* labeled_statement: CASE constant_expression COLON statement  */
#line 1274 "ass6_20CS10067_20CS30008.y"
        {
		// Create new statement
		(yyval.S) = new statement();
	}
#line 3678 "y.tab.c"
    break;

  case 183: /* labeled_statement: DEFAULT COLON statement  */
#line 1279 "ass6_20CS10067_20CS30008.y"
        {
		// Create new statement
		(yyval.S) = new statement();
	}
#line 3687 "y.tab.c"
    break;

  case 184: /* compound_statement: CURBRAOPEN block_item_list CURBRACLOSE  */
#line 1287 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.S)=(yyvsp[-1].S);
	}
#line 3696 "y.tab.c"
    break;

  case 185: /* compound_statement: CURBRAOPEN CURBRACLOSE  */
#line 1292 "ass6_20CS10067_20CS30008.y"
        {
		// Create new statement
		(yyval.S) = new statement();
	}
#line 3705 "y.tab.c"
    break;

  case 186: /* block_item_list: block_item  */
#line 1300 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.S)=(yyvsp[0].S);
	}
#line 3714 "y.tab.c"
    break;

  case 187: /* block_item_list: block_item_list M block_item  */
#line 1305 "ass6_20CS10067_20CS30008.y"
        {
		// After $1, move to block_item via $2
		(yyval.S)=(yyvsp[0].S);
		backpatch((yyvsp[-2].S)->nextlist, (yyvsp[-1].instr));
	}
#line 3724 "y.tab.c"
    break;

  case 188: /* block_item: declaration  */
#line 1314 "ass6_20CS10067_20CS30008.y"
        {
		// New statement
		(yyval.S) = new statement();
	}
#line 3733 "y.tab.c"
    break;

  case 189: /* block_item: statement  */
#line 1319 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.S) = (yyvsp[0].S);
	}
#line 3742 "y.tab.c"
    break;

  case 190: /* expression_statement: expression SEMICOLON  */
#line 1327 "ass6_20CS10067_20CS30008.y"
        {
		// Simply equate
		(yyval.E)=(yyvsp[-1].E);
	}
#line 3751 "y.tab.c"
    break;

  case 191: /* expression_statement: SEMICOLON  */
#line 1332 "ass6_20CS10067_20CS30008.y"
        {
		// New expression
		(yyval.E) = new expr();
	}
#line 3760 "y.tab.c"
    break;

  case 192: /* selection_statement: IF ROBRAOPEN expression N ROBRACLOSE M statement N  */
#line 1340 "ass6_20CS10067_20CS30008.y"
        {
		// If stmt without else
		backpatch((yyvsp[-4].S)->nextlist, nextinstr());						// Nextlist of N goes to nextinstr
		convertInt2Bool((yyvsp[-5].E));							 			// Convert expression to bool	
		(yyval.S) = new statement();										// Make new statement
		backpatch((yyvsp[-5].E)->truelist, (yyvsp[-2].instr));								// Is expression is true, go to M i.e just before statement body
		list<int> temp = merge((yyvsp[-5].E)->falselist, (yyvsp[-1].S)->nextlist); 		// Mergefalselist of expression, nextlist of statement and second N
		(yyval.S)->nextlist = merge((yyvsp[0].S)->nextlist, temp);
	}
#line 3774 "y.tab.c"
    break;

  case 193: /* selection_statement: IF ROBRAOPEN expression N ROBRACLOSE M statement N ELSE M statement  */
#line 1350 "ass6_20CS10067_20CS30008.y"
        {
		// If stmt with else
		backpatch((yyvsp[-7].S)->nextlist, nextinstr());						// Nextlist of N goes to nextinstr
		convertInt2Bool((yyvsp[-8].E));										// Convert expression to bool
		(yyval.S) = new statement();										// Create new statement
		backpatch((yyvsp[-8].E)->truelist, (yyvsp[-5].instr));								// When expression is true, go to M1 else go to M2
		backpatch((yyvsp[-8].E)->falselist, (yyvsp[-1].instr));
		list<int> temp = merge((yyvsp[-4].S)->nextlist, (yyvsp[-3].S)->nextlist);			// Mergethe nextlists of the statements and second N
		(yyval.S)->nextlist = merge((yyvsp[0].S)->nextlist,temp);
	}
#line 3789 "y.tab.c"
    break;

  case 194: /* selection_statement: SWITCH ROBRAOPEN expression ROBRACLOSE statement  */
#line 1360 "ass6_20CS10067_20CS30008.y"
                                                          {}
#line 3795 "y.tab.c"
    break;

  case 195: /* iteration_statement: WHILE M ROBRAOPEN expression ROBRACLOSE M statement  */
#line 1365 "ass6_20CS10067_20CS30008.y"
        {
		// Create new statement
		(yyval.S) = new statement();
		// Convert int expression to bool
		convertInt2Bool((yyvsp[-3].E));

		// M1 to go back to boolean again
		// M2 to go to statement if the boolean is true
		backpatch((yyvsp[0].S)->nextlist, (yyvsp[-5].instr));
		backpatch((yyvsp[-3].E)->truelist, (yyvsp[-1].instr));
		(yyval.S)->nextlist = (yyvsp[-3].E)->falselist;

		stringstream strs;
	    strs << (yyvsp[-5].instr);
	    string temp_str = strs.str();
	    char* intStr = (char*) temp_str.c_str();
		string str = string(intStr);
		// Emitto prevent fallthrough
		emit("GOTOOP", str);
	}
#line 3820 "y.tab.c"
    break;

  case 196: /* iteration_statement: DO M statement M WHILE ROBRAOPEN expression ROBRACLOSE SEMICOLON  */
#line 1386 "ass6_20CS10067_20CS30008.y"
        {
		// Create new statement
		(yyval.S) = new statement();
		// Convert int expression to bool
		convertInt2Bool((yyvsp[-2].E));
		// M1 to go back to statement if expression is true
		// M2 to go to check expression if statement is complete
		backpatch((yyvsp[-2].E)->truelist, (yyvsp[-7].instr));
		backpatch((yyvsp[-6].S)->nextlist, (yyvsp[-5].instr));

		// Some bug in the next statement
		(yyval.S)->nextlist = (yyvsp[-2].E)->falselist;
	}
#line 3838 "y.tab.c"
    break;

  case 197: /* iteration_statement: FOR ROBRAOPEN expression_statement M expression_statement ROBRACLOSE M statement  */
#line 1400 "ass6_20CS10067_20CS30008.y"
        {
		// Create new statement
		(yyval.S) = new statement();
		// Convert int expression to bool
		convertInt2Bool((yyvsp[-3].E));

		// Standard back-patching principles
		backpatch((yyvsp[-3].E)->truelist, (yyvsp[-1].instr));
		backpatch((yyvsp[0].S)->nextlist, (yyvsp[-4].instr));

		stringstream strs;
	    strs << (yyvsp[-4].instr);
	    string temp_str = strs.str();
	    char* intStr = (char*) temp_str.c_str();
		string str = string(intStr);

		// Prevent fallthrough
		emit("GOTOOP", str);
		(yyval.S)->nextlist = (yyvsp[-3].E)->falselist;
	}
#line 3863 "y.tab.c"
    break;

  case 198: /* iteration_statement: FOR ROBRAOPEN expression_statement M expression_statement M expression N ROBRACLOSE M statement  */
#line 1421 "ass6_20CS10067_20CS30008.y"
        {
		// Create new statement
		(yyval.S) = new statement();
		// Convert int expression_statement to bool
		convertInt2Bool((yyvsp[-6].E));

		// Simple back-patching principles
		backpatch((yyvsp[-6].E)->truelist, (yyvsp[-1].instr));
		backpatch((yyvsp[-3].S)->nextlist, (yyvsp[-7].instr));
		backpatch((yyvsp[0].S)->nextlist, (yyvsp[-5].instr));

		stringstream strs;
	    strs << (yyvsp[-5].instr);
	    string temp_str = strs.str();
	    char* intStr = (char*) temp_str.c_str();
		string str = string(intStr);

		// Prevent fallthrough
		emit("GOTOOP", str);
		(yyval.S)->nextlist = (yyvsp[-6].E)->falselist;
	}
#line 3889 "y.tab.c"
    break;

  case 199: /* jump_statement: GOTO IDENTIFIER SEMICOLON  */
#line 1445 "ass6_20CS10067_20CS30008.y"
                                  {(yyval.S) = new statement();}
#line 3895 "y.tab.c"
    break;

  case 200: /* jump_statement: CONTINUE SEMICOLON  */
#line 1446 "ass6_20CS10067_20CS30008.y"
                            {(yyval.S) = new statement();}
#line 3901 "y.tab.c"
    break;

  case 201: /* jump_statement: BREAK SEMICOLON  */
#line 1447 "ass6_20CS10067_20CS30008.y"
                         {(yyval.S) = new statement();}
#line 3907 "y.tab.c"
    break;

  case 202: /* jump_statement: RETURN expression SEMICOLON  */
#line 1449 "ass6_20CS10067_20CS30008.y"
        {
		// Emitreturn with the name of the return value
		(yyval.S) = new statement();
		emit("RETURN",(yyvsp[-1].E)->loc->name);
	}
#line 3917 "y.tab.c"
    break;

  case 203: /* jump_statement: RETURN SEMICOLON  */
#line 1455 "ass6_20CS10067_20CS30008.y"
        {
		// Simply emitreturn
		(yyval.S) = new statement();
		emit("RETURN","");
	}
#line 3927 "y.tab.c"
    break;

  case 204: /* translation_unit: external_declaration  */
#line 1463 "ass6_20CS10067_20CS30008.y"
                             {}
#line 3933 "y.tab.c"
    break;

  case 205: /* translation_unit: translation_unit external_declaration  */
#line 1464 "ass6_20CS10067_20CS30008.y"
                                               {}
#line 3939 "y.tab.c"
    break;

  case 206: /* external_declaration: function_definition  */
#line 1468 "ass6_20CS10067_20CS30008.y"
                            {}
#line 3945 "y.tab.c"
    break;

  case 207: /* external_declaration: declaration  */
#line 1469 "ass6_20CS10067_20CS30008.y"
                     {}
#line 3951 "y.tab.c"
    break;

  case 208: /* function_definition: declaration_specifiers declarator declaration_list CT compound_statement  */
#line 1473 "ass6_20CS10067_20CS30008.y"
                                                                                 {}
#line 3957 "y.tab.c"
    break;

  case 209: /* function_definition: declaration_specifiers declarator CT compound_statement  */
#line 1475 "ass6_20CS10067_20CS30008.y"
        {
		emit("FUNCEND", table->name);
		table->parent = globalTable;
		// Once we come back to this at the end, change the table to global Symbol table
		changeTable(globalTable);
	}
#line 3968 "y.tab.c"
    break;

  case 210: /* declaration_list: declaration  */
#line 1484 "ass6_20CS10067_20CS30008.y"
                    {}
#line 3974 "y.tab.c"
    break;

  case 211: /* declaration_list: declaration_list declaration  */
#line 1485 "ass6_20CS10067_20CS30008.y"
                                      {}
#line 3980 "y.tab.c"
    break;


#line 3984 "y.tab.c"

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
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

  return yyresult;
}

#line 1490 "ass6_20CS10067_20CS30008.y"


void yyerror(string s) {
    cout<<s<<endl;
}
