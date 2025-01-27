#include <stdio.h>
void Insertionsort(int arr[], int numberOfElements)
{
    for (int index1 = 1; index1 < numberOfElements; index1++)
    {
        int key = arr[index1];
        int index2 = index1 - 1;
        while (index2 >= 0 && arr[index2] > key)
        {
            arr[index2 + 1] = arr[index2];
            index2--;
        }
        arr[index2 + 1] = key;
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

