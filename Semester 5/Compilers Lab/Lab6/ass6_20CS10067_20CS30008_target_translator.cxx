/* Compilers Assignment - 6 */
/* Atishay Jain (20CS30008) */
/* Suvvari Venkata Sai Suvvari (20CS10067) */
#include "ass6_20CS10067_20CS30008_translator.h"
#include <iostream>
#include <cstring>
#include <string>

extern FILE *yyin;
extern vector<string> allstrings;

using namespace std;

int labelCount = 0;									// Label count in asm file
std::map<int, int> labelMap;						// Map from quad number to label number
ofstream out;										// Asm file stream
vector<quad> Array;									// Quad Array
string asmfilename = "ass6_20CS10067_20CS30008_";	// Asm file name
string inputfile = "ass6_20CS10067_20CS30008_test"; // Input file name

// Prepares the activation table for a given symtable
void computeActivationRecord(symtable *st)
{
	int param = -20;
	int local = -24;

	// Iterate over the symtable
	for (list<sym>::iterator it = st->table.begin(); it != st->table.end(); it++)
	{
		// If param
		if (it->category == "param")
		{
			st->ar[it->name] = param; // Assign it to be param in activation record
			param += it->size;		  // Add the size of the entry
		}
		else if (it->name == "return")
			continue;

		// If local
		else
		{
			st->ar[it->name] = local; // Assign it to be param in activation record
			local -= it->size;		  // Add the size of the entry
		}
	}
}

