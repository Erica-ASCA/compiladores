%{
#include "sql.tab.h" 
#include <stdlib.h>

void yyerror(char *s); 
%}

%%
SELECT								{ return SELECT;}
WHERE								{ return WHERE;}
FROM								{ return FROM;}
SET									{ return SET;}
UPDATE								{ return UPDATE;}
DELETE								{ return DELETE;}
INSERT								{ return INSERT;}
INTO								{ return INTO;}
VALUES								{ return VALUES;}
[(]									{ return P_LEFT;}
[)]									{ return P_RIGHT;}
[=]									{ return EQUALS;}
>|<|>=|<=|<>|BETWEEN|LIKE|IN		{ return OPERATOR;}
[*]									{ return ALL;}
[,]									{ return COMMA;}
[.]									{ return DOT;}
[a-zA-Z][_a-zA-Z]*					{ return NAME;}
\"[^\"]*\"|\'[^\']*\'				{ return STRING;}
[-+]?[0-9]+|[-+]?[0-9]+(\.[0-9]+)?  { return NUMBER;}
[;]									{ return END;}
[\n]								{ return EOL;}
[[:space:]]							;
.									{ yyerror("Undefined token\n"); }

%%

int yywrap()
{
	return 1;
}

