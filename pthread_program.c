#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

typedef struct
{
    char name[50];
    int status;
    pthread_mutex_t lock;
    int initialized;
} Room;

Room rooms[100];
int count = 0;
pthread_mutex_t global_lock;

int find_room_index(char *room)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(rooms[i].name, room) == 0)
            return i;
    }
    return -1;
}

void command_room(char *input, char *command, char *room)
{
    int i = 0, j = 0;

    while (input[i] != ' ' && input[i] != '\0')
    {
        command[i] = input[i];
        i++;
    }
    command[i] = '\0';

    while (input[i] == ' ')
        i++;

    while (input[i] != '\0')
    {
        room[j++] = input[i++];
    }
    room[j] = '\0';
}

void *control_light(void *arg)
{
    char input[100];
    strcpy(input, (char *)arg);

    char command[20], room[50];
    command_room(input, command, room);

    pthread_mutex_lock(&global_lock);
    int index = find_room_index(room);
    if (index == -1)
    {
        index = count++;
        strcpy(rooms[index].name, room);
        rooms[index].status = 0;
        pthread_mutex_init(&rooms[index].lock, NULL);
        rooms[index].initialized = 1;
    }
    pthread_mutex_unlock(&global_lock);

    pthread_mutex_lock(&rooms[index].lock);

    if (strcmp(command, "TURN_ON") == 0)
    {
        rooms[index].status = 1;
        printf("Light in %s turned ON\n", room);
    }
    else if (strcmp(command, "TURN_OFF") == 0)
    {
        rooms[index].status = 0;
        printf("Light in %s turned OFF\n", room);
    }
    else if (strcmp(command, "STATUS") == 0)
    {
        printf("Light in %s is %s\n", room, rooms[index].status ? "ON" : "OFF");
    }

    pthread_mutex_unlock(&rooms[index].lock);
    pthread_exit(NULL);
}

int main()
{
    int n;
    printf("Enter number of commands: ");
    scanf("%d", &n);
    getchar();

    pthread_t threads[n];
    pthread_mutex_init(&global_lock, NULL);

    char inputs[n][100];

    for (int i = 0; i < n; i++)
    {
        fgets(inputs[i], 100, stdin);
        inputs[i][strcspn(inputs[i], "\n")] = '\0';

        pthread_create(&threads[i], NULL, control_light, (void *)inputs[i]);
    }

    for (int i = 0; i < n; i++)
    {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < count; i++)
    {
        if (rooms[i].initialized)
        {
            pthread_mutex_destroy(&rooms[i].lock);
        }
    }
    pthread_mutex_destroy(&global_lock);

    return 0;
}

