#include <stdio.h>
#include <stdlib.h>

int **matrixMultiplication(int **matrix1, int row1, int column1, int **matrix2, int row2, int column2)
{

    if (row2 != column1)
    {
        printf("\nMultiplication not possible.");
        return;
    }

    int **result = (int **)malloc(row2 * sizeof(int *));
    for (int index = 0; index < row2; index++)
    {
        result[index] = (int *)malloc(column2 * sizeof(int));
    }

    for (int index1 = 0; index1 < row1; index1++)
    {
        for (int index2 = 0; index2 < column1; index2++)
        {
            result[index1][index2] = 0;
            for (int index3 = 0; index3 < column2; index3++)
            {
                result[index1][index2] += matrix1[index1][index3] * matrix2[index3][index2];
            }
        }
    }
    return result;
}

void elements(int row, int column, int **matrix)
{
    printf("\nEnter %d elements for rows and %d elements for columns.\n", row, column);
    for (int index1 = 0; index1 < row; index1++)
    {
        for (int index2 = 0; index2 < column; index2++)
        {
            scanf("%d", &matrix[index1][index2]);
        }
        printf("\n");
    }
}

int main()
{

    int row1, row2, column1, column2;
    printf("Enter number of rows for matrix 1: ");
    scanf("%d", &row1);
    printf("\nEnter number of columns for matrix 1: ");
    scanf("%d", &column1);
    printf("\nEnter number of rows for matrix 2: ");
    scanf("%d", &row2);
    printf("\nEnter number of columns for matrix 2: ");
    scanf("%d", &column2);

    int **matrix1 = (int **)malloc(row1 * sizeof(int *));
    for (int index = 0; index < row1; index++)
    {
        matrix1[index] = (int *)malloc(column1 * sizeof(int));
    }
    int **matrix2 = (int **)malloc(row2 * sizeof(int *));
    for (int i = 0; i < row2; i++)
    {
        matrix2[i] = (int *)malloc(column2 * sizeof(int));
    }

    printf("\n Input first matrix: ");
    elements(row1, column1, matrix1);
    printf("\n Input second matrix: ");
    elements(row2, column2, matrix2);

    int **result = matrixMultiplication(matrix1, row1, column1, matrix2, row2, column2);

    printf("Multiplied matrix is:\n");
    for (int index1 = 0; index1 < row1; index1++)
    {
        for (int index2 = 0; index2 < column1; index2++)
        {
            printf("%d ", result[index1][index2]);
        }
        printf("\n");
    }

    for (int index = 0; index < row1; index++)
    {
        free(matrix1[index]);
    }
    free(matrix1);

    for (int index = 0; index < row2; index++)
    {
        free(matrix2[index]);
    }
    free(matrix2);
    for (int index = 0; index < row2; index++)
    {
        free(result[index]);
    }
    free(result);

    return 0;
}

