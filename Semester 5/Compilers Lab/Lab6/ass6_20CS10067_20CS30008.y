/* Compilers Assignment - 6 */
/* Atishay Jain (20CS30008) */
/* Suvvari Venkata Sai Suvvari (20CS10067) */
%{
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
%}


%union {
	int intval;
	char* charval;
	int instr;
	sym* symp;
	symtype* symtp;
	expr* E;
	statement* S;
	Array* A;
	char unaryOperator;
} 

%token AUTO
%token ENUM
%token RESTRICT
%token UNSIGNED
%token BREAK
%token EXTERN
%token RETURN
%token VOID
%token CASE
%token FLOAT
%token SHORT
%token VOLATILE
%token CHAR
%token FOR
%token SIGNED
%token WHILE
%token CONST
%token GOTO
%token SIZEOF
%token BOOL
%token CONTINUE
%token IF
%token STATIC
%token COMPLEX
%token DEFAULT
%token INLINE
%token STRUCT
%token IMAGINARY
%token DO
%token INT
%token SWITCH
%token DOUBLE
%token LONG
%token TYPEDEF
%token ELSE
%token REGISTER
%token UNION
%token<symp> IDENTIFIER
%token<intval> INTEGER_CONSTANT
%token<charval> FLOATING_CONSTANT
%token<charval> CHARACTER_CONSTANT ENUMERATION_CONSTANT
%token<charval> STRING_LITERAL
%token SQBRAOPEN
%token SQBRACLOSE
%token ROBRAOPEN
%token ROBRACLOSE
%token CURBRAOPEN
%token CURBRACLOSE
%token DOT
%token ACC
%token INC
%token DEC
%token AMP
%token MUL
%token ADD
%token SUB
%token NEG
%token EXCLAIM
%token DIV
%token MODULO
%token SHL
%token SHR
%token BITSHL
%token BITSHR
%token LTE
%token GTE
%token EQ
%token NEQ
%token BITXOR
%token BITOR
%token AND
%token OR
%token QUESTION
%token COLON
%token SEMICOLON
%token DOTS
%token ASSIGN
%token STAREQ
%token DIVEQ
%token MODEQ
%token PLUSEQ
%token MINUSEQ
%token SHLEQ
%token SHREQ
%token BINANDEQ
%token BINXOREQ
%token BINOREQ
%token COMMA
%token HASH

%start translation_unit
// To remove the dangling else problem
%right THEN ELSE

// Expressions
%type <E>
	expression
	primary_expression 
	multiplicative_expression
	additive_expression
	shift_expression
	relational_expression
	equality_expression
	AND_expression
	exclusive_OR_expression
	inclusive_OR_expression
	logical_AND_expression
	logical_OR_expression
	conditional_expression
	assignment_expression
	expression_statement

%type <intval> argument_expression_list

// Array to be used later
%type <A> postfix_expression
	unary_expression
	cast_expression

%type <unaryOperator> unary_operator
%type <symp> constant initializer
%type <symp> direct_declarator init_declarator declarator
%type <symtp> pointer

// Auxillary non terminals M and N
%type <instr> M
%type <S> N


// Statements
%type <S>  statement
	labeled_statement 
	compound_statement
	selection_statement
	iteration_statement
	jump_statement
	block_item
	block_item_list

%%

primary_expression: 
	IDENTIFIER 								// Identifier
	{
		$$ = new expr();					// Create a new expression and store pointer to ST entry in the location
		$$->loc = $1;
		$$->type = "NONBOOL";
	}
	| constant 								
	{
		// Create a new expression and store the value of the constant in a temporary
		$$ = new expr();
		$$->loc = $1;
	}
	| STRING_LITERAL 
	{
		// Create a new expression and store the value of the constant in a temporary
		$$ = new expr();
		symtype* tmp = new symtype("PTR");
		$$->loc = gentemp(tmp, $1);
		$$->loc->type->ptr = new symtype("CHAR");

		allstrings.push_back($1);
		stringstream strs;
		strs << allstrings.size()-1;
		string temp_str = strs.str();
		char* intStr = (char*) temp_str.c_str();
		string str = string(intStr);
		emit("EQUALSTR", $$->loc->name, str);
	}
	| ROBRAOPEN expression ROBRACLOSE 
	{
		// Simply equal to expression
		$$ = $2;
	}
	;

constant:
	INTEGER_CONSTANT 
	{
		stringstream strs;
		strs << $1;
		string temp_str = strs.str();
		char* intStr = (char*) temp_str.c_str();
		string str = string(intStr);
		$$ = gentemp(new symtype("INTEGER"), str);
		emit("EQUAL", $$->name, $1);
	}
	|FLOATING_CONSTANT 
	{
		$$ = gentemp(new symtype("DOUBLE"), string($1));
		emit("EQUAL", $$->name, string($1));
	}
	|ENUMERATION_CONSTANT  {}
	|CHARACTER_CONSTANT 
	{
		$$ = gentemp(new symtype("CHAR"),$1);
		emit("EQUALCHAR", $$->name, string($1));
	}
	;


