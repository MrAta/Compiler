#include "debug_mode.h"
#include <iostream>
#include <fstream>
//#if TEST_MODE > TEST_AST_GEN
#include "codegen.h"
//#endif
#include "node.h"
#include <string>

using namespace std;

extern int yyparse();
extern NProgram* programBlock;

void createCoreFunctions(CodeGenContext& context);

extern "C" FILE* yyin;

int main(int argc, char **argv)
{	
	string filename(argv[1]);

	yyin = fopen(argv[1], "r");
//	FILE *in = stdin;
/*
	ifstream in(filename);
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());
*/

	filename = filename.substr(0, filename.find_last_of("."));
//	yyin  = fopen(argv[1], "r");
	ofstream res;
	res.open(filename+".res");
//	ofstream out;
//	res.open(filename+".out", std::ios::binary);
//	FILE *res = fopen((filename+".res").c_str(), "w");
//	FILE *out = fopen((filename+".out").c_str(), "w");
//	yyout = fopen(argv[2], "w");
	if(!yyparse()){
		//fprintf(res, "1");
		res << 1 << endl;
	}else{
		//fprintf(res, "0");
		res << 0 << endl;
	}
	res.close();

    // see http://comments.gmane.org/gmane.comp.compilers.llvm.devel/33877
	InitializeNativeTarget();
	InitializeNativeTargetAsmPrinter();
	InitializeNativeTargetAsmParser();
	CodeGenContext context;
	createCoreFunctions(context);
	context.generateCode(*programBlock);
	context.runCode();

//	programBlock->codeGen();	
	return 0;
}

