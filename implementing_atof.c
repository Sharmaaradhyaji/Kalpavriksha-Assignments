#include <stdio.h>

void atof(char string[])
{

    double result = 0.0;
    int index = 0;
    int number = 0;
    int sign = 1;
    double divisor = 1.0;

    while (string[index] != '\0')
    {
        if (string[index] == '-')
        {
            sign = -1;
            index++;
        }
        else if (string[index] == '+')
        {
            index++;
        }
        if (string[index] >= '0' && string[index] <= '9')
        {
            while (string[index] != '.')
            {
                result = result * 10 + (string[index] - '0');
                index++;
            }
            if (string[index] == '.')
            {
                index++;
                while (string[index] != '\0' && string[index] >= '0' && string[index] <= '9')
                {
                    result = result + (string[index] - '0') / (divisor *= 10);
                    index++;
                }
            }
        }
        index++;
    }
    result *= sign;
    printf("%lf", result);
}

int main()
{

    char string[14];

    printf("Enter the string for atof implementation: ");
    scanf("%[^\n]", string);

    atof(string);

    return 0;
}

