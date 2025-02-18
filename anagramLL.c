#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node
{
    char Word[100];
    struct Node *next;
};

bool checkHash(int hash[128], char *word)
{
    int hash1[128] = {0};

    int k = 0;
    while (word[k] != '\0')
    {
        hash1[word[k]]++;
        k++;
    }

    for (int i = 0; i < 128; i++)
    {
        if (hash[i] != hash1[i])
        {
            return false;
        }
    }
    return true;
}

void printGroup(struct Node *head, int group)
{
    printf("Word Group %d: ", group);
    struct Node *temp = head;
    while (temp)
    {
        printf("%s -> ", temp->Word);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(struct Node *head)
{
    struct Node *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    char words[100][100];
    int n;

    printf("Insert the number of words: ");
    scanf("%d", &n);
    
    printf("Insert words: \n");
    for(int i=0;i<n;i++){
        scanf("%s", words[i]);
    }

    int processed[n];
    for (int i = 0; i < n; i++)
    {
        processed[i] = 0;
    }

    int group = 1;
    for (int i = 0; i < n; i++)
    {
        int hash[128] = {0};

        int k = 0;
        while (words[i][k] != '\0')
        {
            hash[words[i][k]]++;
            k++;
        }

        struct Node *head = NULL;
        struct Node *tail = NULL;
        if (processed[i])
        {
            continue;
        }
        for (int j = i; j < n; j++)
        {
            if (processed[j])
            {
                continue;
            }
            if (checkHash(hash, words[j]))
            {
                processed[j] = 1;
                struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
                strcpy(newNode->Word, words[j]);
                newNode->next = NULL;
                if (!head)
                {
                    head = newNode;
                    tail=newNode;
                }
                else
                {
                    tail->next=newNode;
                    tail=tail->next;
                }
            }
        }
        printGroup(head, group++);
        freeList(head);
    }
    return 0;
}

