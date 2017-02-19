#include <iostream>
#include <vector>
#include <llvm/IR/Value.h>

class CodeGenContext;
class NStatement;
class NExpression;
class NVarDecl;

typedef std::vector<NIdentifier*> IdentifierList;
typedef std::vector<NBlock*> BlockList;
typedef std::vector<NStatement*> StatementList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NVarDecl*> VariableList;
typedef std::vector<NTsDecl*> TsDeclList;

class Node {
public:
	virtual ~Node() {}
	virtual llvm::Value* codeGen(CodeGenContext& context) { return NULL; }
};

class NExpression : public Node {
public:
	int type;
	NExpression& lhs;
	NExpression& rhs;
	int op;
	NExpression(NExpression& lhs, int op, NExpression& rhs) :
		lhs(lhs), rhs(rhs), op(op) { type = 3;}
	NExpression(int op, NExpression& rhs) :
		rhs(rhs), op(op) { type = 2;}
	NExpression(NExpression& lhs) :
		lhs(lhs) { type = 1;}
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NBlank : public NExpression {
};

class NStatement : public Node {
};

class NBreak : public NStatement {
};

class NContinue : public NStatement {
};

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
};

class NInteger : public NExpression {
public:
	long long value;
	NInteger(long long value) : value(value) { }
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
	NString(std::string& value) : name(name) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NIdentifier : public NExpression {
public:
	std::string name;
	NIdentifier(const std::string& name) : name(name) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NFuncCall : public NExpression {
public:
	const NIdentifier& id;
	ExpressionList arguments;
	NFuncCall(const NIdentifier& id, ExpressionList& arguments) :
		id(id), arguments(arguments) { }
	//NFuncCall(const NIdentifier& id) : id(id) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/*class NBinaryOperator : public NExpression {
public:
	int op;
	NExpression& lhs;
	NExpression& rhs;
	NBinaryOperator(NExpression& lhs, int op, NExpression& rhs) :
		lhs(lhs), rhs(rhs), op(op) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};
*/
class NAssignment : public NExpression {
public:
	int type;
	NIdentifier& id;
	NExpression& lhs;
	NExpression& rhs;
	NVarDecl& vd;
	NAssignment(NIdentifier& id, NExpression& rhs : 
		id(id), rhs(rhs) { type = 1; }
	NAssignment(NVarDecl& vd, NExpression& rhs) : 
		vd(vd), rhs(rhs) { type = 2; }
	NAssignment(NIdentifier& id, NExpression& lhs, NExpression& rhs) : 
		id(id), lhs(lhs), rhs(rhs) { type = 3; }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NBlock : public NExpression {
public:
	StatementList statements;
	NBlock() { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/*class NExpressionStatement : public NStatement {
public:
	NExpression& expression;
	NExpressionStatement(NExpression& expression) : 
		expression(expression) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};*/

class NReturn : public NStatement {
public:
	IdentifierList idl;
	NReturn(IdentifierList& idl) : 
		idl(idl) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NTsDecl : public NStatement {
public:
	int type;
	NInteger& num;
	NTsDecl(int type, NInteger& num) :
		type(type), num(num) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NVarDecl : public NStatement {
public:
	const NIdentifier& id;
	NTsDecl TsDecl;
	//NExpression *assignmentExpr;
	NVarDecl(NIdentifier& id, const NTsDecl& TsDecl) :
		id(id), TsDecl(TsDecl) { /*assignmentExpr = NULL; */ }
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
	ExpressionList el;
	BlockList bl;
	NIf() : { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NCase : public NStatement {
public:
	ExpressionList el;
	BlockList bl;
	NCase() : { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

/*
class NExternDeclaration : public NStatement {
public:
    const NIdentifier& type;
    const NIdentifier& id;
    VariableList arguments;
    NExternDeclaration(const NIdentifier& type, const NIdentifier& id,
            const VariableList& arguments) :
        type(type), id(id), arguments(arguments) {}
    virtual llvm::Value* codeGen(CodeGenContext& context);
};
*/

class NFunctionDecl : public NStatement {
public:
	TsDeclList returns;
	NIdentifier& id;
	VariableList arguments;
	NBlock& block;
	NFunctionDecl(TsDeclList& returns, NIdentifier& id, 
			VariableList& arguments, NBlock& block) :
		returns(returns), id(id), arguments(arguments), block(block) { }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NProgram : public Node {
public:
	NBlock& block;
	NIdentifier& start;
	NIdentifier& finish;
	NProgram() : {  }
	virtual llvm::Value* codeGen(CodeGenContext& context);	
}