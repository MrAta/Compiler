#include "debug_mode.h"

#include <iostream>
#include <vector>
#if TEST_MODE > TEST_AST_GEN
#include <llvm/IR/Value.h>
#endif

#if TEST_MODE > TEST_AST
#define TEST_PRINT() 
#define TEST_PRINT_LEAF(token)	
#define TEST_PRINT_MEM(token)
#define TEST_PRINT_ME(level)
#else
#define TEST_PRINT()		do{std::cout << __PRETTY_FUNCTION__ << std::endl; }while(0)
#define TEST_PRINT_LEAF(token)	do{std::cout << (token) << " ";}while(0)
#define TEST_PRINT_MEM(token)	do{(token).print();}while(0)
#define TEST_PRINT_ME(level)	do{if( AST_DEBUG_LEVEL <= (level) ) {this->print(); std::cout << std::endl;} }while(0)
#endif

#if HAS_CODEGEN

#define CODEGEN_FUNC()	llvm::Value*	codeGen(CodeGenContext& context)
#define VIRTUAL_CODEGEN_FUNC() virtual CODEGEN_FUNC() {}

#else

#define CODEGEN_FUNC()	/*virtual void*		codeGen(CodeGenContext& context)*/
#define VIRTUAL_CODEGEN_FUNC()

#endif

/* What Parser knows */
class CodeGenContext;
class Node;
class NExpression;
class NConst;
class NInteger;
class NIdentifier;
class NUnaryOp;
class NBinaryOp;
class NArrayExpr;
class NStatement;
class NReturn;
class NFuncCall;
class NDecl;
class NVarDecl;
class TsDecl;
class NAssignment;
class AssignmentLHS;
class NCase;
class NSwitch;
class NIf;
class NBlock;
class NFunctionDecl;
class NProgram;
typedef std::vector<NIdentifier*> IdentifierList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NStatement*> StatementList;
typedef std::vector<TsDecl*> TsDeclList;
typedef std::vector<NVarDecl*> VariableList;
typedef std::vector<NDecl*> DeclarationList;
typedef std::vector<NCase*> CaseList;

extern NProgram    *programBlock;
extern NIdentifier *start;
extern NIdentifier *finish;

/* Not used directly by Parser */
class NLong;
class NReal;
class NChar;
class NBool;
class NString;
class NBreak;
class NContinue;
class NConditional;

/* Class Declarations */

class Node {
public:
	virtual ~Node() {}
	VIRTUAL_CODEGEN_FUNC()
	virtual void print() {}
};

class NExpression : public Node {
public:
	VIRTUAL_CODEGEN_FUNC();
	virtual void print() {}
};

class NStatement : public Node {
public:
	VIRTUAL_CODEGEN_FUNC();
	virtual void print() {}
};

class NConst   : public NExpression {
public:
	VIRTUAL_CODEGEN_FUNC();
	virtual void print() {}
};

class NDecl : public Node {
public:
	VIRTUAL_CODEGEN_FUNC();
	virtual void print() {}
};

class AssignmentLHS : public Node {
public:
	VIRTUAL_CODEGEN_FUNC();
	virtual void print() {}
};

class NConditional : public NStatement {
public:
	VIRTUAL_CODEGEN_FUNC();
	virtual void print() {}
};

class NForIterator : public Node {
public:
	virtual int start() {}
	virtual int step() {}
	virtual int end() {}
	VIRTUAL_CODEGEN_FUNC();
	virtual void print() {}
};

class NForRangeOperand : public Node {
public:
	VIRTUAL_CODEGEN_FUNC();
	virtual void print() {}
};

class NInteger : public NConst, public NForRangeOperand {
public:
	long value;
	NInteger(int value) : value(value) { TEST_PRINT(); TEST_PRINT_ME(1); }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF(value);
	}
};

class NLong : public NConst {
public:
	long value;
	NLong(long value) : value(value) { TEST_PRINT(); TEST_PRINT_ME(1); }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF(value);
	}
};

class NReal : public NConst {
public:
	double value;
	NReal(double value) : value(value) { TEST_PRINT(); TEST_PRINT_ME(1); }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF(value);
	}
};

class NChar : public NConst {
public:
	char value;
	NChar(char value) : value(value) { TEST_PRINT(); TEST_PRINT_ME(1); }
	CODEGEN_FUNC();
	void print(){
		printf("%c", value);//TEST_PRINT_LEAF(value);
	}
};

