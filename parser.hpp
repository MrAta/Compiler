/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INDENT = 258,
    UNINDENT = 259,
    LBRACK = 260,
    RBRACK = 261,
    START = 262,
    FINISH = 263,
    WHILE = 264,
    FOR = 265,
    IN = 266,
    RANGE = 267,
    TO = 268,
    BREAK = 269,
    CONTINUE = 270,
    IF = 271,
    ELSE = 272,
    ELIF = 273,
    CASE = 274,
    DEFAULT = 275,
    RETURN = 276,
    COLON = 277,
    NOT = 278,
    COMMA = 279,
    EQ = 280,
    OROR = 281,
    ANDAND = 282,
    OR = 283,
    XOR = 284,
    AND = 285,
    EQEQ = 286,
    NOTEQ = 287,
    LT = 288,
    LTEQ = 289,
    GT = 290,
    GTEQ = 291,
    PLUS = 292,
    MINUS = 293,
    MULT = 294,
    DIV = 295,
    MOD = 296,
    SIZEOF = 297,
    NEG = 298,
    COMP = 299,
    LPAREN = 300,
    RPAREN = 301,
    BOOL = 302,
    INT = 303,
    LONG = 304,
    CHAR = 305,
    REAL = 306,
    STRING = 307,
    ID = 308,
    CONST_INT = 309,
    CONST_REAL = 310,
    CONST_CHAR = 311,
    CONST_STRING = 312,
    CONST_LONG = 313,
    TRUE = 314,
    FALSE = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 53 "Aparser.y" /* yacc.c:1909  */

	Node *node;
	NBlock *block;
	NExpression *expr;
	NStatement *stmt;
	NIdentifier *ident;
	TsDeclList tsdecl;
	//std::vector<ExprBlock*> ExprBlockList;
	std::vector<NIdentifier*> IdentifierList;
	std::vector<NStatement*> StatementList;
	std::vector<NExpression*> ExpressionList;
	std::vector<NVarDecl*> VariableList;

	std::string *string;
	int token;

#line 132 "parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
