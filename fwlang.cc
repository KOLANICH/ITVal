/* A Bison parser, made by GNU Bison 2.2.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++

   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.

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


#include "src/fwlang.tab.hh"

/* User implementation prologue.  */
YY_DECL;

/* Line 317 of lalr1.cc.  */
#line 43 "fwlang.cc"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG							\
  for (bool yydebugcond_ = yydebug_; yydebugcond_; yydebugcond_ = false)	\
    (*yycdebug_)

/* Enable debugging if requested.  */
#if YYDEBUG

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab

namespace yy
{
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  parser::parser (parser_interface& pi_yyarg)
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
      pi (pi_yyarg)
  {
  }

  parser::~parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif /* ! YYDEBUG */

  void
  parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }


  int
  parser::parse ()
  {
    /// Look-ahead and look-ahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the look-ahead.
    semantic_type yylval;
    /// Location of the look-ahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;
    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without look-ahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a look-ahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc, pi);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Accept?  */
    if (yyn == yyfinal_)
      goto yyacceptlab;

    /* Shift the look-ahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted unless it is eof.  */
    if (yychar != yyeof_)
      yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 9:
#line 97 "fwlang.yy"
    {(yyval.group_rec) = DefineGroup((yysemantic_stack_[(3) - (2)].name), (yysemantic_stack_[(3) - (3)].address_rec)); delete[] (yysemantic_stack_[(3) - (2)].name);}
    break;

  case 10:
#line 99 "fwlang.yy"
    {(yyval.service_rec) = DefineService((yysemantic_stack_[(3) - (2)].name), (yysemantic_stack_[(3) - (3)].port_rec)); delete[] (yysemantic_stack_[(3) - (2)].name);}
    break;

  case 11:
#line 101 "fwlang.yy"
    {(yyval.address_rec) = AppendAddy((yysemantic_stack_[(2) - (1)].address_rec),(yysemantic_stack_[(2) - (2)].address_rec));}
    break;

  case 12:
#line 102 "fwlang.yy"
    {(yyval.address_rec) = AppendAddy(NULL, (yysemantic_stack_[(1) - (1)].address_rec));}
    break;

  case 13:
#line 104 "fwlang.yy"
    {(yyval.port_rec) = AppendPort((yysemantic_stack_[(2) - (1)].port_rec), (yysemantic_stack_[(2) - (2)].port_rec));}
    break;

  case 14:
#line 105 "fwlang.yy"
    {(yyval.port_rec) = AppendPort(NULL, (yysemantic_stack_[(1) - (1)].port_rec));}
    break;

  case 15:
#line 107 "fwlang.yy"
    {(yyval.query_rec) = PrintClasses();}
    break;

  case 16:
#line 108 "fwlang.yy"
    {(yyval.query_rec) = PrintServiceClasses();}
    break;

  case 17:
#line 109 "fwlang.yy"
    {(yyval.query_rec) = PrintServiceGraph();}
    break;

  case 18:
#line 110 "fwlang.yy"
    {(yyval.query_rec) = PerformQuery((yysemantic_stack_[(3) - (2)].sub), (yysemantic_stack_[(3) - (3)].condition_rec));}
    break;

  case 19:
#line 116 "fwlang.yy"
    {(yyval.assert_rec) = PerformAssertion((yysemantic_stack_[(4) - (2)].condition_rec), (yysemantic_stack_[(4) - (4)].condition_rec), (yysemantic_stack_[(4) - (3)].assert_op), 0, 0);}
    break;

  case 20:
#line 117 "fwlang.yy"
    {(yyval.assert_rec) = PerformAssertion((yysemantic_stack_[(5) - (3)].condition_rec), (yysemantic_stack_[(5) - (5)].condition_rec), (yysemantic_stack_[(5) - (4)].assert_op), 1, 0);}
    break;

  case 21:
#line 118 "fwlang.yy"
    {(yyval.assert_rec) = PerformAssertion((yysemantic_stack_[(5) - (3)].condition_rec), (yysemantic_stack_[(5) - (5)].condition_rec), (yysemantic_stack_[(5) - (4)].assert_op), 0, 1);}
    break;

  case 22:
