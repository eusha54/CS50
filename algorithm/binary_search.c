// binary search algorithm
// time complexity O(log(n))
// requirement: sorted array
/*
Binary search is an efficient algorithm for finding a target value in a sorted array. 
It repeatedly divides the search interval in half:

    01. Start by comparing the target with the middle element.
    02. If the target equals the middle element, return its index.
    03. If the target is smaller, repeat the search on the left half.
    04. If the target is larger, repeat the search on the right half.
    05. Continue until the target is found or the search interval is empty.
    
Time Complexity:
Best case: O(1)
Average/Worst case: O(logn)
*/


#include<stdio.h>
#include<stdlib.h>
#include "utilities.c"
    // stdlib requires for utilities.c


int binary_search(int* arr, int size, int val){
    // assuming the array is sorted from low to high
    int high = size;
    int low = 0;
    int mid;

    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(arr[mid] == val){
            return mid;
        }else if(arr[mid] > val){
            high = mid-1;
        }else if(arr[mid] < val){
            low = mid+1;
        }
    }
    return -1;
}


int main(){
    int size1 = 10;
    int find_val = 7;
    int* arr1 = rand_sorted_arr(size1);
    print_arr(arr1, size1);
    printf("\nindex of %d is : %d\n", find_val, binary_search(arr1, size1, find_val));
    return 0;
}