postfix_expression:
	primary_expression 
	{
		// Create new Array and store the location of primary expression in it
		$$ = new Array ();
		$$->Array = $1->loc;
		$$->loc = $$->Array;
		$$->type = $1->loc->type;
	}
	|postfix_expression SQBRAOPEN expression SQBRACLOSE 
	{
		$$ = new Array();
		
		$$->Array = $1->loc;							// Copy the base
		$$->type = $1->type->ptr;						// Type = type of element
		$$->loc = gentemp(new symtype("INTEGER"));		// Store computed address
		
		// New address = (if only) already computed + $3 * new width
		if ($1->cat=="ARR") 
		{						
			// If already arr, multiply the size of the sub-type of Array with the expression value and add
			sym* t = gentemp(new symtype("INTEGER"));
			stringstream strs;
		    strs <<size_type($$->type);
		    string temp_str = strs.str();
		    char* intStr = (char*) temp_str.c_str();
			string str = string(intStr);				
 			emit("MULT", t->name, $3->loc->name, str);
			emit("ADD", $$->loc->name, $1->loc->name, t->name);
		}
 		else 
		{
			// If a 1D Array, simply calculate size
 			stringstream strs;
		    strs <<size_type($$->type);
		    string temp_str = strs.str();
		    char* intStr1 = (char*) temp_str.c_str();
			string str1 = string(intStr1);		
	 		emit("MULT", $$->loc->name, $3->loc->name, str1);
 		}

 		// Mark that it contains Array address and first time computation is done
		$$->cat = "ARR";
	}
	|postfix_expression ROBRAOPEN ROBRACLOSE {}
	|postfix_expression ROBRAOPEN argument_expression_list ROBRACLOSE 
	{
		// Call the function with number of parameters from argument_expression_list_opt
		$$ = new Array();
		$$->Array = gentemp($1->type);
		stringstream strs;
	    strs <<$3;
	    string temp_str = strs.str();
	    char* intStr = (char*) temp_str.c_str();
		string str = string(intStr);		
		emit("CALL", $$->Array->name, $1->Array->name, str);
	}
	|postfix_expression DOT IDENTIFIER {}
	|postfix_expression ACC IDENTIFIER {}
	|postfix_expression INC 
	{
		// Generate new temporary, equate it to old one and then add 1
		$$ = new Array();

		// Copy $1 to $$
		$$->Array = gentemp($1->Array->type);
		emit("EQUAL", $$->Array->name, $1->Array->name);

		// Increment $1
		emit("ADD", $1->Array->name, $1->Array->name, "1");
	}
	|postfix_expression DEC 
	{
		// Generate new temporary, equate it to old one and then subtract 1
		$$ = new Array();

		// Copy $1 to $$
		$$->Array = gentemp($1->Array->type);
		emit("EQUAL", $$->Array->name, $1->Array->name);

		// Decrement $1
		emit("SUB", $1->Array->name, $1->Array->name, "1");
	}
	|ROBRAOPEN type_name ROBRACLOSE CURBRAOPEN initializer_list CURBRACLOSE 
	{
		// Later to be added more
		$$ = new Array();
		$$->Array = gentemp(new symtype("INTEGER"));
		$$->loc = gentemp(new symtype("INTEGER"));
	}
	|ROBRAOPEN type_name ROBRACLOSE CURBRAOPEN initializer_list COMMA CURBRACLOSE 
	{
		// Later to be added more
		$$ = new Array();
		$$->Array = gentemp(new symtype("INTEGER"));
		$$->loc = gentemp(new symtype("INTEGER"));
	}
	;

argument_expression_list:
	assignment_expression 
	{
		// One argument and emitparam
		emit("PARAM", $1->loc->name);
		$$ = 1;
	}
	|argument_expression_list COMMA assignment_expression 
	{
		// One more argument and emitparam
		emit("PARAM", $3->loc->name);
		$$ = $1+1;
	}
	;

