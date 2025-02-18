#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

struct Queue
{
    int data[QUEUE_SIZE];
    int front, rear, size;
};

struct Stack
{
    struct Queue *q1, *q2;
};

void initQueue(struct Queue *queue)
{
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
}

void enqueue(struct Queue *queue, int value)
{
    if (queue->size == QUEUE_SIZE)
        return;
    queue->data[queue->rear++] = value;
    queue->size++;
}

int dequeue(struct Queue *queue)
{
    if (queue->size == 0)
        return -1;
    int val = queue->data[queue->front++];
    queue->size--;
    return val;
}

int front(struct Queue *q)
{
    return (q->size > 0) ? q->data[q->front] : -1;
}

void push(struct Stack *stack, int value)
{
    enqueue(stack->q1, value);
}

void pop(struct Stack *stack)
{
    if (stack->q1->size == 0)
    {
        printf("Stack is empty.\n");
        return;
    }
    while (stack->q1->size > 1)
    {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    dequeue(stack->q1);
    struct Queue *temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}

int topDisplay(struct Stack *stack)
{
    if (stack->q1->size == 0)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    while (stack->q1->size > 1)
    {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    int topElement = front(stack->q1);
    enqueue(stack->q2, dequeue(stack->q1));
    struct Queue *temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
    return topElement;
}

int sizeDisplay(struct Stack *stack)
{
    return stack->q1->size;
}

int isEmpty(struct Stack *stack)
{
    return stack->q1->size == 0;
}

struct Stack *initStack()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->q1 = (struct Queue *)malloc(sizeof(struct Queue));
    stack->q2 = (struct Queue *)malloc(sizeof(struct Queue));
    initQueue(stack->q1);
    initQueue(stack->q2);
    return stack;
}

int main()
{
    struct Stack *st = initStack();
    int choice, data;

    printf("\nStack implementation using two queues\n");
    printf("1. Push element onto the stack\n");
    printf("2. Display the top element of the stack\n");
    printf("3. Pop element from the stack\n");
    printf("4. Display the size of the stack\n");
    printf("5. Check if the stack is empty\n");
    printf("6. Exit\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data you want to push: ");
            scanf("%d", &data);
            push(st, data);
            break;
        case 2:
            data = topDisplay(st);
            if (data != -1)
                printf("Top element is: %d\n", data);
            break;
        case 3:
            pop(st);
            break;
        case 4:
            printf("Size of the stack is: %d\n", sizeDisplay(st));
            break;
        case 5:
            printf(isEmpty(st) ? "Stack is empty\n" : "Stack is not empty\n");
            break;
        case 6:
            free(st->q1);
            free(st->q2);
            free(st);
            printf("Exiting the program\n");
            return 0;
        default:
            printf("Enter a valid choice.\n");
        }
    }
}

