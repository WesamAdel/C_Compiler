#include "SymTab.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*-------------- scope stack code ------------------*/

void init_stack(struct stack *s){
	s->top = -1;
}

int is_stack_empty(struct stack *s){
	return (s->top == -1) ? 1 : 0;
}

void stack_push(struct stack *s, int scope){
	s->top += 1;
	s->arr[s->top] = scope;
}

void stack_pop(struct stack *s){
	if(! is_stack_empty(s))
		s->top -=1;
}

int stack_top(struct stack *s){
	return is_stack_empty(s) ? -1 : s->arr[s->top];
}

/*-------------- Scope Tree Functions --------------*/

// initialize a scope tree.
void init_scope_tree(struct scope_tree *st, int id){
	(*st).scope_ID = id;
	(*st).nxt_child = 0;
}

// adding a child to a scope tree.
int add_child(struct scope_tree *st, int parent_scope, int child_scope){
	if (st == NULL)
		return NULL_ERR; //error (operation failed)
	if (parent_scope==child_scope) return MISS_PC;

	if (st->scope_ID == parent_scope){ // found_parent
		int i  = 0;
		// child already exists?
		for (i = 0; i < st->nxt_child; ++i){ // yes.
			if(st->children[i]->scope_ID == child_scope){
				return SCOPE_FOUND; // found a child for this parent with the same scope.
			}
		}
		// child does not exist.
		st->children[st->nxt_child] = (struct scope_tree*)malloc(sizeof(struct scope_tree*));
		init_scope_tree(st->children[st->nxt_child], child_scope);
		st->nxt_child = st->nxt_child + 1;
		return SUCCESS; // success.
	}

	// recurse to children if parent is not found.
	int i = 0;
	for (i = 0; i < st->nxt_child; ++i){
		if(add_child(st->children[i], parent_scope, child_scope) == 1)
			return 1;
	}
	return MISS_PC; // child or parent not found.
}

// check if a node is parent to another one.
int is_parent(struct scope_tree *st, int parent_scope, int child_scope){

	if (st == NULL)
		return NULL_ERR; //error

	if(child_scope==parent_scope)
		return SUCCESS;

	if (st->scope_ID == parent_scope){ // found_parent
		int i;
		for (i = 0; i < st->nxt_child; i++){
			if(st->children[i]->scope_ID == child_scope)
				return SUCCESS; // this node is a parent for the child node.

			int t = is_parent(st->children[i], st->children[i]->scope_ID, child_scope);
			if(t == 1)
				return SUCCESS;
		}
		return FAILURE; // parent node is not a parent for the provided child node.
	}
	int i = 0;
	for (i = 0; i < st->nxt_child; ++i){
		if(is_parent(st->children[i], parent_scope, child_scope) == 1)
			return SUCCESS;
	}
	return FAILURE; // parent does not exist or it is not a parent.
}


/*-------------- Symbol Table Functions --------------*/


/* print every symbol with its details */
void print_table(struct sym_tab *table){
	int i=0;
	for (; i < table->nxt_symbol; i+=1)
		printf("%s %d %d %d", table->symbols[i].name, table->symbols[i].type, table->symbols[i].scope_ID, table->symbols[i].const_var);
}

void init_table(struct sym_tab *table){
	table->nxt_symbol=0;
}

// adding a new symbol
int add_sym(struct symbol s, struct sym_tab *table, struct scope_tree *st){
	int indx = find_sym(&s.name, s.scope_ID, table);

	if (indx >= 0){
		return FAILURE; // redifinition error.
	}

	else{ // check if there is a parent with same name.
		int i = find_sym2(s.name, s.scope_ID, table, st);
		if (i>= 0) return WARNING;
	}
	// add a new node.
	table->symbols[table->nxt_symbol] = s;
	table->nxt_symbol = table->nxt_symbol + 1;
	return SUCCESS; // success.
}

// linearly search the symbol table.
int find_sym(char* name, int scope_ID, struct sym_tab *table){
	int i;
	for(i=0; i<table->nxt_symbol; ++i){
		struct symbol temp = table->symbols[i];
		if(strcmp(temp.name, name) == 0 && temp.scope_ID == scope_ID)
			return i;
	}
	return NOT_FOUND; // not found.
}

int find_sym2(char* name, int scope_ID, struct sym_tab *table, struct scope_tree *st){
	int i;
	for(i=0; i<table->nxt_symbol; ++i){
		struct symbol temp = table->symbols[i];
		if(strcmp(temp.name, name) == 0){
			if(is_parent(st, temp.scope_ID, scope_ID) == SUCCESS)
				return i; // redifinition error.
		}
	}
	return NOT_FOUND;
}

// seach then return type.
enum datatype get_type(char* name, int scope_ID, struct sym_tab *table, struct scope_tree *st){
	int indx = find_sym(name, scope_ID, table);
	if(indx >= 0){
		return (table->symbols[indx].type == numeric)?1:0 ;
	}
	indx = find_sym2(name, scope_ID, table, st);
	if(indx >= 0){
		return (table->symbols[indx].type == numeric)?1:0 ;
	}
	return -1;
}

int is_const_set(char* name, int scope_ID, struct sym_tab *table, struct scope_tree *st){
	int indx = find_sym(name, scope_ID, table);
	if(indx >= 0){
		return table->symbols[indx].is_assigned;
	}
	indx = find_sym2(name, scope_ID, table, st);
	if(indx >= 0){
		return table->symbols[indx].is_assigned;
	}
	return -1;
}


void write_sym_tab(FILE *F, struct sym_tab *table){
	int i;
	char*A = "integer";
	char*B = "float";
	char*C = "boolean";
	char*D = "char";
	for (i = 0; i < table->nxt_symbol; i = i + 1){
		char*tmp = (char*)malloc(sizeof(char*));
		if (table->symbols[i].type == integer) tmp = "integer\0";
		if (table->symbols[i].type == numeric) tmp = "float\0";
		if (table->symbols[i].type == boolean) tmp = "boolean\0";
		if (table->symbols[i].type == character) tmp = "char\0";

		char *tmp2 = (char*)malloc(sizeof(char*));
		if (table->symbols[i].const_var == 1) tmp2= "Yes\0";
		if (table->symbols[i].const_var == 0) tmp2 = "No\0";

		fprintf(F, "%s\t%s\t%d\t%s\n", table->symbols[i].name, tmp, table->symbols[i].scope_ID, tmp2);
	}
}
