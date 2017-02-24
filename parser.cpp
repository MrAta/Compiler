/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Aparser.y" /* yacc.c:339  */


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


#line 100 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
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
#line 52 "Aparser.y" /* yacc.c:355  */

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

#line 264 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 281 "parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   482

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   198,   198,   205,   210,   220,   231,   241,   255,   262,
     270,   278,   285,   292,   297,   303,   312,   317,   322,   327,
     334,   339,   347,   354,   359,   367,   372,   377,   382,   383,
     384,   389,   394,   402,   410,   415,   420,   427,   432,   440,
     460,   465,   482,   487,   495,   501,   510,   515,   523,   528,
     537,   542,   552,   557,   563,   568,   573,   578,   589,   594,
     618,   623,   630,   635,   643,   648,   653,   658,   664,   669,
     674,   679,   684,   691,   696,   701,   706,   711,   716,   721,
     726,   731,   736,   741,   746,   751,   756,   761,   766,   774,
     779,   784,   789,   794,   799,   804,   811,   811,   811,   811,
     811,   811,   814,   821,   828
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INDENT", "UNINDENT", "LBRACK", "RBRACK",
  "START", "FINISH", "WHILE", "FOR", "IN", "RANGE", "TO", "BREAK",
  "CONTINUE", "IF", "ELSE", "ELIF", "CASE", "DEFAULT", "RETURN", "COLON",
  "NOT", "COMMA", "EQ", "OROR", "ANDAND", "OR", "XOR", "AND", "EQEQ",
  "NOTEQ", "LT", "LTEQ", "GT", "GTEQ", "PLUS", "MINUS", "MULT", "DIV",
  "MOD", "SIZEOF", "NEG", "COMP", "LPAREN", "RPAREN", "BOOL", "INT",
  "LONG", "CHAR", "REAL", "STRING", "ID", "CONST_INT", "CONST_REAL",
  "CONST_CHAR", "CONST_STRING", "CONST_LONG", "TRUE", "FALSE", "$accept",
  "program", "program1", "start", "finish", "var_dcl", "ts_dcl", "ts_dcl1",
  "func_dcl", "func_dcl1", "block", "block1", "statement", "assignment",
  "assignment_lhs", "expr1", "func_call", "func_param", "func_param1",
  "cond_stmt", "cond_stmt1", "cond_stmt2", "loop_stmt", "loop_stmt1",
  "loop_stmt2", "return_stmt", "id1", "expr", "bin_op", "const_val",
  "type", "const_int", "id", "array", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

#define YYPACT_NINF -158

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-158)))

