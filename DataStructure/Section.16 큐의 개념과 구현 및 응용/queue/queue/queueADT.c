//
//  queueADT.c
//  queue
//
//  Created by 조팝개발자by_ju on 2021/05/21.
//

#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    Item data;
    struct node *next;
};

struct queue_type {
    struct node *front;
    struct node *rear;
    int size;
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
        terminate("Error in create : qeuee could not be created.\n");
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    
    return q;
}

void destroy(Queue q) {
    
    make_empty(q);
    free(q);
}

void make_empty(Queue q) {
    while(!is_empty(q))
        dequeue(q);
    q->size = 0;
}

int is_empty(Queue q) {
    
    if (q->front == NULL)
        return 1;
    return 0;
}

void enqueue(Queue q, Item i)
{
    struct node* new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in enqueue : queue is full.");
    
    new_node->data = i;
    new_node->next = NULL;
    
    if (q->front == NULL) { // 큐가 비어있으면 front에 추가하기
        q->front = new_node;
        q->rear = new_node;
    }
    else{
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
}

Item dequeue(Queue q){
    
    struct node* old_front;
    Item i;
    
    if (is_empty(q))
        terminate("Error in dequeue : queue is empty.\n");
    
    old_front = q->front;
    i = old_front->data;
    
    q->front = old_front->next;
    old_front->next = NULL;
    
    if (q->front == NULL)
        q->rear = NULL;
    
    free(old_front);
    q->size--;
    
    return i;
}

Item peek(Queue q){
    
    if (is_empty(q)){
        terminate("Error in peek : queue is empty.\n");
    }
    return q->front->data;
}
