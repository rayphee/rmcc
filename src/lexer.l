D				[0-9]
H				[0-9A-Fa-f]
O				[0-7]
ID				[A-Za-z_]
ULL				([uU]?[lL]{0,2})|([lL]{0,2}[uU])
FL				[fFlL]
E				([eE][\+-]?{D}+)
P				([pP][\+-]?{D}+)
%x				comment
%x				character
%x				string
%x				escape
%x				preprocess

%option noyywrap
%{
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#include <yystype.h>

#include "y.tab.h"

#ifndef YYTOKENTYPE
#include <tokens-manual.h>
typedef union{
	char* ident;
	char char_lit;
	struct string_lit string_lit;
	struct num_lit num_lit;
} YYSTYPE;
#endif

YYSTYPE yylval;
int is_string;
int line;
char filename[64]="stdin";

void handle_integer(char *yytext, int yyleng, int base);
void handle_float(char *yytext, int yyleng);
void append_string(char *str, int length);
void yywarn(char *message, ...);
void yyerror(char *error, ...);
int yylex();
%}
%%

	/* Preprocessing work */
#	|
%:				{ BEGIN(preprocess); }
<preprocess>[ ]*{D}+[ ]*\"[^\"]+\".			{ sscanf(yytext, "%d \"%62[^\"]\"", &line, filename);}
<preprocess>.			{ }
<preprocess>\n			{ BEGIN(INITIAL); }

	/* Comments */
\/\/.*\n			{ line++; }
\/\*				{ BEGIN(comment); }
<comment>.			{ }
<comment>\n			{ line++; }
<comment>\*\/			{ BEGIN(INITIAL); }

	/* Integers */
0[xX]{H}+{ULL}?			{
				handle_integer(yytext, yyleng,16);
				return NUMBER;
				}
[1-9]{D}*{ULL}?			{
				handle_integer(yytext, yyleng, 10);
				return NUMBER;
				}
0{O}*{ULL}?			{
				handle_integer(yytext, yyleng, 8);
				return NUMBER;
				}

	/* Floating Point */
{D}+"."?{D}*{E}{FL}?		|
{D}*"."{D}+{E}?{FL}?		|
{D}+"."{FL}?			|
0[xX]{H}+"."?{H}*{P}{FL}?	|
0[xX]{H}*"."{H}+{P}?{FL}?	|
0[xX]{H}+"."{FL}?		{
				handle_float(yytext, yyleng);
				return NUMBER;
				}
	/* Char */
L?\'				{
				is_string=0;
				BEGIN(character);
				}
<character>[^\'\n\\]+		{
				yylval.char_lit=yytext[0];
				if(yyleng>1)
					yywarn("Unsupported multibyte character literal truncated to first byte");
				}
<character>\n			{
				yyerror("Improper character literal");
				}
<character>\\			{ BEGIN(escape); }
<character>\'			{
				is_string=0;
				BEGIN(INITIAL);
				return CHARLIT;
				}

	/* String */
L?\"				{
				yylval.string_lit.string_size=0;
				is_string=1;
				BEGIN(string);
				}
<string>[^\"\n\\]*		{
				append_string(yytext, yyleng);
				}
<string>\n			{ yyerror("Improper string literal"); }
<string>\\			{ BEGIN(escape); }
<string>\"			{
				is_string=0;
				BEGIN(INITIAL);
				return STRING;
				}

	/* Escape */
<escape>[abfnrtv\\\'\"\?]	{
				char c;
				switch(yytext[0]){
					case 'a':
						c = '\a';
						break;
					case 'b':
						c = '\b';
						break;
					case 'f':
						c = '\f';
						break;
					case 'n':
						c = '\n';
						break;
					case 'r':
						c = '\r';
						break;
					case 't':
						c = '\t';
						break;
					case 'v':
						c = '\v';
						break;
					case '\\':
						c = '\\';
						break;
					case '\'':
						c = '\'';
						break;
					case '"':
						c = '"';
						break;
					case '?':
						c = '?';
						break;
				}
				if(is_string){
					append_string(&c, 1);
					BEGIN(string);
				}
				else{
					yylval.char_lit=c;
					BEGIN(character);
				}
				}
