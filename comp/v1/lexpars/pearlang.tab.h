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
     ID = 258,
     NUMBER = 259,
     FLOAT = 260,
     STRING = 261,
     AR = 262,
     COLON = 263,
     SEMICOLON = 264,
     COMMA = 265,
     DOT = 266,
     L_BRACE = 267,
     R_BRACE = 268,
     L_GBRACE = 269,
     R_GBRACE = 270,
     EQUAL = 271,
     TIMES = 272,
     PLUS = 273,
     MINUS = 274,
     DIVIDED = 275,
     MODULO = 276,
     HASH = 277,
     BIGGER = 278,
     SMALLER = 279,
     VOID = 280,
     I8 = 281,
     I16 = 282,
     I32 = 283,
     I64 = 284,
     U8 = 285,
     U16 = 286,
     U32 = 287,
     U64 = 288,
     F32 = 289,
     F64 = 290,
     BOOL = 291,
     RETURN = 292,
     IF = 293,
     NEW = 294,
     CRT = 295,
     BREAK = 296,
     CONTINUE = 297,
     STRUCT = 298,
     TRUE = 299,
     FALSE = 300,
     NUL = 301
   };
#endif
/* Tokens.  */
#define ID 258
#define NUMBER 259
#define FLOAT 260
#define STRING 261
#define AR 262
#define COLON 263
#define SEMICOLON 264
#define COMMA 265
#define DOT 266
#define L_BRACE 267
#define R_BRACE 268
#define L_GBRACE 269
#define R_GBRACE 270
#define EQUAL 271
#define TIMES 272
#define PLUS 273
#define MINUS 274
#define DIVIDED 275
#define MODULO 276
#define HASH 277
#define BIGGER 278
#define SMALLER 279
#define VOID 280
#define I8 281
#define I16 282
#define I32 283
#define I64 284
#define U8 285
#define U16 286
#define U32 287
#define U64 288
#define F32 289
#define F64 290
#define BOOL 291
#define RETURN 292
#define IF 293
#define NEW 294
#define CRT 295
#define BREAK 296
#define CONTINUE 297
#define STRUCT 298
#define TRUE 299
#define FALSE 300
#define NUL 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "pearlang.y"
{
    Production *prod;
    char *str;
    int ival;
    float fval;
}
/* Line 1529 of yacc.c.  */
#line 148 "pearlang.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

