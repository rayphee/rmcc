%debug
%error-verbose
%{
#include <stdio.h>
#include <stdlib.h>
#include <yystype.h>
#include <ast.h>
#include <symtab.h>

#include "y.tab.h"

int yylex();
int yyparse();
int yyerror();
int yywarn();
struct ASTNODE *create_node(int nodetype);
void populate_num_node(struct ASTNODE *node, struct num_lit *number);
void print_node(struct ASTNODE *node, int depth);

extern struct scope *current_scope;
extern int line;
extern char filename[64];
struct ASTNODE *head, *tail, *ugly_stitch;
int entering_function;
%}

%union {
	struct ASTNODE *node;
	char *ident;
	char char_lit;
	struct string_lit string_lit;
	struct num_lit num_lit;
}

%start translation_unit
%type<node> expr expr_list primary_expr postfix_expr component_select_expr function_call post_inc_expr post_dec_expr sizeof_expr cast_expr unary_expr unary_plus_expr unary_minus_expr log_neg_expr bit_neg_expr pre_inc_expr pre_dec_expr address_expr indirection_expr subscript_expr mult_expr add_expr shift_expr relation_expr equality_expr bit_and_expr bit_xor_expr bit_or_expr log_and_expr log_or_expr assign_expr cond_expr comma_expr compound_literal initializer_list initializer top_level_decl func_def decl_specs declarator compound_statement decl_or_statement decl_or_statement_list statement decl func_def_specifier decl_list expr_statement type_spec func_spec type_qualifier storage_class_spec simple_declarator pointer_declarator array_declarator func_declarator direct_declarator pointer type_qualifier_list constant_expr parameter_type_list enum_type_spec float_type_spec int_type_spec struct_type_spec union_type_spec parameter_list parameter_decl designation designator_list designator complex_type_spec signed_type_spec unsigned_type_spec char_type_spec bool_type_spec void_type_spec labeled_statement conditional_statement iterative_statement switch_statement break_statement continue_statement return_statement goto_statement null_statement if_statement do_statement while_statement for_statement for_expr init_clause named_label init_declarator_list init_declarator enum_type_def enum_type_ref abstract_declarator direct_abstract_declarator identifier_list
%token<ident> IDENT
%token<char_lit> CHARLIT
%token<string_lit> STRING
%token<num_lit> NUMBER

%token TOKEOF 
%token INDSEL PLUSPLUS MINUSMINUS SHL SHR LTEQ GTEQ EQEQ NOTEQ LOGAND LOGOR ELLIPSIS SIZEOF
%token AUTO BREAK CASE CONST CONTINUE DEFAULT DO ENUM EXTERN FOR GOTO INLINE REGISTER RESTRICT RETURN STATIC STRUCT SWITCH TYPEDEF UNION VOID VOLATILE WHILE _BOOL _COMPLEX _IMAGINARY

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

%left IF
%left ELSE

%right UNSIGNED SIGNED SHORT LONG INT CHAR DOUBLE FLOAT
%right '=' PLUSEQ MINUSEQ TIMESEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ XOREQ OREQ
%%

/* Main translation */
translation_unit:	top_level_decl
		|	translation_unit top_level_decl
		;

/* Declarations */
top_level_decl:	decl
	      |	func_def
	      ;

