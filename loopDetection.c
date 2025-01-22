#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void printList(struct Node* head)
{
    printf("Updated Linked List: ");
    struct Node* temp = head;
    while (temp)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head)
{
    struct Node* temp = head;
    while (temp)
    {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
}

int main()
{
    int listSize;
    scanf("%d", &listSize);

    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < listSize; i++)
    {
        int value;
        scanf("%d", &value);
        struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int cyclePosition;
    printf("Enter the position to add cycle: ");
    scanf("%d", &cyclePosition);
    if (cyclePosition > 0)
    {
        struct Node* cycleNode = head;
        for (int i = 1; i < cyclePosition; i++)
            cycleNode = cycleNode->next;
        tail->next = cycleNode;
    }

    struct Node* slow = head;
    struct Node* fast = head;
    int hasLoop = 0;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            hasLoop = 1;
            break;
        }
    }

    if (hasLoop)
    {
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        struct Node* loopStart = slow;
        struct Node* temp = loopStart;
        while (temp->next != loopStart)
            temp = temp->next;
        temp->next = NULL;

        printf("Loop detected: true\n");
    }
    else
    {
        printf("Loop detected: false\n");
    }

    printList(head);
    freeList(head);

    return 0;
}

