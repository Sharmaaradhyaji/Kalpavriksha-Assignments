#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct Node
{
    int key, value;
    struct Node *next;
};

struct HashMap
{
    struct Node *table[TABLE_SIZE];
};

int hash(int key)
{
    return key % TABLE_SIZE;
}

void insert(struct HashMap *map, int key, int value)
{
    int index = hash(key);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    struct Node *current = map->table[index];

    if (current == NULL)
    {
        map->table[index] = newNode;
    }
    else
    {
        newNode->next = current;
        map->table[index] = newNode;
    }
}

int search(struct HashMap *map, int key)
{
    int index = hash(key);
    struct Node *current = map->table[index];

    while (current != NULL)
    {
        if (current->key == key)
        {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

void deleteKey(struct HashMap *map, int key)
{
    int index = hash(key);
    struct Node *current = map->table[index];
    struct Node *prev = NULL;

    while (current != NULL)
    {
        if (current->key == key)
        {
            if (prev == NULL)
            {
                map->table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            printf("Key %d deleted.\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Key not found.\n");
}

void display(struct HashMap *map)
{
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        struct Node *current = map->table[i];
        if (current != NULL)
        {
            printf("Index %d: ", i);
            while (current != NULL)
            {
                printf("(%d, %d) -> ", current->key, current->value);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}

int main()
{
    struct HashMap *map = (struct HashMap *)malloc(sizeof(struct HashMap));
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        map->table[i] = NULL;
    }

    int choice, key, value;

    printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter value: ");
            scanf("%d", &value);
            insert(map, key, value);
            break;
        case 2:
            printf("Enter key: ");
            scanf("%d", &key);
            value = search(map, key);
            if (value != -1)
                printf("Value: %d\n", value);
            else
                printf("Key not found.\n");
            break;
        case 3:
            printf("Enter key: ");
            scanf("%d", &key);
            deleteKey(map, key);
            break;
        case 4:
            display(map);
            break;
        case 5:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

