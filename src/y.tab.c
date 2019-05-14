/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENT = 258,
     CHARLIT = 259,
     STRING = 260,
     NUMBER = 261,
     TOKEOF = 262,
     INDSEL = 263,
     PLUSPLUS = 264,
     MINUSMINUS = 265,
     SHL = 266,
     SHR = 267,
     LTEQ = 268,
     GTEQ = 269,
     EQEQ = 270,
     NOTEQ = 271,
     LOGAND = 272,
     LOGOR = 273,
     ELLIPSIS = 274,
     SIZEOF = 275,
     AUTO = 276,
     BREAK = 277,
     CASE = 278,
     CONST = 279,
     CONTINUE = 280,
     DEFAULT = 281,
     DO = 282,
     ENUM = 283,
     EXTERN = 284,
     FOR = 285,
     GOTO = 286,
     INLINE = 287,
     REGISTER = 288,
     RESTRICT = 289,
     RETURN = 290,
     STATIC = 291,
     STRUCT = 292,
     SWITCH = 293,
     TYPEDEF = 294,
     UNION = 295,
     VOID = 296,
     VOLATILE = 297,
     WHILE = 298,
     _BOOL = 299,
     _COMPLEX = 300,
     _IMAGINARY = 301,
     IF = 302,
     ELSE = 303,
     FLOAT = 304,
     DOUBLE = 305,
     CHAR = 306,
     INT = 307,
     LONG = 308,
     SHORT = 309,
     SIGNED = 310,
     UNSIGNED = 311,
     OREQ = 312,
     XOREQ = 313,
     ANDEQ = 314,
     SHREQ = 315,
     SHLEQ = 316,
     MODEQ = 317,
     DIVEQ = 318,
     TIMESEQ = 319,
     MINUSEQ = 320,
     PLUSEQ = 321
   };
#endif
/* Tokens.  */
#define IDENT 258
#define CHARLIT 259
#define STRING 260
#define NUMBER 261
#define TOKEOF 262
#define INDSEL 263
#define PLUSPLUS 264
#define MINUSMINUS 265
#define SHL 266
#define SHR 267
#define LTEQ 268
#define GTEQ 269
#define EQEQ 270
#define NOTEQ 271
#define LOGAND 272
#define LOGOR 273
#define ELLIPSIS 274
#define SIZEOF 275
#define AUTO 276
#define BREAK 277
#define CASE 278
#define CONST 279
#define CONTINUE 280
#define DEFAULT 281
#define DO 282
#define ENUM 283
#define EXTERN 284
#define FOR 285
#define GOTO 286
#define INLINE 287
#define REGISTER 288
#define RESTRICT 289
#define RETURN 290
#define STATIC 291
#define STRUCT 292
#define SWITCH 293
#define TYPEDEF 294
#define UNION 295
#define VOID 296
#define VOLATILE 297
#define WHILE 298
#define _BOOL 299
#define _COMPLEX 300
#define _IMAGINARY 301
#define IF 302
#define ELSE 303
#define FLOAT 304
#define DOUBLE 305
#define CHAR 306
#define INT 307
#define LONG 308
#define SHORT 309
#define SIGNED 310
#define UNSIGNED 311
#define OREQ 312
#define XOREQ 313
#define ANDEQ 314
#define SHREQ 315
#define SHLEQ 316
#define MODEQ 317
#define DIVEQ 318
#define TIMESEQ 319
#define MINUSEQ 320
#define PLUSEQ 321




/* Copy the first part of user declarations.  */
#line 3 "src/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <yystype.h>
#include <ast.h>
#include <symtab.h>

#include "y.tab.h"

int yylex();
int yyparse();
int yyerror();
int yywarn();
struct ASTNODE *create_node(int nodetype);
void populate_num_node(struct ASTNODE *node, struct num_lit *number);
void print_node(struct ASTNODE *node, int depth);

