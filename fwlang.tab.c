/* A Bison parser, made by GNU Bison 2.0.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

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
     GROUP = 258,
     SERVICE = 259,
     QUERY = 260,
     INPUT = 261,
     FORWARD = 262,
     OUTPUT = 263,
     PACKET = 264,
     SPORT = 265,
     DPORT = 266,
     SADDY = 267,
     DADDY = 268,
     STATE = 269,
     UDP = 270,
     TCP = 271,
     ICMP = 272,
     BOTH = 273,
     NUM = 274,
     DOT = 275,
     LOGGED = 276,
     T_INVALID = 277,
     T_NEW = 278,
     T_ESTABLISHED = 279,
     T_RELATED = 280,
     FIN = 281,
     SYN = 282,
     RST = 283,
     PSH = 284,
     ACK = 285,
     URG = 286,
     NAME = 287,
     LPAREN = 288,
     RPAREN = 289,
     SEMI = 290,
     AND = 291,
     OR = 292,
     NOT = 293,
     WITH = 294,
     IN = 295,
     ON = 296,
     FOR = 297,
     TO = 298,
     FROM = 299
   };
#endif
#define GROUP 258
#define SERVICE 259
#define QUERY 260
#define INPUT 261
#define FORWARD 262
#define OUTPUT 263
#define PACKET 264
#define SPORT 265
#define DPORT 266
#define SADDY 267
#define DADDY 268
#define STATE 269
#define UDP 270
#define TCP 271
#define ICMP 272
#define BOTH 273
#define NUM 274
#define DOT 275
#define LOGGED 276
#define T_INVALID 277
#define T_NEW 278
#define T_ESTABLISHED 279
#define T_RELATED 280
#define FIN 281
#define SYN 282
#define RST 283
#define PSH 284
#define ACK 285
#define URG 286
#define NAME 287
#define LPAREN 288
#define RPAREN 289
#define SEMI 290
#define AND 291
#define OR 292
#define NOT 293
#define WITH 294
#define IN 295
#define ON 296
#define FOR 297
#define TO 298
#define FROM 299




/* Copy the first part of user declarations.  */
#line 1 "fwlang.y"