class NBool : public NConst {
public:
	bool value;
	NBool(bool value) : value(value) { TEST_PRINT(); TEST_PRINT_ME(1); }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF(value);
	}
};

class NString : public NConst {
public:
	std::string value;
	NString(std::string& value) : value(value) { TEST_PRINT(); TEST_PRINT_ME(1); }

	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF(value);
	}
};

class NIdentifier : public NExpression, public AssignmentLHS, public NForRangeOperand {
public:
	std::string name;
	NIdentifier(std::string& name) : name(name) { TEST_PRINT(); TEST_PRINT_ME(1); }

	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF(name);
	}
};


class NUnaryOp : public NExpression {
public:
	NExpression& e;
	int op;
	NUnaryOp(int op, NExpression& e) :
		e(e), op(op) { TEST_PRINT(); TEST_PRINT_ME(2); }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF(op);
		TEST_PRINT_MEM(e);
	}
};

class NBinaryOp : public NExpression {
public:
	NExpression& lhs;
	NExpression& rhs;
	int op;
	NBinaryOp(NExpression& lhs, int op, NExpression& rhs) :
		lhs(lhs), rhs(rhs), op(op) { TEST_PRINT(); TEST_PRINT_ME(2); }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF("(");
		TEST_PRINT_MEM(lhs);
		TEST_PRINT_LEAF(op);
		TEST_PRINT_MEM(rhs);
		TEST_PRINT_LEAF(")");
	}
};

class NArrayExpr : public NExpression, public AssignmentLHS {
public:
	NIdentifier& id;
	NExpression& e;
	NArrayExpr(NIdentifier& id, NExpression& e) :
		id(id), e(e) { TEST_PRINT(); TEST_PRINT_ME(2); }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_MEM(id);
		TEST_PRINT_LEAF("[");
		TEST_PRINT_MEM(e);
		TEST_PRINT_LEAF("]");
	}
};

class NReturn : public NStatement {
public:
	IdentifierList idl;
	NReturn(IdentifierList& idl) : 
		idl(idl) { TEST_PRINT(); TEST_PRINT_ME(3); }
	CODEGEN_FUNC();
	void print(){
		IdentifierList::reverse_iterator rit;
		TEST_PRINT_LEAF("RETURN");
		for (rit = idl.rbegin(); rit != idl.rend(); rit++) {
			TEST_PRINT_MEM(**rit);
			TEST_PRINT_LEAF(",");
		}
	}
};

class NFuncCall : public NExpression, public NStatement {
public:
	NIdentifier& id;
	ExpressionList args;
	NFuncCall(NIdentifier& id, ExpressionList& args) :
		id(id), args(args) { TEST_PRINT(); TEST_PRINT_ME(3); }
	CODEGEN_FUNC();
	void print(){
		ExpressionList::reverse_iterator rit;
		TEST_PRINT_LEAF("FUNC:");
		TEST_PRINT_MEM(id);
		for (rit = args.rbegin(); rit != args.rend(); rit++) {
			TEST_PRINT_MEM(**rit);
			TEST_PRINT_LEAF(",");
		}
	}
};

class TsDecl {
public:
	int type;
	int size;
	TsDecl( int type, int size ) :
		type(type), size(size) { TEST_PRINT(); TEST_PRINT_ME(3); }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF(type);
		TEST_PRINT_LEAF(":");
		TEST_PRINT_LEAF(size);
	}
};

class NVarDecl : public NDecl, public NStatement, public AssignmentLHS {
public:
	NIdentifier& id;
	TsDeclList& TsDecl;
	NVarDecl(NIdentifier& id, TsDeclList& TsDecl) :
		id(id), TsDecl(TsDecl) { TEST_PRINT(); TEST_PRINT_ME(4); }
	CODEGEN_FUNC();
	void print(){
		TsDeclList::reverse_iterator rit;
		TEST_PRINT_LEAF("VAR_DECL:");
		TEST_PRINT_MEM(id);
		TEST_PRINT_LEAF("=");
		for (rit = TsDecl.rbegin(); rit != TsDecl.rend(); rit++) {
			TEST_PRINT_MEM(**rit);
			TEST_PRINT_LEAF(",");
		}
	}
};