#define YYTABLE_NINF -37

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,    65,   -25,   -25,  -158,    39,  -158,    10,    10,    10,
     -25,    10,     9,  -158,  -158,  -158,  -158,  -158,  -158,     8,
    -158,  -158,  -158,  -158,  -158,  -158,     2,  -158,    37,    19,
    -158,    41,    65,    -4,    53,    64,    19,    56,   -25,    47,
      21,  -158,    43,  -158,    56,    54,   194,   -25,  -158,  -158,
     194,   194,   -25,    66,    98,  -158,    56,  -158,    78,  -158,
    -158,  -158,  -158,    28,  -158,    19,   102,    -4,  -158,    94,
     115,   119,   194,   194,   194,   194,  -158,  -158,  -158,  -158,
    -158,  -158,  -158,   317,  -158,  -158,  -158,    29,  -158,   112,
     337,   357,   100,  -158,  -158,   194,   249,   170,  -158,  -158,
      56,    91,   122,  -158,    56,  -158,   205,  -158,   288,   126,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,    15,   128,   129,
     -25,  -158,   395,   395,  -158,   413,   130,    94,  -158,   131,
    -158,    56,   245,   245,  -158,  -158,  -158,   427,   427,   441,
     441,   441,   441,   205,   205,    52,    52,    52,   -32,   114,
    -158,    56,    30,   100,   194,  -158,   132,   194,    93,  -158,
    -158,  -158,   138,   133,  -158,  -158,   140,   141,    38,   127,
    -158,   395,  -158,   413,  -158,  -158,   -32,    56,   134,  -158,
     135,   145,  -158,  -158,  -158,   147,   194,   137,   152,    56,
    -158,   377,   142,    56,   156,   153,   159,   161,    30,    56,
      56,   163,  -158,   164,   167,  -158,   134,  -158,  -158
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,   103,     0,     2,     3,     3,     3,
       0,     3,     0,    96,    97,    98,    99,   100,   101,    13,
       8,     9,     1,     6,     7,     4,     0,     5,     0,    20,
      10,     0,     0,     0,     0,     0,    20,    23,     0,     0,
      13,   102,     0,    11,    23,     0,     0,     0,    31,    32,
       0,     0,    60,    26,     0,    22,    23,    25,     0,    27,
      28,    29,    30,    34,    35,    20,     0,     0,    15,    13,
       0,     0,     0,     0,     0,     0,    90,    91,    94,    95,
      92,    93,    66,     0,    65,    69,    89,    67,    68,     0,
       0,     0,    62,    16,    24,     0,     0,     0,    39,    21,
      23,     0,     0,    18,    23,    71,    70,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,    61,    37,    37,    40,    42,     0,    13,    12,     0,
      64,    23,    81,    82,    79,    80,    78,    83,    84,    87,
      86,    88,    85,    73,    74,    75,    76,    77,     0,     0,
      55,    23,    50,    62,     0,    33,     0,     0,     0,    19,
      14,    17,     0,    56,    58,    59,     0,     0,     0,     0,
      63,    37,   104,    42,    41,    53,     0,    23,    48,    46,
       0,     0,    38,    43,    57,     0,     0,    44,     0,    23,
      52,     0,     0,    23,     0,     0,     0,     0,    50,    23,
      23,     0,    51,     0,     0,    47,    48,    45,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,    86,  -158,  -158,    99,    -6,   -39,  -158,   -16,
     -40,   117,  -158,  -158,  -158,  -120,   -21,  -158,   -33,  -158,
     -42,   -31,  -158,  -158,   -11,  -158,    13,   146,  -158,  -157,
     148,   -14,     0,    -8
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    53,    10,    34,    11,    39,
      54,    55,    56,    57,    58,   165,    82,    98,   168,    60,
     197,   178,    61,   159,   173,    62,   131,   133,    84,    85,
      19,    86,    87,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    68,    20,    21,    70,   179,    30,    12,    12,    12,
      26,    12,    31,   166,     1,     1,    59,     2,     3,    42,
      45,     4,    41,    59,    35,    30,    31,   158,     4,    64,
     102,    28,    32,    96,   126,    59,    64,    63,    31,    22,
      37,    33,   189,    38,    63,    32,     1,    89,    64,    99,
      41,   179,    92,   101,    67,     4,    63,    30,   190,    43,
     136,   192,     4,     4,   139,    46,    47,    44,     4,    66,
      48,    49,    50,    97,    97,    51,    71,    52,    69,    59,
     112,   113,   114,    59,    41,    76,    77,    78,    79,    80,
      81,   -36,    64,    23,    24,    25,    64,    27,   170,     9,
      63,   172,    93,    95,    63,   100,     9,     9,     9,     4,
       9,    29,    13,    14,    15,    16,    17,    18,    32,   103,
      59,   177,   104,   127,   130,    36,   137,   160,   138,   141,
     163,   161,   162,    64,   169,   171,   176,    65,   182,   184,
      59,    63,   185,   187,   174,   188,   186,   195,   199,   191,
     193,   200,   196,    64,   202,   203,   209,   198,   175,   204,
     208,    63,   210,   207,   206,   211,    59,   215,   216,   213,
     214,   217,   174,    94,   218,   194,   180,   212,    59,    64,
      40,     0,    59,     0,     0,     0,   175,    63,    59,    59,
       0,    64,    83,    72,     0,    64,    90,    91,     0,    63,
       0,    64,    64,    63,     0,     0,     0,     0,    73,    63,
      63,     0,     0,     0,    74,    75,   134,    72,   105,   106,
     107,   108,     0,     4,    41,    76,    77,    78,    79,    80,
      81,     0,    73,   112,   113,   114,     0,     0,    74,    75,
       0,   132,     0,   135,   123,   124,   125,     4,    41,    76,
      77,    78,    79,    80,    81,     0,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    72,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    73,     0,     0,
       0,     0,     0,    74,    75,     0,    13,    14,    15,    16,
      17,    18,     4,    41,    76,    77,    78,    79,    80,    81,
     181,     0,     0,   183,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
       0,     0,     0,     0,   140,     0,     0,     0,     0,   109,
       0,     0,   201,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   128,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   129,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   205,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   164,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   167,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   112,   113,   114,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   112,
     113,   114,     0,     0,     0,     0,     0,     0,   121,   122,
     123,   124,   125
};