decl:	decl_specs init_declarator_list ';'	{ 
    							struct ASTNODE *decl_spec_node = $1;
							struct ASTNODE *storage_class_node = $1;
							int storage_class = 0;
							int decl_type;
    							while(decl_spec_node) { 
								if ((decl_spec_node->nodetype != AST_STRUCT) &&
									(decl_spec_node->nodetype != AST_UNION) &&
									(decl_spec_node->nodetype != AST_ENUM) &&
									(decl_spec_node->nodetype != AST_SCALAR) &&
									(decl_spec_node->nodetype != AST_FUNC)) {
									decl_spec_node = decl_spec_node->next_node;
								}
								else {
									decl_type = decl_spec_node->nodetype;
									break;
								}
							}
							while(storage_class_node){
								if (storage_class_node->nodetype == AST_STORAGE) {
									storage_class = storage_class_node->storage_class;
									break;
								}
								storage_class_node = storage_class_node->next_node;
							}
 							while($2) {
								struct ASTNODE *node = $2->next_node;
								struct ASTNODE *gen_node;
								int namespace_type, overwrite;
								int ident_type = 0;
								char *symbol_name;
								switch(decl_type) {
									case AST_STRUCT:
										ident_type = ID_STRUCT_TAG;
										break;
									case AST_UNION:
										ident_type = ID_UNION_TAG;
										break;
									case AST_ENUM:
										ident_type = ID_ENUM_TAG;
										break;
									case AST_SCALAR:
										if(!(($2->init_list_tail->nodetype == AST_FUNC) && ($2->init_list_head->next_node->nodetype == AST_FUNC))){
											gen_node = create_node(AST_VAR);
											if(current_scope->scope_type) {
												storage_class = storage_class?storage_class:AUTO;
											}
											else{
												storage_class = storage_class?storage_class:EXTERN;
											}
											$2->init_list_tail->next_node = decl_spec_node;
											gen_node->next_node = $2->init_list_head->next_node;
											gen_node->var_name = $2->init_list_head->ident;
											symbol_name = gen_node->var_name;
											ident_type = ID_VAR;
											namespace_type = NS_OTHER;
											overwrite = 0;
										}
										else {
											gen_node = create_node(AST_FUNC);
											storage_class = storage_class?storage_class:EXTERN;
											gen_node->next_node = decl_spec_node;
											gen_node->func_ident = $2->init_list_head->ident;
											symbol_name = gen_node->func_ident;
											ident_type = ID_FUNC;
											namespace_type = NS_OTHER;
											overwrite = 0;
										}	
										break;
									/*
									case AST_TYPEDEF:
										ident_type = ID_TYPEDEF_NAME;
										break;
									case AST_FUNC:
										ident_type = ID_FUNC;
										break;
									*/
								}
								struct symbol *installed_symbol = install_symbol(symbol_name, filename, line, ident_type, storage_class, namespace_type, current_scope, gen_node, overwrite);
								installed_symbol?print_symbol(installed_symbol):yywarn("Semantic error: Attempted redeclaration of identifier \"%s\"", symbol_name);
								$2 = $2->existing_init_list;	
							}							
						}
    ;

decl_specs:	storage_class_spec decl_specs	{ 
	  						$$ = $1;
							$$->next_node = $2;
	  					}
	  |	storage_class_spec 		{	$$ = $1; $$->next_node = ($$->next_node)?($$->next_node):NULL;	}
	  |	type_spec decl_specs		{ 
	  						$$ = $1;
							$$->next_node = $2;
	  					}
	  |	type_spec 			{	$$ = $1; $$->next_node = ($$->next_node)?($$->next_node):NULL;	}
	  |	type_qualifier decl_specs	{ 
	  						$$ = $1;
							$$->next_node = $2;
	  					}	
	  |	type_qualifier 			{	$$ = $1; $$->next_node = ($$->next_node)?($$->next_node):NULL;	}
	  |	func_spec decl_specs		{ 
	  						$$ = $1;
							$$->next_node = $2;
	  					}
	  |	func_spec			{	$$ = $1; $$->next_node = ($$->next_node)?($$->next_node):NULL;	}
	  ;

init_declarator_list:	init_declarator					{
		    								$$ = create_node(AST_LIST);
										$$->init_list_head = head;
										$$->init_list_tail = tail;
										$$->existing_init_list = NULL;
										$$->next_node = $1;
									}
		    |	init_declarator_list ',' init_declarator	{
										$$ = create_node(AST_LIST);
										$$->init_list_head = head;
										$$->init_list_tail = tail;
										$$->existing_init_list = $1;
										$$->next_node = $3;
									}
		    ;

