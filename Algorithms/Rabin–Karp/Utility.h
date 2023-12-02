#pragma once

#include <stdlib.h>

// Get a string of arbitrary length
wchar_t* getString(size_t* length);

// Get a string of arbitrary length from file
wchar_t* getStringFromFile(const char* const nameFile, size_t* length);
