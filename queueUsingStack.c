#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

struct Stack
{
    int data[STACK_SIZE];
    int top, size;
};

void initStack(struct Stack *stack)
{
    stack->top = -1;
    stack->size = 0;
}

void enqueue(struct Stack *stack, int value)
{
    if (stack->size == STACK_SIZE)
        printf("Queue Overflow!\n");
    else
    {
        stack->data[++(stack->top)] = value;
        stack->size++;
    }
}

int dequeue(struct Stack *stack, int *success)
{
    int dequeuedValue = -1;
    *success = 0;

    if (stack->size == 0)
        printf("Queue Underflow!\n");
    else
    {
        struct Stack tempStack;
        initStack(&tempStack);

        while (stack->size > 1)
        {
            enqueue(&tempStack, stack->data[stack->top--]);
            stack->size--;
        }

        dequeuedValue = stack->data[stack->top--];
        stack->size--;
        *success = 1;

        while (tempStack.size > 0)
        {
            enqueue(stack, tempStack.data[tempStack.top--]);
            tempStack.size--;
        }
    }
    return dequeuedValue;
}

int front(struct Stack *stack, int *success)
{
    int frontElement = -1;
    *success = 0;

    if (stack->size == 0)
        printf("Queue is empty.\n");
    else
    {
        struct Stack tempStack;
        initStack(&tempStack);

        while (stack->size > 0)
        {
            enqueue(&tempStack, stack->data[stack->top--]);
            stack->size--;
        }

        frontElement = tempStack.data[tempStack.top];
        *success = 1;

        while (tempStack.size > 0)
        {
            enqueue(stack, tempStack.data[tempStack.top--]);
            tempStack.size--;
        }
    }
    return frontElement;
}

int isEmpty(struct Stack *stack)
{
    return stack->size == 0;
}

int main()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    initStack(stack);

    int choice, data, success;

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
            data = dequeue(stack, &success);
            if (success)
                printf("Dequeued: %d\n", data);
            break;
        case 3:
            data = front(stack, &success);
            if (success)
                printf("Front: %d\n", data);
            break;
        case 4:
            printf(isEmpty(stack) ? "Queue is Empty\n" : "Queue is Not Empty\n");
            break;
        case 5:
            free(stack);
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid Choice!\n");
        }

        if (choice == 5)
            break;
    }

    return 0;
}

