#pragma once

#include <stdbool.h>
#include <stdlib.h>

// Search pattern in text
bool searchPattern(const wchar_t* const string, const wchar_t* const pattern, 
    const size_t lengthString, const size_t lengthPattern);
