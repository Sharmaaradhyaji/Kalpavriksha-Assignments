#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int **data;
    int row;
    int column;
} matrix;

matrix multiplication(matrix Matrix1, matrix Matrix2)
{
    if (Matrix2.row != Matrix1.column)
    {
        printf("\nMultiplication not possible.");
        exit(1);
    }

    matrix result;
    result.row = Matrix1.row;
    result.column = Matrix2.column;

    result.data = (int **)malloc(result.row * sizeof(int *));
    for (int index = 0; index < result.row; index++)
    {
        result.data[index] = (int *)malloc(result.column * sizeof(int));
    }

    for (int index1 = 0; index1 < result.row; index1++)
    {
        for (int index2 = 0; index2 < result.column; index2++)
        {
            result.data[index1][index2] = 0;
            for (int index3 = 0; index3 < Matrix1.column; index3++)
            {
                result.data[index1][index2] += Matrix1.data[index1][index3] * Matrix2.data[index3][index2];
            }
        }
    }
    return result;
}

void enterMatrix(matrix *Matrix)
{
    printf("\nEnter %d elements for rows and %d elements for columns.\n", Matrix->row, Matrix->column);
    for (int index1 = 0; index1 < Matrix->row; index1++)
    {
        for (int index2 = 0; index2 < Matrix->column; index2++)
        {
            scanf("%d", &Matrix->data[index1][index2]);
        }
        printf("\n");
    }
}

void freeMemory(matrix Matrix){
    for (int i = 0; i < Matrix.row; i++) {
        free(Matrix.data[i]);
    }
    free(Matrix.data);
}

int main()
{

    matrix matrix1;
    matrix matrix2;
    matrix result;

    printf("Enter number of rows for matrix 1: ");
    scanf("%d", &matrix1.row);
    printf("\nEnter number of columns for matrix 1: ");
    scanf("%d", &matrix1.column);
    
    matrix1.data = (int **)malloc(matrix1.row * sizeof(int *));
    for (int index = 0; index < matrix1.row; index++)
    {
        matrix1.data[index] = (int *)malloc(matrix1.column * sizeof(int));
    }

    printf("\n Input first matrix: ");
    enterMatrix(&matrix1);

    printf("\nEnter number of rows for matrix 2: ");
    scanf("%d", &matrix2.row);
    printf("\nEnter number of columns for matrix 2: ");
    scanf("%d", &matrix2.column);

    matrix2.data = (int **)malloc(matrix2.row * sizeof(int *));
    for (int i = 0; i < matrix2.row; i++)
    {
        matrix2.data[i] = (int *)malloc(matrix2.column * sizeof(int));
    }
    printf("\n Input second matrix: ");
    enterMatrix(&matrix2);

    result = multiplication(matrix1, matrix2);

    printf("Multiplied matrix is:\n");
    for (int index1 = 0; index1 < result.row; index1++)
    {
        for (int index2 = 0; index2 < result.column; index2++)
        {
            printf("%d ", result.data[index1][index2]);
        }
        printf("\n");
    }

    freeMemory(matrix1);
    freeMemory(matrix2);
    freeMemory(result);

    return 0;
}


