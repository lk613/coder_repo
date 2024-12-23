#include <stdio.h>
#include "quick_sort.h"
#include "sort_alg/QuickSort/quick_sort.h"

#define ARRAY_MAX_NUM 10

static void PrintArray(int *input_array, int array_size);

static void PrintArray(int *input_array, int array_size)
{
    int i;
    for (i = 0; i < array_size; i++)
    {
        printf("%d  ", input_array[i]);
    }
    printf("\n");
}


int main(){
    printf("Hello, from code_repo!\n");

    int arr[ARRAY_MAX_NUM] = {3, 15, 0, 4, 8, 8, 20, 14, 20, 53};
    printf("Before Sort, array is: \n");
    PrintArray(arr, ARRAY_MAX_NUM);

    QuickSort(arr, 0, 9, 1);

    printf("After Sort, array is: \n");
    PrintArray(arr, ARRAY_MAX_NUM);

    return 0;
}
