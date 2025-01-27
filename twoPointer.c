#include <stdio.h>

int twoPointerSum(int arr[], int size, int target)
{
    int left = 0, right = size - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            printf("Pair found: %d and %d\n", arr[left], arr[right]);
            return 1;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return 0;
}

int main()
{
    int arr[1000];
    int size;
    int target;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("Enter the elements: \n");
    for (int index = 0; index < size; index++)
    {
        scanf("%d", &arr[index]);
    }

    printf("Enter the target: \n");
    scanf("%d", &target);

    if (!twoPointerSum(arr, size, target))
    {
        printf("No pair found\n");
    }

    return 0;
}

