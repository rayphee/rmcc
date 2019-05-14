%debug
%error-verbose
%{
#include <stdio.h>
#include <stdlib.h>
#include <yystype.h>
#include <ast.h>

#include "y.tab.h"

int yylex();
int yyparse();
int yyerror();
struct ASTNODE* create_node(int nodetype);
void populate_num_node(struct ASTNODE* node, struct num_lit* number);
void print_node(struct ASTNODE* node, int depth);

%}

%union {
	struct ASTNODE* node;
	char* ident;
	char char_lit;
	struct string_lit string_lit;
	struct num_lit num_lit;
}

%type<node> expr expr_list primary_expr postfix_expr component_select_expr function_call post_inc_expr post_dec_expr sizeof_expr cast_expr unary_expr unary_plus_expr unary_minus_expr log_neg_expr bit_neg_expr pre_inc_expr pre_dec_expr address_expr indirection_expr subscript_expr mult_expr add_expr shift_expr relation_expr equality_expr bit_and_expr bit_xor_expr bit_or_expr log_and_expr log_or_expr assign_expr cond_expr comma_expr compound_literal initializer_list initializer
%token<ident> IDENT
%token<char_lit> CHARLIT
%token<string_lit> STRING
%token<num_lit> NUMBER

%token TOKEOF 
%token INDSEL PLUSPLUS MINUSMINUS SHL SHR LTEQ GTEQ EQEQ NOTEQ LOGAND LOGOR ELLIPSIS SIZEOF
%token AUTO BREAK CASE CONST CONTINUE DEFAULT DO ELSE ENUM EXTERN FOR GOTO IF INLINE REGISTER RESTRICT RETURN STATIC STRUCT SWITCH TYPEDEF UNION VOID VOLATILE WHILE _BOOL _COMPLEX _IMAGINARY

%left LOGOR
%left LOGAND
%left '|'
%left '^'
%left '&'
%left EQEQ NOTEQ
%left '<' '>' GTEQ LTEQ
%left SHL SHR
%left '-'
%left '+'
%left '%'
%left '*' '/'

%right UNSIGNED SIGNED SHORT LONG INT CHAR DOUBLE FLOAT
%right '=' PLUSEQ MINUSEQ TIMESEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ XOREQ OREQ
%%

start: expr_statement
     | start expr_statement
     ;

expr_statement:	expr ';'	{ 
	      				print_node($1, 0); 
	      				fprintf(stdout, "\n");
				}
	      ;

expr:	comma_expr	
    ;

primary_expr:	IDENT	{
	    			$$ = create_node(AST_IDENT);
				$$->ident = $1;
			}
	    |	NUMBER	{ 
				$$ = create_node(AST_NUM);
				populate_num_node($$, &$1);
			}
	    |	STRING	{ 
				$$ = create_node(AST_STRINGLIT);
				$$->string_lit = $1.string_lit;
				$$->string_size = $1.string_size;
			}
	    |	CHARLIT	{
				$$ = create_node(AST_CHARLIT);
				$$->char_lit = $1;
			}
	    |	'(' expr ')' { 
				$$ = $2;
			}
	    ;

postfix_expr:	primary_expr
	    |	subscript_expr
	    |	component_select_expr
	    |	function_call
	    |	post_inc_expr
	    |	post_dec_expr
	    |	compound_literal 
	    ;

subscript_expr:	postfix_expr '[' expr ']'	{
	      						$$ = create_node(AST_UNARYOP);
							$$->ast_unaryop = '*';
							struct ASTNODE* child = create_node(AST_BINOP);
							child->ast_binop = '+';
							child->left_binop = $1;
							child->right_binop = $3;
							$$->single_op = child;
						}
	      ;

component_select_expr:	postfix_expr '.' IDENT	{
	      						$$ = create_node(AST_BINOP);
							$$->ast_binop = '.';
							struct ASTNODE* child_ident = create_node(AST_IDENT);
							child_ident->ident = $3;
							$$->left_binop = $1;
							$$->right_binop = child_ident;
						}
		     |	postfix_expr INDSEL IDENT	{
	      						$$ = create_node(AST_BINOP);
							$$->ast_binop = '.';
							struct ASTNODE* child_deref = create_node(AST_UNARYOP);
							struct ASTNODE* child_ident = create_node(AST_IDENT);
							child_deref->ast_unaryop = '*';
							child_deref->single_op = $1;
							child_ident->ident = $3;
							$$->left_binop = child_deref;
							$$->right_binop = child_ident;
						}
		     ;

function_call:	postfix_expr '(' expr_list ')'	{
	     						$$ = create_node(AST_FUNC);
							$$->func_name = $1;
							$$->arg_no = $3->expr_no;
							$$->args = $3;
						}
	     ;

