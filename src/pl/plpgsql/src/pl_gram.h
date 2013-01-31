
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENT = 258,
     FCONST = 259,
     SCONST = 260,
     BCONST = 261,
     XCONST = 262,
     Op = 263,
     ICONST = 264,
     PARAM = 265,
     TYPECAST = 266,
     DOT_DOT = 267,
     COLON_EQUALS = 268,
     T_WORD = 269,
     T_CWORD = 270,
     T_DATUM = 271,
     LESS_LESS = 272,
     GREATER_GREATER = 273,
     K_ABSOLUTE = 274,
     K_ALIAS = 275,
     K_ALL = 276,
     K_ARRAY = 277,
     K_BACKWARD = 278,
     K_BEGIN = 279,
     K_BY = 280,
     K_CASE = 281,
     K_CLOSE = 282,
     K_COLLATE = 283,
     K_CONSTANT = 284,
     K_CONTINUE = 285,
     K_CURRENT = 286,
     K_CURSOR = 287,
     K_DEBUG = 288,
     K_DECLARE = 289,
     K_DEFAULT = 290,
     K_DETAIL = 291,
     K_DIAGNOSTICS = 292,
     K_DUMP = 293,
     K_ELSE = 294,
     K_ELSIF = 295,
     K_END = 296,
     K_ERRCODE = 297,
     K_ERROR = 298,
     K_EXCEPTION = 299,
     K_EXECUTE = 300,
     K_EXIT = 301,
     K_FETCH = 302,
     K_FIRST = 303,
     K_FOR = 304,
     K_FOREACH = 305,
     K_FORWARD = 306,
     K_FROM = 307,
     K_GET = 308,
     K_HINT = 309,
     K_IF = 310,
     K_IN = 311,
     K_INFO = 312,
     K_INSERT = 313,
     K_INTO = 314,
     K_IS = 315,
     K_LAST = 316,
     K_LOG = 317,
     K_LOOP = 318,
     K_MESSAGE = 319,
     K_MESSAGE_TEXT = 320,
     K_MOVE = 321,
     K_NEXT = 322,
     K_NO = 323,
     K_NOT = 324,
     K_NOTICE = 325,
     K_NULL = 326,
     K_OPEN = 327,
     K_OPTION = 328,
     K_OR = 329,
     K_PERFORM = 330,
     K_PG_EXCEPTION_CONTEXT = 331,
     K_PG_EXCEPTION_DETAIL = 332,
     K_PG_EXCEPTION_HINT = 333,
     K_PRIOR = 334,
     K_QUERY = 335,
     K_RAISE = 336,
     K_RELATIVE = 337,
     K_RESULT_OID = 338,
     K_RETURN = 339,
     K_RETURNED_SQLSTATE = 340,
     K_REVERSE = 341,
     K_ROWTYPE = 342,
     K_ROW_COUNT = 343,
     K_SCROLL = 344,
     K_SLICE = 345,
     K_SQLSTATE = 346,
     K_STACKED = 347,
     K_STRICT = 348,
     K_THEN = 349,
     K_TO = 350,
     K_TYPE = 351,
     K_USE_COLUMN = 352,
     K_USE_VARIABLE = 353,
     K_USING = 354,
     K_VARIABLE_CONFLICT = 355,
     K_WARNING = 356,
     K_WHEN = 357,
     K_WHILE = 358
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 116 "gram.y"

		core_YYSTYPE			core_yystype;
		/* these fields must match core_YYSTYPE: */
		int						ival;
		char					*str;
		const char				*keyword;

		PLword					word;
		PLcword					cword;
		PLwdatum				wdatum;
		bool					boolean;
		Oid						oid;
		struct
		{
			char *name;
			int  lineno;
		}						varname;
		struct
		{
			char *name;
			int  lineno;
			PLpgSQL_datum   *scalar;
			PLpgSQL_rec		*rec;
			PLpgSQL_row		*row;
		}						forvariable;
		struct
		{
			char *label;
			int  n_initvars;
			int  *initvarnos;
		}						declhdr;
		struct
		{
			List *stmts;
			char *end_label;
			int   end_label_location;
		}						loop_body;
		List					*list;
		PLpgSQL_type			*dtype;
		PLpgSQL_datum			*datum;
		PLpgSQL_var				*var;
		PLpgSQL_expr			*expr;
		PLpgSQL_stmt			*stmt;
		PLpgSQL_condition		*condition;
		PLpgSQL_exception		*exception;
		PLpgSQL_exception_block	*exception_block;
		PLpgSQL_nsitem			*nsitem;
		PLpgSQL_diag_item		*diagitem;
		PLpgSQL_stmt_fetch		*fetch;
		PLpgSQL_case_when		*casewhen;



/* Line 1676 of yacc.c  */
#line 209 "pl_gram.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE plpgsql_yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE plpgsql_yylloc;

