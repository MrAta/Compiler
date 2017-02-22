%{

#include "debug_mode.h"

//#if TEST_MODE > TEST_PARSER
#include "node.h"

//#define  PARSE(token) return token

//#else

#define  PARSE(token) printf("%s\n", #token)

//#endif

#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#define YYDEBUG 1

//#if TEST_MODE > TEST_PARSER
NBlock *programBlock; /* the top level root node of our final AST */
NIdentifier* start = NULL;
NIdentifier* finish = NULL;
//#endif

 /*NProgram *program; /* the top level root node of our final AST */

extern int yylex();
extern FILE *yyin;
void yyerror(const char *s) { printf("ERROR: %s\n", s); }

%}
/*
%union{ 
//#if TEST_MODE > TEST_PARSER
//Node *node;
//NBlock *block;
//NIdentifier *ident;

//#endif
int test;
int token;
std::string *str;
/*bool bval;
long lval;
}
*/



%union {
#if TEST_MODE > TEST_PARSER
	Node *node;
	NBlock *block;
	NExpression *expr;
	NStatement *stmt;
	NVarDecl* var;
	NIdentifier *ident;
	NInteger *intt;
	NIf *iff;
	NFor *forr;
	NCase *casee;
	NWhile *whilee;
	std::vector<TsDecl*> *tsdeclvec;
	//std::vector<ExprBlock*> ExprBlockList;
	std::vector<NIdentifier*> *identvec;
//	std::vector<NStatement*> stmtvec;
	std::vector<NExpression*> *exprvec;
	std::vector<NVarDecl*> *varvec;
#else
	int   test;
#define	node  test
#define	expr  test
#define	stmt  test
#define	ident test
#define	tsdeclvec test
#define	ExprBlockList test
#define	identvec test
#define	stmtvec test
#define	exprvec test
#define	varvec test
#define	intt test
#define	forr test
#define	casee test
#define	whilee test
#define	iff test

#endif
	std::string *str;
	int token;
}

%token <token> INDENT UNINDENT LBRACK RBRACK
%token <token> START FINISH
%token <token> WHILE FOR IN RANGE TO 
%token <token> BREAK CONTINUE
%token <token> IF ELSE ELIF CASE DEFAULT
%token <token> RETURN
%token <token> COLON 
%token <token> NOT COMMA EQ OROR ANDAND OR XOR AND EQEQ NOTEQ LT LTEQ GT GTEQ PLUS MINUS MULT DIV MOD SIZEOF NEG COMP LPAREN RPAREN
%token <token> BOOL INT LONG CHAR REAL STRING
//TODO change types to str
%token <str> ID
%token <str> CONST_INT CONST_REAL 
%token <str> CONST_CHAR CONST_STRING
%token <str> CONST_LONG
%token <str> TRUE FALSE 
//End-of-TODO
/*
%token <token> READ WRITE
%token <token> START FINISH
*/

%type <block> program
%type <ident> start finish
%type <var> var_dcl
%type <tsdeclvec> ts_dcl 
%type <tsdeclvec> ts_dcl1
%type <stmt> func_dcl 
%type <varvec> func_dcl1
%type <block> block //block_0
%type <stmt> return_stmt
%type <stmt> cond_stmt
%type <iff> cond_stmt1
%type <casee> cond_stmt2
%type <stmt> loop_stmt 
%type <forr> loop_stmt1
%type <expr> expr loop_stmt2
%type <identvec> id1
%type <exprvec> expr1
%type <stmt> statement
%type <stmt> assignment
%type <expr> func_call func_param1
%type <exprvec> func_param func_param2
%type <token> bin_op
%type <token> arithmetic
%type <token> conditional
%type <expr> const_val 
%type <intt> const_int
%type <token> type
%type <ident> id
/*
%type type
%type const_int
*/