#line 119 "fwlang.yy"
    {(yyval.assert_rec) = PerformAssertion((yysemantic_stack_[(6) - (4)].condition_rec), (yysemantic_stack_[(6) - (6)].condition_rec), (yysemantic_stack_[(6) - (5)].assert_op), 1,1);}
    break;

  case 23:
#line 122 "fwlang.yy"
    {(yyval.assert_op) = 0;}
    break;

  case 24:
#line 123 "fwlang.yy"
    {(yyval.assert_op)=1;}
    break;

  case 25:
#line 124 "fwlang.yy"
    {(yyval.assert_op) = 2;}
    break;

  case 26:
#line 125 "fwlang.yy"
    {(yyval.assert_op) = 3;}
    break;

  case 27:
#line 128 "fwlang.yy"
    {(yyval.input_chain) = 0;}
    break;

  case 28:
#line 129 "fwlang.yy"
    {(yyval.input_chain) = 1;}
    break;

  case 29:
#line 130 "fwlang.yy"
    {(yyval.input_chain) = 2;}
    break;

  case 30:
#line 133 "fwlang.yy"
    {(yyval.sub)=0;}
    break;

  case 31:
#line 134 "fwlang.yy"
    {(yyval.sub)=1;}
    break;

  case 32:
#line 135 "fwlang.yy"
    {(yyval.sub)=2;}
    break;

  case 33:
#line 136 "fwlang.yy"
    {(yyval.sub)=3;}
    break;

  case 34:
#line 137 "fwlang.yy"
    {(yyval.sub)=4;}
    break;

  case 35:
#line 138 "fwlang.yy"
    {(yyval.sub)=5;}
    break;

  case 36:
#line 142 "fwlang.yy"
    {(yyval.condition_rec) = (yysemantic_stack_[(1) - (1)].condition_rec);}
    break;

  case 37:
#line 143 "fwlang.yy"
    {(yyval.condition_rec) = IntersectConditions((yysemantic_stack_[(3) - (1)].condition_rec),(yysemantic_stack_[(3) - (3)].condition_rec));}
    break;

  case 38:
#line 144 "fwlang.yy"
    {(yyval.condition_rec) = UnionConditions((yysemantic_stack_[(3) - (1)].condition_rec),(yysemantic_stack_[(3) - (3)].condition_rec));}
    break;

  case 39:
#line 145 "fwlang.yy"
    {(yyval.condition_rec) = NegateCondition((yysemantic_stack_[(2) - (2)].condition_rec));}
    break;

  case 40:
#line 146 "fwlang.yy"
    {(yyval.condition_rec) = (yysemantic_stack_[(3) - (2)].condition_rec);}
    break;

  case 41:
#line 147 "fwlang.yy"
    { (yyval.condition_rec) = GetLoggedCondition((yysemantic_stack_[(2) - (2)].input_chain));}
    break;

  case 42:
#line 150 "fwlang.yy"
    {(yyval.condition_rec)=BuildConditionFromGroup((yysemantic_stack_[(2) - (2)].group_rec), 0);}
    break;

  case 43:
#line 151 "fwlang.yy"
    {(yyval.condition_rec)=BuildConditionFromGroup((yysemantic_stack_[(2) - (2)].group_rec),1);}
    break;

  case 44:
#line 152 "fwlang.yy"
    {(yyval.condition_rec)=BuildConditionFromService((yysemantic_stack_[(2) - (2)].service_rec), 0);}
    break;

  case 45:
#line 153 "fwlang.yy"
    {(yyval.condition_rec)=BuildConditionFromService((yysemantic_stack_[(2) - (2)].service_rec), 1);}
    break;

  case 46:
#line 154 "fwlang.yy"
    {(yyval.condition_rec)=BuildConditionFromState((yysemantic_stack_[(2) - (2)].sv));}
    break;

  case 47:
#line 155 "fwlang.yy"
    {(yyval.condition_rec)=BuildConditionFromFlag((yysemantic_stack_[(2) - (2)].fv));}
    break;

  case 48:
