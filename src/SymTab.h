#ifndef SYMTAB_H
#define SYMTAB_H

#define SUCCESS 	1
#define FAILURE 	-1
#define NOT_FOUND 	-2
#define NULL_ERR 	-3
#define SCOPE_FOUND -4
#define MISS_PC		-5

#define WARNING     -6

enum datatype {integer, numeric, boolean, character, no_type};

typedef struct stack{
    int arr[500];
    int top;
}a_stack;


typedef struct symbol{
    char name[100];
    enum datatype type;
    int scope_ID;
    int const_var;
    int is_assigned;
}sym;


struct sym_tab{
	struct symbol symbols[100];
	int nxt_symbol;
};



struct scope_tree{
	int scope_ID;
	int nxt_child;
	struct scope_tree *children[100];
};


#endif