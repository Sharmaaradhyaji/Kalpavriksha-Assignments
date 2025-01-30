#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Node
{
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
    int size;
};

void enqueue(struct Queue* q)
{
    int value;
    printf("Enter the value to be added: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
    printf("Value added\n");
}

void dequeue(struct Queue* q)
{
    if(q->front==NULL){
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    printf("Value removed\n");
    q->size--;
}

void peek(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("The first element is: %d\n", q->front->data);
}

void isEmpty(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("The Stack is empty.\n");
    }
    else
    {
        printf("The Stack is not empty.\n");
    }
}

void findSize(struct Queue *q)
{
    
    printf("Queue size: %d\n", q->size);
}

int main()
{
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->front=q->rear=NULL;
    q->size=0;
    printf("1. Push element onto Queue\n");
    printf("2. Pop an element from Queue\n");
    printf("3. Find top element of Queue\n");
    printf("4. Check if Queue is empty\n");
    printf("5. Find size of Queue\n");
    printf("0. Exit\n");

    int choice = -1;
    while (choice)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(q);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            peek(q);
            break;
        case 4:
            isEmpty(q);
            break;
        case 5:
            findSize(q);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Enter a valid choice\n");
            break;
        }
    }
    free(q);

    return 0;
}

