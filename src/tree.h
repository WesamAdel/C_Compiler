#define true 1
#define false 0

#define MAX_VAR_NUM 100 /* maximum numbers of symbols (initial implementation) */

typedef int bool;
extern FILE *error, *warn, *output;

#include "SymTab.h"

char* datatype_name [4] = {"INT", "FLOAT", "BOOL", "CHAR"};

enum arthm_logic_operators {plus, minus, star, over, not, SHL, SHR, GT, LT, GTE, LTE, xor, EQ, EQEQ, NE, and, or};

struct scope_tree a_scope_tree;
struct sym_tab a_symbol_table;

int cur_reg_id;
int cur_label_id;
int max_scope;


/* helper function for  char * allocation */
char* alloc_str(char *Str)
{
    size_t len = strlen( Str );
    char *StrResult = malloc( len + 1 );
    StrResult[len] = '\0';
    strcpy(StrResult, Str);
    return StrResult;
}


/*  ------------------------------------- Parse Tree Code ----------------------------------------- */

/* each node in the parse tree has type, depending on the rules*/
enum treetype {operator_node, number_node, variable_node, f_number_node, alloc,
               char_node, bool_node, list_node, if_node, if_else_node, while_node,
               do_while_node, for_node, break_node, default_node, case_node, switch_node,
               uni_operator_node, compound_stmt_node, const_alloc_node
              };



/* treenode definition */
 typedef struct tree {
   enum treetype nodetype; // each node has a type
   union { // for each node type, it holds different data
     struct {struct tree *left, *right; int operator;} an_operator; // for operator node
     int a_number; // for integer values
     struct {struct tree *left, *right; enum datatype type;} an_alloc; // a decleration statement
     struct {char* name; enum datatype type;} a_variable;   // for identifiers, variable name: string
     float f_number; //floating point number
     bool a_bool; // boolean value: true/false
     char a_char;  // for character values
     struct {int child_cnt; struct tree* children[10000];} list_of_nodes; // for a list of nodes
     struct {struct tree * expression, * stmt;} an_if; // for if_staement
     struct {struct tree * expression, * stmt_1, *stmt_2;} an_if_else; // for if_else_staement
     struct {struct tree * expression, * stmt;} a_while; // for while_loop
     struct {struct tree * expression, * stmt;} a_do_while; // for do_while_loop
     struct {struct tree* exp_1, * exp_2,  * exp_3, * stmt;} a_for; // for for loop
     struct {struct tree* expression, *stmt;} a_case; // for case statement (in switch)
     struct {struct tree* expression; struct {int child_cnt; struct tree* children[10000];} stmt;} a_switch; // for a switch(exp){statement}
     struct {struct tree *stmt;} a_default;// default statement (in switch)
     struct {struct tree * child; int operator;}a_uni_operator;
     struct {struct tree * stmt;} a_compund_stmt; // compund statement { list of nodes }
     struct {struct tree *left, *right; enum datatype type;} a_const_alloc_node;
   } body;
 } tree;

/* each function makes a specific type node, returns poiter to it*/

static tree *make_const(tree *l, tree*r, enum datatype type){
    tree *result = (tree*) malloc (sizeof(tree));
    result->nodetype = const_alloc_node;
    result->body.a_const_alloc_node.left = l;
    result->body.a_const_alloc_node.type = type;
    result->body.a_const_alloc_node.right = r;
    return result;
}

static tree *make_compund_stmt(tree *stmt){
    if(stmt == NULL)
        return NULL;

    tree *result= (tree*) malloc (sizeof(tree));
    result->nodetype = compound_stmt_node;
    result->body.a_compund_stmt.stmt = stmt;
    return result;
}

static tree* make_uni_operator(tree *child, int o) {
  tree *result= (tree*) malloc (sizeof(tree));
  result->nodetype = uni_operator_node;
  result->body.a_uni_operator.child = child;
  result->body.a_uni_operator.operator = o;
  return result;
}


