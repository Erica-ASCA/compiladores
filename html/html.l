%{
#include "html.tab.h" 
#include <stdlib.h>

void yyerror(char *s); 
%}

%%

"<!DOCTYPE html>"       { return TYPE; }
"<html>"                { return HTML_OPEN; }
"</html>"               { return HTML_CLOSE; }
"<body>"                { return BODY_OPEN; }
"</body>"               { return BODY_CLOSE; }
"<h1>"                  { return HEADING1_OPEN; }
"</h1>"                 { return HEADING1_CLOSE; }
"<h2>"                  { return HEADING2_OPEN; }
"</h2>"                 { return HEADING2_CLOSE; }
"<h3>"                  { return HEADING3_OPEN; }
"</h3>"                 { return HEADING3_CLOSE; }
"<h4>"                  { return HEADING4_OPEN; }
"</h4>"                 { return HEADING4_CLOSE; }
"<h5>"                  { return HEADING5_OPEN; }
"</h5>"                 { return HEADING5_CLOSE; }
"<h6>"                  { return HEADING6_OPEN; }
"</h6>"                 { return HEADING6_CLOSE; }
"<p>"                   { return PARAGRAPH_OPEN; }
"</p>"                  { return PARAGRAPH_CLOSE; }
"<a href="              { return LINK_OPEN; }
"</a>"                  { return LINK_CLOSE; }
"<ul>"                  { return UL_LIST_OPEN;}
"</ul>"                 { return UL_LIST_CLOSE; }
"<ol>"                  { return OL_LIST_OPEN; }
"</ol>"                 { return OL_LIST_CLOSE; }
"<li>"                  { return LIST_OPEN; }
"</li>"                 { return LIST_CLOSE; }
"<img src="             { return IMAGE; }
"<button>"              { return BUTTON_OPEN; }
"</button>"             { return BUTTON_CLOSE; }
" alt="                 { return ALT; }
" width="               { return WIDTH; }
" height="              { return HEIGHT; }
">"                     { return CLOSE; }
\"[^\"]*\"              { return STRING; }
.                       ;
\n                      ;
\s                      ;

%%

int yywrap()
{
	return 1;
}
