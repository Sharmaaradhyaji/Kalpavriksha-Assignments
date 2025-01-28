#include <stdio.h>

int waterTrapped(int matrix[][100], int rows, int columns)
{
    int maxLeft[rows][columns], maxRight[rows][columns];
    int maxTop[rows][columns], maxBottom[rows][columns];
    int water = 0;

    for (int index1 = 0; index1 < rows; index1++)
    {
        maxLeft[index1][0] = matrix[index1][0];
        for (int index2 = 1; index2 < columns; index2++)
        {
            if (matrix[index1][index2] > maxLeft[index1][index2 - 1])
            {
                maxLeft[index1][index2] = matrix[index1][index2];
            }
            else
            {
                maxLeft[index1][index2] = maxLeft[index1][index2 - 1];
            }
        }
    }

    for (int index1 = 0; index1 < rows; index1++)
    {
        maxRight[index1][columns - 1] = matrix[index1][columns - 1];
        for (int index2 = columns - 2; index2 >= 0; index2--)
        {
            if (matrix[index1][index2] > maxRight[index1][index2 + 1])
            {
                maxRight[index1][index2] = matrix[index1][index2];
            }
            else
            {
                maxRight[index1][index2] = maxRight[index1][index2 + 1];
            }
        }
    }

    for (int index2 = 0; index2 < columns; index2++)
    {
        maxTop[0][index2] = matrix[0][index2];
        for (int index1 = 1; index1 < rows; index1++)
        {
            if (matrix[index1][index2] > maxTop[index1 - 1][index2])
            {
                maxTop[index1][index2] = matrix[index1][index2];
            }
            else
            {
                maxTop[index1][index2] = maxTop[index1 - 1][index2];
            }
        }
    }

    for (int index2 = 0; index2 < columns; index2++)
    {
        maxBottom[rows - 1][index2] = matrix[rows - 1][index2];
        for (int index1 = rows - 2; index1 >= 0; index1--)
        {
            if (matrix[index1][index2] > maxBottom[index1 + 1][index2])
            {
                maxBottom[index1][index2] = matrix[index1][index2];
            }
            else
            {
                maxBottom[index1][index2] = maxBottom[index1 + 1][index2];
            }
        }
    }

    for (int index1 = 1; index1 < rows - 1; index1++)
    {
        for (int index2 = 1; index2 < columns - 1; index2++)
        {
            int minHeight = maxLeft[index1][index2];
            if (maxRight[index1][index2] < minHeight)
            {
                minHeight = maxRight[index1][index2];
            }
            if (maxTop[index1][index2] < minHeight)
            {
                minHeight = maxTop[index1][index2];
            }
            if (maxBottom[index1][index2] < minHeight)
            {
                minHeight = maxBottom[index1][index2];
            }

            if (minHeight > matrix[index1][index2])
            {
                water += minHeight - matrix[index1][index2];
            }
        }
    }

    return water;
}

int main()
{
    int rows, columns;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    int matrix[100][100];
    printf("Enter the values of the matrix: \n");
    for (int index1 = 0; index1 < rows; index1++)
    {
        for (int index2 = 0; index2 < columns; index2++)
        {
            scanf("%d", &matrix[index1][index2]);
        }
    }

    printf("The matrix is:\n");
    for (int index1 = 0; index1 < rows; index1++)
    {
        for (int index2 = 0; index2 < columns; index2++)
        {
            printf("%d ", matrix[index1][index2]);
        }
        printf("\n");
    }

    int water = waterTrapped(matrix, rows, columns);
    printf("Total water trapped is: %d", water);

    return 0;
}

