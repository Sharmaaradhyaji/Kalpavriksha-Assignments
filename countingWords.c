#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countingWords(char string[])
{
    int count = 0;
    int index = 0;
    int flag = 0;

    while (string[index] != '\0')
    {
        if (string[index + 1] == '\0' && flag == 1)
        {
            count++;
        }
        if ((string[index] >= 'a' && string[index] <= 'z') || (string[index] >= 'A' && string[index] <= 'Z') || (string[index] >= '0' && string[index] <= '9'))
        {
            flag = 1;
        }
        else if (string[index] == ' ' && flag == 1)
        {
            flag = 0;
            count++;
        }
        index++;
    }

    return count;
}

int main()
{
    char string[100];

    printf("Enter string: ");
    scanf("%[^\n]", string);

    printf("Number of words are: %d", countingWords(string));

    return 0;
}

