#pragma once

typedef enum ErrorCode
{
	ok,
	stackIsEmpty,
	outOfMemory
}ErrorCode;

//Объявление структуры Стека
typedef struct Stack Stack;

//Функция добавления элемента в Стек
ErrorCode push(Stack** head, const int value());

//Функция удаления и вывода элемента из Стека
int pop(Stack** head);

//Функция удаления Стека
ErrorCode freeStack(Stack** head);

//Функция вывода верхнего элемента Стека
int top(Stack* head, ErrorCode* errorCode);
