#include <iostream>
#include <vector>
#if TEST_MODE > TEST_AST_GEN
#include <llvm/IR/Value.h>
#endif

#if TEST_MODE > TEST_AST
#define CODEGEN_FUNC()	virtual llvm::Value*	codeGen(CodeGenContext& context)
#define TEST_PRINT() 
#define TEST_PRINT_LEAF(token)	
#define TEST_PRINT_MEM(token)
#define TEST_PRINT_ME(level)
#else
#define CODEGEN_FUNC()	/*virtual void*		codeGen(CodeGenContext& context)*/
#define TEST_PRINT()		do{std::cout << __PRETTY_FUNCTION__ << std::endl; }while(0)
#define TEST_PRINT_LEAF(token)	do{std::cout << (token) << " ";}while(0)
#define TEST_PRINT_MEM(token)	do{(token).print();}while(0)
#define TEST_PRINT_ME(level)	do{if( AST_DEBUG_LEVEL <= (level) ) {this->print(); std::cout << std::endl;} }while(0)
#endif

/* What Parser knows */
class Node;
class NExpression;
class NConst;
class NInteger;
class NIdentifier;
class NArrayExpr;
typedef std::vector<NIdentifier*> IdentifierList;
typedef std::vector<NExpression*> ExpressionList;

/* Not used directly by Parser */
class NLong;
class NReal;
class NChar;
class NBool;
class NString;

/* To be used */
class NUnaryOp;
class NBinaryOp;

class Node {
public:
	virtual ~Node() {}
	CODEGEN_FUNC();
	virtual void print() {}
};

class NExpression : public Node {
public:
	virtual void print() {}
};

class NStatement : public Node {
public:
	virtual void print() {}
};

class NConst   : public NExpression {
public:
	virtual void print() {}
};

class NInteger : public NConst {
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
		TEST_PRINT_LEAF(value);
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

class NIdentifier : public NExpression {
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

class NArrayExpr : public NExpression {
public:
	NIdentifier& id;
	NExpression& e;
	NArrayExpr(NIdentifier& id, NExpression& e) :
		id(id), e(e) { TEST_PRINT(); TEST_PRINT_ME(2); }
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


