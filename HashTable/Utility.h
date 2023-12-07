#pragma once

#include <stdlib.h>

#include "List.h"

// Get a string of arbitrary length
char* getString(FILE* file, size_t* const length);

// Get a string of arbitrary length from file
List* getStringFromFile(const char* const nameFile);
