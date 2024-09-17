#include<stdio.h>
#include<stdlib.h>
#include "utilities.c"
    // requires utilities.c for random array generator, and array print
#include<time.h>


void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void bubble_sort(int *arr, int size) {
    int swapped;

    for (int i = 0; i < size - 1; i++) {
        swapped = 0;  // Flag to track if any swap happens

        // Perform a pass through the array
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;  // Set flag if a swap occurs
            }
        }

        // If no swaps occurred during this pass, the array is sorted
        if (swapped == 0)
            break;
    }
}



int main(){
    int size = 100000;
    // srand(time(NULL));
    int* arr = rand_arr(size);

    printf("Bubble Sort By GPT\n");

    bubble_sort(arr, size);
    // print_arr(arr, size);

    return 0;   
}