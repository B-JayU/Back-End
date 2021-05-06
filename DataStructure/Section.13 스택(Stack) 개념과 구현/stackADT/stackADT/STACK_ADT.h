//
//  STACK_ADT.h
//  stackADT
//
//  Created by 조팝개발자by_ju on 2021/05/06.
//

#ifndef STACK_ADT_h
#define STACK_ADT_h

#include <stdio.h>

typedef int Item;

//typedef struct {
//    Item *contents;
//    int top;
//    int size;
//}stack_type;

typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
int is_empty(Stack s);
int is_full(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);
Item peek(Stack s);

#endif /* STACK_ADT_h */
