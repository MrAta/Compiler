#include "debug_mode.h"
#include "node.h"
#include "codegen.h"
#include "parser.hpp"

using namespace std;

/* Compile the AST into a module */
void CodeGenContext::generateCode(NProgram& root)
{
	std::cout << "Generating code...\n";
	
#if 0	//DeclarationList& declarations;
	DeclarationList::const_iterator it;
	NFunctionDecl* start;
	for (it = root.declarations.begin(); it != root.declarations.end(); it++) {
		std::cout << "Finding start function" << endl;
		if(NFunctionDecl* f = dynamic_cast<NFunctionDecl*>(**it)){
			if(root.start.name.compare(f.id.name) != 0) {
				start = f;
				break;
			}
		}
	}
	std::cout << "Generating code...\n";
	
	/* Create the top level interpreter function to call as entry */
	vector<Type*> argTypes;
	FunctionType *ftype = FunctionType::get(Type::getVoidTy(getGlobalContext()), makeArrayRef(argTypes), false);
	mainFunction = Function::Create(ftype, GlobalValue::InternalLinkage, "start", module);
	BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry", mainFunction, 0);

	/* Push a new variable/block context */
	pushBlock(bblock);

	root.codeGen(*this); /* emit bytecode for the toplevel block */
	ReturnInst::Create(getGlobalContext(), bblock);
	popBlock();
#endif
	root.codeGen(*this);
	/* Print the bytecode in a human-readable format 
	   to see if our program compiled properly
	 */
	startFunction = context.module->getFunction(root.start.name.c_str());
	if(startFunction == NULL){
		std::cerr << "no start function" << endl;
		exit(0);
	}
	if(finishFunction != NULL) 
		finishFunction = context.module->getFunction(root.finish.name.c_str());
	std::cout << "Code is generated.\n";
	/* Print the bytecode in a human-readable format 
	   to see if our program compiled properly
	 */
	PassManager<Module> pm;
	pm.addPass(PrintModulePass(outs()));
	pm.run(*module);
}

/* Executes the AST by running the main function */
GenericValue CodeGenContext::runCode() {
	std::cout << "Running code...\n";
	ExecutionEngine *ee = EngineBuilder( unique_ptr<Module>(module) ).create();
	ee->finalizeObject();
	vector<GenericValue> noargs;
	GenericValue v = ee->runFunction(startFunction, noargs);
if(finishFunction != NULL) enericValue v = ee->runFunction(finishFunction, noargs);
	std::cout << "Code was run.\n";
	return v;
}

Value* NProgram::codeGen(CodeGenContext& context){
//DeclarationList& declarations;
	DeclarationList::const_iterator it;
	Value *last = NULL;
	for (it = declarations.begin(); it != declarations.end(); it++) {
		std::cout << "Generating code for " << typeid(**it).name() << endl;
		last = (**it).codeGen(context);
	}
	std::cout << "Creating program" << endl;
	return last;
}

/* Returns an LLVM type based on the identifier */
static Type *typeOf(int type, int size) 
{	
	if (size <= 1) {
		if (type == INT) {
			return Type::getInt64Ty(getGlobalContext());
		}
		else if (type == REAL) {
			return Type::getDoubleTy(getGlobalContext());
		}
		else if (type == CHAR) {
			return Type::getInt8Ty(getGlobalContext());
		}
		else if (type == BOOL) {
			return Type::getInt1Ty(getGlobalContext());
		}
		else if (type == LONG) {
			return Type::getInt128Ty(getGlobalContext());
		} 
	}
	else {
		if (type == INT) {
			return Type::getInt64PtrTy(getGlobalContext());
		}
		else if (type == REAL) {
			return Type::getDoublePtrTy(getGlobalContext());
		}
		//TODO: type of string
		else if (type == CHAR || type == STRING) {
			return Type::getInt8PtrTy(getGlobalContext());
		}
		else if (type == BOOL) {
			return Type::getInt1PtrTy(getGlobalContext());
		}
		else if (type == LONG) {
			return Type::getInt128PtrTy(getGlobalContext());
		}
	}

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
	return ConstantFP::get(Type::getFloatTy(getGlobalContext()), value);
}

