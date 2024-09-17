/*
Selection sort repeatedly selects the smallest element from the unsorted portion of the array
and swaps it with the first unsorted element. This process is repeated until the entire array 
is sorted. It has a time complexity of O(n^2) and performs fewer swaps compared to other simple
sorting algorithms but is not efficient for large datasets.
*/

#include<stdio.h>
#include<stdlib.h>
#include "utilities.c"
    // stdlib requires for utilities.c


void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selection_sort(int* arr, int size)
{       // selecting the lowest and swaping with initial position
    for(int i=0; i<size; i++)
    {
        int min_index = i;
            // initially minimum val is assumed the i th val
        
        // looking for the index of minimum value
        for(int j=i+1; j<size; j++)
        {
            if(arr[min_index] > arr[j]) min_index = j; 
        }
        if(min_index != i) swap(arr, i, min_index);
    }
}


int main(){
    int size = 100000;
    // srand(time(NULL));
    int* arr = rand_arr(size);
    // print_arr(arr, size);

    printf("Selection Sort\n");

    selection_sort(arr, size);
    // print_arr(arr, size);
    
    return 0;    
}