init_declarator:	declarator
	       |	declarator '=' initializer	{
								$$ = $1;
								// Initialized declarators turned out to be harder than expected!
								// $$ = create_node(AST_ASSIGNMENT);
								// $$->lval = $1;
								// $$->rval = $3;
							}	
	       ;

storage_class_spec:	AUTO		{
		  				$$ = create_node(AST_STORAGE);
						$$->storage_class = AUTO;
						$$->next_node = NULL;
		 			}
		  |	EXTERN		{
		  				$$ = create_node(AST_STORAGE);
						$$->storage_class = EXTERN;
						$$->next_node = NULL;
		 			} 
		  |	REGISTER	{
		  				$$ = create_node(AST_STORAGE);
						$$->storage_class = REGISTER;
						$$->next_node = NULL;
		 			}
		  |	STATIC		{
		  				$$ = create_node(AST_STORAGE);
						$$->storage_class = STATIC;
						$$->next_node = NULL;
		 			}
		  |	TYPEDEF		{	// Not really storage, but whatever
						// We're not implementing this
		  				$$ = create_node(AST_STORAGE);
						$$->storage_class = TYPEDEF;
						$$->next_node = NULL;
		 			}
		  ;

func_spec:	INLINE	{
	      			$$ = create_node(AST_QUALIFIER);
				$$->qualifier = INLINE;
	      		}
	 ;

type_spec:	enum_type_spec
	 |	float_type_spec
	 |	int_type_spec
	 |	struct_type_spec
	/* |	typedef_name */
	 |	union_type_spec
	 |	void_type_spec
	 ;

enum_type_spec:	enum_type_def
	      |	enum_type_ref	
	      ;

enum_type_def:	ENUM enum_tag '{' enum_def_list ',' '}'	{ 
	     							$$ = create_node(AST_ENUM);
								
	     						}
	     |	ENUM '{' enum_def_list ',' '}'		{ 
	     							$$ = create_node(AST_ENUM);
							}
	     |	ENUM enum_tag '{' enum_def_list '}'	{ 
	     							$$ = create_node(AST_ENUM);
							}
	     |	ENUM '{' enum_def_list '}'		{ 
	     							$$ = create_node(AST_ENUM);
							}
	     ;

enum_type_ref:	ENUM enum_tag	{ }
	     ;

enum_tag:	IDENT	{ }
	;

enum_def_list:	enum_constant_def
	     |	enum_def_list ',' enum_constant_def
	     ;

enum_constant_def:	enum_constant
		 |	enum_constant '=' assign_expr
		 ;

enum_constant:	IDENT	{ }
	     ;

float_type_spec:	FLOAT			{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = FLOAT;
							$$->next_node = NULL;
	       					}
	       |	DOUBLE			{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = FLOAT;
							$$->next_node = NULL;
	       					} 
	       |	LONG DOUBLE		{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = DOUBLE;
							$$->next_node = NULL;
	       					}
	       |	complex_type_spec
	       ;

complex_type_spec:	FLOAT _COMPLEX		{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = FLOAT;
							$$->next_node = NULL;
	       					}
		 |	DOUBLE _COMPLEX		{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = FLOAT;
							$$->next_node = NULL;
	       					}
		 |	LONG DOUBLE _COMPLEX	{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = DOUBLE;
							$$->next_node = NULL;
	       					}
		 ;

int_type_spec:	signed_type_spec
	     |	unsigned_type_spec
	     |	char_type_spec
	     |	bool_type_spec
	     ;

