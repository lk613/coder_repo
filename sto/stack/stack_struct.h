#ifndef STACK_STRUCT_H
#define STACK_STRUCT_H
#include <stdlib.h>


typedef struct Node
{
    int val;
    struct Node *next;
}Node;

typedef struct Stack
{
    Node *top;
}Stack;

extern Stack *CreateStack();
extern void Push(Stack *stack, int val);
extern int Pop(Stack *stack);
extern int Top(Stack *stack);
extern int IsEmpty(Stack *stack);

#endif // STACK_STRUCT_H

