#include <stdio.h>

#include <string.h>

#include <stdlib.h>

void shortestWord(char string[])
{
    int index = 0;
    int minlength = 50;
    int length = 0;
    int location = 0;
    int start = 0;

    while (string[index] != '\0')
    {
        if (string[index] == ' ' || string[index + 1] == '\0')
        {

            if (string[index + 1] == '\0')
            {
                length++;
            }
            if (minlength > length)
            {
                minlength = length;
                location = start;
            }
            length = 0;
            start = index + 1;
        }
        else
        {
            length++;
        }
        index++;
    }

    char word[10];
    index = 0;
    while (index < minlength)
    {
        word[index++] = string[location++];
    }
    word[index] = '\0';

    printf("Shortest Word is: %s\n", word);
}

void longestWord(char string[])
{
    int index = 0;
    int maxlength = 0;
    int length = 0;
    int location = 0;
    int start = 0;

    while (string[index] != '\0')
    {
        if (string[index] == ' ' || string[index + 1] == '\0')
        {

            if (string[index + 1] == '\0')
            {
                length++;
            }
            if (maxlength < length)
            {
                maxlength = length;
                location = start;
            }
            length = 0;
            start = index + 1;
        }
        else
        {
            length++;
        }
        index++;
    }

    char word[100];
    index = 0;
    while (index < maxlength)
    {
        word[index++] = string[location++];
    }
    word[index] = '\0';

    printf("Longest Word is: %s\n", word);
}

int main()
{
    char string[50];

    printf("Enter the string: ");
    scanf("%[^\n]", string);

    longestWord(string);
    shortestWord(string);

    return 0;
}