%left COMMA
%right EQ
%left OROR
%left ANDAND
%left OR
%left XOR
%left AND
%left EQEQ NOTEQ
%left LT LTEQ GT GTEQ
%left PLUS MINUS
%left MULT DIV MOD
%right SIZEOF NEG COMP NOT
%left LPAREN RPAREN

%start program

%%

program : 							{
#if TEST_MODE > TEST_PARSER
$$ = new NBlock(); programBlock = $$;
#endif
}
	| var_dcl program					{
#if TEST_MODE > TEST_PARSER
if( $1 != NULL) $2->statements.push_back($1); $$ = $2;
#endif
}
	| func_dcl program					{
#if TEST_MODE > TEST_PARSER
if( $1 != NULL) $2->statements.push_back($1); $$ = $2;
#endif
}

	| start program						{
#if TEST_MODE > TEST_PARSER
if( start == NULL ) start = $1; 
else yyerror("multiple definition of start");
$$ = NULL;
#endif
}
	| finish program					{
#if TEST_MODE > TEST_PARSER
if( finish == NULL ) finish = $1;
else yyerror("multiple definition of finish");
$$ = NULL;
#endif
}

;

start : 
	  START id						{
#if TEST_MODE > TEST_PARSER
$$ = $2;
#endif
}
;
finish : 
	  FINISH id						{
#if TEST_MODE > TEST_PARSER
$$ = $2;
#endif
}
;

var_dcl : 
	  id ts_dcl						{
#if TEST_MODE > TEST_PARSER
$$ = new NVarDecl(*$1, *$2);
#endif
}
;

ts_dcl : 
	LBRACK type ts_dcl1 RBRACK				{ 
#if TEST_MODE > TEST_PARSER
//$3->emplace_back(new TsDecl($2, new NInteger(1))); 
//$$ = $3;
$3->push_back(new TsDecl($2, 1)); $$ = $3; 
#endif
}
	| LBRACK type LT const_int GT ts_dcl1 RBRACK		{ 
#if TEST_MODE > TEST_PARSER
//$6->emplace_back($2, *$4); $$ = $6;
$6->push_back(new TsDecl($2, $4->value)); $$ = $6; 
#endif
}
;
ts_dcl1 : 							{ 
#if TEST_MODE > TEST_PARSER
$$ = new TsDeclList(); 
#endif
}
	| COMMA type LT const_int GT ts_dcl1			{
#if TEST_MODE > TEST_PARSER
//$6->emplace_back($2, *$4); $$ = $6;
$6->push_back(new TsDecl($2, $4->value)); $$ = $6; 
#endif
}
	| COMMA type ts_dcl1					{
#if TEST_MODE > TEST_PARSER
//$3->emplace_back($2, new NInteger(1)); $$ = $3;
$3->push_back(new TsDecl($2, 1)); $$ = $3; 
#endif
}
;

func_dcl : 
	  id COLON INDENT block UNINDENT				{
#if TEST_MODE > TEST_PARSER
$$ = new NFunctionDecl(*(new TsDeclList()), *$1, *(new VariableList()), *$4);
#endif
}
	| ts_dcl id var_dcl func_dcl1 COLON INDENT block UNINDENT 	{
#if TEST_MODE > TEST_PARSER
$4->push_back($3); $$ = new NFunctionDecl(*$1, *$2, *$4, *$7);
#endif
}
	| ts_dcl id COLON INDENT block UNINDENT				{
#if TEST_MODE > TEST_PARSER
$$ = new NFunctionDecl(*$1, *$2, *(new VariableList()), *$5);
#endif
}
	| id var_dcl func_dcl1 COLON INDENT block UNINDENT		{
#if TEST_MODE > TEST_PARSER
$3->push_back($2); $$ = new NFunctionDecl(*(new TsDeclList()), *$1, *$3, *$6);
#endif
}
;

func_dcl1 : 							{
#if TEST_MODE > TEST_PARSER
$$ = new VariableList();
#endif
}
	| COMMA var_dcl func_dcl1				{
#if TEST_MODE > TEST_PARSER
$$ = $3; $$->push_back($2);
#endif
}
;

