#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printForest(int **numbers, int rows, int cols){
    for(int i = 0; i < rows; i++){
        printf("%d |", i);
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
        printf("| %d", i);
        printf("\n");
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
    char data[100];
    fgets(data, 50, file);

    rows = atoi(data);
    printf("%d", rows);
    cols = atoi(data+1);
    printf("%d", cols);
    

    /*for(int i = 0; i < 4; i ++){
        printf("%s", sscanf(data, "%d"));
        }*/
    
    
        free(file);

    printf("rows: ");
    scanf("%d", &rows);
    printf("%d", rows);
    //if(rows != %d) {return 0;};
    printf("%d", rows);
    printf("cols: ");
    scanf("%d", &cols);

    //Creates the 2d Array with dyanimic memory allocation
    int **numbers = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++){
        numbers[i] = (int *)malloc(cols * sizeof(int));
    }


    printf("seed: ");
    scanf("%d", &seed);
    if(seed < 0 ) {return 0;}
    printf("probability: ");
    scanf("%d", &probability);
    if(probability < 0) {return 0;}

    srand(seed);

    printForest(numbers, rows, cols);
    
    
    free(numbers);
    return 0;

}