#line 156 "fwlang.yy"
    {(yyval.condition_rec)=BuildConditionFromIface((yysemantic_stack_[(2) - (2)].name), 0); delete[] (yysemantic_stack_[(2) - (2)].name);}
    break;

  case 49:
#line 157 "fwlang.yy"
    {(yyval.condition_rec)=BuildConditionFromIface((yysemantic_stack_[(2) - (2)].name), 1); delete[] (yysemantic_stack_[(2) - (2)].name);}
    break;

  case 50:
#line 158 "fwlang.yy"
    {(yyval.condition_rec)=BuildAcceptCondition((yysemantic_stack_[(2) - (2)].input_chain));}
    break;

  case 51:
#line 159 "fwlang.yy"
    {(yyval.condition_rec)=BuildDropCondition((yysemantic_stack_[(2) - (2)].input_chain));}
    break;

  case 52:
#line 160 "fwlang.yy"
    {(yyval.condition_rec)=BuildAcceptCondition(1);}
    break;

  case 53:
#line 161 "fwlang.yy"
    {(yyval.condition_rec)=BuildDropCondition(1);}
    break;

  case 54:
#line 164 "fwlang.yy"
    {(yyval.group_rec) = GroupLookup((yysemantic_stack_[(1) - (1)].name)); delete[] (yysemantic_stack_[(1) - (1)].name);}
    break;

  case 55:
#line 165 "fwlang.yy"
    {(yyval.group_rec) = BuildGroupFromAddress((yysemantic_stack_[(1) - (1)].address_rec));}
    break;

  case 56:
#line 167 "fwlang.yy"
    {(yyval.service_rec) = ServiceLookup((yysemantic_stack_[(1) - (1)].name)); delete[] (yysemantic_stack_[(1) - (1)].name);}
    break;

  case 57:
#line 168 "fwlang.yy"
    {(yyval.service_rec) = BuildServiceFromPort((yysemantic_stack_[(1) - (1)].port_rec));}
    break;

  case 58:
#line 170 "fwlang.yy"
    {(yyval.sv)=0;}
    break;

  case 59:
#line 170 "fwlang.yy"
    {(yyval.sv)=1;}
    break;

  case 60:
#line 170 "fwlang.yy"
    {(yyval.sv)=2;}
    break;

  case 61:
#line 170 "fwlang.yy"
    {(yyval.sv)=3;}
    break;

  case 62:
#line 172 "fwlang.yy"
    {(yyval.fv)=0;}
    break;

  case 63:
#line 172 "fwlang.yy"
    {(yyval.fv)=1;}
    break;

  case 64:
#line 172 "fwlang.yy"
    {(yyval.fv)=2;}
    break;

  case 65:
#line 172 "fwlang.yy"
    {(yyval.fv)=3;}
    break;

  case 66:
#line 172 "fwlang.yy"
    {(yyval.fv)=4;}
    break;

  case 67:
#line 172 "fwlang.yy"
    {(yyval.fv)=5;}
    break;

  case 68:
#line 174 "fwlang.yy"
    {(yyval.port_rec) = BuildPort((yysemantic_stack_[(2) - (1)].prot), (yysemantic_stack_[(2) - (2)].port_rec));}
    break;

  case 69:
#line 176 "fwlang.yy"
    {(yyval.prot) = 0;}
    break;

  case 70:
#line 176 "fwlang.yy"
    {(yyval.prot) = 1;}
    break;

  case 71:
#line 176 "fwlang.yy"
    { (yyval.prot) = 2;}
    break;

  case 72:
#line 176 "fwlang.yy"
    { (yyval.prot) = -1;}
    break;

  case 73:
#line 178 "fwlang.yy"
    {(yyval.address_rec) = ParseAddr((yysemantic_stack_[(7) - (1)].val),(yysemantic_stack_[(7) - (3)].val),(yysemantic_stack_[(7) - (5)].val),(yysemantic_stack_[(7) - (7)].val)); delete[] (yysemantic_stack_[(7) - (1)].val); delete[] (yysemantic_stack_[(7) - (3)].val); delete[] (yysemantic_stack_[(7) - (5)].val); delete[] (yysemantic_stack_[(7) - (7)].val);}
    break;

  case 74:
