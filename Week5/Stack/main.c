#include "Stack.h"

#include <stdio.h>

int main(void)
{
	struct Stack* head = NULL;

	ErrorCode rezult = push(&head, 5);
	if (rezult != ok)
	{
		printf("Stack if empty!");
	}
	printf("%d ", top(head, &rezult));
	return 0;

}