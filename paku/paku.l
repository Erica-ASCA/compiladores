%{
#include "paku.tab.h" 
#include <stdlib.h>

void yyerror(char *s);
%}
%option yylineno

%%

[=]									{ return EQUALS; }
[+]			    					{ return PLUS; }
[-]		    						{ return MINUS; }
[/]     							{ return DIVIDE; }
[*]     							{ return TIMES; }
[(]     							{ return P_LEFT; }
[)]     							{ return P_RIGHT; }
int|float               			{ return TYPE; }
[0-9]+|[0-9]+(\.[0-9]+)?  			{ return NUMBER; }
[a-zA-Z_][_a-zA-Z0-9]*  			{ return IDENTIFIER; }
\n                      			{ return EOL; }
<<EOF>>								{ return END; }
[[:space:]]							;

%%

int yywrap()
{
	return 1;
}
