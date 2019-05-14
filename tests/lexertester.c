#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#include <yystype.h>
#include <tokens-manual.h>

typedef union{
	char* ident;
	char char_lit;
	struct string_lit string_lit;
	struct num_lit num_lit;
} YYSTYPE;

extern int line;
extern char filename[64];
extern YYSTYPE yylval;

void print_num();
void print_string();
void print_char();
int yylex();

int main(int ac, char *av[]){
	int token;
	while((token=yylex())){
		fprintf(stdout, "%s\t%d\t", filename, line);
		switch(token){
			case NUMBER:
				fprintf(stdout, "NUMBER\t");
				print_num();
				break;
			case CHARLIT:
				fprintf(stdout, "CHARLIT\t");
				print_char(yylval.char_lit);
				break;
			case STRING:
				fprintf(stdout, "STRING\t");
				print_string();
				break;
			case INDSEL:
				fprintf(stdout, "INDSEL\t");
				break;
			case PLUSPLUS:
				fprintf(stdout, "PLUSPLUS\t");
				break;
			case MINUSMINUS:
				fprintf(stdout, "MINUSMINUS\t");
				break;
			case SHL:
				fprintf(stdout, "SHL\t");
				break;
			case SHR:
				fprintf(stdout, "SHR\t");
				break;
			case LTEQ:
				fprintf(stdout, "LTEQ\t");
				break;
			case GTEQ:
				fprintf(stdout, "GTEQ\t");
				break;
			case EQEQ:
				fprintf(stdout, "EQEQ\t");
				break;
			case NOTEQ:
				fprintf(stdout, "NOTEQ\t");
				break;
			case LOGAND:
				fprintf(stdout, "LOGAND\t");
				break;
			case LOGOR:
				fprintf(stdout, "LOGOR\t");
				break;
			case ELLIPSIS:
				fprintf(stdout, "ELLIPSIS\t");
				break;
			case TIMESEQ:
				fprintf(stdout, "TIMESEQ\t");
				break;
			case DIVEQ:
				fprintf(stdout, "DIVEQ\t");
				break;
			case MODEQ:
				fprintf(stdout, "MODEQ\t");
				break;
			case PLUSEQ:
				fprintf(stdout, "PLUSEQ\t");
				break;
			case MINUSEQ:
				fprintf(stdout, "MINUSEQ\t");
				break;
			case SHLEQ:
				fprintf(stdout, "SHLEQ\t");
				break;
			case SHREQ:
				fprintf(stdout, "SHREQ\t");
				break;
			case ANDEQ:
				fprintf(stdout, "ANDEQ\t");
				break;
			case OREQ:
				fprintf(stdout, "OREQ\t");
				break;
			case XOREQ:
				fprintf(stdout, "XOREQ\t");
				break;
			case AUTO:
				fprintf(stdout, "AUTO\t");
				break;
			case BREAK:
				fprintf(stdout, "BREAK\t");
				break;
			case CASE:
				fprintf(stdout, "CASE\t");
				break;
			case CHAR:
				fprintf(stdout, "CHAR\t");
				break;
			case CONST:
				fprintf(stdout, "CONST\t");
				break;
			case CONTINUE:
				fprintf(stdout, "CONTINUE\t");
				break;
			case DEFAULT:
				fprintf(stdout, "DEFAULT\t");
				break;
			case DO:
				fprintf(stdout, "DO\t");
				break;
			case DOUBLE:
				fprintf(stdout, "DOUBLE\t");
				break;
			case ELSE:
				fprintf(stdout, "ELSE\t");
				break;
			case ENUM:
				fprintf(stdout, "ENUM\t");
				break;
			case EXTERN:
				fprintf(stdout, "EXTERN\t");
				break;
			case FLOAT:
				fprintf(stdout, "FLOAT\t");
				break;
			case FOR:
				fprintf(stdout, "FOR\t");
				break;
			case GOTO:
				fprintf(stdout, "GOTO\t");
				break;
			case IF:
				fprintf(stdout, "IF\t");
				break;
			case INLINE:
				fprintf(stdout, "INLINE\t");
				break;
			case INT:
				fprintf(stdout, "INT\t");
				break;
			case LONG:
				fprintf(stdout, "LONG\t");
				break;
			case REGISTER:
				fprintf(stdout, "REGISTER\t");
				break;
			case RESTRICT:
				fprintf(stdout, "RESTRICT\t");
				break;
			case RETURN:
				fprintf(stdout, "RETURN\t");
				break;
			case SHORT:
				fprintf(stdout, "SHORT\t");
				break;
			case SIGNED:
				fprintf(stdout, "SIGNED\t");
				break;
			case SIZEOF:
				fprintf(stdout, "SIZEOF\t");
				break;
			case STATIC:
				fprintf(stdout, "STATIC\t");
				break;
			case STRUCT:
				fprintf(stdout, "STRUCT\t");
				break;
			case SWITCH:
				fprintf(stdout, "SWITCH\t");
				break;
			case TYPEDEF:
				fprintf(stdout, "TYPEDEF\t");
				break;
			case UNION:
				fprintf(stdout, "UNION\t");
				break;
			case UNSIGNED:
				fprintf(stdout, "UNSIGNED\t");
				break;
			case VOID:
				fprintf(stdout, "VOID\t");
				break;
			case VOLATILE:
				fprintf(stdout, "VOLATILE\t");
				break;
			case WHILE:
				fprintf(stdout, "WHILE\t");
				break;
			case _BOOL:
				fprintf(stdout, "_BOOL\t");
				break;
			case _COMPLEX:
				fprintf(stdout, "_COMPLEX\t");
				break;
			case _IMAGINARY:
				fprintf(stdout, "_IMAGINARY\t");
				break;
			case IDENT:
				fprintf(stdout, "IDENT\t");
				fprintf(stdout, "%s", yylval.ident);
				break;
			default:
				fprintf(stdout, "%c\t", (char) token);
				break;
		}
		fprintf(stdout, "\n");
	}
	return 0;
}

void print_num(){
	switch(yylval.num_lit.sign_and_precision){
		case I_LIT:
			fprintf(stdout, "INTEGER\t%d\tINT\t", yylval.num_lit.i_lit);
			break;
		case I_LIT_U:
			fprintf(stdout, "INTEGER\t%u\tUNSIGNED,INT\t", yylval.num_lit.i_lit_u);
			break;
		case L_LIT:
			fprintf(stdout, "INTEGER\t%ld\tLONG\t", yylval.num_lit.l_lit);
			break;
		case L_LIT_U:
			fprintf(stdout, "INTEGER\t%lu\tUNSIGNED,LONG\t", yylval.num_lit.l_lit_u);
			break;
		case LL_LIT:
			fprintf(stdout, "INTEGER\t%lld\tLONGLONG\t", yylval.num_lit.ll_lit);
			break;
		case LL_LIT_U:
			fprintf(stdout, "INTEGER\t%llu\tUNSIGNED,LONGLONG\t", yylval.num_lit.ll_lit_u);
			break;
		case F_LIT:
			fprintf(stdout, "REAL\t%f\tFLOAT\t", yylval.num_lit.f_lit);
			break;
		case D_LIT:
			fprintf(stdout, "REAL\t%f\tDOUBLE\t", yylval.num_lit.d_lit);
			break;
		case LD_LIT:
			fprintf(stdout, "REAL\t%Lf\tLONGDOUBLE\t", yylval.num_lit.ld_lit);
			break;		
	}
}

void print_string(){
    for(int i=0; i<yylval.string_lit.string_size; i++){
        print_char(yylval.string_lit.string_lit[i]);
    }
}
