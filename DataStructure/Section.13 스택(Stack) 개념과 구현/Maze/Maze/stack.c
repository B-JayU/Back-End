//
//  stack.c
//  Maze
//
//  Created by 조팝개발자by_ju on 2021/05/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_STACK_SIZE 100

position stack[MAX_STACK_SIZE];
int top = -1;

void push(position e) {
    
    if (is_full() == 1){
        printf("Stack is full, not push\n");
        return;
    }else{
        stack[++top] = e;
    }
}

int is_full(void) {
    
    if (top == MAX_STACK_SIZE -1)
        return 1;
    return 0;
}

position pop() {
    
    position p;
    if (is_empty() == 1) {
        printf("Stack is empty, not pop\n");
        p.x = -1;
        p.y = -1;
        return p;
    }else{
        return stack[top--];
    }
}

int is_empty(void) {
    
    if (top == -1)
        return 1;
    return 0;
}




