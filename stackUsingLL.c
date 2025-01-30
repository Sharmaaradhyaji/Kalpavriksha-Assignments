#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* push(struct Node* head)
{
    int value;
    printf("Enter the value to be added: ");
    scanf("%d", &value);

    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if(head!=NULL){
        head->prev=newNode;
    }
    printf("Value added\n");
    return newNode;
}

struct Node* pop(struct Node* head)
{
    if (head == NULL) {
        printf("Stack is empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next; 

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    printf("Value removed\n");
    return head;
}

void peek(struct Node *head)
{
    if (head == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("The first element is: %d\n", head->data);
}

void isEmpty(struct Node *head)
{
    if (head == NULL)
    {
        printf("The Stack is empty.\n");
    }
    else
    {
        printf("The Stack is not empty.\n");
    }
}

void findSize(struct Node *head)
{
    if (head == NULL)
    {
        printf("Queue size: 0\n");
    }
    else
    {
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        printf("Queue size: %d\n", count);
    }
}

int main()
{
    struct Node* head=NULL;

    printf("1. Push element onto Stack\n");
    printf("2. Pop an element from Stack\n");
    printf("3. Find top element of Stack\n");
    printf("4. Check if Stack is empty\n");
    printf("5. Find size of Stack\n");
    printf("0. Exit\n");

    int choice = -1;
    while (choice)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = push(head);
            break;
        case 2:
            head = pop(head);
            break;
        case 3:
            peek(head);
            break;
        case 4:
            isEmpty(head);
            break;
        case 5:
            findSize(head);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Enter a valid choice\n");
            break;
        }
    }

    return 0;
}

