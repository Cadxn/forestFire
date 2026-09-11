#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    //srand(time(NULL));
    /*
    *int numbers[2][2] = {
        {0}, {0}
    };
    */
    int rows, cols, seed, probability; 

    printf("rows: ", &rows);
    scanf("%d", &rows);
    printf("cols: ", &cols);
    scanf("%d", &cols);

    int **numbers = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++){
        numbers[i] = (int *)malloc(cols * sizeof(int));
    }


    printf("seed: ", &seed);
    scanf("%d", &seed);
    if(seed < 0 ) {return 0;}
    printf("probability: ", &probability);
    scanf("%d", &probability);
    if(probability < 0) {return 0;}

    srand(seed);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d", numbers[i][j]);
        }
        printf("\n");
    }
    return 0;
}