class NAssignment : public NStatement {
public:
	int type;
	AssignmentLHS& lhs;
	ExpressionList& rhs;
	NAssignment(AssignmentLHS& lhs, ExpressionList& rhs) : 
		lhs(lhs), rhs(rhs) { TEST_PRINT(); TEST_PRINT_ME(4); }
	CODEGEN_FUNC();
	void print(){
		ExpressionList::reverse_iterator rit;
		TEST_PRINT_LEAF("Assign:");
		TEST_PRINT_MEM(lhs);
		TEST_PRINT_LEAF("EQ");
		for (rit = rhs.rbegin(); rit != rhs.rend(); rit++) {
			TEST_PRINT_MEM(**rit);
			TEST_PRINT_LEAF(",");
		}
	}
};

class NBreak : public NStatement {
public:
	NBreak() { TEST_PRINT(); TEST_PRINT_ME(3); }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF("Break");
	}
};

class NContinue : public NStatement {
public:
	NContinue() { TEST_PRINT(); TEST_PRINT_ME(3); }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF("Continue");
	}
};

class NBlock : public Node {
public:
	StatementList statements;
	NBlock(StatementList& statements) :
		statements(statements) { TEST_PRINT(); TEST_PRINT_ME(5); }
	NBlock(NStatement& statement) : NBlock(*(new StatementList(1, &statement))) {} 
	NBlock() : NBlock(*(new StatementList())) {}
	CODEGEN_FUNC();
	void print(){
		StatementList::reverse_iterator rit;
		TEST_PRINT_LEAF("Block: Begin");TEST_PRINT_LEAF(std::endl);
		for (rit = statements.rbegin(); rit != statements.rend(); rit++) {
			TEST_PRINT_MEM(**rit);
			TEST_PRINT_LEAF(std::endl);
		}
		TEST_PRINT_LEAF("Block: End");TEST_PRINT_LEAF(std::endl);
	}
};

class NCaseDefault : public Node {
public:
	NBlock& block;
	NCaseDefault(NBlock& block) :
		block(block) { TEST_PRINT(); TEST_PRINT_ME(6); }
	NCaseDefault() : NCaseDefault(*(new NBlock())) {  }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF("Default:");
		TEST_PRINT_MEM(block);
		TEST_PRINT_LEAF(std::endl);
	}
};

class NCase : public Node {
public:
	NConst& condition;
	NBlock& block;
	NCase(NConst& condition, NBlock& block) :
		condition(condition), block(block) { TEST_PRINT(); TEST_PRINT_ME(6); }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF("Case:");
		TEST_PRINT_MEM(condition);
		TEST_PRINT_LEAF(std::endl);
		TEST_PRINT_MEM(block);
		TEST_PRINT_LEAF(std::endl);
	}
};

class NSwitch : public NConditional {
public:
	NExpression& expression;
	CaseList cases;
	NCaseDefault& default_case;
	NSwitch(NExpression& expression, CaseList cases, NCaseDefault& default_case) :
		expression(expression), cases(cases), default_case(default_case) { TEST_PRINT(); TEST_PRINT_ME(7); }
	CODEGEN_FUNC();
	void print(){
		CaseList::reverse_iterator rit;
		TEST_PRINT_LEAF("Switch:");
		TEST_PRINT_MEM(expression);
		TEST_PRINT_LEAF(std::endl);
		for (rit = cases.rbegin(); rit != cases.rend(); rit++) {
			TEST_PRINT_MEM(**rit);
		}
		TEST_PRINT_LEAF("Default:");
		TEST_PRINT_MEM(default_case);
		TEST_PRINT_LEAF(std::endl);
	}
};

class NIf : public NConditional {
public:
	NExpression& expression;
	NBlock& if_block;
	NBlock& else_block;
	NIf(NExpression& expression, NBlock& if_block, NBlock& else_block) :
		expression(expression), if_block(if_block), else_block(else_block) { TEST_PRINT(); TEST_PRINT_ME(7); }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF("If ");
		TEST_PRINT_MEM(expression);
		TEST_PRINT_LEAF("Then:");
		TEST_PRINT_LEAF(std::endl);
		TEST_PRINT_MEM(if_block);
		TEST_PRINT_LEAF(std::endl);
		TEST_PRINT_LEAF("Else ");
		TEST_PRINT_MEM(else_block);
		TEST_PRINT_LEAF(std::endl);		
	}
};