unary_expression:
	postfix_expression 
	{
		// Simply equate
		$$ = $1;
	}
	|INC unary_expression 
	{
		// Increment $2
		emit("ADD", $2->Array->name, $2->Array->name, "1");

		// Use the same value as $2
		$$ = $2;
	}
	|DEC unary_expression 
	{
		// Decrement $2
		emit("SUB", $2->Array->name, $2->Array->name, "1");

		// Use the same value as $2
		$$ = $2;
	}
	|unary_operator cast_expression 
	{
		// If it is of this type, where unary operator is involved{
		$$ = new Array();
		switch ($1) {
			case '&':
				// Address of something, then generate a pointer temporary and emitthe quad
				$$->Array = gentemp((new symtype("PTR")));
				$$->Array->type->ptr = $2->Array->type; 
				emit("ADDRESS", $$->Array->name, $2->Array->name);
				break;
			case '*':
				// Value of something, then generate a temporary of the corresponding type and emitthe quad
				$$->cat = "PTR";
				$$->loc = gentemp($2->Array->type->ptr);
				emit("PTRR", $$->loc->name, $2->Array->name);
				$$->Array = $2->Array;
				break;
			case '+':
				// Unary plus
				$$ = $2;
				break;
			case '-':
				// Unary minus 
				$$->Array = gentemp(new symtype($2->Array->type->type));
				emit("UMINUS", $$->Array->name, $2->Array->name);
				break;
			case '~':
				// Bitwise not, generate new temporary of the same base type and make it negative of current one
				$$->Array = gentemp(new symtype($2->Array->type->type));
				emit("BNOT", $$->Array->name, $2->Array->name);
				break;
			case '!':
				// Logical not, generate new temporary of the same base type and make it negative of current one
				$$->Array = gentemp(new symtype($2->Array->type->type));
				emit("LNOT", $$->Array->name, $2->Array->name);
				break;
			default:
				break;
		}
	}
	|SIZEOF unary_expression {}
	|SIZEOF ROBRAOPEN type_name ROBRACLOSE {}
	;

unary_operator:
	AMP 
	{
		// Simply equate to the corresponding operator
		$$ = '&';
	}
	|MUL 
	{
		$$ = '*';
	}
	|ADD 
	{
		$$ = '+';
	}
	|SUB 
	{
		$$ = '-';
	}
	|NEG 
	{
		$$ = '~';
	}
	|EXCLAIM 
	{
		$$ = '!';
	}
	;

cast_expression:
	unary_expression 
	{
		// Unary expression, simply equate
		$$=$1;
	}
	|ROBRAOPEN type_name ROBRACLOSE cast_expression 
	{
		// Simply equate
		$$=$4;
	}
	;

