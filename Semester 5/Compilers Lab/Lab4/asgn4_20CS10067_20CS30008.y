%{
    #include <stdio.h>
    extern int yylex();
    extern int line_no;
    void yyerror(char *);
%}

%union {
    int intVal;
    float floatVal;
    char *charVal;
    char *stringVal;
    char *identifierVal;
}

%token EXTERN STATIC AUTO REGISTER
%token VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED BOOL COMPLEX IMAGINARY ENUM
%token CONST RESTRICT VOLATILE INLINE
%token BREAK CASE CONTINUE DEFAULT GOTO
%token IF ELSE FOR DO WHILE SWITCH
%token RETURN SIZEOF
%token STRUCT TYPEDEF UNION

%token<stringVal> IDENTIFIER
%token<intVal> INTEGER_CONSTANT
%token<floatVal> FLOATING_CONSTANT
%token<charVal> CHARACTER_CONSTANT
%token<stringVal> STRING_LITERAL

%token QUESTION_MARK COMMA COLON SEMI_COLON ELLIPSIS HASH ARROW
%token INCREMENT DECREMENT EQUALS BITWISE_XOR_ASSIGNMENT BITWISE_XOR BITWISE_AND_ASSIGNMENT BITWISE_AND BITWISE_OR_ASSIGNMENT BITWISE_OR LEFT_SHIFT_ASSIGNMENT LEFT_SHIFT RIGHT_SHIFT_ASSIGNMENT RIGHT_SHIFT
%token NOT_EQUALS EXCLAMATION DOT ASSIGNMENT PLUS_ASSIGNMENT PLUS MINUS_ASSIGNMENT MINUS ASTERISK_ASSIGNMENT ASTERISK SLASH_ASSIGNMENT SLASH TILDE MODULO_ASSIGNMENT MODULO
%token LOGICAL_AND LOGICAL_OR LESS_EQUAL_THAN LESS_THAN GREATER_EQUAL_THAN GREATER_THAN
%token LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET LEFT_CURLY_BRACKET RIGHT_CURLY_BRACKET LEFT_PARENTHESES RIGHT_PARENTHESES


%token INVALID_TOKEN

%nonassoc RIGHT_PARENTHESES
%nonassoc ELSE

%start translation_unit

%%

/* Expressions */

primary_expression: 
                    IDENTIFIER  { printf("LINE [%d] : primary_expression => IDENTIFIER\n", line_no); printf("\t\t\t\tIDENTIFIER = %s\n", $1); }
                    | INTEGER_CONSTANT  { printf("LINE [%d] : primary_expression => INTEGER_CONSTANT\n", line_no); printf("\t\t\t\tINTEGER_CONSTANT = %d\n", $1); }
                    | FLOATING_CONSTANT  { printf("LINE [%d] : primary_expression => FLOATING_CONSTANT\n", line_no); printf("\t\t\t\tFLOATING_CONSTANT = %f\n", $1); }
                    | CHARACTER_CONSTANT  { printf("LINE [%d] : primary_expression => CHARACTER_CONSTANT\n", line_no); printf("\t\t\t\tCHARACTER_CONSTANT = %s\n", $1); }
                    | STRING_LITERAL  { printf("LINE [%d] : primary_expression => STRING_LITERAL\n", line_no); printf("\t\t\t\tSTRING_LITERAL = %s\n", $1); }
                    | LEFT_PARENTHESES expression RIGHT_PARENTHESES { printf("LINE [%d] : primary_expression => ( expression )\n", line_no); }
                    ;

