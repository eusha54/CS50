// requirements
// <stdio.h>
// <stdlib.h>

void print_arr(int* arr, int size){
    printf("array size   : %d\n", size);
    for(int i=0; i<size; i++){
        printf("%d\t", arr[i]);
        if((i+1)%10 == 0) printf("\n");
    }
    printf("\n");
}

int* rand_arr(int size){
    int* arr = malloc(sizeof(int)*size);
    int divisor = 5*size;
    for(int i=0; i<size; i++){
        arr[i] = rand()%divisor;
    }
    return arr;
}

int* rand_sorted_arr(int size){  
    int* arr = malloc(sizeof(int)*size);
    int divisor = 5;
    
    arr[0] = rand()%divisor;
    for(int i=1; i<size; i++){
        arr[i] = arr[i-1] + rand()%divisor;
    }
    return arr;
}