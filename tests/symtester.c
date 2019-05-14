#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <errno.h>
#include <yystype.h>
#include <ast.h>
#include <symtab.h>
#include "../src/y.tab.h"

int yyparse();
void print_node(struct ASTNODE* node, int depth);
void print_string(struct ASTNODE* node);
void print_number(struct ASTNODE* node);
void print_char();
extern int yydebug;
extern struct scope *current_scope;

struct scope global_scope;

int main(int ac, char *av[]){
	if(ac>1) yydebug=1;
	else yydebug=0;
	current_scope = &global_scope;
	yyparse();
	return 0;
}

void print_node(struct ASTNODE* node, int depth){
	for(int i=0; i<depth; i++) fprintf(stdout, "  ");
	if(!node) return;
	switch(node->nodetype){
		case AST_BINOP:
			switch(node->ast_binop){
				case '.':
					fprintf(stdout, "SELECT");
					break;
				case '=':
					fprintf(stdout, "ASSIGNMENT");
					break;
				case SHR:
					fprintf(stdout, "BINARY  OP  >>");
					break;
				case SHL:
					fprintf(stdout, "BINARY  OP  <<");
					break;
				case LTEQ:
					fprintf(stdout, "COMPARISON  OP  <=");
					break;
				case GTEQ:
					fprintf(stdout, "COMPARISON  OP  >=");
					break;
				case EQEQ:
					fprintf(stdout, "COMPARISON  OP  ==");
					break;
				case NOTEQ:
					fprintf(stdout, "COMPARISON  OP  !=");
					break;
				case LOGAND:
					fprintf(stdout, "LOGICAL  OP  &&");
					break;
				case LOGOR:
					fprintf(stdout, "LOGICAL  OP  ||");
					break;
				default:
					fprintf(stdout, "BINARY  OP  %c", node->ast_binop);
					break;
			}
			fprintf(stdout, "\n");
			print_node(node->left_binop, depth+1);
			print_node(node->right_binop, depth+1);
			break;
		case AST_UNARYOP:
			switch(node->ast_unaryop){
				case SIZEOF:
					fprintf(stdout, "SIZEOF");
					break;
				case '*':
					fprintf(stdout, "DEREF");
					break;
				case '&':
					fprintf(stdout, "ADDRESSOF");
					break;
				default:
					fprintf(stdout, "UNARY  OP  ");
					switch(node->ast_unaryop){
						case PLUSPLUS:
							fprintf(stdout, "POSTINC");
							break;
						case MINUSMINUS:
							fprintf(stdout, "POSTDEC");
							break;
						default:
							fprintf(stdout, "%c", node->ast_unaryop);
							break;
					}
					break;
			}
			fprintf(stdout, "\n");
			print_node(node->single_op, depth+1);
			break;
		case AST_TERNOP:
			fprintf(stdout, "TERNARY  OP,  IF:\n");
			print_node(node->left_ternop, depth+1);
			fprintf(stdout, "THEN:\n");
			print_node(node->middle_ternop, depth+1);
			fprintf(stdout, "ELSE:\n");
			print_node(node->right_ternop, depth+1);
			break;
		case AST_FUNC:
			fprintf(stdout, "FNCALL,  %d  arguments\n", node->arg_no);
			print_node(node->func_name, depth+1);
			int i=node->arg_no;
			for(struct ASTNODE *expr_list=node->args; expr_list!=NULL; expr_list=expr_list->existing_list){
				for(int i=0; i<depth; i++) fprintf(stdout, "  ");
				fprintf(stdout, "arg  #%d=\n", i--);
				print_node(expr_list->new_expr, depth+1);
			}
			break;
		case AST_IDENT:
			fprintf(stdout, "IDENT  %s\n", node->ident);
			break;
		case AST_CHARLIT:
			fprintf(stdout, "CONSTANT:  (type=char)");
			print_char(node->char_lit);
			fprintf(stdout, "\n");
			break;
		case AST_STRINGLIT:
			fprintf(stdout, "STRING\t");
			print_string(node);
			fprintf(stdout, "\n");
			break;
		case AST_NUM:
			fprintf(stdout, "CONSTANT:  (type=");
			print_number(node);
			fprintf(stdout, "\n");
			break;
		case AST_IF:
			fprintf(stdout, "IF");
			break;
		case AST_WHILE:
			fprintf(stdout, "WHILE");
			break;
		case AST_FOR:
			fprintf(stdout, "FOR");
			break;
		case AST_RETURN:
			fprintf(stdout, "RETURN");
			break;
		case AST_GOTO:
			fprintf(stdout, "GOTO");
			break;
		case AST_ASSIGNMENT:
			fprintf(stdout, "ASSIGNMENT");
			break;
		case AST_BLOCK:
			fprintf(stdout, "BLOCK");
			break;
		case AST_LABELED_STATEMENT:
			fprintf(stdout, "LABELED");
			break;
		case AST_STATEMENT_LIST:
			fprintf(stdout, "LIST {");
			print_node(node->next_node, depth+1);
			fprintf(stdout, "\n}\n");
			break;
		default:
			break;
	}
	return;
}

void print_string(struct ASTNODE* node){
	for(int i=0; i<node->string_size; i++){
		print_char(node->string_lit[i]);
	}
	return;
}

void print_number(struct ASTNODE* node){
	switch(node->sign_and_precision){
		case I_LIT:
			fprintf(stdout, "int)%d", node->i_lit);
			break;
		case I_LIT_U:
			fprintf(stdout, "unsigned int)%u", node->i_lit_u);
			break;
		case L_LIT:
			fprintf(stdout, "long)%ld", node->l_lit);
			break;
		case L_LIT_U:
			fprintf(stdout, "unsigned long)%lu", node->l_lit_u);
			break;
		case LL_LIT:
			fprintf(stdout, "long long)%lld", node->ll_lit);
			break;
		case LL_LIT_U:
			fprintf(stdout, "unsigned long long)%llu", node->ll_lit_u);
			break;
		case F_LIT:
			fprintf(stdout, "float)%f", node->f_lit);
			break;
		case D_LIT:
			fprintf(stdout, "double)%f", node->d_lit);
			break;
		case LD_LIT:
			fprintf(stdout, "long double)%Lf", node->ld_lit);
			break;
		default:
			fprintf(stdout, "int)%d", node->i_lit);
			break;
	}
	return;
}
