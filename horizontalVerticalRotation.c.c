#include <stdio.h>

#include <stdlib.h>

void verticalFlip(int matrix[10][10], int sizeOfMatrix)
{
    for (int index1 = 0; index1 < sizeOfMatrix / 2; index1++)
    {
        for (int index2 = 0; index2 < sizeOfMatrix; index2++)
        {
            int temp = matrix[index1][index2];
            matrix[index1][index2] = matrix[sizeOfMatrix - index1 - 1][index2];
            matrix[sizeOfMatrix - index1 - 1][index2] = temp;
        }
    }

    for (int index1 = 0; index1 < sizeOfMatrix; index1++)
    {
        for (int index2 = 0; index2 < sizeOfMatrix; index2++)
        {
            printf("%d ", matrix[index1][index2]);
        }
        printf("\n");
    }
}

void horizontalFlip(int matrix[10][10], int sizeOfMatrix)
{
    for (int index1 = 0; index1 < sizeOfMatrix; index1++)
    {
        for (int index2 = 0; index2 < sizeOfMatrix / 2; index2++)
        {
            int temp = matrix[index1][index2];
            matrix[index1][index2] = matrix[index1][sizeOfMatrix - index2 - 1];
            matrix[index1][sizeOfMatrix - index2 - 1] = temp;
        }
    }

    for (int index1 = 0; index1 < sizeOfMatrix; index1++)
    {
        for (int index2 = 0; index2 < sizeOfMatrix; index2++)
        {
            printf("%d ", matrix[index1][index2]);
        }
        printf("\n");
    }
}

int main()
{

    int sizeOfMatrix;
    printf("Enter the number of rows: ");
    scanf("%d", &sizeOfMatrix);

    int **matrix = (int **)malloc(sizeOfMatrix * sizeof(int *));
    for (int index = 0; index < sizeOfMatrix; index++)
    {
        matrix[index] = (int *)malloc(sizeOfMatrix * sizeof(int));
    }

    printf("\nEnter Elements: ");
    for (int index1 = 0; index1 < sizeOfMatrix; index1++)
    {
        for (int index2 = 0; index2 < sizeOfMatrix; index2++)
        {
            scanf("%d", &matrix[index1][index2]);
        }
    }

    printf("\nHorizontal flip: \n");
    horizontalFlip(matrix, sizeOfMatrix);

    for (int index1 = 0; index1 < sizeOfMatrix; index1++)
    {
        for (int index2 = 0; index2 < sizeOfMatrix / 2; index2++)
        {
            int temp = matrix[index1][index2];
            matrix[index1][index2] = matrix[index1][sizeOfMatrix - index2 - 1];
            matrix[index1][sizeOfMatrix - index2 - 1] = temp;
        }
    }

    printf("\nVertical flip: \n");
    verticalFlip(matrix, sizeOfMatrix);

    for (int index = 0; index < sizeOfMatrix; index++)
    {
        free(matrix[index]);
    }
    free(matrix);

    return 0;
}

