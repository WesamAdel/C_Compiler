yacc -d compiler.y
lex compiler.l
gcc compiler.tab.c lex.yy.c SymTab.c -o compiler.exe