extern struct scope *current_scope;
extern int line;
extern char filename[64];
struct ASTNODE *head, *tail, *ugly_stitch;
int entering_function;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 27 "src/parser.y"
{
	struct ASTNODE *node;
	char *ident;
	char char_lit;
	struct string_lit string_lit;
	struct num_lit num_lit;
}
/* Line 193 of yacc.c.  */
#line 260 "src/y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 273 "src/y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  87
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1832

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  124
/* YYNRULES -- Number of rules.  */
#define YYNRULES  311
/* YYNRULES -- Number of states.  */
#define YYNSTATES  484

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    88,     2,     2,     2,    54,    49,     2,
      83,    84,    55,    53,    79,    52,    87,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    82,    78,
      50,    67,    51,    90,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    85,     2,    86,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    80,    47,    81,    89,     2,     2,     2,
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
      45,    46,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    16,    19,    21,
      24,    26,    29,    31,    34,    36,    38,    42,    44,    48,
      50,    52,    54,    56,    58,    60,    62,    64,    66,    68,
      70,    72,    74,    76,    83,    89,    95,   100,   103,   105,
     107,   111,   113,   117,   119,   121,   123,   126,   128,   131,
     134,   138,   140,   142,   144,   146,   148,   151,   154,   158,
     160,   163,   165,   167,   170,   173,   177,   180,   184,   188,
     193,   196,   200,   203,   205,   208,   212,   216,   221,   223,
     226,   229,   231,   233,   235,   241,   246,   248,   251,   253,
     256,   260,   262,   266,   268,   270,   272,   276,   279,   281,
     283,   289,   294,   297,   299,   301,   304,   306,   308,   311,
     313,   315,   318,   322,   327,   331,   335,   338,   343,   347,
     351,   354,   356,   358,   360,   362,   364,   366,   370,   372,
     374,   376,   379,   382,   384,   388,   391,   396,   400,   402,
     407,   412,   416,   418,   422,   424,   428,   431,   434,   436,
     440,   442,   447,   451,   453,   457,   460,   465,   468,   470,
     473,   477,   480,   481,   485,   489,   492,   495,   497,   499,
     502,   504,   506,   508,   510,   512,   514,   516,   518,   520,
     522,   524,   527,   531,   533,   535,   537,   538,   543,   546,
     548,   551,   553,   555,   557,   563,   571,   573,   575,   577,
     585,   591,   595,   603,   610,   617,   623,   630,   636,   642,
     647,   649,   652,   658,   661,   663,   666,   669,   673,   676,
     680,   682,   684,   686,   688,   690,   692,   694,   698,   700,
     702,   704,   706,   708,   710,   712,   717,   721,   725,   730,
     731,   733,   737,   740,   743,   751,   758,   760,   765,   767,
     769,   771,   773,   775,   777,   779,   781,   783,   785,   788,
     793,   796,   799,   802,   805,   808,   811,   814,   817,   819,
     823,   827,   831,   833,   837,   841,   843,   847,   851,   853,
     857,   861,   865,   869,   871,   875,   879,   881,   885,   887,
     891,   893,   897,   899,   903,   905,   909,   911,   917,   919,
     923,   927,   931,   935,   939,   943,   947,   951,   955,   959,
     963,   965
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      92,     0,    -1,    93,    -1,    92,    93,    -1,    94,    -1,
     152,    -1,    95,    96,    78,    -1,    98,    95,    -1,    98,
      -1,   100,    95,    -1,   100,    -1,   134,    95,    -1,   134,
      -1,    99,    95,    -1,    99,    -1,    97,    -1,    96,    79,
      97,    -1,   135,    -1,   135,    67,   147,    -1,    21,    -1,
      29,    -1,    33,    -1,    36,    -1,    39,    -1,    32,    -1,
     101,    -1,   108,    -1,   110,    -1,   115,    -1,   125,    -1,
     129,    -1,   102,    -1,   103,    -1,    28,   104,    80,   105,
      79,    81,    -1,    28,    80,   105,    79,    81,    -1,    28,
     104,    80,   105,    81,    -1,    28,    80,   105,    81,    -1,
      28,   104,    -1,     3,    -1,   106,    -1,   105,    79,   106,
      -1,   107,    -1,   107,    67,   213,    -1,     3,    -1,    59,
      -1,    60,    -1,    63,    60,    -1,   109,    -1,    59,    45,
      -1,    60,    45,    -1,    63,    60,    45,    -1,   111,    -1,
     112,    -1,   113,    -1,   114,    -1,    64,    -1,    64,    62,
      -1,    65,    64,    -1,    65,    64,    62,    -1,    62,    -1,
      65,    62,    -1,    65,    -1,    63,    -1,    63,    62,    -1,
      65,    63,    -1,    65,    63,    62,    -1,    63,    63,    -1,
      63,    63,    62,    -1,    65,    63,    63,    -1,    65,    63,
      63,    62,    -1,    66,    64,    -1,    66,    64,    62,    -1,
      66,    62,    -1,    66,    -1,    66,    63,    -1,    66,    63,
      62,    -1,    66,    63,    63,    -1,    66,    63,    63,    62,
      -1,    61,    -1,    65,    61,    -1,    66,    61,    -1,    44,
      -1,   116,    -1,   118,    -1,    37,   117,    80,   119,    81,
      -1,    37,    80,   119,    81,    -1,     3,    -1,    37,   117,
      -1,   120,    -1,   119,   120,    -1,   100,   121,    78,    -1,
     122,    -1,   121,    79,   122,    -1,   123,    -1,   124,    -1,
     135,    -1,   135,    82,   141,    -1,    82,   141,    -1,   126,
      -1,   127,    -1,    40,   128,    80,   119,    81,    -1,    40,
      80,   119,    81,    -1,    40,   128,    -1,     3,    -1,    41,
      -1,    95,   131,    -1,    95,    -1,   139,    -1,   139,   133,
      -1,   133,    -1,   134,    -1,   132,   134,    -1,    83,   131,
      84,    -1,   133,    85,   141,    86,    -1,    85,   141,    86,
      -1,   133,    85,    86,    -1,    85,    86,    -1,   133,    83,
     143,    84,    -1,    83,   143,    84,    -1,   133,    83,    84,
      -1,    83,    84,    -1,    24,    -1,    42,    -1,    34,    -1,
     138,    -1,   136,    -1,   137,    -1,    83,   135,    84,    -1,
     142,    -1,   140,    -1,     3,    -1,   139,   136,    -1,    55,
     132,    -1,    55,    -1,    55,   132,   139,    -1,    55,   139,
      -1,   136,    85,     6,    86,    -1,   136,    85,    86,    -1,
     212,    -1,   136,    83,   143,    84,    -1,   136,    83,   146,
      84,    -1,   136,    83,    84,    -1,   144,    -1,   144,    79,
      19,    -1,   145,    -1,   144,    79,   145,    -1,    95,   135,
      -1,    95,   131,    -1,     3,    -1,   144,    79,     3,    -1,
     213,    -1,    80,   148,    79,    81,    -1,    80,   148,    81,
      -1,   147,    -1,   148,    79,   147,    -1,   149,   147,    -1,
     148,    79,   149,   147,    -1,   150,    67,    -1,   151,    -1,
     150,   151,    -1,    85,   141,    86,    -1,    87,     3,    -1,
      -1,   154,   153,   160,    -1,    95,   135,   155,    -1,    95,
     135,    -1,   135,   155,    -1,   135,    -1,    94,    -1,   155,
      94,    -1,   157,    -1,   158,    -1,   160,    -1,   164,    -1,
     166,    -1,   172,    -1,   175,    -1,   176,    -1,   177,    -1,
     178,    -1,   180,    -1,   181,    78,    -1,   159,    82,   156,
      -1,   179,    -1,   173,    -1,   174,    -1,    -1,    80,   161,
     162,    81,    -1,    80,    81,    -1,   163,    -1,   162,   163,
      -1,    94,    -1,   156,    -1,   165,    -1,    57,    83,   181,
      84,   156,    -1,    57,    83,   181,    84,   156,    58,   156,
      -1,   167,    -1,   168,    -1,   169,    -1,    27,   156,    43,
      83,   181,    84,    78,    -1,    43,    83,   181,    84,   156,
      -1,    30,   170,   156,    -1,    83,   171,    78,   181,    78,
     181,    84,    -1,    83,   171,    78,   181,    78,    84,    -1,
      83,   171,    78,    78,   181,    84,    -1,    83,   171,    78,
      78,    84,    -1,    83,    78,   181,    78,   181,    84,    -1,
      83,    78,   181,    78,    84,    -1,    83,    78,    78,   181,
      84,    -1,    83,    78,    78,    84,    -1,   181,    -1,    95,
      96,    -1,    38,    83,   181,    84,   156,    -1,    23,   141,
      -1,    26,    -1,    22,    78,    -1,    25,    78,    -1,    35,
     181,    78,    -1,    35,    78,    -1,    31,   179,    78,    -1,
       3,    -1,    78,    -1,   214,    -1,     3,    -1,     6,    -1,
       5,    -1,     4,    -1,    83,   181,    84,    -1,   182,    -1,
     184,    -1,   185,    -1,   186,    -1,   188,    -1,   189,    -1,
     190,    -1,   183,    85,   181,    86,    -1,   183,    87,     3,
      -1,   183,     8,     3,    -1,   183,    83,   187,    84,    -1,
      -1,   213,    -1,   187,    79,   213,    -1,   183,     9,    -1,
     183,    10,    -1,    83,   130,    84,    80,   148,    79,    81,
      -1,    83,   130,    84,    80,   148,    81,    -1,   192,    -1,
      83,   130,    84,   191,    -1,   183,    -1,   193,    -1,   194,
      -1,   195,    -1,   196,    -1,   197,    -1,   198,    -1,   199,
      -1,   200,    -1,   201,    -1,    20,   192,    -1,    20,    83,
     130,    84,    -1,    52,   191,    -1,    53,   191,    -1,    88,
     191,    -1,    89,   191,    -1,    49,   191,    -1,    55,   191,
      -1,     9,   192,    -1,    10,   192,    -1,   191,    -1,   202,
      55,   191,    -1,   202,    56,   191,    -1,   202,    54,   191,
      -1,   202,    -1,   203,    53,   202,    -1,   203,    52,   202,
      -1,   203,    -1,   204,    11,   203,    -1,   204,    12,   203,
      -1,   204,    -1,   205,    50,   204,    -1,   205,    51,   204,
      -1,   205,    14,   204,    -1,   205,    13,   204,    -1,   205,
      -1,   206,    15,   205,    -1,   206,    16,   205,    -1,   206,
      -1,   207,    49,   206,    -1,   207,    -1,   208,    48,   207,
      -1,   208,    -1,   209,    47,   208,    -1,   209,    -1,   210,
      17,   209,    -1,   210,    -1,   211,    18,   210,    -1,   211,
      -1,   211,    90,   181,    82,   212,    -1,   212,    -1,   192,
      67,   213,    -1,   192,    77,   213,    -1,   192,    76,   213,
      -1,   192,    75,   213,    -1,   192,    74,   213,    -1,   192,
      73,   213,    -1,   192,    72,   213,    -1,   192,    71,   213,
      -1,   192,    70,   213,    -1,   192,    69,   213,    -1,   192,
      68,   213,    -1,   213,    -1,   214,    79,   213,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    68,    72,    73,    76,   161,   165,   166,
     170,   171,   175,   176,   180,   183,   190,   199,   200,   209,
     214,   219,   224,   229,   237,   243,   244,   245,   246,   248,
     249,   252,   253,   256,   260,   263,   266,   271,   274,   277,
     278,   281,   282,   285,   288,   293,   298,   303,   306,   311,
     316,   323,   324,   325,   326,   329,   334,   339,   344,   349,
     354,   359,   364,   369,   374,   379,   384,   389,   394,   399,
     406,   411,   416,   421,   426,   431,   436,   441,   448,   453,
     458,   465,   471,   472,   475,   476,   479,   482,   485,   486,
     489,   492,   493,   496,   497,   500,   503,   504,   512,   513,
     516,   517,   520,   523,   526,   532,   533,   536,   537,   538,
     541,   542,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   556,   561,   566,   573,   574,   577,   578,   579,   580,
     583,   590,   599,   604,   609,   614,   628,   635,   644,   647,
     651,   654,   663,   664,   669,   670,   673,   674,   677,   678,
     681,   682,   683,   686,   687,   688,   689,   692,   695,   696,
     699,   700,   704,   704,   712,   713,   714,   715,   718,   719,
     723,   724,   725,   726,   727,   728,   729,   730,   731,   732,
     733,   736,   739,   744,   745,   746,   749,   749,   760,   763,
     768,   774,   775,   778,   781,   787,   795,   796,   797,   800,
     807,   814,   820,   826,   832,   838,   844,   850,   856,   862,
     870,   871,   874,   877,   880,   883,   886,   889,   893,   899,
     905,   911,   915,   918,   922,   926,   931,   935,   940,   941,
     942,   943,   944,   945,   946,   949,   960,   968,   981,   989,
     995,  1001,  1009,  1016,  1023,  1024,  1027,  1028,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1046,  1051,
    1054,  1061,  1068,  1075,  1082,  1089,  1096,  1112,  1128,  1129,
    1135,  1141,  1149,  1150,  1156,  1164,  1165,  1171,  1179,  1180,
    1186,  1192,  1198,  1206,  1207,  1213,  1221,  1222,  1230,  1231,
    1239,  1240,  1248,  1249,  1257,  1258,  1266,  1267,  1275,  1276,
    1282,  1292,  1302,  1312,  1322,  1332,  1342,  1352,  1362,  1372,
    1384,  1385
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "CHARLIT", "STRING", "NUMBER",
  "TOKEOF", "INDSEL", "PLUSPLUS", "MINUSMINUS", "SHL", "SHR", "LTEQ",
  "GTEQ", "EQEQ", "NOTEQ", "LOGAND", "LOGOR", "ELLIPSIS", "SIZEOF", "AUTO",
  "BREAK", "CASE", "CONST", "CONTINUE", "DEFAULT", "DO", "ENUM", "EXTERN",
  "FOR", "GOTO", "INLINE", "REGISTER", "RESTRICT", "RETURN", "STATIC",
  "STRUCT", "SWITCH", "TYPEDEF", "UNION", "VOID", "VOLATILE", "WHILE",
  "_BOOL", "_COMPLEX", "_IMAGINARY", "'|'", "'^'", "'&'", "'<'", "'>'",
  "'-'", "'+'", "'%'", "'*'", "'/'", "IF", "ELSE", "FLOAT", "DOUBLE",
  "CHAR", "INT", "LONG", "SHORT", "SIGNED", "UNSIGNED", "'='", "OREQ",
  "XOREQ", "ANDEQ", "SHREQ", "SHLEQ", "MODEQ", "DIVEQ", "TIMESEQ",
  "MINUSEQ", "PLUSEQ", "';'", "','", "'{'", "'}'", "':'", "'('", "')'",
  "'['", "']'", "'.'", "'!'", "'~'", "'?'", "$accept", "translation_unit",
  "top_level_decl", "decl", "decl_specs", "init_declarator_list",
  "init_declarator", "storage_class_spec", "func_spec", "type_spec",
  "enum_type_spec", "enum_type_def", "enum_type_ref", "enum_tag",
  "enum_def_list", "enum_constant_def", "enum_constant", "float_type_spec",
  "complex_type_spec", "int_type_spec", "signed_type_spec",
  "unsigned_type_spec", "char_type_spec", "bool_type_spec",
  "struct_type_spec", "struct_type_def", "struct_tag", "struct_type_ref",
  "field_list", "component_decl", "component_declarator_list",
  "component_declarator", "simple_component", "bit_field",
  "union_type_spec", "union_type_def", "union_type_ref", "union_tag",
  "void_type_spec", "type_name", "abstract_declarator",
  "type_qualifier_list", "direct_abstract_declarator", "type_qualifier",
  "declarator", "direct_declarator", "simple_declarator",
  "pointer_declarator", "pointer", "array_declarator", "constant_expr",
  "func_declarator", "parameter_type_list", "parameter_list",
  "parameter_decl", "identifier_list", "initializer", "initializer_list",
  "designation", "designator_list", "designator", "func_def", "@1",
  "func_def_specifier", "decl_list", "statement", "expr_statement",
  "labeled_statement", "label", "compound_statement", "@2",
  "decl_or_statement_list", "decl_or_statement", "conditional_statement",
  "if_statement", "iterative_statement", "do_statement", "while_statement",
  "for_statement", "for_expr", "init_clause", "switch_statement",
  "case_label", "default_label", "break_statement", "continue_statement",
  "return_statement", "goto_statement", "named_label", "null_statement",
  "expr", "primary_expr", "postfix_expr", "subscript_expr",
  "component_select_expr", "function_call", "expr_list", "post_inc_expr",
  "post_dec_expr", "compound_literal", "cast_expr", "unary_expr",
  "sizeof_expr", "unary_minus_expr", "unary_plus_expr", "log_neg_expr",
  "bit_neg_expr", "address_expr", "indirection_expr", "pre_inc_expr",
  "pre_dec_expr", "mult_expr", "add_expr", "shift_expr", "relation_expr",
  "equality_expr", "bit_and_expr", "bit_xor_expr", "bit_or_expr",
  "log_and_expr", "log_or_expr", "cond_expr", "assign_expr", "comma_expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   124,    94,    38,
      60,    62,    45,    43,    37,    42,    47,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    61,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,    59,    44,
     123,   125,    58,    40,    41,    91,    93,    46,    33,   126,
      63
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    92,    93,    93,    94,    95,    95,    95,
      95,    95,    95,    95,    95,    96,    96,    97,    97,    98,
      98,    98,    98,    98,    99,   100,   100,   100,   100,   100,
     100,   101,   101,   102,   102,   102,   102,   103,   104,   105,
     105,   106,   106,   107,   108,   108,   108,   108,   109,   109,
     109,   110,   110,   110,   110,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   113,
     113,   114,   115,   115,   116,   116,   117,   118,   119,   119,
     120,   121,   121,   122,   122,   123,   124,   124,   125,   125,
     126,   126,   127,   128,   129,   130,   130,   131,   131,   131,
     132,   132,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   134,   134,   134,   135,   135,   136,   136,   136,   136,
     137,   138,   139,   139,   139,   139,   140,   140,   141,   142,
     142,   142,   143,   143,   144,   144,   145,   145,   146,   146,
     147,   147,   147,   148,   148,   148,   148,   149,   150,   150,
     151,   151,   153,   152,   154,   154,   154,   154,   155,   155,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   157,   158,   159,   159,   159,   161,   160,   160,   162,
     162,   163,   163,   164,   165,   165,   166,   166,   166,   167,
     168,   169,   170,   170,   170,   170,   170,   170,   170,   170,
     171,   171,   172,   173,   174,   175,   176,   177,   177,   178,
     179,   180,   181,   182,   182,   182,   182,   182,   183,   183,
     183,   183,   183,   183,   183,   184,   185,   185,   186,   187,
     187,   187,   188,   189,   190,   190,   191,   191,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   193,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   202,
     202,   202,   203,   203,   203,   204,   204,   204,   205,   205,
     205,   205,   205,   206,   206,   206,   207,   207,   208,   208,
     209,   209,   210,   210,   211,   211,   212,   212,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     214,   214
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     2,     1,     2,
       1,     2,     1,     2,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     6,     5,     5,     4,     2,     1,     1,
       3,     1,     3,     1,     1,     1,     2,     1,     2,     2,
       3,     1,     1,     1,     1,     1,     2,     2,     3,     1,
       2,     1,     1,     2,     2,     3,     2,     3,     3,     4,
       2,     3,     2,     1,     2,     3,     3,     4,     1,     2,
       2,     1,     1,     1,     5,     4,     1,     2,     1,     2,
       3,     1,     3,     1,     1,     1,     3,     2,     1,     1,
       5,     4,     2,     1,     1,     2,     1,     1,     2,     1,
       1,     2,     3,     4,     3,     3,     2,     4,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     2,     2,     1,     3,     2,     4,     3,     1,     4,
       4,     3,     1,     3,     1,     3,     2,     2,     1,     3,
       1,     4,     3,     1,     3,     2,     4,     2,     1,     2,
       3,     2,     0,     3,     3,     2,     2,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     1,     1,     1,     0,     4,     2,     1,
       2,     1,     1,     1,     5,     7,     1,     1,     1,     7,
       5,     3,     7,     6,     6,     5,     6,     5,     5,     4,
       1,     2,     5,     2,     1,     2,     2,     3,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     4,     0,
       1,     3,     2,     2,     7,     6,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   130,    19,   121,     0,    20,    24,    21,   123,    22,
       0,    23,     0,   104,   122,    81,   133,    44,    45,    78,
      59,    62,    55,    61,    73,     0,     0,     2,     4,     0,
       8,    14,    10,    25,    31,    32,    26,    47,    27,    51,
      52,    53,    54,    28,    82,    83,    29,    98,    99,    30,
      12,   167,   125,   126,   124,     0,   129,   128,     5,   162,
      38,     0,    37,    86,     0,    87,   103,     0,   102,   132,
     110,   135,    48,    49,    46,    63,    66,    56,    79,    60,
      64,    57,    80,    72,    74,    70,     0,     1,     3,     0,
      15,    17,     7,    13,     9,    11,   168,     0,   166,     0,
       0,   131,     0,    43,     0,    39,    41,     0,     0,     0,
      88,     0,     0,     0,   111,   134,    50,    67,    65,    68,
      58,    75,    76,    71,   127,     6,     0,     0,   164,    17,
     169,   148,   141,     0,     0,   142,   144,     0,     0,   137,
     186,   163,     0,    36,     0,     0,     0,     0,    91,    93,
      94,    95,    85,    89,     0,   101,     0,    69,    77,    16,
     223,   226,   225,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,   228,   248,   229,   230,
     231,   232,   233,   234,   268,   246,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   272,   275,   278,   283,   286,
     288,   290,   292,   294,   296,   298,   150,     0,     0,   147,
     109,   146,   107,   139,     0,   140,   136,   188,     0,    34,
      40,    42,     0,    35,    97,   246,   138,    90,     0,     0,
      84,   100,     0,   266,   267,     0,   258,   264,   260,   261,
     265,     0,     0,   153,     0,     0,     0,   158,   106,     0,
       0,   310,   222,   262,   263,     0,   242,   243,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,     0,     0,   142,   116,     0,     0,     0,   108,
     149,   143,   145,   223,     0,     0,     0,   214,     0,     0,
       0,     0,     0,     0,     0,   221,   191,   192,   170,   171,
       0,   172,     0,   189,   173,   193,   174,   196,   197,   198,
     175,   184,   185,   176,   177,   178,   179,   183,   180,     0,
      33,    92,    96,     0,     0,     0,   161,     0,   152,   155,
     157,   159,     0,   105,   107,     0,   227,     0,   237,     0,
     240,     0,   236,   299,   309,   308,   307,   306,   305,   304,
     303,   302,   301,   300,   271,   269,   270,   274,   273,   276,
     277,   282,   281,   279,   280,   284,   285,   287,   289,   291,
     293,   295,     0,   112,   118,     0,   114,   119,     0,   115,
       0,   215,   213,   216,     0,     0,     0,   220,     0,   218,
       0,     0,     0,     0,     0,   187,   190,   181,     0,   259,
     160,   151,   154,     0,     0,   247,   311,     0,   238,   235,
       0,   117,   113,     0,     0,     0,     0,   210,   201,   219,
     217,     0,     0,     0,   182,   156,     0,   241,   297,     0,
       0,     0,   211,     0,     0,     0,     0,     0,   245,     0,
     209,     0,     0,     0,     0,   212,   200,   194,   244,     0,
     208,   207,     0,   205,     0,     0,     0,   199,   206,   204,
     203,     0,   195,   202
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    27,    28,    97,    89,    90,    30,    31,    32,
      33,    34,    35,    62,   104,   105,   106,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    65,    45,   109,   110,
     147,   148,   149,   150,    46,    47,    48,    68,    49,   249,
     292,    69,   210,    50,   129,    52,    53,    54,    55,    56,
     224,    57,   293,   294,   136,   137,   243,   244,   245,   246,
     247,    58,   102,    59,    98,   317,   318,   319,   320,   321,
     218,   322,   323,   324,   325,   326,   327,   328,   329,   406,
     436,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   176,   177,   178,   179,   180,   359,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   251,   252
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -328
static const yytype_int16 yypact[] =
{
    1375,  -328,  -328,  -328,    30,  -328,  -328,  -328,  -328,  -328,
      41,  -328,    49,  -328,  -328,  -328,    40,     8,    12,  -328,
    -328,    -1,   -35,   118,   125,    34,  1211,  -328,  -328,    34,
    1766,  1766,  1766,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    1766,  1766,   -13,  -328,  -328,    26,  -328,  -328,  -328,  -328,
    -328,    84,    11,  -328,   285,    39,  -328,   285,    51,    40,
    -328,  -328,  -328,  -328,    56,  -328,    95,  -328,  -328,  -328,
      74,    99,  -328,  -328,   143,   104,   106,  -328,  -328,   152,
    -328,  1582,  -328,  -328,  -328,  -328,  -328,    34,  1766,  1329,
      28,   -13,   103,  -328,    -2,  -328,   126,    84,    25,  1274,
    -328,   285,  1623,   285,  -328,  -328,  -328,  -328,  -328,   139,
    -328,  -328,   150,  -328,  -328,  -328,    34,   781,  1766,   148,
    -328,  -328,  -328,    21,   137,   170,  -328,   159,   165,  -328,
     176,  -328,    19,  -328,  1109,    15,  1109,   158,  -328,  -328,
    -328,   189,  -328,  -328,  1631,  -328,  1670,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  1121,  1121,  1174,  1109,  1109,  1109,
    1109,   740,   611,  1109,  1109,  -328,  -328,   142,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,   804,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,   121,   186,   230,   145,   250,
     225,   227,   229,   266,     7,  -328,  -328,  1264,   164,  -328,
     114,  -328,    20,  -328,  1490,  -328,  -328,  -328,   479,  -328,
    -328,  -328,    35,  -328,  -328,  -328,  -328,  -328,    25,  1109,
    -328,  -328,   611,  -328,  -328,   611,  -328,  -328,  -328,  -328,
    -328,  1109,   283,  -328,   123,   781,   -18,  -328,   -12,   204,
     205,  -328,   211,  -328,  -328,   288,  -328,  -328,  1109,  1109,
     291,  1109,  1109,  1109,  1109,  1109,  1109,  1109,  1109,  1109,
    1109,  1109,  1109,  1109,  1109,  1109,  1109,  1109,  1109,  1109,
    1109,  1109,  1109,  1109,  1109,  1109,  1109,  1109,  1109,  1109,
    1109,  -328,   215,   219,   228,  -328,   222,  1536,   834,   114,
    -328,  -328,  -328,   232,   231,  1109,   233,  -328,   681,   234,
     307,   843,   236,   237,   238,  -328,  -328,  -328,  -328,  -328,
     249,  -328,   398,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,   255,
    -328,  -328,  -328,   252,   254,   226,  -328,   275,  -328,  -328,
    -328,  -328,  1423,  -328,   135,   896,  -328,  1109,  -328,   -24,
    -328,   253,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,   121,   121,   186,
     186,   230,   230,   230,   230,   145,   145,   250,   225,   227,
     229,   266,   258,  -328,  -328,  1720,  -328,  -328,   257,  -328,
     256,  -328,  -328,  -328,   272,   545,   681,  -328,   265,  -328,
     276,  1109,  1109,  1109,   681,  -328,  -328,  -328,   273,   273,
    -328,  -328,  -328,   781,   740,  -328,  -328,  1109,  -328,  -328,
    1109,  -328,  -328,   274,   904,    34,   281,  -328,  -328,  -328,
    -328,   277,   300,   301,  -328,  -328,   147,  -328,  -328,  1109,
     957,   287,   308,   995,   681,   681,   681,   722,  -328,   302,
    -328,   304,  1013,  1022,   311,  -328,  -328,   332,  -328,   313,
    -328,  -328,   309,  -328,   310,  1083,   681,  -328,  -328,  -328,
    -328,   312,  -328,  -328
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -328,  -328,   290,   -40,     0,   -38,   280,  -328,  -328,   -28,
    -328,  -328,  -328,  -328,   293,   -95,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,   -21,    44,
    -328,   181,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -169,
    -114,  -328,  -194,    24,    16,   -41,  -328,  -328,   -15,  -328,
    -173,  -328,   -94,   299,  -204,  -328,  -125,   -14,  -327,  -328,
     166,  -328,  -328,  -328,   320,  -291,  -328,  -328,  -328,   314,
    -328,  -328,    91,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,   105,  -328,
    -157,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -161,    94,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,   -30,    -8,   -71,   -11,   129,   131,   156,   157,   155,
    -328,  -143,  -123,  -328
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -221
static const yytype_int16 yytable[] =
{
      29,    71,   175,   226,   206,   134,   237,   238,   239,   240,
     302,    96,   253,   254,   101,   250,    51,   404,   299,   209,
     423,   221,   103,     1,     1,   289,    29,    77,     1,     1,
      92,    93,    94,    60,   138,   296,   108,     1,   103,   108,
      70,    86,    51,    16,    63,    91,   112,   220,   206,   350,
      95,    96,    66,    72,   115,   427,   342,    73,   130,    74,
     428,    75,    76,   343,     3,   226,   344,   241,   345,   242,
      99,   352,   100,   208,     8,   250,    16,   142,   250,   143,
      16,   108,    14,   108,   108,   108,   226,   103,   130,    16,
     154,   107,   156,   114,   222,    16,   223,   290,   226,   133,
     219,   116,   361,   207,   207,   208,   208,   146,    25,    25,
      61,   374,   375,   376,   139,   438,   340,    25,   212,   111,
     349,    64,   206,   444,   151,   400,   108,   220,   108,    67,
     423,   113,   402,   392,   353,   360,   118,   119,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   211,
     255,   256,   257,   153,   410,   226,   153,   117,   279,   280,
     299,   120,   226,   465,   466,   467,   123,   160,   161,   162,
     163,   101,   248,   164,   165,   272,   273,   274,   316,    78,
      79,    80,    81,   140,   166,   482,    82,    83,    84,    85,
     124,   302,   212,   144,   425,   281,   282,   297,   153,   298,
     153,   157,   347,   398,   348,   121,   122,   133,   381,   382,
     383,   384,   158,   167,   133,   127,   168,   169,   352,   170,
     208,   213,   422,    86,   206,   258,   457,   259,   458,   260,
     125,   126,   248,   354,   426,   248,   227,   228,   275,   276,
     225,   277,   278,   215,   151,   377,   378,   172,   437,   214,
     295,   216,   173,   174,   441,   442,   443,   217,   233,   234,
     236,   225,   225,   225,   225,   283,   284,   225,   225,   379,
     380,   229,   385,   386,   285,   286,   287,   451,   160,   161,
     162,   163,   316,   288,   164,   165,   346,   448,   355,   356,
     357,   358,   459,   461,   362,   166,   464,   133,   445,   393,
     206,   206,   225,   394,   447,   472,   474,   395,   396,   401,
     407,   403,   420,     4,  -220,   433,    88,   405,   481,   411,
     412,   413,    10,   225,   167,    12,    13,   168,   169,    15,
     170,   414,   422,   417,   206,   225,   418,   354,   419,   429,
     430,   431,   432,   439,    17,    18,    19,    20,    21,    22,
      23,    24,   133,   424,   440,   171,   421,   449,   172,   453,
     241,   454,   242,   173,   174,   462,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   455,   456,   469,   126,   470,   475,
     476,   477,   225,   478,   479,   133,   483,   452,   135,   225,
     145,   303,   161,   162,   163,   435,   159,   164,   165,   341,
     446,   128,   351,   416,   387,   408,   141,   388,   166,     2,
     304,   305,     3,   306,   307,   308,     4,     5,   309,   310,
       6,     7,     8,   311,     9,    10,   312,    11,    12,    13,
      14,   313,    15,   389,   391,   390,     0,   167,     0,   225,
     168,   169,     0,   170,     0,   314,     0,    17,    18,    19,
      20,    21,    22,    23,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   315,     0,   140,   415,
       0,   172,   303,   161,   162,   163,   173,   174,   164,   165,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   166,
       2,   304,   305,     3,   306,   307,   308,     4,     5,   309,
     310,     6,     7,     8,   311,     9,    10,   312,    11,    12,
      13,    14,   313,    15,   225,     0,     0,     0,   167,     0,
       0,   168,   169,     0,   170,     0,   314,     0,    17,    18,
      19,    20,    21,    22,    23,    24,     0,     0,   160,   161,
     162,   163,     0,     0,   164,   165,     0,   315,     0,   140,
       0,     0,   172,     0,     0,   166,     2,   173,   174,     3,
       0,     0,     0,     4,     5,     0,     0,     6,     7,     8,
       0,     9,    10,     0,    11,    12,    13,    14,     0,    15,
       0,     0,     0,     0,   167,     0,     0,   168,   169,     0,
     170,     0,     0,     0,    17,    18,    19,    20,    21,    22,
      23,    24,     0,     0,   160,   161,   162,   163,     0,     0,
     164,   165,     0,   434,     0,     0,     0,     0,   172,     0,
       0,   166,     2,   173,   174,     3,     0,     0,     0,     4,
       5,     0,     0,     6,     7,     8,     0,     9,    10,     0,
      11,    12,    13,    14,     0,    15,     0,     0,     0,     0,
     167,     0,     0,   168,   169,     0,   170,     0,     0,     0,
      17,    18,    19,    20,    21,    22,    23,    24,     0,     0,
       0,     0,     0,     0,   303,   161,   162,   163,     0,     0,
     164,   165,     0,     0,   172,     0,     0,     0,     0,   173,
     174,   166,     0,   304,   305,     0,   306,   307,   308,     0,
       0,   309,   310,     0,     0,     0,   311,     0,     0,   312,
       0,     0,     0,     0,   313,   160,   161,   162,   163,     0,
     167,   164,   165,   168,   169,     0,   170,     0,   314,     0,
       0,     0,   166,   160,   161,   162,   163,     0,     0,   164,
     165,     0,     0,     0,     0,     0,     0,     0,     0,   315,
     166,   140,     0,     0,   172,     0,     0,     0,     0,   173,
     174,   167,     0,     0,   168,   169,     0,   170,     0,     0,
       0,     0,     0,     0,   160,   161,   162,   163,     0,   167,
     164,   165,   168,   169,     0,   170,     0,     0,     0,     0,
       0,   166,   171,   468,     0,   172,     0,   241,     0,   242,
     173,   174,     0,     0,     0,     0,     0,     0,     0,     0,
     171,     0,     0,   172,     0,   241,     0,   242,   173,   174,
     167,     0,     0,   168,   169,     0,   170,   160,   161,   162,
     163,     0,     0,   164,   165,     0,   160,   161,   162,   163,
       0,     0,   164,   165,   166,     0,     0,     0,     0,     0,
       0,   171,     0,   166,   172,     0,     0,     0,     0,   173,
     174,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,     0,   167,     0,     0,   168,   169,     0,   170,
       0,     0,   167,     0,     0,   168,   169,     0,   170,   160,
     161,   162,   163,     0,     0,   164,   165,   160,   161,   162,
     163,     0,     0,   164,   165,     0,   166,   172,     0,     0,
     399,   409,   173,   174,   166,     0,   172,     0,     0,     0,
       0,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,     0,     0,   168,   169,
       0,   170,     0,   167,     0,     0,   168,   169,     0,   170,
     160,   161,   162,   163,     0,     0,   164,   165,     0,     0,
       0,     0,     0,     0,     0,     0,   424,   166,     0,   172,
       0,     0,   450,     0,   173,   174,     0,   172,     0,     0,
       0,     0,   173,   174,     0,     0,     0,     0,   160,   161,
     162,   163,     0,     0,   164,   165,   167,     0,     0,   168,
     169,     0,   170,     0,     0,   166,   160,   161,   162,   163,
       0,     0,   164,   165,     0,   160,   161,   162,   163,     0,
       0,   164,   165,   166,     0,     0,     0,     0,     0,     0,
     172,   460,   166,     0,   167,   173,   174,   168,   169,     0,
     170,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,     0,     0,   168,   169,     0,   170,     0,
       0,   167,     0,   463,   168,   169,     0,   170,   172,     0,
       0,     0,     0,   173,   174,     0,   160,   161,   162,   163,
       0,     0,   164,   165,     0,     0,   172,   471,     0,     0,
       0,   173,   174,   166,     0,   172,   473,     0,     0,     0,
     173,   174,   160,   161,   162,   163,     0,     0,   164,   165,
       0,     0,     0,     0,   160,   161,   162,   163,     0,   166,
     164,   165,   167,     0,     0,   168,   169,     0,   170,     0,
       0,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,     0,
       0,   168,   169,     0,   170,     0,   172,   480,     0,     0,
     167,   173,   174,   168,   169,     0,   170,   160,   161,   162,
     163,     0,     0,   164,   165,     0,     0,     0,     0,     0,
       0,     0,   172,     0,   166,     0,     0,   173,   174,     0,
       0,     0,     0,     0,   232,     0,     0,     0,     0,   173,
     174,    87,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,   167,     0,     0,   168,   169,     0,   170,
       0,     0,     2,     0,     0,     3,     0,     0,     0,     4,
       5,     0,     0,     6,     7,     8,     0,     9,    10,     0,
      11,    12,    13,    14,     0,    15,     0,   235,     0,     0,
       0,     0,   173,   174,     0,     0,    16,     1,     0,     0,
      17,    18,    19,    20,    21,    22,    23,    24,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     3,     0,
       0,     0,     4,     5,    25,     0,     6,     7,     8,     0,
       9,    10,     4,    11,    12,    13,    14,     0,    15,     0,
       0,    10,     0,     0,    12,    13,     0,     0,    15,    16,
       0,     0,     0,    17,    18,    19,    20,    21,    22,    23,
      24,     0,   131,    17,    18,    19,    20,    21,    22,    23,
      24,     0,     0,     0,     0,     0,     0,   207,   291,   208,
       2,     0,     0,     3,     0,   152,     0,     4,     5,     0,
       0,     6,     7,     8,     0,     9,    10,     0,    11,    12,
      13,    14,     0,    15,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,    20,    21,    22,    23,    24,     2,     0,     0,     3,
       0,     0,     0,     4,     5,     0,     0,     6,     7,     8,
       0,     9,    10,   132,    11,    12,    13,    14,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,     0,    17,    18,    19,    20,    21,    22,
      23,    24,     0,     0,     2,     0,     0,     3,     0,     0,
       0,     4,     5,     0,     0,     6,     7,     8,    25,     9,
      10,     0,    11,    12,    13,    14,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,     0,    17,    18,    19,    20,    21,    22,    23,    24,
       0,     0,     0,   300,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   352,   291,   208,   301,
       0,     2,     0,     0,     3,     0,     0,     0,     4,     5,
       0,     0,     6,     7,     8,     0,     9,    10,     0,    11,
      12,    13,    14,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    19,    20,    21,    22,    23,    24,     2,     0,     0,
       3,     0,     0,     0,     4,     5,     0,     0,     6,     7,
       8,     0,     9,    10,     0,    11,    12,    13,    14,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,    19,    20,    21,
      22,    23,    24,     2,     0,     0,     3,     0,     0,     0,
       4,     5,     0,     0,     6,     7,     8,     0,     9,    10,
     397,    11,    12,    13,    14,     0,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    19,    20,    21,    22,    23,    24,   127,
       0,     4,     0,     0,     0,     0,     0,     0,     0,     4,
      10,     0,  -165,    12,    13,     0,     0,    15,    10,     0,
       0,    12,    13,     0,     0,    15,     0,     0,     0,     0,
       0,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      17,    18,    19,    20,    21,    22,    23,    24,     4,     0,
       0,     0,     0,     0,   155,     0,     0,    10,     0,     0,
      12,    13,   230,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    19,    20,    21,    22,    23,    24,     0,     0,   301,
       0,     2,     0,     0,     3,     0,     0,     0,     4,     5,
       0,   231,     6,     7,     8,     0,     9,    10,     0,    11,
      12,    13,    14,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    19,    20,    21,    22,    23,    24,     2,     0,     0,
       3,     0,     0,     0,     4,     5,     0,     0,     6,     7,
       8,     0,     9,    10,     0,    11,    12,    13,    14,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,    19,    20,    21,
      22,    23,    24
};

static const yytype_int16 yycheck[] =
{
       0,    16,   127,   146,   127,    99,   167,   168,   169,   170,
     214,    51,   173,   174,    55,   172,     0,   308,   212,   133,
     347,   144,     3,     3,     3,    18,    26,    62,     3,     3,
      30,    31,    32,     3,     6,   208,    64,     3,     3,    67,
      16,    25,    26,    55,     3,    29,    67,   142,   171,    67,
      50,    91,     3,    45,    69,    79,   229,    45,    98,    60,
      84,    62,    63,   232,    24,   208,   235,    85,   241,    87,
      83,    83,    85,    85,    34,   232,    55,    79,   235,    81,
      55,   109,    42,   111,   112,   113,   229,     3,   128,    55,
     111,    80,   113,    69,    79,    55,    81,    90,   241,    99,
      81,    45,   259,    83,    83,    85,    85,    82,    83,    83,
      80,   272,   273,   274,    86,   406,    81,    83,   133,    80,
     245,    80,   245,   414,   108,   298,   154,   222,   156,    80,
     457,    80,   305,   290,   248,   258,    62,    63,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   133,
       8,     9,    10,   109,   311,   298,   112,    62,    13,    14,
     354,    62,   305,   454,   455,   456,    62,     3,     4,     5,
       6,   212,   172,     9,    10,    54,    55,    56,   218,    61,
      62,    63,    64,    80,    20,   476,    61,    62,    63,    64,
      84,   395,   207,    67,   355,    50,    51,    83,   154,    85,
     156,    62,    79,   297,    81,    62,    63,   207,   279,   280,
     281,   282,    62,    49,   214,    67,    52,    53,    83,    55,
      85,    84,   347,   207,   347,    83,    79,    85,    81,    87,
      78,    79,   232,   248,   357,   235,    78,    79,    52,    53,
     146,    11,    12,    84,   228,   275,   276,    83,   405,    79,
      86,    86,    88,    89,   411,   412,   413,    81,   164,   165,
     166,   167,   168,   169,   170,    15,    16,   173,   174,   277,
     278,    82,   283,   284,    49,    48,    47,   434,     3,     4,
       5,     6,   322,    17,     9,    10,     3,   430,    84,    84,
      79,     3,   449,   450,     3,    20,   453,   297,   423,    84,
     423,   424,   208,    84,   427,   462,   463,    79,    86,    78,
       3,    78,    86,    28,    82,    43,    26,    83,   475,    83,
      83,    83,    37,   229,    49,    40,    41,    52,    53,    44,
      55,    82,   457,    78,   457,   241,    84,   352,    84,    86,
      82,    84,    86,    78,    59,    60,    61,    62,    63,    64,
      65,    66,   352,    80,    78,    80,    81,    83,    83,    78,
      85,    84,    87,    88,    89,    78,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,    84,    84,    84,    79,    84,    78,
      58,    78,   298,    84,    84,   395,    84,   435,    99,   305,
     107,     3,     4,     5,     6,   405,   126,     9,    10,   228,
     424,    91,   246,   322,   285,   310,   102,   286,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,   287,   289,   288,    -1,    49,    -1,   355,
      52,    53,    -1,    55,    -1,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,
      -1,    83,     3,     4,     5,     6,    88,    89,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,   430,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    -1,    55,    -1,    57,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    10,    -1,    78,    -1,    80,
      -1,    -1,    83,    -1,    -1,    20,    21,    88,    89,    24,
      -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,    34,
      -1,    36,    37,    -1,    39,    40,    41,    42,    -1,    44,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,    -1,
      55,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    10,    -1,    78,    -1,    -1,    -1,    -1,    83,    -1,
      -1,    20,    21,    88,    89,    24,    -1,    -1,    -1,    28,
      29,    -1,    -1,    32,    33,    34,    -1,    36,    37,    -1,
      39,    40,    41,    42,    -1,    44,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    52,    53,    -1,    55,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    10,    -1,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,    20,    -1,    22,    23,    -1,    25,    26,    27,    -1,
      -1,    30,    31,    -1,    -1,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    43,     3,     4,     5,     6,    -1,
      49,     9,    10,    52,    53,    -1,    55,    -1,    57,    -1,
      -1,    -1,    20,     3,     4,     5,     6,    -1,    -1,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      20,    80,    -1,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,    49,    -1,    -1,    52,    53,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    49,
       9,    10,    52,    53,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    20,    80,    81,    -1,    83,    -1,    85,    -1,    87,
      88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    83,    -1,    85,    -1,    87,    88,    89,
      49,    -1,    -1,    52,    53,    -1,    55,     3,     4,     5,
       6,    -1,    -1,     9,    10,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    10,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    20,    83,    -1,    -1,    -1,    -1,    88,
      89,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    49,    -1,    -1,    52,    53,    -1,    55,
      -1,    -1,    49,    -1,    -1,    52,    53,    -1,    55,     3,
       4,     5,     6,    -1,    -1,     9,    10,     3,     4,     5,
       6,    -1,    -1,     9,    10,    -1,    20,    83,    -1,    -1,
      86,    78,    88,    89,    20,    -1,    83,    -1,    -1,    -1,
      -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      -1,    55,    -1,    49,    -1,    -1,    52,    53,    -1,    55,
       3,     4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    20,    -1,    83,
      -1,    -1,    78,    -1,    88,    89,    -1,    83,    -1,    -1,
      -1,    -1,    88,    89,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    10,    49,    -1,    -1,    52,
      53,    -1,    55,    -1,    -1,    20,     3,     4,     5,     6,
      -1,    -1,     9,    10,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    10,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    20,    -1,    49,    88,    89,    52,    53,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    53,    -1,    55,    -1,
      -1,    49,    -1,    78,    52,    53,    -1,    55,    83,    -1,
      -1,    -1,    -1,    88,    89,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    10,    -1,    -1,    83,    84,    -1,    -1,
      -1,    88,    89,    20,    -1,    83,    84,    -1,    -1,    -1,
      88,    89,     3,     4,     5,     6,    -1,    -1,     9,    10,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    20,
       9,    10,    49,    -1,    -1,    52,    53,    -1,    55,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    -1,    55,    -1,    83,    84,    -1,    -1,
      49,    88,    89,    52,    53,    -1,    55,     3,     4,     5,
       6,    -1,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    20,    -1,    -1,    88,    89,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    88,
      89,     0,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,    -1,    55,
      -1,    -1,    21,    -1,    -1,    24,    -1,    -1,    -1,    28,
      29,    -1,    -1,    32,    33,    34,    -1,    36,    37,    -1,
      39,    40,    41,    42,    -1,    44,    -1,    83,    -1,    -1,
      -1,    -1,    88,    89,    -1,    -1,    55,     3,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    24,    -1,
      -1,    -1,    28,    29,    83,    -1,    32,    33,    34,    -1,
      36,    37,    28,    39,    40,    41,    42,    -1,    44,    -1,
      -1,    37,    -1,    -1,    40,    41,    -1,    -1,    44,    55,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,     3,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      21,    -1,    -1,    24,    -1,    81,    -1,    28,    29,    -1,
      -1,    32,    33,    34,    -1,    36,    37,    -1,    39,    40,
      41,    42,    -1,    44,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    21,    -1,    -1,    24,
      -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,    34,
      -1,    36,    37,    84,    39,    40,    41,    42,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    21,    -1,    -1,    24,    -1,    -1,
      -1,    28,    29,    -1,    -1,    32,    33,    34,    83,    36,
      37,    -1,    39,    40,    41,    42,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    19,
      -1,    21,    -1,    -1,    24,    -1,    -1,    -1,    28,    29,
      -1,    -1,    32,    33,    34,    -1,    36,    37,    -1,    39,
      40,    41,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    21,    -1,    -1,
      24,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,
      34,    -1,    36,    37,    -1,    39,    40,    41,    42,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    21,    -1,    -1,    24,    -1,    -1,    -1,
      28,    29,    -1,    -1,    32,    33,    34,    -1,    36,    37,
      84,    39,    40,    41,    42,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      37,    -1,    80,    40,    41,    -1,    -1,    44,    37,    -1,
      -1,    40,    41,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      59,    60,    61,    62,    63,    64,    65,    66,    28,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    37,    -1,    -1,
      40,    41,    81,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    -1,    19,
      -1,    21,    -1,    -1,    24,    -1,    -1,    -1,    28,    29,
      -1,    81,    32,    33,    34,    -1,    36,    37,    -1,    39,
      40,    41,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    21,    -1,    -1,
      24,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,
      34,    -1,    36,    37,    -1,    39,    40,    41,    42,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    21,    24,    28,    29,    32,    33,    34,    36,
      37,    39,    40,    41,    42,    44,    55,    59,    60,    61,
      62,    63,    64,    65,    66,    83,    92,    93,    94,    95,
      98,    99,   100,   101,   102,   103,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   118,   125,   126,   127,   129,
     134,   135,   136,   137,   138,   139,   140,   142,   152,   154,
       3,    80,   104,     3,    80,   117,     3,    80,   128,   132,
     134,   139,    45,    45,    60,    62,    63,    62,    61,    62,
      63,    64,    61,    62,    63,    64,   135,     0,    93,    96,
      97,   135,    95,    95,    95,    95,    94,    95,   155,    83,
      85,   136,   153,     3,   105,   106,   107,    80,   100,   119,
     120,    80,   119,    80,   134,   139,    45,    62,    62,    63,
      62,    62,    63,    62,    84,    78,    79,    67,   155,   135,
      94,     3,    84,    95,   143,   144,   145,   146,     6,    86,
      80,   160,    79,    81,    67,   105,    82,   121,   122,   123,
     124,   135,    81,   120,   119,    81,   119,    62,    62,    97,
       3,     4,     5,     6,     9,    10,    20,    49,    52,    53,
      55,    80,    83,    88,    89,   147,   182,   183,   184,   185,
     186,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    83,    85,   131,
     133,   135,   139,    84,    79,    84,    86,    81,   161,    81,
     106,   213,    79,    81,   141,   192,   212,    78,    79,    82,
      81,    81,    83,   192,   192,    83,   192,   191,   191,   191,
     191,    85,    87,   147,   148,   149,   150,   151,    95,   130,
     181,   213,   214,   191,   191,     8,     9,    10,    83,    85,
      87,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    54,    55,    56,    52,    53,    11,    12,    13,
      14,    50,    51,    15,    16,    49,    48,    47,    17,    18,
      90,    84,   131,   143,   144,    86,   141,    83,    85,   133,
       3,    19,   145,     3,    22,    23,    25,    26,    27,    30,
      31,    35,    38,    43,    57,    78,    94,   156,   157,   158,
     159,   160,   162,   163,   164,   165,   166,   167,   168,   169,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      81,   122,   141,   130,   130,   141,     3,    79,    81,   147,
      67,   151,    83,   131,   139,    84,    84,    79,     3,   187,
     213,   181,     3,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   191,   191,   191,   202,   202,   203,
     203,   204,   204,   204,   204,   205,   205,   206,   207,   208,
     209,   210,   181,    84,    84,    79,    86,    84,   143,    86,
     141,    78,   141,    78,   156,    83,   170,     3,   179,    78,
     181,    83,    83,    83,    82,    81,   163,    78,    84,    84,
      86,    81,   147,   149,    80,   191,   213,    79,    84,    86,
      82,    84,    86,    43,    78,    95,   171,   181,   156,    78,
      78,   181,   181,   181,   156,   147,   148,   213,   212,    83,
      78,   181,    96,    78,    84,    84,    84,    79,    81,   181,
      84,   181,    78,    78,   181,   156,   156,   156,    81,    84,
      84,    84,   181,    84,   181,    78,    58,    78,    84,    84,
      84,   181,   156,    84
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 76 "src/parser.y"
    { 
    							struct ASTNODE *decl_spec_node = (yyvsp[(1) - (3)].node);
							struct ASTNODE *storage_class_node = (yyvsp[(1) - (3)].node);
							int storage_class = 0;
							int decl_type;
    							while(decl_spec_node) { 
								if ((decl_spec_node->nodetype != AST_STRUCT) &&
									(decl_spec_node->nodetype != AST_UNION) &&
									(decl_spec_node->nodetype != AST_ENUM) &&
									(decl_spec_node->nodetype != AST_SCALAR) &&
									(decl_spec_node->nodetype != AST_FUNC)) {
									decl_spec_node = decl_spec_node->next_node;
								}
								else {
									decl_type = decl_spec_node->nodetype;
									break;
								}
							}
							while(storage_class_node){
								if (storage_class_node->nodetype == AST_STORAGE) {
									storage_class = storage_class_node->storage_class;
									break;
								}
								storage_class_node = storage_class_node->next_node;
							}
 							while((yyvsp[(2) - (3)].node)) {
								struct ASTNODE *node = (yyvsp[(2) - (3)].node)->next_node;
								struct ASTNODE *gen_node;
								int namespace_type, overwrite;
								int ident_type = 0;
								char *symbol_name;
								switch(decl_type) {
									case AST_STRUCT:
										ident_type = ID_STRUCT_TAG;
										break;
									case AST_UNION:
										ident_type = ID_UNION_TAG;
										break;
									case AST_ENUM:
										ident_type = ID_ENUM_TAG;
										break;
									case AST_SCALAR:
										if(!(((yyvsp[(2) - (3)].node)->init_list_tail->nodetype == AST_FUNC) && ((yyvsp[(2) - (3)].node)->init_list_head->next_node->nodetype == AST_FUNC))){
											gen_node = create_node(AST_VAR);
											if(current_scope->scope_type) {
												storage_class = storage_class?storage_class:AUTO;
											}
											else{
												storage_class = storage_class?storage_class:EXTERN;
											}
											(yyvsp[(2) - (3)].node)->init_list_tail->next_node = decl_spec_node;
											gen_node->next_node = (yyvsp[(2) - (3)].node)->init_list_head->next_node;
											gen_node->var_name = (yyvsp[(2) - (3)].node)->init_list_head->ident;
											symbol_name = gen_node->var_name;
											ident_type = ID_VAR;
											namespace_type = NS_OTHER;
											overwrite = 0;
										}
										else {
											gen_node = create_node(AST_FUNC);
											storage_class = storage_class?storage_class:EXTERN;
											gen_node->next_node = decl_spec_node;
											gen_node->func_ident = (yyvsp[(2) - (3)].node)->init_list_head->ident;
											symbol_name = gen_node->func_ident;
											ident_type = ID_FUNC;
											namespace_type = NS_OTHER;
											overwrite = 0;
										}	
										break;
									/*
									case AST_TYPEDEF:
										ident_type = ID_TYPEDEF_NAME;
										break;
									case AST_FUNC:
										ident_type = ID_FUNC;
										break;
									*/
								}
								struct symbol *installed_symbol = install_symbol(symbol_name, filename, line, ident_type, storage_class, namespace_type, current_scope, gen_node, overwrite);
								installed_symbol?print_symbol(installed_symbol):yywarn("Semantic error: Attempted redeclaration of identifier \"%s\"", symbol_name);
								(yyvsp[(2) - (3)].node) = (yyvsp[(2) - (3)].node)->existing_init_list;	
							}							
						}
    break;

  case 7:
#line 161 "src/parser.y"
    { 
	  						(yyval.node) = (yyvsp[(1) - (2)].node);
							(yyval.node)->next_node = (yyvsp[(2) - (2)].node);
	  					}
    break;

  case 8:
#line 165 "src/parser.y"
    {	(yyval.node) = (yyvsp[(1) - (1)].node); (yyval.node)->next_node = ((yyval.node)->next_node)?((yyval.node)->next_node):NULL;	}
    break;

  case 9:
#line 166 "src/parser.y"
    { 
	  						(yyval.node) = (yyvsp[(1) - (2)].node);
							(yyval.node)->next_node = (yyvsp[(2) - (2)].node);
	  					}
    break;

  case 10:
#line 170 "src/parser.y"
    {	(yyval.node) = (yyvsp[(1) - (1)].node); (yyval.node)->next_node = ((yyval.node)->next_node)?((yyval.node)->next_node):NULL;	}
    break;

  case 11:
#line 171 "src/parser.y"
    { 
	  						(yyval.node) = (yyvsp[(1) - (2)].node);
							(yyval.node)->next_node = (yyvsp[(2) - (2)].node);
	  					}
    break;

  case 12:
#line 175 "src/parser.y"
    {	(yyval.node) = (yyvsp[(1) - (1)].node); (yyval.node)->next_node = ((yyval.node)->next_node)?((yyval.node)->next_node):NULL;	}
    break;

  case 13:
#line 176 "src/parser.y"
    { 
	  						(yyval.node) = (yyvsp[(1) - (2)].node);
							(yyval.node)->next_node = (yyvsp[(2) - (2)].node);
	  					}
    break;

  case 14:
#line 180 "src/parser.y"
    {	(yyval.node) = (yyvsp[(1) - (1)].node); (yyval.node)->next_node = ((yyval.node)->next_node)?((yyval.node)->next_node):NULL;	}
    break;

  case 15:
#line 183 "src/parser.y"
    {
		    								(yyval.node) = create_node(AST_LIST);
										(yyval.node)->init_list_head = head;
										(yyval.node)->init_list_tail = tail;
										(yyval.node)->existing_init_list = NULL;
										(yyval.node)->next_node = (yyvsp[(1) - (1)].node);
									}
    break;

  case 16:
#line 190 "src/parser.y"
    {
										(yyval.node) = create_node(AST_LIST);
										(yyval.node)->init_list_head = head;
										(yyval.node)->init_list_tail = tail;
										(yyval.node)->existing_init_list = (yyvsp[(1) - (3)].node);
										(yyval.node)->next_node = (yyvsp[(3) - (3)].node);
									}
    break;

  case 18:
#line 200 "src/parser.y"
    {
								(yyval.node) = (yyvsp[(1) - (3)].node);
								// Initialized declarators turned out to be harder than expected!
								// $$ = create_node(AST_ASSIGNMENT);
								// $$->lval = $1;
								// $$->rval = $3;
							}
    break;

  case 19:
#line 209 "src/parser.y"
    {
		  				(yyval.node) = create_node(AST_STORAGE);
						(yyval.node)->storage_class = AUTO;
						(yyval.node)->next_node = NULL;
		 			}
    break;

  case 20:
#line 214 "src/parser.y"
    {
		  				(yyval.node) = create_node(AST_STORAGE);
						(yyval.node)->storage_class = EXTERN;
						(yyval.node)->next_node = NULL;
		 			}
    break;

  case 21:
#line 219 "src/parser.y"
    {
		  				(yyval.node) = create_node(AST_STORAGE);
						(yyval.node)->storage_class = REGISTER;
						(yyval.node)->next_node = NULL;
		 			}
    break;

  case 22:
#line 224 "src/parser.y"
    {
		  				(yyval.node) = create_node(AST_STORAGE);
						(yyval.node)->storage_class = STATIC;
						(yyval.node)->next_node = NULL;
		 			}
    break;

  case 23:
#line 229 "src/parser.y"
    {	// Not really storage, but whatever
						// We're not implementing this
		  				(yyval.node) = create_node(AST_STORAGE);
						(yyval.node)->storage_class = TYPEDEF;
						(yyval.node)->next_node = NULL;
		 			}
    break;

  case 24:
#line 237 "src/parser.y"
    {
	      			(yyval.node) = create_node(AST_QUALIFIER);
				(yyval.node)->qualifier = INLINE;
	      		}
    break;

  case 33:
#line 256 "src/parser.y"
    { 
	     							(yyval.node) = create_node(AST_ENUM);
								
	     						}
    break;

  case 34:
#line 260 "src/parser.y"
    { 
	     							(yyval.node) = create_node(AST_ENUM);
							}
    break;

  case 35:
#line 263 "src/parser.y"
    { 
	     							(yyval.node) = create_node(AST_ENUM);
							}
    break;

  case 36:
#line 266 "src/parser.y"
    { 
	     							(yyval.node) = create_node(AST_ENUM);
							}
    break;

  case 37:
#line 271 "src/parser.y"
    { }
    break;

  case 38:
#line 274 "src/parser.y"
    { }
    break;

  case 43:
#line 285 "src/parser.y"
    { }
    break;

  case 44:
#line 288 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = FLOAT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 45:
#line 293 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = FLOAT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 46:
#line 298 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = DOUBLE;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 48:
#line 306 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = FLOAT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 49:
#line 311 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = FLOAT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 50:
#line 316 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = DOUBLE;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 55:
#line 329 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = SHORT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 56:
#line 334 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = SHORT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 57:
#line 339 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = SHORT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 58:
#line 344 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = SHORT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 59:
#line 349 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = INT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 60:
#line 354 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = INT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 61:
#line 359 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = INT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 62:
#line 364 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = INT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 63:
#line 369 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = INT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 64:
#line 374 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = INT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 65:
#line 379 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = LONG;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 66:
#line 384 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = LONG;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 67:
#line 389 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = LONG;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 68:
#line 394 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = LONG;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 69:
#line 399 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = LONG;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 70:
#line 406 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = SHORT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 71:
#line 411 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = SHORT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 72:
#line 416 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = SHORT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 73:
#line 421 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = SHORT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 74:
#line 426 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = SHORT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 75:
#line 431 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = SHORT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 76:
#line 436 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = SHORT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 77:
#line 441 "src/parser.y"
    { 
	       						(yyval.node) = create_node(AST_SCALAR);
							(yyval.node)->scalar_type = SHORT;
							(yyval.node)->next_node = NULL;
	       					}
    break;

  case 78:
#line 448 "src/parser.y"
    { 
	       				(yyval.node) = create_node(AST_SCALAR);
					(yyval.node)->scalar_type = CHAR;
					(yyval.node)->next_node = NULL;
	       			}
    break;

  case 79:
#line 453 "src/parser.y"
    { 
	       				(yyval.node) = create_node(AST_SCALAR);
					(yyval.node)->scalar_type = CHAR;
					(yyval.node)->next_node = NULL;
	       			}
    break;

  case 80:
#line 458 "src/parser.y"
    { 
	       				(yyval.node) = create_node(AST_SCALAR);
					(yyval.node)->scalar_type = CHAR;
					(yyval.node)->next_node = NULL;
	       			}
    break;

  case 81:
#line 465 "src/parser.y"
    { 
	       			(yyval.node) = create_node(AST_SCALAR);
				(yyval.node)->scalar_type = _BOOL;
	       		}
    break;

  case 82:
#line 471 "src/parser.y"
    { }
    break;

  case 83:
#line 472 "src/parser.y"
    { }
    break;

  case 84:
#line 475 "src/parser.y"
    { }
    break;

  case 85:
#line 476 "src/parser.y"
    { }
    break;

  case 86:
#line 479 "src/parser.y"
    { }
    break;

  case 87:
#line 482 "src/parser.y"
    { }
    break;

  case 98:
#line 512 "src/parser.y"
    { }
    break;

  case 99:
#line 513 "src/parser.y"
    { }
    break;

  case 100:
#line 516 "src/parser.y"
    { }
    break;

  case 101:
#line 517 "src/parser.y"
    { }
    break;

  case 102:
#line 520 "src/parser.y"
    { }
    break;

  case 103:
#line 523 "src/parser.y"
    { }
    break;

  case 104:
#line 526 "src/parser.y"
    { 
	       			(yyval.node) = create_node(AST_SCALAR);
				(yyval.node)->scalar_type = VOID;
	       		}
    break;

  case 108:
#line 537 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 112:
#line 545 "src/parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 114:
#line 547 "src/parser.y"
    { }
    break;

  case 116:
#line 549 "src/parser.y"
    { }
    break;

  case 118:
#line 551 "src/parser.y"
    { }
    break;

  case 120:
#line 553 "src/parser.y"
    { }
    break;

  case 121:
#line 556 "src/parser.y"
    {
	      				(yyval.node) = create_node(AST_QUALIFIER);
					(yyval.node)->qualifier = CONST;
					(yyval.node)->next_node = NULL;
	      			}
    break;

  case 122:
#line 561 "src/parser.y"
    {
	      				(yyval.node) = create_node(AST_QUALIFIER);
					(yyval.node)->qualifier = VOLATILE;
					(yyval.node)->next_node = NULL;
	      			}
    break;

  case 123:
#line 566 "src/parser.y"
    {
	      				(yyval.node) = create_node(AST_QUALIFIER);
					(yyval.node)->qualifier = RESTRICT;
					(yyval.node)->next_node = NULL;
	      			}
    break;

  case 124:
#line 573 "src/parser.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 125:
#line 574 "src/parser.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); }
    break;

  case 127:
#line 578 "src/parser.y"
    { (yyval.node)=(yyvsp[(2) - (3)].node); }
    break;

  case 130:
#line 583 "src/parser.y"
    { 
		 			(yyval.node) = create_node(AST_IDENT);
					(yyval.node)->ident = (yyvsp[(1) - (1)].ident);
					head = tail = (yyval.node);
				}
    break;

  case 131:
#line 590 "src/parser.y"
    {
		  						(yyval.node) = (yyvsp[(1) - (2)].node);
								(yyvsp[(2) - (2)].node)->next_node = (yyval.node);
								for(struct ASTNODE *tn_search = (yyval.node); tn_search; tn_search = tn_search->next_node){
									tail = tn_search;
								}
		  					}
    break;

  case 132:
#line 599 "src/parser.y"
    { 
       								(yyval.node) = create_node(AST_POINTER);
								(yyval.node)->pointer_next = NULL;
								(yyval.node)->next_node = NULL;
						}
    break;

  case 133:
#line 604 "src/parser.y"
    { 
       								(yyval.node) = create_node(AST_POINTER);
								(yyval.node)->pointer_next = NULL;
								(yyval.node)->next_node = NULL;
						}
    break;

  case 134:
#line 609 "src/parser.y"
    { 
       								(yyval.node) = create_node(AST_POINTER);
								(yyval.node)->pointer_next = (yyvsp[(3) - (3)].node);
								(yyvsp[(3) - (3)].node)->next_node = (yyval.node);
						}
    break;

  case 135:
#line 614 "src/parser.y"
    { 
								(yyval.node) = create_node(AST_POINTER);
       								(yyval.node)->pointer_next = (yyvsp[(2) - (2)].node);
								(yyvsp[(2) - (2)].node)->next_node = (yyval.node);
						}
    break;

  case 136:
#line 628 "src/parser.y"
    {
									(yyval.node) = create_node(AST_ARRAY);
									(yyval.node)->array_defined = 1;
									(yyval.node)->array_size = (int) (yyvsp[(3) - (4)].num_lit).i_lit;
									(yyvsp[(1) - (4)].node)->next_node = (yyval.node);
									tail = (yyval.node);
								}
    break;

  case 137:
#line 635 "src/parser.y"
    { 
									(yyval.node) = create_node(AST_ARRAY);
									(yyval.node)->array_defined = 0;
									(yyval.node)->array_size = -1;
									(yyvsp[(1) - (3)].node)->next_node = (yyval.node);
									tail = (yyval.node);
								}
    break;

  case 139:
#line 647 "src/parser.y"
    {
	       									(yyval.node) = create_node(AST_FUNC);
									}
    break;

  case 140:
#line 651 "src/parser.y"
    {
										(yyval.node) = create_node(AST_FUNC);
									}
    break;

  case 141:
#line 654 "src/parser.y"
    {
										(yyval.node) = create_node(AST_FUNC);
										(yyval.node)->func_symbol_table = NULL;
										(yyval.node)->arg_no = -1;
										(yyvsp[(1) - (3)].node)->next_node = (yyval.node);
										tail = (yyval.node);
									}
    break;

  case 143:
#line 664 "src/parser.y"
    {
								(yyval.node) = (yyvsp[(1) - (3)].node);
							}
    break;

  case 148:
#line 677 "src/parser.y"
    { }
    break;

  case 149:
#line 678 "src/parser.y"
    { }
    break;

  case 151:
#line 682 "src/parser.y"
    { }
    break;

  case 152:
#line 683 "src/parser.y"
    { }
    break;

  case 160:
#line 699 "src/parser.y"
    { }
    break;

  case 161:
#line 700 "src/parser.y"
    { }
    break;

  case 162:
#line 704 "src/parser.y"
    { entering_function = 1; }
    break;

  case 163:
#line 704 "src/parser.y"
    { 
												(yyval.node) = create_node(AST_FUNC);
												(yyval.node)->func_body = (yyvsp[(3) - (3)].node);
												entering_function = 0; 
												print_node((yyvsp[(3) - (3)].node), 0);
											}
    break;

  case 181:
#line 736 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 182:
#line 739 "src/parser.y"
    { 
		 					
		 				}
    break;

  case 186:
#line 749 "src/parser.y"
    { 
		  			int new_scope_type = SCOPE_BLOCK;
					if(entering_function){
						new_scope_type = SCOPE_FUNC;
						entering_function = 0;
					}
		  			current_scope = enter_scope(current_scope, new_scope_type); 
				}
    break;

  case 187:
#line 756 "src/parser.y"
    { 
									(yyval.node) = (yyvsp[(3) - (4)].node);
									current_scope = escape_scope(current_scope); 
								}
    break;

  case 188:
#line 760 "src/parser.y"
    { }
    break;

  case 189:
#line 763 "src/parser.y"
    {
		      								(yyval.node) = create_node(AST_STATEMENT_LIST);
										(yyval.node)->statement_node = (yyvsp[(1) - (1)].node);
										(yyval.node)->next_node = NULL;
									}
    break;

  case 190:
#line 768 "src/parser.y"
    {
										(yyval.node) = (yyvsp[(1) - (2)].node);
										(yyval.node)->next_node = (yyvsp[(2) - (2)].node);
									}
    break;

  case 194:
#line 781 "src/parser.y"
    { 
	    									(yyval.node) = create_node(AST_IF);
										(yyval.node)->if_condition = (yyvsp[(3) - (5)].node);
										(yyval.node)->if_true = (yyvsp[(5) - (5)].node);
										(yyval.node)->if_false = NULL;
	    								}
    break;

  case 195:
#line 787 "src/parser.y"
    {
	    									(yyval.node) = create_node(AST_IF);
										(yyval.node)->if_condition = (yyvsp[(3) - (7)].node);
										(yyval.node)->if_true = (yyvsp[(5) - (7)].node);
										(yyval.node)->if_false = (yyvsp[(7) - (7)].node);
									}
    break;

  case 199:
#line 800 "src/parser.y"
    {  // This is likely wrong, but we can alter this to do better later
	    							(yyval.node) = create_node(AST_WHILE);
								(yyval.node)->while_condition = (yyvsp[(5) - (7)].node);
								(yyval.node)->while_true = (yyvsp[(2) - (7)].node);
							}
    break;

  case 200:
#line 807 "src/parser.y"
    { 
	    							(yyval.node) = create_node(AST_WHILE);
								(yyval.node)->while_condition = (yyvsp[(3) - (5)].node);
								(yyval.node)->while_true = (yyvsp[(5) - (5)].node);
							}
    break;

  case 201:
#line 814 "src/parser.y"
    { 
	     							(yyval.node) = (yyvsp[(2) - (3)].node);
								(yyval.node)->for_true = (yyvsp[(3) - (3)].node);
	     						}
    break;

  case 202:
#line 820 "src/parser.y"
    {
								(yyval.node) = create_node(AST_FOR);
								(yyval.node)->for_init = (yyvsp[(2) - (7)].node);
								(yyval.node)->for_condition = (yyvsp[(4) - (7)].node);
								(yyval.node)->for_iteration = (yyvsp[(6) - (7)].node);
							}
    break;

  case 203:
#line 826 "src/parser.y"
    {
								(yyval.node) = create_node(AST_FOR);
								(yyval.node)->for_init = (yyvsp[(2) - (6)].node);
								(yyval.node)->for_condition = (yyvsp[(4) - (6)].node);
								(yyval.node)->for_iteration = NULL;
							}
    break;

  case 204:
#line 832 "src/parser.y"
    {
								(yyval.node) = create_node(AST_FOR);
								(yyval.node)->for_init = (yyvsp[(2) - (6)].node);
								(yyval.node)->for_condition = NULL;
								(yyval.node)->for_iteration = (yyvsp[(5) - (6)].node);
							}
    break;

  case 205:
#line 838 "src/parser.y"
    {
								(yyval.node) = create_node(AST_FOR);
								(yyval.node)->for_init = (yyvsp[(2) - (5)].node);
								(yyval.node)->for_condition = NULL;
								(yyval.node)->for_iteration = NULL;
							}
    break;

  case 206:
#line 844 "src/parser.y"
    {
								(yyval.node) = create_node(AST_FOR);
								(yyval.node)->for_init = NULL;
								(yyval.node)->for_condition = (yyvsp[(3) - (6)].node);
								(yyval.node)->for_iteration = (yyvsp[(5) - (6)].node);
							}
    break;

  case 207:
#line 850 "src/parser.y"
    {
								(yyval.node) = create_node(AST_FOR);
								(yyval.node)->for_init = NULL;
								(yyval.node)->for_condition = (yyvsp[(3) - (5)].node);
								(yyval.node)->for_iteration = NULL;
							}
    break;

  case 208:
#line 856 "src/parser.y"
    {
								(yyval.node) = create_node(AST_FOR);
								(yyval.node)->for_init = NULL;
								(yyval.node)->for_condition = NULL;
								(yyval.node)->for_iteration = (yyvsp[(4) - (5)].node);
							}
    break;

  case 209:
#line 862 "src/parser.y"
    {
								(yyval.node) = create_node(AST_FOR);
								(yyval.node)->for_init = NULL;
								(yyval.node)->for_condition = NULL;
								(yyval.node)->for_iteration = NULL; 
							}
    break;

  case 212:
#line 874 "src/parser.y"
    { }
    break;

  case 215:
#line 883 "src/parser.y"
    { }
    break;

  case 216:
#line 886 "src/parser.y"
    { }
    break;

  case 217:
#line 889 "src/parser.y"
    { 
						(yyval.node) = create_node(AST_RETURN);
						(yyval.node)->return_value = (yyvsp[(2) - (3)].node);
					}
    break;

  case 218:
#line 893 "src/parser.y"
    {
						(yyval.node) = create_node(AST_RETURN);
						(yyval.node)->return_value = NULL;
					}
    break;

  case 219:
#line 899 "src/parser.y"
    { 
	      					(yyval.node) = create_node(AST_GOTO);
						(yyval.node)->goto_label = (yyvsp[(2) - (3)].node);
					}
    break;

  case 220:
#line 905 "src/parser.y"
    {
	   					(yyval.node) = create_node(AST_IDENT);
						(yyval.node)->ident = (yyvsp[(1) - (1)].ident);
					}
    break;

  case 221:
#line 911 "src/parser.y"
    { }
    break;

  case 223:
#line 918 "src/parser.y"
    {
	    			(yyval.node) = create_node(AST_IDENT);
				(yyval.node)->ident = (yyvsp[(1) - (1)].ident);
			}
    break;

  case 224:
#line 922 "src/parser.y"
    { 
				(yyval.node) = create_node(AST_NUM);
				populate_num_node((yyval.node), &(yyvsp[(1) - (1)].num_lit));
			}
    break;

  case 225:
#line 926 "src/parser.y"
    { 
				(yyval.node) = create_node(AST_STRINGLIT);
				(yyval.node)->string_lit = (yyvsp[(1) - (1)].string_lit).string_lit;
				(yyval.node)->string_size = (yyvsp[(1) - (1)].string_lit).string_size;
			}
    break;

  case 226:
#line 931 "src/parser.y"
    {
				(yyval.node) = create_node(AST_CHARLIT);
				(yyval.node)->char_lit = (yyvsp[(1) - (1)].char_lit);
			}
    break;

  case 227:
#line 935 "src/parser.y"
    { 
				(yyval.node) = (yyvsp[(2) - (3)].node);
			}
    break;

  case 235:
#line 949 "src/parser.y"
    {
	      						(yyval.node) = create_node(AST_UNARYOP);
							(yyval.node)->ast_unaryop = '*';
							struct ASTNODE* child = create_node(AST_BINOP);
							child->ast_binop = '+';
							child->left_binop = (yyvsp[(1) - (4)].node);
							child->right_binop = (yyvsp[(3) - (4)].node);
							(yyval.node)->single_op = child;
						}
    break;

  case 236:
#line 960 "src/parser.y"
    {
	      						(yyval.node) = create_node(AST_BINOP);
							(yyval.node)->ast_binop = '.';
							struct ASTNODE* child_ident = create_node(AST_IDENT);
							child_ident->ident = (yyvsp[(3) - (3)].ident);
							(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
							(yyval.node)->right_binop = child_ident;
						}
    break;

  case 237:
#line 968 "src/parser.y"
    {
	      						(yyval.node) = create_node(AST_BINOP);
							(yyval.node)->ast_binop = '.';
							struct ASTNODE* child_deref = create_node(AST_UNARYOP);
							struct ASTNODE* child_ident = create_node(AST_IDENT);
							child_deref->ast_unaryop = '*';
							child_deref->single_op = (yyvsp[(1) - (3)].node);
							child_ident->ident = (yyvsp[(3) - (3)].ident);
							(yyval.node)->left_binop = child_deref;
							(yyval.node)->right_binop = child_ident;
						}
    break;

  case 238:
#line 981 "src/parser.y"
    {
	     						(yyval.node) = create_node(AST_FUNC);
							(yyval.node)->func_name = (yyvsp[(1) - (4)].node);
							(yyval.node)->arg_no = (yyvsp[(3) - (4)].node)->expr_no;
							(yyval.node)->args = (yyvsp[(3) - (4)].node);
						}
    break;

  case 239:
#line 989 "src/parser.y"
    { 
							(yyval.node) = create_node(AST_ARGLIST);
							(yyval.node)->expr_no = 0;
							(yyval.node)->existing_list = NULL;
							(yyval.node)->new_expr = NULL;
	 					}
    break;

  case 240:
#line 995 "src/parser.y"
    {
							(yyval.node) = create_node(AST_ARGLIST);
							(yyval.node)->expr_no = 1;
							(yyval.node)->existing_list = NULL;
							(yyval.node)->new_expr = (yyvsp[(1) - (1)].node);
						}
    break;

  case 241:
#line 1001 "src/parser.y"
    { 
							(yyval.node) = create_node(AST_ARGLIST);
							(yyval.node)->expr_no = ((yyvsp[(1) - (3)].node)->expr_no)+1;
							(yyval.node)->existing_list = (yyvsp[(1) - (3)].node);
							(yyval.node)->new_expr = (yyvsp[(3) - (3)].node);
						}
    break;

  case 242:
#line 1009 "src/parser.y"
    {
						(yyval.node) = create_node(AST_UNARYOP);
						(yyval.node)->ast_unaryop = PLUSPLUS;
						(yyval.node)->single_op = (yyvsp[(1) - (2)].node);
					}
    break;

  case 243:
#line 1016 "src/parser.y"
    {
						(yyval.node) = create_node(AST_UNARYOP);
						(yyval.node)->ast_unaryop = MINUSMINUS;
						(yyval.node)->single_op = (yyvsp[(1) - (2)].node);
					}
    break;

  case 244:
#line 1023 "src/parser.y"
    { }
    break;

  case 245:
#line 1024 "src/parser.y"
    { }
    break;

  case 246:
#line 1027 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 247:
#line 1028 "src/parser.y"
    { 
							(yyval.node) = create_node(AST_CASTOP);
							(yyval.node)->single_cast = (yyvsp[(4) - (4)].node);
						}
    break;

  case 257:
#line 1043 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 258:
#line 1046 "src/parser.y"
    { 
	   						(yyval.node) = create_node(AST_UNARYOP);
							(yyval.node)->ast_unaryop = SIZEOF;
							(yyval.node)->single_op = (yyvsp[(2) - (2)].node);
	   					}
    break;

  case 259:
#line 1051 "src/parser.y"
    { }
    break;

  case 260:
#line 1054 "src/parser.y"
    {
						(yyval.node) = create_node(AST_UNARYOP);
						(yyval.node)->ast_unaryop = '-';
						(yyval.node)->single_op = (yyvsp[(2) - (2)].node);
					}
    break;

  case 261:
#line 1061 "src/parser.y"
    { 
						(yyval.node) = create_node(AST_UNARYOP);
						(yyval.node)->ast_unaryop = '+';
						(yyval.node)->single_op = (yyvsp[(2) - (2)].node);
					}
    break;

  case 262:
#line 1068 "src/parser.y"
    {
						(yyval.node) = create_node(AST_UNARYOP);
						(yyval.node)->ast_unaryop = '!';
						(yyval.node)->single_op = (yyvsp[(2) - (2)].node);
					}
    break;

  case 263:
#line 1075 "src/parser.y"
    {
						(yyval.node) = create_node(AST_UNARYOP);
						(yyval.node)->ast_unaryop = '~';
						(yyval.node)->single_op = (yyvsp[(2) - (2)].node);
					}
    break;

  case 264:
#line 1082 "src/parser.y"
    {
						(yyval.node) = create_node(AST_UNARYOP);
						(yyval.node)->ast_unaryop = '&';
						(yyval.node)->single_op = (yyvsp[(2) - (2)].node);
					}
    break;

  case 265:
#line 1089 "src/parser.y"
    {
						(yyval.node) = create_node(AST_UNARYOP);
						(yyval.node)->ast_unaryop = '*';
						(yyval.node)->single_op = (yyvsp[(2) - (2)].node);
					}
    break;

  case 266:
#line 1096 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '=';
						(yyval.node)->left_binop = (yyvsp[(2) - (2)].node);
						struct ASTNODE* child = create_node(AST_BINOP);
						struct ASTNODE* one = create_node(AST_NUM);
						one->i_lit = 1;
						one->sign_and_precision = I_LIT;
						child->ast_binop = '+';
						child->left_binop = (yyvsp[(2) - (2)].node);
						child->right_binop = one;
						(yyval.node)->right_binop = child;
					}
    break;

  case 267:
#line 1112 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '=';
						(yyval.node)->left_binop = (yyvsp[(2) - (2)].node);
						struct ASTNODE* child = create_node(AST_BINOP);
						struct ASTNODE* one = create_node(AST_NUM);
						one->i_lit = 1;
						one->sign_and_precision = I_LIT;
						child->ast_binop = '-';
						child->left_binop = (yyvsp[(2) - (2)].node);
						child->right_binop = one;
						(yyval.node)->right_binop = child;
					}
    break;

  case 269:
#line 1129 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '*';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 270:
#line 1135 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '/';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 271:
#line 1141 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '%';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 273:
#line 1150 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '+';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 274:
#line 1156 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '-';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 276:
#line 1165 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = SHL;
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 277:
#line 1171 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = SHR;
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 279:
#line 1180 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '<';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 280:
#line 1186 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '>';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 281:
#line 1192 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = GTEQ;
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 282:
#line 1198 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = LTEQ;
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 284:
#line 1207 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = EQEQ;
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 285:
#line 1213 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = NOTEQ;
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 287:
#line 1222 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '&';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 289:
#line 1231 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '^';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 291:
#line 1240 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '|';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 293:
#line 1249 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = LOGAND;
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 295:
#line 1258 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = LOGOR;
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 296:
#line 1266 "src/parser.y"
    {  }
    break;

  case 297:
#line 1267 "src/parser.y"
    {
						(yyval.node) = create_node(AST_TERNOP);
						(yyval.node)->left_ternop = (yyvsp[(1) - (5)].node);
						(yyval.node)->middle_ternop = (yyvsp[(3) - (5)].node);
						(yyval.node)->right_ternop = (yyvsp[(5) - (5)].node);
						}
    break;

  case 298:
#line 1275 "src/parser.y"
    { }
    break;

  case 299:
#line 1276 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '=';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
					}
    break;

  case 300:
