#include <stdio.h>
#define MAX_SIZE 100

struct Stack
{
    int data[MAX_SIZE];
    int top;
};

void push(struct Stack *stack)
{
    int value;
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack is full\n");
        return;
    }
    printf("Enter the value to be added: ");
    scanf("%d", &value);

    stack->top++;
    stack->data[stack->top] = value;
    printf("Value added\n");
}

void pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    stack->top--;
    printf("Value removed\n");
}

void peek(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("The first element is: %d\n", stack->data[stack->top]);
}

void isEmpty(struct Stack *Stack)
{
    if (Stack->top == -1)
    {
        printf("The Stack is empty.\n");
    }
    else
    {
        printf("The Stack is not empty.\n");
    }
}

void findSize(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Queue size: 0\n");
    }
    else
    {
        printf("Queue size: %d\n", (stack->top) + 1);
    }
}

int main()
{
    struct Stack st;
    st.top = -1;

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
            push(&st);
            break;
        case 2:
            pop(&st);
            break;
        case 3:
            peek(&st);
            break;
        case 4:
            isEmpty(&st);
            break;
        case 5:
            findSize(&st);
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

