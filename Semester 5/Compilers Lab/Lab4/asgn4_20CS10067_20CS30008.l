/* Compilers Assignment - 4 */
/* Atishay Jain (20CS30008) */
/* Suvvari Venkata Sai Suvvari (20CS10067) */

/* Declarations */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include "y.tab.h"
    int line_no = 1;
%}

%x MULTI_LINE_COMMENT
%x SINGLE_LINE_COMMENT

IDENTIFIER              {IDENTIFIER_NONDIGIT}({IDENTIFIER_NONDIGIT}|{DIGIT})*

IDENTIFIER_NONDIGIT     [_a-zA-Z]

DIGIT                   [0-9]

CONSTANTS				{INTEGER_CONSTANT}|{FLOATING_CONSTANT}|{ENUMERATION_CONSTANT}|{CHARACTER_CONSTANT}

INTEGER_CONSTANT        {NONZERO_DIGIT}{DIGIT}*|"0"

NONZERO_DIGIT           [1-9]

FLOATING_CONSTANT       {FRACTIONAL_CONSTANT}{EXPONENT_PART}?|{DIGIT_SEQUENCE}{EXPONENT_PART}

FRACTIONAL_CONSTANT     {DIGIT_SEQUENCE}?\.{DIGIT_SEQUENCE}|{DIGIT_SEQUENCE}\.

EXPONENT_PART           "e"{SIGN}?{DIGIT_SEQUENCE}|"E"{SIGN}?{DIGIT_SEQUENCE}

SIGN                    [+-]

DIGIT_SEQUENCE          {DIGIT}+

ENUMERATION_CONSTANT    {IDENTIFIER}

CHARACTER_CONSTANT      \'{C_CHAR_SEQUENCE}\'

C_CHAR_SEQUENCE         {C_CHAR}+

C_CHAR                  [^\'\n\\]|{ESCAPE_SEQUENCE}

ESCAPE_SEQUENCE         \\['"?\\abfnrtv]    

STRING_LITERAL          \"{S_CHAR_SEQUENCE}?\"

S_CHAR_SEQUENCE         {S_CHAR}+

S_CHAR                  [^\"\n\\]|{ESCAPE_SEQUENCE}

WHITESPACE              [ \t\v]

NEWLINE                 \n

/* Transition rules */
%%

"void"                          { return VOID; }
"char"                          { return CHAR; }
"short"                         { return SHORT; }
"int"                           { return INT; }
"long"                          { return LONG; }
"float"                         { return FLOAT; }
"double"                        { return DOUBLE; }
"signed"                        { return SIGNED; }
"unsigned"                      { return UNSIGNED; }
"extern"                        { return EXTERN; }
"static"                        { return STATIC; }
"auto"                          { return AUTO; }
"register"                      { return REGISTER; }
"_Bool"                         { return BOOL; }
"_Complex"                      { return COMPLEX; }
"_Imaginary"                    { return IMAGINARY; }
"enum"                          { return ENUM; }
"const"                         { return CONST; }
"restrict"                      { return RESTRICT; }
"volatile"                      { return VOLATILE; }
"inline"                        { return INLINE; }
"break"                         { return BREAK; }
"case"                          { return CASE; }
"continue"                      { return CONTINUE; }
"default"                       { return DEFAULT; }
"goto"                          { return GOTO; }
"if"                            { return IF; }
"else"                          { return ELSE; }
"for"                           { return FOR; }
"do"                            { return DO; }
"while"                         { return WHILE; }
"switch"                        { return SWITCH; }
"return"                        { return RETURN; }
"struct"                        { return STRUCT; }
"union"                         { return UNION; }
"typedef"                       { return TYPEDEF; }
"sizeof"                        { return SIZEOF; }

{IDENTIFIER}                    { yylval.identifierVal = strdup(yytext); return IDENTIFIER; }
{INTEGER_CONSTANT}              { yylval.intVal = atoi(yytext); return INTEGER_CONSTANT; }
{FLOATING_CONSTANT}             { yylval.floatVal = atof(yytext); return FLOATING_CONSTANT; }
{CHARACTER_CONSTANT}            { yylval.charVal = strdup(yytext); return CHARACTER_CONSTANT; }
{STRING_LITERAL}                { yylval.stringVal = strdup(yytext); return STRING_LITERAL; }

"?"                             { return QUESTION_MARK; }
","                             { return COMMA; }
":"                             { return COLON; }
";"                             { return SEMI_COLON; }
"..."                           { return ELLIPSIS; }
"#"                             { return HASH; }
"->"                            { return ARROW; }
"++"                            { return INCREMENT; }
"--"                            { return DECREMENT; }
"=="                            { return EQUALS; }
"^="                            { return BITWISE_XOR_ASSIGNMENT; }
"^"                             { return BITWISE_XOR; }
"&="                            { return BITWISE_AND_ASSIGNMENT; }
"&"                             { return BITWISE_AND; }
"|="                            { return BITWISE_OR_ASSIGNMENT; }
"|"                             { return BITWISE_OR; }
"<<="                           { return LEFT_SHIFT_ASSIGNMENT; }
"<<"                            { return LEFT_SHIFT; }
">>="                           { return RIGHT_SHIFT_ASSIGNMENT; }
">>"                            { return RIGHT_SHIFT; }
"!="                            { return NOT_EQUALS; }
"!"                             { return EXCLAMATION; }
"."                             { return DOT; }
"="                             { return ASSIGNMENT; }
"+="                            { return PLUS_ASSIGNMENT; }
"+"                             { return PLUS; }
"-="                            { return MINUS_ASSIGNMENT; }
"-"                             { return MINUS; }
"*="                            { return ASTERISK_ASSIGNMENT; }
"*"                             { return ASTERISK; }
"/="                            { return SLASH_ASSIGNMENT; }
"/"                             { return SLASH; }
"~"                             { return TILDE; }
"%="                            { return MODULO_ASSIGNMENT; }
"%"                             { return MODULO; }
"&&"                            { return LOGICAL_AND; }
"||"                            { return LOGICAL_OR; }
"<="                            { return LESS_EQUAL_THAN; }
"<"                             { return LESS_THAN; }
">="                            { return GREATER_EQUAL_THAN; }
">"                             { return GREATER_THAN; }
"["                             { return LEFT_SQUARE_BRACKET; }
"]"                             { return RIGHT_SQUARE_BRACKET; }
"{"                             { return LEFT_CURLY_BRACKET; }
"}"                             { return RIGHT_CURLY_BRACKET; }
"("                             { return LEFT_PARENTHESES; }
")"                             { return RIGHT_PARENTHESES; }

"/*"                            { BEGIN(MULTI_LINE_COMMENT); }
<MULTI_LINE_COMMENT>"*/"        { BEGIN(INITIAL); }
<MULTI_LINE_COMMENT>.           { /* Ignore comment body */}
<MULTI_LINE_COMMENT>"\n"        { /* Ignore comment body */}

"//"                            { BEGIN(SINGLE_LINE_COMMENT); }
<SINGLE_LINE_COMMENT>["\n"]     { BEGIN(INITIAL); }
<SINGLE_LINE_COMMENT>.          { /* Ignore comment body */}

{NEWLINE}                       { line_no++; printf("\n\n\n"); }
.                               { printf("Error in line no. %d: Invalid token \"%s\"\n", line_no, yytext); return INVALID_TOKEN; }
{WHITESPACE}                    { /*Ignore White Space*/ }

%%