%{

#include "paku.tab.h" 
#include <stdlib.h>

void yyerror(char *s);
%}
%option yylineno


%%
"if"										{ return IF; }
"else"                              		{ return ELSE; }
"sqrt"										{ return SQRT; }
"{"                                 		{ return BRACES_LEFT; }
"}"                                 		{ return BRACES_RIGHT; }
"="											{ return EQUALS; }
"+"|"-"|"/"|"*"|">="|"<="|"=="|"!="|">"|"<"|"&&"|"||"|"%" { yylval.operation = strdup(yytext); return OPERATOR; }
"!"											{ return NOT; }
"("     									{ return P_LEFT; }
")"     									{ return P_RIGHT; }
print										{ return PRINT; }
read                                		{ return READ; }
int|float               					{ return TYPE; }
[0-9]+|[0-9]+(\.[0-9]+)?  					{ yylval.value = atof(yytext); return NUMBER; }
[a-zA-Z_][_a-zA-Z0-9]*  					{ yylval.name = strdup(yytext); return IDENTIFIER; }
\"[^\"]*\"|\'[^\']*\'              			{ yylval.string = strdup(yytext); return STRING; }
\n                      					{ return EOL; }
<<EOF>>										{ return END; }
[[:space:]]									;

%%

int yywrap()
{
	return 1;
}
