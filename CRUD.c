#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
} User;

User users[100];
int userCount = 0;

void loadUsers() {
    FILE *file = fopen("users.txt", "r");
    userCount = 0;
    if (file == NULL) {
        printf("No existing user file found. Creating a new one.\n");
        return;
    }

    while (userCount <100 && 
           fscanf(file, "%d,%[^,],%d\n", 
                  &users[userCount].id, 
                  users[userCount].name, 
                  &users[userCount].age) == 3) {
        userCount++;
    }
    fclose(file);
}

void saveUsers() {
    FILE *file = fopen("users.txt", "w");    
    if (file == NULL) {
        printf("Error saving users to file!\n");
        return;
    }
    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%d,%s,%d\n", 
                users[i].id, 
                users[i].name, 
                users[i].age);
    }
    fclose(file);
}

int findUserById(int id) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            return i;
        }
    }
    return -1;
}

void createFile() {
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Error creating file!\n");
        exit(1);
    }
    fclose(file);
    loadUsers();
}

void addUser() {
    User newUser;
    int existingIndex;

    printf("Enter User ID: ");
    scanf("%d", &newUser.id);
    existingIndex = findUserById(newUser.id);
    if (existingIndex != -1) {
        printf("User ID %d already exists!\n", newUser.id);
        return;
    }   
    printf("Enter Name: ");
    scanf(" %[^\n]s", newUser.name);  
    printf("Enter Age: ");
    scanf("%d", &newUser.age);
    users[userCount] = newUser;
    userCount++;

    saveUsers();
    printf("User added successfully!\n");
}

void displayUsers() {
    if (userCount==0) {
        printf("No users found!\n");
        return;
    }

    printf("ID\tName\t\tAge\n");
    for (int i = 0; i < userCount; i++) {
        printf("%d\t%-15s\t%d\n", 
               users[i].id, 
               users[i].name, 
               users[i].age);
    }
}

void updateUser() {
    int searchId, index;
    printf("Enter User ID to update: ");
    scanf("%d", &searchId);

    index = findUserById(searchId);
    if (index==-1) {
        printf("User with ID %d not found!\n", searchId);
        return;
    }
    printf("Current Name: %s\n", users[index].name);
    printf("Current Age: %d\n", users[index].age);
    printf("Enter new Name: ");
    scanf(" %[^\n]s", users[index].name);
    printf("Enter new Age: ");
    scanf("%d", &users[index].age);
    saveUsers();
    printf("User updated successfully!\n");
}

void deleteUser() {
    int searchId, index;
    printf("Enter User ID to delete: ");
    scanf("%d", &searchId);
    index = findUserById(searchId);
    if (index== -1) {
        printf("User with ID %d not found!\n", searchId);
        return;
    }
    for (int i =index; i<userCount-1; i++) {
        users[i] = users[i+1];
    }
    userCount--;
    saveUsers();
    printf("User deleted successfully!\n");
}

int main() {
    int choice;
    int status=0;
    createFile();
    while (status=1) {
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addUser(); 
            break;
            case 2: displayUsers(); break;
            
            case 3: updateUser(); 
            break;
            case 4: deleteUser();
            break;
            case 5: 
                printf("Exiting the program.\n");
                status = 1;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}