%{
#include <stdio.h>
#include <math.h>
#include "hashtable.h"
#include "astcreate.h"
#include "astrun.h"
extern FILE* yyin;

void yyerror(struct AstElement** astDest, char *s);
int yylex(void);
int yyparse();

extern int yylineno;
hashtable *table;
%}

%parse-param {struct AstElement** astDest}

%union {
    char *name;
    char *string;
    int value;
    char* operation;
    struct AstElement* ast;
}

%locations

%token EQUALS EOL END
%token P_LEFT P_RIGHT
%token PRINT READ SQRT
%token IF ELSE 
%token BRACES_LEFT BRACES_RIGHT 

%left P_LEFT P_RIGHT

%token <name> IDENTIFIER TYPE
%token <string> STRING
%token <value> NUMBER
%token <operation> OPERATOR NOT
%type<ast> PRINT_EXP READ_EXP DECLARATION EXP SQRT_EXP PROGRAM BLOCK STATEMENT STATEMENTS IF_STMT ATTRIBUTION


%%

PROGRAM:    
    STATEMENTS END { (*(struct AstElement**)astDest) = $1; YYACCEPT;}
    ;

STATEMENTS:  
    STATEMENT { $$ = 0; }
    | STATEMENTS STATEMENT { $$ = create_statement($1, $2);}
    | END 
    ;

STATEMENT: 
    DECLARATION { $$ = $1; }
    | READ_EXP { $$ = $1; }
    | PRINT_EXP { $$ = $1; }
    | ATTRIBUTION { $$ = $1; }
    | IF_STMT { $$ = $1; }
    | BLOCK { $$ = $1; }
    | EOL
    ;

IF_STMT: 
    IF P_LEFT EXP P_RIGHT BLOCK EOL { $$ = create_if($3, $5, 0);}
    | IF P_LEFT EXP P_RIGHT BLOCK ELSE BLOCK EOL { $$ = create_if($3, $5, $7);}
    ;

BLOCK: 
    BRACES_LEFT STATEMENTS BRACES_RIGHT { $$ = $2; }
    ;

ATTRIBUTION: 
    IDENTIFIER EQUALS EXP EOL { $$ = create_assigment($1, $3);}
    | IDENTIFIER EQUALS SQRT_EXP EOL { $$ = create_assigment($1, $3);}
    ;

EXP:
    NUMBER { $$ = create_exp_num($1); }
    | IDENTIFIER { $$ = create_exp_name($1); }
    | EXP OPERATOR EXP  { $$ = create_exp($1, $3, $2);}
    | P_LEFT EXP P_RIGHT { $$ = $2; }
    | NOT EXP { $$ = create_exp_not($2, $1); }
    ;

SQRT_EXP: 
    SQRT P_LEFT IDENTIFIER P_RIGHT { $$ = create_sqrt($3); }
    ;

PRINT_EXP:
    PRINT P_LEFT IDENTIFIER P_RIGHT EOL { $$ = create_print($3);}
    | PRINT P_LEFT STRING P_RIGHT EOL { $$ = create_print_string(remove_quotes($3));}
    ;

READ_EXP:
    READ P_LEFT IDENTIFIER P_RIGHT EOL  { $$ = create_read($3);}
    ;

DECLARATION:
    TYPE IDENTIFIER EOL { $$ = create_declaration($1, $2); }
    ;

%%

void yyerror(struct AstElement** astDest, char *s)
{
	printf("Error: %s\n", s);
    printf("Line: %d\n", yylineno);
}

int main(int argc, char *argv[])
{
    struct AstElement *ast = 0;
    table = hash_init(101);

    int result;
    yyin = fopen(argv[1], "r");
    result = yyparse(&ast);
    if (result == 0){
        printf("Success\n");
    } 

    exec(table, ast);
 
	return 0;
}
