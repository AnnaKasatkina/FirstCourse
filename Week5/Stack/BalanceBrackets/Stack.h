#pragma once

typedef enum ErrorCode
{
    ok,
    stackIsEmpty,
    outOfMemory,
    errorInput
}ErrorCode;

// Defeninition struct Stack
typedef struct Stack Stack;

// Add element in Stack
ErrorCode push(Stack** const head, const int value);

// Delete top element from Stack
void pop(Stack** const head);

// Delete Stack
void freeStack(Stack** const head);

// Return top element in Stack
int top(const Stack* const head, ErrorCode* const errorCode);
