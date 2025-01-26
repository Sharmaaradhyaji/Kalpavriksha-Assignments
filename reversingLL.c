#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

struct Node *reverseList(struct Node *head)
{
    struct Node *previous = NULL;
    struct Node *current = head;
    struct Node *nextNode = NULL;

    while (current != NULL)
    {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    return previous;
}

int main()
{
    int nodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    struct Node *head = NULL;
    struct Node *temp = NULL;

    printf("Enter the values of the nodes:\n");
    for (int index = 0; index < nodes; index++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &newNode->value);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp->next = newNode;
        }
        temp = newNode;
    }
    printf("Original list: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");

    head = reverseList(head);

    printf("Reversed list: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
    temp = head;
    while (temp != NULL)
    {
        struct Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}

