#include "matrix.h"

#include <stdio.h>

#define ERROR -1
#define ERROR_STRING "Error!"

int main(void) 
{
    int rows = 0;
    int columns = 0;
    printf("Enter the number of rows and columns in the matrix: ");
    if (scanf("%d %d", &rows, &columns) != 2)
    {
        printf(ERROR_STRING);
        return ERROR;
    }

    Matrix* matrix = createMatrix(rows, columns);
    if (matrix == NULL)
    {
        printf(ERROR_STRING);
        return ERROR;
    }

    printf("Enter matrix elements:\n");
    if (readMatrix(matrix) != ok)
    {
        printf(ERROR_STRING);
        deleteMatrix(&matrix);
        return ERROR;
    }

    printMatrix(matrix);
    findSaddlePoints(matrix);

    deleteMatrix(&matrix);

    return 0;
}
