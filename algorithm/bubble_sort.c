/*
Bubble sort repeatedly compares adjacent elements in an array and swaps 
them if they are in the wrong order. This process continues until the 
array is fully sorted, with larger elements "bubbling" to the top with 
each pass. It has a time complexity of O(n^2) and is inefficient for 
large datasets, though it performs O(n) in the best case when the array 
is already sorted.
*/

#include<stdio.h>
#include<stdlib.h>
#include "utilities.c"
    // requires utilities.c for random array generator, and array print
#include<time.h>


void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubble_sort(int* arr, int size){
    int end = size-1;
        // end index of arr is size-1
    while (end){
            // as long as end isn't 0
        int last_swaped = 0;
            // last_swaped means last swaped index
            // initially last swapped is 0
        for(int i=0; i<end; i++){
                // keeping end element aside
                // as i+1 will reach end ele
            if(arr[i] > arr[i+1]){
                swap(arr, i, i+1);
                last_swaped = i;
            }
        }
        end = last_swaped;
    }
}


int main(){
    int size = 100000;
    // srand(time(NULL));
    int* arr = rand_arr(size);

    printf("Bubble Sort\n");

    bubble_sort(arr, size);
    // print_arr(arr, size);

    return 0;    
}