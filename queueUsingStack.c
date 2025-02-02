#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data[100];
    int top, size;
};

void enqueue(struct Stack *stack, int value)
{
    if (stack->size == 100)
    {
        printf("Queue Overflow!\n");
        return;
    }
    stack->data[++(stack->top)] = value;
    stack->size++;
}

int dequeue(struct Stack *stack)
{
    if (stack->size == 0)
    {
        printf("Queue Underflow!\n");
        return -1;
    }

    struct Stack *tempStack = (struct Stack *)malloc(sizeof(struct Stack));
    tempStack->top = -1;
    tempStack->size = 0;

    while (stack->size > 1)
    {
        enqueue(tempStack, stack->data[stack->top--]);
        stack->size--;
    }

    int dequeuedValue = stack->data[stack->top--];
    stack->size--;

    while (tempStack->size > 0)
    {
        enqueue(stack, tempStack->data[tempStack->top--]);
        tempStack->size--;
    }

    free(tempStack);
    return dequeuedValue;
}

int front(struct Stack *stack)
{
    if (stack->size == 0)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    struct Stack *tempStack = (struct Stack *)malloc(sizeof(struct Stack));
    tempStack->size = 0;
    tempStack->top = -1;

    while (stack->size > 0)
    {
        enqueue(tempStack, stack->data[stack->top--]);
        stack->size--;
    }

    int frontElement = tempStack->data[tempStack->top];

    while (tempStack->size > 0)
    {
        enqueue(stack, tempStack->data[tempStack->top--]);
        tempStack->size--;
    }

    free(tempStack);
    return frontElement;
}

int isEmpty(struct Stack *stack)
{
    return stack->size == 0;
}

int main()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->size = 0;

    int choice, data;

    printf("\nQueue Using One Stack (Iterative Dequeue)\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display Front\n4. Check Empty\n5. Exit\n");

    while (1)
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(stack, data);
            break;
        case 2:
            data = dequeue(stack);
            if (data != -1)
                printf("Dequeued: %d\n", data);
            break;
        case 3:
            data = front(stack);
            if (data != -1)
                printf("Front: %d\n", data);
            break;
        case 4:
            printf(isEmpty(stack) ? "Queue is Empty\n" : "Queue is Not Empty\n");
            break;
        case 5:
            free(stack);
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}

