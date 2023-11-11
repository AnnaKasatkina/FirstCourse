#include "Stack.h"

#include <stdlib.h>
#include <malloc.h>

struct Stack
{
    int value;
    Stack* previous;
};

ErrorCode push(Stack** const head, const int value)
{
    Stack* next = (Stack*)malloc(sizeof(Stack));
    if (next == NULL)
    {
        return outOfMemory;
    }
    next->value = value;
    next->previous = *head;
    *head = next;

    return ok;
}

void pop(Stack** const head)
{
    Stack* trash = *head;
    *head = (*head)->previous;
    free(trash);
}

void freeStack(Stack** head)
{
    while (*head != NULL)
    {
        pop(head);
    }
}

int top(const Stack* const head, ErrorCode* const errorCode)
{
    if (head == NULL)
    {
        *errorCode = stackIsEmpty;
        return 0;
    }

    *errorCode = ok;
    return head->value;
}
