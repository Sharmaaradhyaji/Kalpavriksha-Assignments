#include<stdio.h>
#include<stdlib.h>

int **matrixMultiplication(int **matrix1, int row1, int column1, int **matrix2, int row2, int column2){

    if(row1!=row2 || column1!=column2 || row1!=column2){
        printf("\nMultiplication not possible.");
        exit(1);
    }

    int **result = (int**)malloc(row2 * sizeof(int*));
    for (int i = 0; i < row2; i++) {
        result[i] = (int*)malloc(column2 * sizeof(int));
    }

    for(int i=0;i<row1;i++){
        for(int j=0;j<column1;j++){
            result[i][j]=0;
            for(int k=0;k<column2;k++){
                result[i][j]+= matrix1[i][k] *matrix2[k][j]; 
            }
        }        
    }
    return result;
    
}

void inputElements(int row, int column, int **matrix){
    printf("\nEnter %d elements for rows and %d elements for columns.\n", row, column);
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int row1, row2, column1, column2;
    printf("Enter number of rows for matrix 1: ");
    scanf("%d", &row1);
    printf("\nEnter number of columns for matrix 1: ");
    scanf("%d", &column1);
    printf("\nEnter number of rows for matrix 2: ");
    scanf("%d", &row2);
    printf("\nEnter number of columns for matrix 2: ");
    scanf("%d", &column2);

    int **matrix1 = (int**)malloc(row1 * sizeof(int*));
    for (int i = 0; i < row1; i++) {
        matrix1[i] = (int*)malloc(column1 * sizeof(int));
    }
    int **matrix2 = (int**)malloc(row2 * sizeof(int*));
    for (int i = 0; i < row2; i++) {
        matrix2[i] = (int*)malloc(column2 * sizeof(int));
    }

    printf("\n Input first matrix: ");
    inputElements(row1, column1, matrix1);
    printf("\n Input second matrix: ");
    inputElements(row2, column2, matrix2);

    int **result = matrixMultiplication(matrix1, row1, column1, matrix2, row2, column2);

    printf("Multiplied matrix is:\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<column1;j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

