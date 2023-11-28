#pragma once

#include <stdbool.h>

typedef enum CodeBrackets
{
    correct, 
    incorrect, 
    memoryError
} CodeBrackets;

// Checking the bracket sequence
CodeBrackets isBracketsCorrect(const char* const string);