signed_type_spec:	SHORT			{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = SHORT;
							$$->next_node = NULL;
	       					}
		|	SHORT INT		{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = SHORT;
							$$->next_node = NULL;
	       					}
		|	SIGNED SHORT		{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = SHORT;
							$$->next_node = NULL;
	       					}
		|	SIGNED SHORT INT	{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = SHORT;
							$$->next_node = NULL;
	       					}
		|	INT			{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = INT;
							$$->next_node = NULL;
	       					}
		|	SIGNED INT		{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = INT;
							$$->next_node = NULL;
	       					}
		|	SIGNED			{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = INT;
							$$->next_node = NULL;
	       					}
		|	LONG			{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = INT;
							$$->next_node = NULL;
	       					}
		|	LONG INT		{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = INT;
							$$->next_node = NULL;
	       					}
		|	SIGNED LONG		{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = INT;
							$$->next_node = NULL;
	       					}
		|	SIGNED LONG INT		{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = LONG;
							$$->next_node = NULL;
	       					}
		|	LONG LONG		{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = LONG;
							$$->next_node = NULL;
	       					}
		|	LONG LONG INT		{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = LONG;
							$$->next_node = NULL;
	       					}
		|	SIGNED LONG LONG 	{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = LONG;
							$$->next_node = NULL;
	       					}
		|	SIGNED LONG LONG INT	{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = LONG;
							$$->next_node = NULL;
	       					}
		;

unsigned_type_spec:	UNSIGNED SHORT 		{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = SHORT;
							$$->next_node = NULL;
	       					}
		  |	UNSIGNED SHORT INT 	{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = SHORT;
							$$->next_node = NULL;
	       					}
		  |	UNSIGNED INT 		{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = SHORT;
							$$->next_node = NULL;
	       					}
		  |	UNSIGNED 		{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = SHORT;
							$$->next_node = NULL;
	       					}
		  |	UNSIGNED LONG 		{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = SHORT;
							$$->next_node = NULL;
	       					}
		  |	UNSIGNED LONG INT 	{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = SHORT;
							$$->next_node = NULL;
	       					}
		  |	UNSIGNED LONG LONG 	{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = SHORT;
							$$->next_node = NULL;
	       					}
		  |	UNSIGNED LONG LONG INT	{ 
	       						$$ = create_node(AST_SCALAR);
							$$->scalar_type = SHORT;
							$$->next_node = NULL;
	       					}
		  ;

char_type_spec:	CHAR		{ 
	       				$$ = create_node(AST_SCALAR);
					$$->scalar_type = CHAR;
					$$->next_node = NULL;
	       			}
	      |	SIGNED CHAR	{ 
	       				$$ = create_node(AST_SCALAR);
					$$->scalar_type = CHAR;
					$$->next_node = NULL;
	       			}
	      |	UNSIGNED CHAR	{ 
	       				$$ = create_node(AST_SCALAR);
					$$->scalar_type = CHAR;
					$$->next_node = NULL;
	       			}
	      ;

bool_type_spec:	_BOOL	{ 
	       			$$ = create_node(AST_SCALAR);
				$$->scalar_type = _BOOL;
	       		}
	      ;

struct_type_spec:	struct_type_def	{ }
		|	struct_type_ref	{ }
		;

struct_type_def:	STRUCT struct_tag '{' field_list '}'	{ }
	       |	STRUCT '{' field_list '}'		{ }
	       ;

struct_tag:	IDENT	{ }
	  ;
		
struct_type_ref:	STRUCT struct_tag	{ }
	       ;

field_list:	component_decl
	  |	field_list component_decl
	  ;

component_decl:	type_spec component_declarator_list ';'
	      ;

component_declarator_list:	component_declarator
			 |	component_declarator_list ',' component_declarator
			 ;

component_declarator:	simple_component
		    |	bit_field
		    ;

simple_component:	declarator
		;

bit_field:	declarator ':' constant_expr 
	 |	':' constant_expr 
	 ;

/* Stub for typedef implementation; we're not dealing with CSG's
typedef_name:	IDENT	{ }
	    ;
*/

union_type_spec:	union_type_def	{ }
	       |	union_type_ref	{ }
	       ;

