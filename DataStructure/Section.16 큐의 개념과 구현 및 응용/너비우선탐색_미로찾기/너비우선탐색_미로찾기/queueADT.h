//
//  queueADT.h
//  너비우선탐색_미로찾기
//
//  Created by 조팝개발자by_ju on 2021/05/21.
//

#ifndef queueADT_h
#define queueADT_h

#include <stdio.h>

typedef int Item;
typedef struct queue_type* Queue;
typedef struct point position;

Queue create(void);
void reallocate(Queue q);
void terminate(const char *message);
void destroy(Queue q);
void make_empty(Queue q);
int is_empty(Queue q);
int is_full(Queue q);
void enqueue(Queue q, position p);
//void enqueue(Queue q, Item i);
position dequeue(Queue q);
//Item dequeue(Queue q);
position peek(Queue q);
//Item peek(Queue q);
int get_size(Queue q);

#endif /* queueADT_h */
