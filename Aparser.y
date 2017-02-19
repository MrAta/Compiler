%{

#include "debug_mode.h"

#if TEST_MODE > TEST_PARSER
#include "node.h"

#define  PARSE(token) return token

#else

#define  PARSE(token) printf("%s\n", #token)

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdbool.h>
#define YYDEBUG 1

#if TEST_MODE > TEST_PARSER
NBlock *programBlock; /* the top level root node of our final AST */
#endif

 /*NProgram *program; /* the top level root node of our final AST */

extern int yylex();
extern FILE *yyin;
void yyerror(const char *s) { printf("ERROR: %s\n", s); }

%}

%union{ 
//#if TEST_MODE > TEST_PARSER
//Node *node;
//NBlock *block;
//NIdentifier *ident;
/*
%union {
    Node *node;
    NBlock *block;
    NExpression *expr;
    NStatement *stmt;
    NIdentifier *ident;
    NVariableDeclaration *var_decl;
    std::vector<NVariableDeclaration*> *varvec;
    std::vector<NExpression*> *exprvec;
    std::string *string;
    int token;
}
*/
//#endif
int test;
int token;
std::string *str;
/*bool bval;
long lval;
*/
}

%token <token> INDENT UNINDENT LBRACK RBRACK
%token <token> START
%token <token> COLON 
%token <token> NOT COMMA EQ OROR ANDAND OR XOR AND EQEQ NOTEQ LT LTEQ GT GTEQ PLUS MINUS MULT DIV MOD SIZEOF NEG COMP LPAREN RPAREN
//TODO change types to str
%token <str> ID
%token <str> CONST_INT CONST_REAL 
%token <str> CONST_CHAR CONST_STRING
%token <str> CONST_LONG
%token <str> TRUE FALSE 
//End-of-TODO
%token <token> BOOL INT LONG CHAR REAL STRING
/*%token <token> READ WRITE
%token <token> START FINISH
*/
/*
%token <token> BREAK CONTINUE
%token <token> IF ELSE ELIF CASE DEFAULT
%token <token> WHILE FOR IN RANGE TO 
%token <token> RETURN
*/

%type <test> var_dcl
%type <test> ts_dcl 
%type <test> ts_dcl2
%type <test> ts_dcl1
%type <test> block
%type <test> block_0
%type <test> expr
%type <test> bin_op
%type <test> arithmetic
%type <test> conditional
%type <test> const_val const_int
%type <test> type
%type <test> id
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

%start block

%%

var_dcl : 
	  id ts_dcl					{
#if TEST_MODE > TEST_PARSER
//$$ = new NVarDecl(*$1, *$2);
#endif
}
;
ts_dcl : 
	  LBRACK type ts_dcl2				{
#if TEST_MODE > TEST_PARSER
//$$ = new TsDeclList(); $$->push_back( new NTsDecl($2, new NInteger(1)) );
#endif
}
;

ts_dcl2 :
	  RBRACK				{
#if TEST_MODE > TEST_PARSER
//$$ = new TsDeclList(); $$->push_back( new NTsDecl($2, new NInteger(1)) );
#endif
}
	| ts_dcl1 RBRACK			{
#if TEST_MODE > TEST_PARSER
//$3->push_back(new NTsDecl($2, new NInteger(1)) ); $$ = $3;
#endif
}
	| LT const_int GT ts_dcl1 RBRACK	{
#if TEST_MODE > TEST_PARSER
//$6->push_back(new NTsDecl($2, *$4)); $$ = $6;
#endif
}
;

ts_dcl1 : 						{
#if TEST_MODE > TEST_PARSER
//$$ = new TsDeclList();
#endif
}
	| COMMA type LT const_int GT ts_dcl1		{
#if TEST_MODE > TEST_PARSER
//$6->push_back(new NTsDecl($2, *$4)); $$ = $6;
#endif
}
	| COMMA type ts_dcl1				{
#if TEST_MODE > TEST_PARSER
//$3->push_back(new NTsDecl($2, new NInteger(1)) ); $$ = $3;
#endif
}
;

block  : block block_0
	| %empty /* empty */
;

block_0 :  INDENT block UNINDENT	{
#if TEST_MODE > TEST_PARSER
$$ = new NBlock();
#endif
}
	|  expr
	|  var_dcl

;
/*
block : 							{ $$ = new NBlock(); }
	| statement block					{ $2->statements.push_back($1); $$ = $2; }
;

statement : 
	  assignment
	| func_call
	| cond_stmt
	| loop_stmt
	| return_stmt
	| BREAK							{ $$ = new NBreak(); }
	| CONTINUE						{ $$ = new NContinue(); }
;

assignment : 
	  id EQ expr expr1					{ $4->push_back($3); $$ = new NAssignment(*$1, *$4); }
	| id LBRACK expr expr1 RBRACK EQ expr expr1		{ $4->push_back($3); $8->push_back($7); $$ = new NAssignment(*$1, *$4, *$8); }
	| var_dcl EQ expr expr1					{ $4->push_back($3); $$ = new NAssignment(*$1, *$4); }
;
expr1 : 							{ $$ = new ExpressionList(); }
	| COMMA expr expr1					{ $3->push_back($2); $$ = $3; }
;
*/
expr :
	  LPAREN expr RPAREN	{
#if TEST_MODE > TEST_PARSER
$$ = $2;
#endif
}
	| expr bin_op expr	{
#if TEST_MODE > TEST_PARSER
$$ = new NExpression(*$1, $2, *$3);
#endif
}
/*	| func_call		{
#if TEST_MODE > TEST_PARSER
$$ = new NExpression(*$1);
#endif
} */
	| id			{
#if TEST_MODE > TEST_PARSER
$$ = new NExpression(*$1);
#endif
}
	| const_val		{
#if TEST_MODE > TEST_PARSER
$$ = new NExpression(*$1);
#endif
}
	| MINUS expr		{
#if TEST_MODE > TEST_PARSER
$$ = new NExpression($1, *$2);
#endif
}
	| NOT expr		{
#if TEST_MODE > TEST_PARSER
$$ = new NExpression($1, *$2);
#endif
}
	| COMP expr		{
#if TEST_MODE > TEST_PARSER
$$ = new NExpression($1, *$2);
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
	  const_int
	| CONST_REAL 		{
#if TEST_MODE > TEST_PARSER
$$ = new NReal( atof($1->c_str() ) ); delete $1;
#endif
}
	| CONST_CHAR 		{
#if TEST_MODE > TEST_PARSER
$$ = new NChar($1->c_str()); delete $1;
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
$$ = new NString($1->c_str()); delete $1;
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

#if TEST_MODE > TEST_PARSER
#else

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
