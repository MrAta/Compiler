/*
Copyright (C) 2013 Lucas Beyer (http://lucasb.eyer.be)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to
deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.
*/

%{
#include "debug_mode.h"

#define SAVE_TOKEN yylval.str = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)

#if TEST_MODE > TEST_SCANNER
#include "node.h"
#include "parser.hpp"

#define  SCAN(token) return TOKEN(token)
#define  _SCAN_STR(token_name)  do{ SAVE_TOKEN; return token_name; }while(0)

#else

#define  SCAN(token) printf("%s\n", #token)
#define  _SCAN_STR(token_name)  printf("%s:%s\n", #token_name, yytext)

#endif

#define  SCAN_CONST(token)	_SCAN_STR(CONST_##token)
#define  SCAN_ID()		_SCAN_STR(ID)
#define  SCAN_TRUE()		_SCAN_STR(TRUE)
#define  SCAN_FALSE()		_SCAN_STR(FALSE)

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stack>
#include <iostream>

/* globals to track current indentation */
int g_current_line_indent = 0;   /* indentation of the current line */
std::stack<size_t> g_indent_levels;
int g_is_fake_outdent_symbol = 0;

typedef struct _YYLTYPE {
	int first_column;
	int last_column;
	int first_line;
	int last_line;
} YYLTYPE;

YYLTYPE yylloc;

/* TODO: error-out on tabs/spaces mix? */
static const unsigned int TAB_WIDTH = 1;

/* Don't mangle yylex please! */
#define YY_DECL extern int yylex()
#define YYSTYPE int

#define YY_USER_INIT { \
        g_indent_levels.push(0); \
	yylloc.first_line = yylloc.first_column = 1; \
        BEGIN(initial); \
    }

int yycolumn = 1;
void set_yycolumn(int val) {
    yycolumn = val;
    yylloc.first_column = yycolumn;
    yylloc.last_column = yycolumn + yyleng - 1;
}

#define YY_USER_ACTION { \
    yylloc.first_line = yylloc.last_line = yylineno; \
    set_yycolumn(yycolumn); \
    yycolumn += yyleng; \
}

%}

 /* This is a sub-parser (state) for indentation-sensitive scoping */
%x initial
%x indent
%x ml_comment
%x sl_comment
%s normal

 /* %option 8bit reentrant bison-bridge */
%option warn
%option nodefault
%option yylineno
%option noyywrap

DIGIT		[0-9]
IDENTIFIER	[a-zA-Z_][_a-zA-Z0-9]*
UCN		(\\u[0-9a-fA-F]{4}|\\U[0-9a-fA-F]{8})
ILEN		([Uu](L|l|LL|ll)?|(L|l|LL|ll)[Uu]?)

 /*%option debug*/
%%
    int indent_caller = normal;
    int comment_caller = normal;

 /* This helps to keep track of the column number.
  * Note that it won't work if you have a rule which includes a newline and is
  * longer than one character because in that case that rule will be favored
  * and this one here won't get called.
  * TL;DR: If you have a rule which includes \n and more, you need to reset
  *        yycolumn inside that rule!
  */
<*>\n { set_yycolumn(0); yylineno--; REJECT; }
<*>"#".*$ {
#if TEST_MODE > TEST_SCANNER
#else
printf("SL_comment\n");
#endif
}
 /* "@"([^@]|\@+[^@])\@*"@" */
 /* <normal>"@"([^@]|\@+[^@])*"@" */
 /* "@"[^@]*"@"*/		/* @ Only recognize this as a comment @ */
 /* ([@]+)([^@]*)([@]+) */	/* @@ Supports this as a comment @@@ */
<*>"@"[^@]*"@" {
#if TEST_MODE > TEST_SCANNER
#else
printf("ML_comment\n");
#endif
}

 /* Everything runs in the <normal> mode and enters the <indent> mode
    when a newline symbol is encountered.
    There is no newline symbol before the first line, so we need to go
    into the <indent> mode by hand there.
 */
<initial>.  { set_yycolumn(yycolumn-1); indent_caller = normal; yyless(0); BEGIN(indent); }
<initial>\n { indent_caller = normal; yyless(0); BEGIN(indent); }

 /* The following are the rules that keep track of indentation. */
