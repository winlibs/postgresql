/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         plpgsql_yyparse
#define yylex           plpgsql_yylex
#define yyerror         plpgsql_yyerror
#define yydebug         plpgsql_yydebug
#define yynerrs         plpgsql_yynerrs
#define yylval          plpgsql_yylval
#define yychar          plpgsql_yychar
#define yylloc          plpgsql_yylloc

/* First part of user prologue.  */
#line 1 "pl_gram.y"

/*-------------------------------------------------------------------------
 *
 * pl_gram.y			- Parser for the PL/pgSQL procedural language
 *
 * Portions Copyright (c) 1996-2021, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 *
 * IDENTIFICATION
 *	  src/pl/plpgsql/src/pl_gram.y
 *
 *-------------------------------------------------------------------------
 */

#include "postgres.h"

#include "catalog/namespace.h"
#include "catalog/pg_proc.h"
#include "catalog/pg_type.h"
#include "parser/parser.h"
#include "parser/parse_type.h"
#include "parser/scanner.h"
#include "parser/scansup.h"
#include "utils/builtins.h"

#include "plpgsql.h"


/* Location tracking support --- simpler than bison's default */
#define YYLLOC_DEFAULT(Current, Rhs, N) \
	do { \
		if (N) \
			(Current) = (Rhs)[1]; \
		else \
			(Current) = (Rhs)[0]; \
	} while (0)

/*
 * Bison doesn't allocate anything that needs to live across parser calls,
 * so we can easily have it use palloc instead of malloc.  This prevents
 * memory leaks if we error out during parsing.  Note this only works with
 * bison >= 2.0.  However, in bison 1.875 the default is to use alloca()
 * if possible, so there's not really much problem anyhow, at least if
 * you're building with gcc.
 */
#define YYMALLOC palloc
#define YYFREE   pfree


typedef struct
{
	int			location;
} sql_error_callback_arg;

#define parser_errposition(pos)  plpgsql_scanner_errposition(pos)

union YYSTYPE;					/* need forward reference for tok_is_keyword */

static	bool			tok_is_keyword(int token, union YYSTYPE *lval,
									   int kw_token, const char *kw_str);
static	void			word_is_not_variable(PLword *word, int location);
static	void			cword_is_not_variable(PLcword *cword, int location);
static	void			current_token_is_not_variable(int tok);
static	PLpgSQL_expr	*read_sql_construct(int until,
											int until2,
											int until3,
											const char *expected,
											RawParseMode parsemode,
											bool isexpression,
											bool valid_sql,
											int *startloc,
											int *endtoken);
static	PLpgSQL_expr	*read_sql_expression(int until,
											 const char *expected);
static	PLpgSQL_expr	*read_sql_expression2(int until, int until2,
											  const char *expected,
											  int *endtoken);
static	PLpgSQL_expr	*read_sql_stmt(void);
static	PLpgSQL_type	*read_datatype(int tok);
static	PLpgSQL_stmt	*make_execsql_stmt(int firsttoken, int location,
										   PLword *word);
static	PLpgSQL_stmt_fetch *read_fetch_direction(void);
static	void			 complete_direction(PLpgSQL_stmt_fetch *fetch,
											bool *check_FROM);
static	PLpgSQL_stmt	*make_return_stmt(int location);
static	PLpgSQL_stmt	*make_return_next_stmt(int location);
static	PLpgSQL_stmt	*make_return_query_stmt(int location);
static  PLpgSQL_stmt	*make_case(int location, PLpgSQL_expr *t_expr,
								   List *case_when_list, List *else_stmts);
static	char			*NameOfDatum(PLwdatum *wdatum);
static	void			 check_assignable(PLpgSQL_datum *datum, int location);
static	void			 read_into_target(PLpgSQL_variable **target,
										  bool *strict);
static	PLpgSQL_row		*read_into_scalar_list(char *initial_name,
											   PLpgSQL_datum *initial_datum,
											   int initial_location);
static	PLpgSQL_row		*make_scalar_list1(char *initial_name,
										   PLpgSQL_datum *initial_datum,
										   int lineno, int location);
static	void			 check_sql_expr(const char *stmt,
										RawParseMode parseMode, int location);
static	void			 plpgsql_sql_error_callback(void *arg);
static	PLpgSQL_type	*parse_datatype(const char *string, int location);
static	void			 check_labels(const char *start_label,
									  const char *end_label,
									  int end_location);
static	PLpgSQL_expr	*read_cursor_args(PLpgSQL_var *cursor,
										  int until);
static	List			*read_raise_options(void);
static	void			check_raise_parameters(PLpgSQL_stmt_raise *stmt);


