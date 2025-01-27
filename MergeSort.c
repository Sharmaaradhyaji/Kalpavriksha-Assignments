#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftArray[leftSize], rightArray[rightSize];
    for (int leftIndex = 0; leftIndex < leftSize; leftIndex++)
    {
        leftArray[leftIndex] = arr[left + leftIndex];
    }
    for (int rightIndex = 0; rightIndex < rightSize; rightIndex++)
    {
        rightArray[rightIndex] = arr[mid + 1 + rightIndex];
    }

    int leftIndex = 0, rightIndex = 0, mergedIndex = left;
    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (leftArray[leftIndex] <= rightArray[rightIndex])
        {
            arr[mergedIndex++] = leftArray[leftIndex++];
        }
        else
        {
            arr[mergedIndex++] = rightArray[rightIndex++];
        }
    }

    while (leftIndex < leftSize)
    {
        arr[mergedIndex++] = leftArray[leftIndex++];
    }

    while (rightIndex < rightSize)
    {
        arr[mergedIndex++] = rightArray[rightIndex++];
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[1000], numberOfElements;

    printf("Enter number of elements in the array: ");
    scanf("%d", &numberOfElements);

    printf("Enter elements of the array:\n");
    for (int index = 0; index < numberOfElements; index++)
    {
        scanf("%d", &arr[index]);
    }

    printf("Original list: ");
    for (int index = 0; index < numberOfElements; index++)
    {
        printf("%d ", arr[index]);
    }
    printf("\n");

    mergeSort(arr, 0, numberOfElements - 1);

    printf("Sorted list: ");
    for (int index = 0; index < numberOfElements; index++)
    {
        printf("%d ", arr[index]);
    }
    printf("\n");

    return 0;
}