postfix_expression:
                    primary_expression { printf("LINE [%d] : postfix_expression => primary_expression\n", line_no); }
                    | postfix_expression LEFT_SQUARE_BRACKET expression RIGHT_SQUARE_BRACKET { printf("LINE [%d] : postfix_expression => postfix_expression [ expression ]\n", line_no); }
                    | postfix_expression LEFT_PARENTHESES argument_expression_list_opt RIGHT_PARENTHESES { printf("LINE [%d] : postfix_expression => postfix_expression ( argument_expression_list_opt )\n", line_no); }
                    | postfix_expression DOT IDENTIFIER { printf("LINE [%d] : postfix_expression => postfix_expression . IDENTIFIER\n", line_no); printf("\t\t\t\tIDENTIFIER = %s\n", $3); }
                    | postfix_expression ARROW IDENTIFIER { printf("LINE [%d] : postfix_expression => postfix_expression -> IDENTIFIER\n", line_no); printf("\t\t\t\tIDENTIFIER = %s\n", $3); }
                    | postfix_expression INCREMENT { printf("LINE [%d] : postfix_expression => postfix_expression ++\n", line_no); }
                    | postfix_expression DECREMENT { printf("LINE [%d] : postfix_expression => postfix_expression --\n", line_no); }
                    | LEFT_PARENTHESES type_name RIGHT_PARENTHESES LEFT_CURLY_BRACKET initialiser_list RIGHT_CURLY_BRACKET { printf("LINE [%d] : postfix_expression => ( type_name ) { initialiser_list }\n", line_no); }
                    | LEFT_PARENTHESES type_name RIGHT_PARENTHESES LEFT_CURLY_BRACKET initialiser_list COMMA RIGHT_CURLY_BRACKET { printf("LINE [%d] : postfix_expression => ( type_name ) { initialiser_list , }\n", line_no); }
                    ;

argument_expression_list_opt:
                                argument_expression_list { printf("LINE [%d] : argument_expression_list_opt => argument_expression_list\n", line_no); }
                                | { printf("LINE [%d] : argument_expression_list_opt => epsilon\n", line_no); }
                                ;

argument_expression_list:
                            assignment_expression { printf("LINE [%d] : argument_expression_list => assignment_expression\n", line_no); }
                            | argument_expression_list COMMA assignment_expression { printf("LINE [%d] : argument_expression_list => argument_expression_list , assignment_expression\n", line_no); }
                            ;

unary_expression:
                    postfix_expression { printf("LINE [%d] : unary_expression => postfix_expression\n", line_no); }
                    | INCREMENT unary_expression { printf("LINE [%d] : unary_expression => ++ unary_expression\n", line_no); }
                    | DECREMENT unary_expression { printf("LINE [%d] : unary_expression => -- unary_expression\n", line_no); }
                    | unary_operator cast_expression { printf("LINE [%d] : unary_expression => unary_operator cast_expression\n", line_no); }
                    | SIZEOF unary_expression { printf("LINE [%d] : unary_expression => sizeof unary_expression\n", line_no); }
                    | SIZEOF LEFT_PARENTHESES type_name RIGHT_PARENTHESES { printf("LINE [%d] : unary_expression => sizeof ( type_name )\n", line_no); }
                    ;

unary_operator:
                BITWISE_AND { printf("LINE [%d] : unary_operator => &\n", line_no); }
                | ASTERISK { printf("LINE [%d] : unary_operator => *\n", line_no); }
                | PLUS { printf("LINE [%d] : unary_operator => +\n", line_no); }
                | MINUS { printf("LINE [%d] : unary_operator => -\n", line_no); }
                | TILDE { printf("LINE [%d] : unary_operator => ~\n", line_no); }
                | EXCLAMATION { printf("LINE [%d] : unary_operator => !\n", line_no); }
                ;

cast_expression:
                unary_expression { printf("LINE [%d] : cast_expression => unary_expression\n", line_no); }
                | LEFT_PARENTHESES type_name RIGHT_PARENTHESES cast_expression { printf("LINE [%d] : cast_expression => ( type_name ) cast_expression\n", line_no); }
                ;

multiplicative_expression:
                            cast_expression { printf("LINE [%d] : multiplicative_expression => cast_expression\n", line_no); }
                            | multiplicative_expression ASTERISK cast_expression { printf("LINE [%d] : multiplicative_expression => multiplicative_expression * cast_expression\n", line_no); }
                            | multiplicative_expression SLASH cast_expression { printf("LINE [%d] : multiplicative_expression => multiplicative_expression / cast_expression\n", line_no); }
                            | multiplicative_expression MODULO cast_expression { printf("LINE [%d] : multiplicative_expression => multiplicative_expression %% cast_expression\n", line_no); }
                            ;