union_type_def:	UNION union_tag '{' field_list '}'	{ }
	      |	UNION '{' field_list '}'		{ }
	      ;

union_type_ref:	UNION union_tag	{ }
	      ;

union_tag:	IDENT	{ }
	 ;

void_type_spec:	VOID	{ 
	       			$$ = create_node(AST_SCALAR);
				$$->scalar_type = VOID;
	       		}
	      ;

type_name:	decl_specs abstract_declarator
	 |	decl_specs
	 ;

abstract_declarator:	pointer				
		   |	pointer direct_abstract_declarator	{ $$ = $1; }
		   |	direct_abstract_declarator
		   ;

type_qualifier_list:	type_qualifier
		   |	type_qualifier_list type_qualifier
		   ;

direct_abstract_declarator:	'(' abstract_declarator ')'				{ $$ = $2; }
			  |	direct_abstract_declarator '[' constant_expr ']'
			  |	'[' constant_expr ']'					{ }
			  |	direct_abstract_declarator '[' ']'
			  |	'[' ']'							{ }
			  |	direct_abstract_declarator '(' parameter_type_list ')'	
			  |	'(' parameter_type_list ')'				{ }
			  |	direct_abstract_declarator '(' ')'
			  |	'(' ')'							{ }
			  ;

type_qualifier:	CONST		{
	      				$$ = create_node(AST_QUALIFIER);
					$$->qualifier = CONST;
					$$->next_node = NULL;
	      			}
	      |	VOLATILE	{
	      				$$ = create_node(AST_QUALIFIER);
					$$->qualifier = VOLATILE;
					$$->next_node = NULL;
	      			}
	      |	RESTRICT	{
	      				$$ = create_node(AST_QUALIFIER);
					$$->qualifier = RESTRICT;
					$$->next_node = NULL;
	      			}
	      ;

declarator:	pointer_declarator	{ $$=$1; }
	  |	direct_declarator	{ $$=$1; }
	  ;

direct_declarator:	simple_declarator
		 |	'(' declarator ')'	{ $$=$2; }
		 |	func_declarator
		 |	array_declarator
		 ;

simple_declarator:	IDENT	{ 
		 			$$ = create_node(AST_IDENT);
					$$->ident = $1;
					head = tail = $$;
				}
		 ;

pointer_declarator:	pointer direct_declarator	{
		  						$$ = $1;
								$2->next_node = $$;
								// the break in pointers occurs bc of $2 and $$
								for(struct ASTNODE *tn_search = $$; tn_search; tn_search = tn_search->next_node){
									tail = tn_search;
									$$ = tn_search;
								}
		  					}
		  ;

pointer:	'*' type_qualifier_list		{ 
       								$$ = create_node(AST_POINTER);
								$$->pointer_next = NULL;
								$$->next_node = NULL;
						}
       |	'*'				{ 
       								$$ = create_node(AST_POINTER);
								$$->pointer_next = NULL;
								$$->next_node = NULL;
						}
       |	'*' type_qualifier_list	pointer	{ 
       								$$ = create_node(AST_POINTER);
								$$->pointer_next = $3;
								$$->next_node = $3;
						}
       |	'*' pointer			{ 
								$$ = create_node(AST_POINTER);
       								$$->pointer_next = $2;
								$$->next_node = $2;
						}
       ;

array_declarator:/*	direct_declarator '[' constant_expr ']'	{ 
									$$ = create_node(AST_ARRAY);
									$$->array_defined = 1;
									$$->array_size = $3;
									$1->next_node = $$;
									tail = $$;
								}*/
			direct_declarator '[' NUMBER ']'	{
									$$ = create_node(AST_ARRAY);
									$$->array_defined = 1;
									$$->array_size = (int) $3.i_lit;
									$1->next_node = $$;
									tail = $$;
								}
		|	direct_declarator '[' ']'		{ 
									$$ = create_node(AST_ARRAY);
									$$->array_defined = 0;
									$$->array_size = -1;
									$1->next_node = $$;
									tail = $$;
								}
		;

