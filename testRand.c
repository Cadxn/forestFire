#include <stdio.h>
#include <stdlib.h>

int main(){
    int seed = 0;
    printf("Enter a seed value: ");
    scanf("%d", &seed);

    srand(seed);

    printf("Random numbers generated with seed %d:\n", seed);
    float rn = (float)rand()/(float)RAND_MAX; // Dividing by a large number to get a float between 0 and 1
    printf("%f\n", rn);
    printf("%f\n", (75.0/100.0));
    rn = (float)rand()/(float)RAND_MAX; 
    printf("%f\n", rn);
    printf("%f\n", (75.0/100.0));

    return 0;
}