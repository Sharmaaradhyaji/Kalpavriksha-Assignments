#include <stdio.h>

void leftMax(int matrix[][100], int maxLeft[][100], int rows, int columns)
{
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
}

void rightMax(int matrix[][100], int maxRight[][100], int rows, int columns)
{
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
}

void topMax(int matrix[][100], int maxTop[][100], int rows, int columns)
{
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
}

void bottomMax(int matrix[][100], int maxBottom[][100], int rows, int columns)
{
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
}

int waterTrapped(int matrix[][100], int rows, int columns)
{
    int maxLeft[100][100], maxRight[100][100];
    int maxTop[100][100], maxBottom[100][100];
    int water = 0;

    leftMax(matrix, maxLeft, rows, columns);

    rightMax(matrix, maxRight, rows, columns);

    topMax(matrix, maxTop, rows, columns);

    bottomMax(matrix, maxBottom, rows, columns);

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

void printMatrix(int matrix[][100], int rows, int columns)
{
    for (int index1 = 0; index1 < rows; index1++)
    {
        for (int index2 = 0; index2 < columns; index2++)
        {
            printf("%d ", matrix[index1][index2]);
        }
        printf("\n");
    }
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
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < columns; colIndex++)
        {
            printf("Enter element for %dth row, %dth column: ", rowIndex, colIndex);
            scanf("%d", &matrix[rowIndex][colIndex]);
        }
    }

    printf("The matrix is:\n");
    printMatrix(matrix, rows, columns);

    int water = waterTrapped(matrix, rows, columns);
    printf("Total water trapped is: %d", water);

    return 0;
}

