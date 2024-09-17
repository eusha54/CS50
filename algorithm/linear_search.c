// linear search algorithm
// time complexity O(n)
/*
Linear search checks each element of an array sequentially until it finds 
the target value or reaches the end. It works for both sorted and unsorted 
arrays and has a time complexity of O(n). If the target is found, it returns 
the index; otherwise, it returns -1.
*/


#include<stdio.h>
#include<stdlib.h>
#include "utilities.c"
    // stdlib requires for utilities.c

int linearly_search(int* arr, int size, int val)
        // -1 when value isn't matched
        // else returns index
{
    for(int i=0; i<size; i++)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}



int main(){
    int size1 = 10;
    int find_val = 6;
    int* arr1 = rand_arr(size1);
    print_arr(arr1, size1);
    printf("\nindex of %d is : %d\n", find_val, linearly_search(arr1, size1, find_val));
    return 0;
}