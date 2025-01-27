#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *insertEnd(Node *head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void findPairWithTarget(Node *head1, Node *head2, int target)
{
    Node *ptr1, *ptr2;
    int swapped;
    do
    {
        swapped = 0;
        ptr1 = head1;
        while (ptr1 != NULL && ptr1->next != NULL)
        {
            if (ptr1->data > ptr1->next->data)
            {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
    } while (swapped);

    do
    {
        swapped = 0;
        ptr2 = head2;
        while (ptr2 != NULL && ptr2->next != NULL)
        {
            if (ptr2->data > ptr2->next->data)
            {
                int temp = ptr2->data;
                ptr2->data = ptr2->next->data;
                ptr2->next->data = temp;
                swapped = 1;
            }
            ptr2 = ptr2->next;
        }
    } while (swapped);

    ptr1 = head1;
    ptr2 = head2;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        int sum = ptr1->data + ptr2->data;
        if (sum == target)
        {
            printf("%d %d\n", ptr1->data, ptr2->data);
            return;
        }
        else if (sum < target)
        {
            ptr1 = ptr1->next;
        }
        else
        {
            ptr2 = ptr2->next;
        }
    }

    printf("NULL\n");
}

int main()
{
    Node *list1 = NULL;
    Node *list2 = NULL;
    int elementsSize1, elementsSize2, target, value;

    printf("Enter the number of elements in List1: ");
    scanf("%d", &elementsSize1);
    printf("Enter the elements of List1: ");
    for (int index = 0; index < elementsSize1; index++)
    {
        scanf("%d", &value);
        list1 = insertEnd(list1, value);
    }

    printf("Enter the number of elements in List2: ");
    scanf("%d", &elementsSize2);
    printf("Enter the elements of List2: ");
    for (int index = 0; index < elementsSize2; index++)
    {
        scanf("%d", &value);
        list2 = insertEnd(list2, value);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("The first pair is: ");
    findPairWithTarget(list1, list2, target);

    return 0;
}