<escape>{O}{1,3}		{
				long raw_char=strtol(yytext, 0, 8);
				if(raw_char>0xFF)
					yywarn("Octal escape sequence %s out of range", yytext);
				char c=(char)raw_char;
				if(is_string){
					append_string(&c, 1);
					BEGIN(string);
				}
				else{
					yylval.char_lit=c;
					BEGIN(character);
				}
				}
<escape>[xX]{H}+		{
				long raw_char=strtol(&yytext[1], 0, 16);
				if(raw_char>0xFF)
					yywarn("Hex escape sequence %s out of range", yytext);
				char c=(char)raw_char;
				if(is_string){
					append_string(&c, 1);
					BEGIN(string);
				}
				else{
					yylval.char_lit=c;
					BEGIN(character);
				}
				}

	/* The rest */
"->"				{ return INDSEL; }
"++"				{ return PLUSPLUS; }
"--"				{ return MINUSMINUS; }
"<<"				{ return SHL; }
">>"				{ return SHR; }
"<="				{ return LTEQ; }
">="				{ return GTEQ; }
"=="				{ return EQEQ; }
"!="				{ return NOTEQ; }
"&&"				{ return LOGAND; }
"||"				{ return LOGOR; }
"..."				{ return ELLIPSIS; }
"*="				{ return TIMESEQ; }
"/="				{ return DIVEQ; }
"%="				{ return MODEQ; }
"+="				{ return PLUSEQ; }
"-="				{ return MINUSEQ; }
"<<="				{ return SHLEQ; }
">>="				{ return SHREQ; }
"&="				{ return ANDEQ; }
"|="				{ return OREQ; }
"^="				{ return XOREQ; }
"auto"				{ return AUTO; }
"break"				{ return BREAK; }
"case"				{ return CASE; }
"char"				{ return CHAR; }
"const"				{ return CONST; }
"continue"			{ return CONTINUE; }
"default"			{ return DEFAULT; }
"do"				{ return DO; }
"double"			{ return DOUBLE; }
"else"				{ return ELSE; }
"enum"				{ return ENUM; }
"extern"			{ return EXTERN; }
"float"				{ return FLOAT; }
"for"				{ return FOR; }
"goto"				{ return GOTO; }
"if"				{ return IF; }
"inline"			{ return INLINE; }
"int"				{ return INT; }
"long"				{ return LONG; }
"register"			{ return REGISTER; }
"restrict"			{ return RESTRICT; }
"return"			{ return RETURN; }
"short"				{ return SHORT; }
"signed"			{ return SIGNED; }
"sizeof"			{ return SIZEOF; }
"static"			{ return STATIC; }
"struct"			{ return STRUCT; }
"switch"			{ return SWITCH; }
"typedef"			{ return TYPEDEF; }
"union"				{ return UNION; }
"unsigned"			{ return UNSIGNED; }
"void"				{ return VOID; }
"volatile"			{ return VOLATILE; }
"while"				{ return WHILE; }
"_Bool"				{ return _BOOL; }
"_Complex"			{ return _COMPLEX; }
"_Imaginary"			{ return _IMAGINARY; }
"+"				{ return '+'; }
"-"				{ return '-'; }
"*"				{ return '*'; }
"/"				{ return '/'; }
"%"				{ return '%'; }
"<"				{ return '<'; }
">"				{ return '>'; }
"="				{ return '='; }
";"				{ return ';'; }
":"				{ return ':'; }
"."				{ return '.'; }
","				{ return ','; }
"|"				{ return '|'; }
"&"				{ return '&'; }
"!"				{ return '!'; }
"?"				{ return '?'; }
"~"				{ return '~'; }
"^"				{ return '^'; }
"["	|
"<:"				{ return '['; }
"]"	|
":>"				{ return ']'; }
"{"	|
"<%"				{ return '{'; }
"}"	|
"%>"				{ return '}'; }
"("				{ return '('; }
")"				{ return ')'; }

	/* Identifiers */
{ID}({ID}|{D})*			{
				yylval.ident=strdup(yytext);
				return IDENT;
				}
	/* whitespace */