#line 193 "pl_gram.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "pl_gram.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENT = 3,                      /* IDENT  */
  YYSYMBOL_UIDENT = 4,                     /* UIDENT  */
  YYSYMBOL_FCONST = 5,                     /* FCONST  */
  YYSYMBOL_SCONST = 6,                     /* SCONST  */
  YYSYMBOL_USCONST = 7,                    /* USCONST  */
  YYSYMBOL_BCONST = 8,                     /* BCONST  */
  YYSYMBOL_XCONST = 9,                     /* XCONST  */
  YYSYMBOL_Op = 10,                        /* Op  */
  YYSYMBOL_ICONST = 11,                    /* ICONST  */
  YYSYMBOL_PARAM = 12,                     /* PARAM  */
  YYSYMBOL_TYPECAST = 13,                  /* TYPECAST  */
  YYSYMBOL_DOT_DOT = 14,                   /* DOT_DOT  */
  YYSYMBOL_COLON_EQUALS = 15,              /* COLON_EQUALS  */
  YYSYMBOL_EQUALS_GREATER = 16,            /* EQUALS_GREATER  */
  YYSYMBOL_LESS_EQUALS = 17,               /* LESS_EQUALS  */
  YYSYMBOL_GREATER_EQUALS = 18,            /* GREATER_EQUALS  */
  YYSYMBOL_NOT_EQUALS = 19,                /* NOT_EQUALS  */
  YYSYMBOL_T_WORD = 20,                    /* T_WORD  */
  YYSYMBOL_T_CWORD = 21,                   /* T_CWORD  */
  YYSYMBOL_T_DATUM = 22,                   /* T_DATUM  */
  YYSYMBOL_LESS_LESS = 23,                 /* LESS_LESS  */
  YYSYMBOL_GREATER_GREATER = 24,           /* GREATER_GREATER  */
  YYSYMBOL_K_ABSOLUTE = 25,                /* K_ABSOLUTE  */
  YYSYMBOL_K_ALIAS = 26,                   /* K_ALIAS  */
  YYSYMBOL_K_ALL = 27,                     /* K_ALL  */
  YYSYMBOL_K_AND = 28,                     /* K_AND  */
  YYSYMBOL_K_ARRAY = 29,                   /* K_ARRAY  */
  YYSYMBOL_K_ASSERT = 30,                  /* K_ASSERT  */
  YYSYMBOL_K_BACKWARD = 31,                /* K_BACKWARD  */
  YYSYMBOL_K_BEGIN = 32,                   /* K_BEGIN  */
  YYSYMBOL_K_BY = 33,                      /* K_BY  */
  YYSYMBOL_K_CALL = 34,                    /* K_CALL  */
  YYSYMBOL_K_CASE = 35,                    /* K_CASE  */
  YYSYMBOL_K_CHAIN = 36,                   /* K_CHAIN  */
  YYSYMBOL_K_CLOSE = 37,                   /* K_CLOSE  */
  YYSYMBOL_K_COLLATE = 38,                 /* K_COLLATE  */
  YYSYMBOL_K_COLUMN = 39,                  /* K_COLUMN  */
  YYSYMBOL_K_COLUMN_NAME = 40,             /* K_COLUMN_NAME  */
  YYSYMBOL_K_COMMIT = 41,                  /* K_COMMIT  */
  YYSYMBOL_K_CONSTANT = 42,                /* K_CONSTANT  */
  YYSYMBOL_K_CONSTRAINT = 43,              /* K_CONSTRAINT  */
  YYSYMBOL_K_CONSTRAINT_NAME = 44,         /* K_CONSTRAINT_NAME  */
  YYSYMBOL_K_CONTINUE = 45,                /* K_CONTINUE  */
  YYSYMBOL_K_CURRENT = 46,                 /* K_CURRENT  */
  YYSYMBOL_K_CURSOR = 47,                  /* K_CURSOR  */
  YYSYMBOL_K_DATATYPE = 48,                /* K_DATATYPE  */
  YYSYMBOL_K_DEBUG = 49,                   /* K_DEBUG  */
  YYSYMBOL_K_DECLARE = 50,                 /* K_DECLARE  */
  YYSYMBOL_K_DEFAULT = 51,                 /* K_DEFAULT  */
  YYSYMBOL_K_DETAIL = 52,                  /* K_DETAIL  */
  YYSYMBOL_K_DIAGNOSTICS = 53,             /* K_DIAGNOSTICS  */
  YYSYMBOL_K_DO = 54,                      /* K_DO  */
  YYSYMBOL_K_DUMP = 55,                    /* K_DUMP  */
  YYSYMBOL_K_ELSE = 56,                    /* K_ELSE  */
  YYSYMBOL_K_ELSIF = 57,                   /* K_ELSIF  */
  YYSYMBOL_K_END = 58,                     /* K_END  */
  YYSYMBOL_K_ERRCODE = 59,                 /* K_ERRCODE  */
  YYSYMBOL_K_ERROR = 60,                   /* K_ERROR  */
  YYSYMBOL_K_EXCEPTION = 61,               /* K_EXCEPTION  */
  YYSYMBOL_K_EXECUTE = 62,                 /* K_EXECUTE  */
  YYSYMBOL_K_EXIT = 63,                    /* K_EXIT  */
  YYSYMBOL_K_FETCH = 64,                   /* K_FETCH  */
  YYSYMBOL_K_FIRST = 65,                   /* K_FIRST  */
  YYSYMBOL_K_FOR = 66,                     /* K_FOR  */
  YYSYMBOL_K_FOREACH = 67,                 /* K_FOREACH  */
  YYSYMBOL_K_FORWARD = 68,                 /* K_FORWARD  */
  YYSYMBOL_K_FROM = 69,                    /* K_FROM  */
  YYSYMBOL_K_GET = 70,                     /* K_GET  */
  YYSYMBOL_K_HINT = 71,                    /* K_HINT  */
  YYSYMBOL_K_IF = 72,                      /* K_IF  */
  YYSYMBOL_K_IMPORT = 73,                  /* K_IMPORT  */
  YYSYMBOL_K_IN = 74,                      /* K_IN  */
  YYSYMBOL_K_INFO = 75,                    /* K_INFO  */
  YYSYMBOL_K_INSERT = 76,                  /* K_INSERT  */
  YYSYMBOL_K_INTO = 77,                    /* K_INTO  */
  YYSYMBOL_K_IS = 78,                      /* K_IS  */
  YYSYMBOL_K_LAST = 79,                    /* K_LAST  */
  YYSYMBOL_K_LOG = 80,                     /* K_LOG  */
  YYSYMBOL_K_LOOP = 81,                    /* K_LOOP  */
  YYSYMBOL_K_MESSAGE = 82,                 /* K_MESSAGE  */
  YYSYMBOL_K_MESSAGE_TEXT = 83,            /* K_MESSAGE_TEXT  */
  YYSYMBOL_K_MOVE = 84,                    /* K_MOVE  */
  YYSYMBOL_K_NEXT = 85,                    /* K_NEXT  */
  YYSYMBOL_K_NO = 86,                      /* K_NO  */
  YYSYMBOL_K_NOT = 87,                     /* K_NOT  */
  YYSYMBOL_K_NOTICE = 88,                  /* K_NOTICE  */
  YYSYMBOL_K_NULL = 89,                    /* K_NULL  */
  YYSYMBOL_K_OPEN = 90,                    /* K_OPEN  */
  YYSYMBOL_K_OPTION = 91,                  /* K_OPTION  */
  YYSYMBOL_K_OR = 92,                      /* K_OR  */
  YYSYMBOL_K_PERFORM = 93,                 /* K_PERFORM  */
  YYSYMBOL_K_PG_CONTEXT = 94,              /* K_PG_CONTEXT  */
  YYSYMBOL_K_PG_DATATYPE_NAME = 95,        /* K_PG_DATATYPE_NAME  */
  YYSYMBOL_K_PG_EXCEPTION_CONTEXT = 96,    /* K_PG_EXCEPTION_CONTEXT  */
  YYSYMBOL_K_PG_EXCEPTION_DETAIL = 97,     /* K_PG_EXCEPTION_DETAIL  */
  YYSYMBOL_K_PG_EXCEPTION_HINT = 98,       /* K_PG_EXCEPTION_HINT  */
  YYSYMBOL_K_PRINT_STRICT_PARAMS = 99,     /* K_PRINT_STRICT_PARAMS  */
  YYSYMBOL_K_PRIOR = 100,                  /* K_PRIOR  */
  YYSYMBOL_K_QUERY = 101,                  /* K_QUERY  */
  YYSYMBOL_K_RAISE = 102,                  /* K_RAISE  */
  YYSYMBOL_K_RELATIVE = 103,               /* K_RELATIVE  */
  YYSYMBOL_K_RETURN = 104,                 /* K_RETURN  */
  YYSYMBOL_K_RETURNED_SQLSTATE = 105,      /* K_RETURNED_SQLSTATE  */
  YYSYMBOL_K_REVERSE = 106,                /* K_REVERSE  */
  YYSYMBOL_K_ROLLBACK = 107,               /* K_ROLLBACK  */
  YYSYMBOL_K_ROW_COUNT = 108,              /* K_ROW_COUNT  */
  YYSYMBOL_K_ROWTYPE = 109,                /* K_ROWTYPE  */
  YYSYMBOL_K_SCHEMA = 110,                 /* K_SCHEMA  */
  YYSYMBOL_K_SCHEMA_NAME = 111,            /* K_SCHEMA_NAME  */
  YYSYMBOL_K_SCROLL = 112,                 /* K_SCROLL  */
  YYSYMBOL_K_SLICE = 113,                  /* K_SLICE  */
  YYSYMBOL_K_SQLSTATE = 114,               /* K_SQLSTATE  */
  YYSYMBOL_K_STACKED = 115,                /* K_STACKED  */
  YYSYMBOL_K_STRICT = 116,                 /* K_STRICT  */
  YYSYMBOL_K_TABLE = 117,                  /* K_TABLE  */
  YYSYMBOL_K_TABLE_NAME = 118,             /* K_TABLE_NAME  */
  YYSYMBOL_K_THEN = 119,                   /* K_THEN  */
  YYSYMBOL_K_TO = 120,                     /* K_TO  */
  YYSYMBOL_K_TYPE = 121,                   /* K_TYPE  */
  YYSYMBOL_K_USE_COLUMN = 122,             /* K_USE_COLUMN  */
  YYSYMBOL_K_USE_VARIABLE = 123,           /* K_USE_VARIABLE  */
  YYSYMBOL_K_USING = 124,                  /* K_USING  */
  YYSYMBOL_K_VARIABLE_CONFLICT = 125,      /* K_VARIABLE_CONFLICT  */
  YYSYMBOL_K_WARNING = 126,                /* K_WARNING  */
  YYSYMBOL_K_WHEN = 127,                   /* K_WHEN  */
  YYSYMBOL_K_WHILE = 128,                  /* K_WHILE  */
  YYSYMBOL_129_ = 129,                     /* '#'  */
  YYSYMBOL_130_ = 130,                     /* ';'  */
  YYSYMBOL_131_ = 131,                     /* '('  */
  YYSYMBOL_132_ = 132,                     /* ')'  */
  YYSYMBOL_133_ = 133,                     /* ','  */
  YYSYMBOL_134_ = 134,                     /* '='  */
  YYSYMBOL_YYACCEPT = 135,                 /* $accept  */
  YYSYMBOL_pl_function = 136,              /* pl_function  */
  YYSYMBOL_comp_options = 137,             /* comp_options  */
  YYSYMBOL_comp_option = 138,              /* comp_option  */
  YYSYMBOL_option_value = 139,             /* option_value  */
  YYSYMBOL_opt_semi = 140,                 /* opt_semi  */
  YYSYMBOL_pl_block = 141,                 /* pl_block  */
  YYSYMBOL_decl_sect = 142,                /* decl_sect  */
  YYSYMBOL_decl_start = 143,               /* decl_start  */
  YYSYMBOL_decl_stmts = 144,               /* decl_stmts  */
  YYSYMBOL_decl_stmt = 145,                /* decl_stmt  */
  YYSYMBOL_decl_statement = 146,           /* decl_statement  */
  YYSYMBOL_147_1 = 147,                    /* $@1  */
  YYSYMBOL_opt_scrollable = 148,           /* opt_scrollable  */
  YYSYMBOL_decl_cursor_query = 149,        /* decl_cursor_query  */
  YYSYMBOL_decl_cursor_args = 150,         /* decl_cursor_args  */
  YYSYMBOL_decl_cursor_arglist = 151,      /* decl_cursor_arglist  */
  YYSYMBOL_decl_cursor_arg = 152,          /* decl_cursor_arg  */
  YYSYMBOL_decl_is_for = 153,              /* decl_is_for  */
  YYSYMBOL_decl_aliasitem = 154,           /* decl_aliasitem  */
  YYSYMBOL_decl_varname = 155,             /* decl_varname  */
  YYSYMBOL_decl_const = 156,               /* decl_const  */
  YYSYMBOL_decl_datatype = 157,            /* decl_datatype  */
  YYSYMBOL_decl_collate = 158,             /* decl_collate  */
  YYSYMBOL_decl_notnull = 159,             /* decl_notnull  */
  YYSYMBOL_decl_defval = 160,              /* decl_defval  */
  YYSYMBOL_decl_defkey = 161,              /* decl_defkey  */
  YYSYMBOL_assign_operator = 162,          /* assign_operator  */
  YYSYMBOL_proc_sect = 163,                /* proc_sect  */
  YYSYMBOL_proc_stmt = 164,                /* proc_stmt  */
  YYSYMBOL_stmt_perform = 165,             /* stmt_perform  */
  YYSYMBOL_stmt_call = 166,                /* stmt_call  */
  YYSYMBOL_stmt_assign = 167,              /* stmt_assign  */
  YYSYMBOL_stmt_getdiag = 168,             /* stmt_getdiag  */
  YYSYMBOL_getdiag_area_opt = 169,         /* getdiag_area_opt  */
  YYSYMBOL_getdiag_list = 170,             /* getdiag_list  */
  YYSYMBOL_getdiag_list_item = 171,        /* getdiag_list_item  */
  YYSYMBOL_getdiag_item = 172,             /* getdiag_item  */
  YYSYMBOL_getdiag_target = 173,           /* getdiag_target  */
  YYSYMBOL_stmt_if = 174,                  /* stmt_if  */
  YYSYMBOL_stmt_elsifs = 175,              /* stmt_elsifs  */
  YYSYMBOL_stmt_else = 176,                /* stmt_else  */
  YYSYMBOL_stmt_case = 177,                /* stmt_case  */
  YYSYMBOL_opt_expr_until_when = 178,      /* opt_expr_until_when  */
  YYSYMBOL_case_when_list = 179,           /* case_when_list  */
  YYSYMBOL_case_when = 180,                /* case_when  */
  YYSYMBOL_opt_case_else = 181,            /* opt_case_else  */
  YYSYMBOL_stmt_loop = 182,                /* stmt_loop  */
  YYSYMBOL_stmt_while = 183,               /* stmt_while  */
  YYSYMBOL_stmt_for = 184,                 /* stmt_for  */
  YYSYMBOL_for_control = 185,              /* for_control  */
  YYSYMBOL_for_variable = 186,             /* for_variable  */
  YYSYMBOL_stmt_foreach_a = 187,           /* stmt_foreach_a  */
  YYSYMBOL_foreach_slice = 188,            /* foreach_slice  */
  YYSYMBOL_stmt_exit = 189,                /* stmt_exit  */
  YYSYMBOL_exit_type = 190,                /* exit_type  */
  YYSYMBOL_stmt_return = 191,              /* stmt_return  */
  YYSYMBOL_stmt_raise = 192,               /* stmt_raise  */
  YYSYMBOL_stmt_assert = 193,              /* stmt_assert  */
  YYSYMBOL_loop_body = 194,                /* loop_body  */
  YYSYMBOL_stmt_execsql = 195,             /* stmt_execsql  */
  YYSYMBOL_stmt_dynexecute = 196,          /* stmt_dynexecute  */
  YYSYMBOL_stmt_open = 197,                /* stmt_open  */
  YYSYMBOL_stmt_fetch = 198,               /* stmt_fetch  */
  YYSYMBOL_stmt_move = 199,                /* stmt_move  */
  YYSYMBOL_opt_fetch_direction = 200,      /* opt_fetch_direction  */
  YYSYMBOL_stmt_close = 201,               /* stmt_close  */
  YYSYMBOL_stmt_null = 202,                /* stmt_null  */
  YYSYMBOL_stmt_commit = 203,              /* stmt_commit  */
  YYSYMBOL_stmt_rollback = 204,            /* stmt_rollback  */
  YYSYMBOL_opt_transaction_chain = 205,    /* opt_transaction_chain  */
  YYSYMBOL_cursor_variable = 206,          /* cursor_variable  */
  YYSYMBOL_exception_sect = 207,           /* exception_sect  */
  YYSYMBOL_208_2 = 208,                    /* @2  */
  YYSYMBOL_proc_exceptions = 209,          /* proc_exceptions  */
  YYSYMBOL_proc_exception = 210,           /* proc_exception  */
  YYSYMBOL_proc_conditions = 211,          /* proc_conditions  */
  YYSYMBOL_proc_condition = 212,           /* proc_condition  */
  YYSYMBOL_expr_until_semi = 213,          /* expr_until_semi  */
  YYSYMBOL_expr_until_then = 214,          /* expr_until_then  */
  YYSYMBOL_expr_until_loop = 215,          /* expr_until_loop  */
  YYSYMBOL_opt_block_label = 216,          /* opt_block_label  */
  YYSYMBOL_opt_loop_label = 217,           /* opt_loop_label  */
  YYSYMBOL_opt_label = 218,                /* opt_label  */
  YYSYMBOL_opt_exitcond = 219,             /* opt_exitcond  */
  YYSYMBOL_any_identifier = 220,           /* any_identifier  */
  YYSYMBOL_unreserved_keyword = 221        /* unreserved_keyword  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1322

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  135
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  250
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  331

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   383


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   129,     2,     2,     2,     2,
     131,   132,     2,     2,   133,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   130,
       2,   134,     2,     2,     2,     2,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   359,   359,   365,   366,   369,   373,   382,   386,   390,
     396,   400,   405,   406,   409,   432,   440,   447,   456,   468,
     469,   472,   473,   477,   490,   528,   534,   533,   587,   590,
     594,   601,   607,   610,   641,   645,   651,   659,   660,   662,
     677,   692,   720,   748,   779,   780,   785,   796,   797,   802,
     807,   814,   815,   819,   821,   827,   828,   836,   837,   841,
     842,   852,   854,   856,   858,   860,   862,   864,   866,   868,
     870,   872,   874,   876,   878,   880,   882,   884,   886,   888,
     890,   892,   894,   896,   898,   902,   938,   956,   977,  1016,
    1079,  1082,  1086,  1092,  1096,  1102,  1115,  1159,  1177,  1182,
    1189,  1207,  1210,  1224,  1227,  1233,  1240,  1254,  1258,  1264,
    1276,  1279,  1294,  1312,  1331,  1365,  1623,  1649,  1663,  1670,
    1709,  1712,  1718,  1771,  1775,  1781,  1807,  1952,  1976,  1994,
    1998,  2002,  2013,  2026,  2090,  2168,  2198,  2211,  2216,  2230,
    2237,  2251,  2266,  2267,  2268,  2272,  2294,  2299,  2307,  2309,
    2308,  2350,  2354,  2360,  2373,  2382,  2388,  2425,  2429,  2433,
    2437,  2441,  2449,  2453,  2461,  2464,  2471,  2473,  2480,  2484,
    2488,  2497,  2498,  2499,  2500,  2501,  2502,  2503,  2504,  2505,
    2506,  2507,  2508,  2509,  2510,  2511,  2512,  2513,  2514,  2515,
    2516,  2517,  2518,  2519,  2520,  2521,  2522,  2523,  2524,  2525,
    2526,  2527,  2528,  2529,  2530,  2531,  2532,  2533,  2534,  2535,
    2536,  2537,  2538,  2539,  2540,  2541,  2542,  2543,  2544,  2545,
    2546,  2547,  2548,  2549,  2550,  2551,  2552,  2553,  2554,  2555,
    2556,  2557,  2558,  2559,  2560,  2561,  2562,  2563,  2564,  2565,
    2566,  2567,  2568,  2569,  2570,  2571,  2572,  2573,  2574,  2575,
    2576
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENT", "UIDENT",
  "FCONST", "SCONST", "USCONST", "BCONST", "XCONST", "Op", "ICONST",
  "PARAM", "TYPECAST", "DOT_DOT", "COLON_EQUALS", "EQUALS_GREATER",
  "LESS_EQUALS", "GREATER_EQUALS", "NOT_EQUALS", "T_WORD", "T_CWORD",
  "T_DATUM", "LESS_LESS", "GREATER_GREATER", "K_ABSOLUTE", "K_ALIAS",
  "K_ALL", "K_AND", "K_ARRAY", "K_ASSERT", "K_BACKWARD", "K_BEGIN", "K_BY",
  "K_CALL", "K_CASE", "K_CHAIN", "K_CLOSE", "K_COLLATE", "K_COLUMN",
  "K_COLUMN_NAME", "K_COMMIT", "K_CONSTANT", "K_CONSTRAINT",
  "K_CONSTRAINT_NAME", "K_CONTINUE", "K_CURRENT", "K_CURSOR", "K_DATATYPE",
  "K_DEBUG", "K_DECLARE", "K_DEFAULT", "K_DETAIL", "K_DIAGNOSTICS", "K_DO",
  "K_DUMP", "K_ELSE", "K_ELSIF", "K_END", "K_ERRCODE", "K_ERROR",
  "K_EXCEPTION", "K_EXECUTE", "K_EXIT", "K_FETCH", "K_FIRST", "K_FOR",
  "K_FOREACH", "K_FORWARD", "K_FROM", "K_GET", "K_HINT", "K_IF",
  "K_IMPORT", "K_IN", "K_INFO", "K_INSERT", "K_INTO", "K_IS", "K_LAST",
  "K_LOG", "K_LOOP", "K_MESSAGE", "K_MESSAGE_TEXT", "K_MOVE", "K_NEXT",
  "K_NO", "K_NOT", "K_NOTICE", "K_NULL", "K_OPEN", "K_OPTION", "K_OR",
  "K_PERFORM", "K_PG_CONTEXT", "K_PG_DATATYPE_NAME",
  "K_PG_EXCEPTION_CONTEXT", "K_PG_EXCEPTION_DETAIL", "K_PG_EXCEPTION_HINT",
  "K_PRINT_STRICT_PARAMS", "K_PRIOR", "K_QUERY", "K_RAISE", "K_RELATIVE",
  "K_RETURN", "K_RETURNED_SQLSTATE", "K_REVERSE", "K_ROLLBACK",
  "K_ROW_COUNT", "K_ROWTYPE", "K_SCHEMA", "K_SCHEMA_NAME", "K_SCROLL",
  "K_SLICE", "K_SQLSTATE", "K_STACKED", "K_STRICT", "K_TABLE",
  "K_TABLE_NAME", "K_THEN", "K_TO", "K_TYPE", "K_USE_COLUMN",
  "K_USE_VARIABLE", "K_USING", "K_VARIABLE_CONFLICT", "K_WARNING",
  "K_WHEN", "K_WHILE", "'#'", "';'", "'('", "')'", "','", "'='", "$accept",
  "pl_function", "comp_options", "comp_option", "option_value", "opt_semi",
  "pl_block", "decl_sect", "decl_start", "decl_stmts", "decl_stmt",
  "decl_statement", "$@1", "opt_scrollable", "decl_cursor_query",
  "decl_cursor_args", "decl_cursor_arglist", "decl_cursor_arg",
  "decl_is_for", "decl_aliasitem", "decl_varname", "decl_const",
  "decl_datatype", "decl_collate", "decl_notnull", "decl_defval",
  "decl_defkey", "assign_operator", "proc_sect", "proc_stmt",
  "stmt_perform", "stmt_call", "stmt_assign", "stmt_getdiag",
  "getdiag_area_opt", "getdiag_list", "getdiag_list_item", "getdiag_item",
  "getdiag_target", "stmt_if", "stmt_elsifs", "stmt_else", "stmt_case",
  "opt_expr_until_when", "case_when_list", "case_when", "opt_case_else",
  "stmt_loop", "stmt_while", "stmt_for", "for_control", "for_variable",
  "stmt_foreach_a", "foreach_slice", "stmt_exit", "exit_type",
  "stmt_return", "stmt_raise", "stmt_assert", "loop_body", "stmt_execsql",
  "stmt_dynexecute", "stmt_open", "stmt_fetch", "stmt_move",
  "opt_fetch_direction", "stmt_close", "stmt_null", "stmt_commit",
  "stmt_rollback", "opt_transaction_chain", "cursor_variable",
  "exception_sect", "@2", "proc_exceptions", "proc_exception",
  "proc_conditions", "proc_condition", "expr_until_semi",
  "expr_until_then", "expr_until_loop", "opt_block_label",
  "opt_loop_label", "opt_label", "opt_exitcond", "any_identifier",
  "unreserved_keyword", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-253)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-162)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -253,    25,   -18,  -253,   306,   -55,  -253,  -101,     1,   -15,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,    24,  -253,    -1,   624,   -33,  -253,  -253,  -253,
    -253,   199,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
     987,  -253,   306,  -253,   199,  -253,  -253,   -10,  -253,  -253,
    -253,  -253,   306,  -253,  -253,  -253,    85,    22,  -253,  -253,
    -253,  -253,  -253,  -253,   -31,  -253,  -253,  -253,  -253,   -66,
      85,  -253,  -253,  -253,    22,   -59,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,   306,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,    19,   -25,    42,  -253,    14,  -253,   -29,  -253,    39,
    -253,    64,   -35,  -253,  -253,  -253,   -32,    -5,   -21,   -30,
      85,  -253,  -253,    48,  -253,    85,  -253,  -253,   -20,  -253,
     -81,  -253,   306,   109,   109,  -253,  -253,  -253,   413,  -253,
    -253,    74,     8,  -253,   -42,  -253,  -253,  -253,    77,  -253,
     306,   -30,  -253,    38,   112,   835,    -7,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,    45,     7,  1063,  -253,
    -253,  -253,  -253,    -6,  -253,     5,   520,    51,  -253,  -253,
    -253,    83,  -253,   -64,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,   -70,  -253,   -12,    18,  -253,  -253,  -253,  -253,   132,
      70,    66,  -253,  -253,   728,    -9,  -253,  -253,  -253,    56,
     -13,   -11,  1139,   113,   306,  -253,  -253,   112,  -253,  -253,
    -253,  -253,  -253,    91,  -253,   122,   306,   -38,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,    26,
    -253,   105,  -253,  -253,  1215,  -253,    86,  -253,    27,  -253,
     728,  -253,  -253,  -253,   911,    30,  -253,  -253,  -253,  -253,
    -253
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,   160,     1,     0,     0,     4,    12,     0,    15,
     168,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,   169,     0,     0,     0,    13,     2,    59,
      18,    16,   161,     5,    10,     6,    11,     7,     9,     8,
     162,    42,     0,    22,    17,    20,    21,    44,    43,   131,
     132,    88,     0,   127,    86,   106,     0,   144,   124,    87,
     149,   133,   123,   137,    90,   158,   129,   130,   137,     0,
       0,    85,   126,   125,   144,     0,    60,    75,    76,    62,
      77,    63,    64,    65,    66,    67,    68,    69,   164,    70,
      71,    72,    73,    74,    78,    79,    80,    81,    82,    83,
      84,     0,     0,     0,    19,     0,    45,     0,    30,     0,
      46,     0,     0,   146,   147,   145,     0,     0,     0,     0,
       0,    91,    92,     0,    59,     0,   139,   134,     0,    61,
       0,   165,   164,     0,     0,    59,   159,    23,     0,    29,
      26,    47,   163,   158,   110,   108,   138,   142,     0,   140,
       0,   150,   152,     0,     0,   162,     0,   141,   157,   166,
     122,    14,   117,   118,   116,    59,     0,   120,   162,   112,
      59,    39,    41,     0,    40,    32,     0,    51,    59,    59,
     107,     0,   143,     0,   155,   156,   151,   135,    98,    99,
      97,     0,    94,     0,   103,   136,   167,   114,   115,     0,
       0,     0,   113,    25,     0,     0,    48,    50,    49,     0,
       0,   162,   162,     0,     0,    59,    89,     0,    58,    57,
      96,    59,   158,     0,   121,     0,   164,     0,    34,    46,
      38,    37,    31,    52,    56,    53,    24,    54,    55,     0,
     154,   162,    93,    95,   162,    59,     0,   159,     0,    33,
       0,    36,    27,   105,   162,     0,    59,   128,    35,   100,
     119
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -253,  -253,  -253,  -253,  -253,  -253,   159,  -253,  -253,  -253,
      50,  -253,  -253,  -253,  -253,  -253,  -253,  -158,  -253,  -253,
    -252,  -253,  -134,  -253,  -253,  -253,  -253,  -114,   -95,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -117,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,   -43,  -253,  -253,  -253,  -253,
    -253,   -28,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -222,
    -253,  -253,  -253,  -253,  -253,    34,  -253,  -253,  -253,  -253,
      29,  -123,  -253,  -253,  -253,   -47,  -253,  -105,  -253,  -205,
    -135,  -253,  -253,  -196,  -253,    -4,   -94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     6,   105,    98,   145,     8,   101,   114,
     115,   116,   245,   179,   322,   275,   297,   298,   302,   243,
     117,   180,   211,   247,   280,   306,   307,   290,   238,   146,
     147,   148,   149,   150,   193,   261,   262,   313,   263,   151,
     264,   293,   152,   182,   214,   215,   251,   153,   154,   155,
     235,   236,   156,   270,   157,   158,   159,   160,   161,   239,
     162,   163,   164,   165,   166,   190,   167,   168,   169,   170,
     188,   186,   171,   189,   221,   222,   253,   254,   266,   194,
     240,     9,   172,   200,   230,   201,    93
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,   106,   288,   288,   110,     4,   231,   118,   248,   119,
     120,   121,   122,   267,   249,   191,   175,   197,   272,   123,
     118,  -160,   299,   124,   125,     3,   126,   107,   284,    97,
     127,   217,   176,    99,   128,   100,    94,   -28,   304,  -160,
    -161,   203,   204,   129,    95,  -109,   228,  -109,   102,   229,
     187,   131,   132,   133,   103,   285,   205,   300,  -161,   134,
     286,   135,   136,   287,   196,   137,   207,   223,   299,   301,
      96,   199,   226,   138,   291,   292,   177,   202,   139,   140,
     208,   218,   141,   209,   192,   213,   210,   315,   212,   108,
     109,   142,   213,   143,   319,   320,   144,   220,   216,   225,
     318,   224,   178,   206,   330,   183,   184,   185,   173,   219,
     227,     5,   246,   252,   244,   257,  -109,   305,   181,   268,
     269,   289,   289,   265,   273,   119,   120,   121,   122,   232,
     233,   234,   258,   259,   260,   123,   274,  -160,   279,   124,
     125,   283,   126,   294,   295,   303,   127,   296,   309,   316,
     128,   317,   278,   281,   282,  -160,   323,   327,   325,   129,
     329,     7,   328,  -153,   174,   321,   308,   131,   132,   133,
     312,   250,   195,   198,   256,   134,   237,   135,   136,   310,
     118,   137,   326,     0,     0,     0,     0,     0,     0,   138,
     311,     0,     0,     0,   139,   140,   314,     0,   141,     0,
       0,     0,     0,     0,     0,     0,     0,   142,     0,   143,
       0,     0,   144,     0,     0,     0,   255,     0,     0,   111,
     324,     0,   112,     0,    12,    13,   118,    14,    15,    16,
      17,     0,  -153,    18,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   113,
      33,    34,    35,    36,    37,     0,    38,     0,    39,    40,
      41,     0,    42,    43,    44,     0,     0,    45,     0,    46,
      47,     0,    48,     0,    49,    50,     0,    51,    52,    53,
     255,    54,    55,    56,    57,    58,     0,    59,     0,    60,
      61,     0,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,    86,     0,     0,
      87,    88,    89,     0,    90,    91,    10,     0,    11,     0,
       0,    12,    13,     0,    14,    15,    16,    17,     0,     0,
      18,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     0,    33,    34,    35,
      36,    37,     0,    38,     0,    39,    40,    41,     0,    42,
      43,    44,     0,     0,    45,     0,    46,    47,     0,    48,
       0,    49,    50,     0,    51,    52,    53,     0,    54,    55,
      56,    57,    58,     0,    59,     0,    60,    61,     0,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,    85,    86,     0,     0,    87,    88,    89,
       0,    90,    91,   241,   242,     0,     0,     0,    12,    13,
       0,    14,    15,    16,    17,     0,     0,    18,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,     0,    33,    34,    35,    36,    37,     0,
      38,     0,    39,    40,    41,     0,    42,    43,    44,     0,
       0,    45,     0,    46,    47,     0,    48,     0,    49,    50,
       0,    51,    52,    53,     0,    54,    55,    56,    57,    58,
       0,    59,     0,    60,    61,     0,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,    86,     0,     0,    87,    88,    89,     0,    90,    91,
     276,   277,     0,     0,     0,    12,    13,     0,    14,    15,
      16,    17,     0,     0,    18,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       0,    33,    34,    35,    36,    37,     0,    38,     0,    39,
      40,    41,     0,    42,    43,    44,     0,     0,    45,     0,
      46,    47,     0,    48,     0,    49,    50,     0,    51,    52,
      53,     0,    54,    55,    56,    57,    58,     0,    59,     0,
      60,    61,     0,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,    86,     0,
       0,    87,    88,    89,   104,    90,    91,     0,     0,    12,
      13,     0,    14,    15,    16,    17,     0,     0,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
       0,    38,     0,    39,    40,    41,     0,    42,    43,    44,
       0,     0,    45,     0,    46,    47,     0,    48,     0,    49,
      50,     0,    51,    52,    53,     0,    54,    55,    56,    57,
      58,     0,    59,     0,    60,    61,     0,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,    85,    86,     0,     0,    87,    88,    89,   111,    90,
      91,     0,     0,    12,    13,     0,    14,    15,    16,    17,
       0,     0,    18,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     0,    33,
      34,    35,    36,    37,     0,    38,     0,    39,    40,    41,
       0,    42,    43,    44,     0,     0,    45,     0,    46,    47,
       0,    48,     0,    49,    50,     0,    51,    52,    53,     0,
      54,    55,    56,    57,    58,     0,    59,     0,    60,    61,
       0,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,    85,    86,     0,     0,    87,
      88,    89,     0,    90,    91,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,   123,     0,  -160,     0,   124,
     125,     0,   126,     0,     0,     0,   127,     0,     0,     0,
     128,     0,     0,     0,     0,  -160,     0,     0,     0,   129,
       0,  -101,  -101,  -101,     0,     0,     0,   131,   132,   133,
       0,     0,     0,     0,     0,   134,     0,   135,   136,     0,
       0,   137,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,   139,   140,     0,     0,   141,     0,
       0,   119,   120,   121,   122,     0,     0,   142,     0,   143,
       0,   123,   144,  -160,     0,   124,   125,     0,   126,     0,
       0,     0,   127,     0,     0,     0,   128,     0,     0,     0,
       0,  -160,     0,     0,     0,   129,     0,  -102,  -102,  -102,
       0,     0,     0,   131,   132,   133,     0,     0,     0,     0,
       0,   134,     0,   135,   136,     0,     0,   137,     0,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,     0,
     139,   140,     0,     0,   141,     0,     0,   119,   120,   121,
     122,     0,     0,   142,     0,   143,     0,   123,   144,  -160,
       0,   124,   125,     0,   126,     0,     0,     0,   127,     0,
       0,     0,   128,     0,     0,     0,     0,  -160,     0,     0,
       0,   129,     0,     0,     0,  -148,     0,     0,   130,   131,
     132,   133,     0,     0,     0,     0,     0,   134,     0,   135,
     136,     0,     0,   137,     0,     0,     0,     0,     0,     0,
       0,   138,     0,     0,     0,     0,   139,   140,     0,     0,
     141,     0,     0,   119,   120,   121,   122,     0,     0,   142,
       0,   143,     0,   123,   144,  -160,     0,   124,   125,     0,
     126,     0,     0,     0,   127,     0,     0,     0,   128,     0,
       0,     0,     0,  -160,     0,     0,     0,   129,     0,     0,
       0,   271,     0,     0,     0,   131,   132,   133,     0,     0,
       0,     0,     0,   134,     0,   135,   136,     0,     0,   137,
       0,     0,     0,     0,     0,     0,     0,   138,     0,     0,
       0,     0,   139,   140,     0,     0,   141,     0,     0,   119,
     120,   121,   122,     0,     0,   142,     0,   143,     0,   123,
     144,  -160,     0,   124,   125,     0,   126,     0,     0,     0,
     127,     0,     0,     0,   128,     0,     0,     0,     0,  -160,
       0,     0,     0,   129,     0,     0,     0,  -111,     0,     0,
       0,   131,   132,   133,     0,     0,     0,     0,     0,   134,
       0,   135,   136,     0,     0,   137,     0,     0,     0,     0,
       0,     0,     0,   138,     0,     0,     0,     0,   139,   140,
       0,     0,   141,     0,     0,   119,   120,   121,   122,     0,
       0,   142,     0,   143,     0,   123,   144,  -160,     0,   124,
     125,     0,   126,     0,     0,     0,   127,     0,     0,     0,
     128,     0,     0,     0,     0,  -160,     0,     0,     0,   129,
       0,     0,     0,  -104,     0,     0,     0,   131,   132,   133,
       0,     0,     0,     0,     0,   134,     0,   135,   136,     0,
       0,   137,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,   139,   140,     0,     0,   141,     0,
       0,     0,     0,     0,     0,     0,     0,   142,     0,   143,
       0,     0,   144
};

static const yytype_int16 yycheck[] =
{
       4,    95,    15,    15,    99,    23,   202,   101,   213,    20,
      21,    22,    23,   235,    56,    46,    26,   140,   240,    30,
     114,    32,   274,    34,    35,     0,    37,    60,    92,   130,
      41,    36,    42,    32,    45,    50,    91,    47,    51,    50,
      32,    66,    67,    54,    99,    56,   127,    58,    24,   130,
      28,    62,    63,    64,    55,   119,    81,    66,    50,    70,
     130,    72,    73,   133,   130,    76,    24,   190,   320,    78,
     125,   130,   195,    84,    56,    57,    86,    58,    89,    90,
      66,    86,    93,   112,   115,   127,    47,   292,    24,   122,
     123,   102,   127,   104,   132,   133,   107,   127,   130,   194,
     296,    53,   112,   128,   326,    20,    21,    22,   112,   130,
     130,   129,    38,    36,   208,    77,   127,   130,   122,    74,
     113,   134,   134,   130,   130,    20,    21,    22,    23,    20,
      21,    22,    20,    21,    22,    30,   131,    32,    87,    34,
      35,    58,    37,    11,    74,    89,    41,    81,    35,    58,
      45,    29,   246,   248,   249,    50,   130,   130,    72,    54,
     130,     2,   320,    58,   114,   299,   280,    62,    63,    64,
     287,   214,   138,   144,   221,    70,   204,    72,    73,   284,
     274,    76,   317,    -1,    -1,    -1,    -1,    -1,    -1,    84,
     285,    -1,    -1,    -1,    89,    90,   291,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,   104,
      -1,    -1,   107,    -1,    -1,    -1,   220,    -1,    -1,    20,
     315,    -1,    23,    -1,    25,    26,   320,    28,    29,    30,
      31,    -1,   127,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    -1,    59,    60,
      61,    -1,    63,    64,    65,    -1,    -1,    68,    -1,    70,
      71,    -1,    73,    -1,    75,    76,    -1,    78,    79,    80,
     284,    82,    83,    84,    85,    86,    -1,    88,    -1,    90,
      91,    -1,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    -1,   117,   118,    -1,    -1,
     121,   122,   123,    -1,   125,   126,    20,    -1,    22,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    -1,    -1,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,    52,    53,
      54,    55,    -1,    57,    -1,    59,    60,    61,    -1,    63,
      64,    65,    -1,    -1,    68,    -1,    70,    71,    -1,    73,
      -1,    75,    76,    -1,    78,    79,    80,    -1,    82,    83,
      84,    85,    86,    -1,    88,    -1,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,   117,   118,    -1,    -1,   121,   122,   123,
      -1,   125,   126,    20,    21,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    -1,    -1,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,    52,    53,    54,    55,    -1,
      57,    -1,    59,    60,    61,    -1,    63,    64,    65,    -1,
      -1,    68,    -1,    70,    71,    -1,    73,    -1,    75,    76,
      -1,    78,    79,    80,    -1,    82,    83,    84,    85,    86,
      -1,    88,    -1,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    -1,
     117,   118,    -1,    -1,   121,   122,   123,    -1,   125,   126,
      20,    21,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    -1,    -1,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    -1,    57,    -1,    59,
      60,    61,    -1,    63,    64,    65,    -1,    -1,    68,    -1,
      70,    71,    -1,    73,    -1,    75,    76,    -1,    78,    79,
      80,    -1,    82,    83,    84,    85,    86,    -1,    88,    -1,
      90,    91,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,   117,   118,    -1,
      -1,   121,   122,   123,    20,   125,   126,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    -1,    -1,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
      -1,    57,    -1,    59,    60,    61,    -1,    63,    64,    65,
      -1,    -1,    68,    -1,    70,    71,    -1,    73,    -1,    75,
      76,    -1,    78,    79,    80,    -1,    82,    83,    84,    85,
      86,    -1,    88,    -1,    90,    91,    -1,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   117,   118,    -1,    -1,   121,   122,   123,    20,   125,
     126,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      -1,    -1,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
      52,    53,    54,    55,    -1,    57,    -1,    59,    60,    61,
      -1,    63,    64,    65,    -1,    -1,    68,    -1,    70,    71,
      -1,    73,    -1,    75,    76,    -1,    78,    79,    80,    -1,
      82,    83,    84,    85,    86,    -1,    88,    -1,    90,    91,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,   117,   118,    -1,    -1,   121,
     122,   123,    -1,   125,   126,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    -1,    34,
      35,    -1,    37,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,
      -1,    56,    57,    58,    -1,    -1,    -1,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    73,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    93,    -1,
      -1,    20,    21,    22,    23,    -1,    -1,   102,    -1,   104,
      -1,    30,   107,    32,    -1,    34,    35,    -1,    37,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    54,    -1,    56,    57,    58,
      -1,    -1,    -1,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    73,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    90,    -1,    -1,    93,    -1,    -1,    20,    21,    22,
      23,    -1,    -1,   102,    -1,   104,    -1,    30,   107,    32,
      -1,    34,    35,    -1,    37,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      73,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,
      93,    -1,    -1,    20,    21,    22,    23,    -1,    -1,   102,
      -1,   104,    -1,    30,   107,    32,    -1,    34,    35,    -1,
      37,    -1,    -1,    -1,    41,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    73,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    89,    90,    -1,    -1,    93,    -1,    -1,    20,
      21,    22,    23,    -1,    -1,   102,    -1,   104,    -1,    30,
     107,    32,    -1,    34,    35,    -1,    37,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    90,
      -1,    -1,    93,    -1,    -1,    20,    21,    22,    23,    -1,
      -1,   102,    -1,   104,    -1,    30,   107,    32,    -1,    34,
      35,    -1,    37,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    73,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,   104,
      -1,    -1,   107
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   136,   137,     0,    23,   129,   138,   141,   142,   216,
      20,    22,    25,    26,    28,    29,    30,    31,    34,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    51,    52,    53,    54,    55,    57,    59,
      60,    61,    63,    64,    65,    68,    70,    71,    73,    75,
      76,    78,    79,    80,    82,    83,    84,    85,    86,    88,
      90,    91,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   117,   118,   121,   122,   123,
     125,   126,   220,   221,    91,    99,   125,   130,   140,    32,
      50,   143,    24,    55,    20,   139,   221,    60,   122,   123,
     163,    20,    23,    50,   144,   145,   146,   155,   221,    20,
      21,    22,    23,    30,    34,    35,    37,    41,    45,    54,
      61,    62,    63,    64,    70,    72,    73,    76,    84,    89,
      90,    93,   102,   104,   107,   141,   164,   165,   166,   167,
     168,   174,   177,   182,   183,   184,   187,   189,   190,   191,
     192,   193,   195,   196,   197,   198,   199,   201,   202,   203,
     204,   207,   217,   220,   145,    26,    42,    86,   112,   148,
     156,   220,   178,    20,    21,    22,   206,    28,   205,   208,
     200,    46,   115,   169,   214,   200,   130,   206,   205,   130,
     218,   220,    58,    66,    67,    81,   128,    24,    66,   112,
      47,   157,    24,   127,   179,   180,   130,    36,    86,   130,
     127,   209,   210,   206,    53,   163,   206,   130,   127,   130,
     219,   218,    20,    21,    22,   185,   186,   186,   163,   194,
     215,    20,    21,   154,   221,   147,    38,   158,   214,    56,
     180,   181,    36,   211,   212,   220,   210,    77,    20,    21,
      22,   170,   171,   173,   175,   130,   213,   194,    74,   113,
     188,    58,   194,   130,   131,   150,    20,    21,   221,    87,
     159,   163,   163,    58,    92,   119,   130,   133,    15,   134,
     162,    56,    57,   176,    11,    74,    81,   151,   152,   155,
      66,    78,   153,    89,    51,   130,   160,   161,   162,    35,
     212,   163,   171,   172,   163,   214,    58,    29,   218,   132,
     133,   157,   149,   130,   163,    72,   215,   130,   152,   130,
     194
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   135,   136,   137,   137,   138,   138,   138,   138,   138,
     139,   139,   140,   140,   141,   142,   142,   142,   143,   144,
     144,   145,   145,   145,   146,   146,   147,   146,   148,   148,
     148,   149,   150,   150,   151,   151,   152,   153,   153,   154,
     154,   154,   155,   155,   156,   156,   157,   158,   158,   158,
     158,   159,   159,   160,   160,   161,   161,   162,   162,   163,
     163,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   165,   166,   166,   167,   168,
     169,   169,   169,   170,   170,   171,   172,   173,   173,   173,
     174,   175,   175,   176,   176,   177,   178,   179,   179,   180,
     181,   181,   182,   183,   184,   185,   186,   186,   186,   187,
     188,   188,   189,   190,   190,   191,   192,   193,   194,   195,
     195,   195,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   205,   205,   206,   206,   206,   207,   208,
     207,   209,   209,   210,   211,   211,   212,   213,   214,   215,
     216,   216,   217,   217,   218,   218,   219,   219,   220,   220,
     220,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     2,     3,     3,     3,     3,     3,
       1,     1,     0,     1,     6,     1,     2,     3,     1,     2,
       1,     1,     1,     3,     6,     5,     0,     7,     0,     2,
       1,     0,     0,     3,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     0,     0,     2,     2,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     0,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       0,     1,     1,     3,     1,     3,     0,     1,     1,     1,
       8,     0,     4,     0,     2,     7,     0,     2,     1,     3,
       0,     2,     3,     4,     4,     2,     1,     1,     1,     8,
       0,     2,     3,     1,     1,     1,     1,     1,     5,     1,
       1,     1,     1,     1,     2,     4,     4,     0,     3,     2,
       3,     3,     2,     3,     0,     1,     1,     1,     0,     0,
       3,     2,     1,     4,     3,     1,     1,     0,     0,     0,
       0,     3,     0,     3,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* pl_function: comp_options pl_block opt_semi  */
