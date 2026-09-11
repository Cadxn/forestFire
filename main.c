#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    //srand(time(NULL));
    int rows, cols, seed, probability; 

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
    
    free(numbers);
    return 0;

}