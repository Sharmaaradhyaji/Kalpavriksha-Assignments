#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct Stack
{
    int data[SIZE];
    int top, size;
};

struct Stack *init()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->size = 0;
    return stack;
}

void push(struct Stack *stack, int value)
{
    if (stack->size == SIZE)
    {
        printf("Queue Overflow!\n");
        return;
    }
    stack->data[++(stack->top)] = value;
    stack->size++;
}

int pop(struct Stack *stack, int *success)
{
    if (stack->size == 0)
    {
        *success = 0;
        return -1;
    }
    *success = 1;
    stack->size--;
    return stack->data[(stack->top)--];
}

void enqueue(struct Stack *stack1)
{
    int value;
    printf("Enter data: ");
    scanf("%d", &value);
    push(stack1, value);
}

int dequeue(struct Stack *stack1, struct Stack *stack2, int *success)
{
    if (stack1->size == 0 && stack2->size == 0)
    {
        printf("Queue Underflow!\n");
        *success = 0;
        return -1;
    }

    if (stack2->size == 0)
    {
        while (stack1->size > 0)
        {
            int value = pop(stack1, success);
            push(stack2, value);
        }
    }

    return pop(stack2, success);
}

int front(struct Stack *stack1, struct Stack *stack2, int *success)
{
    if (stack1->size == 0 && stack2->size == 0)
    {
        printf("Queue is empty.\n");
        *success = 0;
        return -1;
    }

    if (stack2->size == 0)
    {
        while (stack1->size > 0)
        {
            int value = pop(stack1, success);
            push(stack2, value);
        }
    }

    *success = 1;
    return stack2->data[stack2->top];
}

int isEmpty(struct Stack *stack1, struct Stack *stack2)
{
    return stack1->size == 0 && stack2->size == 0;
}

void freeStack(struct Stack *stack)
{
    free(stack);
}

int main()
{
    struct Stack *stack1 = init();
    struct Stack *stack2 = init();

    int choice, data, success;

    printf("\nQueue Using Two Stacks\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display Front\n4. Check Empty\n5. Exit\n");

    while (1)
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue(stack1);
            break;
        case 2:
            data = dequeue(stack1, stack2, &success);
            if (success)
                printf("Dequeued: %d\n", data);
            break;
        case 3:
            data = front(stack1, stack2, &success);
            if (success)
                printf("Front: %d\n", data);
            break;
        case 4:
            printf(isEmpty(stack1, stack2) ? "Queue is Empty\n" : "Queue is Not Empty\n");
            break;
        case 5:
            freeStack(stack1);
            freeStack(stack2);
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