#line 360 "pl_gram.y"
                                        {
						plpgsql_parse_result = (PLpgSQL_stmt_block *) (yyvsp[-1].stmt);
					}
#line 2017 "pl_gram.c"
    break;

  case 5: /* comp_option: '#' K_OPTION K_DUMP  */
#line 370 "pl_gram.y"
                                        {
						plpgsql_DumpExecTree = true;
					}
#line 2025 "pl_gram.c"
    break;

  case 6: /* comp_option: '#' K_PRINT_STRICT_PARAMS option_value  */
#line 374 "pl_gram.y"
                                        {
						if (strcmp((yyvsp[0].str), "on") == 0)
							plpgsql_curr_compile->print_strict_params = true;
						else if (strcmp((yyvsp[0].str), "off") == 0)
							plpgsql_curr_compile->print_strict_params = false;
						else
							elog(ERROR, "unrecognized print_strict_params option %s", (yyvsp[0].str));
					}
#line 2038 "pl_gram.c"
    break;

  case 7: /* comp_option: '#' K_VARIABLE_CONFLICT K_ERROR  */
#line 383 "pl_gram.y"
                                        {
						plpgsql_curr_compile->resolve_option = PLPGSQL_RESOLVE_ERROR;
					}
#line 2046 "pl_gram.c"
    break;

  case 8: /* comp_option: '#' K_VARIABLE_CONFLICT K_USE_VARIABLE  */
#line 387 "pl_gram.y"
                                        {
						plpgsql_curr_compile->resolve_option = PLPGSQL_RESOLVE_VARIABLE;
					}
#line 2054 "pl_gram.c"
    break;

  case 9: /* comp_option: '#' K_VARIABLE_CONFLICT K_USE_COLUMN  */
#line 391 "pl_gram.y"
                                        {
						plpgsql_curr_compile->resolve_option = PLPGSQL_RESOLVE_COLUMN;
					}
#line 2062 "pl_gram.c"
    break;

  case 10: /* option_value: T_WORD  */
#line 397 "pl_gram.y"
                                {
					(yyval.str) = (yyvsp[0].word).ident;
				}
#line 2070 "pl_gram.c"
    break;

  case 11: /* option_value: unreserved_keyword  */
#line 401 "pl_gram.y"
                                {
					(yyval.str) = pstrdup((yyvsp[0].keyword));
				}
#line 2078 "pl_gram.c"
    break;

  case 14: /* pl_block: decl_sect K_BEGIN proc_sect exception_sect K_END opt_label  */
