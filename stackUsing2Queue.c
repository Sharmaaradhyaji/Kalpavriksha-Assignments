#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int data[100];
    int front, rear, size;
};

void enqueue(struct Queue *queue, int value) {
    if (queue->size == 100) return; 
    queue->data[queue->rear++] = value;
    queue->size++;
}

int dequeue(struct Queue *queue) {
    if (queue->size == 0) return -1;
    int val = queue->data[queue->front++];
    queue->size--;
    return val;
}

int front(struct Queue *q) {
    return (q->size > 0) ? q->data[q->front] : -1;
}

struct Stack {
    struct Queue *q1, *q2;
};

void push(struct Stack *stack, int value) {
    enqueue(stack->q1, value);
}

void pop(struct Stack *stack) {
    if (stack->q1->size == 0) {
        printf("Stack is empty.\n");
        return;
    }
    while (stack->q1->size > 1) {
        int dequeueValue = dequeue(stack->q1);
        enqueue(stack->q2, dequeueValue);
    }
    dequeue(stack->q1);
    struct Queue *temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}

int topDisplay(struct Stack *stack) {
    if (stack->q1->size == 0) {
        printf("Stack is empty.\n");
        return -1;
    }
    while (stack->q1->size > 1) {
        int dequeueValue = dequeue(stack->q1);
        enqueue(stack->q2, dequeueValue);
    }
    int topElement = front(stack->q1);

    int dequeueValue = dequeue(stack->q1);
    enqueue(stack->q2, dequeueValue);
    struct Queue *temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
    return topElement;
}

int sizeDisplay(struct Stack *stack) {
    return stack->q1->size;
}

int isEmpty(struct Stack *stack) {
    return stack->q1->size == 0;
}

int main() {
    struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack));

    struct Queue *queue1 = (struct Queue *)malloc(sizeof(struct Queue));
    struct Queue *queue2 = (struct Queue *)malloc(sizeof(struct Queue));

    queue1->front = 0;
    queue1->rear = 0;
    queue1->size = 0;

    queue2->front = 0;
    queue2->rear = 0;
    queue2->size = 0;

    st->q1 = queue1;
    st->q2 = queue2;

    int choice, data;

    printf("\nStack implementation using two queues\n");
    printf("1. Push element onto the stack\n");
    printf("2. Display the top element of the stack\n");
    printf("3. Pop element from the stack\n");
    printf("4. Display the size of the stack\n");
    printf("5. Check if the stack is empty\n");
    printf("6. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data you want to push: ");
                scanf("%d", &data);
                push(st, data);
                break;
            case 2:
                data = topDisplay(st);
                if (data != -1) printf("Top element is: %d\n", data);
                break;
            case 3:
                pop(st);
                break;
            case 4:
                printf("Size of the stack is: %d\n", sizeDisplay(st));
                break;
            case 5:
                if (isEmpty(st)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 6:
                free(queue1);
                free(queue2);
                free(st);
                printf("Exiting the program\n");
                return 0;
            default:
                printf("Enter a valid choice.\n");
        }
    }

    return 0;
}

