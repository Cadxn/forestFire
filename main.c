#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printForest(int **numbers, int rows, int cols){
    for(int i = 0; i < rows; i++){
        printf("%d |", i+1);
        for(int j = 0; j < cols; j++){
            //printf("%d |", j);
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

    printf("%d\n", rows);
    printf("%d\n", cols);
    printf("%d\n", seed);
    printf("%d\n", probability);

    /*for(int i = 0; i < 4; i ++){
        printf("%s", sscanf(data, "%d"));
        }*/

    /*
    printf("rows: ");
    scanf("%d", &rows);
    printf("%d", rows);
    //if(rows != %d) {return 0;};
    printf("%d", rows);
    printf("cols: ");
    scanf("%d", &cols);
    */

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