expr_list:	/* Optional */			{ 
							$$ = create_node(AST_ARGLIST);
							$$->expr_no = 0;
							$$->existing_list = NULL;
							$$->new_expr = NULL;
	 					}
	 |	assign_expr			{
							$$ = create_node(AST_ARGLIST);
							$$->expr_no = 1;
							$$->existing_list = NULL;
							$$->new_expr = $1;
						}
	 |	expr_list ',' assign_expr	{ 
							$$ = create_node(AST_ARGLIST);
							$$->expr_no = ($1->expr_no)+1;
							$$->existing_list = $1;
							$$->new_expr = $3;
						}
	 ;

post_inc_expr:	postfix_expr PLUSPLUS	{
						$$ = create_node(AST_UNARYOP);
						$$->ast_unaryop = PLUSPLUS;
						$$->single_op = $1;
					}
	     ;

post_dec_expr:	postfix_expr MINUSMINUS	{
						$$ = create_node(AST_UNARYOP);
						$$->ast_unaryop = MINUSMINUS;
						$$->single_op = $1;
					}
	     ;

type_name:	CHAR	
	 |	SHORT
	 |	DOUBLE
	 |	FLOAT
	 |	LONG LONG
	 |	LONG
	 |	INT
	 ;

compound_literal:	'(' type_name ')' '{' initializer_list ',' '}'	{ }
		|	'(' type_name ')' '{' initializer_list '}'	{ }
		;

initializer_list:	initializer
		|	initializer_list ',' initializer
		;

initializer:	assign_expr
	   ;

cast_expr:	unary_expr	{ $$ = $1; }
	 |	'(' type_name ')' cast_expr	{ 
							$$ = create_node(AST_CASTOP);
							$$->single_cast = $4;
						}
	 ;

unary_expr:	postfix_expr
	  |	sizeof_expr 
	  |	unary_minus_expr
	  |	unary_plus_expr
	  |	log_neg_expr
	  |	bit_neg_expr
	  |	address_expr
	  |	indirection_expr
	  |	pre_inc_expr
	  |	pre_dec_expr	{ $$ = $1; }
	  ;
	
sizeof_expr:	SIZEOF unary_expr		{ 
	   						$$ = create_node(AST_UNARYOP);
							$$->ast_unaryop = SIZEOF;
							$$->single_op = $2;
	   					}
	   |	SIZEOF '(' type_name ')'	{ }
	   ;

unary_minus_expr:	'-' cast_expr	{
						$$ = create_node(AST_UNARYOP);
						$$->ast_unaryop = '-';
						$$->single_op = $2;
					}
		;

unary_plus_expr:	'+' cast_expr	{ 
						$$ = create_node(AST_UNARYOP);
						$$->ast_unaryop = '+';
						$$->single_op = $2;
					}
	       ;

log_neg_expr:	'!' cast_expr	{
						$$ = create_node(AST_UNARYOP);
						$$->ast_unaryop = '!';
						$$->single_op = $2;
					}
	    ;

bit_neg_expr:	'~' cast_expr	{
						$$ = create_node(AST_UNARYOP);
						$$->ast_unaryop = '~';
						$$->single_op = $2;
					}
	    ;

address_expr:	'&' cast_expr	{
						$$ = create_node(AST_UNARYOP);
						$$->ast_unaryop = '&';
						$$->single_op = $2;
					}
	    ;

indirection_expr:	'*' cast_expr	{
						$$ = create_node(AST_UNARYOP);
						$$->ast_unaryop = '*';
						$$->single_op = $2;
					}
		;

pre_inc_expr:	PLUSPLUS unary_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '=';
						$$->left_binop = $2;
						struct ASTNODE* child = create_node(AST_BINOP);
						struct ASTNODE* one = create_node(AST_NUM);
						one->i_lit = 1;
						one->sign_and_precision = I_LIT;
						child->ast_binop = '+';
						child->left_binop = $2;
						child->right_binop = one;
						$$->right_binop = child;
					}

	    ;

pre_dec_expr:	MINUSMINUS unary_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '=';
						$$->left_binop = $2;
						struct ASTNODE* child = create_node(AST_BINOP);
						struct ASTNODE* one = create_node(AST_NUM);
						one->i_lit = 1;
						one->sign_and_precision = I_LIT;
						child->ast_binop = '-';
						child->left_binop = $2;
						child->right_binop = one;
						$$->right_binop = child;
					}

	    ;

mult_expr:	cast_expr
	 |	mult_expr '*' cast_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '*';
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	 |	mult_expr '/' cast_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '/';
						$$->left_binop = $1;
						$$->right_binop = $3;
					} 
	 |	mult_expr '%' cast_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '%';
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	 ;

add_expr:	mult_expr
	|	add_expr '+' mult_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '+';
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	|	add_expr '-' mult_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '-';
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	;

shift_expr:	add_expr
	  |	shift_expr SHL add_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = SHL;
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	  |	shift_expr SHR add_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = SHR;
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	  ;

relation_expr:	shift_expr
	     |	relation_expr '<' shift_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '<';
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	     |	relation_expr '>' shift_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '>';
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	     |	relation_expr GTEQ shift_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = GTEQ;
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	     |	relation_expr LTEQ shift_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = LTEQ;
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	     ;

