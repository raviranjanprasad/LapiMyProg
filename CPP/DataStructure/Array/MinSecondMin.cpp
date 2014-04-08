#include <stdio.h>
#include <limits.h> /* For INT_MAX */

/* Function to print first smallest and second smallest elements */
void print2Smallest(int arr[], int arr_size)
{
    int i, first, second;

    /* There should be atleast two elements*/
    if(arr_size < 2)
    {
        printf(" Invalid Input ");
        return;
    }            

    first = second = arr[0];
    for(i = 0; i < arr_size ; i ++)
    {

        /*If current element is smaller than first then update both
         *       first and second */
        if(arr[i] < first)
        {
            second = first;
            first = arr[i];
        }

        /* If arr[i] is in between first and second then update second  */
        else if (arr[i] < second)
        {
            second = arr[i];
        }
    }
    printf("The smallest element is %d\n second Smallest element is %d\n",
            first, second);
}

/* Driver program to test above function */
int main()
{
    int arr[] = {-5,12, 13, 15,10, 35,1};
    print2Smallest(arr, 6);
    getchar();
    return 0;
}

