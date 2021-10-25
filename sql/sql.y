%{
#include <stdio.h>

void yyerror(char *s);
int yylex(void);
int yyparse();
%}

%token NAME ALL COMMA DOT
%token SELECT WHERE FROM OPERATOR STRING NUMBER
%token END

%%
QUERRY:
    SELECT_EXP END {YYACCEPT;}
    |   SELECT_EXP WHERE_EXP END {YYACCEPT;}
    ;

WHERE_EXP:
    WHERE NAME OPERATOR STRING
    |   WHERE NAME OPERATOR NUMBER
    ;

SELECT_EXP:
    SELECT SELECT_EXP_LIST FROM EXP
    ;

SELECT_EXP_LIST:
    EXP
    |   SELECT_EXP_LIST COMMA EXP
    |   ALL
    ;

EXP:
    NAME
    | NAME DOT NAME
    ;

%%

void yyerror(char *s)
{
	printf("Error: %s\n", s);
}

int main(int argc, char *argv[])
{
	int result;
    result = yyparse();
    if (result == 0){
        printf("Correct\n");
    }
	return 0;
}
