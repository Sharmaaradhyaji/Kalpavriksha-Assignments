#include <stdio.h>

void evaluate(int towers, char source, char auxRod, char destination)
{
    if (towers == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    evaluate(towers - 1, source, destination, auxRod);
    printf("Move disk %d from %c to %c\n", towers, source, destination);
    evaluate(towers - 1, auxRod, source, destination);
}

int main()
{
    int towers;
    scanf("%d", &towers);
    evaluate(towers, 'A', 'B', 'C');
    return 0;
}

