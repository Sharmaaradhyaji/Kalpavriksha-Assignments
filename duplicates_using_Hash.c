#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

struct Transaction
{
    int transactionID;
    int userID;
    float amount;
    int timestamp;
    struct Transaction *next;
};

struct Transaction *List[SIZE] = {NULL};

int hash(int uId, float amnt)
{
    return (uId + (int)amnt) % SIZE;
}

void insert(int tID, int uID, float amnt, int stamp)
{
    int index = hash(uID, amnt);

    struct Transaction *temp = List[index];
    struct Transaction *prev = NULL;

    while (temp != NULL)
    {
        if (temp->userID == uID && temp->amount == amnt ||
            (stamp - temp->timestamp) <= 60)
        {
            printf("Duplicate transaction detected! Removing TransactionID: %d\n", temp->transactionID);

            if (prev == NULL)
            {
                List[index] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    struct Transaction *newTransaction = (struct Transaction *)malloc(sizeof(struct Transaction));
    newTransaction->userID = uID;
    newTransaction->transactionID = tID;
    newTransaction->amount = amnt;
    newTransaction->timestamp = stamp;
    newTransaction->next = List[index];
    List[index] = newTransaction;

    printf("Transaction inserted successfully!\n");
}

void display()
{
    printf("\nUnique Transactions:\n");
    for (int i = 0; i < SIZE; i++)
    {
        struct Transaction *temp = List[i];
        while (temp)
        {
            printf("TransactionID: %d UserID: %d Amount: %f Timestamp: %d\n", temp->transactionID, temp->userID, temp->amount, temp->timestamp);
            temp = temp->next;
        }
    }
}

int main()
{
    int tID = 0;
    int uID = 0;
    float amnt = 0;
    int stamp = 0;
    int choice;
    printf("Type 1 to insert.\nType 2 to display.\nType 3 to exit.\n");
    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter TransactionID, UserID, Amount, Timestamp: ");
            scanf("%d %d %f %d", &tID, &uID, &amnt, &stamp);
            insert(tID, uID, amnt, stamp);
            break;

        case 2:
            display();
            break;

        case 3:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Enter a valid choice\n");
            break;
        }
    }
}

