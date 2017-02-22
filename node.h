#include <iostream>
#include <vector>
#if TEST_MODE > TEST_AST_GEN
#include <llvm/IR/Value.h>
#endif

class CodeGenContext;
class NExpression;
class NVarDecl;
class NTsDecl;
class NIdentifier;
class NBlock;
class NStatement;
class NInteger;

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

/*
std::vector<Student> result
result.emplace_back(id, name, surname, points);
ExprBlockList ebl
ebl.emplace_back(b, e);
*/

typedef std::vector<TsDecl*> TsDeclList;
typedef std::vector<ExprBlock*> ExprBlockList;
typedef std::vector<NIdentifier*> IdentifierList;
typedef std::vector<NStatement*> StatementList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NVarDecl*> VariableList;

class Node {
public:
	virtual ~Node() {}
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context) { return NULL; }
#endif
};

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
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NAssignment" << std::endl;
	}
#endif
};

class NReturn : public NStatement {
public:
	IdentifierList idl;
	NReturn(IdentifierList& idl) : 
		idl(idl) { }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NReturn" << std::endl;
	}
#endif
};

class NWhile : public NStatement {
public:
	NExpression& e;
	NBlock& b;
	NWhile(NExpression& e, NBlock& b) :
		e(e), b(b) { }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NWhile" << std::endl;
	}
#endif
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
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NFor" << std::endl;
	}
#endif
};

class NIf : public NStatement {
public:
	ExprBlockList ebl;
	NIf() { /*ebl = new ExprBlockList();*/ }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NIf" << std::endl;
	}
#endif
};

class NCase : public NStatement {
public:
	ExprBlockList ebl;
	NExpression* Expression;
	NCase() { }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NCase" << std::endl;
	}
#endif
};

//****************************************************************************************************

class NExpression : public NStatement {
};

class NUnaryOp : public NExpression {
public:
	NExpression& e;
	int op;
	NUnaryOp(int op, NExpression& e) :
		e(e), op(op) {  }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NUnaryOp" << std::endl;
	}
#endif
};

class NBineryOp : public NExpression {
public:
	NExpression& lhs;
	NExpression& rhs;
	int op;
	NBineryOp(NExpression& lhs, int op, NExpression& rhs) :
		lhs(lhs), rhs(rhs), op(op) {  }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NBineryOp" << std::endl;
	}
#endif
};

class NArrayExpr : public NExpression {
public:
	NExpression& index;
	NIdentifier& id;
	NArrayExpr(NIdentifier& id, NExpression& index) :
		index(index), id(id) {  }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NArrayExpr" << std::endl;
	}
#endif
};

class NFuncCall : public NExpression/*, public NStatement*/ {
public:
	NIdentifier& id;
	ExpressionList arguments;
	NFuncCall(NIdentifier& id, ExpressionList& arguments) :
		id(id), arguments(arguments) { }
	//NFuncCall(const NIdentifier& id) : id(id) { }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NFuncCall" << std::endl;
	}
#endif
};

class NBlank : public NExpression {
};

class NInteger : public NExpression {
public:
	long value;
	NInteger(int value) : value(value) { }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NInteger" << std::endl;
	}
#endif
};

class NLong : public NExpression {
public:
	long value;
	NLong(long value) : value(value) { }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NLong" << std::endl;
	}
#endif
};

class NReal : public NExpression {
public:
	double value;
	NReal(double value) : value(value) { }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NReal" << std::endl;
	}
#endif
};

class NChar : public NExpression {
public:
	char value;
	NChar(char value) : value(value) { }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NChar" << std::endl;
	}
#endif
};

class NBool : public NExpression {
public:
	bool value;
	NBool(bool value) : value(value) { }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NBool" << std::endl;
	}
#endif
};

class NString : public NExpression {
public:
	std::string value;
	NString(std::string& value) : value(value) { }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NString" << std::endl;
	}
#endif
};

class NIdentifier : public NExpression {
public:
	std::string name;
	NIdentifier(std::string& name) : name(name) { }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NIdentifier" << std::endl;
	}
#endif
};

//****************************************************************************************************



class NBlock : public Node {
public:
	StatementList statements;
	NBlock() { }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NBlock" << std::endl;
	}
#endif
};


/*class NProgram : public Node {
public:
	NBlock& block;
	NIdentifier& start;
	NIdentifier& finish;
	NProgram(NIdentifier& start, NIdentifier& finish) : {  }
	virtual llvm::Value* codeGen(CodeGenContext& context);	
}

class NDecl : public Node {
};*/

class NVarDecl : public NStatement {
public:
	NIdentifier& id;
	TsDeclList& TsDecl;
	//NExpression *assignmentExpr;
	NVarDecl(NIdentifier& id, TsDeclList& TsDecl) :
		id(id), TsDecl(TsDecl) { /*assignmentExpr = NULL; */ }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NVarDecl" << std::endl;
	}
#endif
};

class NFunctionDecl : public NStatement {
public:
	TsDeclList returns;
	NIdentifier& id;
	VariableList arguments;
	NBlock& block;
	NFunctionDecl(TsDeclList& returns, NIdentifier& id, VariableList& arguments, NBlock& block) :
		returns(returns), id(id), arguments(arguments), block(block) { }
#if TEST_MODE > TEST_AST_GEN
	virtual llvm::Value* codeGen(CodeGenContext& context);
#else
	void codeGen(){
		std::cout << "NFunctionDecl" << std::endl;
	}
#endif
};




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
