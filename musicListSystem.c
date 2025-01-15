#include <stdio.h>
#include <string.h>

struct Music
{
    int ID;
    char Title[20];
    char Artist[20];
    char Genre[10];
    float Duration;
};

int trackIndex = 0;

struct Music list[100];

void AddTrack()
{
    printf("Enter details to add track: \n");

    printf("Enter Id: ");
    scanf("%d", &list[trackIndex].ID);
    getchar(); 

    printf("Enter Title: ");
    fgets(list[trackIndex].Title, sizeof(list[trackIndex].Title), stdin);
    list[trackIndex].Title[strcspn(list[trackIndex].Title, "\n")] = 0;

    printf("Enter Artist: ");
    fgets(list[trackIndex].Artist, sizeof(list[trackIndex].Artist), stdin);
    list[trackIndex].Artist[strcspn(list[trackIndex].Artist, "\n")] = 0;

    printf("Enter Genre: ");
    scanf("%s", list[trackIndex].Genre);

    printf("Enter Duration (in minutes): ");
    scanf("%f", &list[trackIndex].Duration);

    printf("Track Added Successfully.\n");
    trackIndex++;
}

void DisplayTrack()
{
    if (trackIndex == 0)
    {
        printf("No tracks available.\n");
        return;
    }

    printf("Displaying all tracks:\n");
    for (int i = 0; i < trackIndex; i++)
    {
        printf("Title: %s\n", list[i].Title);
        printf("ID: %d\n", list[i].ID);
        printf("Genre: %s\n", list[i].Genre);
        printf("Artist: %s\n", list[i].Artist);
        printf("Duration: %.2f\n\n", list[i].Duration);
    }
}

void DeleteTrack()
{
    int deletionID;
    printf("Enter Id to delete: ");
    scanf("%d", &deletionID);

    int found = 0;
    for (int i = 0; i < trackIndex; i++)
    {
        if (list[i].ID == deletionID)
        {
            found = 1;
            for (int j = i; j < trackIndex - 1; j++)
            {
                list[j] = list[j + 1];
            }
            trackIndex--;
            printf("Track deleted successfully.\n");
            break;
        }
    }
    if (!found)
    {
        printf("Track with ID %d not found.\n", deletionID);
    }
}

void SearchTrack()
{
    char titleName[20];
    getchar(); 
    printf("Enter title to search: ");
    fgets(titleName, sizeof(titleName), stdin);
    titleName[strcspn(titleName, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < trackIndex; i++)
    {
        if (strcmp(list[i].Title, titleName) == 0)
        {
            printf("Track Found:\n");
            printf("ID: %d\n", list[i].ID);
            printf("Genre: %s\n", list[i].Genre);
            printf("Artist: %s\n", list[i].Artist);
            printf("Duration: %.2f\n\n", list[i].Duration);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Track with title '%s' not found.\n", titleName);
    }
}

void SortTrack()
{
    for (int i = 0; i < trackIndex - 1; i++)
    {
        for (int j = i + 1; j < trackIndex; j++)
        {
            if (strcmp(list[i].Title, list[j].Title) > 0)
            {
                struct Music temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    printf("Tracks sorted by title.\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\nEnter choice of operation:\n");
        printf("1. Add Track\n");
        printf("2. Delete Track\n");
        printf("3. List Tracks\n");
        printf("4. Search Track\n");
        printf("5. Sort Tracks\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            AddTrack();
            break;
        case 2:
            DeleteTrack();
            break;
        case 3:
            DisplayTrack();
            break;
        case 4:
            SearchTrack();
            break;
        case 5:
            SortTrack();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