constant_expr:	cond_expr
	     ;

func_declarator:	direct_declarator '(' parameter_type_list ')'	{
	       									$$ = create_node(AST_FUNC);
									}

	       |	direct_declarator '(' identifier_list ')'	{
										$$ = create_node(AST_FUNC);
									}
	       |	direct_declarator '(' ')'			{
										$$ = create_node(AST_FUNC);
										$$->func_symbol_table = NULL;
										$$->arg_no = -1;
										$1->next_node = $$;
										tail = $$;
									}
	       ;

parameter_type_list:	parameter_list
		   |	parameter_list ',' ELLIPSIS	{
								$$ = $1;
							}
		   ;

parameter_list:	parameter_decl
	      |	parameter_list ',' parameter_decl	
	      ;

parameter_decl:	decl_specs declarator
	      |	decl_specs abstract_declarator 
	      ;

identifier_list:	IDENT				{ }
	       |	parameter_list ',' IDENT	{ }
	       ;

initializer:	assign_expr
	   |	'{' initializer_list ',' '}'	{ }
	   |	'{' initializer_list '}'	{ }
	   ;

initializer_list:	initializer
		|	initializer_list ',' initializer
		|	designation initializer
		|	initializer_list ',' designation initializer
		;

designation:	designator_list '='
	   ;

designator_list:	designator
	       |	designator_list designator
	       ;

designator:	'[' constant_expr ']'	{ }
	  |	'.' IDENT		{ }
	  ;

/* FUNCTION DEFINITIONS */
func_def:	func_def_specifier { entering_function = 1; } compound_statement	{ 
												$$ = create_node(AST_FUNC);
												$$->func_body = $3;
												entering_function = 0; 
												print_node($3, 0);
											}
	;

func_def_specifier:	decl_specs declarator decl_list
		  |	decl_specs declarator
		  |	declarator decl_list
		  |	declarator
		  ;

decl_list:	decl
	 |	decl_list decl
	 ;

/* STATEMENTS */
statement:	expr_statement
	 |	labeled_statement
	 |	compound_statement
	 |	conditional_statement
	 |	iterative_statement
	 |	switch_statement
	 |	break_statement
	 |	continue_statement
	 |	return_statement
	 |	goto_statement
	 |	null_statement
	 ;

expr_statement:	expr ';'	{ $$ = $1; }
	      ;

labeled_statement:	label ':' statement	{ 
		 					
		 				}
		 ;

label:	named_label
     |	case_label
     |	default_label
     ;

compound_statement:	'{' 	{ 
		  			int new_scope_type = SCOPE_BLOCK;
					if(entering_function){
						new_scope_type = SCOPE_FUNC;
						entering_function = 0;
					}
		  			current_scope = enter_scope(current_scope, new_scope_type); 
				}  decl_or_statement_list '}'	{ 
									$$ = $3;
									current_scope = escape_scope(current_scope); 
								}
		  |	'{' '}' 			{ }
		  ;

decl_or_statement_list:	decl_or_statement				{
		      								$$ = create_node(AST_STATEMENT_LIST);
										$$->statement_node = $1;
										$$->next_node = NULL;
									}
		      | decl_or_statement_list decl_or_statement	{
										$$ = $1;
										$$->next_node = $2;
									}
		      ;

decl_or_statement:	decl
		 |	statement
		 ;

conditional_statement:	if_statement
		     ;

if_statement:	IF '(' expr ')' statement %prec IF			{ 
	    									$$ = create_node(AST_IF);
										$$->if_condition = $3;
										$$->if_true = $5;
										$$->if_false = NULL;
	    								}
	    |	IF '(' expr ')' statement ELSE statement %prec ELSE	{
	    									$$ = create_node(AST_IF);
										$$->if_condition = $3;
										$$->if_true = $5;
										$$->if_false = $7;
									}
	    ;

