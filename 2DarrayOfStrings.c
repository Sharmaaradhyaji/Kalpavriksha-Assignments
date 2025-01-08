#include<stdio.h>

#include<string.h>

#include<stdlib.h>

int main(){

    int rows, columns;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    
    printf("\n Enter number of columns: ");
    scanf("%d", &columns);

    char ***matrix = (char ***)malloc(rows*sizeof(char **));
    for (int i = 0; i < rows; i++){
        matrix[i]=(char **)malloc(columns*sizeof(char *));
        for (int j=0; j<columns; j++){
            matrix[i][j]=(char *)malloc(50*sizeof(char));
        }
    }

    printf("\nEnter the names: \n");

    for(int index1=0;index1<rows;index1++){
        for(int index2=0;index2<columns;index2++){
            printf("Name at (%d, %d): ", index1, index2);
            scanf("%s", matrix[index1][index2]);
        }
    }

    char *longestName=matrix[0][0];
    int countOfVowels=0;

    for(int index1=0;index1<rows;index1++){
        for(int index2=0;index2<columns;index2++){
            printf("%s ", matrix[index1][index2]);

            if(strlen(matrix[index1][index2])>strlen(longestName)){
                strcpy(longestName, matrix[index1][index2]);
            }
            
            if(matrix[index1][index2][0]=='a' || matrix[index1][index2][0]=='e' ||matrix[index1][index2][0]=='i' ||matrix[index1][index2][0]=='o' ||matrix[index1][index2][0]=='u' ||matrix[index1][index2][0]=='A' || matrix[index1][index2][0]=='E' ||matrix[index1][index2][0]=='I' ||matrix[index1][index2][0]=='O' ||matrix[index1][index2][0]=='U'){
                countOfVowels++;
            }
        }
        printf("\n");
    }

    printf("Number of names starting with a vowel: %d\n", countOfVowels);
    printf("Longest name is: %s\n", longestName);

    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++){
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

