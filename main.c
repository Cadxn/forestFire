#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printForest(int **numbers, int rows, int cols){
    //Prints the 10's digit first everytime there is a 10 milestone
    printf("   ");
    for(int i = 0; i < cols; i++){
        if((((i+1)%10) == 0) && i != 0){
            printf("%d", (i+1)/10);
        } else{
            printf(" ");
        }
    } printf("\n   ");

    //Prints the 1's digit of the column numbers on the top
    for(int i = 0; i < cols; i++){
        if((((i+1)%10) == 0) && ((i+1) != 0)){
            printf("0");
        } else if (i >= 10){
            printf("%d", (i%10)+1);
        } else{
            printf("%d", i+1);
        }
    } printf("\n  +");

    //Prints the top border of the forest
    for(int i = 0; i < cols; i++){
        printf("-");
    } printf("+");
    
    printf("\n");
    //Prints the forest
    for(int i = 0; i < rows; i++){
        printf("%d |", i+1);
        for(int j = 0; j < cols; j++){
            if(numbers[i][j] == 0){
                printf("."); 
            } else if(numbers[i][j] == 1){
                printf("T"); 
            }
            else if(numbers[i][j] == 2){
                printf("F"); 
            }
        }
        printf("| %d", i+1);
        printf("\n");
    }   

    //Prints the bottom border of the forest
    printf("  +");
    for(int i = 0; i < cols; i++){
        printf("-");
    } printf("+\n   ");  

    //Prints the 1's digit of the column numbers on the bottom
    for(int i = 0; i < cols; i++){
        if((((i+1)%10) == 0) && ((i+1) != 0)){
            printf("0");
        } else if (i >= 10){
            printf("%d", (i%10)+1);
        } else{
            printf("%d", i+1);
        }
    } printf("\n   ");
    
     //Prints the 10's digit first everytime there is a 10 milestone
    for(int i = 0; i < cols; i++){
        if((((i+1)%10) == 0) && i != 0){
            printf("%d", (i+1)/10);
        } else{
            printf(" ");
        }
    }
}
void populateForest(int **numbers, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            numbers[i][j] = 1;
        }
    }
}

int main(){
    //srand(time(NULL));
    int rows, cols, seed, probability; 
    FILE *file;
    char filename[100];
    scanf("%s", filename);

    file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file.\n");
        return 1;
    } else {
        printf("File opened successfully.\n");
    }

    fscanf(file, "%d", &rows);
    fscanf(file, "%d", &cols);
    fscanf(file, "%d", &seed);
    fscanf(file, "%d", &probability);

    printf("rows: %d\n", rows);
    printf("cols: %d\n", cols);
    printf("seed: %d\n", seed);
    printf("probability: %d\n", probability);

    //Creates the 2d Array with dyanimic memory allocation
    int **numbers = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++){
        numbers[i] = (int *)malloc(cols * sizeof(int));
    }

    char type = 'O';
    int i, j;
    while(1){
        fscanf(file, " %c", &type);
        //printf("Type: %c\n", type);
        if(type == 'Q'){
            break;
        }
        if(type == 'E'){
            fscanf(file, "%d", &i);
            fscanf(file, "%d", &j);
            numbers[i-1][j-1] = 0;
        }
        else if(type == 'T'){
            fscanf(file, "%d", &i);
            fscanf(file, "%d", &j);
            numbers[i-1][j-1] = 1;
        } else if (type == 'F'){
            fscanf(file, "%d", &i);
            fscanf(file, "%d", &j);
            numbers[i-1][j-1] = 2;

        }else if(type == 'A'){
            populateForest(numbers, rows, cols);
        }
    }


    /*
    printf("seed: ");
    scanf("%d", &seed);
    if(seed < 0 ) {return 0;}
    printf("probability: ");
    scanf("%d", &probability);
    if(probability < 0) {return 0;}
    */

    srand(seed);

    printForest(numbers, rows, cols);
    
    
    free(numbers);
    fclose(file);
    return 0;

}