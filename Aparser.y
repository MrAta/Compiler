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

#if TEST_MODE > TEST_PARSER
NProgram    *programBlock; /* the top level root node of our final AST */
NIdentifier *start;
NIdentifier *finish;
#endif

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
	NExpression *expr;
	NInteger *const_int;
	NConst *const_val;
	NIdentifier *ident;
	NBinaryOp *bin_op;
	IdentifierList *ident_l;
	NReturn *ret;
	ExpressionList *expr_l;
	NFuncCall *func;
	NStatement *stmt;
	NVarDecl *vard;
	TsDecl *tsd;
	TsDeclList *tsd_l;
	NAssignment *ass;
	AssignmentLHS *lhs;
	NArrayExpr *arr;
	StatementList *stmt_l;
	NBlock *blk;
	VariableList *var_l;
	NFunctionDecl *funcd;
	DeclarationList *dec_l;
	NProgram *prog;
/*
	NBlock *block;
	NStatement *stmt;
	NVarDecl* var;
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
*/
#else
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

%type <prog> program
%type <dec_l> program1
%type <ident> start finish
%type <vard> var_dcl
%type <tsd_l> ts_dcl 
%type <tsd_l> ts_dcl1
%type <funcd> func_dcl 
%type <var_l> func_dcl1
%type <blk> block
%type <stmt_l> block1
%type <ret> return_stmt
%type <token> cond_stmt
%type <token> cond_stmt1
%type <token> cond_stmt2
%type <token> loop_stmt 
%type <token> loop_stmt1
%type <token> loop_stmt2
%type <expr> expr
%type <expr_l> expr1
%type <ident_l> id1
%type <stmt> statement
%type <ass> assignment
%type <lhs> assignment_lhs
%type <func> func_call
%type <expr_l> func_param1
%type <expr_l> func_param //func_param2
%type <bin_op> bin_op
%type <const_val> const_val 
%type <const_int> const_int
%type <ident> id
%type <arr> array
%type <token> type
/*
%type type
%type const_int
*/
%right EQ

%right COMMA
/*
%nonassoc LBRACK RBRACK
*/
%left ANDAND OROR

%left EQEQ NOTEQ
%left LT LTEQ GT GTEQ

%left PLUS MINUS
%left MULT DIV MOD
%left OR AND XOR
%right SIZEOF NEG COMP NOT

%left RPAREN
%right LPAREN

%right RETURN
%right ID

%start program

%%
program :
	program1						{
#if TEST_MODE > TEST_PARSER
$$ = programBlock = new NProgram(*$1);
#endif
}
;

