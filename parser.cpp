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
	NConst *const_int_val;
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
	NCaseDefault *caze_default;
	NCase *caze;
	CaseList *caze_l;
	NSwitch *swtch;
	NIf *iff;
	NForRangeOperand *forr_it_op;
	NForIterator *forr_it;
	NFor *forr;
	NWhile *whilee;
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

#line 274 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 291 "parser.cpp" /* yacc.c:358  */

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
#define YYLAST   465

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  222

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
       0,   211,   211,   218,   223,   233,   244,   254,   268,   275,
     283,   291,   298,   305,   310,   316,   325,   330,   335,   340,
     347,   352,   360,   367,   372,   380,   385,   390,   395,   400,
     405,   410,   415,   420,   425,   433,   441,   446,   451,   458,
     463,   471,   491,   496,   513,   518,   526,   534,   539,   544,
     557,   563,   573,   578,   588,   596,   608,   613,   618,   629,
     632,   654,   659,   666,   671,   679,   684,   689,   695,   701,
     706,   711,   716,   721,   728,   733,   738,   743,   748,   753,
     758,   763,   768,   773,   778,   783,   788,   793,   798,   803,
     811,   816,   821,   826,   831,   838,   838,   838,   838,   838,
     838,   842,   847,   852,   861,   868,   875
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
  "if_stmt", "if_stmt1", "case_stmt", "case_stmt1", "for_stmt",
  "while_stmt", "for_stmt1", "for_stmt2", "return_stmt", "id1", "expr",
  "bin_op", "const_val", "type", "const_int_val", "const_int", "id",
  "array", YY_NULLPTR
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

#define YYPACT_NINF -143

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-143)))

