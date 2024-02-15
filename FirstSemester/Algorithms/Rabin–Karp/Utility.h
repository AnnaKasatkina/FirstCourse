#pragma once

#include <stdlib.h>
#include <stdio.h>

// Get a string of arbitrary length
wchar_t* getString(FILE* file, size_t* const length);

// Get a string of arbitrary length from file
wchar_t* getStringFromFile(const char* const nameFile, size_t* const length);
