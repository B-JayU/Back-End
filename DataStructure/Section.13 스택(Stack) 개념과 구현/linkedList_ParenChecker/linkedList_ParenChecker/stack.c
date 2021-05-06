//
//  stack.c
//  linkedList_ParenChecker
//
//  Created by 조팝개발자by_ju on 2021/05/06.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


Node *top = NULL;

#define MAX_CAPACITY 100

char stack[MAX_CAPACITY];

int is_empty(void){
    
    if (top == NULL)
        return 1;
    else
        return 0;
}

void push(char ch){
    
    Node *temp = malloc(sizeof(Node));
    temp->data = ch;
    temp->next = top;
    top = temp;
    
}

char pop(void){
    
    if (is_empty())
        return '\0';
    char temp = top->data;
    top= top->next;

    return temp;
}

char peek(){
    
    char temp= top->data;
    
    return temp;
}