additive_expression:
                    multiplicative_expression { printf("LINE [%d] : additive_expression => multiplicative_expression\n", line_no); }
                    | additive_expression PLUS multiplicative_expression { printf("LINE [%d] : additive_expression => additive_expression + multiplicative_expression\n", line_no); }
                    | additive_expression MINUS multiplicative_expression { printf("LINE [%d] : additive_expression => additive_expression - multiplicative_expression\n", line_no); }
                    ;

shift_expression:
                    additive_expression { printf("LINE [%d] : shift_expression => additive_expression\n", line_no); }
                    | shift_expression LEFT_SHIFT additive_expression { printf("LINE [%d] : shift_expression => shift_expression << additive_expression\n", line_no); }
                    | shift_expression RIGHT_SHIFT additive_expression { printf("LINE [%d] : shift_expression => shift_expression >> additive_expression\n", line_no); }
                    ;

relational_expression:
                        shift_expression { printf("LINE [%d] : relational_expression => shift_expression\n", line_no); }
                        | relational_expression LESS_THAN shift_expression { printf("LINE [%d] : relational_expression => relational_expression < shift_expression\n", line_no); }
                        | relational_expression GREATER_THAN shift_expression { printf("LINE [%d] : relational_expression => relational_expression > shift_expression\n", line_no); }
                        | relational_expression LESS_EQUAL_THAN shift_expression { printf("LINE [%d] : relational_expression => relational_expression <= shift_expression\n", line_no); }
                        | relational_expression GREATER_EQUAL_THAN shift_expression { printf("LINE [%d] : relational_expression => relational_expression >= shift_expression\n", line_no); }
                        ;

equality_expression:
                    relational_expression { printf("LINE [%d] : equality_expression => relational_expression\n", line_no); }
                    | equality_expression EQUALS relational_expression { printf("LINE [%d] : equality_expression => equality_expression == relational_expression\n", line_no); }
                    | equality_expression NOT_EQUALS relational_expression { printf("LINE [%d] : equality_expression => equality_expression != relational_expression\n", line_no); }
                    ;

AND_expression:
                equality_expression { printf("LINE [%d] : AND_expression => equality_expression\n", line_no); }
                | AND_expression BITWISE_AND equality_expression { printf("LINE [%d] : AND_expression => AND_expression & equality_expression\n", line_no); }
                ;

exclusive_OR_expression:
                        AND_expression { printf("LINE [%d] : exclusive_OR_expression => AND_expression\n", line_no); }
                        | exclusive_OR_expression BITWISE_XOR AND_expression { printf("LINE [%d] : exclusive_OR_expression => exclusive_OR_expression ^ AND_expression\n", line_no); }
                        ;

inclusive_OR_expression:
                        exclusive_OR_expression { printf("LINE [%d] : inclusive_OR_expression => exclusive_OR_expression\n", line_no); }
                        | inclusive_OR_expression BITWISE_OR exclusive_OR_expression { printf("LINE [%d] : inclusive_OR_expression => inclusive_OR_expression | exclusive_OR_expression\n", line_no); }
                        ;

logical_AND_expression:
                        inclusive_OR_expression { printf("LINE [%d] : logical_AND_expression => inclusive_OR_expression\n", line_no); }
                        | logical_AND_expression LOGICAL_AND inclusive_OR_expression { printf("LINE [%d] : logical_AND_expression => logical_AND_expression && inclusive_OR_expression\n", line_no); }
                        ;

logical_OR_expression:
                        logical_AND_expression { printf("LINE [%d] : logical_OR_expression => logical_AND_expression\n", line_no); }
                        | logical_OR_expression LOGICAL_OR logical_AND_expression { printf("LINE [%d] : logical_OR_expression => logical_OR_expression || logical_AND_expression\n", line_no); }
                        ;

conditional_expression:
                        logical_OR_expression { printf("LINE [%d] : conditional_expression => logical_OR_expression\n", line_no); }
                        | logical_OR_expression QUESTION_MARK expression COLON conditional_expression { printf("LINE [%d] : conditional_expression => logical_OR_expression ? expression : conditional_expression\n", line_no); }
                        ;

assignment_expression:
                        conditional_expression { printf("LINE [%d] : assignment_expression => conditional_expression\n", line_no); }
                        | unary_expression assignment_operator assignment_expression { printf("LINE [%d] : assignment_expression => unary_expression assignment_operator assignment_expression\n", line_no); }
                        ;

