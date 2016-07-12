%{
void yyerror (char *s);
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include <string.h>
#include "tree.h"

extern struct scope_tree a_scope_treet;
extern struct sym_tab a_symbol_table;
extern int max_scope;

FILE *error, *output, *warn, *Sym_Table;

struct stack scope_stack;

int line_cnt;
%}


%union {int num; float f_num; struct tree * a_tree; char* str; int bool_val; char char_val;}         /* Yacc definitions */

%start main_func

%token CONST INT FLOAT CHAR BOOL FOR WHILE DO IF SWITCH BREAK DEFAULT CONTINUE CASE GOTO ELSE
%token LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP XOR_OP LEFT_OP RIGHT_OP
%token MAIN

%token <bool_val> TRUE
%token <bool_val> FALSE
%token <char_val> CHAR_VAL
%token <f_num> f_number
%token <num> number
%token <str> identifier

%type <a_tree> add_exp expression mul_exp factor assignment declaration unary_exp constant_declaration
%type <a_tree> and_exp or_exp xor_exp relational_exp equality_exp
%type <a_tree> statement labeled_statement compound_statement selection_statement iteration_statement expression_statement
%type <a_tree> constant_expression statement_list conditional_exp

%type <a_tree> error_statement

%%

/*
    descriptions of expected inputs     corresponding actions

    we construct the parse tree while parsing, from the leaves to the root.
    at each production rule, we make a new node with its specific type, and assign it to the lhs of the rule.
*/

main_func : INT MAIN '('')' '{' statement_list '}' {get_TAC($6, 0, 0, 0);}
            ;

/*----------------------------------------- BASIC EXPRESSIONS ---------------------------------------- */

factor  : number                {$$ = make_number($1);}
        | f_number              {$$ = make_f_number($1);}
		| identifier			{$$ = make_variable($1);}
		| TRUE                  {$$ = make_bool($1);}
        | FALSE                 {$$ = make_bool($1);}
        | CHAR_VAL              {$$ = make_char($1);}
        | unary_exp             {$$ = $1;}
        | '(' expression ')'    {$$ = $2;}
		;

unary_exp : '!' factor       {$$ = make_uni_operator($2, not);}
        |  '-' factor        {$$ = make_uni_operator($2, minus);}
        ;


mul_exp : factor				    {$$ = $1;}
        | mul_exp '/' factor		{$$ = make_operator($1, over, $3);}
		| mul_exp '*' factor		{$$ = make_operator($1, star, $3);}
		;

add_exp : mul_exp                  {$$ = $1;}
        | add_exp '+' mul_exp      {$$ = make_operator($1, plus, $3);}
        | add_exp '-' mul_exp      {$$ = make_operator($1, minus, $3);}
    	;

/*
shift_exp : add_exp                        {$$ = $1;}
	      | shift_exp LEFT_OP add_exp      {$$ = make_operator($1, SHL, $3);}
	      | shift_exp RIGHT_OP add_exp     {$$ = make_operator($1, SHR, $3);}
	      ;
*/

relational_exp : add_exp                          {$$ = $1;}
	           | relational_exp '<' add_exp       {$$ = make_operator($1, LT,  $3);}
	           | relational_exp '>' add_exp       {$$ = make_operator($1, GT,  $3);}
	           | relational_exp LE_OP add_exp     {$$ = make_operator($1, LTE,  $3);}
	           | relational_exp GE_OP add_exp     {$$ = make_operator($1, GTE,  $3);}
	           ;


equality_exp : relational_exp                       {$$ = $1;}
         	| equality_exp EQ_OP relational_exp     {$$ = make_operator($1, EQEQ,  $3);}
         	| equality_exp NE_OP relational_exp     {$$ = make_operator($1, NE,  $3);}
         	;


xor_exp: equality_exp                   {$$ = $1;}
        | xor_exp XOR_OP equality_exp   {$$ = make_operator($1, xor, $3);}
        ;


and_exp: xor_exp                    {$$ = $1;}
       | and_exp AND_OP xor_exp     {$$ = make_operator($1, and, $3);}
       ;


or_exp: and_exp                       {$$ = $1;}
      | or_exp OR_OP and_exp          {$$ = make_operator($1, or, $3);}
      ;

conditional_exp : or_exp            {$$ = $1;}
              ;

constant_expression: conditional_exp {$$ = $1;}
                    ;


assignment  : identifier '=' assignment     {$$ = make_operator(make_variable($1), EQ, $3);}
             | conditional_exp              {$$ = $1;}
             ;

expression : assignment                     {$$ = $1;}
            ;


/* --------------------------------- statements, delarations, list of statements, IF, LOOPS --------------------------------*/

/* a declaration statement eg. int x; int x = 5; int x = (1 + y); */
declaration : INT identifier '=' assignment ';' {
                                                    $$ = make_alloc(make_variable($2), $4, integer);
                                                   //insert_symbol(make_symbol($2, integer));
                                                }
           | FLOAT identifier '=' assignment ';' {
                                                   $$ = make_alloc(make_variable($2), $4, numeric);
                                                   /*//insert_symbol(make_symbol($2, numeric));*/
                                                }
           | INT identifier ';'                   {

                                                   $$ = make_alloc(make_variable($2), NULL, integer);
                                                   //insert_symbol(make_symbol($2, integer));
                                                    }
           | FLOAT identifier  ';'                {
                                                   $$ = make_alloc(make_variable($2), NULL, numeric);
                                                   //insert_symbol(make_symbol($2, numeric));
                                               }
           | BOOL identifier '=' assignment ';'   {
                                                   $$ = make_alloc(make_variable($2), $4, boolean);
                                                   //insert_symbol(make_symbol($2, boolean));
                                                }
           | BOOL identifier   ';'                {
                                                   $$ = make_alloc(make_variable($2), NULL, boolean);
                                                   //insert_symbol(make_symbol($2, boolean));
                                               }
           | CHAR identifier '=' assignment ';'   {
                                                   $$ = make_alloc(make_variable($2), $4, character);
                                                   //insert_symbol(make_symbol($2, character));
                                               }
           | CHAR identifier ';'                  {
                                                   $$ = make_alloc(make_variable($2), NULL, character);
                                                   //insert_symbol(make_symbol($2, character));
                                               }
           ;

