#include <stdio.h>
#include <string.h>

int SubstringExistence(char string[], char substring[])
{
    int index = 0;
    int iterator = 0;
    int length = 0;

    while (string[index] != '\0')
    {
        if (string[index] == substring[iterator])
        {
            int temporaryIterator = index + 1;
            iterator++;
            while (string[temporaryIterator] != '\0' || substring[iterator] != '\0')
            {
                if (string[temporaryIterator++] == substring[iterator++])
                {
                    length++;
                }
                else
                {
                    iterator = 0;
                    length = 0;
                    break;
                }
            }
            if (length > 0)
            {
                return index;
            }
        }
        index++;
    }

    return -1;
}

int main()
{
    char string[100];
    char substring[10];
    printf("Enter String: ");
    scanf("%[^\n]", string);

    printf("Enter Substring: ");
    scanf("%s", substring);

    printf("%d", SubstringExistence(string, substring));

    return 0;
}