assignment_operator:
                    ASSIGNMENT { printf("LINE [%d] : assignment_operator => =\n", line_no); }
                    | ASTERISK_ASSIGNMENT { printf("LINE [%d] : assignment_operator => *=\n", line_no); }
                    | SLASH_ASSIGNMENT { printf("LINE [%d] : assignment_operator => /=\n", line_no); }
                    | MODULO_ASSIGNMENT { printf("LINE [%d] : assignment_operator => %%=\n", line_no); }
                    | PLUS_ASSIGNMENT { printf("LINE [%d] : assignment_operator => += \n", line_no); }
                    | MINUS_ASSIGNMENT { printf("LINE [%d] : assignment_operator => -= \n", line_no); }
                    | LEFT_SHIFT_ASSIGNMENT { printf("LINE [%d] : assignment_operator => <<=\n", line_no); }
                    | RIGHT_SHIFT_ASSIGNMENT { printf("LINE [%d] : assignment_operator => >>=\n", line_no); }
                    | BITWISE_AND_ASSIGNMENT { printf("LINE [%d] : assignment_operator => &=\n", line_no); }
                    | BITWISE_XOR_ASSIGNMENT { printf("LINE [%d] : assignment_operator => ^=\n", line_no); }
                    | BITWISE_OR_ASSIGNMENT { printf("LINE [%d] : assignment_operator => |=\n", line_no); }
                    ;

expression:
            assignment_expression { printf("LINE [%d] : expression => assignment_expression\n", line_no); }
            | expression COMMA assignment_expression { printf("LINE [%d] : expression => expression , assignment_expression\n", line_no); }
            ;

constant_expression:
                    conditional_expression { printf("LINE [%d] : constant_expression => conditional_expression\n", line_no); }
                    ;

/* Declarations */

declaration:
            declaration_specifiers init_declarator_list_opt SEMI_COLON { printf("LINE [%d] : declaration => declaration_specifiers init_declarator_list_opt ;\n", line_no); }
            ;

init_declarator_list_opt:
                            init_declarator_list { printf("LINE [%d] : init_declarator_list_opt => init_declarator_list\n", line_no); }
                            | { printf("LINE [%d] : init_declarator_list_opt => epsilon\n", line_no); }
                            ;

declaration_specifiers:
                        storage_class_specifier declaration_specifiers_opt { printf("LINE [%d] : declaration_specifiers => storage_class_specifier declaration_specifiers_opt\n", line_no); }
                        | type_specifier declaration_specifiers_opt { printf("LINE [%d] : declaration_specifiers => type_specifier declaration_specifiers_opt\n", line_no); }
                        | type_qualifier declaration_specifiers_opt { printf("LINE [%d] : declaration_specifiers => type_qualifier declaration_specifiers_opt\n", line_no); }
                        | function_specifier declaration_specifiers_opt { printf("LINE [%d] : declaration_specifiers => function_specifier declaration_specifiers_opt\n", line_no); }
                        ;

declaration_specifiers_opt:
                            declaration_specifiers { printf("LINE [%d] : declaration_specifiers_opt => declaration_specifiers\n", line_no); }
                            | { printf("LINE [%d] : declaration_specifiers_opt => epsilon \n", line_no); }
                            ;

init_declarator_list:
                        init_declarator { printf("LINE [%d] : init_declarator_list => init_declarator\n", line_no); }
                        | init_declarator_list COMMA init_declarator { printf("LINE [%d] : init_declarator_list => init_declarator_list , init_declarator\n", line_no); }
                        ;

init_declarator:
                declarator { printf("LINE [%d] : init_declarator => declarator\n", line_no); }
                | declarator ASSIGNMENT initialiser { printf("LINE [%d] : init_declarator => declarator = initialiser\n", line_no); }
                ;

storage_class_specifier:
                        EXTERN { printf("LINE [%d] : storage_class_specifier => extern\n", line_no); }
                        | STATIC { printf("LINE [%d] : storage_class_specifier => static\n", line_no); }
                        | AUTO { printf("LINE [%d] : storage_class_specifier => auto\n", line_no); }
                        | REGISTER { printf("LINE [%d] : storage_class_specifier => register\n", line_no); }
                        ;

