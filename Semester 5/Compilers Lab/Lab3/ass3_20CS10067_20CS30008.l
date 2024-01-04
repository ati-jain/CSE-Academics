/* Compilers Assignment - 3 */
/* Atishay Jain (20CS30008) */
/* Suvvari Venkata Sai Suvvari (20CS10067) */

/* Declarations */
%{
    #define KEYWORD                 1
	#define IDENTIFIER              2
	#define CONSTANT                3
	#define STRING_LITERAL          4
	#define PUNCTUATOR              5
    #define INVALID_TOKEN           -1
%}

%x MULTI_LINE_COMMENT
%x SINGLE_LINE_COMMENT
 
KEYWORD                 "auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inline"|"int"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"_Bool"|"_Complex"|"_Imaginary"

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

PUNCTUATOR              "["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|","|"#"

WHITESPACE              [ \n\t\v]

/* Transition rules */
%%

{KEYWORD}                       { return KEYWORD; }
{IDENTIFIER}                    { return IDENTIFIER; }
{CONSTANTS}					    { return CONSTANT; }
{STRING_LITERAL}                { return STRING_LITERAL; }
{PUNCTUATOR}                    { return PUNCTUATOR; }
"/*"                            { BEGIN(MULTI_LINE_COMMENT); }
<MULTI_LINE_COMMENT>"*/"        { BEGIN(INITIAL); }
<MULTI_LINE_COMMENT>.           { /* Ignore comment body */}
<MULTI_LINE_COMMENT>"\n"        { /* Ignore comment body */}

"//"                            { BEGIN(SINGLE_LINE_COMMENT); }
<SINGLE_LINE_COMMENT>["\n"]     { BEGIN(INITIAL); }
<SINGLE_LINE_COMMENT>.          { /* Ignore comment body */}

{WHITESPACE}                    { /* Ignore whitespace */ }
.                               { return INVALID_TOKEN; }

%%