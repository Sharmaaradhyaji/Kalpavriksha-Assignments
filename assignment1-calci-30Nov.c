#include <stdio.h>

#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int precedence(char operator)
{
    return (operator== '+' || operator== '-') ? 1 : (operator== '*' || operator== '/') ? 2 : 0;
}

int main()
{

    char str[MAX_LEN];

    int flag = 0;

    printf("Enter a string for calculation: \n");
    scanf("%[^\n]%*c", str);

    int stack[MAX_LEN];
    int topStack = -1;
    char operators[MAX_LEN];
    int topOperators = -1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isspace(str[i]))
            continue;

        if (isdigit(str[i]))
        {
            int num = 0;
            while (isdigit(str[i]))
            {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            i--;
            stack[++topStack] = num;
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            while (topOperators >= 0)
            {
                char currOperator = str[i];
                if (precedence(operators[topOperators]) < precedence(currOperator))
                    break;

                int b = stack[topStack--];
                int a = stack[topStack--];

                char operatorApplicable = operators[topOperators--];

                if (operatorApplicable == '/' && b == 0)
                {
                    flag = 2;
                }

                switch (operatorApplicable)
                {
                case '+':
                    stack[++topStack] = a + b;
                    break;
                case '-':
                    stack[++topStack] = a - b;
                    break;
                case '*':
                    stack[++topStack] = a * b;
                    break;
                case '/':
                    stack[++topStack] = a / b;
                    break;

                default:
                    break;
                }
            }
            operators[++topOperators] = str[i];
        }
        else
            flag = 1;
    }
    while (topOperators >= 0)
    {
        int b = stack[topStack--];
        int a = stack[topStack--];

        char operatorApplicable = operators[topOperators--];

        if (operatorApplicable == '/' && b == 0)
        {
            flag = 2;
            break;
        }

        switch (operatorApplicable)
        {
        case '+':
            stack[++topStack] = a + b;
            break;
        case '-':
            stack[++topStack] = a - b;
            break;
        case '*':
            stack[++topStack] = a * b;
            break;
        case '/':
            stack[++topStack] = a / b;
            break;

        default:
            break;
        }
    }

    printf(flag == 1 ? "Error: Invalid Expression." : flag == 2 ? "Error: Use of zero is invalid." : "Answer: %d\n",
           stack[0]);

    return 0;
}