type_specifier:
                VOID { printf("LINE [%d] : type_specifier => void\n", line_no); }
                | CHAR { printf("LINE [%d] : type_specifier => char\n", line_no); }
                | SHORT { printf("LINE [%d] : type_specifier => short\n", line_no); }
                | INT { printf("LINE [%d] : type_specifier => int\n", line_no); }
                | LONG { printf("LINE [%d] : type_specifier => long\n", line_no); }
                | FLOAT { printf("LINE [%d] : type_specifier => float\n", line_no); }
                | DOUBLE { printf("LINE [%d] : type_specifier => double\n", line_no); }
                | SIGNED { printf("LINE [%d] : type_specifier => signed\n", line_no); }
                | UNSIGNED { printf("LINE [%d] : type_specifier => unsigned\n", line_no); }
                | BOOL { printf("LINE [%d] : type_specifier => _Bool\n", line_no); }
                | COMPLEX { printf("LINE [%d] : type_specifier => _Complex\n", line_no); }
                | IMAGINARY { printf("LINE [%d] : type_specifier => _Imaginary\n", line_no); }
                | enum_specifier  { printf("LINE [%d] : type_specifier => enum_specifier\n", line_no); }
                ;

specifier_qualifier_list:
                            type_specifier specifier_qualifier_list_opt { printf("LINE [%d] : specifier_qualifier_list => type_specifier specifier_qualifier_list_opt\n", line_no); }
                            | type_qualifier specifier_qualifier_list_opt { printf("LINE [%d] : specifier_qualifier_list => type_qualifier specifier_qualifier_list_opt\n", line_no); }
                            ;

specifier_qualifier_list_opt:
                                specifier_qualifier_list { printf("LINE [%d] : specifier_qualifier_list_opt => specifier_qualifier_list\n", line_no); }
                                |  { printf("LINE [%d] : specifier_qualifier_list_opt => epsilon\n", line_no); }
                                ;

enum_specifier:
                ENUM identifier_opt LEFT_CURLY_BRACKET enumerator_list RIGHT_CURLY_BRACKET  { printf("LINE [%d] : enum_specifier => enum identifier_opt { enumerator_list }\n", line_no); }
                | ENUM identifier_opt LEFT_CURLY_BRACKET enumerator_list COMMA RIGHT_CURLY_BRACKET { printf("LINE [%d] : enum_specifier => enum identifier_opt { enumerator_list , }\n", line_no); }
                | ENUM IDENTIFIER { printf("LINE [%d] : enum_specifier => enum IDENTIFIER\n", line_no); printf("\t\t\t\tIDENTIFIER = %s\n", $2); }
                ;

identifier_opt:
                IDENTIFIER  { printf("LINE [%d] : identifier_opt => IDENTIFIER\n", line_no); printf("\t\t\t\tIDENTIFIER = %s\n", $1); }
                |  { printf("LINE [%d] : identifier_opt => epsilon\n", line_no); }
                ;

enumerator_list:
                enumerator  { printf("LINE [%d] : enumerator_list => enumerator\n", line_no); }
                | enumerator_list COMMA enumerator { printf("LINE [%d] : enumerator_list => enumerator_list , enumerator\n", line_no); }
                ;

enumerator:
            IDENTIFIER  { printf("LINE [%d] : enumerator => ENUMERATION_CONSTANT\n", line_no); printf("\t\t\t\tENUMERATION_CONSTANT = %s\n", $1); }
            | IDENTIFIER ASSIGNMENT constant_expression { printf("LINE [%d] : enumerator => ENUMERATION_CONSTANT = constant_expression\n", line_no); printf("\t\t\t\tENUMERATION_CONSTANT = %s\n", $1); }
            ;

type_qualifier:
                CONST { printf("LINE [%d] : type_qualifier => const\n", line_no); }
                | RESTRICT { printf("LINE [%d] : type_qualifier => restrict\n", line_no); }
                | VOLATILE { printf("LINE [%d] : type_qualifier => volatile\n", line_no); }
                ;

function_specifier:
                    INLINE { printf("LINE [%d] : function_specifier => inline\n", line_no); }
                    ;

