
/* calculator with AST */
%{
#include <stdio.h>
#include <stdlib.h>
#include "ex_calc_ast.h"
%}

%union {
    struct ast *a;
    double d;
}

/* tokens */
%token <d> NUMBER;
%token EOL

%type <a> exp factor term

%%
root: /* nothing */
    | root exp EOL          { printf("= %4.4g\n", eval($2)); treefree($2); printf("> "); }
    | root EOL              { printf("> "); }
    ;

exp: factor
    | exp '+' factor        { $$ = newast('+', $1, $3); }
    | exp '-' factor        { $$ = newast('-', $1, $3); }
    ;

factor: term
    | factor '*' term       { $$ = newast('*', $1, $3); }
    | factor '/' term       { $$ = newast('/', $1, $3); }
    ;

term: NUMBER                { $$ = newnum($1); }
    | '|' term              { $$ = newast('|', $2, NULL); }
    | '(' exp ')'           { $$ = $2; }
    | '-' term              { $$ = newast('M', $2, NULL); }
    ;

%%
