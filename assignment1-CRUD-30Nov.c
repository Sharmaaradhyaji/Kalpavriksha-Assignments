#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

struct User
{
    int userID;
    char name[MAX_LEN];
    int age;
};

void createFile(const char *fileName){
    FILE *file = fopen(fileName, "a");
    if(!file){
        printf("Error creating file.");
        return;
    }
    fclose(file);
}

void addUser(const char *fileName){
    struct User test;
    FILE *file = fopen(fileName, "a");
    if(!file){
        printf("Error opening file. \n");
        return;
    } 
    
    printf("Enter unique user ID: ");
    scanf("%d", &test.userID);

    getchar();
    printf("Enter name: \n");
    scanf("%[^\n]s", test.name);
    printf("Enter user age: ");
    scanf("%d", &test.age);

    fprintf(file, "%d,%s,%d\n", test.userID, test.name, test.age);
    fclose(file);
    printf("The new user is added!\n");
}

void displayUser(const char *fileName){
    FILE *file = fopen(fileName, "r");
    if(!file) {
        printf("No users found! \n");
        return;
    }
    
    struct User test;
    printf("Users are:- \n");
    getchar();
    while(fscanf(file, "%d,%99[^,],%d\n", &test.userID, test.name, &test.age) == 3){
        printf("user ID: %d, Name of user: %s, age of user: %d\n", test.userID, test.name, test.age);
    }
    fclose(file);
}

void updateUser(const char *fileName){
    int id;
    int flag=0;
    struct User test;
    FILE *file = fopen(fileName, "r");

    if(!file){
        printf("Error!");
        return;
    }
    FILE *temp = fopen("waste.txt", "w");
    printf("Enter id to update: \n");
    scanf("%d", &id);
    int i = 0;
    while (fscanf(file, "%d,%99[^,],%d\n", &test.userID, test.name, &test.age)==3)
    {
        if(test.userID == id){
            flag=1;
            getchar();
            printf("New Name: ");
            scanf(" %[^\n]s", test.name);
            printf("New Age: ");
            scanf("%d", &test.age);
            printf("List updated! \n");
            break;
        }
        fprintf(temp, "%d, %s, %d\n", test.userID, test.name, test.age);
    }  
    fclose(file);
    fclose(temp);

    if(flag){
        remove(fileName);
        rename("waste.txt", fileName);
        printf("User updated succesfully!\n");
    }
    else{
        remove("waste.txt");
        printf("User not found.\n");
    }
}

void removeUser(const char *fileName){
    int id, flag = 0;
    struct User test;
    FILE *file = fopen(fileName, "r");

    FILE *temp = fopen("waste.txt", "w");

    printf("Enter id to delete: \n");
    scanf("%d", &id);
    int i = 0;
    while (fscanf(file, "%d,%99[^,],%d\n", &test.userID, test.name, &test.age)==3)
    {
        if(test.userID == id){
            flag=1;
        }
    } 
    fclose(file);
    fclose(temp);

    if(flag){
        remove(fileName);
        rename("waste.txt", fileName);
        printf("Deleted User!\n");
    }
    else{
        remove("waste.txt");
    }
}


int main(){

    int flag=0;
    const char *file = "users.txt";
    createFile(file);
    
    while(flag==0){
    printf("1. Add User \n2. Display User \n3. Update User \n4. Delete User \nSelect any other choice to Exit.\n");
    int choice;
    printf("Enter choice of operation. \n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1: addUser(file);
        break;
    case 2: displayUser(file);
        break;
    case 3: updateUser(file);
        break;
    case 4: removeUser(file);
        break;
    
    default: printf("You choose to exit.");
        flag=1;
        break;
    }
    }

    return 0;
}