#include <stdio.h>

#include <string.h>

#include <stdlib.h>

void Strcat(char string1[], char string2[])
{
    int index = 0;
    char stringResult[101];

    while (string1[index] != '\0')
    {
        stringResult[index] = string1[index];
        index++;
    }

    int iterator = 0;
    while (string2[iterator] != '\0')
    {
        stringResult[index] = string2[iterator++];
        index++;
    }
    stringResult[index] = '\0';

    printf("\nThe concatinated string is: %s", stringResult);
}

int main()
{
    char string1[50];
    char string2[50];

    printf("Enter string1: ");
    scanf("%[^\n]", string1);
    getchar();
    printf("Enter string2: ");
    scanf("%[^\n]", string2);

    Strcat(string1, string2);

    return 0;
}