static tree *make_switch(tree* expression, tree* stmt){
    tree *result= (tree*) malloc (sizeof(tree));
    result->nodetype = switch_node;
    result->body.a_switch.expression  = expression;
    result->body.a_switch.stmt.child_cnt =  (stmt)->body.list_of_nodes.child_cnt;
    memcpy(result->body.a_switch.stmt.children, (stmt)->body.list_of_nodes.children, sizeof (stmt)->body.list_of_nodes.children) ;
    return result;
}

static tree *make_case(tree* expression, tree* stmt){
    tree *result= (tree*) malloc (sizeof(tree));
    result->nodetype = case_node;
    result->body.a_case.expression  = expression;
    result->body.a_case.stmt =  stmt;
    return result;
}

static tree *make_default(tree* stmt){
    tree *result= (tree*) malloc (sizeof(tree));
    result->nodetype = default_node;
    result->body.a_default.stmt =  stmt;
    return result;
}

static tree *make_break(){
    tree *result= (tree*) malloc (sizeof(tree));
    result->nodetype = break_node;
    return result;
}


 static tree *make_for(tree* exp_1, tree* exp_2, tree* exp_3, tree* stmt){
     tree *result= (tree*) malloc (sizeof(tree));
     result->nodetype = for_node;
     result->body.a_for.exp_1  = exp_1;
     result->body.a_for.exp_2  = exp_2;
     result->body.a_for.exp_3  = exp_3;
     result->body.a_for.stmt =  stmt;
     return result;
 }

 static tree *make_do_while(tree *expression, tree *statement){
     tree *result= (tree*) malloc (sizeof(tree));
     result->nodetype =  do_while_node;
     result->body.a_do_while.expression = expression;
     result->body.a_do_while.stmt = statement;
     return result;
 }

 static tree *make_while(tree *expression, tree * statement){
     tree *result= (tree*) malloc (sizeof(tree));
     result->nodetype = while_node;
     result->body.a_while.expression = expression;
     result->body.a_while.stmt = statement;
     return result;
 }

 static tree *make_if(tree *expression, tree * statement){
     tree *result= (tree*) malloc (sizeof(tree));
     result->nodetype = if_node;
     result->body.an_if.expression = expression;
     result->body.an_if.stmt = statement;
     return result;
 }

 static tree *make_if_else(tree *expression, tree * statement_1, tree * statement_2){
     tree *result= (tree*) malloc (sizeof(tree));
     result->nodetype = if_else_node;
     result->body.an_if_else.expression = expression;
     result->body.an_if_else.stmt_1 = statement_1;
     result->body.an_if_else.stmt_2 = statement_2;
     return result;
 }

 static tree *make_list(tree *child){
	 tree *result = (tree*)malloc(sizeof(tree));
     result->nodetype= list_node;
	 result->body.list_of_nodes.child_cnt = 0;
     result->body.list_of_nodes.children[result->body.list_of_nodes.child_cnt] = child;
     result->body.list_of_nodes.child_cnt = 1;
     return result;
 }

 static tree *add_child_to_list(tree *parent, tree *child){
     parent->body.list_of_nodes.children[parent->body.list_of_nodes.child_cnt] = child;
     parent->body.list_of_nodes.child_cnt = parent->body.list_of_nodes.child_cnt + 1;
     return  parent;
 }

