//
//  main.c
//  toPostFIX
//
//  Created by 조팝개발자by_ju on 2021/05/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToPost(char* exp);
int is_operator(char t);
void push(char c);
char pop(void);
void operator_process(char c);
char result[100];

#define STACK_MAX_SIZE 100

int stack_top = -1;
char stack_operator[STACK_MAX_SIZE];
int top_index[STACK_MAX_SIZE];

char operator[] = {'+', '-', '*', '/', '(', ')'};
int priority_in[] = {10, 10, 20, 20, 30, 0};
int priority_out[] = {10, 10, 20, 20, 0, 0};

int main(int argc, const char * argv[]) {
    // insert code here...
    char* expr = malloc(sizeof(char)*100);
    
    printf("Input Infix : ");
    gets(expr);
    
    convertToPost(expr);
    printf("%s\n", result);
    return 0;
}

void convertToPost(char* expr) {
    
    char *token = strtok(expr, " ");
    
    while(token != NULL) {
        if (is_operator(token[0]) == -1){
            strcat(result, token);
            strcat(result, " ");
        }
        else if(is_operator(token[0]) > -1){
            operator_process(token[0]);
        }
        
        token = strtok(NULL, " ");
    }
    
    while(stack_top > -1){
        char op = pop();
        if (op != '(' && op != ')'){
            strcat(result, &op);
            strcat(result, " ");
        }
    }
}


int is_operator(char token) {
        
    int arrayLength = sizeof(operator) / sizeof(char);
    for (int i = 0; i < arrayLength; i++){
        if (token == operator[i])
            return i;
    }
    return -1;
}

void operator_process(char token){
    
    if (stack_top == -1){
        push(token);
    }else{
        // char token
        int token_index=-1;
        
        for (int i = 0; i < 6; i++){
            if (operator[i] == token)
                token_index = i;
        }
        if (stack_operator[stack_top] == '(')
            push(token);
        else{
            while(priority_out[top_index[stack_top]] >= priority_in[token_index] && stack_top != -1){
                char op = pop();
                if (op != '(' && op != ')'){
                    strcat(result, &op);
                    strcat(result, " ");
                }
            }
            push(token);
        }
    }
}

void push(char c){
    
    if (stack_top == STACK_MAX_SIZE -1){
        printf("Stack is full\n");
        return;
    }
    
    for (int i = 0; i < 6; i++){
        if (operator[i] == c){
            top_index[++stack_top] = i;
            break;
        }
    }

    stack_operator[stack_top] = c;
}

char pop(void){
    
    if (stack_top == -1){
        printf("stack is empty\n");
        exit(1);
    }
    
    return stack_operator[stack_top--];
}
