#include <stdio.h>
void Bubblesort(int arr[], int numberOfElements)
{
    for (int index1 = 0; index1 < numberOfElements; index1++)
    {
        for (int index2 = 0; index2 < numberOfElements - index1 - 1; index2++)
        {
            if (arr[index2] > arr[index2 + 1])
            {
                int temp = arr[index2];
                arr[index2] = arr[index2 + 1];
                arr[index2 + 1] = temp;
            }
        }
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

    Bubblesort(arr, numberOfElements);

    printf("Sorted list is: ");
    printList(arr, numberOfElements);
    return 0;
}

