//
//  main.c
//  postfix
//
//  Created by 조팝개발자by_ju on 2021/05/11.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define MAX_STACK_SIZE 100

static char OPERATORS[] = "+-*/";
int operand_stack[MAX_STACK_SIZE];
int stack_top = -1;
int is_operator(char ch);
int eval(char* expr);
int eval_op(char ch);
void push(int v);
int pop(void);

int main(int argc, const char * argv[]) {
    
    char* expr= malloc(sizeof(char) * 100);
    int result;
    
    printf("Input postfix : ");
    gets(expr);
    //printf("%s\n", expr);
    
    result = eval(expr);
    printf("%d\n", result);
    
    return 0;
}

int is_operator(char ch) {
    for (int i = 0; i < strlen(OPERATORS); i++)
        if (OPERATORS[i] == ch)
            return i;
    return -1;
}

int eval(char *expr){
    
    int result;
    char* token = strtok(expr, " ");
    while(token != NULL) {
        if (is_operator(token[0]) == -1){ // 연산자가 아니면
            int value = atoi(token);
            push(value);
        }else if (is_operator(token[0]) > -1){ // 연산자
            result = eval_op(token[0]);
            push(result);
        }
        token = strtok(NULL, " ");
    }
    result = pop();
    
    return result;
}

int eval_op(char tok){
    
    int oprnd2 = pop();
    int oprnd1 = pop();
    int result = 0;
    
    switch(tok){
        case '+':
            result = oprnd1 + oprnd2;
            break;
        case '-':
            result = oprnd1 - oprnd2;
            break;
        case '*':
            result = oprnd1 * oprnd2;
            break;
        case '/':
            result = oprnd1 / oprnd2;
    }
    
    return result;
}

void push(int v) {
    
    if (stack_top == MAX_STACK_SIZE -1){
        printf("Stack is full\n");
        return;
    }
    
    operand_stack[++stack_top] = v;
}

int pop(void) {
    if (stack_top < 0){
        printf("Stack is empty\n");
        exit(1);
    }
    
    return operand_stack[stack_top--];
}
