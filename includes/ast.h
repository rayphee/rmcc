#ifndef AST
#define AST
enum astnode_type {
	/* Expression stuff */
	AST_BINOP=0,
	AST_UNARYOP,
	AST_TERNOP,
	AST_CASTOP,
	AST_ARGLIST,
	AST_IDENT,
	AST_CHARLIT,
	AST_STRINGLIT,
	AST_NUM,
	/* Type stuff */
	AST_SCALAR,
	AST_ARRAY,
	AST_STRUCT,
	AST_UNION,
	AST_ENUM,
	AST_MEMBER,
	AST_POINTER,
	AST_FUNC,
	AST_VAR,
	AST_STORAGE,
	AST_QUALIFIER,
	/* Statement stuff */
	AST_IF,
	AST_WHILE,
	AST_FOR,
	AST_RETURN,
	AST_GOTO,
	AST_ASSIGNMENT,
	AST_BLOCK,
	AST_LIST,
	AST_LABELED_STATEMENT,
	AST_STATEMENT_LIST,
	AST_GENERIC
};

/* Operations */
struct astnode_unaryop {
	int ast_unaryop;
	struct ASTNODE *single_op;
};

struct astnode_binop {
	int ast_binop;
	struct ASTNODE *left_binop, *right_binop;
};

struct astnode_ternop {
	struct ASTNODE *left_ternop, *middle_ternop, *right_ternop;
};

struct astnode_castop {
	struct ASTNODE *single_cast, *cast_type;
};

/* Functions */
struct astnode_func {
	int arg_no;
	int func_is_inline;
	char *func_ident;
	struct ASTNODE *func_name, *args, *return_type, *func_body;
	struct scope *func_symbol_table;
};

struct astnode_arglist {
	int expr_no;
	struct ASTNODE *existing_list, *new_expr;
};

/* Idents and Literals */
struct astnode_ident {
	char *ident;
};

struct astnode_charlit {
	char char_lit;
};

struct astnode_stringlit {
	char *string_lit;
	int string_size;
};

struct astnode_num {
	char sign_and_precision;
	union {
		int i_lit;
		unsigned int i_lit_u;
		long l_lit;
		unsigned long l_lit_u;
		long long ll_lit;
		unsigned long long ll_lit_u;
		float f_lit;
		double d_lit;
		long double ld_lit;
	};
};

/* Variables, Members, Structs */
struct astnode_scalar {
	int scalar_type;
};

struct astnode_member {
	char *member_name;
	struct ASTNODE *member_op;
};

struct astnode_array {
	int array_defined;
	int array_size;
	/*struct ASTNODE *array_size;*/
};

struct astnode_struct {
	char *struct_name;
	struct scope *struct_symbol_table;
};

struct astnode_union {
	char *union_name;
	struct scope *union_symbol_table;
};

struct astnode_enum {
	char *enum_name;
	struct ASTNODE *enum_defs;
};

struct astnode_pointer {
	struct ASTNODE *pointer_next, *pointer_back;
};

struct astnode_var {
	char *var_name;
	struct ASTNODE *var_type;
};

struct astnode_storage_class {
	int storage_class;
};

struct astnode_qualifier {
	int qualifier;
};

/* Statements */
struct astnode_if {
	struct ASTNODE *if_condition, *if_true, *if_false;
};

struct astnode_while {
	struct ASTNODE *while_condition, *while_true;
};

struct astnode_for {
	struct ASTNODE *for_init, *for_condition, *for_iteration, *for_true;
};

struct astnode_return {
	struct ASTNODE *return_value;
};

struct astnode_goto {
	char *goto_label_name;
	struct ASTNODE *goto_label;
};

struct astnode_labeled_statement {
	char *labeled_name;
	struct ASTNODE *labeled_statement;
};

struct astnode_assignment {
	struct ASTNODE *lval, *rval;
};

struct astnode_block {
	struct ASTNODE *block_statements;
};

struct astnode_init_list {
	struct ASTNODE *existing_init_list, *init_list_head, *init_list_tail;
};

struct astnode_statement_list {
	struct ASTNODE *statement_node;
};

struct ASTNODE {
	int nodetype;
	struct ASTNODE *next_node;
	union {
		struct astnode_binop;
		struct astnode_unaryop;
		struct astnode_ternop;
		struct astnode_castop;
		struct astnode_func;
		struct astnode_arglist;
		struct astnode_ident;
		struct astnode_charlit;
		struct astnode_stringlit;
		struct astnode_num;
		struct astnode_scalar;
		struct astnode_member; 
		struct astnode_array;
		struct astnode_struct;
		struct astnode_union;
		struct astnode_enum;
		struct astnode_pointer;
		struct astnode_var;
		struct astnode_storage_class;
		struct astnode_qualifier;
		struct astnode_if;
		struct astnode_while;
		struct astnode_for;
		struct astnode_return;
		struct astnode_goto;
		struct astnode_labeled_statement;
		struct astnode_assignment;
		struct astnode_block;
		struct astnode_init_list;
		struct astnode_statement_list;
	};
};
#endif
