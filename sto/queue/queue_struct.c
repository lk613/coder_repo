#include "queue_struct.h"

Queue *CreateQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL)
    {
        printf("Assign Memory Failare!\n");
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

bool IsEmptyQueue(Queue *queue)
{
    bool empty_flag = (queue->front == NULL) ? true : false;
    return empty_flag;
}

void Enqueue(Queue *queue, int val)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Assign Memory Failare!\n");
        return;
    }
    new_node->val = val;
    new_node->next = NULL;

    if (queue->front == NULL)
    {
        queue->front = new_node;
        queue->rear = new_node;
    }else
    {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

int Dequeue(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty, dequeue failure !\n");
        return -1;
    }else
    {
        int que_front = queue->front->val;
        Node *temp_node = queue->front;
        queue->front = queue->front->next;

        if (queue->front == NULL)
        {
            queue->rear = NULL;
        }
        free(temp_node);

        return que_front;
    }
}

int Front(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty ! \n");
        return -1;
    }

    return queue->front->val;
}

void FreeQueue(Queue *queue)
{
    while (!IsEmptyQueue(queue))
    {
        Dequeue(queue);
    }

    free(queue);
}