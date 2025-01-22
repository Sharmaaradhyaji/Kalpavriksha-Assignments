#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    int lengthOfLL;
    printf("Enter length of LinkedList: ");
    scanf("%d", &lengthOfLL);

    struct Node* head = NULL;
    struct Node* temp = NULL;

    printf("Enter data for %d nodes:\n", lengthOfLL);
    for (int index = 1; index <= lengthOfLL; index++)
    {
        struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
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

    struct Node* left = head;
    struct Node* right = head;

    while (right && right->next)
    {
        right = right->next;
    }

    int iterator = 0;
    while (left != right && left->next != right)
    {
        struct Node* prev = left;
        while (prev->next && prev->next != right)
        {
            prev = prev->next;
        }

        struct Node* nextLeft = left->next;
        right->next = left->next;
        left->next = right;

        prev->next = NULL;
        left = nextLeft;
        right = prev; 
    }

    printf("Modified Linked List: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    temp = head;
    while (temp != NULL)
    {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}