static const yytype_int16 yycheck[] =
{
       0,    40,     2,     3,    44,   162,    12,     7,     8,     9,
      10,    11,    12,   133,     5,     5,    37,     7,     8,    33,
      36,    53,    54,    44,    22,    31,    26,    12,    53,    37,
      69,    22,    24,     5,     5,    56,    44,    37,    38,     0,
       3,    33,     4,    24,    44,    24,     5,    47,    56,    65,
      54,   208,    52,    67,    33,    53,    56,    63,    20,     6,
     100,   181,    53,    53,   104,     9,    10,     3,    53,    22,
      14,    15,    16,    45,    45,    19,    22,    21,    35,   100,
      28,    29,    30,   104,    54,    55,    56,    57,    58,    59,
      60,    25,   100,     7,     8,     9,   104,    11,   137,     0,
     100,   141,     4,    25,   104,     3,     7,     8,     9,    53,
      11,    12,    47,    48,    49,    50,    51,    52,    24,     4,
     141,   161,     3,    11,    24,    26,    35,   127,     6,     3,
     130,     3,     3,   141,     4,     4,    22,    38,     6,    46,
     161,   141,     4,     3,   158,     4,    13,   187,     3,    22,
     183,     4,    18,   161,    17,     3,     3,    22,   158,   199,
       4,   161,     3,   203,    22,     4,   187,     4,     4,   209,
     210,     4,   186,    56,   216,   186,   163,   208,   199,   187,
      32,    -1,   203,    -1,    -1,    -1,   186,   187,   209,   210,
      -1,   199,    46,    23,    -1,   203,    50,    51,    -1,   199,
      -1,   209,   210,   203,    -1,    -1,    -1,    -1,    38,   209,
     210,    -1,    -1,    -1,    44,    45,    46,    23,    72,    73,
      74,    75,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    38,    28,    29,    30,    -1,    -1,    44,    45,
      -1,    95,    -1,    97,    39,    40,    41,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    23,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    38,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
     164,    -1,    -1,   167,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    22,
      -1,    -1,   196,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    22,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    22,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    22,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    28,    29,    30,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     7,     8,    53,    62,    63,    64,    65,    66,
      67,    69,    93,    47,    48,    49,    50,    51,    52,    91,
      93,    93,     0,    63,    63,    63,    93,    63,    22,    66,
      67,    93,    24,    33,    68,    22,    66,     3,    24,    70,
      91,    54,    92,     6,     3,    70,     9,    10,    14,    15,
      16,    19,    21,    66,    71,    72,    73,    74,    75,    77,
      80,    83,    86,    93,    94,    66,    22,    33,    68,    35,
      71,    22,    23,    38,    44,    45,    55,    56,    57,    58,
      59,    60,    77,    88,    89,    90,    92,    93,    94,    93,
      88,    88,    93,     4,    72,    25,     5,    45,    78,    70,
       3,    92,    68,     4,     3,    88,    88,    88,    88,    22,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     5,    11,    22,    22,
      24,    87,    88,    88,    46,    88,    71,    35,     6,    71,
      46,     3,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    12,    84,
      93,     3,     3,    93,    24,    76,    76,    24,    79,     4,
      68,     4,    71,    85,    92,    93,    22,    71,    82,    90,
      87,    88,     6,    88,    46,     4,    13,     3,     4,     4,
      20,    22,    76,    79,    85,    71,    18,    81,    22,     3,
       4,    88,    17,     3,    71,    22,    22,    71,     4,     3,
       3,     4,    82,    71,    71,     4,     4,     4,    81
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    63,    63,    63,    63,    64,    65,
      66,    67,    67,    68,    68,    68,    69,    69,    69,    69,
      70,    70,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    73,    74,    75,    75,    75,    76,    76,    77,
      78,    78,    79,    79,    80,    80,    80,    80,    81,    81,
      82,    82,    83,    83,    84,    84,    84,    84,    85,    85,
      86,    86,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    90,
      90,    90,    90,    90,    90,    90,    91,    91,    91,    91,
      91,    91,    92,    93,    94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     2,     2,     2,
       2,     4,     7,     0,     6,     3,     5,     8,     6,     7,
       0,     3,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     1,     0,     3,     2,
       2,     4,     0,     3,     7,    12,     6,    11,     0,     7,
       0,     6,     8,     6,     0,     1,     2,     4,     1,     1,
       1,     3,     0,     3,     3,     1,     1,     1,     1,     1,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 198 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.prog) = programBlock = new NProgram(*(yyvsp[0].dec_l));