multiplicative_expression:
	cast_expression 
	{
		$$ = new expr();		// Generate new expression
		if ($1->cat=="ARR") 
		{ 
			// Array
			$$->loc = gentemp($1->loc->type);
			emit("ARR", $$->loc->name, $1->Array->name, $1->loc->name);		
			// Emitwith Array right
		}
		else if ($1->cat=="PTR") 
		{ 
			// If it is of type ptr
			$$->loc = $1->loc;
		}
		else 
		{ 
			// Otherwise
			$$->loc = $1->Array;
		}
	}
	|multiplicative_expression MUL cast_expression 
	{
		// If we have multiplication
		if (typecheck ($1->loc, $3->Array) ) 
		{
			// If types are compatible, generate new temporary and equate to the product
			$$ = new expr();
			$$->loc = gentemp(new symtype($1->loc->type->type));
			emit("MULT", $$->loc->name, $1->loc->name, $3->Array->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
	|multiplicative_expression DIV cast_expression 
	{
		// If we have division
		if (typecheck ($1->loc, $3->Array) ) 
		{
			// If types are compatible, generate new temporary and equate to the quotient
			$$ = new expr();
			$$->loc = gentemp(new symtype($1->loc->type->type));
			emit("DIVIDE", $$->loc->name, $1->loc->name, $3->Array->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
	|multiplicative_expression MODULO cast_expression 
	{
		// If we have mod
		if (typecheck ($1->loc, $3->Array) ) 
		{
			// If types are compatible, generate new temporary and equate to the quotient
			$$ = new expr();
			$$->loc = gentemp(new symtype($1->loc->type->type));
			emit("MODOP", $$->loc->name, $1->loc->name, $3->Array->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
	;

additive_expression:
	multiplicative_expression 
	{
		// Simply equate
		$$=$1;
	}
	|additive_expression ADD multiplicative_expression 
	{	
		// For addition
		if (typecheck ($1->loc, $3->loc) ) 
		{
			// If types are compatible, generate new temporary and equate to the sum
			$$ = new expr();
			$$->loc = gentemp(new symtype($1->loc->type->type));
			emit("ADD", $$->loc->name, $1->loc->name, $3->loc->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
	|additive_expression SUB multiplicative_expression 
	{
		// For subtraction
		if (typecheck($1->loc, $3->loc)) 
		{
			// If types are compatible, generate new temporary and equate to the difference
			$$ = new expr();
			$$->loc = gentemp(new symtype($1->loc->type->type));
			emit("SUB", $$->loc->name, $1->loc->name, $3->loc->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
	;

shift_expression:
	additive_expression 
	{
		// Simply equate
		$$=$1;
	}
	|shift_expression SHL additive_expression 
	{
		// If base type is int, generate new temporary and equate to the shifted value
		if ($3->loc->type->type == "INTEGER") 
		{
			$$ = new expr();
			$$->loc = gentemp(new symtype("INTEGER"));
			emit("LEFTOP", $$->loc->name, $1->loc->name, $3->loc->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
	|shift_expression SHR additive_expression
	{
		// If base type is int, generate new temporary and equate to the shifted value
		if ($3->loc->type->type == "INTEGER") 
		{
			$$ = new expr();
			$$->loc = gentemp(new symtype("INTEGER"));
			emit("RIGHTOP", $$->loc->name, $1->loc->name, $3->loc->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
	;

relational_expression:
	shift_expression 
	{
		// Simply equate
		$$=$1;
	}	
	|relational_expression BITSHL shift_expression 
	{
		// Check compatible types
		if (typecheck($1->loc, $3->loc)) 
		{
			$$ = new expr();
			$$->type = "BOOL";

			$$->truelist = makelist (nextinstr());					// Make truelist
			$$->falselist = makelist (nextinstr()+1);				// Make falselist
			emit("LT", "", $1->loc->name, $3->loc->name);			// Emitstatement if a < b goto ...
			emit("GOTOOP", "");										// Emitgoto ...
		}
		// Error
		else cout << "Type Error" << endl;
	}
	|relational_expression BITSHR shift_expression 
	{
		// Check compatible types
		if (typecheck($1->loc, $3->loc)) 
		{
			$$ = new expr();
			$$->type = "BOOL";
			$$->truelist = makelist(nextinstr());					// Make truelist
			$$->falselist = makelist(nextinstr()+1);				// Make falselist
			emit("GT", "", $1->loc->name, $3->loc->name);			// Emitstatement if a > b goto ...
			emit("GOTOOP", "");										// Emitgoto ...
		}
		// Error
		else cout << "Type Error" << endl;
	}
	|relational_expression LTE shift_expression 
	{
		// Check compatible types, make truelist and falselist, emitthe required statement
		if (typecheck($1->loc, $3->loc)) 
		{
			$$ = new expr();
			$$->type = "BOOL";
			$$->truelist = makelist(nextinstr());					// Make truelist
			$$->falselist = makelist(nextinstr()+1);				// Make falselist
			emit("LE", "", $1->loc->name, $3->loc->name);			// Emitstatement if a > b goto ...
			emit("GOTOOP", "");										// Emitgoto ...
		}
		// Error
		else cout << "Type Error" << endl;
	}
	|relational_expression GTE shift_expression 
	{
		// Check compatible types, make truelist and falselist, emitthe required statement
		if (typecheck($1->loc, $3->loc)) 
		{
			$$ = new expr();
			$$->type = "BOOL";
			$$->truelist = makelist(nextinstr());					// Make truelist
			$$->falselist = makelist(nextinstr()+1);				// Make falselist
			emit("GE", "", $1->loc->name, $3->loc->name);			// Emitstatement if a > b goto ...
			emit("GOTOOP", "");										// Emitgoto ...
		}
		// Error
		else cout << "Type Error" << endl;
	}
	;

equality_expression:
	relational_expression 
	{
		// Simply equate
		$$=$1;
	}
	|equality_expression EQ relational_expression 
	{
		// Check compatibility, make list and emit
		if (typecheck($1->loc, $3->loc))         
		{
			// Convert bool to int
			convertBool2Int($1);			
			convertBool2Int($3);

			$$ = new expr();
			$$->type = "BOOL";
			$$->truelist = makelist(nextinstr());					// Make truelist
			$$->falselist = makelist(nextinstr()+1);				// Make falselist
			emit("EQOP", "", $1->loc->name, $3->loc->name);			// Emitstatement if a > b goto ...
			emit("GOTOOP", "");									// Emitgoto ...
		}
		// Error
		else cout << "Type Error" << endl;
	}
	|equality_expression NEQ relational_expression 
	{
		// Check compatibility, convert bool to int, make list and emit
		if (typecheck($1->loc, $3->loc)) 
		{
			convertBool2Int($1);
			convertBool2Int($3);

			$$ = new expr();
			$$->type = "BOOL";
			$$->truelist = makelist(nextinstr());					// Make truelist
			$$->falselist = makelist(nextinstr()+1);				// Make falselist
			emit("NEOP", "", $1->loc->name, $3->loc->name);			// Emitstatement if a > b goto ...
			emit("GOTOOP", "");										// Emitgoto ...
		}
		// Error
		else cout << "Type Error" << endl;
	}
	;

AND_expression:
	equality_expression 
	{
		// Simply equate
		$$=$1;
	}
	|AND_expression AMP equality_expression 
	{
		// Check compatible types, make non-boolean expression and convert bool to int and emit
		if (typecheck($1->loc, $3->loc)) 
		{
			// Convert bool to int
			convertBool2Int($1);
			convertBool2Int($3);
			
			$$ = new expr();
			$$->type = "NONBOOL";
			$$->loc = gentemp(new symtype("INTEGER"));
			emit("BAND", $$->loc->name, $1->loc->name, $3->loc->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
	;

exclusive_OR_expression:
	AND_expression 
	{
		// Simply equate
		$$=$1;
	}
	|exclusive_OR_expression BITXOR AND_expression 
	{
		// Same as AND_expression: check compatible types, make non-boolean expression and convert bool to int and emit
		if (typecheck($1->loc, $3->loc)) 
		{
			convertBool2Int($1);
			convertBool2Int($3);
			
			$$ = new expr();
			$$->type = "NONBOOL";

			$$->loc = gentemp(new symtype("INTEGER"));
			emit("XOR", $$->loc->name, $1->loc->name, $3->loc->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
	;

inclusive_OR_expression:
	exclusive_OR_expression 
	{
		// Simply equate
		$$=$1;
	}
	|inclusive_OR_expression BITOR exclusive_OR_expression 
	{
		// Same as and_expression: check compatible types, make non-boolean expression and convert bool to int and emit
		if (typecheck($1->loc, $3->loc)) 
		{
			// If any is bool get its value
			convertBool2Int($1);
			convertBool2Int($3);
			
			$$ = new expr();
			$$->type = "NONBOOL";

			$$->loc = gentemp(new symtype("INTEGER"));
			emit("INOR", $$->loc->name, $1->loc->name, $3->loc->name);
		}
		// Error
		else cout << "Type Error" << endl;
	}
	;

logical_AND_expression:
	inclusive_OR_expression 
	{
		// Simply equate
		$$=$1;
	}
	|logical_AND_expression N AND M inclusive_OR_expression 
	{
		// Involves back-patching
		// Convert int to bool
		convertInt2Bool($5);

		// Convert $1 to bool and backpatch using N
		backpatch($2->nextlist, nextinstr());
		convertInt2Bool($1);

		$$ = new expr();
		$$->type = "BOOL";

		// Standard back-patching principles
		backpatch($1->truelist, $4);
		$$->truelist = $5->truelist;
		$$->falselist = merge($1->falselist, $5->falselist);
	}
	;

logical_OR_expression:
	logical_AND_expression 
	{
		// Simply equate 
		$$=$1;
	}
	|logical_OR_expression N OR M logical_AND_expression 
	{
		// Convert (if) int to bool
		convertInt2Bool($5);

		// Convert $1 to bool and backpatch using N
		backpatch($2->nextlist, nextinstr());
		convertInt2Bool($1);

		$$ = new expr();
		$$->type = "BOOL";

		// Standard back-patching principles involved
		backpatch($1->falselist, $4);
		$$->truelist = merge($1->truelist, $5->truelist);
		$$->falselist = $5->falselist;
	}
	;

M: 
	%empty
	{	
		// To store the address of the next instruction
		$$ = nextinstr();
	};

N: 
	%empty 
	{ 	
		// Guard against fallthrough by emitting a goto
		$$  = new statement();
		$$->nextlist = makelist(nextinstr());
		emit("GOTOOP","");
	};

conditional_expression:
	logical_OR_expression 
	{
		// Simply equate
		$$=$1;
	}
	|logical_OR_expression N QUESTION M expression N COLON M conditional_expression 
	{
		// Generate temporary for expression
		$$->loc = gentemp($5->loc->type);
		$$->loc->update($5->loc->type);
		
		// Make it equal to the conditional expression
		emit("EQUAL", $$->loc->name, $9->loc->name);
		list<int> l = makelist(nextinstr());
		emit("GOTOOP", "");				// Prevent fallthrough

		// Necessary back-patching 
		backpatch($6->nextlist, nextinstr());
		emit("EQUAL", $$->loc->name, $5->loc->name);
		list<int> m = makelist(nextinstr());
		l = merge(l, m);					// Mergethe next instruction list
		emit("GOTOOP", "");				// Prevent fallthrough

		// Necessary back-patching w.r.t logical_OR_expression
		backpatch($2->nextlist, nextinstr());
		convertInt2Bool($1);
		backpatch($1->truelist, $4);
		backpatch($1->falselist, $8);
		backpatch(l, nextinstr());
	}
	;

assignment_expression:
	conditional_expression 
	{
		// Simply equate
		$$=$1;
	}
	|unary_expression assignment_operator assignment_expression 
	{
		// If type is arr, simply check if we need to convert and emit
		if($1->cat=="ARR") 
		{
			$3->loc = conv($3->loc, $1->type->type);
			emit("ARRL", $1->Array->name, $1->loc->name, $3->loc->name);	
		}
		// If type is ptr, simply emit
		else if($1->cat=="PTR") 
		{
			emit("PTRL", $1->Array->name, $3->loc->name);	
		}
		// Otherwise assignment
		else
		{
			$3->loc = conv($3->loc, $1->Array->type->type);
			emit("EQUAL", $1->Array->name, $3->loc->name);
		}
		$$ = $3;
	}
	;

assignment_operator:
	ASSIGN {}
	|STAREQ {}
	|DIVEQ {}
	|MODEQ {}
	|PLUSEQ {}
	|MINUSEQ {}
	|SHLEQ {}
	|SHREQ {}
	|BINANDEQ {}
	|BINXOREQ {}
	|BINOREQ {}
	;

expression:
	assignment_expression 
	{
		// Simply equate
		$$=$1;
	}
	|expression COMMA assignment_expression {}
	;

constant_expression:
	conditional_expression {}
	;

declaration:
	declaration_specifiers init_declarator_list SEMICOLON {	}
	|declaration_specifiers SEMICOLON {	}
	;


declaration_specifiers:
	storage_class_specifier declaration_specifiers {}
	|storage_class_specifier {}
	|type_specifier declaration_specifiers {}
	|type_specifier {}
	|type_qualifier declaration_specifiers {}
	|type_qualifier {}
	|function_specifier declaration_specifiers {}
	|function_specifier {}
	;

init_declarator_list:
	init_declarator {}
	|init_declarator_list COMMA init_declarator {}
	;

init_declarator:
	declarator {$$=$1;}
	|declarator ASSIGN initializer 
	{
		// Get the initial value and emitit
		if ($3->initial_value!="") $1->initial_value=$3->initial_value;
		emit("EQUAL", $1->name, $3->name);
	}
	;

storage_class_specifier:
	EXTERN {}
	| STATIC {}
	| AUTO {}
	| REGISTER {}
	;

type_specifier: 
	VOID {Type="VOID";}
	| CHAR {Type="CHAR";}
	| SHORT {}
	| INT {Type="INTEGER";}
	| LONG {}
	| FLOAT {}
	| DOUBLE {Type="DOUBLE";}
	| SIGNED {}
	| UNSIGNED {}
	| BOOL {}
	| COMPLEX {}
	| IMAGINARY {}
	| enum_specifier {}
	;

specifier_qualifier_list:
	type_specifier specifier_qualifier_list {}
	| type_specifier {}
	| type_qualifier specifier_qualifier_list {}
	| type_qualifier {}
	;

enum_specifier:
	ENUM IDENTIFIER CURBRAOPEN enumerator_list CURBRACLOSE {}
	|ENUM CURBRAOPEN enumerator_list CURBRACLOSE {}
	|ENUM IDENTIFIER CURBRAOPEN enumerator_list COMMA CURBRACLOSE {}
	|ENUM CURBRAOPEN enumerator_list COMMA CURBRACLOSE {}
	|ENUM IDENTIFIER {}
	;

enumerator_list:
	enumerator {}
	|enumerator_list COMMA enumerator {}
	;

enumerator:
	IDENTIFIER {}
	|IDENTIFIER ASSIGN constant_expression {}
	;

type_qualifier:
	CONST {}
	|RESTRICT {}
	|VOLATILE {}
	;

function_specifier:
	INLINE {}
	;

declarator:
	pointer direct_declarator 
	{
		// For multidimensional arrays
		// Move in depth till you get the base type
		symtype * t = $1;
		while (t->ptr !=NULL) t = t->ptr;
		t->ptr = $2->type;
		$$ = $2->update($1);
	}
	|direct_declarator {}
	;


direct_declarator:
	IDENTIFIER 
	{
		// If identifier, simply add a new variable of var_type
		$$ = $1->update(new symtype(Type));
		currentSymbol = $$;
	}
	| ROBRAOPEN declarator ROBRACLOSE 
	{
		// Simply equate
		$$=$2;
	}
	| direct_declarator SQBRAOPEN type_qualifier_list assignment_expression SQBRACLOSE {}
	| direct_declarator SQBRAOPEN type_qualifier_list SQBRACLOSE {}
	| direct_declarator SQBRAOPEN assignment_expression SQBRACLOSE 
	{
		symtype * t = $1 -> type;
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
			int temp = atoi($3->loc->initial_value.c_str());
			// Create new symbol table with that initial value
			symtype* s = new symtype("ARR", $1->type, temp);
			// Update the symbol table			
			$$ = $1->update(s);
		}
		else 
		{
			// Similar arguments as above	
			prev->ptr =  new symtype("ARR", t, atoi($3->loc->initial_value.c_str()));
			$$ = $1->update ($1->type);
		}
	}
	| direct_declarator SQBRAOPEN SQBRACLOSE 
	{
		symtype * t = $1 -> type;
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
			symtype* s = new symtype("ARR", $1->type, 0);
			$$ = $1->update(s);
		}
		else 
		{
			prev->ptr =  new symtype("ARR", t, 0);
			$$ = $1->update ($1->type);
		}
	}
	| direct_declarator SQBRAOPEN STATIC type_qualifier_list assignment_expression SQBRACLOSE {}
	| direct_declarator SQBRAOPEN STATIC assignment_expression SQBRACLOSE {}
	| direct_declarator SQBRAOPEN type_qualifier_list MUL SQBRACLOSE {}
	| direct_declarator SQBRAOPEN MUL SQBRACLOSE {}
	| direct_declarator ROBRAOPEN CT parameter_type_list ROBRACLOSE 
	{
		table->name = $1->name;

		if ($1->type->type !="VOID") 
		{
			// Lookup for return value
			sym *s = table->lookup("return");
			s->update($1->type);		
		}
		$1->nested=table;
		$1->category = "function";
		table->parent = globalTable;

		// Come back to globalsymbol table
		changeTable(globalTable);				
		currentSymbol = $$;
	}
	| direct_declarator ROBRAOPEN identifier_list ROBRACLOSE {}
	| direct_declarator ROBRAOPEN CT ROBRACLOSE 
	{
		table->name = $1->name;

		if ($1->type->type != "VOID") 
		{
			// Lookup for return value
			sym *s = table->lookup("return");
			s->update($1->type);		
		}
		$1->nested=table;
		$1->category = "function";
		
		table->parent = globalTable;

		// Come back to globalsymbol table
		changeTable(globalTable);				
		currentSymbol = $$;
	}
	;

CT: 
	%empty 
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
	;

pointer:
	MUL type_qualifier_list {}
	|MUL 
	{
		// Create new pointer
		$$ = new symtype("PTR");
	}
	|MUL type_qualifier_list pointer {}
	|MUL pointer 
	{
		// Create new pointer
		$$ = new symtype("PTR", $2);
	}
	;

type_qualifier_list:
	type_qualifier {}
	|type_qualifier_list type_qualifier {}
	;

parameter_type_list:
	parameter_list {}
	|parameter_list COMMA DOTS {}
	;

parameter_list:
	parameter_declaration {}
	|parameter_list COMMA parameter_declaration {}
	;

parameter_declaration:
	declaration_specifiers declarator 
	{
		$2->category = "param";
	}
	|declaration_specifiers {}
	;

identifier_list:
	IDENTIFIER {}
	|identifier_list COMMA IDENTIFIER {}
	;

type_name:
	specifier_qualifier_list {}
	;

initializer:
	assignment_expression 
	{
		// Assignment
		$$ = $1->loc;
	}
	|CURBRAOPEN initializer_list CURBRACLOSE {}
	|CURBRAOPEN initializer_list COMMA CURBRACLOSE {}
	;


initializer_list:
	designation initializer {}
	|initializer {}
	|initializer_list COMMA designation initializer {}
	|initializer_list COMMA initializer {}
	;

designation:
	designator_list ASSIGN {}
	;

designator_list:
	designator {}
	|designator_list designator {}
	;

designator:
	SQBRAOPEN constant_expression SQBRACLOSE {}
	|DOT IDENTIFIER {}
	;

statement:
	labeled_statement {}
	|compound_statement 
	{
		// Simply equate
		$$=$1;
	}
	|expression_statement 
	{
		// Create new statement with same nextlist
		$$ = new statement();
		$$->nextlist = $1->nextlist;
	}
	|selection_statement 
	{
		// Simply equate
		$$=$1;
	}
	|iteration_statement 
	{
		// Simply equate
		$$=$1;
	}
	|jump_statement 
	{
		// Simply equate
		$$=$1;
	}
	;

labeled_statement:
	IDENTIFIER COLON statement 
	{
		// Create new statement
		$$ = new statement();
	}
	|CASE constant_expression COLON statement 
	{
		// Create new statement
		$$ = new statement();
	}
	|DEFAULT COLON statement 
	{
		// Create new statement
		$$ = new statement();
	}
	;

compound_statement:
	CURBRAOPEN block_item_list CURBRACLOSE 
	{
		// Simply equate
		$$=$2;
	}
	|CURBRAOPEN CURBRACLOSE 
	{
		// Create new statement
		$$ = new statement();
	}
	;

block_item_list:
	block_item 
	{
		// Simply equate
		$$=$1;
	}
	|block_item_list M block_item 
	{
		// After $1, move to block_item via $2
		$$=$3;
		backpatch($1->nextlist, $2);
	}
	;

block_item:
	declaration 
	{
		// New statement
		$$ = new statement();
	}
	|statement 
	{
		// Simply equate
		$$ = $1;
	}
	;

expression_statement:
	expression SEMICOLON 
	{
		// Simply equate
		$$=$1;
	}
	|SEMICOLON 
	{
		// New expression
		$$ = new expr();
	}
	;

selection_statement:
	IF ROBRAOPEN expression N ROBRACLOSE M statement N %prec THEN
	{
		// If stmt without else
		backpatch($4->nextlist, nextinstr());						// Nextlist of N goes to nextinstr
		convertInt2Bool($3);							 			// Convert expression to bool	
		$$ = new statement();										// Make new statement
		backpatch($3->truelist, $6);								// Is expression is true, go to M i.e just before statement body
		list<int> temp = merge($3->falselist, $7->nextlist); 		// Mergefalselist of expression, nextlist of statement and second N
		$$->nextlist = merge($8->nextlist, temp);
	}
	|IF ROBRAOPEN expression N ROBRACLOSE M statement N ELSE M statement 
	{
		// If stmt with else
		backpatch($4->nextlist, nextinstr());						// Nextlist of N goes to nextinstr
		convertInt2Bool($3);										// Convert expression to bool
		$$ = new statement();										// Create new statement
		backpatch($3->truelist, $6);								// When expression is true, go to M1 else go to M2
		backpatch($3->falselist, $10);
		list<int> temp = merge($7->nextlist, $8->nextlist);			// Mergethe nextlists of the statements and second N
		$$->nextlist = merge($11->nextlist,temp);
	}
	|SWITCH ROBRAOPEN expression ROBRACLOSE statement {}
	;

iteration_statement:
	WHILE M ROBRAOPEN expression ROBRACLOSE M statement 
	{
		// Create new statement
		$$ = new statement();
		// Convert int expression to bool
		convertInt2Bool($4);

		// M1 to go back to boolean again
		// M2 to go to statement if the boolean is true
		backpatch($7->nextlist, $2);
		backpatch($4->truelist, $6);
		$$->nextlist = $4->falselist;

		stringstream strs;
	    strs << $2;
	    string temp_str = strs.str();
	    char* intStr = (char*) temp_str.c_str();
		string str = string(intStr);
		// Emitto prevent fallthrough
		emit("GOTOOP", str);
	}
	|DO M statement M WHILE ROBRAOPEN expression ROBRACLOSE SEMICOLON 
	{
		// Create new statement
		$$ = new statement();
		// Convert int expression to bool
		convertInt2Bool($7);
		// M1 to go back to statement if expression is true
		// M2 to go to check expression if statement is complete
		backpatch($7->truelist, $2);
		backpatch($3->nextlist, $4);

		// Some bug in the next statement
		$$->nextlist = $7->falselist;
	}
	|FOR ROBRAOPEN expression_statement M expression_statement ROBRACLOSE M statement
	{
		// Create new statement
		$$ = new statement();
		// Convert int expression to bool
		convertInt2Bool($5);

		// Standard back-patching principles
		backpatch($5->truelist, $7);
		backpatch($8->nextlist, $4);

		stringstream strs;
	    strs << $4;
	    string temp_str = strs.str();
	    char* intStr = (char*) temp_str.c_str();
		string str = string(intStr);

		// Prevent fallthrough
		emit("GOTOOP", str);
		$$->nextlist = $5->falselist;
	}
	|FOR ROBRAOPEN expression_statement M expression_statement M expression N ROBRACLOSE M statement
	{
		// Create new statement
		$$ = new statement();
		// Convert int expression_statement to bool
		convertInt2Bool($5);

		// Simple back-patching principles
		backpatch($5->truelist, $10);
		backpatch($8->nextlist, $4);
		backpatch($11->nextlist, $6);

		stringstream strs;
	    strs << $6;
	    string temp_str = strs.str();
	    char* intStr = (char*) temp_str.c_str();
		string str = string(intStr);

		// Prevent fallthrough
		emit("GOTOOP", str);
		$$->nextlist = $5->falselist;
	}
	;

jump_statement:
	GOTO IDENTIFIER SEMICOLON {$$ = new statement();}
	|CONTINUE SEMICOLON {$$ = new statement();}
	|BREAK SEMICOLON {$$ = new statement();}
	|RETURN expression SEMICOLON 
	{
		// Emitreturn with the name of the return value
		$$ = new statement();
		emit("RETURN",$2->loc->name);
	}
	|RETURN SEMICOLON
	{
		// Simply emitreturn
		$$ = new statement();
		emit("RETURN","");
	}
	;

translation_unit:
	external_declaration {}
	|translation_unit external_declaration {}
	;

external_declaration:
	function_definition {}
	|declaration {}
	;

function_definition:
	declaration_specifiers declarator declaration_list CT compound_statement {}
	|declaration_specifiers declarator CT compound_statement 
	{
		emit("FUNCEND", table->name);
		table->parent = globalTable;
		// Once we come back to this at the end, change the table to global Symbol table
		changeTable(globalTable);
	}
	;

declaration_list:
	declaration {}
	|declaration_list declaration {}
	;



%%

void yyerror(string s) {
    cout<<s<<endl;
}
