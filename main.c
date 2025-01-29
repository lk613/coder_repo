#include <stdio.h>
#include <string.h>
#include "quick_sort.h"
#include "sort_alg/QuickSort/quick_sort.h"
#include "matrix_lib/matrix.h"
#include "sword_to_offer/link_list/reverse_linklist.h"

#define ARRAY_MAX_NUM 10

static void PrintArray(int *input_array, int array_size);
static void TestMatrixTrans();

static void PrintArray(int *input_array, int array_size)
{
    int i;
    for (i = 0; i < array_size; i++)
    {
        printf("%d  ", input_array[i]);
    }
    printf("\n");
}

static void TestMatrixTrans()
{
    matrix mtx_src;
    matrix mtx_dst;

    int size[2] = {3,4};
    float data[12] = {
        1.0, 2.0, 3.0, 4.0,
        5.0, 23.7, 7.0, 8.0,
        9.0, 10.0, 1.5, 12.0
    };

    int trans_size[2] = {4,3};
    float trans_data[12] = {0 * 12};

    MatrixInit(&mtx_src, size, data);
    MatrixInit(&mtx_dst, trans_size, trans_data);

    printf("before transform, mtx_src is: \n");
    MatrixPrint(&mtx_src);

    MatrixTrans(&mtx_src, &mtx_dst);
    printf("\nafter transform, mtx_dst is: \n");
    MatrixPrint(&mtx_dst);
}

static void TestReverseList()
{
    int arr[6] = {1, 2, 2, 3, 4, 5};
    int length = 6;

    struct ListNode *p_head = GenerateList(arr, length);
    printf("before reverse, linklist is: \n");
    PrintList(p_head);

    printf("start reverse linklist ... \n");
    struct ListNode *reversed_list = ReverseList(p_head);

    printf("after reverse, linklist is: \n");
    PrintList(reversed_list);
}


int main(){
#if 0
    printf("Hello, from code_repo!\n");

    int arr[ARRAY_MAX_NUM] = {3, 15, 0, 4, 8, 8, 20, 14, 20, 53};
    int ascend_flag = 0;
    printf("Before Sort, array is: \n");
    PrintArray(arr, ARRAY_MAX_NUM);

    QuickSort(arr, 0, 9, ascend_flag);

    printf("After Sort, array is: \n");
    if (1 == ascend_flag)
    {
        printf("升序排列结果\n");
    }else if (0 == ascend_flag)
    {
        printf("降序排列结果\n");
    }
    PrintArray(arr, ARRAY_MAX_NUM);
#endif

    // TestMatrixTrans();

    TestReverseList();

    return 0;
}