#line 179 "fwlang.yy"
    {(yyval.address_rec)=ParseAddr((yysemantic_stack_[(5) - (1)].val),(yysemantic_stack_[(5) - (3)].val),(yysemantic_stack_[(5) - (5)].val),NULL); delete[] (yysemantic_stack_[(5) - (1)].val); delete[] (yysemantic_stack_[(5) - (3)].val); delete[] (yysemantic_stack_[(5) - (5)].val);}
    break;

  case 75:
#line 180 "fwlang.yy"
    {(yyval.address_rec)=ParseAddr((yysemantic_stack_[(3) - (1)].val),(yysemantic_stack_[(3) - (3)].val),NULL,NULL); delete[] (yysemantic_stack_[(3) - (1)].val); delete[] (yysemantic_stack_[(3) - (3)].val);}
    break;

  case 76:
#line 181 "fwlang.yy"
    {(yyval.address_rec)=ParseAddr((yysemantic_stack_[(1) - (1)].val),NULL,NULL,NULL); delete[] (yysemantic_stack_[(1) - (1)].val);}
    break;

  case 77:
#line 183 "fwlang.yy"
    {(yyval.port_rec)=ParsePort((yysemantic_stack_[(1) - (1)].val)); delete[] (yysemantic_stack_[(1) - (1)].val);}
    break;


    /* Line 675 of lalr1.cc.  */
