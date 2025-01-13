#include <stdio.h>

void alteringMatrix(int matrix[10][10], int dimensions[2], int alteredDimensions[2])
{
    int row = -1, column = -1;

    for (int index1 = alteredDimensions[0] + 1; index1 < dimensions[0]; index1++)
    {
        for (int index2 = alteredDimensions[1] + 1; index2 < dimensions[1]; index2++)
        {
            if (matrix[index1][index2] == 0)
            {
                row = index1;
                column = index2;
            }
            index1 != alteredDimensions[0];
        }
    }

    alteredDimensions[0] = row;
    alteredDimensions[1] = column;

    if (row == -1 || column == -1)
        return;

    for (int iterator = 0; iterator < dimensions[0]; iterator++)
    {
        matrix[iterator][column] = 0;
    }

    for (int iterator = 0; iterator < dimensions[1]; iterator++)
    {
        matrix[row][iterator] = 0;
    }

    alteringMatrix(matrix, dimensions, alteredDimensions);
}

void printMatrix(int grid[][10], int rows, int columns)
{
    for (int index1 = 0; index1 < rows; index1++)
    {
        for (int index2 = 0; index2 < columns; index2++)
        {
            printf("%d ", grid[index1][index2]);
        }
        printf("\n");
    }
}

int main()
{
    int grid[10][10];
    int rows, columns;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    printf("Enter the elements row by row: \n");
    for (int index1 = 0; index1 < rows; index1++)
    {
        for (int index2 = 0; index2 < columns; index2++)
        {
            scanf("%d", &grid[index1][index2]);
        }
    }

    printf("Original Matrix is: \n");
    printMatrix(grid, rows, columns);

    int dimensions[2] = {rows, columns};
    int alteredDimensions[2] = {-1, -1};

    alteringMatrix(grid, dimensions, alteredDimensions);

    printf("Altered Matrix is: \n");
    printMatrix(grid, rows, columns);

    return 0;
}