program1 : 							{
#if TEST_MODE > TEST_PARSER
$$ = new DeclarationList();
#endif
}
	| var_dcl program1					{
#if TEST_MODE > TEST_PARSER
if( $1 != NULL) {
	$2->push_back($1);
	$$ = $2;
} else {
	yyerror("Ridi!");
}
#endif
}
	| func_dcl program1					{
#if TEST_MODE > TEST_PARSER
if( $1 != NULL) {
	$2->push_back($1);
	$$ = $2;
} else {
	yyerror("Rede!");
}
#endif
}

	| start program1					{
#if TEST_MODE > TEST_PARSER
if( start == NULL )
	start = $1; 
else
	yyerror("multiple definition of start");

$$ = $2;
#endif
}
	| finish program1					{
#if TEST_MODE > TEST_PARSER
if( finish == NULL )
	finish = $1;
else
	yyerror("multiple definition of finish");

$$ = $2;
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

block :
	block1							{
#if TEST_MODE > TEST_PARSER
$$ = new NBlock(*$1);
#endif
}
;

block1 : 							{
#if TEST_MODE > TEST_PARSER
$$ = new StatementList();
#endif
}
	| statement block1					{
#if TEST_MODE > TEST_PARSER
$2->push_back($1); $$ = $2;
#endif
}
;

statement : 
	  assignment						{
#if TEST_MODE > TEST_PARSER
$$=$1;
#endif
}
	| var_dcl						{
#if TEST_MODE > TEST_PARSER
$$=$1;
#endif
}
	| func_call						{
#if TEST_MODE > TEST_PARSER
$$=$1;
#endif
}
	| cond_stmt
	| loop_stmt
	| return_stmt						{
#if TEST_MODE > TEST_PARSER
$$=$1;
#endif
}
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
	  assignment_lhs EQ expr expr1				{
#if TEST_MODE > TEST_PARSER
$4->push_back($3); $$ = new NAssignment(*$1, *$4);
#endif
}
;

assignment_lhs:
	  id							{
#if TEST_MODE > TEST_PARSER
$$=$1;
#endif
}
	| array							{
#if TEST_MODE > TEST_PARSER
$$=$1;
#endif
}
	| var_dcl						{
#if TEST_MODE > TEST_PARSER
$$=$1;
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
	   LPAREN RPAREN					{
#if TEST_MODE > TEST_PARSER
$$ = new ExpressionList();
#endif
}
	   | LPAREN expr func_param1 RPAREN			{
#if TEST_MODE > TEST_PARSER
$3->push_back($2); $$ = $3;
#endif
}
;
/*
func_param1 :							{
#if 0 && TEST_MODE > TEST_PARSER
$$ = new NBlank();
#endif
}
	| expr	
	//| id
	//| const_val
;
*/
func_param1 :							{
#if TEST_MODE > TEST_PARSER
$$ = new ExpressionList();
#endif
}
	| COMMA expr func_param1				{
#if TEST_MODE > TEST_PARSER
$3->push_back($2); $$ = $3;
#endif
}
;

cond_stmt : 
	  IF expr COLON INDENT block UNINDENT cond_stmt1	{
#if 0 && TEST_MODE > TEST_PARSER
//$7->ebl.emplace_back($2, $5); $$ = $7;
$7->ebl.push_back(new ExprBlock($2, $5)); $$ = $7;
#endif
}
	| IF expr COLON INDENT block UNINDENT cond_stmt1 ELSE COLON INDENT block UNINDENT
								{
#if 0 && TEST_MODE > TEST_PARSER
//$7->ebl.emplace_back($2, $5);
//$7->ebl.emplace_back(new NBool(true), $11); $$ = $7;
$7->ebl.push_back(new ExprBlock($2, $5)); $7->ebl.push_back(new ExprBlock(new NBool(true), $11)); $$ = $7;
//$7->bl.push_back($5); $7->bl.push_back($11); $7->el.push_back($2); $$ = $7;
#endif
}
	| CASE expr COLON INDENT cond_stmt2 UNINDENT		{
#if 0 && TEST_MODE > TEST_PARSER
$5->Expression = $2; $$ = $5;
#endif
}
	| CASE expr COLON INDENT cond_stmt2 DEFAULT COLON INDENT block	UNINDENT UNINDENT
								{
#if 0 && TEST_MODE > TEST_PARSER
$5->ebl.push_back(new ExprBlock(new NBool(true), $9)); $5->Expression = $2; $$ = $5;
//$5->ebl.emplace_back(new NBool(true), $9); $5->Expression = $2; $$ = $5;
#endif
}
;
cond_stmt1 : 							{
#if 0 && TEST_MODE > TEST_PARSER
$$ = new NIf();
#endif
}	//NIf() has two list: Block and Expression List. if we have 'else' then bl.length -1 = el.length . if we do not have 'else' then bl.length = el.length .
	| ELIF expr COLON INDENT block UNINDENT cond_stmt1	{
#if 0 && TEST_MODE > TEST_PARSER
//$7->ebl.emplace_back($2, $5); $$ = $7;
$7->ebl.push_back(new ExprBlock($2, $5)); $$ = $7;
//$7->bl.push_back($5); $7->el.push_back($2); $$ = $7;
#endif
}
;

cond_stmt2 : 							{
#if 0 && TEST_MODE > TEST_PARSER
$$ = new NCase();
#endif
}
	| const_val COLON INDENT block UNINDENT cond_stmt2	{
#if 0 && TEST_MODE > TEST_PARSER
$6->ebl.push_back(new ExprBlock($1, $4)); $$ = $6;
//$6->ebl.emplace_back($1, $4); $$ = $6;
#endif
}
;

loop_stmt :
//	  FOR id IN COLON block
	  FOR id IN loop_stmt1 COLON INDENT block UNINDENT	{
#if 0 && TEST_MODE > TEST_PARSER
$4->id = $2; $4->block = $7; $$ = $4;
#endif
}		//new NFor(NIdentifier id, NExpression range, NBlock block);
	| WHILE expr COLON INDENT block	UNINDENT		{
#if 0 && TEST_MODE > TEST_PARSER
$$ = new NWhile(*$2, *$5);
#endif
}		//new NWhile(NExpression condition, NBlock block);
;
loop_stmt1 :							{
#if 0 && TEST_MODE > TEST_PARSER
$$ = new NFor(NULL, NULL, 1);
#endif
}
	| id							{
#if 0 && TEST_MODE > TEST_PARSER
$$ = new NFor($1, NULL, 2);
#endif
}
	| RANGE loop_stmt2					{
#if 0 && TEST_MODE > TEST_PARSER
$$ = new NFor($2, NULL, 3);
#endif
}
	| RANGE loop_stmt2 TO loop_stmt2			{
#if 0 && TEST_MODE > TEST_PARSER && 0
$$ = new NFor($2, $4, 4);
#endif
}
;
loop_stmt2 :							/*{
#if 0 && TEST_MODE > TEST_PARSER
$$ = new NBlank();
#endif
}
	|*/const_int						{
#if 0
$<expr>$ = $1;
#endif
}
	| id							{
#if 0
$<expr>$ = $1;
#endif
}
;

/*
block  : block block_0
	| %empty // empty
;

block_0 :  INDENT block UNINDENT	{
#if 0 && TEST_MODE > TEST_PARSER
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
	| bin_op		{
#if TEST_MODE > TEST_PARSER
//$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
	| func_call		{
#if 0 && TEST_MODE > TEST_PARSER
//$$ = new NExpression(*$1);
#endif
}
	| id			{
#if TEST_MODE > TEST_PARSER
$$ = $1;
//$$ = new NExpression(*$1);
#endif
}
	| array			{
#if TEST_MODE > TEST_PARSER
$$=$1;
#endif
}
	| const_val		{
#if TEST_MODE > TEST_PARSER
$$ = $1;//$$ = new NExpression(*$1);
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
	  expr PLUS   expr {
#if TEST_MODE > TEST_PARSER
$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
	| expr MINUS  expr {
#if TEST_MODE > TEST_PARSER
$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
	| expr MULT   expr {
#if TEST_MODE > TEST_PARSER
$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
	| expr DIV    expr {
#if TEST_MODE > TEST_PARSER
$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
	| expr MOD    expr {
#if TEST_MODE > TEST_PARSER
$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
	| expr AND    expr {
#if TEST_MODE > TEST_PARSER
$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
	| expr OR     expr {
#if TEST_MODE > TEST_PARSER
$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
	| expr XOR    expr {
#if TEST_MODE > TEST_PARSER
$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
	| expr OROR   expr {
#if TEST_MODE > TEST_PARSER
$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
	| expr ANDAND expr {
#if TEST_MODE > TEST_PARSER
$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
	| expr EQEQ   expr {
#if TEST_MODE > TEST_PARSER
$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
	| expr NOTEQ  expr {
#if TEST_MODE > TEST_PARSER
$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
	| expr GTEQ   expr {
#if TEST_MODE > TEST_PARSER
$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
	| expr LTEQ   expr {
#if TEST_MODE > TEST_PARSER
$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
	| expr LT     expr {
#if TEST_MODE > TEST_PARSER
$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
	| expr GT     expr {
#if TEST_MODE > TEST_PARSER
$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
;

const_val : 
	  const_int		{
#if TEST_MODE > TEST_PARSER
$$ = $1;
#endif
}
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
//TODO What the fuck should I finally do? how many dimensions etc. ?
array : id LBRACK expr expr1 RBRACK {
#if TEST_MODE > TEST_PARSER
$$ = new NArrayExpr(*$1, *$3);
#endif
}
;
/*
array_lhs : id LBRACK expr expr1 RBRACK {
#if TEST_MODE > TEST_PARSER
$$ = new NArrayExpr(*$1, *$3);
#endif
}
;

array_expr : id LBRACK expr RBRACK {
#if TEST_MODE > TEST_PARSER
$$ = new NArrayExpr(*$1, *$3);
#endif
}
;
*/
%%

#if TEST_MODE < TEST_NONE

#include<cctype>
#include<cstring>
int count=0;
extern int yyparse();

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