#line 410 "pl_gram.y"
                                        {
						PLpgSQL_stmt_block *new;

						new = palloc0(sizeof(PLpgSQL_stmt_block));

						new->cmd_type	= PLPGSQL_STMT_BLOCK;
						new->lineno		= plpgsql_location_to_lineno((yylsp[-4]));
						new->stmtid		= ++plpgsql_curr_compile->nstatements;
						new->label		= (yyvsp[-5].declhdr).label;
						new->n_initvars = (yyvsp[-5].declhdr).n_initvars;
						new->initvarnos = (yyvsp[-5].declhdr).initvarnos;
						new->body		= (yyvsp[-3].list);
						new->exceptions	= (yyvsp[-2].exception_block);

						check_labels((yyvsp[-5].declhdr).label, (yyvsp[0].str), (yylsp[0]));
						plpgsql_ns_pop();

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 2102 "pl_gram.c"
    break;

  case 15: /* decl_sect: opt_block_label  */
#line 433 "pl_gram.y"
                                        {
						/* done with decls, so resume identifier lookup */
						plpgsql_IdentifierLookup = IDENTIFIER_LOOKUP_NORMAL;
						(yyval.declhdr).label	  = (yyvsp[0].str);
						(yyval.declhdr).n_initvars = 0;
						(yyval.declhdr).initvarnos = NULL;
					}
#line 2114 "pl_gram.c"
    break;

  case 16: /* decl_sect: opt_block_label decl_start  */
#line 441 "pl_gram.y"
                                        {
						plpgsql_IdentifierLookup = IDENTIFIER_LOOKUP_NORMAL;
						(yyval.declhdr).label	  = (yyvsp[-1].str);
						(yyval.declhdr).n_initvars = 0;
						(yyval.declhdr).initvarnos = NULL;
					}
#line 2125 "pl_gram.c"
    break;

  case 17: /* decl_sect: opt_block_label decl_start decl_stmts  */
#line 448 "pl_gram.y"
                                        {
						plpgsql_IdentifierLookup = IDENTIFIER_LOOKUP_NORMAL;
						(yyval.declhdr).label	  = (yyvsp[-2].str);
						/* Remember variables declared in decl_stmts */
						(yyval.declhdr).n_initvars = plpgsql_add_initdatums(&((yyval.declhdr).initvarnos));
					}
#line 2136 "pl_gram.c"
    break;

  case 18: /* decl_start: K_DECLARE  */
#line 457 "pl_gram.y"
                                        {
						/* Forget any variables created before block */
						plpgsql_add_initdatums(NULL);
						/*
						 * Disable scanner lookup of identifiers while
						 * we process the decl_stmts
						 */
						plpgsql_IdentifierLookup = IDENTIFIER_LOOKUP_DECLARE;
					}
#line 2150 "pl_gram.c"
    break;

  case 22: /* decl_stmt: K_DECLARE  */
#line 474 "pl_gram.y"
                                        {
						/* We allow useless extra DECLAREs */
					}
#line 2158 "pl_gram.c"
    break;

  case 23: /* decl_stmt: LESS_LESS any_identifier GREATER_GREATER  */
#line 478 "pl_gram.y"
                                        {
						/*
						 * Throw a helpful error if user tries to put block
						 * label just before BEGIN, instead of before DECLARE.
						 */
						ereport(ERROR,
								(errcode(ERRCODE_SYNTAX_ERROR),
								 errmsg("block label must be placed before DECLARE, not after"),
								 parser_errposition((yylsp[-2]))));
					}
#line 2173 "pl_gram.c"
    break;

  case 24: /* decl_statement: decl_varname decl_const decl_datatype decl_collate decl_notnull decl_defval  */
#line 491 "pl_gram.y"
                                        {
						PLpgSQL_variable	*var;

						/*
						 * If a collation is supplied, insert it into the
						 * datatype.  We assume decl_datatype always returns
						 * a freshly built struct not shared with other
						 * variables.
						 */
						if (OidIsValid((yyvsp[-2].oid)))
						{
							if (!OidIsValid((yyvsp[-3].dtype)->collation))
								ereport(ERROR,
										(errcode(ERRCODE_DATATYPE_MISMATCH),
										 errmsg("collations are not supported by type %s",
												format_type_be((yyvsp[-3].dtype)->typoid)),
										 parser_errposition((yylsp[-2]))));
							(yyvsp[-3].dtype)->collation = (yyvsp[-2].oid);
						}

						var = plpgsql_build_variable((yyvsp[-5].varname).name, (yyvsp[-5].varname).lineno,
													 (yyvsp[-3].dtype), true);
						var->isconst = (yyvsp[-4].boolean);
						var->notnull = (yyvsp[-1].boolean);
						var->default_val = (yyvsp[0].expr);

						/*
						 * The combination of NOT NULL without an initializer
						 * can't work, so let's reject it at compile time.
						 */
						if (var->notnull && var->default_val == NULL)
							ereport(ERROR,
									(errcode(ERRCODE_NULL_VALUE_NOT_ALLOWED),
									 errmsg("variable \"%s\" must have a default value, since it's declared NOT NULL",
											var->refname),
									 parser_errposition((yylsp[-1]))));
					}
#line 2215 "pl_gram.c"
    break;

  case 25: /* decl_statement: decl_varname K_ALIAS K_FOR decl_aliasitem ';'  */
#line 529 "pl_gram.y"
                                        {
						plpgsql_ns_additem((yyvsp[-1].nsitem)->itemtype,
										   (yyvsp[-1].nsitem)->itemno, (yyvsp[-4].varname).name);
					}
#line 2224 "pl_gram.c"
    break;

  case 26: /* $@1: %empty  */
#line 534 "pl_gram.y"
                                        { plpgsql_ns_push((yyvsp[-2].varname).name, PLPGSQL_LABEL_OTHER); }
#line 2230 "pl_gram.c"
    break;

  case 27: /* decl_statement: decl_varname opt_scrollable K_CURSOR $@1 decl_cursor_args decl_is_for decl_cursor_query  */
#line 536 "pl_gram.y"
                                        {
						PLpgSQL_var *new;
						PLpgSQL_expr *curname_def;
						char		buf[NAMEDATALEN * 2 + 64];
						char		*cp1;
						char		*cp2;

						/* pop local namespace for cursor args */
						plpgsql_ns_pop();

						new = (PLpgSQL_var *)
							plpgsql_build_variable((yyvsp[-6].varname).name, (yyvsp[-6].varname).lineno,
												   plpgsql_build_datatype(REFCURSOROID,
																		  -1,
																		  InvalidOid,
																		  NULL),
												   true);

						curname_def = palloc0(sizeof(PLpgSQL_expr));

						/* Note: refname has been truncated to NAMEDATALEN */
						cp1 = new->refname;
						cp2 = buf;
						/*
						 * Don't trust standard_conforming_strings here;
						 * it might change before we use the string.
						 */
						if (strchr(cp1, '\\') != NULL)
							*cp2++ = ESCAPE_STRING_SYNTAX;
						*cp2++ = '\'';
						while (*cp1)
						{
							if (SQL_STR_DOUBLE(*cp1, true))
								*cp2++ = *cp1;
							*cp2++ = *cp1++;
						}
						strcpy(cp2, "'::pg_catalog.refcursor");
						curname_def->query = pstrdup(buf);
						curname_def->parseMode = RAW_PARSE_PLPGSQL_EXPR;
						new->default_val = curname_def;

						new->cursor_explicit_expr = (yyvsp[0].expr);
						if ((yyvsp[-2].datum) == NULL)
							new->cursor_explicit_argrow = -1;
						else
							new->cursor_explicit_argrow = (yyvsp[-2].datum)->dno;
						new->cursor_options = CURSOR_OPT_FAST_PLAN | (yyvsp[-5].ival);
					}
#line 2283 "pl_gram.c"
    break;

  case 28: /* opt_scrollable: %empty  */
#line 587 "pl_gram.y"
                                        {
						(yyval.ival) = 0;
					}
#line 2291 "pl_gram.c"
    break;

  case 29: /* opt_scrollable: K_NO K_SCROLL  */
#line 591 "pl_gram.y"
                                        {
						(yyval.ival) = CURSOR_OPT_NO_SCROLL;
					}
#line 2299 "pl_gram.c"
    break;

  case 30: /* opt_scrollable: K_SCROLL  */
#line 595 "pl_gram.y"
                                        {
						(yyval.ival) = CURSOR_OPT_SCROLL;
					}
#line 2307 "pl_gram.c"
    break;

  case 31: /* decl_cursor_query: %empty  */
#line 601 "pl_gram.y"
                                        {
						(yyval.expr) = read_sql_stmt();
					}
#line 2315 "pl_gram.c"
    break;

  case 32: /* decl_cursor_args: %empty  */
#line 607 "pl_gram.y"
                                        {
						(yyval.datum) = NULL;
					}
#line 2323 "pl_gram.c"
    break;

  case 33: /* decl_cursor_args: '(' decl_cursor_arglist ')'  */
#line 611 "pl_gram.y"
                                        {
						PLpgSQL_row *new;
						int i;
						ListCell *l;

						new = palloc0(sizeof(PLpgSQL_row));
						new->dtype = PLPGSQL_DTYPE_ROW;
						new->refname = "(unnamed row)";
						new->lineno = plpgsql_location_to_lineno((yylsp[-2]));
						new->rowtupdesc = NULL;
						new->nfields = list_length((yyvsp[-1].list));
						new->fieldnames = palloc(new->nfields * sizeof(char *));
						new->varnos = palloc(new->nfields * sizeof(int));

						i = 0;
						foreach (l, (yyvsp[-1].list))
						{
							PLpgSQL_variable *arg = (PLpgSQL_variable *) lfirst(l);
							Assert(!arg->isconst);
							new->fieldnames[i] = arg->refname;
							new->varnos[i] = arg->dno;
							i++;
						}
						list_free((yyvsp[-1].list));

						plpgsql_adddatum((PLpgSQL_datum *) new);
						(yyval.datum) = (PLpgSQL_datum *) new;
					}
#line 2356 "pl_gram.c"
    break;

  case 34: /* decl_cursor_arglist: decl_cursor_arg  */
#line 642 "pl_gram.y"
                                        {
						(yyval.list) = list_make1((yyvsp[0].datum));
					}
#line 2364 "pl_gram.c"
    break;

  case 35: /* decl_cursor_arglist: decl_cursor_arglist ',' decl_cursor_arg  */
#line 646 "pl_gram.y"
                                        {
						(yyval.list) = lappend((yyvsp[-2].list), (yyvsp[0].datum));
					}
#line 2372 "pl_gram.c"
    break;

  case 36: /* decl_cursor_arg: decl_varname decl_datatype  */
#line 652 "pl_gram.y"
                                        {
						(yyval.datum) = (PLpgSQL_datum *)
							plpgsql_build_variable((yyvsp[-1].varname).name, (yyvsp[-1].varname).lineno,
												   (yyvsp[0].dtype), true);
					}
#line 2382 "pl_gram.c"
    break;

  case 39: /* decl_aliasitem: T_WORD  */
#line 663 "pl_gram.y"
                                        {
						PLpgSQL_nsitem *nsi;

						nsi = plpgsql_ns_lookup(plpgsql_ns_top(), false,
												(yyvsp[0].word).ident, NULL, NULL,
												NULL);
						if (nsi == NULL)
							ereport(ERROR,
									(errcode(ERRCODE_UNDEFINED_OBJECT),
									 errmsg("variable \"%s\" does not exist",
											(yyvsp[0].word).ident),
									 parser_errposition((yylsp[0]))));
						(yyval.nsitem) = nsi;
					}
#line 2401 "pl_gram.c"
    break;

  case 40: /* decl_aliasitem: unreserved_keyword  */
#line 678 "pl_gram.y"
                                        {
						PLpgSQL_nsitem *nsi;

						nsi = plpgsql_ns_lookup(plpgsql_ns_top(), false,
												(yyvsp[0].keyword), NULL, NULL,
												NULL);
						if (nsi == NULL)
							ereport(ERROR,
									(errcode(ERRCODE_UNDEFINED_OBJECT),
									 errmsg("variable \"%s\" does not exist",
											(yyvsp[0].keyword)),
									 parser_errposition((yylsp[0]))));
						(yyval.nsitem) = nsi;
					}
#line 2420 "pl_gram.c"
    break;

  case 41: /* decl_aliasitem: T_CWORD  */
#line 693 "pl_gram.y"
                                        {
						PLpgSQL_nsitem *nsi;

						if (list_length((yyvsp[0].cword).idents) == 2)
							nsi = plpgsql_ns_lookup(plpgsql_ns_top(), false,
													strVal(linitial((yyvsp[0].cword).idents)),
													strVal(lsecond((yyvsp[0].cword).idents)),
													NULL,
													NULL);
						else if (list_length((yyvsp[0].cword).idents) == 3)
							nsi = plpgsql_ns_lookup(plpgsql_ns_top(), false,
													strVal(linitial((yyvsp[0].cword).idents)),
													strVal(lsecond((yyvsp[0].cword).idents)),
													strVal(lthird((yyvsp[0].cword).idents)),
													NULL);
						else
							nsi = NULL;
						if (nsi == NULL)
							ereport(ERROR,
									(errcode(ERRCODE_UNDEFINED_OBJECT),
									 errmsg("variable \"%s\" does not exist",
											NameListToString((yyvsp[0].cword).idents)),
									 parser_errposition((yylsp[0]))));
						(yyval.nsitem) = nsi;
					}
#line 2450 "pl_gram.c"
    break;

  case 42: /* decl_varname: T_WORD  */
#line 721 "pl_gram.y"
                                        {
						(yyval.varname).name = (yyvsp[0].word).ident;
						(yyval.varname).lineno = plpgsql_location_to_lineno((yylsp[0]));
						/*
						 * Check to make sure name isn't already declared
						 * in the current block.
						 */
						if (plpgsql_ns_lookup(plpgsql_ns_top(), true,
											  (yyvsp[0].word).ident, NULL, NULL,
											  NULL) != NULL)
							yyerror("duplicate declaration");

						if (plpgsql_curr_compile->extra_warnings & PLPGSQL_XCHECK_SHADOWVAR ||
							plpgsql_curr_compile->extra_errors & PLPGSQL_XCHECK_SHADOWVAR)
						{
							PLpgSQL_nsitem *nsi;
							nsi = plpgsql_ns_lookup(plpgsql_ns_top(), false,
													(yyvsp[0].word).ident, NULL, NULL, NULL);
							if (nsi != NULL)
								ereport(plpgsql_curr_compile->extra_errors & PLPGSQL_XCHECK_SHADOWVAR ? ERROR : WARNING,
										(errcode(ERRCODE_DUPLICATE_ALIAS),
										 errmsg("variable \"%s\" shadows a previously defined variable",
												(yyvsp[0].word).ident),
										 parser_errposition((yylsp[0]))));
						}

					}
#line 2482 "pl_gram.c"
    break;

  case 43: /* decl_varname: unreserved_keyword  */
#line 749 "pl_gram.y"
                                        {
						(yyval.varname).name = pstrdup((yyvsp[0].keyword));
						(yyval.varname).lineno = plpgsql_location_to_lineno((yylsp[0]));
						/*
						 * Check to make sure name isn't already declared
						 * in the current block.
						 */
						if (plpgsql_ns_lookup(plpgsql_ns_top(), true,
											  (yyvsp[0].keyword), NULL, NULL,
											  NULL) != NULL)
							yyerror("duplicate declaration");

						if (plpgsql_curr_compile->extra_warnings & PLPGSQL_XCHECK_SHADOWVAR ||
							plpgsql_curr_compile->extra_errors & PLPGSQL_XCHECK_SHADOWVAR)
						{
							PLpgSQL_nsitem *nsi;
							nsi = plpgsql_ns_lookup(plpgsql_ns_top(), false,
													(yyvsp[0].keyword), NULL, NULL, NULL);
							if (nsi != NULL)
								ereport(plpgsql_curr_compile->extra_errors & PLPGSQL_XCHECK_SHADOWVAR ? ERROR : WARNING,
										(errcode(ERRCODE_DUPLICATE_ALIAS),
										 errmsg("variable \"%s\" shadows a previously defined variable",
												(yyvsp[0].keyword)),
										 parser_errposition((yylsp[0]))));
						}

					}
#line 2514 "pl_gram.c"
    break;

  case 44: /* decl_const: %empty  */
#line 779 "pl_gram.y"
                                        { (yyval.boolean) = false; }
#line 2520 "pl_gram.c"
    break;

  case 45: /* decl_const: K_CONSTANT  */
#line 781 "pl_gram.y"
                                        { (yyval.boolean) = true; }
#line 2526 "pl_gram.c"
    break;

  case 46: /* decl_datatype: %empty  */
#line 785 "pl_gram.y"
                                        {
						/*
						 * If there's a lookahead token, read_datatype
						 * should consume it.
						 */
						(yyval.dtype) = read_datatype(yychar);
						yyclearin;
					}
#line 2539 "pl_gram.c"
    break;

  case 47: /* decl_collate: %empty  */
#line 796 "pl_gram.y"
                                        { (yyval.oid) = InvalidOid; }
#line 2545 "pl_gram.c"
    break;

  case 48: /* decl_collate: K_COLLATE T_WORD  */
#line 798 "pl_gram.y"
                                        {
						(yyval.oid) = get_collation_oid(list_make1(makeString((yyvsp[0].word).ident)),
											   false);
					}
#line 2554 "pl_gram.c"
    break;

  case 49: /* decl_collate: K_COLLATE unreserved_keyword  */
#line 803 "pl_gram.y"
                                        {
						(yyval.oid) = get_collation_oid(list_make1(makeString(pstrdup((yyvsp[0].keyword)))),
											   false);
					}
#line 2563 "pl_gram.c"
    break;

  case 50: /* decl_collate: K_COLLATE T_CWORD  */
#line 808 "pl_gram.y"
                                        {
						(yyval.oid) = get_collation_oid((yyvsp[0].cword).idents, false);
					}
#line 2571 "pl_gram.c"
    break;

  case 51: /* decl_notnull: %empty  */
#line 814 "pl_gram.y"
                                        { (yyval.boolean) = false; }
#line 2577 "pl_gram.c"
    break;

  case 52: /* decl_notnull: K_NOT K_NULL  */
#line 816 "pl_gram.y"
                                        { (yyval.boolean) = true; }
#line 2583 "pl_gram.c"
    break;

  case 53: /* decl_defval: ';'  */
#line 820 "pl_gram.y"
                                        { (yyval.expr) = NULL; }
#line 2589 "pl_gram.c"
    break;

  case 54: /* decl_defval: decl_defkey  */
#line 822 "pl_gram.y"
                                        {
						(yyval.expr) = read_sql_expression(';', ";");
					}
#line 2597 "pl_gram.c"
    break;

  case 59: /* proc_sect: %empty  */
#line 841 "pl_gram.y"
                                        { (yyval.list) = NIL; }
#line 2603 "pl_gram.c"
    break;

  case 60: /* proc_sect: proc_sect proc_stmt  */
#line 843 "pl_gram.y"
                                        {
						/* don't bother linking null statements into list */
						if ((yyvsp[0].stmt) == NULL)
							(yyval.list) = (yyvsp[-1].list);
						else
							(yyval.list) = lappend((yyvsp[-1].list), (yyvsp[0].stmt));
					}
#line 2615 "pl_gram.c"
    break;

  case 61: /* proc_stmt: pl_block ';'  */
#line 853 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 2621 "pl_gram.c"
    break;

  case 62: /* proc_stmt: stmt_assign  */
#line 855 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2627 "pl_gram.c"
    break;

  case 63: /* proc_stmt: stmt_if  */
#line 857 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2633 "pl_gram.c"
    break;

  case 64: /* proc_stmt: stmt_case  */
#line 859 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2639 "pl_gram.c"
    break;

  case 65: /* proc_stmt: stmt_loop  */
#line 861 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2645 "pl_gram.c"
    break;

  case 66: /* proc_stmt: stmt_while  */
#line 863 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2651 "pl_gram.c"
    break;

  case 67: /* proc_stmt: stmt_for  */
#line 865 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2657 "pl_gram.c"
    break;

  case 68: /* proc_stmt: stmt_foreach_a  */
#line 867 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2663 "pl_gram.c"
    break;

  case 69: /* proc_stmt: stmt_exit  */
#line 869 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2669 "pl_gram.c"
    break;

  case 70: /* proc_stmt: stmt_return  */
#line 871 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2675 "pl_gram.c"
    break;

  case 71: /* proc_stmt: stmt_raise  */
#line 873 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2681 "pl_gram.c"
    break;

  case 72: /* proc_stmt: stmt_assert  */
#line 875 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2687 "pl_gram.c"
    break;

  case 73: /* proc_stmt: stmt_execsql  */
#line 877 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2693 "pl_gram.c"
    break;

  case 74: /* proc_stmt: stmt_dynexecute  */
#line 879 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2699 "pl_gram.c"
    break;

  case 75: /* proc_stmt: stmt_perform  */
#line 881 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2705 "pl_gram.c"
    break;

  case 76: /* proc_stmt: stmt_call  */
#line 883 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2711 "pl_gram.c"
    break;

  case 77: /* proc_stmt: stmt_getdiag  */
#line 885 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2717 "pl_gram.c"
    break;

  case 78: /* proc_stmt: stmt_open  */
#line 887 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2723 "pl_gram.c"
    break;

  case 79: /* proc_stmt: stmt_fetch  */
#line 889 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2729 "pl_gram.c"
    break;

  case 80: /* proc_stmt: stmt_move  */
#line 891 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2735 "pl_gram.c"
    break;

  case 81: /* proc_stmt: stmt_close  */
#line 893 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2741 "pl_gram.c"
    break;

  case 82: /* proc_stmt: stmt_null  */
#line 895 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2747 "pl_gram.c"
    break;

  case 83: /* proc_stmt: stmt_commit  */
#line 897 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2753 "pl_gram.c"
    break;

  case 84: /* proc_stmt: stmt_rollback  */
#line 899 "pl_gram.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2759 "pl_gram.c"
    break;

  case 85: /* stmt_perform: K_PERFORM  */
#line 903 "pl_gram.y"
                                        {
						PLpgSQL_stmt_perform *new;
						int		startloc;

						new = palloc0(sizeof(PLpgSQL_stmt_perform));
						new->cmd_type = PLPGSQL_STMT_PERFORM;
						new->lineno   = plpgsql_location_to_lineno((yylsp[0]));
						new->stmtid = ++plpgsql_curr_compile->nstatements;
						plpgsql_push_back_token(K_PERFORM);

						/*
						 * Since PERFORM isn't legal SQL, we have to cheat to
						 * the extent of substituting "SELECT" for "PERFORM"
						 * in the parsed text.  It does not seem worth
						 * inventing a separate parse mode for this one case.
						 * We can't do syntax-checking until after we make the
						 * substitution.
						 */
						new->expr = read_sql_construct(';', 0, 0, ";",
													   RAW_PARSE_DEFAULT,
													   false, false,
													   &startloc, NULL);
						/* overwrite "perform" ... */
						memcpy(new->expr->query, " SELECT", 7);
						/* left-justify to get rid of the leading space */
						memmove(new->expr->query, new->expr->query + 1,
								strlen(new->expr->query));
						/* offset syntax error position to account for that */
						check_sql_expr(new->expr->query, new->expr->parseMode,
									   startloc + 1);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 2797 "pl_gram.c"
    break;

  case 86: /* stmt_call: K_CALL  */
#line 939 "pl_gram.y"
                                        {
						PLpgSQL_stmt_call *new;

						new = palloc0(sizeof(PLpgSQL_stmt_call));
						new->cmd_type = PLPGSQL_STMT_CALL;
						new->lineno = plpgsql_location_to_lineno((yylsp[0]));
						new->stmtid = ++plpgsql_curr_compile->nstatements;
						plpgsql_push_back_token(K_CALL);
						new->expr = read_sql_stmt();
						new->is_call = true;

						/* Remember we may need a procedure resource owner */
						plpgsql_curr_compile->requires_procedure_resowner = true;

						(yyval.stmt) = (PLpgSQL_stmt *)new;

					}
#line 2819 "pl_gram.c"
    break;

  case 87: /* stmt_call: K_DO  */
#line 957 "pl_gram.y"
                                        {
						/* use the same structures as for CALL, for simplicity */
						PLpgSQL_stmt_call *new;

						new = palloc0(sizeof(PLpgSQL_stmt_call));
						new->cmd_type = PLPGSQL_STMT_CALL;
						new->lineno = plpgsql_location_to_lineno((yylsp[0]));
						new->stmtid = ++plpgsql_curr_compile->nstatements;
						plpgsql_push_back_token(K_DO);
						new->expr = read_sql_stmt();
						new->is_call = false;

						/* Remember we may need a procedure resource owner */
						plpgsql_curr_compile->requires_procedure_resowner = true;

						(yyval.stmt) = (PLpgSQL_stmt *)new;

					}
#line 2842 "pl_gram.c"
    break;

  case 88: /* stmt_assign: T_DATUM  */
#line 978 "pl_gram.y"
                                        {
						PLpgSQL_stmt_assign *new;
						RawParseMode pmode;

						/* see how many names identify the datum */
						switch ((yyvsp[0].wdatum).ident ? 1 : list_length((yyvsp[0].wdatum).idents))
						{
							case 1:
								pmode = RAW_PARSE_PLPGSQL_ASSIGN1;
								break;
							case 2:
								pmode = RAW_PARSE_PLPGSQL_ASSIGN2;
								break;
							case 3:
								pmode = RAW_PARSE_PLPGSQL_ASSIGN3;
								break;
							default:
								elog(ERROR, "unexpected number of names");
								pmode = 0; /* keep compiler quiet */
						}

						check_assignable((yyvsp[0].wdatum).datum, (yylsp[0]));
						new = palloc0(sizeof(PLpgSQL_stmt_assign));
						new->cmd_type = PLPGSQL_STMT_ASSIGN;
						new->lineno   = plpgsql_location_to_lineno((yylsp[0]));
						new->stmtid = ++plpgsql_curr_compile->nstatements;
						new->varno = (yyvsp[0].wdatum).datum->dno;
						/* Push back the head name to include it in the stmt */
						plpgsql_push_back_token(T_DATUM);
						new->expr = read_sql_construct(';', 0, 0, ";",
													   pmode,
													   false, true,
													   NULL, NULL);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 2883 "pl_gram.c"
    break;

  case 89: /* stmt_getdiag: K_GET getdiag_area_opt K_DIAGNOSTICS getdiag_list ';'  */
#line 1017 "pl_gram.y"
                                        {
						PLpgSQL_stmt_getdiag	 *new;
						ListCell		*lc;

						new = palloc0(sizeof(PLpgSQL_stmt_getdiag));
						new->cmd_type = PLPGSQL_STMT_GETDIAG;
						new->lineno   = plpgsql_location_to_lineno((yylsp[-4]));
						new->stmtid	  = ++plpgsql_curr_compile->nstatements;
						new->is_stacked = (yyvsp[-3].boolean);
						new->diag_items = (yyvsp[-1].list);

						/*
						 * Check information items are valid for area option.
						 */
						foreach(lc, new->diag_items)
						{
							PLpgSQL_diag_item *ditem = (PLpgSQL_diag_item *) lfirst(lc);

							switch (ditem->kind)
							{
								/* these fields are disallowed in stacked case */
								case PLPGSQL_GETDIAG_ROW_COUNT:
									if (new->is_stacked)
										ereport(ERROR,
												(errcode(ERRCODE_SYNTAX_ERROR),
												 errmsg("diagnostics item %s is not allowed in GET STACKED DIAGNOSTICS",
														plpgsql_getdiag_kindname(ditem->kind)),
												 parser_errposition((yylsp[-4]))));
									break;
								/* these fields are disallowed in current case */
								case PLPGSQL_GETDIAG_ERROR_CONTEXT:
								case PLPGSQL_GETDIAG_ERROR_DETAIL:
								case PLPGSQL_GETDIAG_ERROR_HINT:
								case PLPGSQL_GETDIAG_RETURNED_SQLSTATE:
								case PLPGSQL_GETDIAG_COLUMN_NAME:
								case PLPGSQL_GETDIAG_CONSTRAINT_NAME:
								case PLPGSQL_GETDIAG_DATATYPE_NAME:
								case PLPGSQL_GETDIAG_MESSAGE_TEXT:
								case PLPGSQL_GETDIAG_TABLE_NAME:
								case PLPGSQL_GETDIAG_SCHEMA_NAME:
									if (!new->is_stacked)
										ereport(ERROR,
												(errcode(ERRCODE_SYNTAX_ERROR),
												 errmsg("diagnostics item %s is not allowed in GET CURRENT DIAGNOSTICS",
														plpgsql_getdiag_kindname(ditem->kind)),
												 parser_errposition((yylsp[-4]))));
									break;
								/* these fields are allowed in either case */
								case PLPGSQL_GETDIAG_CONTEXT:
									break;
								default:
									elog(ERROR, "unrecognized diagnostic item kind: %d",
										 ditem->kind);
									break;
							}
						}

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 2947 "pl_gram.c"
    break;

  case 90: /* getdiag_area_opt: %empty  */
#line 1079 "pl_gram.y"
                                        {
						(yyval.boolean) = false;
					}
#line 2955 "pl_gram.c"
    break;

  case 91: /* getdiag_area_opt: K_CURRENT  */
#line 1083 "pl_gram.y"
                                        {
						(yyval.boolean) = false;
					}
#line 2963 "pl_gram.c"
    break;

  case 92: /* getdiag_area_opt: K_STACKED  */
#line 1087 "pl_gram.y"
                                        {
						(yyval.boolean) = true;
					}
#line 2971 "pl_gram.c"
    break;

  case 93: /* getdiag_list: getdiag_list ',' getdiag_list_item  */
#line 1093 "pl_gram.y"
                                        {
						(yyval.list) = lappend((yyvsp[-2].list), (yyvsp[0].diagitem));
					}
#line 2979 "pl_gram.c"
    break;

  case 94: /* getdiag_list: getdiag_list_item  */
#line 1097 "pl_gram.y"
                                        {
						(yyval.list) = list_make1((yyvsp[0].diagitem));
					}
#line 2987 "pl_gram.c"
    break;

  case 95: /* getdiag_list_item: getdiag_target assign_operator getdiag_item  */
#line 1103 "pl_gram.y"
                                        {
						PLpgSQL_diag_item *new;

						new = palloc(sizeof(PLpgSQL_diag_item));
						new->target = (yyvsp[-2].datum)->dno;
						new->kind = (yyvsp[0].ival);

						(yyval.diagitem) = new;
					}
#line 3001 "pl_gram.c"
    break;

  case 96: /* getdiag_item: %empty  */
#line 1115 "pl_gram.y"
                                        {
						int	tok = yylex();

						if (tok_is_keyword(tok, &yylval,
										   K_ROW_COUNT, "row_count"))
							(yyval.ival) = PLPGSQL_GETDIAG_ROW_COUNT;
						else if (tok_is_keyword(tok, &yylval,
												K_PG_CONTEXT, "pg_context"))
							(yyval.ival) = PLPGSQL_GETDIAG_CONTEXT;
						else if (tok_is_keyword(tok, &yylval,
												K_PG_EXCEPTION_DETAIL, "pg_exception_detail"))
							(yyval.ival) = PLPGSQL_GETDIAG_ERROR_DETAIL;
						else if (tok_is_keyword(tok, &yylval,
												K_PG_EXCEPTION_HINT, "pg_exception_hint"))
							(yyval.ival) = PLPGSQL_GETDIAG_ERROR_HINT;
						else if (tok_is_keyword(tok, &yylval,
												K_PG_EXCEPTION_CONTEXT, "pg_exception_context"))
							(yyval.ival) = PLPGSQL_GETDIAG_ERROR_CONTEXT;
						else if (tok_is_keyword(tok, &yylval,
												K_COLUMN_NAME, "column_name"))
							(yyval.ival) = PLPGSQL_GETDIAG_COLUMN_NAME;
						else if (tok_is_keyword(tok, &yylval,
												K_CONSTRAINT_NAME, "constraint_name"))
							(yyval.ival) = PLPGSQL_GETDIAG_CONSTRAINT_NAME;
						else if (tok_is_keyword(tok, &yylval,
												K_PG_DATATYPE_NAME, "pg_datatype_name"))
							(yyval.ival) = PLPGSQL_GETDIAG_DATATYPE_NAME;
						else if (tok_is_keyword(tok, &yylval,
												K_MESSAGE_TEXT, "message_text"))
							(yyval.ival) = PLPGSQL_GETDIAG_MESSAGE_TEXT;
						else if (tok_is_keyword(tok, &yylval,
												K_TABLE_NAME, "table_name"))
							(yyval.ival) = PLPGSQL_GETDIAG_TABLE_NAME;
						else if (tok_is_keyword(tok, &yylval,
												K_SCHEMA_NAME, "schema_name"))
							(yyval.ival) = PLPGSQL_GETDIAG_SCHEMA_NAME;
						else if (tok_is_keyword(tok, &yylval,
												K_RETURNED_SQLSTATE, "returned_sqlstate"))
							(yyval.ival) = PLPGSQL_GETDIAG_RETURNED_SQLSTATE;
						else
							yyerror("unrecognized GET DIAGNOSTICS item");
					}
#line 3048 "pl_gram.c"
    break;

  case 97: /* getdiag_target: T_DATUM  */
#line 1160 "pl_gram.y"
                                        {
						/*
						 * In principle we should support a getdiag_target
						 * that is an array element, but for now we don't, so
						 * just throw an error if next token is '['.
						 */
						if ((yyvsp[0].wdatum).datum->dtype == PLPGSQL_DTYPE_ROW ||
							(yyvsp[0].wdatum).datum->dtype == PLPGSQL_DTYPE_REC ||
							plpgsql_peek() == '[')
							ereport(ERROR,
									(errcode(ERRCODE_SYNTAX_ERROR),
									 errmsg("\"%s\" is not a scalar variable",
											NameOfDatum(&((yyvsp[0].wdatum)))),
									 parser_errposition((yylsp[0]))));
						check_assignable((yyvsp[0].wdatum).datum, (yylsp[0]));
						(yyval.datum) = (yyvsp[0].wdatum).datum;
					}
#line 3070 "pl_gram.c"
    break;

  case 98: /* getdiag_target: T_WORD  */
#line 1178 "pl_gram.y"
                                        {
						/* just to give a better message than "syntax error" */
						word_is_not_variable(&((yyvsp[0].word)), (yylsp[0]));
					}
#line 3079 "pl_gram.c"
    break;

  case 99: /* getdiag_target: T_CWORD  */
#line 1183 "pl_gram.y"
                                        {
						/* just to give a better message than "syntax error" */
						cword_is_not_variable(&((yyvsp[0].cword)), (yylsp[0]));
					}
#line 3088 "pl_gram.c"
    break;

  case 100: /* stmt_if: K_IF expr_until_then proc_sect stmt_elsifs stmt_else K_END K_IF ';'  */
#line 1190 "pl_gram.y"
                                        {
						PLpgSQL_stmt_if *new;

						new = palloc0(sizeof(PLpgSQL_stmt_if));
						new->cmd_type	= PLPGSQL_STMT_IF;
						new->lineno		= plpgsql_location_to_lineno((yylsp[-7]));
						new->stmtid		= ++plpgsql_curr_compile->nstatements;
						new->cond		= (yyvsp[-6].expr);
						new->then_body	= (yyvsp[-5].list);
						new->elsif_list = (yyvsp[-4].list);
						new->else_body  = (yyvsp[-3].list);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 3107 "pl_gram.c"
    break;

  case 101: /* stmt_elsifs: %empty  */
#line 1207 "pl_gram.y"
                                        {
						(yyval.list) = NIL;
					}
#line 3115 "pl_gram.c"
    break;

  case 102: /* stmt_elsifs: stmt_elsifs K_ELSIF expr_until_then proc_sect  */
#line 1211 "pl_gram.y"
                                        {
						PLpgSQL_if_elsif *new;

						new = palloc0(sizeof(PLpgSQL_if_elsif));
						new->lineno = plpgsql_location_to_lineno((yylsp[-2]));
						new->cond   = (yyvsp[-1].expr);
						new->stmts  = (yyvsp[0].list);

						(yyval.list) = lappend((yyvsp[-3].list), new);
					}
#line 3130 "pl_gram.c"
    break;

  case 103: /* stmt_else: %empty  */
#line 1224 "pl_gram.y"
                                        {
						(yyval.list) = NIL;
					}
#line 3138 "pl_gram.c"
    break;

  case 104: /* stmt_else: K_ELSE proc_sect  */
#line 1228 "pl_gram.y"
                                        {
						(yyval.list) = (yyvsp[0].list);
					}
#line 3146 "pl_gram.c"
    break;

  case 105: /* stmt_case: K_CASE opt_expr_until_when case_when_list opt_case_else K_END K_CASE ';'  */
#line 1234 "pl_gram.y"
                                        {
						(yyval.stmt) = make_case((yylsp[-6]), (yyvsp[-5].expr), (yyvsp[-4].list), (yyvsp[-3].list));
					}
#line 3154 "pl_gram.c"
    break;

  case 106: /* opt_expr_until_when: %empty  */
#line 1240 "pl_gram.y"
                                        {
						PLpgSQL_expr *expr = NULL;
						int	tok = yylex();

						if (tok != K_WHEN)
						{
							plpgsql_push_back_token(tok);
							expr = read_sql_expression(K_WHEN, "WHEN");
						}
						plpgsql_push_back_token(K_WHEN);
						(yyval.expr) = expr;
					}
#line 3171 "pl_gram.c"
    break;

  case 107: /* case_when_list: case_when_list case_when  */
#line 1255 "pl_gram.y"
                                        {
						(yyval.list) = lappend((yyvsp[-1].list), (yyvsp[0].casewhen));
					}
#line 3179 "pl_gram.c"
    break;

  case 108: /* case_when_list: case_when  */
#line 1259 "pl_gram.y"
                                        {
						(yyval.list) = list_make1((yyvsp[0].casewhen));
					}
#line 3187 "pl_gram.c"
    break;

  case 109: /* case_when: K_WHEN expr_until_then proc_sect  */
#line 1265 "pl_gram.y"
                                        {
						PLpgSQL_case_when *new = palloc(sizeof(PLpgSQL_case_when));

						new->lineno	= plpgsql_location_to_lineno((yylsp[-2]));
						new->expr	= (yyvsp[-1].expr);
						new->stmts	= (yyvsp[0].list);
						(yyval.casewhen) = new;
					}
#line 3200 "pl_gram.c"
    break;

  case 110: /* opt_case_else: %empty  */
#line 1276 "pl_gram.y"
                                        {
						(yyval.list) = NIL;
					}
#line 3208 "pl_gram.c"
    break;

  case 111: /* opt_case_else: K_ELSE proc_sect  */
#line 1280 "pl_gram.y"
                                        {
						/*
						 * proc_sect could return an empty list, but we
						 * must distinguish that from not having ELSE at all.
						 * Simplest fix is to return a list with one NULL
						 * pointer, which make_case() must take care of.
						 */
						if ((yyvsp[0].list) != NIL)
							(yyval.list) = (yyvsp[0].list);
						else
							(yyval.list) = list_make1(NULL);
					}
#line 3225 "pl_gram.c"
    break;

  case 112: /* stmt_loop: opt_loop_label K_LOOP loop_body  */
#line 1295 "pl_gram.y"
                                        {
						PLpgSQL_stmt_loop *new;

						new = palloc0(sizeof(PLpgSQL_stmt_loop));
						new->cmd_type = PLPGSQL_STMT_LOOP;
						new->lineno   = plpgsql_location_to_lineno((yylsp[-1]));
						new->stmtid   = ++plpgsql_curr_compile->nstatements;
						new->label	  = (yyvsp[-2].str);
						new->body	  = (yyvsp[0].loop_body).stmts;

						check_labels((yyvsp[-2].str), (yyvsp[0].loop_body).end_label, (yyvsp[0].loop_body).end_label_location);
						plpgsql_ns_pop();

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 3245 "pl_gram.c"
    break;

  case 113: /* stmt_while: opt_loop_label K_WHILE expr_until_loop loop_body  */
#line 1313 "pl_gram.y"
                                        {
						PLpgSQL_stmt_while *new;

						new = palloc0(sizeof(PLpgSQL_stmt_while));
						new->cmd_type = PLPGSQL_STMT_WHILE;
						new->lineno   = plpgsql_location_to_lineno((yylsp[-2]));
						new->stmtid	  = ++plpgsql_curr_compile->nstatements;
						new->label	  = (yyvsp[-3].str);
						new->cond	  = (yyvsp[-1].expr);
						new->body	  = (yyvsp[0].loop_body).stmts;

						check_labels((yyvsp[-3].str), (yyvsp[0].loop_body).end_label, (yyvsp[0].loop_body).end_label_location);
						plpgsql_ns_pop();

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 3266 "pl_gram.c"
    break;

  case 114: /* stmt_for: opt_loop_label K_FOR for_control loop_body  */
#line 1332 "pl_gram.y"
                                        {
						/* This runs after we've scanned the loop body */
						if ((yyvsp[-1].stmt)->cmd_type == PLPGSQL_STMT_FORI)
						{
							PLpgSQL_stmt_fori		*new;

							new = (PLpgSQL_stmt_fori *) (yyvsp[-1].stmt);
							new->lineno   = plpgsql_location_to_lineno((yylsp[-2]));
							new->label	  = (yyvsp[-3].str);
							new->body	  = (yyvsp[0].loop_body).stmts;
							(yyval.stmt) = (PLpgSQL_stmt *) new;
						}
						else
						{
							PLpgSQL_stmt_forq		*new;

							Assert((yyvsp[-1].stmt)->cmd_type == PLPGSQL_STMT_FORS ||
								   (yyvsp[-1].stmt)->cmd_type == PLPGSQL_STMT_FORC ||
								   (yyvsp[-1].stmt)->cmd_type == PLPGSQL_STMT_DYNFORS);
							/* forq is the common supertype of all three */
							new = (PLpgSQL_stmt_forq *) (yyvsp[-1].stmt);
							new->lineno   = plpgsql_location_to_lineno((yylsp[-2]));
							new->label	  = (yyvsp[-3].str);
							new->body	  = (yyvsp[0].loop_body).stmts;
							(yyval.stmt) = (PLpgSQL_stmt *) new;
						}

						check_labels((yyvsp[-3].str), (yyvsp[0].loop_body).end_label, (yyvsp[0].loop_body).end_label_location);
						/* close namespace started in opt_loop_label */
						plpgsql_ns_pop();
					}
#line 3302 "pl_gram.c"
    break;

  case 115: /* for_control: for_variable K_IN  */
#line 1366 "pl_gram.y"
                                        {
						int			tok = yylex();
						int			tokloc = yylloc;

						if (tok == K_EXECUTE)
						{
							/* EXECUTE means it's a dynamic FOR loop */
							PLpgSQL_stmt_dynfors	*new;
							PLpgSQL_expr			*expr;
							int						term;

							expr = read_sql_expression2(K_LOOP, K_USING,
														"LOOP or USING",
														&term);

							new = palloc0(sizeof(PLpgSQL_stmt_dynfors));
							new->cmd_type = PLPGSQL_STMT_DYNFORS;
							new->stmtid	  = ++plpgsql_curr_compile->nstatements;
							if ((yyvsp[-1].forvariable).row)
							{
								new->var = (PLpgSQL_variable *) (yyvsp[-1].forvariable).row;
								check_assignable((yyvsp[-1].forvariable).row, (yylsp[-1]));
							}
							else if ((yyvsp[-1].forvariable).scalar)
							{
								/* convert single scalar to list */
								new->var = (PLpgSQL_variable *)
									make_scalar_list1((yyvsp[-1].forvariable).name, (yyvsp[-1].forvariable).scalar,
													  (yyvsp[-1].forvariable).lineno, (yylsp[-1]));
								/* make_scalar_list1 did check_assignable */
							}
							else
							{
								ereport(ERROR,
										(errcode(ERRCODE_DATATYPE_MISMATCH),
										 errmsg("loop variable of loop over rows must be a record variable or list of scalar variables"),
										 parser_errposition((yylsp[-1]))));
							}
							new->query = expr;

							if (term == K_USING)
							{
								do
								{
									expr = read_sql_expression2(',', K_LOOP,
																", or LOOP",
																&term);
									new->params = lappend(new->params, expr);
								} while (term == ',');
							}

							(yyval.stmt) = (PLpgSQL_stmt *) new;
						}
						else if (tok == T_DATUM &&
								 yylval.wdatum.datum->dtype == PLPGSQL_DTYPE_VAR &&
								 ((PLpgSQL_var *) yylval.wdatum.datum)->datatype->typoid == REFCURSOROID)
						{
							/* It's FOR var IN cursor */
							PLpgSQL_stmt_forc	*new;
							PLpgSQL_var			*cursor = (PLpgSQL_var *) yylval.wdatum.datum;

							new = (PLpgSQL_stmt_forc *) palloc0(sizeof(PLpgSQL_stmt_forc));
							new->cmd_type = PLPGSQL_STMT_FORC;
							new->stmtid = ++plpgsql_curr_compile->nstatements;
							new->curvar = cursor->dno;

							/* Should have had a single variable name */
							if ((yyvsp[-1].forvariable).scalar && (yyvsp[-1].forvariable).row)
								ereport(ERROR,
										(errcode(ERRCODE_SYNTAX_ERROR),
										 errmsg("cursor FOR loop must have only one target variable"),
										 parser_errposition((yylsp[-1]))));

							/* can't use an unbound cursor this way */
							if (cursor->cursor_explicit_expr == NULL)
								ereport(ERROR,
										(errcode(ERRCODE_SYNTAX_ERROR),
										 errmsg("cursor FOR loop must use a bound cursor variable"),
										 parser_errposition(tokloc)));

							/* collect cursor's parameters if any */
							new->argquery = read_cursor_args(cursor,
															 K_LOOP);

							/* create loop's private RECORD variable */
							new->var = (PLpgSQL_variable *)
								plpgsql_build_record((yyvsp[-1].forvariable).name,
													 (yyvsp[-1].forvariable).lineno,
													 NULL,
													 RECORDOID,
													 true);

							(yyval.stmt) = (PLpgSQL_stmt *) new;
						}
						else
						{
							PLpgSQL_expr	*expr1;
							int				expr1loc;
							bool			reverse = false;

							/*
							 * We have to distinguish between two
							 * alternatives: FOR var IN a .. b and FOR
							 * var IN query. Unfortunately this is
							 * tricky, since the query in the second
							 * form needn't start with a SELECT
							 * keyword.  We use the ugly hack of
							 * looking for two periods after the first
							 * token. We also check for the REVERSE
							 * keyword, which means it must be an
							 * integer loop.
							 */
							if (tok_is_keyword(tok, &yylval,
											   K_REVERSE, "reverse"))
								reverse = true;
							else
								plpgsql_push_back_token(tok);

							/*
							 * Read tokens until we see either a ".."
							 * or a LOOP.  The text we read may be either
							 * an expression or a whole SQL statement, so
							 * we need to invoke read_sql_construct directly,
							 * and tell it not to check syntax yet.
							 */
							expr1 = read_sql_construct(DOT_DOT,
													   K_LOOP,
													   0,
													   "LOOP",
													   RAW_PARSE_DEFAULT,
													   true,
													   false,
													   &expr1loc,
													   &tok);

							if (tok == DOT_DOT)
							{
								/* Saw "..", so it must be an integer loop */
								PLpgSQL_expr		*expr2;
								PLpgSQL_expr		*expr_by;
								PLpgSQL_var			*fvar;
								PLpgSQL_stmt_fori	*new;

								/*
								 * Relabel first expression as an expression;
								 * then we can check its syntax.
								 */
								expr1->parseMode = RAW_PARSE_PLPGSQL_EXPR;
								check_sql_expr(expr1->query, expr1->parseMode,
											   expr1loc);

								/* Read and check the second one */
								expr2 = read_sql_expression2(K_LOOP, K_BY,
															 "LOOP",
															 &tok);

								/* Get the BY clause if any */
								if (tok == K_BY)
									expr_by = read_sql_expression(K_LOOP,
																  "LOOP");
								else
									expr_by = NULL;

								/* Should have had a single variable name */
								if ((yyvsp[-1].forvariable).scalar && (yyvsp[-1].forvariable).row)
									ereport(ERROR,
											(errcode(ERRCODE_SYNTAX_ERROR),
											 errmsg("integer FOR loop must have only one target variable"),
											 parser_errposition((yylsp[-1]))));

								/* create loop's private variable */
								fvar = (PLpgSQL_var *)
									plpgsql_build_variable((yyvsp[-1].forvariable).name,
														   (yyvsp[-1].forvariable).lineno,
														   plpgsql_build_datatype(INT4OID,
																				  -1,
																				  InvalidOid,
																				  NULL),
														   true);

								new = palloc0(sizeof(PLpgSQL_stmt_fori));
								new->cmd_type = PLPGSQL_STMT_FORI;
								new->stmtid	  = ++plpgsql_curr_compile->nstatements;
								new->var	  = fvar;
								new->reverse  = reverse;
								new->lower	  = expr1;
								new->upper	  = expr2;
								new->step	  = expr_by;

								(yyval.stmt) = (PLpgSQL_stmt *) new;
							}
							else
							{
								/*
								 * No "..", so it must be a query loop.
								 */
								PLpgSQL_stmt_fors	*new;

								if (reverse)
									ereport(ERROR,
											(errcode(ERRCODE_SYNTAX_ERROR),
											 errmsg("cannot specify REVERSE in query FOR loop"),
											 parser_errposition(tokloc)));

								/* Check syntax as a regular query */
								check_sql_expr(expr1->query, expr1->parseMode,
											   expr1loc);

								new = palloc0(sizeof(PLpgSQL_stmt_fors));
								new->cmd_type = PLPGSQL_STMT_FORS;
								new->stmtid = ++plpgsql_curr_compile->nstatements;
								if ((yyvsp[-1].forvariable).row)
								{
									new->var = (PLpgSQL_variable *) (yyvsp[-1].forvariable).row;
									check_assignable((yyvsp[-1].forvariable).row, (yylsp[-1]));
								}
								else if ((yyvsp[-1].forvariable).scalar)
								{
									/* convert single scalar to list */
									new->var = (PLpgSQL_variable *)
										make_scalar_list1((yyvsp[-1].forvariable).name, (yyvsp[-1].forvariable).scalar,
														  (yyvsp[-1].forvariable).lineno, (yylsp[-1]));
									/* make_scalar_list1 did check_assignable */
								}
								else
								{
									ereport(ERROR,
											(errcode(ERRCODE_SYNTAX_ERROR),
											 errmsg("loop variable of loop over rows must be a record variable or list of scalar variables"),
											 parser_errposition((yylsp[-1]))));
								}

								new->query = expr1;
								(yyval.stmt) = (PLpgSQL_stmt *) new;
							}
						}
					}
#line 3544 "pl_gram.c"
    break;

  case 116: /* for_variable: T_DATUM  */
#line 1624 "pl_gram.y"
                                        {
						(yyval.forvariable).name = NameOfDatum(&((yyvsp[0].wdatum)));
						(yyval.forvariable).lineno = plpgsql_location_to_lineno((yylsp[0]));
						if ((yyvsp[0].wdatum).datum->dtype == PLPGSQL_DTYPE_ROW ||
							(yyvsp[0].wdatum).datum->dtype == PLPGSQL_DTYPE_REC)
						{
							(yyval.forvariable).scalar = NULL;
							(yyval.forvariable).row = (yyvsp[0].wdatum).datum;
						}
						else
						{
							int			tok;

							(yyval.forvariable).scalar = (yyvsp[0].wdatum).datum;
							(yyval.forvariable).row = NULL;
							/* check for comma-separated list */
							tok = yylex();
							plpgsql_push_back_token(tok);
							if (tok == ',')
								(yyval.forvariable).row = (PLpgSQL_datum *)
									read_into_scalar_list((yyval.forvariable).name,
														  (yyval.forvariable).scalar,
														  (yylsp[0]));
						}
					}
#line 3574 "pl_gram.c"
    break;

  case 117: /* for_variable: T_WORD  */
#line 1650 "pl_gram.y"
                                        {
						int			tok;

						(yyval.forvariable).name = (yyvsp[0].word).ident;
						(yyval.forvariable).lineno = plpgsql_location_to_lineno((yylsp[0]));
						(yyval.forvariable).scalar = NULL;
						(yyval.forvariable).row = NULL;
						/* check for comma-separated list */
						tok = yylex();
						plpgsql_push_back_token(tok);
						if (tok == ',')
							word_is_not_variable(&((yyvsp[0].word)), (yylsp[0]));
					}
#line 3592 "pl_gram.c"
    break;

  case 118: /* for_variable: T_CWORD  */
#line 1664 "pl_gram.y"
                                        {
						/* just to give a better message than "syntax error" */
						cword_is_not_variable(&((yyvsp[0].cword)), (yylsp[0]));
					}
#line 3601 "pl_gram.c"
    break;

  case 119: /* stmt_foreach_a: opt_loop_label K_FOREACH for_variable foreach_slice K_IN K_ARRAY expr_until_loop loop_body  */
#line 1671 "pl_gram.y"
                                        {
						PLpgSQL_stmt_foreach_a *new;

						new = palloc0(sizeof(PLpgSQL_stmt_foreach_a));
						new->cmd_type = PLPGSQL_STMT_FOREACH_A;
						new->lineno = plpgsql_location_to_lineno((yylsp[-6]));
						new->stmtid = ++plpgsql_curr_compile->nstatements;
						new->label = (yyvsp[-7].str);
						new->slice = (yyvsp[-4].ival);
						new->expr = (yyvsp[-1].expr);
						new->body = (yyvsp[0].loop_body).stmts;

						if ((yyvsp[-5].forvariable).row)
						{
							new->varno = (yyvsp[-5].forvariable).row->dno;
							check_assignable((yyvsp[-5].forvariable).row, (yylsp[-5]));
						}
						else if ((yyvsp[-5].forvariable).scalar)
						{
							new->varno = (yyvsp[-5].forvariable).scalar->dno;
							check_assignable((yyvsp[-5].forvariable).scalar, (yylsp[-5]));
						}
						else
						{
							ereport(ERROR,
									(errcode(ERRCODE_SYNTAX_ERROR),
									 errmsg("loop variable of FOREACH must be a known variable or list of variables"),
											 parser_errposition((yylsp[-5]))));
						}

						check_labels((yyvsp[-7].str), (yyvsp[0].loop_body).end_label, (yyvsp[0].loop_body).end_label_location);
						plpgsql_ns_pop();

						(yyval.stmt) = (PLpgSQL_stmt *) new;
					}
#line 3641 "pl_gram.c"
    break;

  case 120: /* foreach_slice: %empty  */
#line 1709 "pl_gram.y"
                                        {
						(yyval.ival) = 0;
					}
#line 3649 "pl_gram.c"
    break;

  case 121: /* foreach_slice: K_SLICE ICONST  */
#line 1713 "pl_gram.y"
                                        {
						(yyval.ival) = (yyvsp[0].ival);
					}
#line 3657 "pl_gram.c"
    break;

  case 122: /* stmt_exit: exit_type opt_label opt_exitcond  */
#line 1719 "pl_gram.y"
                                        {
						PLpgSQL_stmt_exit *new;

						new = palloc0(sizeof(PLpgSQL_stmt_exit));
						new->cmd_type = PLPGSQL_STMT_EXIT;
						new->stmtid	  = ++plpgsql_curr_compile->nstatements;
						new->is_exit  = (yyvsp[-2].boolean);
						new->lineno	  = plpgsql_location_to_lineno((yylsp[-2]));
						new->label	  = (yyvsp[-1].str);
						new->cond	  = (yyvsp[0].expr);

						if ((yyvsp[-1].str))
						{
							/* We have a label, so verify it exists */
							PLpgSQL_nsitem *label;

							label = plpgsql_ns_lookup_label(plpgsql_ns_top(), (yyvsp[-1].str));
							if (label == NULL)
								ereport(ERROR,
										(errcode(ERRCODE_SYNTAX_ERROR),
										 errmsg("there is no label \"%s\" "
												"attached to any block or loop enclosing this statement",
												(yyvsp[-1].str)),
										 parser_errposition((yylsp[-1]))));
							/* CONTINUE only allows loop labels */
							if (label->itemno != PLPGSQL_LABEL_LOOP && !new->is_exit)
								ereport(ERROR,
										(errcode(ERRCODE_SYNTAX_ERROR),
										 errmsg("block label \"%s\" cannot be used in CONTINUE",
												(yyvsp[-1].str)),
										 parser_errposition((yylsp[-1]))));
						}
						else
						{
							/*
							 * No label, so make sure there is some loop (an
							 * unlabeled EXIT does not match a block, so this
							 * is the same test for both EXIT and CONTINUE)
							 */
							if (plpgsql_ns_find_nearest_loop(plpgsql_ns_top()) == NULL)
								ereport(ERROR,
										(errcode(ERRCODE_SYNTAX_ERROR),
										 new->is_exit ?
										 errmsg("EXIT cannot be used outside a loop, unless it has a label") :
										 errmsg("CONTINUE cannot be used outside a loop"),
										 parser_errposition((yylsp[-2]))));
						}

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 3712 "pl_gram.c"
    break;

  case 123: /* exit_type: K_EXIT  */
#line 1772 "pl_gram.y"
                                        {
						(yyval.boolean) = true;
					}
#line 3720 "pl_gram.c"
    break;

  case 124: /* exit_type: K_CONTINUE  */
#line 1776 "pl_gram.y"
                                        {
						(yyval.boolean) = false;
					}
#line 3728 "pl_gram.c"
    break;

  case 125: /* stmt_return: K_RETURN  */
#line 1782 "pl_gram.y"
                                        {
						int	tok;

						tok = yylex();
						if (tok == 0)
							yyerror("unexpected end of function definition");

						if (tok_is_keyword(tok, &yylval,
										   K_NEXT, "next"))
						{
							(yyval.stmt) = make_return_next_stmt((yylsp[0]));
						}
						else if (tok_is_keyword(tok, &yylval,
												K_QUERY, "query"))
						{
							(yyval.stmt) = make_return_query_stmt((yylsp[0]));
						}
						else
						{
							plpgsql_push_back_token(tok);
							(yyval.stmt) = make_return_stmt((yylsp[0]));
						}
					}
#line 3756 "pl_gram.c"
    break;

  case 126: /* stmt_raise: K_RAISE  */
#line 1808 "pl_gram.y"
                                        {
						PLpgSQL_stmt_raise		*new;
						int	tok;

						new = palloc(sizeof(PLpgSQL_stmt_raise));

						new->cmd_type	= PLPGSQL_STMT_RAISE;
						new->lineno		= plpgsql_location_to_lineno((yylsp[0]));
						new->stmtid		= ++plpgsql_curr_compile->nstatements;
						new->elog_level = ERROR;	/* default */
						new->condname	= NULL;
						new->message	= NULL;
						new->params		= NIL;
						new->options	= NIL;

						tok = yylex();
						if (tok == 0)
							yyerror("unexpected end of function definition");

						/*
						 * We could have just RAISE, meaning to re-throw
						 * the current error.
						 */
						if (tok != ';')
						{
							/*
							 * First is an optional elog severity level.
							 */
							if (tok_is_keyword(tok, &yylval,
											   K_EXCEPTION, "exception"))
							{
								new->elog_level = ERROR;
								tok = yylex();
							}
							else if (tok_is_keyword(tok, &yylval,
													K_WARNING, "warning"))
							{
								new->elog_level = WARNING;
								tok = yylex();
							}
							else if (tok_is_keyword(tok, &yylval,
													K_NOTICE, "notice"))
							{
								new->elog_level = NOTICE;
								tok = yylex();
							}
							else if (tok_is_keyword(tok, &yylval,
													K_INFO, "info"))
							{
								new->elog_level = INFO;
								tok = yylex();
							}
							else if (tok_is_keyword(tok, &yylval,
													K_LOG, "log"))
							{
								new->elog_level = LOG;
								tok = yylex();
							}
							else if (tok_is_keyword(tok, &yylval,
													K_DEBUG, "debug"))
							{
								new->elog_level = DEBUG1;
								tok = yylex();
							}
							if (tok == 0)
								yyerror("unexpected end of function definition");

							/*
							 * Next we can have a condition name, or
							 * equivalently SQLSTATE 'xxxxx', or a string
							 * literal that is the old-style message format,
							 * or USING to start the option list immediately.
							 */
							if (tok == SCONST)
							{
								/* old style message and parameters */
								new->message = yylval.str;
								/*
								 * We expect either a semi-colon, which
								 * indicates no parameters, or a comma that
								 * begins the list of parameter expressions,
								 * or USING to begin the options list.
								 */
								tok = yylex();
								if (tok != ',' && tok != ';' && tok != K_USING)
									yyerror("syntax error");

								while (tok == ',')
								{
									PLpgSQL_expr *expr;

									expr = read_sql_construct(',', ';', K_USING,
															  ", or ; or USING",
															  RAW_PARSE_PLPGSQL_EXPR,
															  true, true,
															  NULL, &tok);
									new->params = lappend(new->params, expr);
								}
							}
							else if (tok != K_USING)
							{
								/* must be condition name or SQLSTATE */
								if (tok_is_keyword(tok, &yylval,
												   K_SQLSTATE, "sqlstate"))
								{
									/* next token should be a string literal */
									char   *sqlstatestr;

									if (yylex() != SCONST)
										yyerror("syntax error");
									sqlstatestr = yylval.str;

									if (strlen(sqlstatestr) != 5)
										yyerror("invalid SQLSTATE code");
									if (strspn(sqlstatestr, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ") != 5)
										yyerror("invalid SQLSTATE code");
									new->condname = sqlstatestr;
								}
								else
								{
									if (tok == T_WORD)
										new->condname = yylval.word.ident;
									else if (plpgsql_token_is_unreserved_keyword(tok))
										new->condname = pstrdup(yylval.keyword);
									else
										yyerror("syntax error");
									plpgsql_recognize_err_condition(new->condname,
																	false);
								}
								tok = yylex();
								if (tok != ';' && tok != K_USING)
									yyerror("syntax error");
							}

							if (tok == K_USING)
								new->options = read_raise_options();
						}

						check_raise_parameters(new);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 3903 "pl_gram.c"
    break;

  case 127: /* stmt_assert: K_ASSERT  */
#line 1953 "pl_gram.y"
                                        {
						PLpgSQL_stmt_assert		*new;
						int	tok;

						new = palloc(sizeof(PLpgSQL_stmt_assert));

						new->cmd_type	= PLPGSQL_STMT_ASSERT;
						new->lineno		= plpgsql_location_to_lineno((yylsp[0]));
						new->stmtid		= ++plpgsql_curr_compile->nstatements;

						new->cond = read_sql_expression2(',', ';',
														 ", or ;",
														 &tok);

						if (tok == ',')
							new->message = read_sql_expression(';', ";");
						else
							new->message = NULL;

						(yyval.stmt) = (PLpgSQL_stmt *) new;
					}
#line 3929 "pl_gram.c"
    break;

  case 128: /* loop_body: proc_sect K_END K_LOOP opt_label ';'  */
#line 1977 "pl_gram.y"
                                        {
						(yyval.loop_body).stmts = (yyvsp[-4].list);
						(yyval.loop_body).end_label = (yyvsp[-1].str);
						(yyval.loop_body).end_label_location = (yylsp[-1]);
					}
#line 3939 "pl_gram.c"
    break;

  case 129: /* stmt_execsql: K_IMPORT  */
#line 1995 "pl_gram.y"
                                        {
						(yyval.stmt) = make_execsql_stmt(K_IMPORT, (yylsp[0]), NULL);
					}
#line 3947 "pl_gram.c"
    break;

  case 130: /* stmt_execsql: K_INSERT  */
#line 1999 "pl_gram.y"
                                        {
						(yyval.stmt) = make_execsql_stmt(K_INSERT, (yylsp[0]), NULL);
					}
#line 3955 "pl_gram.c"
    break;

  case 131: /* stmt_execsql: T_WORD  */
#line 2003 "pl_gram.y"
                                        {
						int			tok;

						tok = yylex();
						plpgsql_push_back_token(tok);
						if (tok == '=' || tok == COLON_EQUALS ||
							tok == '[' || tok == '.')
							word_is_not_variable(&((yyvsp[0].word)), (yylsp[0]));
						(yyval.stmt) = make_execsql_stmt(T_WORD, (yylsp[0]), &((yyvsp[0].word)));
					}
#line 3970 "pl_gram.c"
    break;

  case 132: /* stmt_execsql: T_CWORD  */
#line 2014 "pl_gram.y"
                                        {
						int			tok;

						tok = yylex();
						plpgsql_push_back_token(tok);
						if (tok == '=' || tok == COLON_EQUALS ||
							tok == '[' || tok == '.')
							cword_is_not_variable(&((yyvsp[0].cword)), (yylsp[0]));
						(yyval.stmt) = make_execsql_stmt(T_CWORD, (yylsp[0]), NULL);
					}
#line 3985 "pl_gram.c"
    break;

  case 133: /* stmt_dynexecute: K_EXECUTE  */
#line 2027 "pl_gram.y"
                                        {
						PLpgSQL_stmt_dynexecute *new;
						PLpgSQL_expr *expr;
						int endtoken;

						expr = read_sql_construct(K_INTO, K_USING, ';',
												  "INTO or USING or ;",
												  RAW_PARSE_PLPGSQL_EXPR,
												  true, true,
												  NULL, &endtoken);

						new = palloc(sizeof(PLpgSQL_stmt_dynexecute));
						new->cmd_type = PLPGSQL_STMT_DYNEXECUTE;
						new->lineno = plpgsql_location_to_lineno((yylsp[0]));
						new->stmtid = ++plpgsql_curr_compile->nstatements;
						new->query = expr;
						new->into = false;
						new->strict = false;
						new->target = NULL;
						new->params = NIL;

						/*
						 * We loop to allow the INTO and USING clauses to
						 * appear in either order, since people easily get
						 * that wrong.  This coding also prevents "INTO foo"
						 * from getting absorbed into a USING expression,
						 * which is *really* confusing.
						 */
						for (;;)
						{
							if (endtoken == K_INTO)
							{
								if (new->into)			/* multiple INTO */
									yyerror("syntax error");
								new->into = true;
								read_into_target(&new->target, &new->strict);
								endtoken = yylex();
							}
							else if (endtoken == K_USING)
							{
								if (new->params)		/* multiple USING */
									yyerror("syntax error");
								do
								{
									expr = read_sql_construct(',', ';', K_INTO,
															  ", or ; or INTO",
															  RAW_PARSE_PLPGSQL_EXPR,
															  true, true,
															  NULL, &endtoken);
									new->params = lappend(new->params, expr);
								} while (endtoken == ',');
							}
							else if (endtoken == ';')
								break;
							else
								yyerror("syntax error");
						}

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 4050 "pl_gram.c"
    break;

  case 134: /* stmt_open: K_OPEN cursor_variable  */
#line 2091 "pl_gram.y"
                                        {
						PLpgSQL_stmt_open *new;
						int				  tok;

						new = palloc0(sizeof(PLpgSQL_stmt_open));
						new->cmd_type = PLPGSQL_STMT_OPEN;
						new->lineno = plpgsql_location_to_lineno((yylsp[-1]));
						new->stmtid = ++plpgsql_curr_compile->nstatements;
						new->curvar = (yyvsp[0].var)->dno;
						new->cursor_options = CURSOR_OPT_FAST_PLAN;

						if ((yyvsp[0].var)->cursor_explicit_expr == NULL)
						{
							/* be nice if we could use opt_scrollable here */
							tok = yylex();
							if (tok_is_keyword(tok, &yylval,
											   K_NO, "no"))
							{
								tok = yylex();
								if (tok_is_keyword(tok, &yylval,
												   K_SCROLL, "scroll"))
								{
									new->cursor_options |= CURSOR_OPT_NO_SCROLL;
									tok = yylex();
								}
							}
							else if (tok_is_keyword(tok, &yylval,
													K_SCROLL, "scroll"))
							{
								new->cursor_options |= CURSOR_OPT_SCROLL;
								tok = yylex();
							}

							if (tok != K_FOR)
								yyerror("syntax error, expected \"FOR\"");

							tok = yylex();
							if (tok == K_EXECUTE)
							{
								int		endtoken;

								new->dynquery =
									read_sql_expression2(K_USING, ';',
														 "USING or ;",
														 &endtoken);

								/* If we found "USING", collect argument(s) */
								if (endtoken == K_USING)
								{
									PLpgSQL_expr *expr;

									do
									{
										expr = read_sql_expression2(',', ';',
																	", or ;",
																	&endtoken);
										new->params = lappend(new->params,
															  expr);
									} while (endtoken == ',');
								}
							}
							else
							{
								plpgsql_push_back_token(tok);
								new->query = read_sql_stmt();
							}
						}
						else
						{
							/* predefined cursor query, so read args */
							new->argquery = read_cursor_args((yyvsp[0].var), ';');
						}

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 4130 "pl_gram.c"
    break;

  case 135: /* stmt_fetch: K_FETCH opt_fetch_direction cursor_variable K_INTO  */
#line 2169 "pl_gram.y"
                                        {
						PLpgSQL_stmt_fetch *fetch = (yyvsp[-2].fetch);
						PLpgSQL_variable *target;

						/* We have already parsed everything through the INTO keyword */
						read_into_target(&target, NULL);

						if (yylex() != ';')
							yyerror("syntax error");

						/*
						 * We don't allow multiple rows in PL/pgSQL's FETCH
						 * statement, only in MOVE.
						 */
						if (fetch->returns_multiple_rows)
							ereport(ERROR,
									(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
									 errmsg("FETCH statement cannot return multiple rows"),
									 parser_errposition((yylsp[-3]))));

						fetch->lineno = plpgsql_location_to_lineno((yylsp[-3]));
						fetch->target	= target;
						fetch->curvar	= (yyvsp[-1].var)->dno;
						fetch->is_move	= false;

						(yyval.stmt) = (PLpgSQL_stmt *)fetch;
					}
#line 4162 "pl_gram.c"
    break;

  case 136: /* stmt_move: K_MOVE opt_fetch_direction cursor_variable ';'  */
#line 2199 "pl_gram.y"
                                        {
						PLpgSQL_stmt_fetch *fetch = (yyvsp[-2].fetch);

						fetch->lineno = plpgsql_location_to_lineno((yylsp[-3]));
						fetch->curvar	= (yyvsp[-1].var)->dno;
						fetch->is_move	= true;

						(yyval.stmt) = (PLpgSQL_stmt *)fetch;
					}
#line 4176 "pl_gram.c"
    break;

  case 137: /* opt_fetch_direction: %empty  */
#line 2211 "pl_gram.y"
                                        {
						(yyval.fetch) = read_fetch_direction();
					}
#line 4184 "pl_gram.c"
    break;

  case 138: /* stmt_close: K_CLOSE cursor_variable ';'  */
#line 2217 "pl_gram.y"
                                        {
						PLpgSQL_stmt_close *new;

						new = palloc(sizeof(PLpgSQL_stmt_close));
						new->cmd_type = PLPGSQL_STMT_CLOSE;
						new->lineno = plpgsql_location_to_lineno((yylsp[-2]));
						new->stmtid = ++plpgsql_curr_compile->nstatements;
						new->curvar = (yyvsp[-1].var)->dno;

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 4200 "pl_gram.c"
    break;

  case 139: /* stmt_null: K_NULL ';'  */
#line 2231 "pl_gram.y"
                                        {
						/* We do not bother building a node for NULL */
						(yyval.stmt) = NULL;
					}
#line 4209 "pl_gram.c"
    break;

  case 140: /* stmt_commit: K_COMMIT opt_transaction_chain ';'  */
#line 2238 "pl_gram.y"
                                        {
						PLpgSQL_stmt_commit *new;

						new = palloc(sizeof(PLpgSQL_stmt_commit));
						new->cmd_type = PLPGSQL_STMT_COMMIT;
						new->lineno = plpgsql_location_to_lineno((yylsp[-2]));
						new->stmtid = ++plpgsql_curr_compile->nstatements;
						new->chain = (yyvsp[-1].ival);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 4225 "pl_gram.c"
    break;

  case 141: /* stmt_rollback: K_ROLLBACK opt_transaction_chain ';'  */
#line 2252 "pl_gram.y"
                                        {
						PLpgSQL_stmt_rollback *new;

						new = palloc(sizeof(PLpgSQL_stmt_rollback));
						new->cmd_type = PLPGSQL_STMT_ROLLBACK;
						new->lineno = plpgsql_location_to_lineno((yylsp[-2]));
						new->stmtid = ++plpgsql_curr_compile->nstatements;
						new->chain = (yyvsp[-1].ival);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 4241 "pl_gram.c"
    break;

  case 142: /* opt_transaction_chain: K_AND K_CHAIN  */
#line 2266 "pl_gram.y"
                                                        { (yyval.ival) = true; }
#line 4247 "pl_gram.c"
    break;

  case 143: /* opt_transaction_chain: K_AND K_NO K_CHAIN  */
#line 2267 "pl_gram.y"
                                                { (yyval.ival) = false; }
#line 4253 "pl_gram.c"
    break;

  case 144: /* opt_transaction_chain: %empty  */
#line 2268 "pl_gram.y"
                                                        { (yyval.ival) = false; }
#line 4259 "pl_gram.c"
    break;

  case 145: /* cursor_variable: T_DATUM  */
#line 2273 "pl_gram.y"
                                        {
						/*
						 * In principle we should support a cursor_variable
						 * that is an array element, but for now we don't, so
						 * just throw an error if next token is '['.
						 */
						if ((yyvsp[0].wdatum).datum->dtype != PLPGSQL_DTYPE_VAR ||
							plpgsql_peek() == '[')
							ereport(ERROR,
									(errcode(ERRCODE_DATATYPE_MISMATCH),
									 errmsg("cursor variable must be a simple variable"),
									 parser_errposition((yylsp[0]))));

						if (((PLpgSQL_var *) (yyvsp[0].wdatum).datum)->datatype->typoid != REFCURSOROID)
							ereport(ERROR,
									(errcode(ERRCODE_DATATYPE_MISMATCH),
									 errmsg("variable \"%s\" must be of type cursor or refcursor",
											((PLpgSQL_var *) (yyvsp[0].wdatum).datum)->refname),
									 parser_errposition((yylsp[0]))));
						(yyval.var) = (PLpgSQL_var *) (yyvsp[0].wdatum).datum;
					}
#line 4285 "pl_gram.c"
    break;

  case 146: /* cursor_variable: T_WORD  */
#line 2295 "pl_gram.y"
                                        {
						/* just to give a better message than "syntax error" */
						word_is_not_variable(&((yyvsp[0].word)), (yylsp[0]));
					}
#line 4294 "pl_gram.c"
    break;

  case 147: /* cursor_variable: T_CWORD  */
#line 2300 "pl_gram.y"
                                        {
						/* just to give a better message than "syntax error" */
						cword_is_not_variable(&((yyvsp[0].cword)), (yylsp[0]));
					}
#line 4303 "pl_gram.c"
    break;

  case 148: /* exception_sect: %empty  */
#line 2307 "pl_gram.y"
                                        { (yyval.exception_block) = NULL; }
#line 4309 "pl_gram.c"
    break;

  case 149: /* @2: %empty  */
#line 2309 "pl_gram.y"
                                        {
						/*
						 * We use a mid-rule action to add these
						 * special variables to the namespace before
						 * parsing the WHEN clauses themselves.  The
						 * scope of the names extends to the end of the
						 * current block.
						 */
						int			lineno = plpgsql_location_to_lineno((yylsp[0]));
						PLpgSQL_exception_block *new = palloc(sizeof(PLpgSQL_exception_block));
						PLpgSQL_variable *var;

						var = plpgsql_build_variable("sqlstate", lineno,
													 plpgsql_build_datatype(TEXTOID,
																			-1,
																			plpgsql_curr_compile->fn_input_collation,
																			NULL),
													 true);
						var->isconst = true;
						new->sqlstate_varno = var->dno;

						var = plpgsql_build_variable("sqlerrm", lineno,
													 plpgsql_build_datatype(TEXTOID,
																			-1,
																			plpgsql_curr_compile->fn_input_collation,
																			NULL),
													 true);
						var->isconst = true;
						new->sqlerrm_varno = var->dno;

						(yyval.exception_block) = new;
					}
#line 4346 "pl_gram.c"
    break;

  case 150: /* exception_sect: K_EXCEPTION @2 proc_exceptions  */
#line 2342 "pl_gram.y"
                                        {
						PLpgSQL_exception_block *new = (yyvsp[-1].exception_block);
						new->exc_list = (yyvsp[0].list);

						(yyval.exception_block) = new;
					}
#line 4357 "pl_gram.c"
    break;

  case 151: /* proc_exceptions: proc_exceptions proc_exception  */
#line 2351 "pl_gram.y"
                                                {
							(yyval.list) = lappend((yyvsp[-1].list), (yyvsp[0].exception));
						}
#line 4365 "pl_gram.c"
    break;

  case 152: /* proc_exceptions: proc_exception  */
#line 2355 "pl_gram.y"
                                                {
							(yyval.list) = list_make1((yyvsp[0].exception));
						}
#line 4373 "pl_gram.c"
    break;

  case 153: /* proc_exception: K_WHEN proc_conditions K_THEN proc_sect  */
#line 2361 "pl_gram.y"
                                        {
						PLpgSQL_exception *new;

						new = palloc0(sizeof(PLpgSQL_exception));
						new->lineno = plpgsql_location_to_lineno((yylsp[-3]));
						new->conditions = (yyvsp[-2].condition);
						new->action = (yyvsp[0].list);

						(yyval.exception) = new;
					}
#line 4388 "pl_gram.c"
    break;

  case 154: /* proc_conditions: proc_conditions K_OR proc_condition  */
#line 2374 "pl_gram.y"
                                                {
							PLpgSQL_condition	*old;

							for (old = (yyvsp[-2].condition); old->next != NULL; old = old->next)
								/* skip */ ;
							old->next = (yyvsp[0].condition);
							(yyval.condition) = (yyvsp[-2].condition);
						}
#line 4401 "pl_gram.c"
    break;

  case 155: /* proc_conditions: proc_condition  */
#line 2383 "pl_gram.y"
                                                {
							(yyval.condition) = (yyvsp[0].condition);
						}
#line 4409 "pl_gram.c"
    break;

  case 156: /* proc_condition: any_identifier  */
#line 2389 "pl_gram.y"
                                                {
							if (strcmp((yyvsp[0].str), "sqlstate") != 0)
							{
								(yyval.condition) = plpgsql_parse_err_condition((yyvsp[0].str));
							}
							else
							{
								PLpgSQL_condition *new;
								char   *sqlstatestr;

								/* next token should be a string literal */
								if (yylex() != SCONST)
									yyerror("syntax error");
								sqlstatestr = yylval.str;

								if (strlen(sqlstatestr) != 5)
									yyerror("invalid SQLSTATE code");
								if (strspn(sqlstatestr, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ") != 5)
									yyerror("invalid SQLSTATE code");

								new = palloc(sizeof(PLpgSQL_condition));
								new->sqlerrstate =
									MAKE_SQLSTATE(sqlstatestr[0],
												  sqlstatestr[1],
												  sqlstatestr[2],
												  sqlstatestr[3],
												  sqlstatestr[4]);
								new->condname = sqlstatestr;
								new->next = NULL;

								(yyval.condition) = new;
							}
						}
#line 4447 "pl_gram.c"
    break;

  case 157: /* expr_until_semi: %empty  */
#line 2425 "pl_gram.y"
                                        { (yyval.expr) = read_sql_expression(';', ";"); }
#line 4453 "pl_gram.c"
    break;

  case 158: /* expr_until_then: %empty  */
#line 2429 "pl_gram.y"
                                        { (yyval.expr) = read_sql_expression(K_THEN, "THEN"); }
#line 4459 "pl_gram.c"
    break;

  case 159: /* expr_until_loop: %empty  */
#line 2433 "pl_gram.y"
                                        { (yyval.expr) = read_sql_expression(K_LOOP, "LOOP"); }
#line 4465 "pl_gram.c"
    break;

  case 160: /* opt_block_label: %empty  */
#line 2437 "pl_gram.y"
                                        {
						plpgsql_ns_push(NULL, PLPGSQL_LABEL_BLOCK);
						(yyval.str) = NULL;
					}
#line 4474 "pl_gram.c"
    break;

  case 161: /* opt_block_label: LESS_LESS any_identifier GREATER_GREATER  */
#line 2442 "pl_gram.y"
                                        {
						plpgsql_ns_push((yyvsp[-1].str), PLPGSQL_LABEL_BLOCK);
						(yyval.str) = (yyvsp[-1].str);
					}
#line 4483 "pl_gram.c"
    break;

  case 162: /* opt_loop_label: %empty  */
#line 2449 "pl_gram.y"
                                        {
						plpgsql_ns_push(NULL, PLPGSQL_LABEL_LOOP);
						(yyval.str) = NULL;
					}
#line 4492 "pl_gram.c"
    break;

  case 163: /* opt_loop_label: LESS_LESS any_identifier GREATER_GREATER  */
#line 2454 "pl_gram.y"
                                        {
						plpgsql_ns_push((yyvsp[-1].str), PLPGSQL_LABEL_LOOP);
						(yyval.str) = (yyvsp[-1].str);
					}
#line 4501 "pl_gram.c"
    break;

  case 164: /* opt_label: %empty  */
#line 2461 "pl_gram.y"
                                        {
						(yyval.str) = NULL;
					}
#line 4509 "pl_gram.c"
    break;

  case 165: /* opt_label: any_identifier  */
#line 2465 "pl_gram.y"
                                        {
						/* label validity will be checked by outer production */
						(yyval.str) = (yyvsp[0].str);
					}
#line 4518 "pl_gram.c"
    break;

  case 166: /* opt_exitcond: ';'  */
#line 2472 "pl_gram.y"
                                        { (yyval.expr) = NULL; }
#line 4524 "pl_gram.c"
    break;

  case 167: /* opt_exitcond: K_WHEN expr_until_semi  */
#line 2474 "pl_gram.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 4530 "pl_gram.c"
    break;

  case 168: /* any_identifier: T_WORD  */
#line 2481 "pl_gram.y"
                                        {
						(yyval.str) = (yyvsp[0].word).ident;
					}
#line 4538 "pl_gram.c"
    break;

  case 169: /* any_identifier: unreserved_keyword  */
#line 2485 "pl_gram.y"
                                        {
						(yyval.str) = pstrdup((yyvsp[0].keyword));
					}
#line 4546 "pl_gram.c"
    break;

  case 170: /* any_identifier: T_DATUM  */
#line 2489 "pl_gram.y"
                                        {
						if ((yyvsp[0].wdatum).ident == NULL) /* composite name not OK */
							yyerror("syntax error");
						(yyval.str) = (yyvsp[0].wdatum).ident;
					}
#line 4556 "pl_gram.c"
    break;


#line 4560 "pl_gram.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 2579 "pl_gram.y"


/*
 * Check whether a token represents an "unreserved keyword".
 * We have various places where we want to recognize a keyword in preference
 * to a variable name, but not reserve that keyword in other contexts.
 * Hence, this kluge.
 */
static bool
tok_is_keyword(int token, union YYSTYPE *lval,
			   int kw_token, const char *kw_str)
{
	if (token == kw_token)
	{
		/* Normal case, was recognized by scanner (no conflicting variable) */
		return true;
	}
	else if (token == T_DATUM)
	{
		/*
		 * It's a variable, so recheck the string name.  Note we will not
		 * match composite names (hence an unreserved word followed by "."
		 * will not be recognized).
		 */
		if (!lval->wdatum.quoted && lval->wdatum.ident != NULL &&
			strcmp(lval->wdatum.ident, kw_str) == 0)
			return true;
	}
	return false;				/* not the keyword */
}

/*
 * Convenience routine to complain when we expected T_DATUM and got T_WORD,
 * ie, unrecognized variable.
 */
static void
word_is_not_variable(PLword *word, int location)
{
	ereport(ERROR,
			(errcode(ERRCODE_SYNTAX_ERROR),
			 errmsg("\"%s\" is not a known variable",
					word->ident),
			 parser_errposition(location)));
}

/* Same, for a CWORD */
static void
cword_is_not_variable(PLcword *cword, int location)
{
	ereport(ERROR,
			(errcode(ERRCODE_SYNTAX_ERROR),
			 errmsg("\"%s\" is not a known variable",
					NameListToString(cword->idents)),
			 parser_errposition(location)));
}

/*
 * Convenience routine to complain when we expected T_DATUM and got
 * something else.  "tok" must be the current token, since we also
 * look at yylval and yylloc.
 */
static void
current_token_is_not_variable(int tok)
{
	if (tok == T_WORD)
		word_is_not_variable(&(yylval.word), yylloc);
	else if (tok == T_CWORD)
		cword_is_not_variable(&(yylval.cword), yylloc);
	else
		yyerror("syntax error");
}

/* Convenience routine to read an expression with one possible terminator */
static PLpgSQL_expr *
read_sql_expression(int until, const char *expected)
{
	return read_sql_construct(until, 0, 0, expected,
							  RAW_PARSE_PLPGSQL_EXPR,
							  true, true, NULL, NULL);
}

/* Convenience routine to read an expression with two possible terminators */
static PLpgSQL_expr *
read_sql_expression2(int until, int until2, const char *expected,
					 int *endtoken)
{
	return read_sql_construct(until, until2, 0, expected,
							  RAW_PARSE_PLPGSQL_EXPR,
							  true, true, NULL, endtoken);
}

/* Convenience routine to read a SQL statement that must end with ';' */
static PLpgSQL_expr *
read_sql_stmt(void)
{
	return read_sql_construct(';', 0, 0, ";",
							  RAW_PARSE_DEFAULT,
							  false, true, NULL, NULL);
}

/*
 * Read a SQL construct and build a PLpgSQL_expr for it.
 *
 * until:		token code for expected terminator
 * until2:		token code for alternate terminator (pass 0 if none)
 * until3:		token code for another alternate terminator (pass 0 if none)
 * expected:	text to use in complaining that terminator was not found
 * parsemode:	raw_parser() mode to use
 * isexpression: whether to say we're reading an "expression" or a "statement"
 * valid_sql:   whether to check the syntax of the expr
 * startloc:	if not NULL, location of first token is stored at *startloc
 * endtoken:	if not NULL, ending token is stored at *endtoken
 *				(this is only interesting if until2 or until3 isn't zero)
 */
static PLpgSQL_expr *
read_sql_construct(int until,
				   int until2,
				   int until3,
				   const char *expected,
				   RawParseMode parsemode,
				   bool isexpression,
				   bool valid_sql,
				   int *startloc,
				   int *endtoken)
{
	int					tok;
	StringInfoData		ds;
	IdentifierLookup	save_IdentifierLookup;
	int					startlocation = -1;
	int					endlocation = -1;
	int					parenlevel = 0;
	PLpgSQL_expr		*expr;

	initStringInfo(&ds);

	/* special lookup mode for identifiers within the SQL text */
	save_IdentifierLookup = plpgsql_IdentifierLookup;
	plpgsql_IdentifierLookup = IDENTIFIER_LOOKUP_EXPR;

	for (;;)
	{
		tok = yylex();
		if (startlocation < 0)			/* remember loc of first token */
			startlocation = yylloc;
		if (tok == until && parenlevel == 0)
			break;
		if (tok == until2 && parenlevel == 0)
			break;
		if (tok == until3 && parenlevel == 0)
			break;
		if (tok == '(' || tok == '[')
			parenlevel++;
		else if (tok == ')' || tok == ']')
		{
			parenlevel--;
			if (parenlevel < 0)
				yyerror("mismatched parentheses");
		}
		/*
		 * End of function definition is an error, and we don't expect to
		 * hit a semicolon either (unless it's the until symbol, in which
		 * case we should have fallen out above).
		 */
		if (tok == 0 || tok == ';')
		{
			if (parenlevel != 0)
				yyerror("mismatched parentheses");
			if (isexpression)
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("missing \"%s\" at end of SQL expression",
								expected),
						 parser_errposition(yylloc)));
			else
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("missing \"%s\" at end of SQL statement",
								expected),
						 parser_errposition(yylloc)));
		}
		/* Remember end+1 location of last accepted token */
		endlocation = yylloc + plpgsql_token_length();
	}

	plpgsql_IdentifierLookup = save_IdentifierLookup;

	if (startloc)
		*startloc = startlocation;
	if (endtoken)
		*endtoken = tok;

	/* give helpful complaint about empty input */
	if (startlocation >= endlocation)
	{
		if (isexpression)
			yyerror("missing expression");
		else
			yyerror("missing SQL statement");
	}

	/*
	 * We save only the text from startlocation to endlocation-1.  This
	 * suppresses the "until" token as well as any whitespace or comments
	 * following the last accepted token.  (We used to strip such trailing
	 * whitespace by hand, but that causes problems if there's a "-- comment"
	 * in front of said whitespace.)
	 */
	plpgsql_append_source_text(&ds, startlocation, endlocation);

	expr = palloc0(sizeof(PLpgSQL_expr));
	expr->query			= pstrdup(ds.data);
	expr->parseMode		= parsemode;
	expr->plan			= NULL;
	expr->paramnos		= NULL;
	expr->target_param	= -1;
	expr->ns			= plpgsql_ns_top();
	pfree(ds.data);

	if (valid_sql)
		check_sql_expr(expr->query, expr->parseMode, startlocation);

	return expr;
}

static PLpgSQL_type *
read_datatype(int tok)
{
	StringInfoData		ds;
	char			   *type_name;
	int					startlocation;
	PLpgSQL_type		*result;
	int					parenlevel = 0;

	/* Should only be called while parsing DECLARE sections */
	Assert(plpgsql_IdentifierLookup == IDENTIFIER_LOOKUP_DECLARE);

	/* Often there will be a lookahead token, but if not, get one */
	if (tok == YYEMPTY)
		tok = yylex();

	startlocation = yylloc;

	/*
	 * If we have a simple or composite identifier, check for %TYPE
	 * and %ROWTYPE constructs.
	 */
	if (tok == T_WORD)
	{
		char   *dtname = yylval.word.ident;

		tok = yylex();
		if (tok == '%')
		{
			tok = yylex();
			if (tok_is_keyword(tok, &yylval,
							   K_TYPE, "type"))
			{
				result = plpgsql_parse_wordtype(dtname);
				if (result)
					return result;
			}
			else if (tok_is_keyword(tok, &yylval,
									K_ROWTYPE, "rowtype"))
			{
				result = plpgsql_parse_wordrowtype(dtname);
				if (result)
					return result;
			}
		}
	}
	else if (plpgsql_token_is_unreserved_keyword(tok))
	{
		char   *dtname = pstrdup(yylval.keyword);

		tok = yylex();
		if (tok == '%')
		{
			tok = yylex();
			if (tok_is_keyword(tok, &yylval,
							   K_TYPE, "type"))
			{
				result = plpgsql_parse_wordtype(dtname);
				if (result)
					return result;
			}
			else if (tok_is_keyword(tok, &yylval,
									K_ROWTYPE, "rowtype"))
			{
				result = plpgsql_parse_wordrowtype(dtname);
				if (result)
					return result;
			}
		}
	}
	else if (tok == T_CWORD)
	{
		List   *dtnames = yylval.cword.idents;

		tok = yylex();
		if (tok == '%')
		{
			tok = yylex();
			if (tok_is_keyword(tok, &yylval,
							   K_TYPE, "type"))
			{
				result = plpgsql_parse_cwordtype(dtnames);
				if (result)
					return result;
			}
			else if (tok_is_keyword(tok, &yylval,
									K_ROWTYPE, "rowtype"))
			{
				result = plpgsql_parse_cwordrowtype(dtnames);
				if (result)
					return result;
			}
		}
	}

	while (tok != ';')
	{
		if (tok == 0)
		{
			if (parenlevel != 0)
				yyerror("mismatched parentheses");
			else
				yyerror("incomplete data type declaration");
		}
		/* Possible followers for datatype in a declaration */
		if (tok == K_COLLATE || tok == K_NOT ||
			tok == '=' || tok == COLON_EQUALS || tok == K_DEFAULT)
			break;
		/* Possible followers for datatype in a cursor_arg list */
		if ((tok == ',' || tok == ')') && parenlevel == 0)
			break;
		if (tok == '(')
			parenlevel++;
		else if (tok == ')')
			parenlevel--;

		tok = yylex();
	}

	/* set up ds to contain complete typename text */
	initStringInfo(&ds);
	plpgsql_append_source_text(&ds, startlocation, yylloc);
	type_name = ds.data;

	if (type_name[0] == '\0')
		yyerror("missing data type declaration");

	result = parse_datatype(type_name, startlocation);

	pfree(ds.data);

	plpgsql_push_back_token(tok);

	return result;
}

/*
 * Read a generic SQL statement.  We have already read its first token;
 * firsttoken is that token's code and location its starting location.
 * If firsttoken == T_WORD, pass its yylval value as "word", else pass NULL.
 */
static PLpgSQL_stmt *
make_execsql_stmt(int firsttoken, int location, PLword *word)
{
	StringInfoData		ds;
	IdentifierLookup	save_IdentifierLookup;
	PLpgSQL_stmt_execsql *execsql;
	PLpgSQL_expr		*expr;
	PLpgSQL_variable	*target = NULL;
	int					tok;
	int					prev_tok;
	bool				have_into = false;
	bool				have_strict = false;
	int					into_start_loc = -1;
	int					into_end_loc = -1;
	int			paren_depth = 0;
	int			begin_depth = 0;
	bool		in_routine_definition = false;
	int			token_count = 0;
	char		tokens[4];		/* records the first few tokens */

	initStringInfo(&ds);

	memset(tokens, 0, sizeof(tokens));

	/* special lookup mode for identifiers within the SQL text */
	save_IdentifierLookup = plpgsql_IdentifierLookup;
	plpgsql_IdentifierLookup = IDENTIFIER_LOOKUP_EXPR;

	/*
	 * Scan to the end of the SQL command.  Identify any INTO-variables
	 * clause lurking within it, and parse that via read_into_target().
	 *
	 * The end of the statement is defined by a semicolon ... except that
	 * semicolons within parentheses or BEGIN/END blocks don't terminate a
	 * statement.  We follow psql's lead in not recognizing BEGIN/END except
	 * after CREATE [OR REPLACE] {FUNCTION|PROCEDURE}.  END can also appear
	 * within a CASE construct, so we treat CASE/END like BEGIN/END.
	 *
	 * Because INTO is sometimes used in the main SQL grammar, we have to be
	 * careful not to take any such usage of INTO as a PL/pgSQL INTO clause.
	 * There are currently three such cases:
	 *
	 * 1. SELECT ... INTO.  We don't care, we just override that with the
	 * PL/pgSQL definition.
	 *
	 * 2. INSERT INTO.  This is relatively easy to recognize since the words
	 * must appear adjacently; but we can't assume INSERT starts the command,
	 * because it can appear in CREATE RULE or WITH.  Unfortunately, INSERT is
	 * *not* fully reserved, so that means there is a chance of a false match;
	 * but it's not very likely.
	 *
	 * 3. IMPORT FOREIGN SCHEMA ... INTO.  This is not allowed in CREATE RULE
	 * or WITH, so we just check for IMPORT as the command's first token.
	 * (If IMPORT FOREIGN SCHEMA returned data someone might wish to capture
	 * with an INTO-variables clause, we'd have to work much harder here.)
	 *
	 * Fortunately, INTO is a fully reserved word in the main grammar, so
	 * at least we need not worry about it appearing as an identifier.
	 *
	 * Any future additional uses of INTO in the main grammar will doubtless
	 * break this logic again ... beware!
	 */
	tok = firsttoken;
	if (tok == T_WORD && strcmp(word->ident, "create") == 0)
		tokens[token_count] = 'c';
	token_count++;

	for (;;)
	{
		prev_tok = tok;
		tok = yylex();
		if (have_into && into_end_loc < 0)
			into_end_loc = yylloc;		/* token after the INTO part */
		/* Detect CREATE [OR REPLACE] {FUNCTION|PROCEDURE} */
		if (tokens[0] == 'c' && token_count < sizeof(tokens))
		{
			if (tok == K_OR)
				tokens[token_count] = 'o';
			else if (tok == T_WORD &&
					 strcmp(yylval.word.ident, "replace") == 0)
				tokens[token_count] = 'r';
			else if (tok == T_WORD &&
					 strcmp(yylval.word.ident, "function") == 0)
				tokens[token_count] = 'f';
			else if (tok == T_WORD &&
					 strcmp(yylval.word.ident, "procedure") == 0)
				tokens[token_count] = 'f';	/* treat same as "function" */
			if (tokens[1] == 'f' ||
				(tokens[1] == 'o' && tokens[2] == 'r' && tokens[3] == 'f'))
				in_routine_definition = true;
			token_count++;
		}
		/* Track paren nesting (needed for CREATE RULE syntax) */
		if (tok == '(')
			paren_depth++;
		else if (tok == ')' && paren_depth > 0)
			paren_depth--;
		/* We need track BEGIN/END nesting only in a routine definition */
		if (in_routine_definition && paren_depth == 0)
		{
			if (tok == K_BEGIN || tok == K_CASE)
				begin_depth++;
			else if (tok == K_END && begin_depth > 0)
				begin_depth--;
		}
		/* Command-ending semicolon? */
		if (tok == ';' && paren_depth == 0 && begin_depth == 0)
			break;
		if (tok == 0)
			yyerror("unexpected end of function definition");
		if (tok == K_INTO)
		{
			if (prev_tok == K_INSERT)
				continue;		/* INSERT INTO is not an INTO-target */
			if (firsttoken == K_IMPORT)
				continue;		/* IMPORT ... INTO is not an INTO-target */
			if (have_into)
				yyerror("INTO specified more than once");
			have_into = true;
			into_start_loc = yylloc;
			plpgsql_IdentifierLookup = IDENTIFIER_LOOKUP_NORMAL;
			read_into_target(&target, &have_strict);
			plpgsql_IdentifierLookup = IDENTIFIER_LOOKUP_EXPR;
		}
	}

	plpgsql_IdentifierLookup = save_IdentifierLookup;

	if (have_into)
	{
		/*
		 * Insert an appropriate number of spaces corresponding to the
		 * INTO text, so that locations within the redacted SQL statement
		 * still line up with those in the original source text.
		 */
		plpgsql_append_source_text(&ds, location, into_start_loc);
		appendStringInfoSpaces(&ds, into_end_loc - into_start_loc);
		plpgsql_append_source_text(&ds, into_end_loc, yylloc);
	}
	else
		plpgsql_append_source_text(&ds, location, yylloc);

	/* trim any trailing whitespace, for neatness */
	while (ds.len > 0 && scanner_isspace(ds.data[ds.len - 1]))
		ds.data[--ds.len] = '\0';

	expr = palloc0(sizeof(PLpgSQL_expr));
	expr->query			= pstrdup(ds.data);
	expr->parseMode		= RAW_PARSE_DEFAULT;
	expr->plan			= NULL;
	expr->paramnos		= NULL;
	expr->target_param	= -1;
	expr->ns			= plpgsql_ns_top();
	pfree(ds.data);

	check_sql_expr(expr->query, expr->parseMode, location);

	execsql = palloc0(sizeof(PLpgSQL_stmt_execsql));
	execsql->cmd_type = PLPGSQL_STMT_EXECSQL;
	execsql->lineno  = plpgsql_location_to_lineno(location);
	execsql->stmtid  = ++plpgsql_curr_compile->nstatements;
	execsql->sqlstmt = expr;
	execsql->into	 = have_into;
	execsql->strict	 = have_strict;
	execsql->target	 = target;

	return (PLpgSQL_stmt *) execsql;
}


/*
 * Read FETCH or MOVE direction clause (everything through FROM/IN).
 */
static PLpgSQL_stmt_fetch *
read_fetch_direction(void)
{
	PLpgSQL_stmt_fetch *fetch;
	int			tok;
	bool		check_FROM = true;

	/*
	 * We create the PLpgSQL_stmt_fetch struct here, but only fill in
	 * the fields arising from the optional direction clause
	 */
	fetch = (PLpgSQL_stmt_fetch *) palloc0(sizeof(PLpgSQL_stmt_fetch));
	fetch->cmd_type = PLPGSQL_STMT_FETCH;
	fetch->stmtid	= ++plpgsql_curr_compile->nstatements;
	/* set direction defaults: */
	fetch->direction = FETCH_FORWARD;
	fetch->how_many  = 1;
	fetch->expr		 = NULL;
	fetch->returns_multiple_rows = false;

	tok = yylex();
	if (tok == 0)
		yyerror("unexpected end of function definition");

	if (tok_is_keyword(tok, &yylval,
					   K_NEXT, "next"))
	{
		/* use defaults */
	}
	else if (tok_is_keyword(tok, &yylval,
							K_PRIOR, "prior"))
	{
		fetch->direction = FETCH_BACKWARD;
	}
	else if (tok_is_keyword(tok, &yylval,
							K_FIRST, "first"))
	{
		fetch->direction = FETCH_ABSOLUTE;
	}
	else if (tok_is_keyword(tok, &yylval,
							K_LAST, "last"))
	{
		fetch->direction = FETCH_ABSOLUTE;
		fetch->how_many  = -1;
	}
	else if (tok_is_keyword(tok, &yylval,
							K_ABSOLUTE, "absolute"))
	{
		fetch->direction = FETCH_ABSOLUTE;
		fetch->expr = read_sql_expression2(K_FROM, K_IN,
										   "FROM or IN",
										   NULL);
		check_FROM = false;
	}
	else if (tok_is_keyword(tok, &yylval,
							K_RELATIVE, "relative"))
	{
		fetch->direction = FETCH_RELATIVE;
		fetch->expr = read_sql_expression2(K_FROM, K_IN,
										   "FROM or IN",
										   NULL);
		check_FROM = false;
	}
	else if (tok_is_keyword(tok, &yylval,
							K_ALL, "all"))
	{
		fetch->how_many = FETCH_ALL;
		fetch->returns_multiple_rows = true;
	}
	else if (tok_is_keyword(tok, &yylval,
							K_FORWARD, "forward"))
	{
		complete_direction(fetch, &check_FROM);
	}
	else if (tok_is_keyword(tok, &yylval,
							K_BACKWARD, "backward"))
	{
		fetch->direction = FETCH_BACKWARD;
		complete_direction(fetch, &check_FROM);
	}
	else if (tok == K_FROM || tok == K_IN)
	{
		/* empty direction */
		check_FROM = false;
	}
	else if (tok == T_DATUM)
	{
		/* Assume there's no direction clause and tok is a cursor name */
		plpgsql_push_back_token(tok);
		check_FROM = false;
	}
	else
	{
		/*
		 * Assume it's a count expression with no preceding keyword.
		 * Note: we allow this syntax because core SQL does, but it's
		 * ambiguous with the case of an omitted direction clause; for
		 * instance, "MOVE n IN c" will fail if n is a variable, because the
		 * preceding else-arm will trigger.  Perhaps this can be improved
		 * someday, but it hardly seems worth a lot of work.
		 */
		plpgsql_push_back_token(tok);
		fetch->expr = read_sql_expression2(K_FROM, K_IN,
										   "FROM or IN",
										   NULL);
		fetch->returns_multiple_rows = true;
		check_FROM = false;
	}

	/* check FROM or IN keyword after direction's specification */
	if (check_FROM)
	{
		tok = yylex();
		if (tok != K_FROM && tok != K_IN)
			yyerror("expected FROM or IN");
	}

	return fetch;
}

/*
 * Process remainder of FETCH/MOVE direction after FORWARD or BACKWARD.
 * Allows these cases:
 *   FORWARD expr,  FORWARD ALL,  FORWARD
 *   BACKWARD expr, BACKWARD ALL, BACKWARD
 */
static void
complete_direction(PLpgSQL_stmt_fetch *fetch,  bool *check_FROM)
{
	int			tok;

	tok = yylex();
	if (tok == 0)
		yyerror("unexpected end of function definition");

	if (tok == K_FROM || tok == K_IN)
	{
		*check_FROM = false;
		return;
	}

	if (tok == K_ALL)
	{
		fetch->how_many = FETCH_ALL;
		fetch->returns_multiple_rows = true;
		*check_FROM = true;
		return;
	}

	plpgsql_push_back_token(tok);
	fetch->expr = read_sql_expression2(K_FROM, K_IN,
									   "FROM or IN",
									   NULL);
	fetch->returns_multiple_rows = true;
	*check_FROM = false;
}


static PLpgSQL_stmt *
make_return_stmt(int location)
{
	PLpgSQL_stmt_return *new;

	new = palloc0(sizeof(PLpgSQL_stmt_return));
	new->cmd_type = PLPGSQL_STMT_RETURN;
	new->lineno   = plpgsql_location_to_lineno(location);
	new->stmtid	  = ++plpgsql_curr_compile->nstatements;
	new->expr	  = NULL;
	new->retvarno = -1;

	if (plpgsql_curr_compile->fn_retset)
	{
		if (yylex() != ';')
			ereport(ERROR,
					(errcode(ERRCODE_DATATYPE_MISMATCH),
					 errmsg("RETURN cannot have a parameter in function returning set"),
					 errhint("Use RETURN NEXT or RETURN QUERY."),
					 parser_errposition(yylloc)));
	}
	else if (plpgsql_curr_compile->fn_rettype == VOIDOID)
	{
		if (yylex() != ';')
		{
			if (plpgsql_curr_compile->fn_prokind == PROKIND_PROCEDURE)
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("RETURN cannot have a parameter in a procedure"),
						 parser_errposition(yylloc)));
			else
				ereport(ERROR,
						(errcode(ERRCODE_DATATYPE_MISMATCH),
						 errmsg("RETURN cannot have a parameter in function returning void"),
						 parser_errposition(yylloc)));
		}
	}
	else if (plpgsql_curr_compile->out_param_varno >= 0)
	{
		if (yylex() != ';')
			ereport(ERROR,
					(errcode(ERRCODE_DATATYPE_MISMATCH),
					 errmsg("RETURN cannot have a parameter in function with OUT parameters"),
					 parser_errposition(yylloc)));
		new->retvarno = plpgsql_curr_compile->out_param_varno;
	}
	else
	{
		/*
		 * We want to special-case simple variable references for efficiency.
		 * So peek ahead to see if that's what we have.
		 */
		int		tok = yylex();

		if (tok == T_DATUM && plpgsql_peek() == ';' &&
			(yylval.wdatum.datum->dtype == PLPGSQL_DTYPE_VAR ||
			 yylval.wdatum.datum->dtype == PLPGSQL_DTYPE_PROMISE ||
			 yylval.wdatum.datum->dtype == PLPGSQL_DTYPE_ROW ||
			 yylval.wdatum.datum->dtype == PLPGSQL_DTYPE_REC))
		{
			new->retvarno = yylval.wdatum.datum->dno;
			/* eat the semicolon token that we only peeked at above */
			tok = yylex();
			Assert(tok == ';');
		}
		else
		{
			/*
			 * Not (just) a variable name, so treat as expression.
			 *
			 * Note that a well-formed expression is _required_ here;
			 * anything else is a compile-time error.
			 */
			plpgsql_push_back_token(tok);
			new->expr = read_sql_expression(';', ";");
		}
	}

	return (PLpgSQL_stmt *) new;
}


static PLpgSQL_stmt *
make_return_next_stmt(int location)
{
	PLpgSQL_stmt_return_next *new;

	if (!plpgsql_curr_compile->fn_retset)
		ereport(ERROR,
				(errcode(ERRCODE_DATATYPE_MISMATCH),
				 errmsg("cannot use RETURN NEXT in a non-SETOF function"),
				 parser_errposition(location)));

	new = palloc0(sizeof(PLpgSQL_stmt_return_next));
	new->cmd_type	= PLPGSQL_STMT_RETURN_NEXT;
	new->lineno		= plpgsql_location_to_lineno(location);
	new->stmtid		= ++plpgsql_curr_compile->nstatements;
	new->expr		= NULL;
	new->retvarno	= -1;

	if (plpgsql_curr_compile->out_param_varno >= 0)
	{
		if (yylex() != ';')
			ereport(ERROR,
					(errcode(ERRCODE_DATATYPE_MISMATCH),
					 errmsg("RETURN NEXT cannot have a parameter in function with OUT parameters"),
					 parser_errposition(yylloc)));
		new->retvarno = plpgsql_curr_compile->out_param_varno;
	}
	else
	{
		/*
		 * We want to special-case simple variable references for efficiency.
		 * So peek ahead to see if that's what we have.
		 */
		int		tok = yylex();

		if (tok == T_DATUM && plpgsql_peek() == ';' &&
			(yylval.wdatum.datum->dtype == PLPGSQL_DTYPE_VAR ||
			 yylval.wdatum.datum->dtype == PLPGSQL_DTYPE_PROMISE ||
			 yylval.wdatum.datum->dtype == PLPGSQL_DTYPE_ROW ||
			 yylval.wdatum.datum->dtype == PLPGSQL_DTYPE_REC))
		{
			new->retvarno = yylval.wdatum.datum->dno;
			/* eat the semicolon token that we only peeked at above */
			tok = yylex();
			Assert(tok == ';');
		}
		else
		{
			/*
			 * Not (just) a variable name, so treat as expression.
			 *
			 * Note that a well-formed expression is _required_ here;
			 * anything else is a compile-time error.
			 */
			plpgsql_push_back_token(tok);
			new->expr = read_sql_expression(';', ";");
		}
	}

	return (PLpgSQL_stmt *) new;
}


static PLpgSQL_stmt *
make_return_query_stmt(int location)
{
	PLpgSQL_stmt_return_query *new;
	int			tok;

	if (!plpgsql_curr_compile->fn_retset)
		ereport(ERROR,
				(errcode(ERRCODE_DATATYPE_MISMATCH),
				 errmsg("cannot use RETURN QUERY in a non-SETOF function"),
				 parser_errposition(location)));

	new = palloc0(sizeof(PLpgSQL_stmt_return_query));
	new->cmd_type = PLPGSQL_STMT_RETURN_QUERY;
	new->lineno = plpgsql_location_to_lineno(location);
	new->stmtid = ++plpgsql_curr_compile->nstatements;

	/* check for RETURN QUERY EXECUTE */
	if ((tok = yylex()) != K_EXECUTE)
	{
		/* ordinary static query */
		plpgsql_push_back_token(tok);
		new->query = read_sql_stmt();
	}
	else
	{
		/* dynamic SQL */
		int		term;

		new->dynquery = read_sql_expression2(';', K_USING, "; or USING",
											 &term);
		if (term == K_USING)
		{
			do
			{
				PLpgSQL_expr *expr;

				expr = read_sql_expression2(',', ';', ", or ;", &term);
				new->params = lappend(new->params, expr);
			} while (term == ',');
		}
	}

	return (PLpgSQL_stmt *) new;
}


/* convenience routine to fetch the name of a T_DATUM */
static char *
NameOfDatum(PLwdatum *wdatum)
{
	if (wdatum->ident)
		return wdatum->ident;
	Assert(wdatum->idents != NIL);
	return NameListToString(wdatum->idents);
}

static void
check_assignable(PLpgSQL_datum *datum, int location)
{
	switch (datum->dtype)
	{
		case PLPGSQL_DTYPE_VAR:
		case PLPGSQL_DTYPE_PROMISE:
		case PLPGSQL_DTYPE_REC:
			if (((PLpgSQL_variable *) datum)->isconst)
				ereport(ERROR,
						(errcode(ERRCODE_ERROR_IN_ASSIGNMENT),
						 errmsg("variable \"%s\" is declared CONSTANT",
								((PLpgSQL_variable *) datum)->refname),
						 parser_errposition(location)));
			break;
		case PLPGSQL_DTYPE_ROW:
			/* always assignable; member vars were checked at compile time */
			break;
		case PLPGSQL_DTYPE_RECFIELD:
			/* assignable if parent record is */
			check_assignable(plpgsql_Datums[((PLpgSQL_recfield *) datum)->recparentno],
							 location);
			break;
		default:
			elog(ERROR, "unrecognized dtype: %d", datum->dtype);
			break;
	}
}

/*
 * Read the argument of an INTO clause.  On entry, we have just read the
 * INTO keyword.
 */
static void
read_into_target(PLpgSQL_variable **target, bool *strict)
{
	int			tok;

	/* Set default results */
	*target = NULL;
	if (strict)
		*strict = false;

	tok = yylex();
	if (strict && tok == K_STRICT)
	{
		*strict = true;
		tok = yylex();
	}

	/*
	 * Currently, a row or record variable can be the single INTO target,
	 * but not a member of a multi-target list.  So we throw error if there
	 * is a comma after it, because that probably means the user tried to
	 * write a multi-target list.  If this ever gets generalized, we should
	 * probably refactor read_into_scalar_list so it handles all cases.
	 */
	switch (tok)
	{
		case T_DATUM:
			if (yylval.wdatum.datum->dtype == PLPGSQL_DTYPE_ROW ||
				yylval.wdatum.datum->dtype == PLPGSQL_DTYPE_REC)
			{
				check_assignable(yylval.wdatum.datum, yylloc);
				*target = (PLpgSQL_variable *) yylval.wdatum.datum;

				if ((tok = yylex()) == ',')
					ereport(ERROR,
							(errcode(ERRCODE_SYNTAX_ERROR),
							 errmsg("record variable cannot be part of multiple-item INTO list"),
							 parser_errposition(yylloc)));
				plpgsql_push_back_token(tok);
			}
			else
			{
				*target = (PLpgSQL_variable *)
					read_into_scalar_list(NameOfDatum(&(yylval.wdatum)),
										  yylval.wdatum.datum, yylloc);
			}
			break;

		default:
			/* just to give a better message than "syntax error" */
			current_token_is_not_variable(tok);
	}
}

/*
 * Given the first datum and name in the INTO list, continue to read
 * comma-separated scalar variables until we run out. Then construct
 * and return a fake "row" variable that represents the list of
 * scalars.
 */
static PLpgSQL_row *
read_into_scalar_list(char *initial_name,
					  PLpgSQL_datum *initial_datum,
					  int initial_location)
{
	int				 nfields;
	char			*fieldnames[1024];
	int				 varnos[1024];
	PLpgSQL_row		*row;
	int				 tok;

	check_assignable(initial_datum, initial_location);
	fieldnames[0] = initial_name;
	varnos[0]	  = initial_datum->dno;
	nfields		  = 1;

	while ((tok = yylex()) == ',')
	{
		/* Check for array overflow */
		if (nfields >= 1024)
			ereport(ERROR,
					(errcode(ERRCODE_PROGRAM_LIMIT_EXCEEDED),
					 errmsg("too many INTO variables specified"),
					 parser_errposition(yylloc)));

		tok = yylex();
		switch (tok)
		{
			case T_DATUM:
				check_assignable(yylval.wdatum.datum, yylloc);
				if (yylval.wdatum.datum->dtype == PLPGSQL_DTYPE_ROW ||
					yylval.wdatum.datum->dtype == PLPGSQL_DTYPE_REC)
					ereport(ERROR,
							(errcode(ERRCODE_SYNTAX_ERROR),
							 errmsg("\"%s\" is not a scalar variable",
									NameOfDatum(&(yylval.wdatum))),
							 parser_errposition(yylloc)));
				fieldnames[nfields] = NameOfDatum(&(yylval.wdatum));
				varnos[nfields++]	= yylval.wdatum.datum->dno;
				break;

			default:
				/* just to give a better message than "syntax error" */
				current_token_is_not_variable(tok);
		}
	}

	/*
	 * We read an extra, non-comma token from yylex(), so push it
	 * back onto the input stream
	 */
	plpgsql_push_back_token(tok);

	row = palloc0(sizeof(PLpgSQL_row));
	row->dtype = PLPGSQL_DTYPE_ROW;
	row->refname = "(unnamed row)";
	row->lineno = plpgsql_location_to_lineno(initial_location);
	row->rowtupdesc = NULL;
	row->nfields = nfields;
	row->fieldnames = palloc(sizeof(char *) * nfields);
	row->varnos = palloc(sizeof(int) * nfields);
	while (--nfields >= 0)
	{
		row->fieldnames[nfields] = fieldnames[nfields];
		row->varnos[nfields] = varnos[nfields];
	}

	plpgsql_adddatum((PLpgSQL_datum *)row);

	return row;
}

/*
 * Convert a single scalar into a "row" list.  This is exactly
 * like read_into_scalar_list except we never consume any input.
 *
 * Note: lineno could be computed from location, but since callers
 * have it at hand already, we may as well pass it in.
 */
static PLpgSQL_row *
make_scalar_list1(char *initial_name,
				  PLpgSQL_datum *initial_datum,
				  int lineno, int location)
{
	PLpgSQL_row		*row;

	check_assignable(initial_datum, location);

	row = palloc0(sizeof(PLpgSQL_row));
	row->dtype = PLPGSQL_DTYPE_ROW;
	row->refname = "(unnamed row)";
	row->lineno = lineno;
	row->rowtupdesc = NULL;
	row->nfields = 1;
	row->fieldnames = palloc(sizeof(char *));
	row->varnos = palloc(sizeof(int));
	row->fieldnames[0] = initial_name;
	row->varnos[0] = initial_datum->dno;

	plpgsql_adddatum((PLpgSQL_datum *)row);

	return row;
}

/*
 * When the PL/pgSQL parser expects to see a SQL statement, it is very
 * liberal in what it accepts; for example, we often assume an
 * unrecognized keyword is the beginning of a SQL statement. This
 * avoids the need to duplicate parts of the SQL grammar in the
 * PL/pgSQL grammar, but it means we can accept wildly malformed
 * input. To try and catch some of the more obviously invalid input,
 * we run the strings we expect to be SQL statements through the main
 * SQL parser.
 *
 * We only invoke the raw parser (not the analyzer); this doesn't do
 * any database access and does not check any semantic rules, it just
 * checks for basic syntactic correctness. We do this here, rather
 * than after parsing has finished, because a malformed SQL statement
 * may cause the PL/pgSQL parser to become confused about statement
 * borders. So it is best to bail out as early as we can.
 *
 * It is assumed that "stmt" represents a copy of the function source text
 * beginning at offset "location".  We use this assumption to transpose
 * any error cursor position back to the function source text.
 * If no error cursor is provided, we'll just point at "location".
 */
static void
check_sql_expr(const char *stmt, RawParseMode parseMode, int location)
{
	sql_error_callback_arg cbarg;
	ErrorContextCallback  syntax_errcontext;
	MemoryContext oldCxt;

	if (!plpgsql_check_syntax)
		return;

	cbarg.location = location;

	syntax_errcontext.callback = plpgsql_sql_error_callback;
	syntax_errcontext.arg = &cbarg;
	syntax_errcontext.previous = error_context_stack;
	error_context_stack = &syntax_errcontext;

	oldCxt = MemoryContextSwitchTo(plpgsql_compile_tmp_cxt);
	(void) raw_parser(stmt, parseMode);
	MemoryContextSwitchTo(oldCxt);

	/* Restore former ereport callback */
	error_context_stack = syntax_errcontext.previous;
}

static void
plpgsql_sql_error_callback(void *arg)
{
	sql_error_callback_arg *cbarg = (sql_error_callback_arg *) arg;
	int			errpos;

	/*
	 * First, set up internalerrposition to point to the start of the
	 * statement text within the function text.  Note this converts
	 * location (a byte offset) to a character number.
	 */
	parser_errposition(cbarg->location);

	/*
	 * If the core parser provided an error position, transpose it.
	 * Note we are dealing with 1-based character numbers at this point.
	 */
	errpos = geterrposition();
	if (errpos > 0)
	{
		int		myerrpos = getinternalerrposition();

		if (myerrpos > 0)		/* safety check */
			internalerrposition(myerrpos + errpos - 1);
	}

	/* In any case, flush errposition --- we want internalerrposition only */
	errposition(0);
}

/*
 * Parse a SQL datatype name and produce a PLpgSQL_type structure.
 *
 * The heavy lifting is done elsewhere.  Here we are only concerned
 * with setting up an errcontext link that will let us give an error
 * cursor pointing into the plpgsql function source, if necessary.
 * This is handled the same as in check_sql_expr(), and we likewise
 * expect that the given string is a copy from the source text.
 */
static PLpgSQL_type *
parse_datatype(const char *string, int location)
{
	TypeName   *typeName;
	Oid			type_id;
	int32		typmod;
	sql_error_callback_arg cbarg;
	ErrorContextCallback  syntax_errcontext;

	cbarg.location = location;

	syntax_errcontext.callback = plpgsql_sql_error_callback;
	syntax_errcontext.arg = &cbarg;
	syntax_errcontext.previous = error_context_stack;
	error_context_stack = &syntax_errcontext;

	/* Let the main parser try to parse it under standard SQL rules */
	typeName = typeStringToTypeName(string);
	typenameTypeIdAndMod(NULL, typeName, &type_id, &typmod);

	/* Restore former ereport callback */
	error_context_stack = syntax_errcontext.previous;

	/* Okay, build a PLpgSQL_type data structure for it */
	return plpgsql_build_datatype(type_id, typmod,
								  plpgsql_curr_compile->fn_input_collation,
								  typeName);
}

/*
 * Check block starting and ending labels match.
 */
static void
check_labels(const char *start_label, const char *end_label, int end_location)
{
	if (end_label)
	{
		if (!start_label)
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("end label \"%s\" specified for unlabeled block",
							end_label),
					 parser_errposition(end_location)));

		if (strcmp(start_label, end_label) != 0)
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("end label \"%s\" differs from block's label \"%s\"",
							end_label, start_label),
					 parser_errposition(end_location)));
	}
}

/*
 * Read the arguments (if any) for a cursor, followed by the until token
 *
 * If cursor has no args, just swallow the until token and return NULL.
 * If it does have args, we expect to see "( arg [, arg ...] )" followed
 * by the until token, where arg may be a plain expression, or a named
 * parameter assignment of the form argname := expr. Consume all that and
 * return a SELECT query that evaluates the expression(s) (without the outer
 * parens).
 */
static PLpgSQL_expr *
read_cursor_args(PLpgSQL_var *cursor, int until)
{
	PLpgSQL_expr *expr;
	PLpgSQL_row *row;
	int			tok;
	int			argc;
	char	  **argv;
	StringInfoData ds;
	bool		any_named = false;

	tok = yylex();
	if (cursor->cursor_explicit_argrow < 0)
	{
		/* No arguments expected */
		if (tok == '(')
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("cursor \"%s\" has no arguments",
							cursor->refname),
					 parser_errposition(yylloc)));

		if (tok != until)
			yyerror("syntax error");

		return NULL;
	}

	/* Else better provide arguments */
	if (tok != '(')
		ereport(ERROR,
				(errcode(ERRCODE_SYNTAX_ERROR),
				 errmsg("cursor \"%s\" has arguments",
						cursor->refname),
				 parser_errposition(yylloc)));

	/*
	 * Read the arguments, one by one.
	 */
	row = (PLpgSQL_row *) plpgsql_Datums[cursor->cursor_explicit_argrow];
	argv = (char **) palloc0(row->nfields * sizeof(char *));

	for (argc = 0; argc < row->nfields; argc++)
	{
		PLpgSQL_expr *item;
		int		endtoken;
		int		argpos;
		int		tok1,
				tok2;
		int		arglocation;

		/* Check if it's a named parameter: "param := value" */
		plpgsql_peek2(&tok1, &tok2, &arglocation, NULL);
		if (tok1 == IDENT && tok2 == COLON_EQUALS)
		{
			char   *argname;
			IdentifierLookup save_IdentifierLookup;

			/* Read the argument name, ignoring any matching variable */
			save_IdentifierLookup = plpgsql_IdentifierLookup;
			plpgsql_IdentifierLookup = IDENTIFIER_LOOKUP_DECLARE;
			yylex();
			argname = yylval.str;
			plpgsql_IdentifierLookup = save_IdentifierLookup;

			/* Match argument name to cursor arguments */
			for (argpos = 0; argpos < row->nfields; argpos++)
			{
				if (strcmp(row->fieldnames[argpos], argname) == 0)
					break;
			}
			if (argpos == row->nfields)
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("cursor \"%s\" has no argument named \"%s\"",
								cursor->refname, argname),
						 parser_errposition(yylloc)));

			/*
			 * Eat the ":=". We already peeked, so the error should never
			 * happen.
			 */
			tok2 = yylex();
			if (tok2 != COLON_EQUALS)
				yyerror("syntax error");

			any_named = true;
		}
		else
			argpos = argc;

		if (argv[argpos] != NULL)
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("value for parameter \"%s\" of cursor \"%s\" specified more than once",
							row->fieldnames[argpos], cursor->refname),
					 parser_errposition(arglocation)));

		/*
		 * Read the value expression. To provide the user with meaningful
		 * parse error positions, we check the syntax immediately, instead of
		 * checking the final expression that may have the arguments
		 * reordered.
		 */
		item = read_sql_construct(',', ')', 0,
								  ",\" or \")",
								  RAW_PARSE_PLPGSQL_EXPR,
								  true, true,
								  NULL, &endtoken);

		argv[argpos] = item->query;

		if (endtoken == ')' && !(argc == row->nfields - 1))
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("not enough arguments for cursor \"%s\"",
							cursor->refname),
					 parser_errposition(yylloc)));

		if (endtoken == ',' && (argc == row->nfields - 1))
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("too many arguments for cursor \"%s\"",
							cursor->refname),
					 parser_errposition(yylloc)));
	}

	/* Make positional argument list */
	initStringInfo(&ds);
	for (argc = 0; argc < row->nfields; argc++)
	{
		Assert(argv[argc] != NULL);

		/*
		 * Because named notation allows permutated argument lists, include
		 * the parameter name for meaningful runtime errors.
		 */
		appendStringInfoString(&ds, argv[argc]);
		if (any_named)
			appendStringInfo(&ds, " AS %s",
							 quote_identifier(row->fieldnames[argc]));
		if (argc < row->nfields - 1)
			appendStringInfoString(&ds, ", ");
	}

	expr = palloc0(sizeof(PLpgSQL_expr));
	expr->query			= pstrdup(ds.data);
	expr->parseMode		= RAW_PARSE_PLPGSQL_EXPR;
	expr->plan			= NULL;
	expr->paramnos		= NULL;
	expr->target_param	= -1;
	expr->ns            = plpgsql_ns_top();
	pfree(ds.data);

	/* Next we'd better find the until token */
	tok = yylex();
	if (tok != until)
		yyerror("syntax error");

	return expr;
}