#endif
}
#line 1569 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 205 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.dec_l) = new DeclarationList();
#endif
}
#line 1579 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 210 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
if( (yyvsp[-1].vard) != NULL) {
	(yyvsp[0].dec_l)->push_back((yyvsp[-1].vard));
	(yyval.dec_l) = (yyvsp[0].dec_l);
} else {
	yyerror("Ridi!");
}
#endif
}
#line 1594 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 220 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
if( (yyvsp[-1].funcd) != NULL) {
	(yyvsp[0].dec_l)->push_back((yyvsp[-1].funcd));
	(yyval.dec_l) = (yyvsp[0].dec_l);
} else {
	yyerror("Rede!");
}
#endif
}
#line 1609 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 231 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
if( start == NULL )
	start = (yyvsp[-1].ident); 
else
	yyerror("multiple definition of start");

(yyval.dec_l) = (yyvsp[0].dec_l);
#endif
}
#line 1624 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 241 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
if( finish == NULL )
	finish = (yyvsp[-1].ident);
else
	yyerror("multiple definition of finish");

(yyval.dec_l) = (yyvsp[0].dec_l);
#endif
}
#line 1639 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 255 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.ident) = (yyvsp[0].ident);
#endif
}
#line 1649 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 262 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.ident) = (yyvsp[0].ident);
#endif
}
#line 1659 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 270 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.vard) = new NVarDecl(*(yyvsp[-1].ident), *(yyvsp[0].tsd_l));
#endif
}
#line 1669 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 278 "Aparser.y" /* yacc.c:1646  */
    { 
#if TEST_MODE > TEST_PARSER 
//$3->emplace_back(new TsDecl($2, new NInteger(1))); 
//$$ = $3;
(yyvsp[-1].tsd_l)->push_back(new TsDecl((yyvsp[-2].token), 1)); (yyval.tsd_l) = (yyvsp[-1].tsd_l); 
#endif
}
#line 1681 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 285 "Aparser.y" /* yacc.c:1646  */
    { 
#if TEST_MODE > TEST_PARSER
//$6->emplace_back($2, *$4); $$ = $6;
(yyvsp[-1].tsd_l)->push_back(new TsDecl((yyvsp[-5].token), (yyvsp[-3].const_int)->value)); (yyval.tsd_l) = (yyvsp[-1].tsd_l); 
#endif
}
#line 1692 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 292 "Aparser.y" /* yacc.c:1646  */
    { 
#if TEST_MODE > TEST_PARSER
(yyval.tsd_l) = new TsDeclList(); 
#endif
}
#line 1702 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 297 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
//$6->emplace_back($2, *$4); $$ = $6;
(yyvsp[0].tsd_l)->push_back(new TsDecl((yyvsp[-4].token), (yyvsp[-2].const_int)->value)); (yyval.tsd_l) = (yyvsp[0].tsd_l); 
#endif
}
#line 1713 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 303 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
//$3->emplace_back($2, new NInteger(1)); $$ = $3;
(yyvsp[0].tsd_l)->push_back(new TsDecl((yyvsp[-1].token), 1)); (yyval.tsd_l) = (yyvsp[0].tsd_l); 
#endif
}
#line 1724 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 312 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.funcd) = new NFunctionDecl(*(new TsDeclList()), *(yyvsp[-4].ident), *(new VariableList()), *(yyvsp[-1].blk));
#endif
}
#line 1734 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 317 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[-4].var_l)->push_back((yyvsp[-5].vard)); (yyval.funcd) = new NFunctionDecl(*(yyvsp[-7].tsd_l), *(yyvsp[-6].ident), *(yyvsp[-4].var_l), *(yyvsp[-1].blk));
#endif
}
#line 1744 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 322 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.funcd) = new NFunctionDecl(*(yyvsp[-5].tsd_l), *(yyvsp[-4].ident), *(new VariableList()), *(yyvsp[-1].blk));
#endif
}
#line 1754 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 327 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[-4].var_l)->push_back((yyvsp[-5].vard)); (yyval.funcd) = new NFunctionDecl(*(new TsDeclList()), *(yyvsp[-6].ident), *(yyvsp[-4].var_l), *(yyvsp[-1].blk));
#endif
}
#line 1764 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 334 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.var_l) = new VariableList();
#endif
}
#line 1774 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 339 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.var_l) = (yyvsp[0].var_l); (yyval.var_l)->push_back((yyvsp[-1].vard));
#endif
}
#line 1784 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 347 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.blk) = new NBlock(*(yyvsp[0].stmt_l));
#endif
}
#line 1794 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 354 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt_l) = new StatementList();
#endif
}
#line 1804 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 359 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[0].stmt_l)->push_back((yyvsp[-1].stmt)); (yyval.stmt_l) = (yyvsp[0].stmt_l);
#endif
}
#line 1814 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 367 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt)=(yyvsp[0].ass);
#endif
}
#line 1824 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 372 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt)=(yyvsp[0].vard);
#endif
}
#line 1834 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 377 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt)=(yyvsp[0].func);
#endif
}
#line 1844 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 384 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt)=(yyvsp[0].ret);
#endif
}
#line 1854 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 389 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt) = new NBreak();
#endif
}
#line 1864 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 394 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt) = new NContinue();
#endif
}
#line 1874 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 402 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[0].expr_l)->push_back((yyvsp[-1].expr)); (yyval.ass) = new NAssignment(*(yyvsp[-3].lhs), *(yyvsp[0].expr_l));
#endif
}
#line 1884 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 410 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.lhs)=(yyvsp[0].ident);
#endif
}
#line 1894 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 415 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.lhs)=(yyvsp[0].arr);
#endif
}
#line 1904 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 420 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.lhs)=(yyvsp[0].vard);
#endif
}
#line 1914 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 427 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr_l) = new ExpressionList();
#endif
}
#line 1924 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 432 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[0].expr_l)->push_back((yyvsp[-1].expr)); (yyval.expr_l) = (yyvsp[0].expr_l);
#endif
}
#line 1934 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 440 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.func) = new NFuncCall(*(yyvsp[-1].ident), *(yyvsp[0].expr_l));
#endif
}
#line 1944 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 460 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr_l) = new ExpressionList();
#endif
}
#line 1954 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 465 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[-1].expr_l)->push_back((yyvsp[-2].expr)); (yyval.expr_l) = (yyvsp[-1].expr_l);
#endif
}
#line 1964 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 482 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr_l) = new ExpressionList();
#endif
}
#line 1974 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 487 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[0].expr_l)->push_back((yyvsp[-1].expr)); (yyval.expr_l) = (yyvsp[0].expr_l);
#endif
}
#line 1984 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 495 "Aparser.y" /* yacc.c:1646  */
    {
#if 0 && TEST_MODE > TEST_PARSER
//$7->ebl.emplace_back($2, $5); $$ = $7;
(yyvsp[0].token)->ebl.push_back(new ExprBlock((yyvsp[-5].expr), (yyvsp[-2].blk))); (yyval.token) = (yyvsp[0].token);
#endif
}
#line 1995 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 502 "Aparser.y" /* yacc.c:1646  */
    {
#if 0 && TEST_MODE > TEST_PARSER
//$7->ebl.emplace_back($2, $5);
//$7->ebl.emplace_back(new NBool(true), $11); $$ = $7;
(yyvsp[-5].token)->ebl.push_back(new ExprBlock((yyvsp[-10].expr), (yyvsp[-7].blk))); (yyvsp[-5].token)->ebl.push_back(new ExprBlock(new NBool(true), (yyvsp[-1].blk))); (yyval.token) = (yyvsp[-5].token);
//$7->bl.push_back($5); $7->bl.push_back($11); $7->el.push_back($2); $$ = $7;
#endif
}
#line 2008 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 510 "Aparser.y" /* yacc.c:1646  */
    {
#if 0 && TEST_MODE > TEST_PARSER
(yyvsp[-1].token)->Expression = (yyvsp[-4].expr); (yyval.token) = (yyvsp[-1].token);
#endif
}
#line 2018 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 516 "Aparser.y" /* yacc.c:1646  */
    {
#if 0 && TEST_MODE > TEST_PARSER
(yyvsp[-6].token)->ebl.push_back(new ExprBlock(new NBool(true), (yyvsp[-2].blk))); (yyvsp[-6].token)->Expression = (yyvsp[-9].expr); (yyval.token) = (yyvsp[-6].token);
//$5->ebl.emplace_back(new NBool(true), $9); $5->Expression = $2; $$ = $5;
#endif
}
#line 2029 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 523 "Aparser.y" /* yacc.c:1646  */
    {
#if 0 && TEST_MODE > TEST_PARSER
(yyval.token) = new NIf();
#endif
}
#line 2039 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 528 "Aparser.y" /* yacc.c:1646  */
    {
#if 0 && TEST_MODE > TEST_PARSER
//$7->ebl.emplace_back($2, $5); $$ = $7;
(yyvsp[0].token)->ebl.push_back(new ExprBlock((yyvsp[-5].expr), (yyvsp[-2].blk))); (yyval.token) = (yyvsp[0].token);
//$7->bl.push_back($5); $7->el.push_back($2); $$ = $7;
#endif
}
#line 2051 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 537 "Aparser.y" /* yacc.c:1646  */
    {
#if 0 && TEST_MODE > TEST_PARSER
(yyval.token) = new NCase();
#endif
}
#line 2061 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 542 "Aparser.y" /* yacc.c:1646  */
    {
#if 0 && TEST_MODE > TEST_PARSER
(yyvsp[0].token)->ebl.push_back(new ExprBlock((yyvsp[-5].const_val), (yyvsp[-2].blk))); (yyval.token) = (yyvsp[0].token);
//$6->ebl.emplace_back($1, $4); $$ = $6;
#endif
}
#line 2072 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 552 "Aparser.y" /* yacc.c:1646  */
    {
#if 0 && TEST_MODE > TEST_PARSER
(yyvsp[-4].token)->id = (yyvsp[-6].ident); (yyvsp[-4].token)->block = (yyvsp[-1].blk); (yyval.token) = (yyvsp[-4].token);
#endif
}
#line 2082 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 557 "Aparser.y" /* yacc.c:1646  */
    {
#if 0 && TEST_MODE > TEST_PARSER
(yyval.token) = new NWhile(*(yyvsp[-4].expr), *(yyvsp[-1].blk));
#endif
}
#line 2092 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 563 "Aparser.y" /* yacc.c:1646  */
    {
#if 0 && TEST_MODE > TEST_PARSER
(yyval.token) = new NFor(NULL, NULL, 1);
#endif
}
#line 2102 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 568 "Aparser.y" /* yacc.c:1646  */
    {
#if 0 && TEST_MODE > TEST_PARSER
(yyval.token) = new NFor((yyvsp[0].ident), NULL, 2);
#endif
}
#line 2112 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 573 "Aparser.y" /* yacc.c:1646  */
    {
#if 0 && TEST_MODE > TEST_PARSER
(yyval.token) = new NFor((yyvsp[0].token), NULL, 3);
#endif
}
#line 2122 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 578 "Aparser.y" /* yacc.c:1646  */
    {
#if 0 && TEST_MODE > TEST_PARSER && 0
(yyval.token) = new NFor((yyvsp[-2].token), (yyvsp[0].token), 4);
#endif
}
#line 2132 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 589 "Aparser.y" /* yacc.c:1646  */
    {
#if 0
(yyval.expr) = (yyvsp[0].const_int);
#endif
}
#line 2142 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 594 "Aparser.y" /* yacc.c:1646  */
    {
#if 0
(yyval.expr) = (yyvsp[0].ident);
#endif
}
#line 2152 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 618 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.ret) = new NReturn( *(new IdentifierList()) );
#endif
}
#line 2162 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 623 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[0].ident_l)->push_back((yyvsp[-1].ident)); (yyval.ret) = new NReturn(*(yyvsp[0].ident_l));
#endif
}
#line 2172 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 630 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.ident_l) = new IdentifierList();
#endif
}
#line 2182 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 635 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[0].ident_l)->push_back((yyvsp[-1].ident)); (yyval.ident_l) = (yyvsp[0].ident_l);
#endif
}
#line 2192 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 643 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr) = (yyvsp[-1].expr);
#endif
}
#line 2202 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 648 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
//$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
#line 2212 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 653 "Aparser.y" /* yacc.c:1646  */
    {
#if 0 && TEST_MODE > TEST_PARSER
//$$ = new NExpression(*$1);
#endif
}
#line 2222 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 658 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr) = (yyvsp[0].ident);
//$$ = new NExpression(*$1);
#endif
}
#line 2233 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 664 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr)=(yyvsp[0].arr);
#endif
}
#line 2243 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 669 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr) = (yyvsp[0].const_val);//$$ = new NExpression(*$1);
#endif
}
#line 2253 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 674 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr) = new NUnaryOp((yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2263 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 679 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr) = new NUnaryOp((yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2273 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 684 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr) = new NUnaryOp((yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2283 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 691 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2293 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 696 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2303 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 701 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2313 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 706 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2323 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 711 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2333 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 716 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2343 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 721 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2353 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 726 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2363 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 731 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2373 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 736 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2383 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 741 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2393 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 746 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2403 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 751 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2413 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 756 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2423 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 761 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2433 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 766 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2443 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 774 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_val) = (yyvsp[0].const_int);
#endif
}
#line 2453 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 779 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_val) = new NReal( atof((yyvsp[0].str)->c_str() ) ); delete (yyvsp[0].str);
#endif
}
#line 2463 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 784 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_val) = new NChar((yyvsp[0].str)->c_str()[0]); delete (yyvsp[0].str);
#endif
}
#line 2473 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 789 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_val) = new NBool(true); delete (yyvsp[0].str);
#endif
}
#line 2483 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 794 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_val) = new NBool(false); delete (yyvsp[0].str);
#endif
}
#line 2493 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 799 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_val) = new NString(*(yyvsp[0].str)); delete (yyvsp[0].str);
#endif
}
#line 2503 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 804 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_val) = new NLong( atol((yyvsp[0].str)->c_str()) ); delete (yyvsp[0].str);
#endif
}
#line 2513 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 814 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_int) = new NInteger( atoi((yyvsp[0].str)->c_str() ) ); delete (yyvsp[0].str);
#endif
}
#line 2523 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 821 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.ident) = new NIdentifier (*(yyvsp[0].str)); delete (yyvsp[0].str);
#endif
}
#line 2533 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 828 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.arr) = new NArrayExpr(*(yyvsp[-4].ident), *(yyvsp[-2].expr));
#endif
}
#line 2543 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2547 "parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 849 "Aparser.y" /* yacc.c:1906  */


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
