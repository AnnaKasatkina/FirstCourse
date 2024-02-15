#pragma once

#include "List.h"

// Fill the List with indexes
void fillList(const size_t amount, List* const list, ErrorCode* errorCode);

// Calculate a safe place
size_t kill(const size_t gap, List* const list);