block : 							{
#if TEST_MODE > TEST_PARSER
$$ = new NBlock();
#endif
}
	| var_dcl block						{
#if TEST_MODE > TEST_PARSER
$2->statements.push_back($1); $$ = $2;
#endif
}
	| statement block					{
#if TEST_MODE > TEST_PARSER
$2->statements.push_back($1); $$ = $2;
#endif
}
;

statement : 
	  assignment
	| func_call						{ $<stmt>$ = $1; }
	| cond_stmt
	| loop_stmt
	| return_stmt
	| BREAK							{
#if TEST_MODE > TEST_PARSER
$$ = new NBreak();
#endif
}
	| CONTINUE						{
#if TEST_MODE > TEST_PARSER
$$ = new NContinue();
#endif
}
;

assignment : 
	  id EQ expr expr1					{
#if TEST_MODE > TEST_PARSER
$4->push_back($3); $$ = new NAssignment($1, *$4);
#endif
}
	| id LBRACK expr expr1 RBRACK EQ expr expr1		{
#if TEST_MODE > TEST_PARSER
$4->push_back($3); $8->push_back($7); $$ = new NAssignment($1, $4, *$8);
#endif
}
	| var_dcl EQ expr expr1					{
#if TEST_MODE > TEST_PARSER
$4->push_back($3); $$ = new NAssignment($1, *$4);
#endif
}
;
expr1 : 							{
#if TEST_MODE > TEST_PARSER
$$ = new ExpressionList();
#endif
}
	| COMMA expr expr1					{
#if TEST_MODE > TEST_PARSER
$3->push_back($2); $$ = $3;
#endif
}
;

func_call : 
	  id func_param						{
#if TEST_MODE > TEST_PARSER
$$ = new NFuncCall(*$1, *$2);
#endif
}
/*
	| SIZEOF LPAREN sizeof1 RPAREN				{ $$ = $3; }
	| STRLEN LPAREN id RPAREN				{ $$ = new NStrlen(*$3); }
	| CONCAT LPAREN id COMMA id RPAREN			{ $$ = new NConcat(*$3, *$5); }
	| READ LPAREN id RPAREN					{ $$ = new NRead(*$3); }
	| WRITE LPAREN expr RPAREN				{ $$ = new NWrite(*$3); }
;

sizeof1 : 							{ $$ = new NSizeOf(); }
	| type							{ $$ = new NSizeOf($1); }
	| id							{ $$ = new NSizeOf(*$1); }
*/
;

func_param : 
	   LPAREN func_param1 func_param2 RPAREN		{
#if TEST_MODE > TEST_PARSER
$3->push_back($2); $$ = $3;
#endif
}
;
func_param1 :							{
#if TEST_MODE > TEST_PARSER
$$ = new NBlank();
#endif
}
	| expr	
	/*| id	*/
	/*| const_val	*/
;
func_param2 :							{
#if TEST_MODE > TEST_PARSER
$$ = new ExpressionList();
#endif
}
	| COMMA func_param1 func_param2				{
#if TEST_MODE > TEST_PARSER
$3->push_back($2); $$ = $3;
#endif
}
;