[\t\v\f ]+			{ }
\n				{ line++; }

%%

void handle_integer(char *yytext, int yyleng, int base){
	yylval.num_lit.sign_and_precision=0;
	long long converted_integer;
	for(int i=yyleng-3; i<yyleng; i++){
		switch(yytext[i]){
			case 'u': /* 'u' is the same as 'U' */
			case 'U':
				yylval.num_lit.sign_and_precision+=1; /* this works because our regex only gives us one u|U and unsigned are always odd in yystype.h enum */
				yytext[i]=0;
				break;
			case 'l': /* Again, 'l' is the same as 'L' */
			case 'L':
				yylval.num_lit.sign_and_precision+=2; /* this works because of the way we enumerated in yystype.h */
				yytext[i]=0;
				break;
		}
	}

	converted_integer=strtoll(yytext, 0, base);
	if(converted_integer==LLONG_MIN || converted_integer==LLONG_MAX)
		yywarn("Passed integer too large");
	switch(yylval.num_lit.sign_and_precision){
		case I_LIT:
			yylval.num_lit.i_lit=(int) converted_integer;
			break;
		case I_LIT_U:
			yylval.num_lit.i_lit_u=(unsigned int) converted_integer;
			break;
		case L_LIT:
			yylval.num_lit.l_lit=(long) converted_integer;
			break;
		case L_LIT_U:
			yylval.num_lit.l_lit_u=(unsigned long) converted_integer;
			break;
		case LL_LIT:
			yylval.num_lit.ll_lit=(long long) converted_integer;
			break;
		case LL_LIT_U:
			yylval.num_lit.ll_lit_u=(unsigned long long) converted_integer;
			break;
	}
}

void handle_float(char *yytext, int yyleng){
	yylval.num_lit.sign_and_precision=D_LIT;
	switch(yytext[yyleng-1]){
		case 'f': /* 'f' is the same as 'F' */
		case 'F':
			yylval.num_lit.sign_and_precision=6;
			yytext[yyleng]=F_LIT;
			break;
		case 'l': /* Again, 'l' is the same as 'L' */
		case 'L':
			yylval.num_lit.sign_and_precision=LD_LIT;
			yytext[yyleng]=0;
			break;
	}

	switch(yylval.num_lit.sign_and_precision){
		case F_LIT:
			yylval.num_lit.f_lit=strtof(yytext, 0);
			break;
		case D_LIT:
			yylval.num_lit.d_lit=strtod(yytext, 0);
			break;
		case LD_LIT:
			yylval.num_lit.ld_lit=strtold(yytext, 0);
			break;
	}
}

void append_string(char *str, int yyleng){
	if(!(yylval.string_lit.string_size))
		yylval.string_lit.string_lit=(char*) malloc(yyleng);
	else{
		char *reallocated_mem=(char *)realloc(yylval.string_lit.string_lit, yylval.string_lit.string_size+yyleng);
		if(!reallocated_mem)
			yyerror("Failed to reallocate memory for string");
		yylval.string_lit.string_lit=reallocated_mem;
	}
	memcpy(yylval.string_lit.string_lit+yylval.string_lit.string_size, str, yyleng);
	yylval.string_lit.string_size+=yyleng;
}
void yywarn(char *str, ...){
	fprintf(stderr, "%s:%d:Warning:", filename, line);

	va_list arguments;
	va_start(arguments, str);
	vfprintf(stderr, str, arguments);
	va_end(arguments);

	fprintf(stderr, "\n");
}

void yyerror(char *str, ...){
	fprintf(stderr, "%s:%d:Error:", filename, line);

	va_list arguments;
	va_start(arguments, str);
	vfprintf(stderr, str, arguments);
	va_end(arguments);

	fprintf(stderr, "\n");
	exit(-1);
}
