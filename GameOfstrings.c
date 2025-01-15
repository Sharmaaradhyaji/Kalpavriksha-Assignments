#include <stdio.h>
#include <string.h>

struct Games
{
    char string[50];
    int sId;
    char gameNames[20];
    int counter;
};

struct Games students[10];

void calculatingOutput(int lengthOfStudents)
{
    int found = 0;

    for (int index = 0; index < lengthOfStudents; index++)
    {
        if (students[index].counter == 3)
        {
            printf("All games are played by: SID-%d\n", students[index].sId);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("No player plays all games.\n");
    }

    for (int i = 0; i < lengthOfStudents - 1; i++)
    {
        for (int j = i + 1; j < lengthOfStudents; j++)
        {
            if (students[j].sId < students[i].sId)
            {
                struct Games temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("All unique game players are: ");
    for (int index = 0; index < lengthOfStudents; index++)
    {
        if (students[index].counter == 1)
        {
            printf("SID-%d ", students[index].sId);
        }
    }
    printf("\n");
}

void parseStudents(int lengthOfStudents)
{
    for (int index = 0; index < lengthOfStudents; index++)
    {
        char sId[10];
        int number = 0;
        int iterator = 0;

        while (students[index].string[iterator] != ' ' && students[index].string[iterator] != '\0')
        {
            sId[iterator] = students[index].string[iterator];
            if (sId[iterator] >= '0' && sId[iterator] <= '9')
            {
                number = number * 10 + (sId[iterator] - '0');
            }
            iterator++;
        }
        sId[iterator] = '\0';

        students[index].sId = number;
        students[index].counter = 1;

        iterator++;
        int gameIndex = 0;
        while (students[index].string[iterator] != '\0')
        {
            students[index].gameNames[gameIndex++] = students[index].string[iterator++];
        }
        students[index].gameNames[gameIndex] = '\0';

        for (int i = 0; i < index; i++)
        {
            if (students[i].sId == students[index].sId)
            {
                students[i].counter++;
                students[index].counter = 0;
                break;
            }
        }
    }

    calculatingOutput(lengthOfStudents);
}

int main()
{
    int studentsLength;

    printf("Enter the number of students: ");
    scanf("%d", &studentsLength);
    getchar();

    printf("Enter ID and GameName:\n");

    for (int index = 0; index < studentsLength; index++)
    {
        fgets(students[index].string, sizeof(students[index].string), stdin);
        students[index].string[strcspn(students[index].string, "\n")] = '\0';
    }

    parseStudents(studentsLength);

    return 0;
}

