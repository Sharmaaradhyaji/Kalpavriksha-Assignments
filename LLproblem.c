#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct Element list[100];
int iterator = 0;

void sort(int input)
{
    for (int i = 0; i < input - 1; i++)
    {
        for (int j = 0; j < input - i - 1; j++)
        {
            if (list[j].situation > list[j + 1].situation)
            {
                struct Element temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

struct Node *creatingLL()
{
    struct Node *head = NULL, *temp = NULL, *prev = NULL;
    for (int i = 0; i < iterator; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = list[i];
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

void processString(char string[100])
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
    int i = 0;
    while (string[index] != '\0')
    {
        situation[i++] = string[index++];
    }
    situation[i] = '\0';

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

    iterator++;
}

int main()
{
    int input;
    printf("No. of inputs: ");
    scanf("%d", &input);
    getchar();

    char string[100];
    for (int i = 0; i < input; i++)
    {
        fgets(string, sizeof(string), stdin);
        string[strcspn(string, "\n")] = '\0';
        processString(string);
    }

    sort(input);

    struct Node *head = creatingLL();
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

