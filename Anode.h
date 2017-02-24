#include <iostream>
#include <vector>
#if TEST_MODE > TEST_AST_GEN
#include <llvm/IR/Value.h>
#endif

#if 0
class CodeGenContext;
class NExpression;
class NVarDecl;
class NTsDecl;
class NIdentifier;
class NBlock;
class NStatement;
class NInteger;
#endif

#if TEST_MODE > TEST_AST
#define CODEGEN_FUNC()	virtual llvm::Value*	codeGen(CodeGenContext& context)
#define TEST_PRINT() 
#else
#define CODEGEN_FUNC()	/*virtual void*		codeGen(CodeGenContext& context)*/
#define TEST_PRINT() do{std::cout << __PRETTY_FUNCTION__ << std::endl;}while(0)
#endif

/* What Parser knows */
class Node;
class NExpression;
class NConst;
class NInteger;
class NIdentifier;

/* Not used directly by Parser */
class NLong;
class NReal;
class NChar;
class NBool;
class NString;

/* To be used */
class NUnaryOp;
class NBinaryOp;

#if 0

class TsDecl {
public:
	int type;
	int size;
	TsDecl( int type, int size ) :
		type(type), size(size) { }
};

class ExprBlock {
public:
	NBlock* b;
	NExpression* e;

	ExprBlock(NExpression* e, NBlock* b) :
		b(b), e(e) {}
};
#endif
/*
std::vector<Student> result
result.emplace_back(id, name, surname, points);
ExprBlockList ebl
ebl.emplace_back(b, e);
*/


#if 0
typedef std::vector<TsDecl*> TsDeclList;
typedef std::vector<ExprBlock*> ExprBlockList;
typedef std::vector<NIdentifier*> IdentifierList;
typedef std::vector<NStatement*> StatementList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NVarDecl*> VariableList;
#endif
class Node {
public:
	virtual ~Node() {}
	CODEGEN_FUNC();
};
#if 0
//****************************************************************************************************

class NStatement : public Node {
};

class NBreak : public NStatement {
};

class NContinue : public NStatement {
};

//****************************************************************************************************

class NAssignment : public NStatement {
public:
	int type;
	NIdentifier *id;
	ExpressionList *lhs;
	ExpressionList rhs;
	NVarDecl *vd;
	NAssignment(NIdentifier *id, ExpressionList& rhs) : 
		id(id), rhs(rhs) { lhs = NULL; vd = NULL; type = 1; }
	NAssignment(NVarDecl *vd, ExpressionList& rhs) : 
		vd(vd), rhs(rhs) { lhs = NULL; id = NULL; type = 2; }
	NAssignment(NIdentifier *id, ExpressionList *lhs, ExpressionList& rhs) : 
		id(id), lhs(lhs), rhs(rhs) { vd = NULL; type = 3; }
	CODEGEN_FUNC();
};

class NReturn : public NStatement {
public:
	IdentifierList idl;
	NReturn(IdentifierList& idl) : 
		idl(idl) { }
	CODEGEN_FUNC();
};

class NWhile : public NStatement {
public:
	NExpression& e;
	NBlock& b;
	NWhile(NExpression& e, NBlock& b) :
		e(e), b(b) { }
	CODEGEN_FUNC();
};

class NFor : public NStatement {
public:
	int type;
	NIdentifier* id;
	NExpression* range;
	NExpression* to;
	NBlock* block;
	NFor(NExpression *range, NExpression *to, int type) :
		range(range), to(to), type(type) { block = NULL; id = NULL; }
	CODEGEN_FUNC();
};

class NIf : public NStatement {
public:
	ExprBlockList ebl;
	NIf() { /*ebl = new ExprBlockList();*/ }
	CODEGEN_FUNC();
};

class NCase : public NStatement {
public:
	ExprBlockList ebl;
	NExpression* Expression;
	NCase() { }
	CODEGEN_FUNC();
};

//****************************************************************************************************
#endif
class NExpression : public Node {
};

class NUnaryOp : public NExpression {
public:
	NExpression& e;
	int op;
	NUnaryOp(int op, NExpression& e) :
		e(e), op(op) { TEST_PRINT(); }
	CODEGEN_FUNC();
};

