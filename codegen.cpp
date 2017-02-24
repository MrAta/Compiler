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
		else if (type == CHAR) {
			return Type::getInt8PtrTy(getGlobalContext());
		}
		else if (type == BOOL) {
			return Type::getInt1PtrTy(getGlobalContext());
		}
		else if (type == LONG) {
			return Type::getInt128PtrTy(getGlobalContext());
		}
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
	return return ConstantInt::get(Type::getInt8Ty(getGlobalContext()), 		value, true);*/
//	Value* NChar::codeGen(CodeGenContext& context)
//{
	/*std::cout << "Creating string: " << value << endl;
	return ConstantDataArray::getString(context, value, true);*/
//}
}

Value* NBinaryOp::codeGen(CodeGenContext& context)
{
	std::cout << "Creating binary operation " << op << endl;
	Instruction::BinaryOps instr;
	Value *L = lhs->codegen();
	Value *R = rhs->codegen();
	//TODO generate code for L R
	switch (op) {
		case PLUS: 		    return Builder.CreateFAdd(L, R, "addtmp");
		case MINUS: 		return Builder.CreateFSub(L, R, "subtmp");
		case MUL: 		    return Builder.CreateFMul(L, R, "multmp");
		case DIV: 			return Builder.CreateFDiv(L, R, "divtmp");
		case MOD:			return Builder.CreateSRem(L, R, "remtmp");
		case OR:			instr = Instruction::Or; goto math;
		case AND:			instr = Instruction::And; goto math;
		case XOR:			instr = Instruction::Xor; goto math;
		
		case GT:			L = Builder.CreateICmpSGT(L, R, "gttmp"); 	goto cond;
		case LT:			L = Builder.CreateICmpSLT(L, R, "ltvtmp"); goto cond;
		case GTEQ:			L = Builder.CreateICmpSGE(L, R, "getmp"); goto cond;
		case LTEQ:			L = Builder.CreateICmpSLE(L, R, "letmp"); goto cond;
		case NOTEQ:			L = Builder.CreateICmpNE(L, R, "andtmp"); goto cond;
		case EQEQ:			return Builder.CreateICmpEQ(L, R, "andtmp"); goto cond;
		case ANDAND:		return Builder.CreateAnd(L, R, "andtmp"); goto cond;
		case OROR:			return Builder.CreateOr(L, R, "ortmp"); goto cond;
		
		
	}

	return NULL;

cond:
	     return Builder.CreateUIToFP(L, Type::getDoubleTy(TheContext),
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
		case NOT:			return Builder.CreateNot(R, "subtmp");
		case MINUS:			return Builder.CreateFSub(0, R, "subtmp");
		
	}

	return NULL;
math:
	return BinaryOperator::Create(instr, lhs.codeGen(context), 
		rhs.codeGen(context), "", context.currentBlock());
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

Value* NFunctionDeclaration::codeGen(CodeGenContext& context)
{
	vector<Type*> argTypes;
	VariableList::const_iterator it;
	for (it = arguments.begin(); it != arguments.end(); it++) {
		argTypes.push_back(typeOf((**it).type));
	}
	FunctionType *ftype = FunctionType::get(typeOf(type), makeArrayRef(argTypes), false);
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
	switch(type){
			case 1:
			{
				std::cout << "Creating assignment for " << id.name <<endl;
			
			}
			break;
			case 2:
			{
				std::cout << "Creating assignment for " << vd.id.name <<endl;
				
			}
			break;
			case 3:
			{
				std::cout << "Creating assignment for " << id.name <<endl;
				
			}
			break;
	}
	
	/*	if (context.locals().find(lhs.name) == context.locals().end()) {
		std::cerr << "undeclared variable " << lhs.name << endl;
		return NULL;
	}
	return new StoreInst(rhs.codeGen(context), context.locals()[lhs.name], false, context.currentBlock());*/
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

