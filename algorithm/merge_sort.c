/*
Merge Sort Summary:

Merge sort is a divide-and-conquer algorithm that splits the input array 
into smaller subarrays, sorts them individually, and then merges the sorted
subarrays to produce a fully sorted array. It operates recursively and works
as follows:

    1. Divide: Split the array into two halves recursively until each subarray 
            has only one element (which is trivially sorted).
    2. Conquer: Sort and merge the subarrays by comparing elements from each 
            half and building a sorted array.
    3. Merge: Combine the two halves by taking the smallest element from either 
            half and placing it in the correct position in the final array.

Time Complexity: O(n log n) in all cases (best, average, and worst).
Space Complexity: O(n), because of the extra space needed to merge subarrays.
*/


#include<stdio.h>
#include<stdlib.h>
#include "utilities.c"
    // stdlib required for utilities.c
    // utilities.c required for random array generator, and array print
#include<time.h>


void merge(int* arr, int m, int n, int o)
        // m = start index arr1 inclusive
        // n = end index arr1 exclusive
        //   = start index arr2 inclusive
        // o = end index arr2 exclusive
{

    int i = 0, size = o-m;
        // current index and size of merged array
    int m_up = n, n_up = o;
        // m_up is upper limit index for array 1
        // n_up is upper limit index for array 2
    
    int* arr_merged = malloc(sizeof(int)*size);
        // temporarily storing merged array heere

    while (m<m_up && n<n_up)
        // whenever m or n reaches maximum limit which means
        // arr1 or arr2 is finished inserting in merged arr
        // loop stops
    {
        if(arr[m]<=arr[n]){
            arr_merged[i] = arr[m];
            m++;
        }else{
            arr_merged[i] = arr[n];
            n++;
        }
        i++;
    }

    // if arr1 has leftovers, it will be added to arr_merged
    while(m<m_up)
    {
        arr_merged[i] = arr[m];
        m++;
        i++;
    }
    
    // if arr2 has leftovers, it will be added to arr_merged
    while(n<n_up)
    {
        arr_merged[i] = arr[n];
        n++;
        i++;
    }


    m = o-size;
        // retriving m, as m is changed in prev loops
        // as declared initially, size = o-m
        // m is the initial pos of merged sorted arr
    for(i=0; i<size; i++){
        arr[m+i] = arr_merged[i];
            // adding arr_merged eles to original arr
            // replacing old values
    }

    free(arr_merged);
        // freeing up memory used by arr_merged
}


void merge_sort(int* arr, int strt, int end)
            // start and end position of array
            // initially start=0, end=size
            // end is exclusive
{
    if(end-strt>1)
        // as end is exclusive end-strt will have minimum val of 1
        // when end-strt==1, element count in the array is 1
        // therefore array is already sorted
    {
        int m,n,o;
            // m = start index arr1 inclusive
            // n = end index arr1 exclusive
            //   = start index arr2 inclusive
            // o = end index arr2 exclusive
        m = strt;
        n = strt + (end-strt+1)/2;
        o = end;

        merge_sort(arr, m, n);
            // sorting first half of the array
        merge_sort(arr, n, o);
            // sorting next half of the array
        
        merge(arr,m,n,o);
            // now merging both part of the array
    }
}


int main()
{
    int size = 1000000;
    // srand(time(NULL));
    int* arr = rand_arr(size);
    // print_arr(arr, size);

    printf("Merge Sort\n");

    merge_sort(arr, 0, size);
    // print_arr(arr, size);
}