void genasm()
{
	Array = q.Array;

	// O update the goto labels
	// Iterate over Array
	for (vector<quad>::iterator it = Array.begin(); it != Array.end(); it++)
	{
		int i;
		if (it->op == "GOTOOP" || it->op == "LT" || it->op == "GT" || it->op == "LE" || it->op == "GE" || it->op == "EQOP" || it->op == "NEOP")
		{
			i = atoi(it->result.c_str()); // Convert the result in string to integer
			labelMap[i] = 1;
		}
	}
	int count = 0;
	// Map from quad number to label number
	for (std::map<int, int>::iterator it = labelMap.begin(); it != labelMap.end(); ++it)
		it->second = count++;
	list<symtable *> tablelist;
	// Flatten the global symbol table
	for (list<sym>::iterator it = globalTable->table.begin(); it != globalTable->table.end(); it++)
	{
		if (it->nested != NULL)
			tablelist.push_back(it->nested);
	}
	// Compute activation record for all (nested) the symbol table
	for (list<symtable *>::iterator iterator = tablelist.begin();
		 iterator != tablelist.end(); ++iterator)
	{
		computeActivationRecord(*iterator);
	}

	// Assembly file -> sfile (.s)
	ofstream sfile;
	sfile.open(asmfilename.c_str());

	// Begin the .s file
	sfile << "\t.file	\"test.c\"\n";
	for (list<sym>::iterator it = table->table.begin(); it != table->table.end(); it++)
	{
		if (it->category != "function")
		{
			// Global char
			if (it->type->type == "CHAR")
			{
				if (it->initial_value != "")
				{
					sfile << "\t.globl\t" << it->name << "\n";
					sfile << "\t.type\t" << it->name << ", @object\n";
					sfile << "\t.size\t" << it->name << ", 1\n";
					sfile << it->name << ":\n";
					sfile << "\t.byte\t" << atoi(it->initial_value.c_str()) << "\n";
				}
				else
				{
					sfile << "\t.comm\t" << it->name << ",1,1\n";
				}
			}
			// Global int
			if (it->type->type == "INTEGER")
			{
				if (it->initial_value != "")
				{
					sfile << "\t.globl\t" << it->name << "\n";
					sfile << "\t.data\n";
					sfile << "\t.align 4\n";
					sfile << "\t.type\t" << it->name << ", @object\n";
					sfile << "\t.size\t" << it->name << ", 4\n";
					sfile << it->name << ":\n";
					sfile << "\t.long\t" << it->initial_value << "\n";
				}
				else
				{
					sfile << "\t.comm\t" << it->name << ",4,4\n";
				}
			}
		}
	}
	// The strings from input (to be output in stdout)
	if (allstrings.size())
	{
		sfile << "\t.section\t.rodata\n";
		for (vector<string>::iterator it = allstrings.begin(); it != allstrings.end(); it++)
		{
			sfile << ".LC" << it - allstrings.begin() << ":\n";
			sfile << "\t.string\t" << *it << "\n";
		}
	}

	// Begin the text segment
	sfile << "\t.text	\n";

	vector<string> params;
	std::map<string, int> theMap;
	for (vector<quad>::iterator it = Array.begin(); it != Array.end(); it++)
	{
		if (labelMap.count(it - Array.begin()))
		{
			sfile << ".L" << (2 * labelCount + labelMap.at(it - Array.begin()) + 2) << ": " << endl;
		}

		string op = it->op;
		string result = it->result;
		string arg1 = it->arg1;
		string arg2 = it->arg2;
		string s = arg2;

		// If param -> add to the param list
		if (op == "PARAM")
		{
			params.push_back(result);
		}
		else
		{
			sfile << "\t";

			// Binary Operations
			// Addition operation
			if (op == "ADD")
			{
				bool flag = true;
				if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
					flag = false;
				else
				{
					char *p;
					strtol(s.c_str(), &p, 10);
					if (*p == 0)
						flag = true;
					else
						flag = false;
				}
				if (flag)
				{
					sfile << "addl \t$" << atoi(arg2.c_str()) << ", " << table->ar[arg1] << "(%rbp)";
				}
				else
				{
					sfile << "movl \t" << table->ar[arg1] << "(%rbp), "
						  << "%eax" << endl;
					sfile << "\tmovl \t" << table->ar[arg2] << "(%rbp), "
						  << "%edx" << endl;
					sfile << "\taddl \t%edx, %eax\n";
					sfile << "\tmovl \t%eax, " << table->ar[result] << "(%rbp)";
				}
			}
			// Subtract operation
			else if (op == "SUB")
			{
				sfile << "movl \t" << table->ar[arg1] << "(%rbp), "
					  << "%eax" << endl;
				sfile << "\tmovl \t" << table->ar[arg2] << "(%rbp), "
					  << "%edx" << endl;
				sfile << "\tsubl \t%edx, %eax\n";
				sfile << "\tmovl \t%eax, " << table->ar[result] << "(%rbp)";
			}
			// Multiplcation operator
			else if (op == "MULT")
			{
				sfile << "movl \t" << table->ar[arg1] << "(%rbp), "
					  << "%eax" << endl;
				bool flag = true;
				if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
					flag = false;
				else
				{
					char *p;
					strtol(s.c_str(), &p, 10);
					if (*p == 0)
						flag = true;
					else
						flag = false;
				}
				if (flag)
				{
					sfile << "\timull \t$" << atoi(arg2.c_str()) << ", "
						  << "%eax" << endl;
					symtable *t = table;
					string val;
					for (list<sym>::iterator it = t->table.begin(); it != t->table.end(); it++)
					{
						if (it->name == arg1)
							val = it->initial_value;
					}
					theMap[result] = atoi(arg2.c_str()) * atoi(val.c_str());
				}
				else
					sfile << "\timull \t" << table->ar[arg2] << "(%rbp), "
						  << "%eax" << endl;
				sfile << "\tmovl \t%eax, " << table->ar[result] << "(%rbp)";
			}
			// Divide operation
			else if (op == "DIVIDE")
			{
				sfile << "movl \t" << table->ar[arg1] << "(%rbp), "
					  << "%eax" << endl;
				sfile << "\tcltd" << endl;
				sfile << "\tidivl \t" << table->ar[arg2] << "(%rbp)" << endl;
				sfile << "\tmovl \t%eax, " << table->ar[result] << "(%rbp)";
			}

			// Bit Operators
			else if (op == "MODOP")
				sfile << result << " = " << arg1 << " % " << arg2;
			else if (op == "XOR")
				sfile << result << " = " << arg1 << " ^ " << arg2;
			else if (op == "INOR")
				sfile << result << " = " << arg1 << " | " << arg2;
			else if (op == "BAND")
				sfile << result << " = " << arg1 << " & " << arg2;
			// Shift Operations
			else if (op == "LEFTOP")
				sfile << result << " = " << arg1 << " << " << arg2;
			else if (op == "RIGHTOP")
				sfile << result << " = " << arg1 << " >> " << arg2;

			// Copy
			else if (op == "EQUAL")
			{
				s = arg1;
				bool flag = true;
				if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
					flag = false;
				else
				{
					char *p;
					strtol(s.c_str(), &p, 10);
					if (*p == 0)
						flag = true;
					else
						flag = false;
				}
				if (flag)
					sfile << "movl\t$" << atoi(arg1.c_str()) << ", "
						  << "%eax" << endl;
				else
					sfile << "movl\t" << table->ar[arg1] << "(%rbp), "
						  << "%eax" << endl;
				sfile << "\tmovl \t%eax, " << table->ar[result] << "(%rbp)";
			}
			else if (op == "EQUALSTR")
			{
				sfile << "movq \t$.LC" << arg1 << ", " << table->ar[result] << "(%rbp)";
			}
			else if (op == "EQUALCHAR")
			{
				sfile << "movb\t$" << atoi(arg1.c_str()) << ", " << table->ar[result] << "(%rbp)";
			}

			// Relational Operations
			else if (op == "EQOP")
			{
				sfile << "movl\t" << table->ar[arg1] << "(%rbp), %eax\n";
				sfile << "\tcmpl\t" << table->ar[arg2] << "(%rbp), %eax\n";
				sfile << "\tje .L" << (2 * labelCount + labelMap.at(atoi(result.c_str())) + 2);
			}
			else if (op == "NEOP")
			{
				sfile << "movl\t" << table->ar[arg1] << "(%rbp), %eax\n";
				sfile << "\tcmpl\t" << table->ar[arg2] << "(%rbp), %eax\n";
				sfile << "\tjne .L" << (2 * labelCount + labelMap.at(atoi(result.c_str())) + 2);
			}
			else if (op == "LT")
			{
				sfile << "movl\t" << table->ar[arg1] << "(%rbp), %eax\n";
				sfile << "\tcmpl\t" << table->ar[arg2] << "(%rbp), %eax\n";
				sfile << "\tjl .L" << (2 * labelCount + labelMap.at(atoi(result.c_str())) + 2);
			}
			else if (op == "GT")
			{
				sfile << "movl\t" << table->ar[arg1] << "(%rbp), %eax\n";
				sfile << "\tcmpl\t" << table->ar[arg2] << "(%rbp), %eax\n";
				sfile << "\tjg .L" << (2 * labelCount + labelMap.at(atoi(result.c_str())) + 2);
			}
			else if (op == "GE")
			{
				sfile << "movl\t" << table->ar[arg1] << "(%rbp), %eax\n";
				sfile << "\tcmpl\t" << table->ar[arg2] << "(%rbp), %eax\n";
				sfile << "\tjge .L" << (2 * labelCount + labelMap.at(atoi(result.c_str())) + 2);
			}
			else if (op == "LE")
			{
				sfile << "movl\t" << table->ar[arg1] << "(%rbp), %eax\n";
				sfile << "\tcmpl\t" << table->ar[arg2] << "(%rbp), %eax\n";
				sfile << "\tjle .L" << (2 * labelCount + labelMap.at(atoi(result.c_str())) + 2);
			}
			else if (op == "GOTOOP")
			{
				sfile << "jmp .L" << (2 * labelCount + labelMap.at(atoi(result.c_str())) + 2);
			}

			// Unary Operators
			else if (op == "ADDRESS")
			{
				sfile << "leaq\t" << table->ar[arg1] << "(%rbp), %rax\n";
				sfile << "\tmovq \t%rax, " << table->ar[result] << "(%rbp)";
			}
			else if (op == "PTRR")
			{
				sfile << "movl\t" << table->ar[arg1] << "(%rbp), %eax\n";
				sfile << "\tmovl\t(%eax),%eax\n";
				sfile << "\tmovl \t%eax, " << table->ar[result] << "(%rbp)";
			}
			else if (op == "PTRL")
			{
				sfile << "movl\t" << table->ar[result] << "(%rbp), %eax\n";
				sfile << "\tmovl\t" << table->ar[arg1] << "(%rbp), %edx\n";
				sfile << "\tmovl\t%edx, (%eax)";
			}
			else if (op == "UMINUS")
			{
				sfile << "negl\t" << table->ar[arg1] << "(%rbp)";
			}
			else if (op == "BNOT")
				sfile << result << " = ~" << arg1;
			else if (op == "LNOT")
				sfile << result << " = !" << arg1;
			else if (op == "ARRR")
			{
				int off = 0;
				off = theMap[arg2] * (-1) + table->ar[arg1];
				sfile << "movq\t" << off << "(%rbp), "
					  << "%rax" << endl;
				sfile << "\tmovq \t%rax, " << table->ar[result] << "(%rbp)";
			}
			else if (op == "ARRL")
			{
				int off = 0;
				off = theMap[arg1] * (-1) + table->ar[result];
				sfile << "movq\t" << table->ar[arg2] << "(%rbp), "
					  << "%rdx" << endl;
				sfile << "\tmovq\t"
					  << "%rdx, " << off << "(%rbp)";
			}
			else if (op == "RETURN")
			{
				if (result != "")
					sfile << "movl\t" << table->ar[result] << "(%rbp), "
						  << "%eax";
				else
					sfile << "nop";
			}
			else if (op == "PARAM")
			{
				params.push_back(result);
			}

			// Call a function
			else if (op == "CALL")
			{
				// Function Table
				symtable *t = globalTable->lookup(arg1)->nested;
				int i, j = 0; // Index
				for (list<sym>::iterator it = t->table.begin(); it != t->table.end(); it++)
				{
					i = distance(t->table.begin(), it);
					if (it->category == "param")
					{
						if (j == 0)
						{
							// The first parameter to the function
							sfile << "movl \t" << table->ar[params[i]] << "(%rbp), "
								  << "%eax" << endl;
							sfile << "\tmovq \t" << table->ar[params[i]] << "(%rbp), "
								  << "%rdi" << endl;
							j++;
						}
						else if (j == 1)
						{
							// The second parameter to the function
							sfile << "movl \t" << table->ar[params[i]] << "(%rbp), "
								  << "%eax" << endl;
							sfile << "\tmovq \t" << table->ar[params[i]] << "(%rbp), "
								  << "%rsi" << endl;
							j++;
						}
						else if (j == 2)
						{
							// The third parameter to the function
							sfile << "movl \t" << table->ar[params[i]] << "(%rbp), "
								  << "%eax" << endl;
							sfile << "\tmovq \t" << table->ar[params[i]] << "(%rbp), "
								  << "%rdx" << endl;
							j++;
						}
						else if (j == 3)
						{
							// The fourth parameter to the function
							sfile << "movl \t" << table->ar[params[i]] << "(%rbp), "
								  << "%eax" << endl;
							sfile << "\tmovq \t" << table->ar[params[i]] << "(%rbp), "
								  << "%rcx" << endl;
							j++;
						}
						else
						{
							sfile << "\tmovq \t" << table->ar[params[i]] << "(%rbp), "
								  << "%rdi" << endl;
						}
					}
					else
						break;
				}
				params.clear();
				sfile << "\tcall\t" << arg1 << endl;
				sfile << "\tmovl\t%eax, " << table->ar[result] << "(%rbp)";
			}

			else if (op == "FUNC")
			{
				// Prologue of a function
				sfile << ".globl\t" << result << "\n";
				sfile << "\t.type\t" << result << ", @function\n";
				sfile << result << ": \n";
				sfile << ".LFB" << labelCount << ":" << endl;
				sfile << "\t.cfi_startproc" << endl;
				sfile << "\tpushq \t%rbp" << endl;
				sfile << "\t.cfi_def_cfa_offset 8" << endl;
				sfile << "\t.cfi_offset 5, -8" << endl;
				sfile << "\tmovq \t%rsp, %rbp" << endl;
				sfile << "\t.cfi_def_cfa_register 5" << endl;
				table = globalTable->lookup(result)->nested;
				sfile << "\tsubq\t$" << table->table.back().offset + 24 << ", %rsp" << endl;

				// Function Table
				symtable *t = table;
				int i = 0;
				for (list<sym>::iterator it = t->table.begin(); it != t->table.end(); it++)
				{
					if (it->category == "param")
					{
						if (i == 0)
						{
							sfile << "\tmovq\t%rdi, " << table->ar[it->name] << "(%rbp)";
							i++;
						}
						else if (i == 1)
						{
							sfile << "\n\tmovq\t%rsi, " << table->ar[it->name] << "(%rbp)";
							i++;
						}
						else if (i == 2)
						{
							sfile << "\n\tmovq\t%rdx, " << table->ar[it->name] << "(%rbp)";
							i++;
						}
						else if (i == 3)
						{
							sfile << "\n\tmovq\t%rcx, " << table->ar[it->name] << "(%rbp)";
							i++;
						}
					}
					else
						break;
				}
			}

			// Epilogue of a function
			// Function ends
			else if (op == "FUNCEND")
			{
				sfile << "leave\n";
				sfile << "\t.cfi_restore 5\n";
				sfile << "\t.cfi_def_cfa 4, 4\n";
				sfile << "\tret\n";
				sfile << "\t.cfi_endproc" << endl;
				sfile << ".LFE" << labelCount++ << ":" << endl;
				sfile << "\t.size\t" << result << ", .-" << result;
			}
			else
				sfile << "op";
			sfile << endl;
		}
	}
	// Footnote
	sfile << "\t.ident\t	\"Compiled by 20CS10067 and 20CS30008\"\n";
	sfile << "\t.section\t.note.GNU-stack,\"\",@progbits\n";
	sfile.close();
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
	copy(v.begin(), v.end(), ostream_iterator<T>(os, " "));
	return os;
}

int main(int ac, char *av[])
{
	inputfile = inputfile + string(av[ac - 1]) + string(".c");
	asmfilename = asmfilename + string(av[ac - 1]) + string(".s");
	globalTable = new symtable("Global");
	table = globalTable;
	yyin = fopen(inputfile.c_str(), "r");
	yyparse();
	globalTable->update();
	globalTable->print();
	q.print();
	genasm();
}
