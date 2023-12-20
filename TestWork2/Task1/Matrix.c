#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

struct Matrix
{
    int** data;
    int rows;
    int columns;
};

Matrix* createMatrix(const int rows, const int columns) 
{
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    if (matrix == NULL)
    {
        return NULL;
    }
    matrix->rows = rows;
    matrix->columns = columns;

    matrix->data = (int**)calloc(rows, sizeof(int*));
    if (matrix->data == NULL)
    {
        free(matrix);
        return NULL;
    }
    for (size_t i = 0; i < rows; ++i) 
    {
        matrix->data[i] = (int*)malloc(columns * sizeof(int));
    }

    return matrix;
}

void deleteMatrix(Matrix** const matrix) 
{
    for (size_t i = 0; i < (*matrix)->rows; ++i)
    {
        free((*matrix)->data[i]);
    }
    free((*matrix)->data);
    free(*matrix);
    *matrix = NULL;
}

ErrorCode readMatrix(Matrix* const matrix)
{
    for (size_t i = 0; i < matrix->rows; ++i)
    {
        for (size_t j = 0; j < matrix->columns; ++j)
        {
            if (scanf("%d", &matrix->data[i][j]) != 1)
            {
                return inputError;
            }
        }
    }
    return ok;
}

void printMatrix(const Matrix* const matrix) 
{
    printf("Matrix:\n");
    for (size_t i = 0; i < matrix->rows; ++i) 
    {
        for (size_t j = 0; j < matrix->columns; ++j)
        {
            printf("%d\t", matrix->data[i][j]);
        }
        printf("\n");
    }
}

void findSaddlePoints(const Matrix* const matrix) 
{
    printf("Saddle Points:\n");

    for (size_t i = 0; i < matrix->rows; ++i)
    {
        int minInRow = matrix->data[i][0];
        size_t minColIndex = 0;

        for (size_t j = 1; j < matrix->columns; ++j)
        {
            if (matrix->data[i][j] < minInRow) 
            {
                minInRow = matrix->data[i][j];
                minColIndex = j;
            }
        }

        size_t isSaddlePoint = 1;

        for (size_t k = 0; k < matrix->rows; ++k) 
        {
            if (matrix->data[k][minColIndex] > minInRow) 
            {
                isSaddlePoint = 0;
                break;
            }
        }

        if (isSaddlePoint) 
        {
            printf("(%zd, %zd): %d\n", i, minColIndex, minInRow);
        }
    }
}
