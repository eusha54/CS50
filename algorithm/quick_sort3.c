#include<stdio.h>
#include<stdlib.h>
#include "utilities.c"
    // stdlib required for utilities.c
    // utilities.c required for random array generator, and array print
#include<time.h>


// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    int size = 1000000;
    // srand(time(NULL));
    int* arr = rand_arr(size);
    // print_arr(arr, size);

    printf("Quick Sort by GPT\n");

    quickSort(arr, 0, size-1);
    // print_arr(arr, size);

    return 0;
}


