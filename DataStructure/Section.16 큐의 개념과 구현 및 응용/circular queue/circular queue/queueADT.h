//
//  queueADT.h
//  circular queue
//
//  Created by 조팝개발자by_ju on 2021/05/21.
//

#ifndef queueADT_h
#define queueADT_h

#include <stdio.h>

typedef int Item;
typedef struct queue_type* Queue;

Queue create(void);
void reallocate(Queue q);
void destroy(Queue q);
void make_empty(Queue q);
int is_empty(Queue q);
int is_full(Queue q);
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item peek(Queue q);
int get_size(Queue q);

#endif /* queueADT_h */