declarator:
            pointer_opt direct_declarator { printf("LINE [%d] : declarator => pointer_opt direct_declarator\n", line_no); }
            ;

pointer_opt:
            pointer { printf("LINE [%d] : pointer_opt => pointer\n", line_no); }
            | { printf("LINE [%d] : pointer_opt => epsilon\n", line_no); }
            ;

direct_declarator:
                    IDENTIFIER  { printf("LINE [%d] : direct_declarator => IDENTIFIER\n", line_no); printf("\t\t\t\tIDENTIFIER = %s\n", $1); }
                    | LEFT_PARENTHESES declarator RIGHT_PARENTHESES { printf("LINE [%d] : direct_declarator => ( declarator )\n", line_no); }
                    | direct_declarator LEFT_SQUARE_BRACKET type_qualifier_list_opt assignment_expression_opt RIGHT_SQUARE_BRACKET { printf("LINE [%d] : direct_declarator => direct_declarator [ type_qualifier_list_opt assignment_expression_opt ]\n", line_no); }
                    | direct_declarator LEFT_SQUARE_BRACKET STATIC type_qualifier_list_opt assignment_expression RIGHT_SQUARE_BRACKET { printf("LINE [%d] : direct_declarator => direct_declarator [ static type_qualifier_list_opt assignment_expression ]\n", line_no); }
                    | direct_declarator LEFT_SQUARE_BRACKET type_qualifier_list STATIC assignment_expression RIGHT_SQUARE_BRACKET { printf("LINE [%d] : direct_declarator => direct_declarator [ type_qualifier_list static assignment_expression ]\n", line_no); }
                    | direct_declarator LEFT_SQUARE_BRACKET type_qualifier_list_opt ASTERISK RIGHT_SQUARE_BRACKET { printf("LINE [%d] : direct_declarator => direct_declarator [ type_qualifier_list_opt * ]\n", line_no); }
                    | direct_declarator LEFT_PARENTHESES parameter_type_list RIGHT_PARENTHESES { printf("LINE [%d] : direct_declarator => direct_declarator ( parameter_type_list )\n", line_no); }
                    | direct_declarator LEFT_PARENTHESES identifier_list_opt RIGHT_PARENTHESES { printf("LINE [%d] : direct_declarator => direct_declarator ( identifier_list_opt )\n", line_no); }
                    ;

type_qualifier_list_opt:
                        type_qualifier_list { printf("LINE [%d] : type_qualifier_list_opt => type_qualifier_list\n", line_no); }
                        | { printf("LINE [%d] : type_qualifier_list_opt => epsilon\n", line_no); }
                        ;

assignment_expression_opt:
                            assignment_expression { printf("LINE [%d] : assignment_expression_opt => assignment_expression\n", line_no); }
                            | { printf("LINE [%d] : assignment_expression_opt => epsilon\n", line_no); }
                            ;

identifier_list_opt:
                    identifier_list { printf("LINE [%d] : identifier_list_opt => identifier_list\n", line_no); }
                    | { printf("LINE [%d] : identifier_list_opt => epsilon\n", line_no); }
                    ;

pointer:
        ASTERISK type_qualifier_list_opt { printf("LINE [%d] : pointer => * type_qualifier_list_opt\n", line_no); }
        | ASTERISK type_qualifier_list_opt pointer { printf("LINE [%d] : pointer => * type_qualifier_list_opt pointer\n", line_no); }
        ;

type_qualifier_list:
                    type_qualifier { printf("LINE [%d] : type_qualifier_list => type_qualifier\n", line_no); }
                    | type_qualifier_list type_qualifier { printf("LINE [%d] : type_qualifier_list => type_qualifier_list type_qualifier\n", line_no); }
                    ;

parameter_type_list:
                    parameter_list { printf("LINE [%d] : parameter_type_list => parameter_list\n", line_no); }
                    | parameter_list COMMA ELLIPSIS { printf("LINE [%d] : parameter_type_list => parameter_list , ...\n", line_no); }
                    ;

parameter_list:
                parameter_declaration { printf("LINE [%d] : parameter_list => parameter_declaration\n", line_no); }
                | parameter_list COMMA parameter_declaration { printf("LINE [%d] : parameter_list => parameter_list , parameter_declaration\n", line_no); }
                ;