/*
 * Parse RAISE ... USING options
 */
static List *
read_raise_options(void)
{
	List	   *result = NIL;

	for (;;)
	{
		PLpgSQL_raise_option *opt;
		int		tok;

		if ((tok = yylex()) == 0)
			yyerror("unexpected end of function definition");

		opt = (PLpgSQL_raise_option *) palloc(sizeof(PLpgSQL_raise_option));

		if (tok_is_keyword(tok, &yylval,
						   K_ERRCODE, "errcode"))
			opt->opt_type = PLPGSQL_RAISEOPTION_ERRCODE;
		else if (tok_is_keyword(tok, &yylval,
								K_MESSAGE, "message"))
			opt->opt_type = PLPGSQL_RAISEOPTION_MESSAGE;
		else if (tok_is_keyword(tok, &yylval,
								K_DETAIL, "detail"))
			opt->opt_type = PLPGSQL_RAISEOPTION_DETAIL;
		else if (tok_is_keyword(tok, &yylval,
								K_HINT, "hint"))
			opt->opt_type = PLPGSQL_RAISEOPTION_HINT;
		else if (tok_is_keyword(tok, &yylval,
								K_COLUMN, "column"))
			opt->opt_type = PLPGSQL_RAISEOPTION_COLUMN;
		else if (tok_is_keyword(tok, &yylval,
								K_CONSTRAINT, "constraint"))
			opt->opt_type = PLPGSQL_RAISEOPTION_CONSTRAINT;
		else if (tok_is_keyword(tok, &yylval,
								K_DATATYPE, "datatype"))
			opt->opt_type = PLPGSQL_RAISEOPTION_DATATYPE;
		else if (tok_is_keyword(tok, &yylval,
								K_TABLE, "table"))
			opt->opt_type = PLPGSQL_RAISEOPTION_TABLE;
		else if (tok_is_keyword(tok, &yylval,
								K_SCHEMA, "schema"))
			opt->opt_type = PLPGSQL_RAISEOPTION_SCHEMA;
		else
			yyerror("unrecognized RAISE statement option");

		tok = yylex();
		if (tok != '=' && tok != COLON_EQUALS)
			yyerror("syntax error, expected \"=\"");

		opt->expr = read_sql_expression2(',', ';', ", or ;", &tok);

		result = lappend(result, opt);

		if (tok == ';')
			break;
	}

	return result;
}