class NForRange : public NForIterator {
public:
	NForRangeOperand& from;
	NForRangeOperand& to;
	NForRange(NForRangeOperand& from, NForRangeOperand& to) :
		from(from), to(to) { TEST_PRINT(); TEST_PRINT_ME(6); }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF("Range: from ");
		TEST_PRINT_MEM(from);
		TEST_PRINT_LEAF("to ");
		TEST_PRINT_MEM(to);
	}
private:
	int start() {}
	int step() {}
	int end() {}
};

class NForEach : public NForIterator {
public:
	NIdentifier& id;
	NForEach(NIdentifier& id) :
		id(id) { TEST_PRINT(); TEST_PRINT_ME(6); }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF("Each: ");
		TEST_PRINT_MEM(id);
	}
private:
	int start() {}
	int step() {}
	int end() {}
};

class NFor : public NStatement {
public:
	NIdentifier& id;
	NForIterator& iter;
	NBlock& blk;
	NFor(NIdentifier& id, NForIterator& iter, NBlock& blk) :
		id(id), iter(iter), blk(blk) { TEST_PRINT(); TEST_PRINT_ME(7); }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF("For ");
		TEST_PRINT_MEM(id);
		TEST_PRINT_LEAF(" in ");
		TEST_PRINT_MEM(iter);
		TEST_PRINT_MEM(blk);
		TEST_PRINT_LEAF(std::endl);
	}
};

class NWhile : public NStatement {
public:
	NExpression& expr;
	NBlock& blk;
	NWhile(NExpression& expr, NBlock& blk) :
		expr(expr), blk(blk) { TEST_PRINT(); TEST_PRINT_ME(7); }
	CODEGEN_FUNC();
	void print(){
		TEST_PRINT_LEAF("While ");
		TEST_PRINT_MEM(expr);
		TEST_PRINT_LEAF(" do");
		TEST_PRINT_LEAF(std::endl);
		TEST_PRINT_MEM(blk);
		TEST_PRINT_LEAF(std::endl);
	}
};


class NFunctionDecl : public NDecl {
public:
	TsDeclList& returns;
	NIdentifier& id;
	VariableList& arguments;
	NBlock& block;
	NFunctionDecl(TsDeclList& returns, NIdentifier& id, VariableList& arguments, NBlock& block) :
		returns(returns), id(id), arguments(arguments), block(block) { TEST_PRINT(); TEST_PRINT_ME(8); }
	CODEGEN_FUNC();
	void print(){
		VariableList::reverse_iterator rit;
		TsDeclList::reverse_iterator rit2;
		TEST_PRINT_LEAF("Function:");TEST_PRINT_MEM(id);TEST_PRINT_LEAF(std::endl);
		TEST_PRINT_LEAF("gets:");
		for (rit = arguments.rbegin(); rit != arguments.rend(); rit++) {
			TEST_PRINT_MEM(**rit);
			TEST_PRINT_LEAF(",");
		} TEST_PRINT_LEAF(std::endl);
		TEST_PRINT_MEM(block);TEST_PRINT_LEAF(std::endl);
		TEST_PRINT_LEAF("returns:");
		for (rit2 = returns.rbegin(); rit2 != returns.rend(); rit2++) {
			TEST_PRINT_MEM(**rit2);
			TEST_PRINT_LEAF(",");
		} TEST_PRINT_LEAF(std::endl);
	}
};

class NProgram : public Node {
public:
	DeclarationList& declarations;
	NIdentifier& start;
	NIdentifier* finish;
	NProgram(DeclarationList& declarations, NIdentifier& start, NIdentifier* finish) :
		declarations(declarations), start(start), finish(finish) { TEST_PRINT(); TEST_PRINT_ME(9); }
	CODEGEN_FUNC();
	void print(){
		DeclarationList::reverse_iterator rit;
		TEST_PRINT_LEAF("Program: Starts   with: "); TEST_PRINT_MEM(start ); TEST_PRINT_LEAF(std::endl);
		if(finish != NULL){
			TEST_PRINT_LEAF("Program: Finishes with: "); TEST_PRINT_MEM(*finish); TEST_PRINT_LEAF(std::endl);
		}
		TEST_PRINT_LEAF("Program: Begin");TEST_PRINT_LEAF(std::endl);
		for (rit = declarations.rbegin(); rit != declarations.rend(); rit++) {
			TEST_PRINT_MEM(**rit);
			TEST_PRINT_LEAF(std::endl);
		}
		TEST_PRINT_LEAF("Program: End");TEST_PRINT_LEAF(std::endl);
	}
};