<indent>\t      { g_current_line_indent = (g_current_line_indent + TAB_WIDTH) & ~(TAB_WIDTH-1); }
<indent>\n      { g_current_line_indent = 0; /* ignoring blank line */ }
<indent><<EOF>> {
                    // When encountering the end of file, we want to emit an
                    // outdent for all indents currently left.
                    if(g_indent_levels.top() != 0) {
                        g_indent_levels.pop();

                        // See the same code below (<indent>.) for a rationale.
                        if(g_current_line_indent != g_indent_levels.top()) {
                            unput('\n');
                            for(size_t i = 0 ; i < g_indent_levels.top() ; ++i) {
                                unput('\t');
                            }
                        } else {
                            BEGIN(indent_caller);
                        }
			
			SCAN(UNINDENT);
			
                    } else {
                        yyterminate();
                    }
                }

 /* <indent>"#".*$  {
#if TEST_MODE > TEST_SCANNER
#else
printf("indent_SL_comment\n");
#endif
} */
<indent>.       {
                    if(!g_is_fake_outdent_symbol) {
                        unput(*yytext);
                    }
                    set_yycolumn(yycolumn-1);
                    g_is_fake_outdent_symbol = 0;

                    // Indentation level has increased. It can only ever
                    // increase by one level at a time. Remember how many
                    // spaces this level has and emit an indentation token.
                    if(g_current_line_indent > g_indent_levels.top()) {
                        g_indent_levels.push(g_current_line_indent);
                        BEGIN(indent_caller);
			
			SCAN(INDENT);

                    } else if(g_current_line_indent < g_indent_levels.top()) {
                        // Outdenting is the most difficult, as we might need to
                        // outdent multiple times at once, but flex doesn't allow
                        // emitting multiple tokens at once! So we fake this by
                        // 'unput'ting fake lines which will give us the next
                        // outdent.
                        g_indent_levels.pop();

                        if(g_current_line_indent != g_indent_levels.top()) {
                            // Unput the rest of the current line, including the newline.
                            // We want to keep it untouched.
                            for(size_t i = 0 ; i < g_current_line_indent ; ++i) {
                                unput('\t');
                            }
                            unput('\n');
                            // Now, insert a fake character indented just so
                            // that we get a correct outdent the next time.
                            unput('.');
                            // Though we need to remember that it's a fake one
                            // so we can ignore the symbol.
                            g_is_fake_outdent_symbol = 1;
                            for(size_t i = 0 ; i < g_indent_levels.top() ; ++i) {
                                unput('\t');
                            }
                            unput('\n');
                        } else {
                            BEGIN(indent_caller);
                        }

			SCAN(UNINDENT);

                    } else {
                        // No change in indentation, not much to do here...
                        BEGIN(indent_caller);
                    }
                }

<normal>\n    { g_current_line_indent = 0; indent_caller = YY_START; BEGIN(indent); }

<normal>start		{SCAN(START);}
<normal>finish		{SCAN(FINISH);}


<normal>sizeof		{SCAN(SIZEOF);}

<normal>true		{SCAN_TRUE();}
<normal>false		{SCAN_FALSE();}

<normal>bool		{SCAN(BOOL);}
<normal>char		{SCAN(CHAR);}
<normal>int		{SCAN(INT);}
<normal>long		{SCAN(LONG);}
<normal>real		{SCAN(REAL);}
<normal>string		{SCAN(STRING);}

<normal>if		{SCAN(IF);}
<normal>elif		{SCAN(ELIF);}
<normal>else		{SCAN(ELSE);}

<normal>while		{SCAN(WHILE);}
<normal>for		{SCAN(FOR);}
<normal>in		{SCAN(IN);}
<normal>range		{SCAN(RANGE);}
<normal>to		{SCAN(TO);}

<normal>continue	{SCAN(CONTINUE);}
<normal>break		{SCAN(BREAK);}
<normal>case		{SCAN(CASE);}
<normal>default		{SCAN(DEFAULT);}

<normal>return		{SCAN(RETURN);}


<normal>[-]?0[Xx][0-9a-fA-F]+{ILEN}?	{SCAN_CONST(INT);}
 /*
{	yylval.intval = strtol(yytext,NULL,0);
	printf("hex int const\n");
	//return(CONST_INT);
}
 */
<normal>[-]?[0-9]*\.[0-9]+		{SCAN_CONST(REAL);}
<normal>[-]?[0-9]+\.[0-9]+		{SCAN_CONST(REAL);}
<normal>[-]?[0-9]+\.[0-9]*		{SCAN_CONST(REAL);}
 /*
<normal>[-]?[0-9]*\.[0-9]*		{SCAN_CONST(REAL);}
 */
 /*
{
	yylval.rval = atof(yytext);
	printf("float const\n");
	//return(CONST_REAL);
}
 */
