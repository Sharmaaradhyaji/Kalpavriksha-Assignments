#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(int position, int value)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != NULL)
        {
            printf(" -> ");
        }
    }
    printf(" -> NULL\n");
}

void updateAtPosition(int position, int newValue)
{
    if (position < 1)
    {
        printf("Invalid Position\n");
        return;
    }
    struct Node *temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of range\n");
        return;
    }
    temp->data = newValue;
}

void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(int position)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (position == 1)
    {
        deleteAtBeginning();
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of range\n");
        return;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

int main()
{
    int operations;
    printf("Enter the number of Operations: ");
    scanf("%d", &operations);
    printf("1 x: Add x to the end. (x: is any number and pos: position)\n");
    printf("2 x: Add x at the beginning.\n3 pos x: Add x at position pos (1-indexed).\n");
    printf("4: Display all elements.\n5 pos x: Update the element at position pos to x.\n6: Delete the first element.\n");
    printf("7: Delete the last element.\n8 pos: Delete the element at position pos (1-indexed).\n");

    for (int index = 0; index < operations; index++)
    {
        int operationType;
        scanf("%d", &operationType);

        switch (operationType)
        {
        case 1:
        {
            int value;
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        }
        case 2:
        {
            int value;
            scanf("%d", &value);
            insertAtBeginning(value);
            break;
        }
        case 3:
        {
            int position, value;
            scanf("%d %d", &position, &value);
            insertAtPosition(position, value);
            break;
        }
        case 4:
            printf("Current List: ");
            display();
            break;
        case 5:
        {
            int position, newValue;
            scanf("%d %d", &position, &newValue);
            updateAtPosition(position, newValue);
            break;
        }
        case 6:
            deleteAtBeginning();
            break;
        case 7:
            deleteAtEnd();
            break;
        case 8:
        {
            int position;
            scanf("%d", &position);
            deleteAtPosition(position);
            break;
        }
        default:
            printf("Invalid Operation Type. Please try again.\n");
        }
    }

    return 0;
}

