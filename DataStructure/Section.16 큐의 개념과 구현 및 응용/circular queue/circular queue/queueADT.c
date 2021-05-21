//
//  queueADT.c
//  circular queue
//
//  Created by 조팝개발자by_ju on 2021/05/21.
//

#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_CAPACITY 100

struct queue_type {
    Item* contents;
    int front;
    int rear;
    int size;
    int capacity;
};

void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

int get_size(Queue q) {
    
    return q->size;
}

Queue create(){ // queue type의 객체를 가리키는 pointer
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create : queue could not be created.\n");
    q->contents = malloc(sizeof(Item) * INIT_CAPACITY);
    
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = INIT_CAPACITY;
    
    return q;
}
void reallocate(Queue q) {
    
    Item *tmp = (Item*)malloc(sizeof(Item) * 2 * q->capacity);
    if (tmp == NULL)
        terminate("Error in reallocate : queue could not be allocated.\n");
    
    int j = q->front;
    for (int i = 0; i < q->size; i++) {
        tmp[i] = q->contents[j];
        j = (j + 1) % q->capacity;
    }
    free(q->contents);
    
    q->contents = tmp;
    q->front = 0;
    q->rear = q->size -1;
    q->capacity *= 2;
}

void destroy(Queue q) { 
    
    make_empty(q);
}

void make_empty(Queue q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int is_empty(Queue q) {
    
    if (q->size == 0)
        return 1;
    return 0;
}

int is_full(Queue q) {
    
    if (q->size == INIT_CAPACITY)
        return 1;
    return 0;
}

void enqueue(Queue q, Item i)
{
    
    if (is_full(q) == 1)
        //terminate("Error in enqueue : queue is full.\n");
        reallocate(q);
        
    q->rear = (q->rear + 1)%q->capacity;
    q->contents[q->rear] = i;
    q->size++;
}

Item dequeue(Queue q){
    
    Item i;
    
    if (is_empty(q))
        terminate("Error in dequeue : queue is empty.\n");
    
    i = q->contents[q->front];
    q->front = (q->front +1)% q->capacity;
    
    q->size--;
    
    return i;
}

Item peek(Queue q){
    
    if (is_empty(q))
        terminate("Error in peek : queue is empty.\n");
    return q->contents[q->front];
}

