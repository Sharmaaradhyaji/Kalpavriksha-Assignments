#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool check(char character, char matrix[10][10], int dimensions[2], int indexDimensions[2])
{
    if (indexDimensions[0] < dimensions[0] - 1 && matrix[indexDimensions[0] + 1][indexDimensions[1]] == character)
    {
        indexDimensions[0] += 1;
        return true;
    }
    if (indexDimensions[0] > 0 && matrix[indexDimensions[0] - 1][indexDimensions[1]] == character)
    {
        indexDimensions[0] -= 1;
        return true;
    }
    if (indexDimensions[1] < dimensions[1] - 1 && matrix[indexDimensions[0]][indexDimensions[1] + 1] == character)
    {
        indexDimensions[1] += 1;
        return true;
    }
    if (indexDimensions[1] > 0 && matrix[indexDimensions[0]][indexDimensions[1] - 1] == character)
    {
        indexDimensions[1] -= 1;
        return true;
    }
    // Diagonals
    if (indexDimensions[0] > 0 && indexDimensions[1] > 0 && matrix[indexDimensions[0] - 1][indexDimensions[1] - 1] == character)
    {
        indexDimensions[0] -= 1;
        indexDimensions[1] -= 1;
        return true;
    }
    if (indexDimensions[0] > 0 && indexDimensions[1] < dimensions[1] - 1 && matrix[indexDimensions[0] - 1][indexDimensions[1] + 1] == character)
    {
        indexDimensions[0] -= 1;
        indexDimensions[1] += 1;
        return true;
    }
    if (indexDimensions[0] < dimensions[0] - 1 && indexDimensions[1] > 0 && matrix[indexDimensions[0] + 1][indexDimensions[1] - 1] == character)
    {
        indexDimensions[0] += 1;
        indexDimensions[1] -= 1;
        return true;
    }
    if (indexDimensions[0] < dimensions[0] - 1 && indexDimensions[1] < dimensions[1] - 1 && matrix[indexDimensions[0] + 1][indexDimensions[1] + 1] == character)
    {
        indexDimensions[0] += 1;
        indexDimensions[1] += 1;
        return true;
    }
    return false;
}

bool wordSearch(char matrix[10][10], char word[10], int dimensions[2])
{

    int iterator = 0;

    for (int index1 = 0; index1 < dimensions[0]; index1++)
    {
        for (int index2 = 0; index2 < dimensions[1]; index2++)
        {
            if (word[0] == matrix[index1][index2])
            {
                int iterator = 1;
                int indexDimensions[2] = {index1, index2};
                while (word[iterator] != '\0')
                {
                    if (check(word[iterator], matrix, dimensions, indexDimensions))
                    {
                        iterator++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (word[iterator] == '\0')
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void showMatrix(char matrix[10][10], int rows, int columns)
{

    for (int index1 = 0; index1 < rows; index1++)
    {
        for (int index2 = 0; index2 < columns; index2++)
        {
            printf("%c ", matrix[index1][index2]);
        }
        printf("\n");
    }
}

int main()
{

    int rows;
    int columns;
    char matrix[10][10];
    char word[10];
    printf("Enter the number of rows of the matrix: ");
    scanf("%d", &rows);

    printf("Enter the number of columns of the matrix: ");
    scanf("%d", &columns);

    printf("Enter the input of matrix \n");
    for (int index1 = 0; index1 < rows; index1++)
    {
        for (int index2 = 0; index2 < columns; index2++)
        {
            printf("Enter value for (%d, %d): ", index1, index2);
            scanf(" %c", &matrix[index1][index2]);
        }
    }

    printf("Enter the word to search: ");
    scanf("%s", word);

    showMatrix(matrix, rows, columns);

    int dimensions[2] = {rows, columns};

    bool isPresent = wordSearch(matrix, word, dimensions);

    if (isPresent)
    {
        printf("The word is present.");
    }
    else
    {
        printf("The word is not present.");
    }

    return 0;
}


