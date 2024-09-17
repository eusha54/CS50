/*
Quick sort is a divide-and-conquer algorithm that selects a pivot element, 
partitions the array into elements less than and greater than the pivot, 
and recursively sorts the subarrays. It has an average time complexity of 
O(nlogn) but can degrade to O(n^2) in the worst case if the pivot selection 
is poor.
*/

#include<stdio.h>
#include<stdlib.h>
#include "utilities.c"
    // stdlib required for utilities.c
    // utilities.c required for random array generator, and array print
#include<time.h>

void swap(int* arr, int i, int j)
{
    if(i==j) return;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


int partition_index(int*arr, int m, int n){
    // arr = original whole arr
    // m = start index of partition in original arr (inclusive)
    // n = end index of partition in original arr (inclusive)
        // by default n is pivot index

    // if((n-m)<=1) return m;                                   // maybe not needed
    
        // moving the pivot ele at the last of the partition arr
    
    int left = m;
        // reducing n by 2, to use it as upper limit
    int right = n-1;
        // as last pos is reserved for pivot 
        // left and right both are inclusive of the looping part
    

    while (left<=right)
    {
        // looking for larger item from left, larger than pivot val
        while (left < n)
        {
            if(arr[left]>arr[n])
            {
                break;
            }
            left++;
        }

        // looking for smaller item from right, smaller than pivot val
        while (right>=m)
        {
            if(arr[right]<arr[n])
            {
                break;
            }
            right--;
        }

        if(left<right)
        {
            swap(arr, left, right);
        }
        else
        {
            swap(arr, n, left);
                // moving the pivot to left pos
                // after completing the loop left is the 
                // first larger element than pivot
                // now all the left eles are smaller
                // right eles are larger
            return left;
                // as pivot val moved to left index
        }
    }
}

void quick_sort_recurse(int* arr, int m, int n)
    // arr = original whole arr
    // m = start index of partition in original arr (inclusive)
    // n = end index of partition in original arr (inclusive)
{
    if((n-m)<=1) return;
    
    int pi = partition_index(arr, m, n);
        // partition index is the same as pivot index for next lines

    quick_sort_recurse(arr, m, pi-1);
    quick_sort_recurse(arr, pi+1, n);
}

void quick_sort(int* arr, int size)
{
    quick_sort_recurse(arr, 0, size-1);
}

int main()
{
    int size = 1000000;
    // srand(time(NULL));
    int* arr = rand_arr(size);
    // print_arr(arr, size);

    printf("Quick Sort Version 2\n");

    quick_sort(arr, size);
    // print_arr(arr, size);

    return 0;
}



