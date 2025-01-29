#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
    struct Node* child;
};

struct Node* flatten(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->child != NULL) {
            struct Node* nextNode = current->next;
            struct Node* child = flatten(current->child);
            current->next = child;
            if (child != NULL) {
                child->prev = current;
            }
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = nextNode;
            if (nextNode != NULL) {
                nextNode->prev = current;
            }
            current->child = NULL;
        }
        current = current->next;
    }

    return head;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int mainListSize, nodeValue;
    printf("Enter the number of nodes in the main list: ");
    scanf("%d", &mainListSize);

    struct Node* mainListHead = NULL;
    struct Node* currentNode = NULL;
    struct Node* prevNode = NULL;

    printf("Enter values for the main list:\n");
    for (int index = 0; index < mainListSize; index++) {
        currentNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &nodeValue);
        currentNode->val = nodeValue;
        currentNode->next = NULL;
        currentNode->prev = prevNode;
        currentNode->child = NULL;
        
        if (prevNode != NULL) {
            prevNode->next = currentNode;
        } else {
            mainListHead = currentNode;
        }
        prevNode = currentNode;
    }

    int childListSize;
    printf("Enter the number of nodes in the child list: ");
    scanf("%d", &childListSize);

    struct Node* childListHead = NULL;
    struct Node* childPrevNode = NULL;

    printf("Enter values for the child list:\n");
    for (int index = 0; index < childListSize; index++) {
        currentNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &nodeValue);
        currentNode->val = nodeValue;
        currentNode->next = NULL;
        currentNode->prev = childPrevNode;
        currentNode->child = NULL;

        if (childPrevNode != NULL) {
            childPrevNode->next = currentNode;
        } else {
            childListHead = currentNode;
        }
        childPrevNode = currentNode;
    }

    if (mainListSize > 1) {
        mainListHead->next->child = childListHead;
    }

    printf("Flattened List: ");
    struct Node* flattenedList = flatten(mainListHead);
    printList(flattenedList);

    return 0;
}
