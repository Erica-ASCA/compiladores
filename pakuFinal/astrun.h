#ifndef ASTRUN_H
#define ASTRUN_H

#include "astcreate.h"
#include "hashtable.h"
#include "math.h"

int operator(char* op, int l, int r);
static void run_statement(hashtable *table, AstElement* node);
int eval_expr(hashtable *table, AstElement* node);
static void exec(hashtable *table, AstElement* a);

int eval_expr(hashtable *table, AstElement* node)
{    
    int l;
    int r;

    Variable* variable = (Variable*)malloc(sizeof(Variable));

    switch (node->command)
    { 
    case 'V': 
        return node->val;
        break;
    case 'N':
        return hash_lookup(table,node->name)->value;
        break;
    case 'E':
        l = eval_expr(table,node->l);
        r = eval_expr(table,node->r);
        return operator(node->op, l, r);
    case 'C':
        int number = hash_lookup(table,node->l->name)->value;
        if (number != 0)
            l = 0;
        if (number == 0)
            l = 1;
        return l;
    case 'F':
        int result;
        result = sqrt(hash_lookup(table,node->name)->value);
        return result;
    break;

    default:
        printf("expression not found %c", node->command);
    }
    return 0;
}

static void run_statement(hashtable *table, AstElement* node)
{
    Variable* variable = (Variable*)malloc(sizeof(Variable));
    int result;

    switch (node->command)
    {
    case 'S':
        exec(table, node);
        break;
    
    case 'P':
        printf("%s = %f\n", node->name, hash_lookup(table, node->name)->value);
        break;

    case 'B':
        printf("%s\n", node->string);
        break;    

    case 'R':     
        variable->name = node->name;
        printf("Input: ");
        scanf("%lf", &variable->value );
        hash_insert(table, node->name, variable);
        break;

    case 'I':
        result = eval_expr(table, node->cond);

        if(result){
            exec(table, node->l);
        }else{
            if(node->r){
                exec(table, node->r);
            }            
        }
        break;

    case 'D':
        variable->name = node->name;
        hash_insert(table, node->name, variable);
        break;

    case 'A':               
        variable->name = node->name;
        variable->value = eval_expr(table, node->r);
        hash_insert(table, node->name,variable);
        break;
    
    default:
        break;
    }
}


static void exec(hashtable *table, AstElement* a)
{   
    int i;
    for(i=0; i < a->count; i++)
    {
        run_statement(table, a->statements[i]);
    }
}

int operator(char* op, int l, int r){
    if (strcmp(op, "+") == 0){
        return l + r;
    } else if (strcmp(op, "-") == 0){
        return l - r;
    } else if (strcmp(op, "/") == 0){
        return l / r;
    } else if (strcmp(op, "*") == 0){
        return l * r;
    } else if (strcmp(op, ">=" )== 0){
        return l >= r;
    } else if (strcmp(op, "<=") == 0){
        return l <= r;
    } else if (strcmp(op, "!=") == 0){
        return l != r;
    } else if (strcmp(op, "<") == 0){
        return l < r;
    } else if (strcmp(op, ">") == 0){
        return l > r;
    } else if (strcmp(op, "==") == 0){
        return l == r;
    } else if (strcmp(op, "&&") == 0){
        return l && r;
    } else if (strcmp(op, "||") == 0){
        return l || r;
    } else if (strcmp(op, "%") == 0){
        int a = l;
        int b = r;
        return a % b;
    } else {
        return 0;
    }
}

#endif