#include <stdio.h>

#include <stdbool.h>

#include <string.h>

bool palindrome(char string[], int startIndex, int endIndex)
{

    while (startIndex < endIndex)
    {
        if (string[startIndex] == string[endIndex])
        {
            startIndex++;
            endIndex--;
        }
        else
            return false;
    }
    return true;
}

void stringProcessing(char string[])
{

    int maxLength = 0;
    int currentLength = 0;
    int startPointer;
    int endPointer;
    int length = 0;

    while (string[length] != '\0')
    {
        length++;
    }

    for (int startIndex = 0; startIndex < length; startIndex++)
    {
        for (int endIndex = startIndex; endIndex < length; endIndex++)
        {
            if (palindrome(string, startIndex, endIndex))
            {
                currentLength = endIndex - startIndex + 1;
            }
            if (currentLength > maxLength)
            {
                maxLength = currentLength;
                startPointer = startIndex;
                endPointer = endIndex;
            }
        }
    }

    char result[100];
    int itr = 0;
    for (int index = startPointer; index <= endPointer; index++)
    {
        result[itr++] = string[index];
    }
    result[itr] = '\0';

    printf("Longest string is: %s\n", result);
    printf("Longest length is: %d", maxLength);
}

int main()
{
    char string[100];

    printf("Enter a string: ");
    scanf("%s", string);

    stringProcessing(string);

    return 0;
}