// 21 75 238

 static tree *make_operator (tree *l, int o, tree *r){
   tree *result= (tree*) malloc (sizeof(tree));
   result->nodetype = operator_node;
   result->body.an_operator.left= l;
   result->body.an_operator.operator= o;
   result->body.an_operator.right= r;
   return result;
 }

 static tree *make_bool (bool b){
     tree *result= (tree*) malloc (sizeof(tree));
     result->nodetype = bool_node;
     result->body.a_bool= b;
     return result;
 }

 static tree *make_char (char c){
     tree *result= (tree*) malloc (sizeof(tree));
     result->nodetype= char_node;
     result->body.a_char= c;
     return result;
 }

 static tree *make_number (int n) {
   tree *result= (tree*) malloc (sizeof(tree));
   result->nodetype= number_node;
   result->body.a_number= n;
   return result;
 }


  static tree *make_f_number (float n) {
    tree *result= (tree*) malloc (sizeof(tree));
    result->nodetype= f_number_node;
    result->body.f_number= n;
    return result;
  }

  static tree *make_variable (char* v) {
    tree *result= (tree*) malloc (sizeof(tree));
    result->nodetype= variable_node;
    result->body.a_variable.name = alloc_str(v);
    //result->body.a_variable.type = get_type(v);
    return result;
  }

  static tree *make_alloc(tree *l, tree*r, enum datatype type){
    /*
        if r == null, no assignment
        else r is an operator node, its operator is '='
    */

    tree *result = (tree*) malloc (sizeof(tree));
    result->nodetype = alloc;
    result->body.an_alloc.left= l;
    result->body.an_alloc.type = type;
    result->body.an_alloc.right = r;
	return result;

  }

 /* ----------------------------- Travers the parse tree to get three address code (TAC)------------------------------- */

 typedef struct ret_val{ // return value of the node, val: what node prints in the code generation,
     char val[100];
     int f; // indicates if floating point operation, cause we may have different operation for floating point data eg addf vs. add
 }ret;

 /*
    function that traverses the tree, generate the code bottom up
 */
 static struct ret_val get_TAC(tree *t, int level, int cur_scope_id, int parent_scope_id){
     /* base case: if terminal node, return variable name / number
        else recurse for left and right children with incremented tmp_id to get their data; return cure Register number;
             if final  assignment statement, store the value
    */
    struct ret_val ret;
    ret.val[0] = '\0';

    if(t == NULL)
        return ret;

    /* Case of terminal nodes */
    if(t->nodetype == variable_node){
        // ADD LOAD operation
        strcpy(ret.val, t->body.a_variable.name);
        ret.f = get_type(t->body.a_variable.name, cur_scope_id, &a_symbol_table, &a_scope_tree);
        return ret;
    }

    if(t->nodetype == number_node){
        sprintf(ret.val, "%d", t->body.a_number);
        ret.f= 0;
        return ret;
    }

    if(t->nodetype == bool_node){
        char * T = "true";
        char * F = "false";
        strcpy(ret.val, (t->body.a_bool)?T:F);
        ret.f= 0;
        return ret;
    }

    if(t->nodetype == char_node){
        strcat(ret.val, "\'");
        char tmp[20];
        sprintf(tmp, "%c", t->body.a_char);
        strcat(ret.val, tmp);
        strcat(ret.val, "\'");
        ret.f= 0;
        return ret;
    }

    if(t->nodetype == f_number_node){
        sprintf(ret.val, "%f", t->body.f_number);
        ret.f = 1;
        return ret;
    }

    /* ------------------- case of non-terminal nodes -----------------------------*/

    if(t->nodetype == uni_operator_node){
        struct ret_val child = get_TAC(t->body.a_uni_operator.child, level+1, cur_scope_id, parent_scope_id);
        int is_float = child.f;
        char instruction[10] = {'\0'};
        int c = t->body.a_uni_operator.operator;

        strcpy(instruction, (c == minus)? "NEG" : "NOT");

        fprintf(output, "%s R%d, %s\n", instruction, cur_reg_id, child.val);

        struct ret_val ret;
        char tmp [100];
        sprintf(tmp, "%d", cur_reg_id);
        strcat(ret.val, "R");
        strcat(ret.val, tmp);
        ret.f = is_float;
        cur_reg_id += 1;

        return ret;
    }



    if(t->nodetype == operator_node){
        /*
            get types of the operands,
            decide operation on types, operator, if any is float return float is true to handle floating point operations
        */
        struct ret_val left_child = get_TAC(t->body.an_operator.left, level+1, cur_scope_id, parent_scope_id),
                      right_child = get_TAC(t->body.an_operator.right, level+1, cur_scope_id, parent_scope_id);

        int is_float = (left_child.f != -1 && right_child.f != -1)? (left_child.f + right_child.f) : -1;

        char instruction[10] = {'\0'};
        int c = t->body.an_operator.operator;

        if(c == EQEQ || c == GT || c == GTE || c ==  LT || c == LTE || c == and || c == or || c == xor)
            is_float = 0;
        switch(c){
            case plus:
                strcpy(instruction, "add");
            break;
            case minus:
                strcpy(instruction, "sub");
            break;
            case star:
                strcpy(instruction, "mul");
            break;
            case over:
                strcpy(instruction, "div");
            break;
            case EQ:
                strcpy(instruction, "stor");
            break;
            case SHL:
                strcpy(instruction, "SHL");
            break;
            case SHR:
                strcpy(instruction, "SHR");
            break;
            case GT:
                strcpy(instruction, "GT");
            break;
            case LT:
                strcpy(instruction, "LT");
            break;
            case GTE:
                strcpy(instruction, "GTE");
            break;
            case LTE:
                strcpy(instruction, "LTE");
            case EQEQ:
                strcpy(instruction, "EQ");
            break;
            case NE:
                strcpy(instruction, "NE");
            break;
            case xor:
                strcpy(instruction, "xor");
            break;
            case and:
                strcpy(instruction, "and");
            break;
            case or:
                strcpy(instruction, "or");
            break;
        }


        /* output code for this non terminal node */
        if(c == EQ){
            fprintf(output, "%s %s, %s\n", instruction, left_child.val, right_child.val); // store operation, as the lhs is always an identifier.
            if(level > 0){ // intermediate assignment statement, store then load in an intermediate register
                strcpy(instruction, "mov");
                fprintf(output, "%s R%d, %s\n", instruction, cur_reg_id, left_child.val);
            }

            /* check if variable does not exist */
            int find_sym_msg = find_sym(left_child.val, cur_scope_id, &a_symbol_table);
            int find_sym_msg2 =find_sym2(left_child.val, cur_scope_id, &a_symbol_table, &a_scope_tree);

            if(find_sym_msg == NOT_FOUND && find_sym_msg2 == NOT_FOUND)
                fprintf(error, "undeclared indetifier \'%s\'\n", left_child.val);

            int tmp_indx = (find_sym_msg <  find_sym_msg2) ? find_sym_msg2 : find_sym_msg;

            if(a_symbol_table.symbols[tmp_indx].const_var == 1){
                fprintf(error, "const \'%s\' can't be reassigned\n", left_child.val);
            }

            /* check for  type mismatch */
            int lhs_type = get_type(left_child.val, cur_scope_id, & a_symbol_table, & a_scope_tree);
            if(lhs_type != right_child.f && lhs_type >=0)
                fprintf(warn, "type mismatch %s\n", left_child.val);
        }
        else
            fprintf(output, "%s R%d, %s, %s\n", instruction, cur_reg_id, left_child.val, right_child.val);

        char tmp [100];
        sprintf(tmp, "%d", cur_reg_id);
        strcat(ret.val, "R");
        strcat(ret.val, tmp);
        ret.f = is_float;
        cur_reg_id += 1;
        return ret;
    }

    /* const declaration */
    if(t->nodetype == const_alloc_node){
        struct symbol s;
        strcpy(s.name, t->body.a_const_alloc_node.left->body.a_variable.name);
        s.type = t->body.a_const_alloc_node.type;
        s.const_var = 1;
        s.scope_ID = cur_scope_id;

        int add_sym_msg = add_sym(s, &a_symbol_table, &a_scope_tree);

        if(add_sym_msg  == FAILURE)
            fprintf(error, "\'%s\' Redifinition Error \n", t->body.a_const_alloc_node.left->body.a_variable.name); // add to another file
        if(add_sym_msg == WARNING)
            fprintf(warn, "override of variable \'%s\'\n",t->body.a_const_alloc_node.left->body.a_variable.name); // add to another file

        fprintf(output, "Define %s %s\n", datatype_name[t->body.a_const_alloc_node.type], t->body.a_const_alloc_node.left->body.a_variable.name);

        struct ret_val rhs = get_TAC(t->body.a_const_alloc_node.right, 0, cur_scope_id, parent_scope_id);

        s.type = (s.type == numeric)?1:0;
        if(t->body.a_const_alloc_node.right != NULL){
            fprintf(output, "stor %s, %s\n", t->body.a_const_alloc_node.left->body.a_variable.name, rhs.val);
            if(s.type != rhs.f && rhs.f != - 1)
    			fprintf(warn, "type mismatch %s\n", s.name);
        }


    }

    /* compound statement, defines a new scope */
    if(t->nodetype == compound_stmt_node){
        /*
            increment max_scope,
            send the new scope id
        */
        max_scope += 1;
        int yy = add_child(&a_scope_tree, cur_scope_id, max_scope);
        get_TAC(t->body.a_compund_stmt.stmt, 0, max_scope, cur_scope_id);
    }

    /* code for decleration statements */
    if(t->nodetype == alloc){
        /*print the data type definition,
        check if it has assignment; recurse*/
        /* add new symbol */
        struct symbol s;
        strcpy(s.name, t->body.an_alloc.left->body.a_variable.name);
        s.type = t->body.an_alloc.type;
        s.const_var = 0;
        s.scope_ID = cur_scope_id;

        int add_sym_msg = add_sym(s, &a_symbol_table, &a_scope_tree);

        if(add_sym_msg  == FAILURE)
            fprintf(error, "\'%s\' Redifinition Error \n", t->body.an_alloc.left->body.a_variable.name); // add to another file
        if(add_sym_msg == WARNING)
			fprintf(warn, "override of variable \'%s\'\n", t->body.an_alloc.left->body.a_variable.name); // add to another file

        fprintf(output, "Define %s %s\n", datatype_name[t->body.an_alloc.type], t->body.an_alloc.left->body.a_variable.name);

        struct ret_val rhs = get_TAC(t->body.an_alloc.right, 0, cur_scope_id, parent_scope_id);
        s.type = (s.type == numeric)?1:0;
        if(t->body.an_alloc.right != NULL){
            fprintf(output, "stor %s, %s\n", t->body.an_alloc.left->body.a_variable.name, rhs.val);
            if(s.type != rhs.f && rhs.f != - 1)
    			fprintf(warn, "type mismatch %s\n", s.name);
        }



    }

    /* code for a list of nodes */
    if(t->nodetype == list_node){
        /* loop on its children and execute get_TAC on every child*/
        int i = 0;
        for(; i < t->body.list_of_nodes.child_cnt; i=i+1)
            get_TAC(t->body.list_of_nodes.children[i],0, cur_scope_id, parent_scope_id);
    }

    /* code for if statement*/
    if(t->nodetype == if_node){
        char final_cmp [100];
		struct ret_val r = get_TAC(t->body.an_if.expression, 0, cur_scope_id, parent_scope_id);
        strcpy(final_cmp, r.val);

        char tmp[100];
        char label [100] = {'\0'};

        strcat(label,"L_");
        sprintf(tmp, "%d", cur_label_id);
        cur_label_id += 1;
        strcat(label, tmp);


        fprintf(output, "JZ %s, %s\n",final_cmp,label); // print condition
        get_TAC(t->body.an_if.stmt,0, cur_scope_id, parent_scope_id); // print the statement
        fprintf(output, "%s:\n",label); // print label after statement to jump to if condition is false
    }

    /* code for if else statement*/
    if(t->nodetype == if_else_node){
        char final_cmp [100];
		struct ret_val r = get_TAC(t->body.an_if_else.expression, 0, cur_scope_id, parent_scope_id);
        strcpy(final_cmp, r.val);

        char tmp[100];
        char label_1 [100] = {'\0'};
        char label_2 [100] = {'\0'};

        strcat(label_1,"L_");
        sprintf(tmp, "%d", cur_label_id);
        cur_label_id += 1;
        strcat(label_1, tmp);

        strcat(label_2,"L_");
        sprintf(tmp, "%d", cur_label_id);
        cur_label_id += 1;
        strcat(label_2, tmp);

        fprintf(output, "JZ %s, %s\n",final_cmp,label_1); //print condition
        get_TAC(t->body.an_if_else.stmt_1,0, cur_scope_id, parent_scope_id); // print the statement
        fprintf(output, "JMP %s\n",label_2); //jmp after the else
        fprintf(output, "%s:\n",label_1); // print label after statement to jump to if condition is false

        get_TAC(t->body.an_if_else.stmt_2, 0, cur_scope_id, parent_scope_id); // print else statement
        fprintf(output, "%s:\n",label_2); //print label afterelse statement to jump to if the first condition was true
    }

    /* code for while loop*/
    if(t->nodetype == while_node){
        char tmp[100];
        char label_1 [100] = {'\0'};
        char label_2 [100] = {'\0'};

        strcat(label_1,"L_");
        sprintf(tmp, "%d", cur_label_id);
        cur_label_id += 1;
        strcat(label_1, tmp);

        strcat(label_2,"L_");
        sprintf(tmp, "%d", cur_label_id);
        cur_label_id += 1;
        strcat(label_2, tmp);

        fprintf(output, "%s:\n",label_1); // start of while loop
        char final_cmp [100];
		struct ret_val r = get_TAC(t->body.a_while.expression, 0, cur_scope_id, parent_scope_id);
        strcpy(final_cmp, r.val);
		fprintf(output, "JZ %s, %s\n", final_cmp, label_2); // if  false jmp to lable_2

        get_TAC(t->body.a_while.stmt, 0, cur_scope_id, parent_scope_id); // code of while loop
		fprintf(output, "JMP %s\n", label_1); //repeat the loop

		fprintf(output, "%s:\n", label_2);
    }

    /* code  for do while loop*/
    if(t->nodetype == do_while_node){
        char tmp[100];
        char label_1 [100] = {'\0'};
        char label_2 [100] = {'\0'};

        strcat(label_1,"L_");
        sprintf(tmp, "%d", cur_label_id);
        cur_label_id += 1;
        strcat(label_1, tmp);

		fprintf(output, "%s:\n", label_1); // start of do_while loop
        get_TAC(t->body.a_do_while.stmt, 0, cur_scope_id, parent_scope_id); // statement of do_while loop

        char final_cmp [100];
		struct ret_val r = get_TAC(t->body.a_while.expression, 0, cur_scope_id, parent_scope_id);
        strcpy(final_cmp, r.val);
		fprintf(output, "JNZ %s, %s\n", final_cmp, label_1); // if true jmp to lable_1 (start ofthe loop)
    }

    /* code for for loop*/
    if(t->nodetype == for_node){
        get_TAC(t->body.a_for.exp_1, 0, cur_scope_id, parent_scope_id);

        char tmp[100];
        char label_1 [100] = {'\0'};
        char label_2 [100] = {'\0'};

        strcat(label_1,"L_");
        sprintf(tmp, "%d", cur_label_id);
        cur_label_id += 1;
        strcat(label_1, tmp);

        strcat(label_2,"L_");
        sprintf(tmp, "%d", cur_label_id);
        cur_label_id += 1;
        strcat(label_2, tmp);

		fprintf(output, "%s:\n", label_1); // start of for loop

        char final_cmp [100];
		struct ret_val r = get_TAC(t->body.a_for.exp_2, 0, cur_scope_id, parent_scope_id);
        strcpy(final_cmp, r.val);

		if(t->body.a_for.exp_2 != NULL)
            fprintf(output, "JZ %s, %s\n", final_cmp, label_2);

        get_TAC(t->body.a_for.stmt, 0, cur_scope_id, parent_scope_id);

        /* if there exists a third exp*/
        if(t->body.a_for.exp_3 != NULL)
            get_TAC(t->body.a_for.exp_3, 0, cur_scope_id, parent_scope_id);

		fprintf(output, "JMP %s\n", label_1);
		fprintf(output, "%s:\n", label_2);
    }

    /* case */
    if(t->nodetype == case_node){
        char final_cmp [100];
		struct ret_val r = get_TAC(t->body.a_case.expression, 0, cur_scope_id, parent_scope_id);
        strcpy(final_cmp, r.val);
        get_TAC(t->body.a_case.stmt,0, cur_scope_id, parent_scope_id);
        struct ret_val ret;
        strcpy(ret.val, final_cmp);
        return ret;
    }


    /*default*/
    if(t->nodetype == default_node){
        get_TAC(t->body.a_default.stmt,0, cur_scope_id, parent_scope_id);
    }

    /*switch*/
    if(t->nodetype == switch_node){
        int has_default = 0;

        char final_cmp_1 [100];
		struct ret_val r = get_TAC(t->body.a_switch.expression, 0, cur_scope_id, parent_scope_id);
        strcpy(final_cmp_1, r.val);

        char after_switch_label [100] = {'\0'};
        char tmp[100];
        strcat(after_switch_label,"L_");
        sprintf(tmp, "%d", cur_label_id);
        cur_label_id += 1;
        strcat(after_switch_label, tmp);

        int i = 0;
        char label_2b_printed [100] = {'\0'};

        for(; i < t->body.a_switch.stmt.child_cnt; i=i+1){
            if(t->body.a_switch.stmt.children[i]->nodetype == case_node){
                if(strcmp("\0", label_2b_printed) != 0){
					fprintf(output, "%s:\n", label_2b_printed);
                    label_2b_printed[0] = '\0';
                }

                tmp[0] = '\0';
                strcat(label_2b_printed,"L_");
                sprintf(tmp, "%d", cur_label_id);
                cur_label_id += 1;
                strcat(label_2b_printed, tmp);

                char final_cmp_2 [100];
				struct ret_val r = get_TAC(t->body.a_switch.stmt.children[i]->body.a_case.expression, 0, cur_scope_id, parent_scope_id);
                strcpy(final_cmp_2, r.val);
                char tmp_reg[100] = {'\0'};
                sprintf(tmp, "%d", cur_reg_id);
                strcat(tmp_reg, "R");
                strcat(tmp_reg, tmp);
				fprintf(output, "EQ %s, %s, %s\n", tmp_reg, final_cmp_2, final_cmp_1);
				fprintf(output, "JZ %s, %s\n", tmp_reg, label_2b_printed);

                get_TAC(t->body.a_switch.stmt.children[i], 0, cur_scope_id, parent_scope_id);
            }

            if(t->body.a_switch.stmt.children[i]->nodetype == break_node)
				fprintf(output, "JMP %s\n", after_switch_label);

            if(t->body.a_switch.stmt.children[i]->nodetype == default_node){
				fprintf(output, "%s:\n", label_2b_printed);
                get_TAC(t->body.a_switch.stmt.children[i], 0, cur_scope_id, parent_scope_id);
                has_default = 1;
            }
        }

        if(strcmp("\0", label_2b_printed)!=0 && ! has_default){
			fprintf(output, "%s:\n", label_2b_printed);
        }

		fprintf(output, "%s:\n", after_switch_label);
    }

 }
