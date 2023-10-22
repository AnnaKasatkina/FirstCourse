#include "Stack.h"

#include <stdlib.h>
#include <malloc.h>

struct Stack
{
	int value;
	struct Stack* previous;
};

ErrorCode push(struct Stack** head, const int value())
{
	struct Stack* next = malloc(sizeof(struct Stack));
	if (next == NULL)
	{
		return stackIsEmpty;
	}
	next->value = value;
	next->previous = *head;
	*head = next;

	return ok;
}

int pop(struct Stack** head)
{
	if (*head == NULL)
	{
		return 404;
	}

	struct Stack* trash = *head;
	int value = trash->value;
	*head = (*head)->previous;
	free(trash);

	return value;
}

ErrorCode freeStack(struct Stack** head)
{
	if (head == NULL || *head == 0)
	{
		return 0;
	}
	struct Stack* next = (*head)->previous;
	free(*head);
	while (next != NULL)
	{
		struct Stack* temp = next;
		next = next->previous;
		free(temp);
	}
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
