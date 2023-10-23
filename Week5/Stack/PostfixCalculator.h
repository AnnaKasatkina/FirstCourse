#pragma once

//Getting a string of arbitrary length
char* getString(ErrorCode* errorCode);

//Removing spaces from a string
void removeSpaces(char* string);

//Postfix Calculator function
int postfixCalculator(char* string);
