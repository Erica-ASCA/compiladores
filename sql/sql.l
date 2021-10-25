%{
#include "sql.tab.h" 
#include <stdlib.h>

void yyerror(char *s); 
%}

%%
SELECT								{ return SELECT;}
WHERE								{ return WHERE;}
FROM								{ return FROM;}
=|>|<|>=|<=|<>|BETWEEN|LIKE|IN		{ return OPERATOR;}
[*]									{ return ALL;}
[,]									{ return COMMA;}
[.]									{ return DOT;}
[a-zA-Z][_a-zA-Z]*					{ return NAME;}
\"[^\"]*\"|\'[^\']*\'				{ return STRING;}
[-+]?[0-9]+|[-+]?[0-9]+(\.[0-9]+)?	{ return NUMBER;}
[\n]								{ return END;}
[[:space:]]							;
.									{ yyerror("Undefined token\n"); }

%%

int yywrap()
{
	return 1;
}

