#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        struct Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
}

int main()
{
    int lengthOfLL;
    printf("Enter length of LinkedList: ");
    scanf("%d", &lengthOfLL);

    struct Node *head = NULL;
    struct Node *temp = NULL;

    printf("Enter data for %d nodes:\n", lengthOfLL);
    for (int index = 1; index <= lengthOfLL; index++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        int newdata;
        scanf("%d", &newdata);
        newNode->data = newdata;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    struct Node *evenHead = NULL, *evenTail = NULL;
    struct Node *oddHead = NULL, *oddTail = NULL;
    temp = head;

    while (temp != NULL)
    {
        struct Node *nextNode = temp->next;
        temp->next = NULL;

        if (temp->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = temp;
                evenTail = temp;
            }
            else
            {
                evenTail->next = temp;
                evenTail = temp;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = temp;
                oddTail = temp;
            }
            else
            {
                oddTail->next = temp;
                oddTail = temp;
            }
        }

        temp = nextNode;
    }

    if (evenTail != NULL)
    {
        evenTail->next = oddHead;
        head = evenHead;
    }
    else
    {
        head = oddHead;
    }
    printf("Modified Linked List: ");
    printList(head);
    freeList(head);

    return 0;
}

