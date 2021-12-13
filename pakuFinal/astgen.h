#ifndef ASTGEN_H
#define ASTGEN_H

#include <string.h>
#include <stdio.h>

typedef struct AstElement {
    struct AstElement *left;
    struct AstElement *right;
    char nodetype;
    char *name;
    char *string;
    char *op;
    int val;
    char *type;
    struct AstElement* cond;
    struct AstElement** statements;
    int count;
} AstElement;

char* remove_quotes(char* s1);
AstElement* create_print_string(char* name);
AstElement* create_assigment(char*name,  AstElement* val);
AstElement* create_exp_num(int val);
AstElement* create_exp_name(char*name);
AstElement* create_exp( AstElement* left,  AstElement* right, char* op);
AstElement* create_statement( AstElement* dest,  AstElement* toAppend);
AstElement* create_print(char* name);
AstElement* create_read(char* name);
AstElement* create_declaration(char* type, char* name);
AstElement* create_if( AstElement* cond, AstElement* left,  AstElement* right);

AstElement* create_assigment( char*name, AstElement* val)
{
    AstElement* result = malloc(sizeof(AstElement));
    result->nodetype = 'A';
    result->name = name;
    result->right = val;
    return result;
}

AstElement* create_exp_num(int val)
{
    AstElement* result = malloc(sizeof(AstElement));
    result->nodetype = 'V';
    result->val = val;
    return result;
}

AstElement* create_exp_name(char* name)
{
    AstElement* result = malloc(sizeof(AstElement));
    result->nodetype = 'N';
    result->name = name;
    return result;
}

AstElement* create_exp_not(AstElement* left, char* op)
{
    AstElement* result = malloc(sizeof(AstElement));
    result->nodetype = 'C';
    result->left = left;
    result->op = op;
    return result;
}

AstElement* create_exp(AstElement* left, AstElement* right, char* op)
{
    AstElement* result = malloc(sizeof(AstElement));
    result->nodetype = 'E';
    result->left = left;
    result->right = right;
    result->op = op;
    return result;
}

AstElement* create_if( AstElement* cond, AstElement* left,  AstElement* right){
    AstElement* result = malloc(sizeof(AstElement));
    result->nodetype = 'I';
    result->left = left;
    result->right = right;
    result->cond = cond;
    return result;
}

AstElement* create_statement(AstElement* result, AstElement* toAppend)
{
    
    if(!result)
    {
        result = malloc(sizeof(AstElement));
        result->nodetype = 'S';
        result->count = 0;
        result->statements = 0;
    }
    result->nodetype = 'S';    
    result->count++;
    result->statements = realloc(result->statements, result->count*sizeof(AstElement));
    result->statements[result->count-1] = toAppend;
    return result;
}

char* remove_quotes(char* s1) {
    size_t len = strlen(s1);
    if (s1[0] == '"' && s1[len - 1] == '"') {
        s1[len - 1] = '\0';
        memmove(s1, s1 + 1, len - 1);
    }
    return s1;
}

AstElement* create_sqrt(char* name){
    AstElement* result = malloc(sizeof (AstElement));
    result->nodetype = 'F';
    result->name = name;
    return result; 
}

AstElement* create_print(char* name){
    AstElement* result = malloc(sizeof (AstElement));
    result->nodetype = 'P';
    result->name = name;
    return result; 
}

AstElement* create_print_string(char* name){
    AstElement* result = malloc(sizeof (AstElement));
    result->nodetype = 'B';
    result->string = name;
    return result; 
}

AstElement* create_read(char* name){
    AstElement* result = malloc(sizeof (AstElement));
    result->nodetype = 'R';
    result->name = name;
    return result; 
}

AstElement* create_declaration(char* type, char* name){
    AstElement* result = malloc(sizeof (AstElement));
    result->nodetype = 'D';
    result->type = type;
    result->name = name;
    return result; 
}

#endif