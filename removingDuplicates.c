#include <stdio.h>

void removeDulplicates(char string[])
{

    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }

    for (int index = 0; index < length; index++)
    {
        for (int pointerIndex = index + 1; pointerIndex < length; pointerIndex++)
        {
            if (string[index] == string[pointerIndex])
            {
                for (int i = pointerIndex; i < length; i++)
                {
                    string[i] = string[i + 1];
                }
            pointerIndex--;
            length--;
            }
        }
    }
}

int main()
{

    char string[50];

    printf("Enter string: ");
    scanf("%s", string);

    removeDulplicates(string);

    printf("\nNew string is: %s", string);
    return 0;
}

