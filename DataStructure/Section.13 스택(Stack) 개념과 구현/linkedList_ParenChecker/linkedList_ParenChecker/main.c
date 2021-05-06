//
//  main.c
//  linkedList_ParenChecker
//
//  Created by 조팝개발자by_ju on 2021/05/06.
//

#include <stdio.h>
#include <string.h>
#include "stack.h"

#define MAX_LENGTH 100

char OPEN[] = "([{";
char CLOSE[] = ")]}";

int is_balanced(char *expr);
int is_open(char ch);
int is_close(char ch);


int main(void){
    
    char expr[MAX_LENGTH];
    printf("Input expression: ");
    scanf("%s", expr);
    
    if (is_balanced(expr))
        printf("%s : balanced. \n", expr);
    else
        printf("%s : unbalanced. \n", expr);
    return 0;
}

int is_balanced(char *expr){
    
    int balanced = 1;
    int index = 0;
    while (balanced && index < strlen(expr)) {
        char ch = expr[index];
        if (is_open(ch) > -1)
            push(ch);
        else if(is_close(ch) > -1){
            if (is_empty()) {
                balanced = 0;
                break;
            }
            char top_ch = pop();
            if (is_open(top_ch) != is_close(ch))
                balanced = 0;
        }
        index++;
    }
    return (balanced == 1 && is_empty() == 1);
}

int is_open(char ch) {
    
    int index = 0;
    while(index < strlen(OPEN)){
        if (ch == OPEN[index++])
            return index;
    }
    return -1;
}

int is_close(char ch){
    
    int index = 0;
    while(index < strlen(CLOSE)){
        if (ch == CLOSE[index++])
            return index;
    }
    return -1;
}

