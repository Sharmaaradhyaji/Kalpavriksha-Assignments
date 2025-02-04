#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 100

struct Stack
{
    char data[SIZE];
    int top;
};

void push(struct Stack *st, char ch)
{
    if (st->top < SIZE - 1)
    {
        st->data[++(st->top)] = ch;
    }
}

char pop(struct Stack *st)
{
    if (st->top == -1)
    {
        return '\0';
    }
    return st->data[(st->top)--];
}

bool checkValidity(struct Stack *st, char *str)
{
    for (int index = 0; str[index] != '\0'; index++)
    {
        char ch = str[index];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(st, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            char topChar = pop(st);
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '['))
            {
                return false;
            }
        }
    }
    return st->top == -1;
}

int main()
{
    char string[100];

    printf("Enter String: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';

    struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack));
    st->top = -1;

    printf("%s\n", checkValidity(st, string) ? "true" : "false");

    free(st);
    return 0;
}