#define YYTABLE_NINF -39

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,    45,   -26,   -26,  -143,    29,  -143,    11,    11,    11,
     -26,    11,     8,  -143,  -143,  -143,  -143,  -143,  -143,    15,
    -143,  -143,  -143,  -143,  -143,  -143,     6,  -143,    40,    36,
    -143,    58,    45,    20,    76,    80,    36,    57,   -26,    67,
      18,  -143,    69,  -143,    57,    86,   272,   -26,  -143,  -143,
     272,   272,   -26,    90,   105,  -143,    57,  -143,    94,  -143,
    -143,  -143,  -143,  -143,  -143,    12,  -143,    36,   108,    20,
    -143,   107,   130,   132,   272,   272,   272,   272,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,   328,  -143,  -143,  -143,  -143,
      30,  -143,   134,   348,   368,   119,  -143,  -143,   272,   230,
     172,  -143,  -143,    57,   111,   141,  -143,    57,  -143,    84,
    -143,   307,   145,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
      24,   146,   147,   -26,  -143,   406,   406,  -143,   424,   149,
     107,  -143,   150,  -143,    57,   226,   226,  -143,  -143,  -143,
     268,   268,    99,    99,    99,    99,    84,    84,    25,    25,
      25,    -8,   129,  -143,    57,    62,   119,   272,  -143,   151,
     272,   109,  -143,  -143,  -143,   152,   153,  -143,  -143,   155,
     158,    21,   137,  -143,   406,  -143,   424,  -143,  -143,    -8,
      57,    32,  -143,   156,   160,  -143,  -143,  -143,   168,   157,
     272,  -143,   170,    57,  -143,   174,   388,    57,   178,    57,
     180,   184,    62,   189,    57,   190,  -143,  -143,   192,  -143,
      32,  -143
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,   105,     0,     2,     3,     3,     3,
       0,     3,     0,    95,    96,    97,    98,    99,   100,    13,
       8,     9,     1,     6,     7,     4,     0,     5,     0,    20,
      10,     0,     0,     0,     0,     0,    20,    23,     0,     0,
      13,   104,     0,    11,    23,     0,     0,     0,    33,    34,
       0,     0,    61,    26,     0,    22,    23,    25,     0,    27,
      28,    29,    30,    31,    32,    36,    37,    20,     0,     0,
      15,    13,     0,     0,     0,     0,     0,     0,    91,   102,
      94,   103,    92,    93,    67,     0,    66,    70,    90,   101,
      68,    69,     0,     0,     0,    63,    16,    24,     0,     0,
       0,    41,    21,    23,     0,     0,    18,    23,    72,    71,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    39,    39,    42,    44,     0,
      13,    12,     0,    65,    23,    82,    83,    80,    81,    79,
      84,    85,    88,    87,    89,    86,    74,    75,    76,    77,
      78,     0,     0,    56,    23,    52,    63,     0,    35,     0,
       0,     0,    19,    14,    17,     0,    57,    59,    60,     0,
       0,     0,     0,    64,    39,   106,    44,    43,    55,     0,
      23,    47,    50,     0,     0,    40,    45,    58,     0,     0,
       0,    46,     0,    23,    54,     0,     0,    23,     0,    23,
       0,     0,    52,     0,    23,     0,    53,    48,     0,    51,
      47,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,    91,  -143,  -143,    79,    -7,   -39,  -143,    -5,
     -38,   148,  -143,  -143,  -143,  -116,   -23,  -143,    16,  -143,
     -15,  -143,    -6,  -143,  -143,  -143,    19,  -143,    31,   124,
    -143,  -143,   179,  -142,   -29,     0,   -22
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    53,    10,    34,    11,    39,
      54,    55,    56,    57,    58,   168,    84,   101,   171,    60,
     201,    61,   181,    62,    63,   162,   176,    64,   134,   136,
      86,    87,    19,    88,    89,    90,    91
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    70,    20,    21,    42,    30,    72,    12,    12,    12,
      26,    12,    31,     1,    59,    66,     1,    99,     2,     3,
     169,    59,    66,   182,    30,   192,    31,     4,    35,    22,
      28,    45,   105,    59,    66,   129,   161,    65,    31,    32,
     104,   193,    32,    37,    65,     4,    41,    92,    33,   199,
     200,    69,    95,   115,   116,   117,    65,   100,    30,     4,
      38,     4,   102,     1,     4,   139,    46,    47,   195,   142,
     182,    48,    49,    50,    41,   100,    51,     4,    52,     9,
      59,    66,    43,    44,    59,    66,     9,     9,     9,    68,
       9,    29,    13,    14,    15,    16,    17,    18,    23,    24,
      25,   173,    27,    65,    71,    36,   175,    65,    73,    96,
       4,   103,   115,   116,   117,   -38,    41,    67,    79,    98,
      81,    59,    66,   126,   127,   128,   180,   115,   116,   117,
     163,    32,   177,   166,   106,   107,   124,   125,   126,   127,
     128,    59,    66,   133,    65,   130,   140,   141,   144,   164,
     165,   179,   198,   172,   174,   187,   188,   185,   190,   194,
     177,   178,   191,   203,    65,   208,   189,    59,    66,   211,
      85,   213,   204,   207,    93,    94,   218,   209,   202,   205,
      59,    66,   212,   214,    59,    66,    59,    66,   215,   178,
      65,    59,    66,   217,   219,    74,   220,   183,   108,   109,
     110,   111,   196,    65,    97,   221,   216,    65,   197,    65,
      75,    40,     0,     0,    65,     0,    76,    77,   137,     0,
       0,     0,   135,     0,   138,     4,    41,    78,    79,    80,
      81,    82,    83,     0,     0,     0,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,    74,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    75,     0,
       0,     0,     0,     0,    76,    77,     0,    13,    14,    15,
      16,    17,    18,     4,    41,    78,    79,    80,    81,    82,
      83,   184,     0,     0,   186,    74,   115,   116,   117,     0,
       0,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      75,     0,     0,     0,     0,     0,    76,    77,     0,     0,
       0,     0,     0,     0,   206,     4,    41,    78,    79,    80,
      81,    82,    83,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,     0,
     112,     0,     0,   143,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     131,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     132,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     210,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     167,     0,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   170,     0,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128
};

