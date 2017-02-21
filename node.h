#include <iostream>
#include <vector>
#include <llvm/IR/Value.h>

class CodeGenContext;
class NExpression;
class NVarDecl;
class NTsDecl;
class NIdentifier;
class NBlock;
class NStatement;
class NInteger;

struct TsDecl
{
	int type;
	NInteger& num;
	TsDecl( int type, NInteger& num ) :
		type(type), num(num) { }
};

struct ExprBlock
{
	NBlock& b;
	NExpression& e;

    ExprBlock(NBlock& b, NExpression& e)
    : b(b), e(e) {}
};

/*
std::vector<Student> result
result.emplace_back(id, name, surname, points);
ExprBlockList ebl
ebl.emplace_back(b, e);
*/

//typedef std::vector<NDecl*> NDeclList;
typedef std::vector<TsDecl*> TsDeclList;
typedef std::vector<ExprBlock*> ExprBlockList;
typedef std::vector<NIdentifier*> IdentifierList;
typedef std::vector<NStatement*> StatementList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NVarDecl*> VariableList;

class Node {
public:
	virtual ~Node() {}
	virtual llvm::Value* codeGen(CodeGenContext& context) { return NULL; }
};

//****************************************************************************************************

class NStatement : public Node {
};

class NBreak : public NStatement {
};

class NContinue : public NStatement {
};

//****************************************************************************************************
/*
class NAssignment1 : public NStatement {
public:
	NIdentifier& id;
	ExpressionList& rhs;
	NAssignment(NIdentifier& id, ExpressionList& rhs) : 
		id(id), rhs(rhs) {  }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NAssignment2 : public NStatement {
public:
	int type;
	NIdentifier& id;
	NExpression& lhs;
	NExpression& rhs;
	NVarDecl& vd;
	NAssignment(NIdentifier& id, NExpression& rhs) : 
		id(id), rhs(rhs) { type = 1; }
	NAssignment(NVarDecl& vd, NExpression& rhs) : 
		vd(vd), rhs(rhs) { type = 2; }
	NAssignment(NIdentifier& id, NExpression& lhs, NExpression& rhs) : 
		id(id), lhs(lhs), rhs(rhs) { type = 3; }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};
*/
class NAssignment : public NStatement {
public:
	int type;
	NIdentifier* id;
	NExpression* lhs;
	NExpression& rhs;
	NVarDecl* vd;
	NAssignment(NIdentifier* id, NExpression& rhs) : 
		id(id), rhs(rhs) { lhs = NULL; vd = NULL; type = 1; }
	NAssignment(NVarDecl* vd, NExpression& rhs) : 
		vd(vd), rhs(rhs) { lhs = NULL; id = NULL; type = 2; }
	NAssignment(NIdentifier* id, NExpression* lhs, NExpression& rhs) : 
		id(id), lhs(lhs), rhs(rhs) { vd = NULL; type = 3; }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NReturn : public NStatement {
public:
	IdentifierList idl;
	NReturn(IdentifierList& idl) : 
		idl(idl) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NWhile : public NStatement {
public:
	NExpression& e;
	NBlock& b;
	NWhile(NExpression& e, NBlock& b) :
		e(e), b(b) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NFor : public NStatement {
public:
	NIdentifier& id;
	NExpression& e;
	NBlock& b;
	NFor(NIdentifier& id, NExpression& e, NBlock& b) :
		id(id), e(e), b(b) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NIf : public NStatement {
public:
	ExprBlockList ebl;
	NIf() { /*ebl = new ExprBlockList();*/ }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NCase : public NStatement {
public:
	ExprBlockList ebl;
	NExpression* Expression;
	NCase() { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
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
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NBineryOp : public NExpression {
public:
	NExpression& lhs;
	NExpression& rhs;
	int op;
	NBineryOp(NExpression& lhs, int op, NExpression& rhs) :
		lhs(lhs), rhs(rhs), op(op) {  }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NArrayExpr : public NExpression {
public:
	NExpression& index;
	NIdentifier& id;
	NArrayExpr(NIdentifier& id, NExpression& index) :
		index(index), id(id) {  }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NFuncCall : public NExpression/*, public NStatement*/ {
public:
	NIdentifier& id;
	ExpressionList arguments;
	NFuncCall(NIdentifier& id, ExpressionList& arguments) :
		id(id), arguments(arguments) { }
	//NFuncCall(const NIdentifier& id) : id(id) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NBlank : public NExpression {
};

class NInteger : public NExpression {
public:
	long value;
	NInteger(int value) : value(value) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NLong : public NExpression {
public:
	long value;
	NLong(long value) : value(value) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NReal : public NExpression {
public:
	double value;
	NReal(double value) : value(value) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NChar : public NExpression {
public:
	char value;
	NChar(char value) : value(value) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NBool : public NExpression {
public:
	bool value;
	NBool(bool value) : value(value) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NString : public NExpression {
public:
	std::string value;
	NString(std::string& value) : value(value) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NIdentifier : public NExpression {
public:
	std::string name;
	NIdentifier(std::string& name) : name(name) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

//****************************************************************************************************



class NBlock : public Node {
public:
	StatementList statements;
	NBlock() { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
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
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NFunctionDecl : public NStatement {
public:
	TsDeclList returns;
	NIdentifier& id;
	VariableList arguments;
	NBlock& block;
	NFunctionDecl(TsDeclList& returns, NIdentifier& id, VariableList& arguments, NBlock& block) :
		returns(returns), id(id), arguments(arguments), block(block) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
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
