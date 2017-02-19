#include "debug_mode.h"
#include "node.h"
#include "codegen.h"
#include "parser.hpp"

using namespace std;

/* Compile the AST into a module */
void CodeGenContext::generateCode(NBlock& root)
{
	std::cout << "Generating code...\n";
	//TODO
}
/* Returns an LLVM type based on the identifier */
static Type *typeOf(const NIdentifier& type) 
{
	if (type.name.compare("int") == 0) {
		return Type::getInt64Ty(getGlobalContext());
	}
	else if (type.name.compare("real") == 0) {
		return Type::getDoubleTy(getGlobalContext());
	}
	else if (type.name.compare("char") == 0) {
		return Type::getInt8Ty(getGlobalContext());
	}
	else if (type.name.compare("bool") == 0) {
		return Type::getInt1Ty(getGlobalContext());
	}
	else if (type.name.compare("long") == 0) {
		return Type::getInt128Ty(getGlobalContext());
	}
	//TODO: type of string
	return Type::getVoidTy(getGlobalContext());
}

/* -- Code Generation -- */

Value* NInteger::codeGen(CodeGenContext& context)
{
	std::cout << "Creating integer: " << value << endl;
	return ConstantInt::get(Type::getInt64Ty(getGlobalContext()), value, true);
}

Value* NReal::codeGen(CodeGenContext& context)
{
	std::cout << "Creating real: " << value << endl;
	return ConstantFP::get(Type::getDoubleTy(getGlobalContext()), value);
}

Value* NChar::codeGen(CodeGenContext& context)
{
	std::cout << "Creating char: " << value << endl;
	return return ConstantInt::get(Type::getInt8Ty(getGlobalContext()), value, true); //TODO: is it correct?
}

Value* NBool::codeGen(CodeGenContext& context)
{
	std::cout << "Creating integer: " << value << endl;
	return ConstantInt::get(Type::getInt1Ty(getGlobalContext()), value, true);
}

Value* NIdentifier::codeGen(CodeGenContext& context)
{
	std::cout << "Creating identifier reference: " << name << endl;
	if (context.locals().find(name) == context.locals().end()) {
		std::cerr << "undeclared variable " << name << endl;
		return NULL;
	}
	return new LoadInst(context.locals()[name], "", false, context.currentBlock());
}

Value* N NFuncCall::codeGen(CodeGenContext& context)
{
	Function *function = context.module->getFunction(id.name.c_str());
	if (function == NULL) {
		std::cerr << "no such function " << id.name << endl;
	}
	std::vector<Value*> args;
	ExpressionList::const_iterator it;
	for (it = arguments.begin(); it != arguments.end(); it++) {
		args.push_back((**it).codeGen(context));
	}
	CallInst *call = CallInst::Create(function, makeArrayRef(args), "", context.currentBlock());
	std::cout << "Creating method call: " << id.name << endl;
	return call;
}

