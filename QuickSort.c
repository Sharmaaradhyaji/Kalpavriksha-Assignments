#include <stdio.h>

void sortArray(int array[], int start, int end)
{
    if (start < end)
    {
        int pivotIndex = divideArray(array, start, end);
        sortArray(array, start, pivotIndex - 1);
        sortArray(array, pivotIndex + 1, end);
    }
}

int divideArray(int array[], int start, int end)
{
    int pivotElement = array[end];
    int smallerIndex = start - 1;
    for (int currentIndex = start; currentIndex < end; currentIndex++)
    {
        if (array[currentIndex] <= pivotElement)
        {
            smallerIndex++;
            int temp = array[smallerIndex];
            array[smallerIndex] = array[currentIndex];
            array[currentIndex] = temp;
        }
    }
    int temp = array[smallerIndex + 1];
    array[smallerIndex + 1] = array[end];
    array[end] = temp;

    return smallerIndex + 1;
}

void printArray(int array[], int size)
{
    for (int index = 0; index < size; index++)
    {
        printf("%d ", array[index]);
    }
    printf("\n");
}

int main()
{
    int numbers[1000];
    int totalNumbers;

    printf("Enter the number of elements: ");
    scanf("%d", &totalNumbers);

    printf("Enter the elements of the array: ");
    for (int index = 0; index < totalNumbers; index++)
    {
        scanf("%d", &numbers[index]);
    }

    printf("Original array: ");
    printArray(numbers, totalNumbers);

    sortArray(numbers, 0, totalNumbers - 1);

    printf("Sorted array: ");
    printArray(numbers, totalNumbers);

    return 0;
}
