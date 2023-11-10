#pragma once

typedef enum ErrorCode
{
	ok,
	stackIsEmpty,
	outOfMemory
}ErrorCode;

//Defeninition struct Stack
typedef struct Stack Stack;

//Add element in Stack
ErrorCode push(Stack** const head, const int value);

//Delete and return top element from Stack
int pop(Stack** const head);

//Delete Stack
ErrorCode freeStack(Stack** head);

//Return top element in Stack
int top(Stack* head, ErrorCode* errorCode);
