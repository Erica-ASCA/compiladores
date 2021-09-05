#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 256

char stack[MAX];
int top = -1;

void push(char i){
    stack[++top] = i;
}

int pop(void){
    return (stack[top--]);
}

int precedence(char element){
    switch(element){
        case '#':
            return 0;
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;    
    }
}

void convert_to_postfix(char *infix, char *postfix){
    char ch, element;
    int i = 0, k = 0;

    push('#');
    while((ch = infix[i++]) != '\0'){
        if(ch == '('){
            push(ch);
        }
        else if (isalnum(ch)){
            postfix[k++] = ch;
        }
        else if (ch == ')'){
            while(stack[top] != '('){
                postfix[k++] = pop();
            }
            element = pop();
        } else {
            while(precedence(stack[top]) >= precedence(ch)){
                postfix[k++] = pop();
            }
            push(ch);
        }
    }
    while (stack[top] != '#'){
        postfix[k++] = pop();
    }
    postfix[k] = 0;
}

int calculate(char *postfix){
    char ch;
    int i = 0;
    int a, b;
    while((ch = postfix[i++]) != 0){
        if(isdigit(ch)){
            push(ch-'0');
        }
        else{
            a = pop();
            b = pop();
            switch(ch){
                case '+':
                    push(a + b);
                    break;
                case '-': 
                    push(a - b);
                    break;
                case '*': 
                    push(a * b);
                    break;
                case '/': 
                    push(a / b);
                    break;
            }
        }
    }
    return stack[top];
}

void main(int argc, char** argv){
    int a, b;
    char input[80], postf[80];

    //for reading values from file
    if(argc == 1){
        while(fgets(input, sizeof(input), stdin) != NULL){
            input[strlen(input) - 1] = 0;
            convert_to_postfix(input, postf);
            printf("Result : %d\n", calculate(postf));
        }
    }

    //for reading values from command line
    else{
        strcpy(input, argv[1]);
        convert_to_postfix(input, postf);
        printf("Result : %d\n", calculate(postf));
    }
}