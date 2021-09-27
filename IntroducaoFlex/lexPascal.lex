COMMENT             "//".*|"(*"((("*"[^/])?)|[^*])*"*)"
KEYWORD             and|array|as|asm|begin|break|case|class|const|constref|constructor|continue|destructor|dispose|div|do|downto|else|end|except|exit|exports|false|file|finalization|finally|for|function|goto|if|implementation|in|inherited|initialization|inline|interface|is|label|library|mod|new|nil|not|object|of|on|on|operator|or|out|packed|procedure|program|property|raise|record|repeat|self|set|shl|shr|string|then|threadvar|to|true|try|type|unit|until|uses|var|while|with|xor
MODIFIER            absolute|abstract|alias|assembler|bitpacked|break|cdecl|continue|cppdecl|cvar|default|deprecated|dynamic|enumerator|experimental|export|external|far|far16|forward|generic|helper|implements|index|interrupt|iocheck|local|message|name|near|nodefault|noreturn|nostackframe|oldfpccall|otherwise|overload|override|pascal|platform|private|protected|public|published|read|register|reintroduce|result|safecall|saveregisters|softfloat|specialize|static|stdcall|stored|strict|unaligned|unimplemented|varargs|virtual|winapi|write
INT                 [-+]?[0-9]+
FLOAT               [-+]?[0-9]+(\.[0-9]+)?
STRING              \'[^\']*\'
IDENTIFIER          [a-zA-Z_][_a-zA-Z0-9]*
OPERATOR            \+|-|\/|\%|\+\+|"--"|==|!=|\>|\<|\>=|\<=|\&&|\|\||!|&|\||\^|~|\<\<|\>\>|"?"|:=
PUNCTUATOR          \(|\)|\{|\}|\[|\]|;|:|,|=|\.
EMPTY               [ \t\n]

%%
{COMMENT}           printf("Comment detected: \"%s\"\n", yytext);
{KEYWORD}           printf("Keyword detected: \"%s\"\n", yytext);
{MODIFIER}          printf("Modifier detected: \"%s\"\n", yytext);
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