cond_stmt : 
	  IF expr COLON INDENT block UNINDENT cond_stmt1	{
#if TEST_MODE > TEST_PARSER
//$7->ebl.emplace_back($2, $5); $$ = $7;
$7->ebl.push_back(new ExprBlock($2, $5)); $$ = $7;
#endif
}
	| IF expr COLON INDENT block UNINDENT cond_stmt1 ELSE COLON INDENT block UNINDENT
								{
#if TEST_MODE > TEST_PARSER
//$7->ebl.emplace_back($2, $5);
//$7->ebl.emplace_back(new NBool(true), $11); $$ = $7;
$7->ebl.push_back(new ExprBlock($2, $5)); $7->ebl.push_back(new ExprBlock(new NBool(true), $11)); $$ = $7;
//$7->bl.push_back($5); $7->bl.push_back($11); $7->el.push_back($2); $$ = $7;
#endif
}
	| CASE expr COLON INDENT cond_stmt2 UNINDENT		{
#if TEST_MODE > TEST_PARSER
$5->Expression = $2; $$ = $5;
#endif
}
	| CASE expr COLON INDENT cond_stmt2 DEFAULT COLON INDENT block	UNINDENT UNINDENT
								{
#if TEST_MODE > TEST_PARSER
$5->ebl.push_back(new ExprBlock(new NBool(true), $9)); $5->Expression = $2; $$ = $5;
//$5->ebl.emplace_back(new NBool(true), $9); $5->Expression = $2; $$ = $5;
#endif
}
;
cond_stmt1 : 							{
#if TEST_MODE > TEST_PARSER
$$ = new NIf();
#endif
}	//NIf() has two list: Block and Expression List. if we have 'else' then bl.length -1 = el.length . if we do not have 'else' then bl.length = el.length .
	| ELIF expr COLON INDENT block UNINDENT cond_stmt1	{
#if TEST_MODE > TEST_PARSER
//$7->ebl.emplace_back($2, $5); $$ = $7;
$7->ebl.push_back(new ExprBlock($2, $5)); $$ = $7;
//$7->bl.push_back($5); $7->el.push_back($2); $$ = $7;
#endif
}
;

cond_stmt2 : 							{
#if TEST_MODE > TEST_PARSER
$$ = new NCase();
#endif
}
	| const_val COLON INDENT block UNINDENT cond_stmt2	{
#if TEST_MODE > TEST_PARSER
$6->ebl.push_back(new ExprBlock($1, $4)); $$ = $6;
//$6->ebl.emplace_back($1, $4); $$ = $6;
#endif
}
;

loop_stmt :
//	  FOR id IN COLON block
	  FOR id IN loop_stmt1 COLON INDENT block UNINDENT	{
#if TEST_MODE > TEST_PARSER
$4->id = $2; $4->block = $7; $$ = $4;
#endif
}		//new NFor(NIdentifier id, NExpression range, NBlock block);
	| WHILE expr COLON INDENT block	UNINDENT		{
#if TEST_MODE > TEST_PARSER
$$ = new NWhile(*$2, *$5);
#endif
}		//new NWhile(NExpression condition, NBlock block);
;
loop_stmt1 :							{
#if TEST_MODE > TEST_PARSER
$$ = new NFor(NULL, NULL, 1);
#endif
}
	| id							{
#if TEST_MODE > TEST_PARSER
$$ = new NFor($1, NULL, 2);
#endif
}
	| RANGE loop_stmt2					{
#if TEST_MODE > TEST_PARSER
$$ = new NFor($2, NULL, 3);
#endif
}
	| RANGE loop_stmt2 TO loop_stmt2			{
#if TEST_MODE > TEST_PARSER
$$ = new NFor($2, $4, 4);
#endif
}
;
loop_stmt2 :							/*{
#if TEST_MODE > TEST_PARSER
$$ = new NBlank();
#endif
}
	|*/const_int						{$<expr>$ = $1;}
	| id							{$<expr>$ = $1;}
;

/*
block  : block block_0
	| %empty // empty
;

block_0 :  INDENT block UNINDENT	{
#if TEST_MODE > TEST_PARSER
$$ = new NBlock();
#endif
}
	|  expr
	|  var_dcl

;
*/

return_stmt :
	  RETURN  						{
#if TEST_MODE > TEST_PARSER
$$ = new NReturn( *(new IdentifierList()) );
#endif
}
	| RETURN id id1 					{
#if TEST_MODE > TEST_PARSER
$3->push_back($2); $$ = new NReturn(*$3);
#endif
}
;