int yylex();
int yyerror(char* str);
#include "structures.h"


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 7 "fwlang.y"
typedef union YYSTYPE {
   int input_chain;
   char dummy;
   group* group_rec;
   service* service_rec;
   query* query_rec;
   condition* condition_rec;
   int sub;
   int sv;
   int fv;
   port* port_rec;
   char *name;
   address* address_rec;
   int prot;
   char* val;
} YYSTYPE;
/* Line 190 of yacc.c.  */
#line 187 "fwlang.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 213 of yacc.c.  */
#line 199 "fwlang.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   83

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  20
/* YYNRULES -- Number of rules. */
#define YYNRULES  60
/* YYNRULES -- Number of states. */
#define YYNSTATES  87

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    17,    19,    23,
      27,    30,    32,    35,    37,    41,    46,    48,    50,    52,
      54,    56,    58,    60,    62,    64,    66,    70,    74,    77,
      81,    83,    86,    89,    92,    95,    98,   101,   103,   105,
     107,   109,   111,   113,   115,   117,   119,   121,   123,   125,
     127,   129,   132,   134,   136,   138,   140,   148,   154,   158,
     160
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      46,     0,    -1,    47,    -1,    47,    46,    -1,    48,    35,
      -1,    49,    35,    -1,    52,    35,    -1,    35,    -1,     3,
      32,    50,    -1,     4,    32,    51,    -1,    50,    63,    -1,
      63,    -1,    51,    61,    -1,    61,    -1,     5,    54,    55,
      -1,     5,    54,    53,    55,    -1,     6,    -1,     7,    -1,
       8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,
      13,    -1,    14,    -1,    56,    -1,    55,    36,    55,    -1,
      55,    37,    55,    -1,    38,    55,    -1,    33,    55,    34,
      -1,    21,    -1,    44,    57,    -1,    43,    57,    -1,    41,
      58,    -1,    42,    58,    -1,    40,    59,    -1,    39,    60,
      -1,    32,    -1,    63,    -1,    32,    -1,    61,    -1,    22,
      -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,
      -1,    28,    -1,    29,    -1,    30,    -1,    31,    -1,    62,
      64,    -1,    17,    -1,    15,    -1,    16,    -1,    18,    -1,
      19,    20,    19,    20,    19,    20,    19,    -1,    19,    20,
      19,    20,    19,    -1,    19,    20,    19,    -1,    19,    -1,
      19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned char yyrline[] =
{
       0,    64,    64,    64,    65,    66,    67,    68,    71,    73,
      75,    76,    78,    79,    81,    82,    84,    85,    86,    88,
      89,    90,    91,    92,    93,    96,    97,    98,    99,   100,
     101,   104,   105,   106,   107,   108,   109,   112,   113,   115,
     116,   118,   118,   118,   118,   120,   120,   120,   120,   120,
     120,   122,   124,   124,   124,   124,   126,   127,   128,   129,
     131
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "GROUP", "SERVICE", "QUERY", "INPUT",
  "FORWARD", "OUTPUT", "PACKET", "SPORT", "DPORT", "SADDY", "DADDY",
  "STATE", "UDP", "TCP", "ICMP", "BOTH", "NUM", "DOT", "LOGGED",
  "T_INVALID", "T_NEW", "T_ESTABLISHED", "T_RELATED", "FIN", "SYN", "RST",
  "PSH", "ACK", "URG", "NAME", "LPAREN", "RPAREN", "SEMI", "AND", "OR",
  "NOT", "WITH", "IN", "ON", "FOR", "TO", "FROM", "$accept", "statement",
  "expression", "group_expression", "service_expression", "addy_list",
  "port_list", "query_expression", "input_chain", "subject", "condition",
  "simple_condition", "compound_addy", "compound_port", "state_value",
  "flag_name", "complete_port", "protocol", "addr", "port", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    45,    46,    46,    47,    47,    47,    47,    48,    49,
      50,    50,    51,    51,    52,    52,    53,    53,    53,    54,
      54,    54,    54,    54,    54,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    57,    57,    58,
      58,    59,    59,    59,    59,    60,    60,    60,    60,    60,
      60,    61,    62,    62,    62,    62,    63,    63,    63,    63,
      64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     1,     3,     3,
       2,     1,     2,     1,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     3,
       1,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     7,     5,     3,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     0,     7,     0,     2,     0,     0,     0,
       0,     0,    19,    20,    21,    22,    23,    24,     0,     1,
       3,     4,     5,     6,    59,     8,    11,    53,    54,    52,
      55,     9,    13,     0,    16,    17,    18,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    25,     0,
      10,    12,    60,    51,     0,    28,    45,    46,    47,    48,
      49,    50,    36,    41,    42,    43,    44,    35,    39,    33,
      40,    34,    37,    32,    38,    31,    15,     0,     0,    58,
      29,    26,    27,     0,    57,     0,    56
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     5,     6,     7,     8,    25,    31,     9,    46,    18,
      47,    48,    73,    69,    67,    62,    70,    33,    74,    53
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -39
static const yysigned_char yypact[] =
{
      -1,    -5,     6,    52,   -39,    26,    -1,    -7,     0,    17,
      34,     1,   -39,   -39,   -39,   -39,   -39,   -39,     3,   -39,
     -39,   -39,   -39,   -39,    53,    34,   -39,   -39,   -39,   -39,
     -39,     1,   -39,    55,   -39,   -39,   -39,   -39,    16,    16,
      41,     8,    -3,    -3,   -12,   -12,    16,   -14,   -39,    56,
     -39,   -39,   -39,   -39,    14,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -14,    16,    16,    57,
     -39,    39,   -39,    59,    60,    62,   -39
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -39,    73,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -38,   -39,    37,    40,   -39,   -39,    -6,   -39,    -4,   -39
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      54,    55,     1,     2,     3,    32,    26,    24,    76,    34,
      35,    36,    27,    28,    29,    30,    27,    28,    29,    30,
      72,    50,    77,    78,    37,    51,    19,    10,    21,    68,
      63,    64,    65,    66,     4,    22,    38,    37,    11,    81,
      82,    39,    40,    41,    42,    43,    44,    45,    80,    38,
      77,    78,    23,    24,    39,    40,    41,    42,    43,    44,
      45,    12,    13,    14,    15,    16,    17,    56,    57,    58,
      59,    60,    61,    49,    52,    79,    78,    83,    84,    20,
      85,    86,    75,    71
};

static const unsigned char yycheck[] =
{
      38,    39,     3,     4,     5,    11,    10,    19,    46,     6,
       7,     8,    15,    16,    17,    18,    15,    16,    17,    18,
      32,    25,    36,    37,    21,    31,     0,    32,    35,    32,
      22,    23,    24,    25,    35,    35,    33,    21,    32,    77,
      78,    38,    39,    40,    41,    42,    43,    44,    34,    33,
      36,    37,    35,    19,    38,    39,    40,    41,    42,    43,
      44,     9,    10,    11,    12,    13,    14,    26,    27,    28,
      29,    30,    31,    20,    19,    19,    37,    20,    19,     6,
      20,    19,    45,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,     4,     5,    35,    46,    47,    48,    49,    52,
      32,    32,     9,    10,    11,    12,    13,    14,    54,     0,
      46,    35,    35,    35,    19,    50,    63,    15,    16,    17,
      18,    51,    61,    62,     6,     7,     8,    21,    33,    38,
      39,    40,    41,    42,    43,    44,    53,    55,    56,    20,
      63,    61,    19,    64,    55,    55,    26,    27,    28,    29,
      30,    31,    60,    22,    23,    24,    25,    59,    32,    58,
      61,    58,    32,    57,    63,    57,    55,    36,    37,    19,
      34,    55,    55,    20,    19,    20,    19
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
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
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
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
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  register short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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


  yyvsp[0] = yylval;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
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

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

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

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
        case 8:
#line 71 "fwlang.y"
    {(yyval.group_rec) = DefineGroup((yyvsp[-1].name), (yyvsp[0].address_rec));;}
    break;

  case 9:
#line 73 "fwlang.y"
    {(yyval.service_rec) = DefineService((yyvsp[-1].name), (yyvsp[0].port_rec));;}
    break;

  case 10:
#line 75 "fwlang.y"
    {(yyval.address_rec) = AppendAddy((yyvsp[-1].address_rec),(yyvsp[0].address_rec));;}
    break;

  case 11:
#line 76 "fwlang.y"
    {(yyval.address_rec) = AppendAddy(NULL, (yyvsp[0].address_rec));;}
    break;

  case 12:
#line 78 "fwlang.y"
    {(yyval.port_rec) = AppendPort((yyvsp[-1].port_rec), (yyvsp[0].port_rec));;}
    break;

  case 13:
#line 79 "fwlang.y"
    {(yyval.port_rec) = AppendPort(NULL, (yyvsp[0].port_rec));;}
    break;

  case 14:
#line 81 "fwlang.y"
    {(yyval.query_rec) = PerformQuery((yyvsp[-1].sub), (yyvsp[0].condition_rec), 1);;}
    break;

  case 15:
#line 82 "fwlang.y"
    {(yyval.query_rec) = PerformQuery((yyvsp[-2].sub), (yyvsp[0].condition_rec), (yyvsp[-1].input_chain));}
    break;

  case 16:
#line 84 "fwlang.y"
    {(yyval.input_chain) = 0;;}
    break;

  case 17:
#line 85 "fwlang.y"
    {(yyval.input_chain) = 1;;}
    break;

  case 18:
#line 86 "fwlang.y"
    {(yyval.input_chain) = 2;;}
    break;

  case 19:
#line 88 "fwlang.y"
    {(yyval.sub)=0;;}
    break;

  case 20:
#line 89 "fwlang.y"
    {(yyval.sub)=1;;}
    break;

  case 21:
#line 90 "fwlang.y"
    {(yyval.sub)=2;;}
    break;

  case 22:
#line 91 "fwlang.y"
    {(yyval.sub)=3;;}
    break;

  case 23:
#line 92 "fwlang.y"
    {(yyval.sub)=4;;}
    break;

  case 24:
#line 93 "fwlang.y"
    {(yyval.sub)=5;;}
    break;

  case 25:
#line 96 "fwlang.y"
    {(yyval.condition_rec) = (yyvsp[0].condition_rec);;}
    break;

  case 26:
#line 97 "fwlang.y"
    {(yyval.condition_rec) = IntersectConditions((yyvsp[-2].condition_rec),(yyvsp[0].condition_rec));;}
    break;

  case 27:
#line 98 "fwlang.y"
    {(yyval.condition_rec) = UnionConditions((yyvsp[-2].condition_rec),(yyvsp[0].condition_rec));;}
    break;

  case 28:
#line 99 "fwlang.y"
    {(yyval.condition_rec) = NegateCondition((yyvsp[0].condition_rec));;}
    break;

  case 29:
#line 100 "fwlang.y"
    {(yyval.condition_rec) = (yyvsp[-1].condition_rec);;}
    break;

  case 30:
#line 101 "fwlang.y"
    { (yyval.condition_rec) = GetLoggedCondition();;}
    break;

  case 31:
#line 104 "fwlang.y"
    {(yyval.condition_rec)=BuildConditionFromGroup((yyvsp[0].group_rec), 0);;}
    break;

  case 32:
#line 105 "fwlang.y"
    {(yyval.condition_rec)=BuildConditionFromGroup((yyvsp[0].group_rec),1);;}
    break;

  case 33:
#line 106 "fwlang.y"
    {(yyval.condition_rec)=BuildConditionFromService((yyvsp[0].service_rec), 0);;}
    break;

  case 34:
#line 107 "fwlang.y"
    {(yyval.condition_rec)=BuildConditionFromService((yyvsp[0].service_rec), 1);;}
    break;

  case 35:
#line 108 "fwlang.y"
    {(yyval.condition_rec)=BuildConditionFromState((yyvsp[0].sv));;}
    break;

  case 36:
#line 109 "fwlang.y"
    {(yyval.condition_rec)=BuildConditionFromFlag((yyvsp[0].fv));;}
    break;

  case 37:
#line 112 "fwlang.y"
    {(yyval.group_rec) = GroupLookup((yyvsp[0].name));;}
    break;

  case 38:
#line 113 "fwlang.y"
    {(yyval.group_rec) = BuildGroupFromAddress((yyvsp[0].address_rec));;}
    break;

  case 39:
#line 115 "fwlang.y"
    {(yyval.service_rec) = ServiceLookup((yyvsp[0].name));;}
    break;

  case 40:
#line 116 "fwlang.y"
    {(yyval.service_rec) = BuildServiceFromPort((yyvsp[0].port_rec));;}
    break;

  case 41:
#line 118 "fwlang.y"
    {(yyval.sv)=0;;}
    break;

  case 42:
#line 118 "fwlang.y"
    {(yyval.sv)=1;;}
    break;

  case 43:
#line 118 "fwlang.y"
    {(yyval.sv)=2;;}
    break;

  case 44:
#line 118 "fwlang.y"
    {(yyval.sv)=3;;}
    break;

  case 45:
#line 120 "fwlang.y"
    {(yyval.fv)=0;;}
    break;

  case 46:
#line 120 "fwlang.y"
    {(yyval.fv)=1;;}
    break;

  case 47:
#line 120 "fwlang.y"
    {(yyval.fv)=2;;}
    break;

  case 48:
#line 120 "fwlang.y"
    {(yyval.fv)=3;;}
    break;

  case 49:
#line 120 "fwlang.y"
    {(yyval.fv)=4;;}
    break;

  case 50:
#line 120 "fwlang.y"
    {(yyval.fv)=5;;}
    break;

  case 51:
#line 122 "fwlang.y"
    {(yyval.port_rec) = BuildPort((yyvsp[-1].prot), (yyvsp[0].port_rec));;}
    break;

  case 52:
#line 124 "fwlang.y"
    {(yyval.prot) = 0;;}
    break;

  case 53:
#line 124 "fwlang.y"
    {(yyval.prot) = 1;;}
    break;

  case 54:
#line 124 "fwlang.y"
    { (yyval.prot) = 2;;}
    break;

  case 55:
#line 124 "fwlang.y"
    { (yyval.prot) = -1;;}
    break;

  case 56:
#line 126 "fwlang.y"
    {(yyval.address_rec) = ParseAddr((yyvsp[-6].val),(yyvsp[-4].val),(yyvsp[-2].val),(yyvsp[0].val));;}
    break;

  case 57:
#line 127 "fwlang.y"
    {(yyval.address_rec)=ParseAddr((yyvsp[-4].val),(yyvsp[-2].val),(yyvsp[0].val),NULL);;}
    break;

  case 58:
#line 128 "fwlang.y"
    {(yyval.address_rec)=ParseAddr((yyvsp[-2].val),(yyvsp[0].val),NULL,NULL);;}
    break;

  case 59:
#line 129 "fwlang.y"
    {(yyval.address_rec)=ParseAddr((yyvsp[0].val),NULL,NULL,NULL);;}
    break;

  case 60:
#line 131 "fwlang.y"
    {(yyval.port_rec)=ParsePort((yyvsp[0].val));;}
    break;


    }

/* Line 1037 of yacc.c.  */
#line 1456 "fwlang.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {

		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 yydestruct ("Error: popping",
                             yystos[*yyssp], yyvsp);
	       }
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
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

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

yyvsp -= yylen;
  yyssp -= yylen;
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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
  yydestruct ("Error: discarding lookahead",
              yytoken, &yylval);
  yychar = YYEMPTY;
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}



