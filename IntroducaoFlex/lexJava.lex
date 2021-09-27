COMMENT             "//".*|"/*"((("*"[^/])?)|[^*])*"*/"
KEYWORD             abstract|continue|for|new|switch|assert|default|goto|package|synchronized|boolean|do|if|private|this|break|double|implements|protected|throw|byte|else|import|public|throws|case|enum|instanceof|return|transient|catch|extends|int|short|try|char|final|interface|static|void|class|finally|long|strictfp|volatile|const|float|native|super|while
INT                 [-+]?[0-9]+
FLOAT               [-+]?[0-9]+(\.[0-9]+)?
STRING              \"[^\"]*\"|\'[^\']*\'
IDENTIFIER          [a-zA-Z_][_a-zA-Z0-9\.]*
OPERATOR            \+|-|\/|\%|\+\+|"--"|==|!=|\>|\<|\>=|\<=|\&&|\|\||!|&|\||\^|~|\<\<|\>\>|"?"
PUNCTUATOR          \(|\)|\{|\}|\[|\]|;|:|,|=
EMPTY               [ \t\n]

%%
{COMMENT}           printf("Comment detected: \"%s\"\n", yytext);
{KEYWORD}           printf("Keyword detected: \"%s\"\n", yytext);
{STRING}            printf("String detected: \"%s\"\n", yytext);
{OPERATOR}          printf("Operator detected: \"%s\"\n", yytext);
{PUNCTUATOR}        printf("Punctuator detected: \"%s\"\n", yytext);
{IDENTIFIER}        printf("Identifier detected: \"%s\"\n", yytext);
{INT}               printf("Int detected: \"%s\"\n", yytext);
{FLOAT}             printf("Float detected: \"%s\"\n", yytext);
{EMPTY}             printf("Whitespace or new line detected: \"%s\"\n", yytext);

%%
void main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Missing input file\n");
        exit(-1);
    }

    yyin = fopen(argv[1], "r");
    yylex();
}