#include <stdio.h>
#include <stdlib.h>
#include <yystype.h>
#include <string.h>
#include <ast.h>
#include <symtab.h>
#include "y.tab.h"


struct symbol *install_symbol(char *symbol_name, char *filename, int lineno, int ident_type, int storage_class, int namespace_type, struct scope *scope, struct ASTNODE *node, int overwrite) {
	struct symbol *new_symbol = get_symbol(symbol_name, scope, namespace_type);
	int replace = 0;
	if(new_symbol) {
		replace = 1;
		if(!overwrite) {
			return NULL;
		}
	}
	else {
		new_symbol = (struct symbol *) malloc(sizeof(struct symbol));
	}

	// Take care of the new symbol
	new_symbol->symbol_name = symbol_name;
	new_symbol->filename = filename;
	new_symbol->lineno = lineno;
	new_symbol->ident_type = ident_type;
	new_symbol->storage_class = storage_class;
	new_symbol->namespace_type = namespace_type;
	new_symbol->node = node;
	new_symbol->scope = scope;
	
	if(!replace) {
		// Add last node on symbol table as previous node
		new_symbol->previous_symbol = scope->end_symbol;
		new_symbol->next_symbol = NULL;
		
		// If this is a new scope
		if(!(scope->start_symbol)) {
			scope->start_symbol = new_symbol;
		}

		// Add the new node as the next node for the former end node
		if(scope->end_symbol) {
			(scope->end_symbol)->next_symbol = new_symbol;
		}

		// Make the end symbol the new symbol
		scope->end_symbol = new_symbol;
	}
	return new_symbol;
}

struct symbol *get_symbol(char *symbol_name, struct scope *scope, int namespace_type) {
	if(!scope) return NULL;
	for(struct symbol *sp=scope->start_symbol;sp;sp=sp->next_symbol) {
		if(!strcmp(symbol_name, sp->symbol_name)) {
			if(sp->namespace_type == namespace_type) {
				return sp;
			}
		}
	}
	return NULL;
}

struct symbol *find_symbol(char *symbol_name, struct scope *base_scope, int namespace_type) {
	struct symbol *found_symbol;
	for(struct scope *scope=base_scope;scope;scope=scope->parent_scope) {
		found_symbol = get_symbol(symbol_name, scope, namespace_type);
		if(found_symbol) return found_symbol;
	}
	return NULL;
}

void print_symbol(struct symbol *sp) {
	fprintf(stdout, "\"%s\" is declared at %s:%d (scope: ", sp->symbol_name, sp->filename, sp->lineno);
	switch(sp->scope->scope_type){
		case SCOPE_GLOBAL:
			fprintf(stdout, "global");
			break;
		case SCOPE_FUNC:
			fprintf(stdout, "function");
			break;
		case SCOPE_BLOCK:
			fprintf(stdout, "block");
			break;
		case SCOPE_PROTO:
			fprintf(stdout, "prototype");
			break;
	}
	fprintf(stdout, ") as a ");
	switch(sp->ident_type){
		case ID_FUNC:
			fprintf(stdout, "function "); 
			break;
		case ID_VAR:
			fprintf(stdout, "variable "); 
			break;
	}
	switch(sp->storage_class) {
		case REGISTER:
			fprintf(stdout, "with storage class REGISTER");
			break;
		case STATIC:
			fprintf(stdout, "with storage class STATIC");
			break;
		case EXTERN:
			fprintf(stdout, "with storage class EXTERN");
			break;
		case AUTO:
		default:
			fprintf(stdout, "with storage class AUTO");
			break;
	}
	int tab_count = 0;
	fprintf(stdout, " with type:\n");
	for(struct ASTNODE* node = sp->node; node; node = node->next_node) {
		for(int i=0; i<tab_count; i++) {
			fprintf(stdout, "  ");
		}
		switch(node->nodetype){
			case AST_POINTER:
				fprintf(stdout, "pointer to \n");
				for(struct ASTNODE* ptr_node = node->pointer_next; ptr_node; ptr_node = ptr_node->pointer_next) {
					if(ptr_node->nodetype == AST_POINTER) {
						tab_count++;
						for(int i=0; i<tab_count; i++) {
							fprintf(stdout, "  ");
						}
						fprintf(stdout, "pointer to \n");
					}
					else break;
				}
				// */
				break;
			case AST_ARRAY:
				fprintf(stdout, "array of %d elements of type\n", node->array_size);
				break;
			case AST_SCALAR:
				switch(node->scalar_type){
					case SHORT:
						fprintf(stdout, "short\n");
						break;
					case INT:
						fprintf(stdout, "int\n");
						break;
					case LONG:
						fprintf(stdout, "long\n");
						break;
					case FLOAT:
						fprintf(stdout, "float\n");
						break;
					case DOUBLE:
						fprintf(stdout, "double\n");
						break;
					case VOID:
						fprintf(stdout, "void\n");
						break;
					case CHAR:
						fprintf(stdout, "char\n");
						break;
				}
				break;
			default:
				break;

		}
		tab_count++;
	}
	fprintf(stdout, "\n");
	return;
}

struct scope *enter_scope(struct scope *parent_scope, int scope_type) {
	struct scope *new_scope;
	new_scope = (struct scope *) malloc(sizeof(struct scope));
	new_scope->parent_scope = parent_scope;
	new_scope->scope_type = scope_type;
	new_scope->start_symbol = NULL;
	new_scope->end_symbol = NULL;
	return new_scope;
}

struct scope *escape_scope(struct scope *current_scope) {
	if(!(current_scope->scope_type)) return current_scope; // this means we're in global scope; we can't escape!
	struct scope *new_scope;
	new_scope = current_scope->parent_scope;
	return new_scope;
}

struct scope *remove_scope(struct scope *current_scope) {
	if(!(current_scope->scope_type)) return current_scope;
	struct scope *new_scope;
	new_scope = current_scope->parent_scope;
	for(struct symbol *sym=new_scope->start_symbol; sym;sym=sym->next_symbol) {
		free(sym);
	}
	free(current_scope);
	return new_scope;
}

