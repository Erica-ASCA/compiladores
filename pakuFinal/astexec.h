#ifndef ASTEXEC_H
#define ASTEXEC_H

#include "astgen.h"
#include "hashtable.h"
#include "math.h"

int operator(char* op, int left, int right);
static void run_statement(hashtable *htable, AstElement* node);
int eval_expr(hashtable *htable, AstElement* node);
static void exec(hashtable *htable, AstElement* a);

int eval_expr(hashtable *htable, AstElement* node)
{    
    int left;
    int right;

    Variable* variable = (Variable*)malloc(sizeof(Variable));

    switch (node->nodetype)
    { 
    case 'V': 
        return node->val;
        break;
    case 'N':
        return hash_lookup(htable,node->name)->value;
        break;
    case 'E':
        left = eval_expr(htable,node->left);
        right = eval_expr(htable,node->right);
        return operator(node->op, left, right);
    case 'C':
        int number = hash_lookup(htable,node->left->name)->value;
        if (number != 0)
            left = 0;
        if (number == 0)
            left = 1;
        return left;
    case 'F':
        int result;
        result = sqrt(hash_lookup(htable,node->name)->value);
        return result;
    break;

    default:
        printf("expression not found %c", node->nodetype);
    }
    return 0;
}

static void run_statement(hashtable *htable, AstElement* node)
{
    Variable* variable = (Variable*)malloc(sizeof(Variable));
    int result;

    switch (node->nodetype)
    {
    case 'S':
        exec(htable, node);
        break;
    
    case 'P':
        printf("%s = %f\n", node->name, hash_lookup(htable, node->name)->value);
        break;

    case 'B':
        printf("%s\n", node->string);
        break;    

    case 'R':     
        variable->name = node->name;
        printf("Value: ");
        scanf("%lf", &variable->value );
        hash_insert(htable, node->name, variable);
        break;

    case 'I':
        result = eval_expr(htable, node->cond);

        if(result){
            exec(htable, node->left);
        }else{
            if(node->right){
                exec(htable, node->right);
            }            
        }
        break;

    case 'D':
        variable->name = node->name;
        hash_insert(htable, node->name, variable);
        break;

    case 'A':               
        variable->name = node->name;
        variable->value = eval_expr(htable, node->right);
        hash_insert(htable, node->name,variable);
        break;
    
    default:
        break;
    }
}


static void exec(hashtable *htable, AstElement* a)
{   
    int i;
    for(i=0; i < a->count; i++)
    {
        run_statement(htable, a->statements[i]);
    }
}

int operator(char* op, int left, int right){
    if (strcmp(op, "+") == 0){
        return left + right;
    } else if (strcmp(op, "-") == 0){
        return left - right;
    } else if (strcmp(op, "/") == 0){
        return left / right;
    } else if (strcmp(op, "*") == 0){
        return left * right;
    } else if (strcmp(op, ">=" )== 0){
        return left >= right;
    } else if (strcmp(op, "<=") == 0){
        return left <= right;
    } else if (strcmp(op, "!=") == 0){
        return left != right;
    } else if (strcmp(op, "<") == 0){
        return left < right;
    } else if (strcmp(op, ">") == 0){
        return left > right;
    } else if (strcmp(op, "==") == 0){
        return left == right;
    } else if (strcmp(op, "&&") == 0){
        return left && right;
    } else if (strcmp(op, "||") == 0){
        return left || right;
    } else if (strcmp(op, "%") == 0){
        int a = left;
        int b = right;
        return a % b;
    } else {
        return 0;
    }
}

#endif