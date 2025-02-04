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

struct Node *bubbleSort(struct Node *head)
{
    if (head == NULL)
        return head;

    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data.situation > ptr1->next->data.situation)
            {
                struct Element temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return head;
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

    struct Node *head = creatingLL(iterator);

    head = bubbleSort(head);

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

