#include <stdio.h>
#define MAX_SIZE 100

struct queue
{
    int data[MAX_SIZE];
    int front, rear;
};

void enqueue(struct queue *q)
{
    int value;
    if (q->rear == MAX_SIZE - 1)
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    printf("Enter the value to be added: ");
    scanf("%d", &value);
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->data[q->rear] = value;
    printf("Value added\n");
}

void dequeue(struct queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }
    printf("Value removed\n");
}

void peek(struct queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("The first element is: %d\n", q->data[q->front]);
}

void isEmpty(struct queue *q)
{
    if (q->front == -1)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        printf("The queue is not empty.\n");
    }
}

void findSize(struct queue *q)
{
    if (q->front == -1)
    {
        printf("Queue size: 0\n");
    }
    else
    {
        printf("Queue size: %d\n", (q->rear - q->front + 1));
    }
}

int main()
{
    struct queue q;
    q.front = -1;
    q.rear = -1;

    printf("1. Push element onto queue\n");
    printf("2. Pop an element from queue\n");
    printf("3. Find top element of queue\n");
    printf("4. Check if queue is empty\n");
    printf("5. Find size of queue\n");
    printf("0. Exit\n");

    int choice = -1;
    while (choice)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            peek(&q);
            break;
        case 4:
            isEmpty(&q);
            break;
        case 5:
            findSize(&q);
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

