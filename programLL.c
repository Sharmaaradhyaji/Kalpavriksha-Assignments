#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *creatingLL(struct Node *head, int n){
    struct Node *head = NULL, *temp = NULL, *prev = NULL;
    
    for (int index = 0; index < n; index++) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data for node %d: ", index + 1);
        scanf("%d", &(newNode->data));
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;
    }
    return head;
}

int main(){
    int k, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter k: ");
    scanf("%d", &k);

    struct Node *head=(struct Node*)malloc(sizeof(struct Node));

    head = creatingLL(head, n);

    struct Node* temp=head;
    struct Node* lptr=NULL;
    struct Node* rptr=NULL;

    for(int i=0;i<k;i++){
        rptr=rptr->next;
    }
     
    while(temp!=NULL){

    }

    return 0;
}