#line 1282 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '=';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = '+';
						child->left_binop = (yyvsp[(1) - (3)].node);
						child->right_binop = (yyvsp[(3) - (3)].node);
						(yyval.node)->right_binop = child;
					}
    break;

  case 301:
#line 1292 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '=';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = '-';
						child->left_binop = (yyvsp[(1) - (3)].node);
						child->right_binop = (yyvsp[(3) - (3)].node);
						(yyval.node)->right_binop = child;
					}
    break;

  case 302:
#line 1302 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '=';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = '*';
						child->left_binop = (yyvsp[(1) - (3)].node);
						child->right_binop = (yyvsp[(3) - (3)].node);
						(yyval.node)->right_binop = child;
					}
    break;

  case 303:
#line 1312 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '=';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = '/';
						child->left_binop = (yyvsp[(1) - (3)].node);
						child->right_binop = (yyvsp[(3) - (3)].node);
						(yyval.node)->right_binop = child;
					}
    break;

  case 304:
#line 1322 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '=';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = '%';
						child->left_binop = (yyvsp[(1) - (3)].node);
						child->right_binop = (yyvsp[(3) - (3)].node);
						(yyval.node)->right_binop = child;
					}
    break;

  case 305:
#line 1332 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '=';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = SHL;
						child->left_binop = (yyvsp[(1) - (3)].node);
						child->right_binop = (yyvsp[(3) - (3)].node);
						(yyval.node)->right_binop = child;
					}
    break;

  case 306:
