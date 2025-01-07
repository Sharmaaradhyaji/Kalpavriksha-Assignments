#include<stdio.h>

#include<stdlib.h>

int main(){

    int sizeOfMatrix;
    printf("Enter the number of rows: ");
    scanf("%d", &sizeOfMatrix);
    
    int **matrix=(int **)malloc(sizeOfMatrix * sizeof(int *));
    for(int index=0;index<sizeOfMatrix;index++){
        matrix[index]=(int *)malloc(sizeOfMatrix * sizeof(int));
    }

    printf("\nEnter Elements: ");
    for(int index1=0; index1<sizeOfMatrix; index1++){
        for(int index2=0;index2<sizeOfMatrix;index2++){
            scanf("%d", &matrix[index1][index2]);
        }
    }

    for(int index1=0; index1<sizeOfMatrix; index1++){
        for(int index2=sizeOfMatrix-1;index2>=0;index2--){
            printf("%d ", matrix[index2][index1]);
        }
        printf("\n");
    }

    for (int index=0; index<sizeOfMatrix; index++) {
        free(matrix[index]);
    }
    free(matrix);

    return 0;
}