/*
 * Check that the number of parameter placeholders in the message matches the
 * number of parameters passed to it, if a message was given.
 */
static void
check_raise_parameters(PLpgSQL_stmt_raise *stmt)
{
	char	   *cp;
	int			expected_nparams = 0;

	if (stmt->message == NULL)
		return;

	for (cp = stmt->message; *cp; cp++)
	{
		if (cp[0] == '%')
		{
			/* ignore literal % characters */
			if (cp[1] == '%')
				cp++;
			else
				expected_nparams++;
		}
	}

	if (expected_nparams < list_length(stmt->params))
		ereport(ERROR,
				(errcode(ERRCODE_SYNTAX_ERROR),
				errmsg("too many parameters specified for RAISE")));
	if (expected_nparams > list_length(stmt->params))
		ereport(ERROR,
				(errcode(ERRCODE_SYNTAX_ERROR),
				errmsg("too few parameters specified for RAISE")));
}

/*
 * Fix up CASE statement
 */
static PLpgSQL_stmt *
make_case(int location, PLpgSQL_expr *t_expr,
		  List *case_when_list, List *else_stmts)
{
	PLpgSQL_stmt_case	*new;

	new = palloc(sizeof(PLpgSQL_stmt_case));
	new->cmd_type = PLPGSQL_STMT_CASE;
	new->lineno = plpgsql_location_to_lineno(location);
	new->stmtid = ++plpgsql_curr_compile->nstatements;
	new->t_expr = t_expr;
	new->t_varno = 0;
	new->case_when_list = case_when_list;
	new->have_else = (else_stmts != NIL);
	/* Get rid of list-with-NULL hack */
	if (list_length(else_stmts) == 1 && linitial(else_stmts) == NULL)
		new->else_stmts = NIL;
	else
		new->else_stmts = else_stmts;

	/*
	 * When test expression is present, we create a var for it and then
	 * convert all the WHEN expressions to "VAR IN (original_expression)".
	 * This is a bit klugy, but okay since we haven't yet done more than
	 * read the expressions as text.  (Note that previous parsing won't
	 * have complained if the WHEN ... THEN expression contained multiple
	 * comma-separated values.)
	 */
	if (t_expr)
	{
		char	varname[32];
		PLpgSQL_var *t_var;
		ListCell *l;

		/* use a name unlikely to collide with any user names */
		snprintf(varname, sizeof(varname), "__Case__Variable_%d__",
				 plpgsql_nDatums);

		/*
		 * We don't yet know the result datatype of t_expr.  Build the
		 * variable as if it were INT4; we'll fix this at runtime if needed.
		 */
		t_var = (PLpgSQL_var *)
			plpgsql_build_variable(varname, new->lineno,
								   plpgsql_build_datatype(INT4OID,
														  -1,
														  InvalidOid,
														  NULL),
								   true);
		new->t_varno = t_var->dno;

		foreach(l, case_when_list)
		{
			PLpgSQL_case_when *cwt = (PLpgSQL_case_when *) lfirst(l);
			PLpgSQL_expr *expr = cwt->expr;
			StringInfoData	ds;

			/* We expect to have expressions not statements */
			Assert(expr->parseMode == RAW_PARSE_PLPGSQL_EXPR);

			/* Do the string hacking */
			initStringInfo(&ds);

			appendStringInfo(&ds, "\"%s\" IN (%s)",
							 varname, expr->query);

			pfree(expr->query);
			expr->query = pstrdup(ds.data);
			/* Adjust expr's namespace to include the case variable */
			expr->ns = plpgsql_ns_top();

			pfree(ds.data);
		}
	}

	return (PLpgSQL_stmt *) new;
}