#line 1342 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '=';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = SHR;
						child->left_binop = (yyvsp[(1) - (3)].node);
						child->right_binop = (yyvsp[(3) - (3)].node);
						(yyval.node)->right_binop = child;
					}
    break;

  case 307:
#line 1352 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '=';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = '&';
						child->left_binop = (yyvsp[(1) - (3)].node);
						child->right_binop = (yyvsp[(3) - (3)].node);
						(yyval.node)->right_binop = child;
					}
    break;

  case 308:
#line 1362 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '=';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = '^';
						child->left_binop = (yyvsp[(1) - (3)].node);
						child->right_binop = (yyvsp[(3) - (3)].node);
						(yyval.node)->right_binop = child;
					}
    break;

  case 309:
#line 1372 "src/parser.y"
    {
						(yyval.node) = create_node(AST_BINOP);
						(yyval.node)->ast_binop = '=';
						(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = '|';
						child->left_binop = (yyvsp[(1) - (3)].node);
						child->right_binop = (yyvsp[(3) - (3)].node);
						(yyval.node)->right_binop = child;
					}
    break;

  case 310:
#line 1384 "src/parser.y"
    { }
    break;

  case 311:
#line 1385 "src/parser.y"
    {
							(yyval.node) = create_node(AST_BINOP);
							(yyval.node)->ast_binop = ',';
							(yyval.node)->left_binop = (yyvsp[(1) - (3)].node);
							(yyval.node)->right_binop = (yyvsp[(3) - (3)].node);
						}
    break;


/* Line 1267 of yacc.c.  */
#line 3990 "src/y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1393 "src/parser.y"


struct ASTNODE *create_node(int nodetype) {
	struct ASTNODE *newnode = malloc(sizeof(struct ASTNODE));
	if(!newnode) {
		yyerror("Fatal Error: Failed to allocate memory for new AST node");
		exit(-1);
	}
	newnode->nodetype = nodetype;
	return newnode;
}

void populate_num_node(struct ASTNODE *node, struct num_lit *number){
	node->sign_and_precision = number->sign_and_precision;
	
	// I'm pretty sure this switch doesn't need to be here, considering how unions
	// are supposed to work in C
	switch(node->sign_and_precision){
		case I_LIT:
			node->i_lit = number->i_lit;
			break;
		case I_LIT_U:
			node->i_lit_u = number->i_lit_u;
			break;
		case L_LIT:
			node->l_lit = number->l_lit;
			break;
		case L_LIT_U:
			node->l_lit_u = number->l_lit_u;
			break;
		case LL_LIT:
			node->ll_lit = number->ll_lit;
			break;
		case LL_LIT_U:
			node->ll_lit_u = number->ll_lit_u;
			break;
		case F_LIT:
			node->f_lit = number->f_lit;
			break;
		case D_LIT:
			node->d_lit = number->d_lit;
			break;
		case LD_LIT:
			node->ld_lit = number->ld_lit;
			break;
		default:
			node->i_lit = number->i_lit;
			break;
	}
	return;
}