id1 :								{
#if TEST_MODE > TEST_PARSER
$$ = new IdentifierList();
#endif
}
	| COMMA id id1						{
#if TEST_MODE > TEST_PARSER
$3->push_back($2); $$ = $3;
#endif
}
;

expr :
	  LPAREN expr RPAREN	{
#if TEST_MODE > TEST_PARSER
$$ = $2;
#endif
}
	| expr bin_op expr	{
#if TEST_MODE > TEST_PARSER
$$ = new NBineryOp(*$1, $2, *$3);
#endif
}
	| func_call		{
#if TEST_MODE > TEST_PARSER
//$$ = new NExpression(*$1);
#endif
}
	| id			{
#if TEST_MODE > TEST_PARSER
//$$ = new NExpression(*$1);
#endif
}
	| id LBRACK expr RBRACK {
#if TEST_MODE > TEST_PARSER
$$ = new NArrayExpr(*$1, *$3);
#endif
}
	| const_val		{
#if TEST_MODE > TEST_PARSER
//$$ = new NExpression(*$1);
#endif
}
	| MINUS expr		{
#if TEST_MODE > TEST_PARSER
$$ = new NUnaryOp($1, *$2);
#endif
}
	| NOT expr		{
#if TEST_MODE > TEST_PARSER
$$ = new NUnaryOp($1, *$2);
#endif
}
	| COMP expr		{
#if TEST_MODE > TEST_PARSER
$$ = new NUnaryOp($1, *$2);
#endif
}
;
bin_op :
	  arithmetic 
	| conditional
;

arithmetic :  PLUS | MINUS | MULT | DIV | MOD | AND | OR | XOR | OROR | ANDAND
;

conditional : EQEQ | NOTEQ | GTEQ | LTEQ | LT | GT
;

const_val : 
	  const_int		{$<expr>$ = $1;}
	| CONST_REAL 		{
#if TEST_MODE > TEST_PARSER
$$ = new NReal( atof($1->c_str() ) ); delete $1;
#endif
}
	| CONST_CHAR 		{
#if TEST_MODE > TEST_PARSER
$$ = new NChar($1->c_str()[0]); delete $1;
#endif
}
	| TRUE			{
#if TEST_MODE > TEST_PARSER
$$ = new NBool(true); delete $1;
#endif
}
	| FALSE 		{
#if TEST_MODE > TEST_PARSER
$$ = new NBool(false); delete $1;
#endif
}
	| CONST_STRING 		{
#if TEST_MODE > TEST_PARSER
$$ = new NString(*$1); delete $1;
#endif
}
	| CONST_LONG 		{
#if TEST_MODE > TEST_PARSER
$$ = new NLong( atol($1->c_str()) ); delete $1;
#endif
}
;

type : BOOL | INT | LONG | CHAR | REAL | STRING
;

const_int : CONST_INT		{
#if TEST_MODE > TEST_PARSER
$$ = new NInteger( atoi($1->c_str() ) ); delete $1;
#endif
}
;

id : ID 			{
#if TEST_MODE > TEST_PARSER
$$ = new NIdentifier (*$1); delete $1;
#endif
}
;

%%

#if TEST_MODE < TEST_NONE

#include<cctype>
#include<cstring>
int count=0;
extern int yyparse();
extern NBlock* programBlock;

int main(int argc, char *argv[])
{
	yyin  = stdin;//fopen(argv[1], "r");
//	yyout = fopen(argv[2], "w");
//	*strstr(argv[1], ".lulu") = '\0';
//	yyout = fopen(strcat(argv[1], "ParseReport.txt"), "w");
	
	if(!yyparse()){
		printf("yes\n");
	}else{
		printf("no\n");
	}
//	fclose(yyin);
//	fclose(yyout);
	//programBlock->codeGen();
    return 0;
}

//int type_size_fn(char* type_name){
//	return 4;
//}
 /*    
void yyerror(char *s) {
	printf("%d : %s %s\n", yylineno, s, yytext );
} 
 */

#endif
