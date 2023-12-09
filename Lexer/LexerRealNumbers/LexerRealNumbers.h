#pragma once

enum State {
    START,
    INTEGER,
    DECIMAL,
    EXPONENT_SIGN,
    EXPONENT_DIGIT
};

// Perform a lexical analysis
int lexer(const char* string);