equality_expr:	relation_expr
	     |	equality_expr EQEQ relation_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = EQEQ;
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	     |	equality_expr NOTEQ relation_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = NOTEQ;
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	     ;

bit_and_expr:	equality_expr
	    |	bit_and_expr '&' equality_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '&';
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	    ;

bit_xor_expr:	bit_and_expr
	    |	bit_xor_expr '^' bit_and_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '^';
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	    ;

bit_or_expr:	bit_xor_expr
	   |	bit_or_expr '|' bit_xor_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '|';
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	   ;
		   
log_and_expr:	bit_or_expr
	   |	log_and_expr LOGAND bit_or_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = LOGAND;
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	   ;

log_or_expr:	log_and_expr
	   |	log_or_expr LOGOR log_and_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = LOGOR;
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	   ;

cond_expr:	log_or_expr			{  }
	 |	log_or_expr '?' expr ':' cond_expr	{
						$$ = create_node(AST_TERNOP);
						$$->left_ternop = $1;
						$$->middle_ternop = $3;
						$$->right_ternop = $5;
						}
	 ;

assign_expr:	cond_expr			{ }
	   |	unary_expr '=' assign_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '=';
						$$->left_binop = $1;
						$$->right_binop = $3;
					}
	   |	unary_expr PLUSEQ assign_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '=';
						$$->left_binop = $1;
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = '+';
						child->left_binop = $1;
						child->right_binop = $3;
						$$->right_binop = child;
					}
	   |	unary_expr MINUSEQ assign_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '=';
						$$->left_binop = $1;
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = '-';
						child->left_binop = $1;
						child->right_binop = $3;
						$$->right_binop = child;
					}
	   |	unary_expr TIMESEQ assign_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '=';
						$$->left_binop = $1;
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = '*';
						child->left_binop = $1;
						child->right_binop = $3;
						$$->right_binop = child;
					}
	   |	unary_expr DIVEQ assign_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '=';
						$$->left_binop = $1;
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = '/';
						child->left_binop = $1;
						child->right_binop = $3;
						$$->right_binop = child;
					}
	   |	unary_expr MODEQ assign_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '=';
						$$->left_binop = $1;
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = '%';
						child->left_binop = $1;
						child->right_binop = $3;
						$$->right_binop = child;
					}
	   |	unary_expr SHLEQ assign_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '=';
						$$->left_binop = $1;
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = SHL;
						child->left_binop = $1;
						child->right_binop = $3;
						$$->right_binop = child;
					}
	   |	unary_expr SHREQ assign_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '=';
						$$->left_binop = $1;
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = SHR;
						child->left_binop = $1;
						child->right_binop = $3;
						$$->right_binop = child;
					}
	   |	unary_expr ANDEQ assign_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '=';
						$$->left_binop = $1;
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = '&';
						child->left_binop = $1;
						child->right_binop = $3;
						$$->right_binop = child;
					}
	   |	unary_expr XOREQ assign_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '=';
						$$->left_binop = $1;
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = '^';
						child->left_binop = $1;
						child->right_binop = $3;
						$$->right_binop = child;
					}
	   |	unary_expr OREQ assign_expr	{
						$$ = create_node(AST_BINOP);
						$$->ast_binop = '=';
						$$->left_binop = $1;
						struct ASTNODE* child = create_node(AST_BINOP);
						child->ast_binop = '|';
						child->left_binop = $1;
						child->right_binop = $3;
						$$->right_binop = child;
					}
	   ;

comma_expr:	assign_expr			{ }
	  |	comma_expr ',' assign_expr	{
							$$ = create_node(AST_BINOP);
							$$->ast_binop = ',';
							$$->left_binop = $1;
							$$->right_binop = $3;
						}
	  ;

%%

struct ASTNODE* create_node(int nodetype) {
	struct ASTNODE *newnode = malloc(sizeof(struct ASTNODE));
	if(!newnode) {
		yyerror("Fatal Error: Failed to allocate memory for new AST node");
		exit(-1);
	}
	newnode->nodetype = nodetype;
	return newnode;
}

void populate_num_node(struct ASTNODE* node, struct num_lit* number){
	node->sign_and_precision = number->sign_and_precision;
	
	// I'm pretty sure this switch doesn't need to be here, considering how unions
	// are supposed to work in C
	switch(node->sign_and_precision){
		case I_LIT:
			node->i_lit = number->i_lit;
			break;
		case I_LIT_U:
			node->i_lit_u = number->i_lit_u;
			break;
		case L_LIT:
			node->l_lit = number->l_lit;
			break;
		case L_LIT_U:
			node->l_lit_u = number->l_lit_u;
			break;
		case LL_LIT:
			node->ll_lit = number->ll_lit;
			break;
		case LL_LIT_U:
			node->ll_lit_u = number->ll_lit_u;
			break;
		case F_LIT:
			node->f_lit = number->f_lit;
			break;
		case D_LIT:
			node->d_lit = number->d_lit;
			break;
		case LD_LIT:
			node->ld_lit = number->ld_lit;
			break;
		default:
			node->i_lit = number->i_lit;
			break;
	}
	return;
}
