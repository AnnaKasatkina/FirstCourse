#include "Stack.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LEN 256

bool isBracketsCorrect(char *string)
{
	struct Stack* brackets = NULL;
	char open[] = "{([";
	char close[] = "})]";
	for (char* character = string; *character != '\0'; ++character) {
		if (strchr(open, *character) != NULL) {
			push(&brackets, *character);
		}
		if (strchr(close, *character) != NULL)
		{
			if (strchr(close, *character) - close != strchr(open, pop(&brackets)) - open)
				return false;
		}
	}
	return true;
}

void printResult(bool result)
{
	if (result)
	{
		printf("Correct");
	}
	else
	{
		printf("Incorrect");
	}
}

int main(void)
{
	char string[LEN] = "";
	gets(string);

	bool result = isBracketsCorrect(string);
	printResult(result);
	
	return 0;
}