#pragma once

#include "Stack.h"

#define ERROR -1

// Getting a string of arbitrary length
int getString(ErrorCode* errorCode, char** string);

// Conversion from infix form to postfix form
ErrorCode shuntingYard(char* string, char* output);
