#include <stdio.h>
#include <stdlib.h>

void printRepeating(int arr[], int size)
{
    int i;  

    printf("\n The repeating elements are");

    for(i = 0; i < size; i++)
    {
        if(arr[abs(arr[i])] > 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            printf(" %d ", abs(arr[i]));
    }
}     

int main()
{
    int arr[] = {1,4,5,12,34,12,34,5,8,13,6,8,6,6, 3, 2, 2, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printRepeating(arr, arr_size);
    getchar();
    return 0;
}

