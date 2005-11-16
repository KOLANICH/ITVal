/* A Bison parser, made by GNU Bison 2.1.  */

/* C++ Skeleton parser for LALR(1) parsing with Bison,
   Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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
/* FIXME: This is wrong, we want computed header guards.
   I don't know why the macros are missing now. :( */
#ifndef PARSER_HEADER_H
# define PARSER_HEADER_H

#include <string>
#include <iostream>

/* Using locations.  */
#define YYLSP_NEEDED 1

namespace yy
{
  class position;
  class location;
}

/* Tokens.  */
   enum yytokentype {
     TOKEN_EOF = 0,
     GROUP = 259,
     SERVICE = 261,
     QUERY = 263,
     INPUT = 264,
     FORWARD = 265,
     OUTPUT = 266,
     PACKET = 267,
     SPORT = 268,
     DPORT = 269,
     SADDY = 270,
     DADDY = 271,
     STATE = 272,
     UDP = 273,
     TCP = 274,
     ICMP = 275,
     BOTH = 276,
     NUM = 277,
     DOT = 278,
     LOGGED = 279,
     T_INVALID = 280,
     T_NEW = 281,
     T_ESTABLISHED = 282,
     T_RELATED = 283,
     FIN = 284,
     SYN = 285,
     RST = 286,
     PSH = 287,
     ACK = 288,
     URG = 289,
     NAME = 291,
     LPAREN = 308,
     RPAREN = 309,
     SEMI = 310,
     AND = 312,
     OR = 314,
     NOT = 316,
     OUTFACE = 318,
     INFACE = 319,
     WITH = 320,
     IN = 321,
     ON = 322,
     FOR = 323,
     TO = 324,
     FROM = 325
   };


/* Copy the first part of user declarations.  */


int yyerror(char* str);
#include <string>
#include "structures.h"
#include "parser_interface.hh"


/* Line 321 of lalr1.cc.  */


#include "stack.hh"
#include "location.hh"

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

#if YYERROR_VERBOSE
# define YYERROR_VERBOSE_IF(x) x
#else
# define YYERROR_VERBOSE_IF(x) /* empty */
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)

union YYSTYPE {
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
};
/* Line 321 of lalr1.cc.  */

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

/* Copy the second part of user declarations.  */


/* Line 321 of lalr1.cc.  */

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
do {							\
  if (N)						\
    {							\
      (Current).begin = (Rhs)[1].begin;			\
      (Current).end   = (Rhs)[N].end;			\
    }							\
  else							\
    {							\
      (Current).begin = (Current).end = (Rhs)[0].end;	\
    }							\
} while (0)
#endif

namespace yy
{
  class parser;

  template <typename P>
  struct traits
  {
  };

  template <>
  struct traits<parser>
  {
    typedef unsigned char token_number_type;
    typedef signed char       rhs_number_type;
    typedef int state_type;
    typedef YYSTYPE semantic_type;
    typedef location location_type;
  };
}

namespace yy
{
  /// A Bison parser.
  class parser
  {
    /// Symbol semantic values.
    typedef traits<parser>::semantic_type semantic_type;
    /// Symbol locations.
    typedef traits<parser>::location_type location_type;

  public:
    /// Build a parser object.
    parser (parser_interface& pi_yyarg) :
      yydebug_ (false),
      yycdebug_ (&std::cerr),
      pi (pi_yyarg)
    {
    }

    virtual ~parser ()
    {
    }

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);

  private:
    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Generate an error message.
    /// \param tok    the look-ahead token.
    virtual std::string yysyntax_error_ (YYERROR_VERBOSE_IF (int tok));

#if YYDEBUG
    /// \brief Report a symbol on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yysymprint_ (int yytype,
			      const semantic_type* yyvaluep,
			      const location_type* yylocationp);
#endif /* ! YYDEBUG */


    /// State numbers.
    typedef traits<parser>::state_type state_type;
    /// State stack type.
    typedef stack<state_type>    state_stack_type;
    /// Semantic value stack type.
    typedef stack<semantic_type> semantic_stack_type;
    /// location stack type.
    typedef stack<location_type> location_stack_type;

    /// The state stack.
    state_stack_type yystate_stack_;
    /// The semantic value stack.
    semantic_stack_type yysemantic_stack_;
    /// The location stack.
    location_stack_type yylocation_stack_;

    /// Internal symbol numbers.
    typedef traits<parser>::token_number_type token_number_type;
    /* Tables.  */
    /// For a state, the index in \a yytable_ of its portion.
    static const signed char yypact_[];
    static const signed char yypact_ninf_;

    /// For a state, default rule to reduce.
    /// Unless\a  yytable_ specifies something else to do.
    /// Zero means the default is an error.
    static const unsigned char yydefact_[];

    static const signed char yypgoto_[];
    static const signed char yydefgoto_[];

    /// What to do in a state.
    /// \a yytable_[yypact_[s]]: what to do in state \a s.
    /// - if positive, shift that token.
    /// - if negative, reduce the rule which number is the opposite.
    /// - if zero, do what YYDEFACT says.
    static const unsigned char yytable_[];
    static const signed char yytable_ninf_;

    static const signed char yycheck_[];

    /// For a state, its accessing symbol.
    static const unsigned char yystos_[];

    /// For a rule, its LHS.
    static const unsigned char yyr1_[];
    /// For a rule, its RHS length.
    static const unsigned char yyr2_[];

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif

#if YYERROR_VERBOSE
    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    virtual std::string yytnamerr_ (const char *n);
#endif

#if YYDEBUG
    /// A type to store symbol numbers and -1.
    typedef traits<parser>::rhs_number_type rhs_number_type;
    /// A `-1'-separated list of the rules' RHS.
    static const rhs_number_type yyrhs_[];
    /// For each rule, the index of the first RHS symbol in \a yyrhs_.
    static const unsigned char yyprhs_[];
    /// For each rule, its source line number.
    static const unsigned char yyrline_[];
    /// For each scanner token number, its symbol number.
    static const unsigned short int yytoken_number_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yyreduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();
#endif

    /// Convert a scanner token number to a symbol number.
    inline token_number_type yytranslate_ (int token);

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg        Why this token is reclaimed.
    /// \param yytype       The symbol type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    inline void yydestruct_ (const char* yymsg,
                             int yytype,
                             semantic_type* yyvaluep,
                             location_type* yylocationp);

    /// Pop \a n symbols the three stacks.
    inline void yypop_ (unsigned int n = 1);

    /* Constants.  */
    static const int yyeof_;
    /* LAST_ -- Last index in TABLE_.  */
    static const int yylast_;
    static const int yynnts_;
    static const int yyempty_;
    static const int yyfinal_;
    static const int yyterror_;
    static const int yyerrcode_;
    static const int yyntokens_;
    static const unsigned int yyuser_token_number_max_;
    static const token_number_type yyundef_token_;

    /* State.  */
    int yyn_;
    int yylen_;
    int yystate_;

    /* Error handling. */
    int yynerrs_;
    int yyerrstatus_;

    /* Debugging.  */
    int yydebug_;
    std::ostream* yycdebug_;


    /* User arguments.  */
    parser_interface& pi;
  };
}

#endif /* ! defined PARSER_HEADER_H */