<normal>[-]?[0-9]+{ILEN}?		{SCAN_CONST(INT);} 
 /*
<normal>[-]?[1-9][0-9]*{ILEN}?		{SCAN_CONST(INT);}
<normal>[-]?[0]*{ILEN}?			{SCAN_CONST(INT);}
 */
 /*
{
	yylval.intval = atoi(yytext);
	printf("int const\n");
	//return(CONST_INT);
}
 */

 /*[-]?0[0-7]*{ILEN}?		{SCAN_CONST(INT);}*/
 /*
{
	yylval.intval = strtol(yytext,NULL,8);
	printf("oct int const\n");
	//return(CONST_INT);
}
 */

<normal>\'([^'\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})+\' {SCAN_CONST(CHAR);}
 /*
{
	char c[2];
	substring(yytext,c,2,1);
	yylval.cval = c[0];
	printf("character const\n");
	//return(CONST_CHAR);
}
 */
															
<normal>\"([^"\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})*\" {SCAN_CONST(STRING);}
 /*
{
	int len = strlen(yytext);
	substring(yytext, yylval.sval, 2, len-2);
	//yylval.id = (char*) strdup(yytext);
	printf("string const\n");
	//return(CONST_STRING);
}
 */

<normal>{IDENTIFIER}	{SCAN_ID();}
 /*
{
	printf("%s", yytext);
	yylval.id = (char*) strdup(yytext);
	//return(ID);
}
 */
 /*
<normal>"#".*$ {
#if TEST_MODE > TEST_SCANNER
#else
printf("SL_comment\n");
#endif
}
 */
 /* "@"([^@]|\@+[^@])\@*"@" */
 /* <normal>"@"([^@]|\@+[^@])*"@" */
 /* "@"[^@]*"@" */		/* @ Only recognize this as a comment @ */
 /* ([@]+)([^@]*)([@]+) */	/* @@ Supports this as a comment @@@ */
 /*
<normal>([@]+)([^@]*)([@]+) {
#if TEST_MODE > TEST_SCANNER
#else
printf("ML_comment\n");
#endif
}
 */
 /*
<normal>[@]+ {
BEGIN(ml_comment);
#if TEST_MODE > TEST_SCANNER
#else
printf("ML_comment_Start\n");
#endif
}
<ml_comment>"@" {
BEGIN(normal);
#if TEST_MODE > TEST_SCANNER
#else
printf("ML_comment_End\n");
#endif
} //"#".*\n	{printf("SL_comment\n");}
<ml_comment>. {}
 */
	/* separators */
<normal>"("                            { SCAN(LPAREN);}//return(LPAREN); 
<normal>")"                            { SCAN(RPAREN);}//return(RPAREN); 
<normal>":"                            { SCAN(COLON);}//return(COLON);
<normal>"["                            { SCAN(LBRACK);}//return(LBRACK);
<normal>"]"                            { SCAN(RBRACK);}//return(RBRACK); 
<normal>","                            { SCAN(COMMA);}//return(COMMA); 


 
  /* operators */
<normal>"="                            { SCAN(EQ);}//return(EQ); 
<normal>">"                            { SCAN(GT);}//return(GT); 
<normal>"<"                            { SCAN(LT);}//return(LT); 
<normal>"!"                            { SCAN(NOT);}//return(NOT); 
<normal>"~"                            { SCAN(COMP);}//return(COMP);
<normal>"=="                           { SCAN(EQEQ);}//return(EQEQ); 
<normal>"<="                           { SCAN(LTEQ);}//return(LTEQ); 
<normal>">="                           { SCAN(GTEQ);}//return(GTEQ); 
<normal>"!="                           { SCAN(NOTEQ);}//return(NOTEQ); 
<normal>"&&"                           { SCAN(ANDAND);}//return(ANDAND); 
<normal>"||"                           { SCAN(OROR);}//return(OROR);
<normal>"+"                            { SCAN(PLUS);}//return(PLUS); 
<normal>"-"                            { SCAN(MINUS);}//return(MINUS); 
<normal>"*"                            { SCAN(MULT);}//return(MULT); 
<normal>"/"                            { SCAN(DIV);}//return(DIV); 
<normal>"&"                            { SCAN(AND);}//return(AND);
<normal>"|"                            { SCAN(OR); }//return(OR); 
<normal>"^"                            { SCAN(XOR);}//return(); 
<normal>"%"                            { SCAN(MOD);}//; 

<normal>" "+ //{ printf("kossher\n"); } //return TOK_REST;
(.|\n)  //{ std::cerr << __FILE__ << ":" << yylineno << ":" << yycolumn << ": Unexpected character: " << yytext << std::endl; exit(1); }

%%
#if TEST_MODE == TEST_SCANNER
int main(int argc, char* argv[]) {
printf("from main:\n");
  yylex() ;
  printf("\n") ;
}
#endif
