#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int data[100];
    int rear, front, size;
};

void push(struct Queue *queue, int value)
{
    if (queue->size == 100)
    {
        printf("Stack is Full.\n");
        return;
    }

    queue->rear = (queue->rear + 1) % 100;
    queue->data[queue->rear] = value;
    queue->size++;

    for (int i = 0; i < queue->size - 1; i++)
    {
        int temp = queue->data[queue->front];
        queue->front = (queue->front + 1) % 100;
        queue->rear = (queue->rear + 1) % 100;
        queue->data[queue->rear] = temp;
    }
}

void pop(struct Queue *queue)
{
    if (queue->size == 0)
    {
        printf("Stack is empty.\n");
        return;
    }
    queue->front = (queue->front + 1) % 100;
    queue->size--;
}

int topDisplay(struct Queue *queue)
{
    if (queue->size == 0)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return queue->data[queue->front];
}

int sizeDisplay(struct Queue *queue)
{
    return queue->size;
}

int isEmpty(struct Queue *queue)
{
    return queue->size == 0;
}

int main()
{
    struct Queue q;
    q.front = 0;
    q.size = 0;
    q.rear = -1;

    int choice, data;

    printf("\nStack implementation using a single queue\n");
    printf("1. Push element onto the stack\n");
    printf("2. Display the top element of the stack\n");
    printf("3. Pop element from the stack\n");
    printf("4. Display the size of the stack\n");
    printf("5. Check if the stack is empty\n");
    printf("6. Exit\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data you want to push: ");
            scanf("%d", &data);
            push(&q, data);
            break;
        case 2:
            data = topDisplay(&q);
            if (data != -1)
                printf("Top element is: %d\n", data);
            break;
        case 3:
            pop(&q);
            break;
        case 4:
            printf("Size of the stack is: %d\n", sizeDisplay(&q));
            break;
        case 5:
            if (isEmpty(&q))
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        case 6:
            printf("Exiting the program\n");
            return 0;
        default:
            printf("Enter a valid choice.\n");
        }
    }

    return 0;
}
