#ifndef SYM_TAB
#define SYM_TAB

enum ident_type {
	ID_VAR=0,
	ID_FUNC,
	ID_STRUCT_TAG,
	ID_STRUCT_MEMBER,
	ID_UNION_TAG,
	ID_UNION_MEMBER,
	ID_ENUM_TAG,
	ID_ENUM_CONSTANT,
	ID_STATEMENT_LABEL,
	ID_TYPEDEF_NAME
};

enum namespace_type {
	NS_LABEL=0,
	NS_TAGS,
	NS_STRUCT_UNION,
	NS_OTHER
};

enum scope_types {
	SCOPE_GLOBAL=0,
	SCOPE_FUNC,
	SCOPE_BLOCK,
	SCOPE_PROTO
};

struct scope {
	int scope_type;
	struct scope *parent_scope;
	struct symbol *start_symbol, *end_symbol;
};

struct symbol {
	char *symbol_name;
	char *filename;
	int lineno;
	int ident_type;
	int storage_class;
	int namespace_type;
	struct ASTNODE* node;
	struct scope *scope;
	struct symbol *previous_symbol, *next_symbol;
};

struct symbol *install_symbol(char *symbol_name, char *filename, int lineno, int ident_type, int storage_class, int namespace_type, struct scope *scope, struct ASTNODE *node, int overwrite);
struct symbol *get_symbol(char *symbol_name, struct scope *scope, int namespace_type); 
struct symbol *find_symbol(char *symbol_name, struct scope *base_scope, int namespace_type); 
void print_symbol(struct symbol *sp); 

struct scope *enter_scope(struct scope *parent_scope, int scope_type);
struct scope *escape_scope(struct scope *current_scope);
struct scope *remove_scope(struct scope *current_scope);

struct scope *current_scope; 

#endif
