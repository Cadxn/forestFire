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
void **nextGeneration(int ** numbers, int rows, int cols, float probability){
    int **newNumbers = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++){
        newNumbers[i] = (int *)malloc(cols * sizeof(int));
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(numbers[i][j] == 0){
                newNumbers[i][j] = 0;
            } else if(numbers[i][j] == 1){
                if(newNumbers[i][j] != 2){
                    newNumbers[i][j] = 1;
                }
            } else if(numbers[i][j] == 2){
                float rn = (float)rand()/(float)RAND_MAX;
                //Top
                if((i != 0) && (numbers[i-1][j] == 1)){
                    printf("Top%d", i-1);
                    //rn = (float)rand()/(float)RAND_MAX;
                    if(rn <= probability){
                        newNumbers[i-1][j] = 2;
                    } else{
                        newNumbers[i-1][j] = 1;
                    }
                } 
                //Bottom
                if((i+1 != rows) && (numbers[i+1][j] == 1)){
                    rn = (float)rand()/(float)RAND_MAX;
                    printf("Bottom%d", i+1);
                    if(rn <= probability){
                        newNumbers[i+1][j] = 2;
                    } else{
                        newNumbers[i+1][j] = 1;
                    }
                }  
                //Left
                if((j != 0) && (numbers[i][j-1] == 1)){
                    rn = (float)rand()/(float)RAND_MAX;
                    printf("LLeft%d", j-1 );
                    if(rn <= probability){
                        newNumbers[i][j-1] = 2;
                    } else{
                        newNumbers[i][j-1] = 1;
                    }
                } 
                //Right
                if((j+1 != cols) && (numbers[i][j+1] == 1)){
                    printf("Right%d", j+1);
                    rn = (float)rand()/(float)RAND_MAX;
                    if(rn <= probability){
                        newNumbers[i][j+1] = 2;
                    } else{
                        newNumbers[i][j+1] = 1;
                    }
                }
                newNumbers[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            numbers[i][j] = newNumbers[i][j];
        }
    }
    free(newNumbers);
}
void populateForest(int **numbers, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            numbers[i][j] = 1;
        }
    }
}
void pause(){
    printf("<press return to continue>");
    getchar();
}

int main(){
    //srand(time(NULL));
    int rows, cols, seed, probability, time = 0, count = 1, generation = 0; 
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

    fclose(file);
    srand(seed);

    double prob = (double)probability / 100.0;

    printForest(numbers, rows, cols);
    while(count != 0){
        count = 0;
        nextGeneration(numbers, rows, cols, prob);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(numbers[i][j] == 2){
                    count++;
                }
            }
            printf("\n Count: %d\n", count);
        }
        generation++;
        printForest(numbers, rows, cols);
        //pause();

    }
    
    
    
    free(numbers);
    return 0;

}