Value* NChar::codeGen(CodeGenContext& context)
{
	std::cout << "Creating char: " << value << endl;
	return return ConstantInt::get(Type::getInt8Ty(getGlobalContext()), 		value, true);
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

Value* NString::codeGen(CodeGenContext& context)
{
	//TODO
	/*std::cout << "Creating string: " << value << endl;
	return ConstantInt::get(Type::getInt8Ty(getGlobalContext()), 		value, true);*/
//	Value* NChar::codeGen(CodeGenContext& context)
//{
	std::cout << "Creating string: " << value << endl;
	Constant *const_str = ConstantDataArray::getString(context, value, true);
//	GlobalVariable* gvar_array__str = new GlobalVariable(/*Module=*/*mod, 
//	/*Type=*/ArrayTy_0,
//	/*isConstant=*/true,
//	/*Linkage=*/GlobalValue::PrivateLinkage,
//	/*Initializer=*/0, // has initializer, specified below
//	/*Name=*/".str");
//	gvar_array__str->setAlignment(1);
//	gvar_array__str->setInitializer(const_str);
//}
	return const_str;
}

Value* NBinaryOp::codeGen(CodeGenContext& context)
{
	std::cout << "Creating binary operation " << op << endl;
	Instruction::BinaryOps instr;
	Value *L = lhs->codegen();
	Value *R = rhs->codegen();
	switch (op) {
		case PLUS: 		    return context.builder.CreateFAdd(L, R, "addtmp");
		case MINUS: 		return context.builder.CreateFSub(L, R, "subtmp");
		case MUL: 		    return context.builder.CreateFMul(L, R, "multmp");
		case DIV: 			return context.builder.CreateFDiv(L, R, "divtmp");
		case MOD:			return context.builder.CreateSRem(L, R, "remtmp");
		case OR:			instr = Instruction::Or; goto math;
		case AND:			instr = Instruction::And; goto math;
		case XOR:			instr = Instruction::Xor; goto math;
		
		case GT:			L = context.builder.CreateICmpSGT(L, R, "gttmp"); 	goto cond;
		case LT:			L = context.builder.CreateICmpSLT(L, R, "ltvtmp"); goto cond;
		case GTEQ:			L = context.builder.CreateICmpSGE(L, R, "getmp"); goto cond;
		case LTEQ:			L = context.builder.CreateICmpSLE(L, R, "letmp"); goto cond;
		case NOTEQ:			L = context.builder.CreateICmpNE(L, R, "andtmp"); goto cond;
		case EQEQ:			return context.builder.CreateICmpEQ(L, R, "andtmp"); goto cond;
		case ANDAND:		return context.builder.CreateAnd(L, R, "andtmp"); goto cond;
		case OROR:			return context.builder.CreateOr(L, R, "ortmp"); goto cond;
		
		
	}

	return NULL;

cond:
	     return context.builder.CreateUIToFP(L, Type::getDoubleTy(TheContext),
                                "booltmp");
math:
	return BinaryOperator::Create(instr, lhs.codeGen(context), 
		rhs.codeGen(context), "", context.currentBlock());
}

Value* NUnaryOp::codeGen(CodeGenContext& context)
{
	Value *R = e->codegen();
	std::cout << "Creating binary operation " << op << endl;
	Instruction::BinaryOps instr;
	switch (op) {		
		case COMP:			BinaryOperator::Create(Instruction::Xor, 0xFFFFFFFF, 
										R, "", context.currentBlock());
		case NOT:			return context.builder.CreateNot(R, "subtmp");
		case MINUS:			return context.builder.CreateFSub(0, R, "subtmp");
		
	}

	return NULL;
math:
	return BinaryOperator::Create(instr, lhs.codeGen(context), 
		rhs.codeGen(context), "", context.currentBlock());
}

Value* NReturn::codeGen(CodeGenContext& context)
{
	std::cout << "Generating return code for " << typeid(expression).name() << endl;
	Value *returnValue = idl.at(0).;//expression.codeGen(context);
	context.setCurrentReturnValue(returnValue);
	return returnValue;
}

Value* NVarDecl::codeGen(CodeGenContext& context)
{
	std::cout << "Creating variable declaration " << TsDecl.type << " " << id.name << endl;
	AllocaInst *alloc = new AllocaInst(typeOf(TsDecl.type, TsDecl.size), 	id.name.c_str(), context.currentBlock());
	context.locals()[id.name] = alloc;
	/*if (assignmentExpr != NULL) {
		NAssignment assn(id, *assignmentExpr);
		assn.codeGen(context);
	}*/
	return alloc;
}

Value* NFunctionDecl::codeGen(CodeGenContext& context)
{
	vector<Type*> argTypes;
	VariableList::const_iterator it;
	for (it = arguments.begin(); it != arguments.end(); it++) {
		argTypes.push_back(typeOf((**it).TsDecl.at(0).type, (**it).TsDecl.at(0).size));
	}
	FunctionType *ftype = FunctionType::get(typeOf(returns.at(0).type, returns.at(0).size), makeArrayRef(argTypes), false);
	Function *function = Function::Create(ftype, GlobalValue::InternalLinkage, id.name.c_str(), context.module);
	BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry", function, 0);

	context.pushBlock(bblock);

	Function::arg_iterator argsValues = function->arg_begin();
    Value* argumentValue;

	for (it = arguments.begin(); it != arguments.end(); it++) {
		(**it).codeGen(context);
		
		argumentValue = &*argsValues++;
		argumentValue->setName((*it)->id.name.c_str());
		StoreInst *inst = new StoreInst(argumentValue, context.locals()[(*it)->id.name], false, bblock);
	}
	
	block.codeGen(context);
	ReturnInst::Create(getGlobalContext(), context.getCurrentReturnValue(), bblock);

	context.popBlock();
	std::cout << "Creating function: " << id.name << endl;
	return function;
}



Value* NFuncCall::codeGen(CodeGenContext& context)
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

Value* NAssignment::codeGen(CodeGenContext& context)
{
	if (NVarDecl* var = dynamic_cast<NVarDecl*>(lhs)) {
		std::cout << "Creating assignment for " << vd.id.name <<endl;
		vd.codeGen(context);
		if(vd.TsDecl.at(0).size > 1) goto array;
		return new StoreInst(rhs.at(0).codeGen(context), context.locals()[vd.id.name], false, context.currentBlock());		
	}
	else if (NIdentifier* id = dynamic_cast<NIdentifier*>(lhs)) {
		std::cout << "Creating assignment for " << id.name <<endl;
		if (context.locals().find(id.name) == context.locals().end()) {
			std::cerr << "undeclared variable " << lhs.name << endl;
			return NULL;
		}
		return new StoreInst(rhs.at(0).codeGen(context), context.locals()[id.name], false, context.currentBlock());
	}

array:
	//TODO
}

Value* NBlock::codeGen(CodeGenContext& context)
{
	StatementList::const_iterator it;
	Value *last = NULL;
	for (it = statements.begin(); it != statements.end(); it++) {
		std::cout << "Generating code for " << typeid(**it).name() << endl;
		last = (**it).codeGen(context);
	}
	std::cout << "Creating block" << endl;
	return last;
}