static const yytype_int16 yycheck[] =
{
       0,    40,     2,     3,    33,    12,    44,     7,     8,     9,
      10,    11,    12,     5,    37,    37,     5,     5,     7,     8,
     136,    44,    44,   165,    31,     4,    26,    53,    22,     0,
      22,    36,    71,    56,    56,     5,    12,    37,    38,    24,
      69,    20,    24,     3,    44,    53,    54,    47,    33,    17,
      18,    33,    52,    28,    29,    30,    56,    45,    65,    53,
      24,    53,    67,     5,    53,   103,     9,    10,   184,   107,
     212,    14,    15,    16,    54,    45,    19,    53,    21,     0,
     103,   103,     6,     3,   107,   107,     7,     8,     9,    22,
      11,    12,    47,    48,    49,    50,    51,    52,     7,     8,
       9,   140,    11,   103,    35,    26,   144,   107,    22,     4,
      53,     3,    28,    29,    30,    25,    54,    38,    56,    25,
      58,   144,   144,    39,    40,    41,   164,    28,    29,    30,
     130,    24,   161,   133,     4,     3,    37,    38,    39,    40,
      41,   164,   164,    24,   144,    11,    35,     6,     3,     3,
       3,    22,   190,     4,     4,    46,     4,     6,     3,    22,
     189,   161,     4,     3,   164,   203,    13,   190,   190,   207,
      46,   209,     4,     3,    50,    51,   214,     3,    22,    22,
     203,   203,     4,     3,   207,   207,   209,   209,     4,   189,
     190,   214,   214,     4,     4,    23,     4,   166,    74,    75,
      76,    77,   186,   203,    56,   220,   212,   207,   189,   209,
      38,    32,    -1,    -1,   214,    -1,    44,    45,    46,    -1,
      -1,    -1,    98,    -1,   100,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    23,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,   167,    -1,    -1,   170,    23,    28,    29,    30,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,   200,    53,    54,    55,    56,    57,
      58,    59,    60,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      22,    -1,    -1,    46,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      22,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      22,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      22,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     7,     8,    53,    62,    63,    64,    65,    66,
      67,    69,    96,    47,    48,    49,    50,    51,    52,    93,
      96,    96,     0,    63,    63,    63,    96,    63,    22,    66,
      67,    96,    24,    33,    68,    22,    66,     3,    24,    70,
      93,    54,    95,     6,     3,    70,     9,    10,    14,    15,
      16,    19,    21,    66,    71,    72,    73,    74,    75,    77,
      80,    82,    84,    85,    88,    96,    97,    66,    22,    33,
      68,    35,    71,    22,    23,    38,    44,    45,    55,    56,
      57,    58,    59,    60,    77,    90,    91,    92,    94,    95,
      96,    97,    96,    90,    90,    96,     4,    72,    25,     5,
      45,    78,    70,     3,    95,    68,     4,     3,    90,    90,
      90,    90,    22,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     5,
      11,    22,    22,    24,    89,    90,    90,    46,    90,    71,
      35,     6,    71,    46,     3,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    12,    86,    96,     3,     3,    96,    24,    76,    76,
      24,    79,     4,    68,     4,    71,    87,    95,    96,    22,
      71,    83,    94,    89,    90,     6,    90,    46,     4,    13,
       3,     4,     4,    20,    22,    76,    79,    87,    71,    17,
      18,    81,    22,     3,     4,    22,    90,     3,    71,     3,
      22,    71,     4,    71,     3,     4,    83,     4,    71,     4,
       4,    81
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    63,    63,    63,    63,    64,    65,
      66,    67,    67,    68,    68,    68,    69,    69,    69,    69,
      70,    70,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    74,    75,    75,    75,    76,
      76,    77,    78,    78,    79,    79,    80,    81,    81,    81,
      82,    82,    83,    83,    84,    85,    86,    86,    86,    87,
      87,    88,    88,    89,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      92,    92,    92,    92,    92,    93,    93,    93,    93,    93,
      93,    94,    94,    94,    95,    96,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     2,     2,     2,
       2,     4,     7,     0,     6,     3,     5,     8,     6,     7,
       0,     3,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     0,
       3,     2,     2,     4,     0,     3,     7,     0,     5,     7,
       6,    11,     0,     6,     8,     6,     1,     2,     4,     1,
       1,     1,     3,     0,     3,     3,     1,     1,     1,     1,
       1,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5
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
#line 211 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.prog) = programBlock = new NProgram(*(yyvsp[0].dec_l), *start, finish);
#endif
}
#line 1579 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 218 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.dec_l) = new DeclarationList();
#endif
}
#line 1589 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 223 "Aparser.y" /* yacc.c:1646  */
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
#line 1604 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 233 "Aparser.y" /* yacc.c:1646  */
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
#line 1619 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 244 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
if( start == NULL )
	start = (yyvsp[-1].ident); 
else
	yyerror("multiple definition of start");

(yyval.dec_l) = (yyvsp[0].dec_l);
#endif
}
#line 1634 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 254 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
if( finish == NULL )
	finish = (yyvsp[-1].ident);
else
	yyerror("multiple definition of finish");

