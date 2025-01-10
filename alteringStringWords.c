#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int location;

void addNewWord(char string[], char newWord[], int lengthOfString)
{

    int lengthOfNewWord = 0;
    while (newWord[lengthOfNewWord] != '\0')
    {
        lengthOfNewWord++;
    }

    for (int i = lengthOfString; i >= location; i--)
    {
        string[i + lengthOfNewWord] = string[i];
    }

    for (int j = 0; j < lengthOfNewWord; j++)
    {
        string[location + j] = newWord[j];
    }
}

int removeWord(char string[], char wordToBeReplaced[])
{

    int lengthOfString = 0;
    while (string[lengthOfString] != '\0')
    {
        lengthOfString++;
    }

    int lengthOfWord = 0;
    while (wordToBeReplaced[lengthOfWord] != '\0')
    {
        lengthOfWord++;
    }

    int iterator = 0;
    int flag = 0;
    for (int index = 0; index <= lengthOfString; index++)
    {
        if (index == lengthOfString)
        {
            printf("Word Not Found");
            return -1;
        }
        if (string[index] == wordToBeReplaced[iterator])
        {
            flag = 0;
            int temp = index;
            while (iterator < lengthOfWord)
            {
                if (string[++temp] == wordToBeReplaced[++iterator])
                {
                    continue;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                location = index;
                while (index < lengthOfString - lengthOfWord)
                {
                    string[index] = string[index + lengthOfWord];
                    index++;
                }
                lengthOfString -= lengthOfWord;
                string[lengthOfString] = '\0';
            }
        }
    }
    return lengthOfString;
}

int main()
{

    char string[50];
    char wordToBeReplaced[10];
    char newWord[10];
    printf("Enter the string: ");
    scanf("%[^\n]", string);

    printf("Enter word to be replaced: ");
    scanf("%s", wordToBeReplaced);

    printf("\nEnter the new word: ");
    scanf("%s", newWord);

    int stringLengthAfterRemoval = removeWord(string, wordToBeReplaced);

    if(stringLengthAfterRemoval==-1){
        return 0;
    }
    addNewWord(string, newWord, stringLengthAfterRemoval);

    printf("\nNew string is: %s", string);
    return 0;
}

