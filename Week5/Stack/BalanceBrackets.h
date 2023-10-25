#pragma once

#include <stdbool.h>

//Getting a string of arbitrary length
char* getString(ErrorCode* errorCode);

//Checking the bracket sequence
bool isBracketsCorrect(char* string);

//Displaying the result
void printResult(bool result);
