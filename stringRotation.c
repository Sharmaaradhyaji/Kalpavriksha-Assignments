#include <stdio.h>

int checkRotation(char string1[], char string2[])
{
    int string1Length = 0;
    while (string1[string1Length] != '\0')
    {
        string1Length++;
    }

    int string2Length = 0;
    while (string1[string2Length] != '\0')
    {
        string2Length++;
    }

    if (string1Length != string2Length)
    {
        return -1;
    }

    for (int index1 = 0; index1 < string1Length; index1++)
    {
        for (int index2 = 0; index2 < string2Length; index2++)
        {
            if (string1[index1] == string2[index2])
            {
                index2++;
                index1++;
                while (string2[index2] != '\0')
                {
                    if (string1[index1] == '\0')
                    {
                        index1 = 0;
                    }
                    else if (string1[index1] == string2[index2])
                    {
                        index1++;
                        index2++;
                        continue;
                    }
                    else
                        return -1;
                }
                return 1;
            }
        }
    }

    return -1;
}

int main()
{
    char string1[50];
    char string2[50];

    printf("Enter first string: ");
    scanf("%s", string1);

    printf("Enter second string: ");
    scanf("%s", string2);

    int result = checkRotation(string1, string2);
    if (result == 1)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    return 0;
}

