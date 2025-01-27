#include <stdio.h>
void Selectionsort(int arr[], int numberOfElements)
{
    for (int index1 = 0; index1 < numberOfElements - 1; index1++)
    {
        int minIndex = index1;
        for (int index2 = index1 + 1; index2 < numberOfElements; index2++)
        {
            if (arr[index2] < arr[minIndex])
            {
                minIndex = index2;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[index1];
        arr[index1] = temp;
    }
}

void printList(int arr[], int numberOfElements)
{
    for (int index = 0; index < numberOfElements; index++)
    {
        printf("%d ", arr[index]);
    }
    printf("\n");
}

int main()
{
    int arr[1000];
    int numberOfElements;

    printf("Enter number of elements in an array: ");
    scanf("%d", &numberOfElements);

    printf("Enter elements of array: \n");
    for (int index = 0; index < numberOfElements; index++)
    {
        scanf("%d", &arr[index]);
    }

    printf("original list is: ");
    printList(arr, numberOfElements);

    Selectionsort(arr, numberOfElements);

    printf("Sorted list is: ");
    printList(arr, numberOfElements);
    return 0;
}

