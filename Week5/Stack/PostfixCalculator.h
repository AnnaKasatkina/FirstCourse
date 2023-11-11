#pragma once

#include "Stack.h"

//Getting a string of arbitrary length
char* getString(ErrorCode* const errorCode);

//Postfix Calculator function
int postfixCalculator(char* string, ErrorCode* errorCode);
