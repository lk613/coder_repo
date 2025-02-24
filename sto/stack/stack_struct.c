#include "stack_struct.h"


/**
 * @brief Create a stack object by LinkList
 * 
 * @return Stack* 
 */


Stack *CreateStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void Push(Stack *stack, int val)
{
    Node *insert_node = (Node *)malloc(sizeof(Node));
    insert_node->val = val;
    insert_node->next = stack->top;
    stack->top = insert_node;
}

int Pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        return -1;    
    }
    
    int peek_val = stack->top->val;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return peek_val;
}

int Top(Stack *stack)
{
    if (stack->top == NULL)
    {
        return -1;
    }
    return stack->top->val;
}

int IsEmpty(Stack *stack)
{
    return stack->top == NULL;
}