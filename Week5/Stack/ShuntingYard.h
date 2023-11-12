#pragma once

#include "Stack.h"

#define ERROR -1

// Getting a string of arbitrary length
char* getString(ErrorCode* const errorCode, size_t* length);

// Conversion from infix form to postfix form
ErrorCode shuntingYard(const char* const string, char* output);
