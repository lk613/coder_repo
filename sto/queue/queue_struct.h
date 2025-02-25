#ifndef QUEUE_STRUCT_H
#define QUEUE_STRUCT_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int val;
    struct Node *next;
}Node;

typedef struct Queue
{
    Node *front;        // 队头
    Node *rear;         // 队尾
}Queue;

Queue *CreateQueue();
bool IsEmptyQueue(Queue *queue);
void Enqueue(Queue *queue, int val);
int Dequeue(Queue *queue);
int Front(Queue *queue);
void FreeQueue(Queue *queue);

#endif