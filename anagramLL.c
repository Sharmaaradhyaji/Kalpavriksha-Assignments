#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char string[100];
    struct Node *next;
};

struct Hash
{
    char shabd[50];
    struct Node *head;
};

struct Hash *List[100];

void sort(char word[50])
{
    int len = strlen(word);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (word[i] > word[j])
            {
                char temp = word[i];
                word[i] = word[j];
                word[j] = temp;
            }
        }
    }
}

int main()
{
    char *words[] = {"listen", "silent", "enlist", "rat", "tar", "art", "dog", "god"};
    int n = 8;

    for (int i = 0; i < n; i++)
    {
        List[i] = (struct Hash *)malloc(sizeof(struct Hash));
        List[i]->head = NULL;
    }

    for (int i = 0; i < n; i++)
    {
        char sortedString[50];
        strcpy(sortedString, words[i]);
        sort(sortedString);
        strcpy(List[i]->shabd, sortedString);
    }

    int processed[n];
    for (int i = 0; i < n; i++)
    {
        processed[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (processed[i])
            continue;

        char word[50];
        strcpy(word, List[i]->shabd);

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        strcpy(newNode->string, words[i]);
        newNode->next = NULL;

        if (List[i]->head == NULL)
        {
            List[i]->head = newNode;
        }
        else
        {
            struct Node *temp = List[i]->head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (processed[j])
                continue;
            if (strcmp(word, List[j]->shabd) == 0)
            {
                struct Node *tempNode = (struct Node *)malloc(sizeof(struct Node));
                strcpy(tempNode->string, words[j]);
                tempNode->next = NULL;

                struct Node *temp = List[i]->head;
                while (temp->next)
                    temp = temp->next;
                temp->next = tempNode;

                processed[j] = 1;
            }
        }
        processed[i] = 1;
    }

    int group = 1;
    for (int i = 0; i < n; i++)
    {
        if (List[i] && List[i]->head)
        {
            struct Node *temp = List[i]->head;
            printf("Anagram Group %d: ", group++);
            while (temp)
            {
                printf("%s -> ", temp->string);
                temp = temp->next;
            }
            printf("NULL\n");
            for (int j = i + 1; j < n; j++)
            {
                if (strcmp(List[i]->shabd, List[j]->shabd) == 0)
                {
                    List[j] = NULL;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (List[i])
        {
            struct Node *temp = List[i]->head;
            while (temp)
            {
                struct Node *toDelete = temp;
                temp = temp->next;
                free(toDelete);
            }
            free(List[i]);
        }
    }

    return 0;
}

