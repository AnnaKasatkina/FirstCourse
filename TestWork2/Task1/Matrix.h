#pragma once

typedef struct Matrix Matrix;

typedef enum
{
    ok,
    inputError
} ErrorCode;

// Create matrix
Matrix* createMatrix(const int rows, const int columns);

// Delete matrix
void deleteMatrix(Matrix** const matrix);

// Read matrix
ErrorCode readMatrix(Matrix* const matrix);

// Print matrix
void printMatrix(const Matrix* const matrix);

// Find saddle points
void findSaddlePoints(const Matrix* const matrix);