constant_declaration: CONST INT identifier '=' assignment ';'      {$$ = make_const(make_variable($3), $5, integer);}
                     | CONST FLOAT identifier '=' assignment ';'    {$$ = make_const(make_variable($3), $5, numeric);}
                     | CONST CHAR identifier '=' assignment ';'     {$$ = make_const(make_variable($3), $5, character);}
                     | CONST BOOL identifier '=' assignment ';'     {$$ = make_const(make_variable($3), $5, boolean);}
                     ;


statement: labeled_statement        {$$ = $1;}
            | compound_statement    {$$ = $1;}
           	| expression_statement  {$$ = $1;}
           	| selection_statement   {$$ = $1;}
           	| iteration_statement   {$$ = $1;}
            | declaration           {$$ = $1;}
            | constant_declaration  {$$ = $1;}
            | BREAK ';'             {$$ = make_break();}
            | error ';'             {$$ = NULL;}
            | error '}'             {$$ = NULL;}
            | error_statement {$$ = NULL;}
           	;

labeled_statement: CASE constant_expression ':' statement  {$$ = make_case($2, $4);}
                 | DEFAULT ':' statement                   {$$ = make_default($3);}
               	 ;

compound_statement : '{' '}'                                   {$$ = make_compund_stmt(NULL);}
                   | '{' statement_list '}'                    {$$ = make_compund_stmt($2);}
                   ;

statement_list: statement                   {$$ = make_list($1); }
              | statement_list statement    {$$ = add_child_to_list($1, $2);}
              ;

expression_statement: ';'                   {$$ = NULL;}
                    | expression ';'        {$$ = $1;}
	                ;

selection_statement : IF '(' expression ')' compound_statement                            {$$ = make_if($3, $5);}
                    | IF '(' expression ')' compound_statement ELSE compound_statement    {$$ = make_if_else($3, $5, $7);}
	                | SWITCH '(' expression ')' compound_statement                        {$$ = make_switch($3, ($5)->body.a_compund_stmt.stmt);}
	                ;



iteration_statement: WHILE '(' expression ')' compound_statement                            {$$ = make_while($3, $5);}
	| DO compound_statement WHILE '(' expression ')' ';'                                    {$$ = make_do_while($5, $2);}
	| FOR '(' expression_statement expression_statement ')' compound_statement              {$$ = make_for($3, $4, NULL, $6);}
	| FOR '(' expression_statement expression_statement expression ')' compound_statement   {$$ = make_for($3, $4, $5, $7);}
	;

/* ------------------------------ ERROR RULES ------------------------------------ */

error_statement: WHILE  expression ')' compound_statement                                {$$ = NULL; fprintf(error, "expected \'(\'\n");}
	| DO compound_statement WHILE expression ')' ';'                                     {$$ = NULL; fprintf(error, "expected \'(\'\n");}
	| FOR  expression_statement expression_statement ')' compound_statement              {$$ = NULL; fprintf(error, "expected \'(\'\n");}
	| FOR  expression_statement expression_statement expression ')' compound_statement   {fprintf(error, "expected \'(\'\n"); $$= NULL;}
	| IF  expression ')' compound_statement                                              {$$ = NULL; fprintf(error, "expected \'(\'\n");}
    | IF  expression ')' compound_statement ELSE compound_statement                      {$$ = NULL; fprintf(error, "expected \'(\'\n");}
    | SWITCH  expression ')' compound_statement                                          {$$ = NULL; fprintf(error, "expected \'(\'\n");}
    | expression                                                                         {$$ = NULL; fprintf(error, "expected ;\n");}

    | INT identifier  assignment ';'                                                     {$$ = NULL; fprintf(error, "expected =\n");}
    | FLOAT identifier  assignment ';'                                                   {$$ = NULL; fprintf(error, "expected =\n");}
    | BOOL identifier  assignment ';'                                                    {$$ = NULL; fprintf(error, "expected =\n");}
    | CHAR identifier  assignment ';'                                                    {$$ = NULL; fprintf(error, "expected =\n");}

    ;




%%                     /* C code */

int main (void){
    line_cnt = 1;
    max_scope = 0;
    cur_reg_id = 0;
    cur_label_id = 0;


    output = fopen("out.txt", "w");
    error = fopen("errors.txt", "w");
	warn = fopen("warns.txt", "w");
	Sym_Table = fopen("sym_tab.txt", "w");

    init_table(&a_symbol_table);
    init_scope_tree(&a_scope_tree, 0);

    /* -------------------------- */
    yyparse ( );

	write_sym_tab(Sym_Table, &a_symbol_table);

    fclose(error);
	fclose(warn);
	fclose(Sym_Table);
    fclose(output);
    return 0;
}

void yyerror (char *s) {
	fprintf(error, "syntex error:line:%d\n", line_cnt);
}
