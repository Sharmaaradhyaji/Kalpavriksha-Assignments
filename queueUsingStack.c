#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data[100];
    int top, size;
};

void push(struct Stack *stack, int value)
{
    if (stack->size == 100)
    {
        printf("Queue Overflow!\n");
        return;
    }
    stack->data[++(stack->top)] = value;
    stack->size++;
}

int pop(struct Stack *stack)
{
    if (stack->size == 0)
    {
        printf("Queue Underflow!\n");
        return -1;
    }
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

int dequeue(struct Stack *stack1, struct Stack *stack2)
{
    if (stack1->size == 0 && stack2->size == 0)
    {
        printf("Queue Underflow!\n");
        return -1;
    }

    if (stack2->size == 0)
    {
        while (stack1->size > 0)
        {
            int value = pop(stack1);
            push(stack2, value);
        }
    }

    return pop(stack2);
}

int front(struct Stack *stack1, struct Stack *stack2)
{
    if (stack1->size == 0 && stack2->size == 0)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    if (stack2->size == 0)
    {
        while (stack1->size > 0)
        {
            int value = pop(stack2);
            push(stack2, value);
        }
    }

    return stack2->data[stack2->top];
}

int isEmpty(struct Stack *stack1, struct Stack *stack2)
{
    return stack1->size == 0 && stack2->size == 0;
}

int main()
{
    struct Stack *stack1 = (struct Stack *)malloc(sizeof(struct Stack));
    struct Stack *stack2 = (struct Stack *)malloc(sizeof(struct Stack));

    stack1->top = -1;
    stack1->size = 0;
    stack2->top = -1;
    stack2->size = 0;

    int choice, data;

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
            data = dequeue(stack1, stack2);
            if (data != -1)
                printf("Dequeued: %d\n", data);
            break;
        case 3:
            data = front(stack1, stack2);
            if (data != -1)
                printf("Front: %d\n", data);
            break;
        case 4:
            printf(isEmpty(stack1, stack2) ? "Queue is Empty\n" : "Queue is Not Empty\n");
            break;
        case 5:
            free(stack1);
            free(stack2);
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}