class NBinaryOp : public NExpression {
public:
	NExpression& lhs;
	NExpression& rhs;
	int op;
	NBinaryOp(NExpression& lhs, int op, NExpression& rhs) :
		lhs(lhs), rhs(rhs), op(op) { TEST_PRINT(); }
	CODEGEN_FUNC();
};
#if 0
class NArrayExpr : public NExpression {
public:
	NExpression& index;
	NIdentifier& id;
	NArrayExpr(NIdentifier& id, NExpression& index) :
		index(index), id(id) {  }
	CODEGEN_FUNC();
};

class NFuncCall : public NExpression/*, public NStatement*/ {
public:
	NIdentifier& id;
	ExpressionList arguments;
	NFuncCall(NIdentifier& id, ExpressionList& arguments) :
		id(id), arguments(arguments) { }
	//NFuncCall(const NIdentifier& id) : id(id) { }
	CODEGEN_FUNC();
};

class NBlank : public NExpression {
};
#endif

class NConst   : public NExpression {
};

class NInteger : public NConst {
public:
	long value;
	NInteger(int value) : value(value) { TEST_PRINT(); }
	CODEGEN_FUNC();
};

class NLong : public NConst {
public:
	long value;
	NLong(long value) : value(value) { TEST_PRINT(); }
	CODEGEN_FUNC();
};

class NReal : public NConst {
public:
	double value;
	NReal(double value) : value(value) { TEST_PRINT(); }
	CODEGEN_FUNC();
};

class NChar : public NConst {
public:
	char value;
	NChar(char value) : value(value) { TEST_PRINT(); }
	CODEGEN_FUNC();
};

class NBool : public NConst {
public:
	bool value;
	NBool(bool value) : value(value) { TEST_PRINT(); }
	CODEGEN_FUNC();
};

class NString : public NConst {
public:
	std::string value;
	NString(std::string& value) : value(value) { TEST_PRINT(); }
	CODEGEN_FUNC();
};

class NIdentifier : public NExpression {
public:
	std::string name;
	NIdentifier(std::string& name) : name(name) { TEST_PRINT();
#if TEST_MODE == TEST_AST
	std::cout << name << std::endl;
#endif
	}

	CODEGEN_FUNC();
};

//****************************************************************************************************


#if 0
class NBlock : public Node {
public:
	StatementList statements;
	NBlock() { }
	CODEGEN_FUNC();
};


class NProgram : public Node {
public:
	NBlock& block;
	NIdentifier& start;
	NIdentifier& finish;
	NProgram(NIdentifier& start, NIdentifier& finish) : {  }
	CODEGEN_FUNC();
}

class NDecl : public Node {
	CODEGEN_FUNC();
};

class NVarDecl : public NDecl, public NStatement {
public:
	NIdentifier& id;
	TsDeclList& TsDecl;
	//NExpression *assignmentExpr;
	NVarDecl(NIdentifier& id, TsDeclList& TsDecl) :
		id(id), TsDecl(TsDecl) { /*assignmentExpr = NULL; */ }
	CODEGEN_FUNC();
};

class NFunctionDecl : public NDecl {
public:
	TsDeclList returns;
	NIdentifier& id;
	VariableList arguments;
	NBlock& block;
	NFunctionDecl(TsDeclList& returns, NIdentifier& id, VariableList& arguments, NBlock& block) :
		returns(returns), id(id), arguments(arguments), block(block) { }
	CODEGEN_FUNC();
};

#endif


/*
class NRead : public NFuncCall {
public:
	NIdentifier& id;
	NRead(NIdentifier& id) : id(id) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NWrite : public NFuncCall {
public:
	NExpression& e;
	NWrite(NExpression& e) : e(e) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NStrlen : public NFuncCall {
public:
	NExpression& str;
	NConcat(NExpression& str) : 
		str(str) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NConcat : public NFuncCall {
public:
	NExpression& str1;
	NExpression& str2;
	NConcat(NExpression& str1, NExpression& str2) : 
		str1(str1), str2(str2) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NSizeOf : public NFuncCall {
public:
	int type;
	int model;
	NIdentifier& id;
	NSizeOf() : { model = 1; }
	NSizeOf(int type) :
		type(type) { model = 2; }
	NSizeOf(NIdentifier& id) :
		id(id) { model = 3; }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};*/