parameter_declaration:
                        declaration_specifiers declarator { printf("LINE [%d] : parameter_declaration => declaration_specifiers declarator\n", line_no); }
                        | declaration_specifiers { printf("LINE [%d] : parameter_declaration => declaration_specifiers\n", line_no); }
                        ;

identifier_list:
                IDENTIFIER  { printf("LINE [%d] : identifier_list => IDENTIFIER\n", line_no); printf("\t\t\t\tIDENTIFIER = %s\n", $1); }
                | identifier_list COMMA IDENTIFIER { printf("LINE [%d] : identifier_list => identifier_list , IDENTIFIER\n", line_no); printf("\t\t\t\tIDENTIFIER = %s\n", $3); }
                ;

type_name:
            specifier_qualifier_list { printf("LINE [%d] : type_name => specifier_qualifier_list\n", line_no); }
            ;

initialiser:
            assignment_expression { printf("LINE [%d] : initialiser => assignment_expression\n", line_no); }
            | LEFT_CURLY_BRACKET initialiser_list RIGHT_CURLY_BRACKET { printf("LINE [%d] : initialiser => { initialiser_list }\n", line_no); }  
            | LEFT_CURLY_BRACKET initialiser_list COMMA RIGHT_CURLY_BRACKET { printf("LINE [%d] : initialiser => { initialiser_list , }\n", line_no); }
            ;

initialiser_list:
                    designation_opt initialiser { printf("LINE [%d] : initialiser_list => designation_opt initialiser\n", line_no); }
                    | initialiser_list COMMA designation_opt initialiser { printf("LINE [%d] : initialiser_list => initialiser_list , designation_opt initialiser\n", line_no); }
                    ;

designation_opt:
                designation { printf("LINE [%d] : designation_opt => designation\n", line_no); }
                | { printf("LINE [%d] : designation_opt => epsilon\n", line_no); }
                ;

designation:
            designator_list ASSIGNMENT { printf("LINE [%d] : designation => designator_list =\n", line_no); }
            ;

designator_list:
                designator { printf("LINE [%d] : designator_list => designator\n", line_no); }
                | designator_list designator { printf("LINE [%d] : designator_list => designator_list designator\n", line_no); }
                ;

designator:
            LEFT_SQUARE_BRACKET constant_expression RIGHT_SQUARE_BRACKET { printf("LINE [%d] : designator => [ constant_expression ]\n", line_no); }
            | DOT IDENTIFIER { printf("LINE [%d] : designator => . IDENTIFIER\n", line_no); printf("\t\t\t\tIDENTIFIER = %s\n", $2); }
            ;

/* Statements */

statement:
            labeled_statement { printf("LINE [%d] : statement => labeled_statement\n", line_no); }
            | compound_statement { printf("LINE [%d] : statement => compound_statement\n", line_no); }
            | expression_statement { printf("LINE [%d] : statement => expression_statement\n", line_no); }
            | selection_statement { printf("LINE [%d] : statement => selection_statement\n", line_no); }
            | iteration_statement { printf("LINE [%d] : statement => iteration_statement\n", line_no); }
            | jump_statement { printf("LINE [%d] : statement => jump_statement\n", line_no); }
            ;

labeled_statement:
                    IDENTIFIER COLON statement { printf("LINE [%d] : labeled_statement => IDENTIFIER : statement\n", line_no); printf("\t\t\t\tIDENTIFIER = %s\n", $1); }
                    | CASE constant_expression COLON statement { printf("LINE [%d] : labeled_statement => case constant_expression : statement\n", line_no); }
                    | DEFAULT COLON statement { printf("LINE [%d] : labeled_statement => default : statement\n", line_no); }
                    ;

compound_statement:
                    LEFT_CURLY_BRACKET block_item_list_opt RIGHT_CURLY_BRACKET { printf("LINE [%d] : compound_statement => { block_item_list_opt }\n", line_no); }
                    ;

block_item_list_opt:
                    block_item_list { printf("LINE [%d] : block_item_list_opt => block_item_list\n", line_no); }
                    | { printf("LINE [%d] : block_item_list_opt => epsilon\n", line_no); }
                    ;

