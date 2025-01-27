#include <stdio.h>

int linearSearch(int arr[], int size, int target)
{
    for (int index = 0; index < size; index++)
    {
        if (arr[index] == target)
        {
            return index;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {4, 2, 7, 1, 9, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int index = linearSearch(arr, size, target);

    if (index != -1)
    {
        printf("Element found at index: %d\n", index);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}

