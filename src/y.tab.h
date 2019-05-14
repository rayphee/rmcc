/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 189 "src/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

