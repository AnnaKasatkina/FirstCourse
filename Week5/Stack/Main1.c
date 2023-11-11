#include "Stack.h"

#include <stdio.h>


int main(void)
{
	Stack* digits = NULL;
	push(&digits, 0);
	push(&digits, 15);
	push(&digits, 23);

	ErrorCode error = ok;

	printf("%d", top(digits, &error));

	freeStack(&digits);

	int value = top(digits, &error);
	if (error == ok)
	{
		printf("%d", value);
	}

	return 0;
}