(yyval.dec_l) = (yyvsp[0].dec_l);
#endif
}
#line 1649 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 268 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.ident) = (yyvsp[0].ident);
#endif
}
#line 1659 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 275 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.ident) = (yyvsp[0].ident);
#endif
}
#line 1669 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 283 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.vard) = new NVarDecl(*(yyvsp[-1].ident), *(yyvsp[0].tsd_l));
#endif
}
#line 1679 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 291 "Aparser.y" /* yacc.c:1646  */
    { 
#if TEST_MODE > TEST_PARSER 
//$3->emplace_back(new TsDecl($2, new NInteger(1))); 
//$$ = $3;
(yyvsp[-1].tsd_l)->push_back(new TsDecl((yyvsp[-2].token), 1)); (yyval.tsd_l) = (yyvsp[-1].tsd_l); 
#endif
}
#line 1691 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 298 "Aparser.y" /* yacc.c:1646  */
    { 
#if TEST_MODE > TEST_PARSER
//$6->emplace_back($2, *$4); $$ = $6;
(yyvsp[-1].tsd_l)->push_back(new TsDecl((yyvsp[-5].token), (yyvsp[-3].const_int)->value)); (yyval.tsd_l) = (yyvsp[-1].tsd_l); 
#endif
}
#line 1702 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 305 "Aparser.y" /* yacc.c:1646  */
    { 
#if TEST_MODE > TEST_PARSER
(yyval.tsd_l) = new TsDeclList(); 
#endif
}
#line 1712 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 310 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
//$6->emplace_back($2, *$4); $$ = $6;
(yyvsp[0].tsd_l)->push_back(new TsDecl((yyvsp[-4].token), (yyvsp[-2].const_int)->value)); (yyval.tsd_l) = (yyvsp[0].tsd_l); 
#endif
}
#line 1723 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 316 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
//$3->emplace_back($2, new NInteger(1)); $$ = $3;
(yyvsp[0].tsd_l)->push_back(new TsDecl((yyvsp[-1].token), 1)); (yyval.tsd_l) = (yyvsp[0].tsd_l); 
#endif
}
#line 1734 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 325 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.funcd) = new NFunctionDecl(*(new TsDeclList()), *(yyvsp[-4].ident), *(new VariableList()), *(yyvsp[-1].blk));
#endif
}
#line 1744 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 330 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[-4].var_l)->push_back((yyvsp[-5].vard)); (yyval.funcd) = new NFunctionDecl(*(yyvsp[-7].tsd_l), *(yyvsp[-6].ident), *(yyvsp[-4].var_l), *(yyvsp[-1].blk));
#endif
}
#line 1754 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 335 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.funcd) = new NFunctionDecl(*(yyvsp[-5].tsd_l), *(yyvsp[-4].ident), *(new VariableList()), *(yyvsp[-1].blk));
#endif
}
#line 1764 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 340 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[-4].var_l)->push_back((yyvsp[-5].vard)); (yyval.funcd) = new NFunctionDecl(*(new TsDeclList()), *(yyvsp[-6].ident), *(yyvsp[-4].var_l), *(yyvsp[-1].blk));
#endif
}
#line 1774 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 347 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.var_l) = new VariableList();
#endif
}
#line 1784 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 352 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.var_l) = (yyvsp[0].var_l); (yyval.var_l)->push_back((yyvsp[-1].vard));
#endif
}
#line 1794 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 360 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.blk) = new NBlock(*(yyvsp[0].stmt_l));
#endif
}
#line 1804 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 367 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt_l) = new StatementList();
#endif
}
#line 1814 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 372 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[0].stmt_l)->push_back((yyvsp[-1].stmt)); (yyval.stmt_l) = (yyvsp[0].stmt_l);
#endif
}
#line 1824 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 380 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt)=(yyvsp[0].ass);
#endif
}
#line 1834 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 385 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt)=(yyvsp[0].vard);
#endif
}
#line 1844 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 390 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt)=(yyvsp[0].func);
#endif
}
#line 1854 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 395 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt)=(yyvsp[0].iff);
#endif
}
#line 1864 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 400 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt)=(yyvsp[0].swtch);
#endif
}
#line 1874 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 405 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt)=(yyvsp[0].forr);
#endif
}
#line 1884 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 410 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt)=(yyvsp[0].whilee);
#endif
}
#line 1894 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 415 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt)=(yyvsp[0].ret);
#endif
}
#line 1904 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 420 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt) = new NBreak();
#endif
}
#line 1914 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 425 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.stmt) = new NContinue();
#endif
}
#line 1924 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 433 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[0].expr_l)->push_back((yyvsp[-1].expr)); (yyval.ass) = new NAssignment(*(yyvsp[-3].lhs), *(yyvsp[0].expr_l));
#endif
}
#line 1934 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 441 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.lhs)=(yyvsp[0].ident);
#endif
}
#line 1944 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 446 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.lhs)=(yyvsp[0].arr);
#endif
}
#line 1954 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 451 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.lhs)=(yyvsp[0].vard);
#endif
}
#line 1964 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 458 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr_l) = new ExpressionList();
#endif
}
#line 1974 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 463 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[0].expr_l)->push_back((yyvsp[-1].expr)); (yyval.expr_l) = (yyvsp[0].expr_l);
#endif
}
#line 1984 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 471 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.func) = new NFuncCall(*(yyvsp[-1].ident), *(yyvsp[0].expr_l));
#endif
}
#line 1994 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 491 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr_l) = new ExpressionList();
#endif
}
#line 2004 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 496 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[-1].expr_l)->push_back((yyvsp[-2].expr)); (yyval.expr_l) = (yyvsp[-1].expr_l);
#endif
}
#line 2014 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 513 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr_l) = new ExpressionList();
#endif
}
#line 2024 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 518 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[0].expr_l)->push_back((yyvsp[-1].expr)); (yyval.expr_l) = (yyvsp[0].expr_l);
#endif
}
#line 2034 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 526 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.iff) = new NIf(*(yyvsp[-5].expr), *(yyvsp[-2].blk), *(yyvsp[0].blk));
#endif
}
#line 2044 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 534 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.blk) = new NBlock();
#endif
}
#line 2054 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 539 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.blk) = (yyvsp[-1].blk);
#endif
}
#line 2064 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 544 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
/*
StatementList& sl = *(new StatementList());
sl.push_back(new NIf(*$2, *$5, *$7));
$$ = new NBlock(sl);
*/
(yyval.blk) = new NBlock(*(new NIf(*(yyvsp[-5].expr), *(yyvsp[-2].blk), *(yyvsp[0].blk))));
#endif
}
#line 2079 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 557 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
//$5->Expression = $2; $$ = $5;
(yyval.swtch) = new NSwitch(*(yyvsp[-4].expr), *(yyvsp[-1].caze_l), *(new NCaseDefault()));
#endif
}
#line 2090 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 564 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.swtch) = new NSwitch(*(yyvsp[-9].expr), *(yyvsp[-6].caze_l), *(new NCaseDefault(*(yyvsp[-2].blk))));
//$5->ebl.push_back(new ExprBlock(new NBool(true), $9)); $5->Expression = $2; $$ = $5;
//$5->ebl.emplace_back(new NBool(true), $9); $5->Expression = $2; $$ = $5;
#endif
}
#line 2102 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 573 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.caze_l) = new CaseList();
#endif
}
#line 2112 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 578 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[0].caze_l)->push_back(new NCase(*(yyvsp[-5].const_int_val), *(yyvsp[-2].blk))); (yyval.caze_l) = (yyvsp[0].caze_l);
//$6->ebl.emplace_back($1, $4); $$ = $6;
#endif
}
#line 2123 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 588 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.forr) = new NFor(*(yyvsp[-6].ident), *(yyvsp[-4].forr_it), *(yyvsp[-1].blk));
#endif
}
#line 2133 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 596 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.whilee) = new NWhile(*(yyvsp[-4].expr), *(yyvsp[-1].blk));
#endif
}
#line 2143 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 608 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.forr_it) = new NForEach(*(yyvsp[0].ident));
#endif
}
#line 2153 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 613 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.forr_it) = new NForRange(*(new NInteger(0)), *(yyvsp[0].forr_it_op));
#endif
}
#line 2163 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 618 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.forr_it) = new NForRange(*(yyvsp[-2].forr_it_op), *(yyvsp[0].forr_it_op));
#endif
}
#line 2173 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 629 "Aparser.y" /* yacc.c:1646  */
    {
(yyval.forr_it_op) = (yyvsp[0].const_int);
}
#line 2181 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 632 "Aparser.y" /* yacc.c:1646  */
    {
(yyval.forr_it_op) = (yyvsp[0].ident);
}
#line 2189 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 654 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.ret) = new NReturn( *(new IdentifierList()) );
#endif
}
#line 2199 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 659 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[0].ident_l)->push_back((yyvsp[-1].ident)); (yyval.ret) = new NReturn(*(yyvsp[0].ident_l));
#endif
}
#line 2209 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 666 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.ident_l) = new IdentifierList();
#endif
}
#line 2219 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 671 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyvsp[0].ident_l)->push_back((yyvsp[-1].ident)); (yyval.ident_l) = (yyvsp[0].ident_l);
#endif
}
#line 2229 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 679 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr) = (yyvsp[-1].expr);
#endif
}
#line 2239 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 684 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
//$$ = new NBinaryOp(*$1, $2, *$3);
#endif
}
#line 2249 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 689 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
//$$ = new NExpression(*$1);
(yyval.expr) = (yyvsp[0].func);
#endif
}
#line 2260 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 695 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr) = (yyvsp[0].ident);
//$$ = new NExpression(*$1);
#endif
}
#line 2271 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 701 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr)=(yyvsp[0].arr);
#endif
}
#line 2281 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 706 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr) = (yyvsp[0].const_val);//$$ = new NExpression(*$1);
#endif
}
#line 2291 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 711 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr) = new NUnaryOp((yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2301 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 716 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr) = new NUnaryOp((yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2311 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 721 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.expr) = new NUnaryOp((yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2321 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 728 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2331 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 733 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2341 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 738 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2351 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 743 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2361 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 748 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2371 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 753 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2381 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 758 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2391 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 763 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2401 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 768 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2411 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 773 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2421 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 778 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2431 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 783 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2441 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 788 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2451 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 793 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2461 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 798 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2471 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 803 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.bin_op) = new NBinaryOp(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr));
#endif
}
#line 2481 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 811 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_val) = (yyvsp[0].const_int_val);
#endif
}
#line 2491 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 816 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_val) = new NReal( atof((yyvsp[0].str)->c_str() ) ); delete (yyvsp[0].str);
#endif
}
#line 2501 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 821 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_val) = new NBool(true); delete (yyvsp[0].str);
#endif
}
#line 2511 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 826 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_val) = new NBool(false); delete (yyvsp[0].str);
#endif
}
#line 2521 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 831 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_val) = new NString(*(yyvsp[0].str)); delete (yyvsp[0].str);
#endif
}
#line 2531 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 842 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_int_val) = (yyvsp[0].const_int);
#endif
}
#line 2541 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 847 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_int_val) = new NChar((yyvsp[0].str)->c_str()[1]); delete (yyvsp[0].str);
#endif
}
#line 2551 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 852 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_int_val) = new NLong( atol((yyvsp[0].str)->c_str()) ); delete (yyvsp[0].str);
#endif
}
#line 2561 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 861 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.const_int) = new NInteger( atoi((yyvsp[0].str)->c_str() ) ); delete (yyvsp[0].str);
#endif
}
#line 2571 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 868 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.ident) = new NIdentifier (*(yyvsp[0].str)); delete (yyvsp[0].str);
#endif
}
#line 2581 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 875 "Aparser.y" /* yacc.c:1646  */
    {
#if TEST_MODE > TEST_PARSER
(yyval.arr) = new NArrayExpr(*(yyvsp[-4].ident), *(yyvsp[-2].expr));
#endif
}
#line 2591 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2595 "parser.cpp" /* yacc.c:1646  */
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
#line 896 "Aparser.y" /* yacc.c:1906  */

#if 0
#include<cctype>
#include<cstring>
int count=0;
extern int yyparse();
using namespace std;
//void createCoreFunctions(CodeGenContext& context);

int main(int argc, char **argv)
{
	yyparse();
	cout << programBlock << endl;
    // see http://comments.gmane.org/gmane.comp.compilers.llvm.devel/33877
	/*InitializeNativeTarget();
	InitializeNativeTargetAsmPrinter();
	InitializeNativeTargetAsmParser();
	CodeGenContext context;
	createCoreFunctions(context);
	context.generateCode(*programBlock);
	context.runCode();*/

//	programBlock->codeGen();	
	return 0;
}



#if TEST_MODE < TEST_NONE && TEST_MODE > TEST_SCANNER
#include "codegen.h"
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
	InitializeNativeTarget();
	InitializeNativeTargetAsmPrinter();
	InitializeNativeTargetAsmParser();
	CodeGenContext context;

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
#endif