block_item_list:
                block_item { printf("LINE [%d] : block_item_list => block_item\n", line_no); }
                | block_item_list block_item { printf("LINE [%d] : block_item_list => block_item_list block_item\n", line_no); }
                ;

block_item:
            declaration { printf("LINE [%d] : block_item => declaration\n", line_no); }
            | statement { printf("LINE [%d] : block_item => statement\n", line_no); }
            ;

expression_statement:
                        expression_opt SEMI_COLON { printf("LINE [%d] : expression_statement => expression_opt ;\n", line_no); }
                        ;

expression_opt:
                expression { printf("LINE [%d] : expression_opt => expression\n", line_no); }
                | { printf("LINE [%d] : expression_opt => epsilon\n", line_no); }
                ;

selection_statement:
                    IF LEFT_PARENTHESES expression RIGHT_PARENTHESES statement { printf("LINE [%d] : selection_statement => if ( expression ) statement\n", line_no); }
                    | IF LEFT_PARENTHESES expression RIGHT_PARENTHESES statement ELSE statement { printf("LINE [%d] : selection_statement => if ( expression ) statement else statement\n", line_no); }
                    | SWITCH LEFT_PARENTHESES expression RIGHT_PARENTHESES statement { printf("LINE [%d] : selection_statement => switch ( expression ) statement\n", line_no); }
                    ;

iteration_statement:
                    WHILE LEFT_PARENTHESES expression RIGHT_PARENTHESES statement { printf("LINE [%d] : iteration_statement => while ( expression ) statement\n", line_no); }
                    | DO statement WHILE LEFT_PARENTHESES expression RIGHT_PARENTHESES SEMI_COLON { printf("LINE [%d] : iteration_statement => do statement while ( expression ) ;\n", line_no); }
                    | FOR LEFT_PARENTHESES expression_opt SEMI_COLON expression_opt SEMI_COLON expression_opt RIGHT_PARENTHESES statement { printf("LINE [%d] : iteration_statement => for ( expression_opt ; expression_opt ; expression_opt ) statement\n", line_no); }
                    | FOR LEFT_PARENTHESES declaration expression_opt SEMI_COLON expression_opt RIGHT_PARENTHESES statement { printf("LINE [%d] : iteration_statement => for ( declaration expression_opt ; expression_opt ) statement\n", line_no); }
                    ;

jump_statement:
                GOTO IDENTIFIER SEMI_COLON { printf("LINE [%d] : jump_statement => goto IDENTIFIER ;\n", line_no); printf("\t\t\t\tIDENTIFIER = %s\n", $2); }    
                | CONTINUE SEMI_COLON { printf("LINE [%d] : jump_statement => continue ;\n", line_no); }
                | BREAK SEMI_COLON { printf("LINE [%d] : jump_statement => break ;\n", line_no); }
                | RETURN expression_opt SEMI_COLON { printf("LINE [%d] : jump_statement => return expression_opt ;\n", line_no); }
                ;

/* External definitions */

translation_unit:
                    external_declaration { printf("LINE [%d] : translation_unit => external_declaration\n", line_no); }
                    | translation_unit external_declaration { printf("LINE [%d] : translation_unit => translation_unit external_declaration\n", line_no); }
                    ;

external_declaration:
                        function_definition { printf("LINE [%d] : external_declaration => function_definition\n", line_no); }
                        | declaration { printf("LINE [%d] : external_declaration => declaration\n", line_no); }
                        ;

function_definition:
                    declaration_specifiers declarator declaration_list_opt compound_statement { printf("LINE [%d] : function_definition => declaration_specifiers declarator declaration_list_opt compound_statement\n", line_no); }
                    ;

declaration_list_opt:
                        declaration_list { printf("LINE [%d] : declaration_list_opt => declaration_list\n", line_no); }
                        | { printf("LINE [%d] : declaration_list_opt => epsilon\n", line_no); }
                        ;

declaration_list:
                    declaration { printf("LINE [%d] : declaration_list => declaration\n", line_no); }
                    | declaration_list declaration { printf("LINE [%d] : declaration_list => declaration_list declaration\n", line_no); }
                    ;

%%

void yyerror(char* s) {
    printf("ERROR [Line %d] : %s\n", line_no, s);
}