#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 100

struct Element
{
    int ID;
    int situation;
};

struct Node
{
    struct Element data;
    struct Node *next;
};

struct Element list[size];

void merge(int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    struct Element leftArr[leftSize], rightArr[rightSize];

    for (int index = 0; index < leftSize; index++)
        leftArr[index] = list[left + index];

    for (int index = 0; index < rightSize; index++)
        rightArr[index] = list[mid + 1 + index];

    int index1 = 0, index2 = 0, index3 = left;
    while (index1 < leftSize && index2 < rightSize)
    {
        if (leftArr[index1].situation < rightArr[index2].situation)
        {
            list[index3++] = leftArr[index1++];
        }
        else
        {
            list[index3++] = rightArr[index2++];
        }
    }

    while (index1 < leftSize)
    {
        list[index3++] = leftArr[index1++];
    }

    while (index2 < rightSize)
    {
        list[index3++] = rightArr[index2++];
    }
}

void mergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

struct Node *creatingLL(int iterator)
{
    struct Node *head = NULL, *temp = NULL, *prev = NULL;
    for (int index = 0; index < iterator; index++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = list[index];
        temp->next = NULL;
        if (prev == NULL)
        {
            head = temp;
        }
        else
        {
            prev->next = temp;
        }
        prev = temp;
    }
    return head;
}

int processString(char string[100], int iterator)
{
    int index = 0, number = 0;

    while (string[index] >= '0' && string[index] <= '9')
    {
        number = number * 10 + (string[index] - '0');
        index++;
    }

    list[iterator].ID = number;

    while (string[index] == ' ')
        index++;

    char situation[10];
    int tempIterator = 0;
    while (string[index] != '\0')
    {
        situation[tempIterator++] = string[index++];
    }
    situation[tempIterator] = '\0';

    if (strcmp(situation, "Critical") == 0)
    {
        list[iterator].situation = 1;
    }
    else if (strcmp(situation, "Serious") == 0)
    {
        list[iterator].situation = 2;
    }
    else if (strcmp(situation, "Stable") == 0)
    {
        list[iterator].situation = 3;
    }

    return iterator + 1;
}

int main()
{
    int input;
    printf("No. of inputs: ");
    scanf("%d", &input);
    getchar();

    char string[100];
    int iterator = 0;
    for (int index = 0; index < input; index++)
    {
        fgets(string, sizeof(string), stdin);
        string[strcspn(string, "\n")] = '\0';
        iterator = processString(string, iterator);
    }

    mergeSort(0, input - 1);

    struct Node *head = creatingLL(iterator);
    struct Node *temp = head;

    printf("The sorted list is:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data.ID);
        if (temp->data.situation == 1)
            printf("Critical\n");
        else if (temp->data.situation == 2)
            printf("Serious\n");
        else if (temp->data.situation == 3)
            printf("Stable\n");
        temp = temp->next;
    }

    return 0;
}