#line 734 "fwlang.cc"
	default: break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
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
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    if (yyn == yyfinal_)
      goto yyacceptlab;

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the look-ahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		   &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyeof_ && yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char parser::yypact_ninf_ = -51;
  const signed char
  parser::yypact_[] =
  {
         2,   -38,   -26,   104,    13,   -51,    29,     2,   -28,   -27,
     -22,   -21,    22,    58,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -24,    34,   -24,     3,   -24,   -24,     3,
       3,    24,    31,    23,    65,    -2,    -2,   -16,   -16,     5,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,    46,    22,   -51,
     -51,   -51,   -51,   -51,    58,   -51,    51,   -40,   -24,     5,
       5,   -51,   -51,   -51,   -51,   -50,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -24,   -24,   -24,    70,   -51,
     -51,   -51,   -51,     5,   -24,   -24,   -51,    33,   -51,   -40,
      76,   -24,   -40,   -40,    78,   -40,    79,   100,   -51
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     8,     0,     2,     0,     0,
       0,     0,     0,     0,    30,    31,    32,    33,    34,    35,
      15,    16,    17,     0,     0,     0,     0,     0,     0,    53,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,     1,     3,     4,     5,     6,     7,    76,     9,    12,
      70,    71,    69,    72,    10,    14,     0,    18,     0,     0,
       0,    27,    28,    29,    41,     0,    39,    51,    50,    49,
      48,    62,    63,    64,    65,    66,    67,    47,    58,    59,
      60,    61,    46,    56,    44,    57,    45,    54,    43,    55,
      42,    23,    25,    24,    26,     0,     0,     0,     0,    11,
      13,    77,    68,     0,     0,     0,    40,    37,    38,    19,
      75,     0,    20,    21,     0,    22,    74,     0,    73
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  parser::yypgoto_[] =
  {
       -51,   123,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -41,
       4,   -51,   -23,   -51,    93,    96,   -51,   -51,   -10,   -51,
      -5,   -51
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  parser::yydefgoto_[] =
  {
        -1,     6,     7,     8,     9,    48,    54,    10,    11,    97,
      64,    23,    39,    40,    88,    84,    82,    77,    85,    56,
      89,   102
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char parser::yytable_ninf_ = -1;
  const unsigned char
  parser::yytable_[] =
  {
        57,    59,    60,    55,    65,    66,     1,    49,     2,    12,
       3,    26,     4,    47,    61,    62,    63,   106,   104,   105,
      95,    13,    96,    50,    51,    52,    53,    24,    25,    41,
      95,    87,    96,    67,    68,   103,    91,    92,    93,    94,
      43,    44,    27,    99,   100,    83,    45,    46,    26,    58,
      28,    47,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,   111,    71,    72,    73,    74,    75,    76,    26,
       5,    69,   107,   108,   109,    95,    98,    96,    70,    27,
     101,   112,   113,    50,    51,    52,    53,    28,   115,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,   110,
      27,    78,    79,    80,    81,    96,   114,   116,    28,   117,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      14,    15,    16,    17,    18,    19,    20,    21,    22,   118,
      42,    90,    86
  };

  /* YYCHECK.  */
  const unsigned char
  parser::yycheck_[] =
  {
        23,    24,    25,    13,    27,    28,     4,    12,     6,    47,
       8,    35,    10,    29,    11,    12,    13,    67,    59,    60,
      70,    47,    72,    25,    26,    27,    28,    14,    15,     0,
      70,    47,    72,    29,    30,    58,    31,    32,    33,    34,
      68,    68,    66,    48,    54,    47,    68,    68,    35,    15,
      74,    29,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,   103,    40,    41,    42,    43,    44,    45,    35,
      68,    47,    95,    96,    97,    70,    30,    72,    47,    66,
      29,   104,   105,    25,    26,    27,    28,    74,   111,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    29,
      66,    36,    37,    38,    39,    72,    30,    29,    74,    30,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    29,
       7,    38,    36
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,     4,     6,     8,    10,    68,    87,    88,    89,    90,
      93,    94,    47,    47,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    97,    14,    15,    35,    66,    74,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    98,
      99,     0,    87,    68,    68,    68,    68,    29,    91,   106,
      25,    26,    27,    28,    92,   104,   105,    98,    15,    98,
      98,    11,    12,    13,    96,    98,    98,    96,    96,    47,
      47,    40,    41,    42,    43,    44,    45,   103,    36,    37,
      38,    39,   102,    47,   101,   104,   101,    47,   100,   106,
     100,    31,    32,    33,    34,    70,    72,    95,    30,   106,
     104,    29,   107,    98,    95,    95,    67,    98,    98,    98,
      29,    95,    98,    98,    30,    98,    29,    30,    29
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  parser::yyr1_[] =
  {
         0,    86,    87,    87,    88,    88,    88,    88,    88,    89,
      90,    91,    91,    92,    92,    93,    93,    93,    93,    94,
      94,    94,    94,    95,    95,    95,    95,    96,    96,    96,
      97,    97,    97,    97,    97,    97,    98,    98,    98,    98,
      98,    98,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,   100,   100,   101,   101,   102,   102,
     102,   102,   103,   103,   103,   103,   103,   103,   104,   105,
     105,   105,   105,   106,   106,   106,   106,   107
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     2,     2,     2,     1,     3,
       3,     2,     1,     2,     1,     2,     2,     2,     3,     4,
       5,     5,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       3,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     7,     5,     3,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "\"group\"", "GROUP",
  "\"service\"", "SERVICE", "\"query\"", "QUERY", "\"assert\"", "ASSERT",
  "INPUT", "FORWARD", "\"selected chain\"", "EXAMPLE",
  "\"ASSERTION flag\"", "PACKET", "SPORT", "DPORT", "SADDY", "DADDY",
  "\"query subject\"", "\"equivalence host classes\"",
  "\"equivalence service classes\"", "\"equivalence class graph\"", "UDP",
  "TCP", "ICMP", "\"protocol\"", "\"number\"", "\".\"", "IS", "ISNT",
  "SUBSET_OF", "\"assertion operators\"", "\"logged condition\"",
  "T_INVALID", "T_NEW", "T_ESTABLISHED", "\"connection state\"", "FIN",
  "SYN", "RST", "PSH", "ACK", "\"tcp flag\"", "\"address\"", "\"name\"",
  "\"port number\"", "\"compound port\"", "\"complete port\"",
  "\"compound address\"", "\"simple condition\"", "\"state value\"",
  "\"flag name\"", "\"query condition\"", "\"subject keyword\"",
  "\"input chain\"", "\"protocol keyword\"", "\"assert expression\"",
  "\"query expression\"", "\"service declaration\"",
  "\"address group declaration\"", "\"address list\"", "\"port list\"",
  "\"assertion operator\"", "LPAREN", "RPAREN", "SEMI", "\"AND\"", "AND",
  "\"OR\"", "OR", "\"NOT\"", "NOT", "\"query primitive\"", "DROPPED",
  "ACCEPTED", "OUTFACE", "INFACE", "WITH", "IN", "ON", "FOR", "TO", "FROM",
  "$accept", "statement", "expression", "group_expression",
  "service_expression", "addy_list", "port_list", "query_expression",
  "assert_expression", "assert_op", "input_chain", "subject", "condition",
  "simple_condition", "compound_addy", "compound_port", "state_value",
  "flag_name", "complete_port", "protocol", "addr", "port", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
        87,     0,    -1,    88,    -1,    88,    87,    -1,    89,    68,
      -1,    90,    68,    -1,    93,    68,    -1,    94,    68,    -1,
      68,    -1,     4,    47,    91,    -1,     6,    47,    92,    -1,
      91,   106,    -1,   106,    -1,    92,   104,    -1,   104,    -1,
       8,    22,    -1,     8,    23,    -1,     8,    24,    -1,     8,
      97,    98,    -1,    10,    98,    95,    98,    -1,    10,    14,
      98,    95,    98,    -1,    10,    15,    98,    95,    98,    -1,
      10,    14,    15,    98,    95,    98,    -1,    31,    -1,    33,
      -1,    32,    -1,    34,    -1,    11,    -1,    12,    -1,    13,
      -1,    16,    -1,    17,    -1,    18,    -1,    19,    -1,    20,
      -1,    21,    -1,    99,    -1,    98,    70,    98,    -1,    98,
      72,    98,    -1,    74,    98,    -1,    66,    98,    67,    -1,
      35,    96,    -1,    85,   100,    -1,    84,   100,    -1,    82,
     101,    -1,    83,   101,    -1,    81,   102,    -1,    80,   103,
      -1,    79,    47,    -1,    78,    47,    -1,    77,    96,    -1,
      76,    96,    -1,    77,    -1,    76,    -1,    47,    -1,   106,
      -1,    47,    -1,   104,    -1,    36,    -1,    37,    -1,    38,
      -1,    39,    -1,    40,    -1,    41,    -1,    42,    -1,    43,
      -1,    44,    -1,    45,    -1,   105,   107,    -1,    27,    -1,
      25,    -1,    26,    -1,    28,    -1,    29,    30,    29,    30,
      29,    30,    29,    -1,    29,    30,    29,    30,    29,    -1,
      29,    30,    29,    -1,    29,    -1,    29,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    14,    17,    20,    22,
      26,    30,    33,    35,    38,    40,    43,    46,    49,    53,
      58,    64,    70,    77,    79,    81,    83,    85,    87,    89,
      91,    93,    95,    97,    99,   101,   103,   105,   109,   113,
     116,   120,   123,   126,   129,   132,   135,   138,   141,   144,
     147,   150,   153,   155,   157,   159,   161,   163,   165,   167,
     169,   171,   173,   175,   177,   179,   181,   183,   185,   188,
     190,   192,   194,   196,   204,   210,   214,   216
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  parser::yyrline_[] =
  {
         0,    89,    89,    89,    90,    91,    92,    93,    94,    97,
      99,   101,   102,   104,   105,   107,   108,   109,   110,   116,
     117,   118,   119,   122,   123,   124,   125,   128,   129,   130,
     133,   134,   135,   136,   137,   138,   142,   143,   144,   145,
     146,   147,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   164,   165,   167,   168,   170,   170,
     170,   170,   172,   172,   172,   172,   172,   172,   174,   176,
     176,   176,   176,   178,   179,   180,   181,   183
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "), ";
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 132;
  const int parser::yynnts_ = 22;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 41;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 86;

  const unsigned int parser::yyuser_token_number_max_ = 340;
  const parser::token_number_type parser::yyundef_token_ = 2;

} // namespace yy

#line 185 "fwlang.yy"

void
yy::parser::error (const yy::parser::location_type& l, const std::string& m)
{
   pi.error(l, m);
}

