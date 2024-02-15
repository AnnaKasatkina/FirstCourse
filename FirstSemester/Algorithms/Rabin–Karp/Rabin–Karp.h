#pragma once

#include <stdbool.h>
#include <stdlib.h>

#define NOT_FOUND -1

// Search pattern in text
long searchPattern(const wchar_t* const string, const wchar_t* const pattern, 
    const size_t lengthString, const size_t lengthPattern);
