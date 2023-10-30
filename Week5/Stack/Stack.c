#include "Stack.h"

#include <stdlib.h>
#include <malloc.h>

struct Stack
{
    int value;
    Stack* previous;
};

ErrorCode push(Stack** head, int value)
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

void pop(Stack** head)
{
    if (*head == NULL)
    {
        return;
    }

    Stack* trash = *head;
    *head = (*head)->previous;
    free(trash);
}

ErrorCode freeStack(Stack** head)
{
    while (*head != NULL)
    {
        pop(head);
    }
    return ok;
}

int top(Stack* head, ErrorCode* errorCode)
{
    if (head == NULL)
    {
        *errorCode = stackIsEmpty;
        return 0;
    }

    *errorCode = ok;
    return head->value;
}
