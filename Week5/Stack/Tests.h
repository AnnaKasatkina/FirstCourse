#pragma once

#include <stdbool.h>

//Print rthe trst result
void printResultTest(const bool rezult, const char* const nameTest);

//Check the correct sequence
bool testCorrectSequence();

//Check the incorrect sequence
bool testIncorrectSequence();

//Check the sequence without brackets
bool testWithoutBrackets();

//Combining results
bool resultTests();
