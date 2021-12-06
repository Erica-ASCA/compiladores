%{

#include "paku.tab.h" 
#include <stdlib.h>
#include <stdbool.h>

void yyerror(char *s);
%}
%option yylineno


%%
"if"								{ return IF;}
"else"                              { return ELSE;}
"{"                                 { return BRACES_LEFT; }
"}"                                 { return BRACES_RIGHT; }
[=]									{ return EQUALS; }
[<]                                 { return LESS_THAN;}
[>]                                 { return GREATER_THAN;}
">="                                { return GREATER_THAN_EQUAL;}
"<="                                { return LESS_THAN_EQUAL;}
"=="			                    { return EQUALS_DOUBLE;}
"!="                                { return NOT_EQUAL;}
[+]			    					{ return PLUS; }
[-]		    						{ return MINUS; }
[/]     							{ return DIVIDE; }
[*]     							{ return TIMES; }
[(]     							{ return P_LEFT; }
[)]     							{ return P_RIGHT; }
print								{ return PRINT; }
read                                { return READ; }
int|float               			{ return TYPE; }
[0-9]+|[0-9]+(\.[0-9]+)?  			{ yylval.d = atof(yytext);return NUMBER; }
[a-zA-Z_][_a-zA-Z0-9]*  			{ yylval.s = strdup(yytext); return IDENTIFIER; }
\n                      			{ return EOL; }
<<EOF>>								{ return END; }
[[:space:]]							;

%%

int yywrap()
{
	return 1;
}
