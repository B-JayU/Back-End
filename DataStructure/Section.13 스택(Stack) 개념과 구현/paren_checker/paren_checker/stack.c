//
//  stack.c
//  paren_checker
//
//  Created by 조팝개발자by_ju on 2021/05/06.
//

#include <stdio.h>
#include <string.h>
#include "stack.h"

#define MAX_CAPACITY 100

char stack[MAX_CAPACITY];
int top = -1;

int is_empty(void){
    
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(char ch){
    
    if (top == MAX_CAPACITY - 1) {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = ch;
}

char pop(void){
    return stack[top--];
}

char peek(){
    return stack[top];
}
