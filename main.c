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

    // int size[2] = {3,4};
    int row = 3;
    int col = 4;

    float data[12] = {
        1.0, 2.0, 3.0, 4.0,
        5.0, 23.7, 7.0, 8.0,
        9.0, 10.0, 1.5, 12.0
    };

    int trans_size[2] = {4,3};
    int row_trans = 4;
    int col_trans = 3;
    float trans_data[12] = {0 * 12};

    MatrixInit(&mtx_src, &row, &col, data);
    MatrixInit(&mtx_dst, &row_trans, &col_trans, trans_data);

    printf("before transform, mtx_src is: \n");
    MatrixPrint(&mtx_src);

    // MatrixTrans(&mtx_src, &mtx_dst);
    // printf("\nafter transform, mtx_dst is: \n");
    // MatrixPrint(&mtx_dst);
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

static void TestCholesky()
{
    matrix mtx_src;
    matrix mtx_dst;

#if 0
    int row = 2;
    int col = 2;
    float A[] = {
                    4.0,  2.0,
                    2.0,  5.0
                };  // 按行存储
#else
    int row = 3;
    int col = 3;
    float A[] = {
                    4.0,  12.0, -16.0,
                    12.0, 37.0, -43.0,
                    -16.0, -43.0, 98.0
                };
#endif
    mtx_src.row = row;
    mtx_src.col = col;
    mtx_src.data = A;

    printf("Cholesky decomposition for matrix A is: \n");
    MatrixPrint(&mtx_src);

    float *mtx_L = (float *)malloc(row * col * sizeof(float));
    mtx_dst.row = row;
    mtx_dst.col = col;
    mtx_dst.data = mtx_L;

    int ret = MatrixCholesky(&mtx_src, &mtx_dst);
    if (0 == ret)
    {
        printf("Cholesky decomposition result is: \n");
        MatrixPrint(&mtx_dst);
    }
    else
    {
        printf("Cholesky decomposition failed\n");
    }
}

static void TestMatrixScalarMulAt()
{
    matrix mtx_src;
    matrix mtx_dst;

#if 0
    int row = 2;
    int col = 2;
    float A[] = {
                    4.0,  2.0,
                    2.0,  5.0
                };  // 按行存储
#else
    int row = 3;
    int col = 3;
    float A[] = {
                    4.0,  12.0, -16.0,
                    12.0, 37.0, -43.0,
                    -16.0, -43.0, 98.0
                };
#endif
    mtx_src.row = row;
    mtx_src.col = col;
    mtx_src.data = A;

    printf("Cholesky decomposition for matrix A is: \n");
    MatrixPrint(&mtx_src);

    float *mtx_L = (float *)malloc(row * col * sizeof(float));
    mtx_dst.row = row;
    mtx_dst.col = col;
    mtx_dst.data = mtx_L;

    // int ret = MatrixCholesky(&mtx_src, &mtx_dst);
    float scalar = 2.0;
    int ret = MatrixScalarMulAt(&mtx_src, &mtx_dst, &scalar);
    if (0 == ret)
    {
        printf("Cholesky decomposition result is: \n");
        MatrixPrint(&mtx_dst);
    }
    else
    {
        printf("Cholesky decomposition failed\n");
    }
}

static void TestMatrixConcateSigmaPnts()
{
    matrix mtx_x_mean;
    matrix mtx_scalar_l;

    int row_x_mean = 4;
    int col_x_mean = 1;
    float x_mean_data[] = {
        1.0,
        2.0,
        3.0,
        4.0
    };
    mtx_x_mean.row = row_x_mean;
    mtx_x_mean.col = col_x_mean;
    mtx_x_mean.data = x_mean_data;

    int row_scalar_l = 4;
    int col_scalar_l = 1;
    float scalar_l_data[] = {
        11.0,
        12.0,
        13.0,
        14.0
    };
    // float scalar_l_data[] = {
    //     1.0, 2.0, 3.0,
    //     4.0, 5.0, 6.0,
    //     7.0, 8.0, 9.0,
    //     10.0, 11.0, 12.0
    // };
    mtx_scalar_l.row = row_scalar_l;
    mtx_scalar_l.col = col_scalar_l;
    mtx_scalar_l.data = scalar_l_data;

    printf("Matrix_x_mean: \n");
    MatrixPrint(&mtx_x_mean);

    printf("Matrix_scalar_l: \n");
    MatrixPrint(&mtx_scalar_l);

    matrix matrix_sigma_pnts;
    float *mtx_sigma_pnts = (float *)malloc(row_x_mean * (col_x_mean + 2 * col_scalar_l) * sizeof(float));
    matrix_sigma_pnts.row = row_x_mean;
    matrix_sigma_pnts.col = col_x_mean + col_scalar_l + col_scalar_l;
    matrix_sigma_pnts.data = mtx_sigma_pnts;

    MatrixConcateSigmaPnts(&mtx_x_mean, &mtx_scalar_l, &matrix_sigma_pnts);
    printf("Matrix_sigma_pnts: \n");
    MatrixPrint(&matrix_sigma_pnts);

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

    // TestReverseList();

    // TestCholesky();

    // TestMatrixScalarMulAt();

    TestMatrixConcateSigmaPnts();

    return 0;
}
