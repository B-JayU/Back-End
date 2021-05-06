//
//  stack.h
//  linkedList_ParenChecker
//
//  Created by 조팝개발자by_ju on 2021/05/06.
//

#ifndef stack_h
#define stack_h

struct node {
    char data;
    struct node *next;
};

typedef struct node Node;

int is_empty(void);
void push(char ch);
char pop(void);
char peek(void);


#endif /* stack_h */

