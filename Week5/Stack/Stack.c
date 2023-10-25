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
    Stack* next = (int *)malloc(sizeof(Stack));
    if (next == NULL)
    {
        return outOfMemory;
    }
    next->value = value;
    next->previous = *head;
    *head = next;

    return ok;
}

ErrorCode pop(Stack** head)
{
    if (*head == NULL)
    {
        return stackIsEmpty;
    }

    Stack* trash = *head;
    *head = (*head)->previous;
    free(trash);

    return ok;
}

ErrorCode freeStack(Stack** head)
{
    Stack* next = (*head)->previous;
    free(*head);
    while (next != NULL)
    {
        Stack* temp = next;
        next = next->previous;
        free(temp);
    }
    *head = next;

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
