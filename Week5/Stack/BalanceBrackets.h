#pragma once

#include "Stack.h"

#include <stdbool.h>

// Getting a string of arbitrary length
char* getString(ErrorCode * const errorCode);

// Checking the bracket sequence
bool isBracketsCorrect(const char* const string);
