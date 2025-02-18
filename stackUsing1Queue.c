#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct Queue
{
    int data[MAX_QUEUE_SIZE];
    int rear, front, size;
};

void initializeQueue(struct Queue *queue)
{
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

int isEmpty(struct Queue *queue)
{
    if (queue->size == 0)
    {
        printf("Stack is empty.\n");
        return 1;
    }
    return 0;
}

void push(struct Queue *queue, int value)
{
    if (queue->size == MAX_QUEUE_SIZE)
    {
        printf("Stack is full.\n");
        return;
    }

    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->data[queue->rear] = value;
    queue->size++;

    for (int i = 0; i < queue->size - 1; i++)
    {
        int temp = queue->data[queue->front];
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
        queue->data[queue->rear] = temp;
    }
}

void pop(struct Queue *queue)
{
    if (!isEmpty(queue))
    {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
        queue->size--;
    }
}

int getTop(struct Queue *queue)
{
    if (isEmpty(queue))
        return -1;
    return queue->data[queue->front];
}

int getSize(struct Queue *queue)
{
    return queue->size;
}

int main()
{
    struct Queue q;
    initializeQueue(&q);

    int choice, data;

    printf("\nStack Implementation Using a Single Queue\n");
    printf("1. Push Element onto the Stack\n");
    printf("2. Display the Top Element of the Stack\n");
    printf("3. Pop Element from the Stack\n");
    printf("4. Display the Size of the Stack\n");
    printf("5. Check if the Stack is Empty\n");
    printf("6. Exit\n");

    while (1)
    {
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the Data You Want to Push: ");
            scanf("%d", &data);
            push(&q, data);
            break;
        case 2:
            data = getTop(&q);
            if (data != -1)
                printf("Top Element is: %d\n", data);
            break;
        case 3:
            pop(&q);
            break;
        case 4:
            printf("Size of the Stack is: %d\n", getSize(&q));
            break;
        case 5:
            isEmpty(&q);
            break;
        case 6:
            printf("Exiting the Program\n");
            return 0;
        default:
            printf("Enter a Valid Choice.\n");
        }
    }
}