iterative_statement:	do_statement
		   |	while_statement
		   |	for_statement
		   ;

do_statement:	DO statement WHILE '(' expr ')' ';'	{  // This is likely wrong, but we can alter this to do better later
	    							$$ = create_node(AST_WHILE);
								$$->while_condition = $5;
								$$->while_true = $2;
							}
	    ;

while_statement:	WHILE '(' expr ')' statement	{ 
	    							$$ = create_node(AST_WHILE);
								$$->while_condition = $3;
								$$->while_true = $5;
							}
	       ;

for_statement:	FOR for_expr statement			{ 
	     							$$ = $2;
								$$->for_true = $3;
	     						}
	     ;

for_expr:	'(' init_clause ';' expr ';' expr ')'	{
								$$ = create_node(AST_FOR);
								$$->for_init = $2;
								$$->for_condition = $4;
								$$->for_iteration = $6;
							}
	|	'(' init_clause ';' expr ';' ')'	{
								$$ = create_node(AST_FOR);
								$$->for_init = $2;
								$$->for_condition = $4;
								$$->for_iteration = NULL;
							}
	|	'(' init_clause ';' ';' expr ')'	{
								$$ = create_node(AST_FOR);
								$$->for_init = $2;
								$$->for_condition = NULL;
								$$->for_iteration = $5;
							}
	|	'(' init_clause ';' ';' ')'		{
								$$ = create_node(AST_FOR);
								$$->for_init = $2;
								$$->for_condition = NULL;
								$$->for_iteration = NULL;
							}
	|	'(' ';' expr ';' expr ')'		{
								$$ = create_node(AST_FOR);
								$$->for_init = NULL;
								$$->for_condition = $3;
								$$->for_iteration = $5;
							}
	|	'(' ';' expr ';' ')'			{
								$$ = create_node(AST_FOR);
								$$->for_init = NULL;
								$$->for_condition = $3;
								$$->for_iteration = NULL;
							}
	|	'(' ';' ';' expr ')'			{
								$$ = create_node(AST_FOR);
								$$->for_init = NULL;
								$$->for_condition = NULL;
								$$->for_iteration = $4;
							}
	|	'(' ';' ';' ')' 			{
								$$ = create_node(AST_FOR);
								$$->for_init = NULL;
								$$->for_condition = NULL;
								$$->for_iteration = NULL; 
							}
	;

init_clause:	expr
	   |	decl_specs init_declarator_list
	   ;

switch_statement:	SWITCH '(' expr ')' statement	{ }
		;

case_label:	CASE constant_expr
	  ;

default_label:	DEFAULT
	     ;

break_statement:	BREAK ';'	{ }
	       ;

continue_statement:	CONTINUE ';'	{ }
		  ;

return_statement:	RETURN expr ';'	{ 
						$$ = create_node(AST_RETURN);
						$$->return_value = $2;
					}
		|	RETURN ';'	{
						$$ = create_node(AST_RETURN);
						$$->return_value = NULL;
					}
		;

goto_statement:	GOTO named_label ';'	{ 
	      					$$ = create_node(AST_GOTO);
						$$->goto_label = $2;
					}
	      ;

named_label:	IDENT			{
	   					$$ = create_node(AST_IDENT);
						$$->ident = $1;
					}
	   ;

null_statement:	';'	{ }
	      ;

/* EXPRESSIONS */
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

compound_literal:	'(' type_name ')' '{' initializer_list ',' '}'	{ }
		|	'(' type_name ')' '{' initializer_list '}'	{ }
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

struct ASTNODE *create_node(int nodetype) {
	struct ASTNODE *newnode = malloc(sizeof(struct ASTNODE));
	if(!newnode) {
		yyerror("Fatal Error: Failed to allocate memory for new AST node");
		exit(-1);
	}
	newnode->nodetype = nodetype;
	return newnode;
}

void populate_num_node(struct ASTNODE *node, struct num_lit *number){
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
