#include <stdio.h>

int smallerThan_Kth(int matrix[10][10], int dimensions[2], int k)
{
    int size = dimensions[0] * dimensions[1];
    int array[size];
    int iterator = 0;
    for (int index1 = 0; index1 < dimensions[0]; index1++)
    {
        for (int index2 = 0; index2 < dimensions[1]; index2++)
        {
            array[iterator++] = matrix[index1][index2];
        }
    }

    for (int index1 = 0; index1 < size; index1++)
    {
        for (int index2 = 0; index2 < size; index2++)
        {
            if (array[index1] < array[index2])
            {
                int temp = array[index1];
                array[index1] = array[index2];
                array[index2] = temp;
            }
        }
    }

    return array[k-1];
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
    int rows, columns, k;

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

    printf("Enter kth number: \n");
    scanf("%d", &k);

    printf("Original Matrix is: \n");
    printMatrix(grid, rows, columns);

    int dimensions[2] = {rows, columns};

    printf("Kth element is: %d", smallerThan_Kth(grid, dimensions, k));

    return 0;
}

