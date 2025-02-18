#include <stdio.h>
#include <string.h>
#include "quick_sort.h"
#include "sort_alg/QuickSort/quick_sort.h"
#include "matrix_lib/matrix.h"
#include "sto/link_list/list_node.h"
#include "sto/link_list/delete_inverse_kth.h"
#include "sto/link_list/reverse_linklist.h"
#include "sto/array/two_sum.h"

#ifndef TWO_SUM_BY_HASH_TABLE
#define TWO_SUM_BY_HASH_TABLE
#endif

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

#if 1
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

    MatrixTrans(&mtx_src, &mtx_dst);
    printf("\nafter transform, mtx_dst is: \n");
    MatrixPrint(&mtx_dst);
}
#endif

static void TestMatrixMultiply()
{
    matrix mtx_a;
    matrix mtx_b;
    matrix mtx_dst;

    int row = 3;
    int col = 4;

    float data_a[12] = {
        1.0, 2.0, 3.0, 4.0,
        5.0, 23.7, 7.0, 8.0,
        9.0, 10.0, 1.5, 12.0
    };

    mtx_a.row = row;
    mtx_a.col = col;
    mtx_a.data = data_a;

    float data_b[12] = {
        1.0, 1.0, 2.0,
        2.0, 3.0, 5.0,
        10.0, 23.0, 4.0,
        3.0, 5.0, 10.0
    };
    mtx_b.row = col;
    mtx_b.col = row;
    mtx_b.data = data_b;

    mtx_dst.row = 3;
    mtx_dst.col = 3;
    mtx_dst.data = (float *)malloc(9 * sizeof(float));

    printf("mtx a: \n");
    MatrixPrint(&mtx_a);

    printf("mtx b: \n");
    MatrixPrint(&mtx_b);

    MatrixMultiply(&mtx_a, &mtx_b, &mtx_dst);

    printf("mtx dst: \n");
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

static void TestMatrixRowVectorMulMatrix()
{
    matrix row_vec;
    matrix mtx_mult_src;

    int row_vec_num = 1;
    int col_vec_num = 4;
    float x_mean_data[4] = {1.0, 2.0, 3.0, 4.0};
    row_vec.row = row_vec_num;
    row_vec.col = col_vec_num;
    row_vec.data = x_mean_data;

    int row_mul_num = 4;
    int col_mul_num = 3;
    float mtx_mul_data[12] = {
        11.0, 12.0, 13.0,
        14.0, 15.0, 16.0,
        17.0, 18.0, 19.0,
        20.0, 21.0, 22.0
    };

    mtx_mult_src.row = row_mul_num;
    mtx_mult_src.col = col_mul_num;
    mtx_mult_src.data = mtx_mul_data;

    printf("Row Vector: \n");
    MatrixPrint(&row_vec);

    printf("Matrix Multi: \n");
    MatrixPrint(&mtx_mult_src);

    matrix ret_vector_mul_mtx;
    float *mtx_sigma_pnts = (float *)malloc(row_vec_num * col_mul_num * sizeof(float));
    ret_vector_mul_mtx.row = row_vec_num;
    ret_vector_mul_mtx.col = col_mul_num;
    ret_vector_mul_mtx.data = mtx_sigma_pnts;

    MatrixRowVectorMulMatrix(&row_vec, &mtx_mult_src, &ret_vector_mul_mtx);
    printf("ret_vector_mul_mtx: \n");
    MatrixPrint(&ret_vector_mul_mtx);

}

static void TestMatrixSubVectorMtx()
{
    matrix mtx_a;
    matrix mtx_b;

    int row_num_a = 1;
    int col_num_a = 3;
    float mtx_a_data[4] = {11.0, 12.0, 13.0};
    mtx_a.row = row_num_a;
    mtx_a.col = col_num_a;
    mtx_a.data = mtx_a_data;

    int row_num_b = 4;
    int col_num_b = 3;
    float mtx_b_data[12] = {
        1.0, 2.0, 3.0,
        4.0, 5.0, 6.0,
        7.0, 8.0, 9.0,
        10.0, 11.0, 12.0
    };

    mtx_b.row = row_num_b;
    mtx_b.col = col_num_b;
    mtx_b.data = mtx_b_data;

    printf("Matrix a: \n");
    MatrixPrint(&mtx_a);

    printf("Matrix b: \n");
    MatrixPrint(&mtx_b);

#if 1
    matrix ret_b_sub_a;
    float *add_b_sub_a = (float *)malloc(row_num_b * col_num_b * sizeof(float));
    ret_b_sub_a.row = row_num_b;
    ret_b_sub_a.col = col_num_b;
    ret_b_sub_a.data = add_b_sub_a;
#else
    matrix ret_a_sub_b;
    float *add_a_sub_b = (float *)malloc(row_num_b * col_num_b * sizeof(float));
    ret_a_sub_b.row = row_num_b;
    ret_a_sub_b.col = col_num_b;
    ret_a_sub_b.data = add_a_sub_b;
#endif

    // MatrixSubVectorMtx(&mtx_a, &mtx_b, &ret_a_sub_b);
    MatrixSubVectorMtx(&mtx_b, &mtx_a, &ret_b_sub_a);
    printf("Matrix ret_a_sub_b: \n");
#if 1
    MatrixPrint(&ret_b_sub_a);
#else
    MatrixPrint(&ret_a_sub_b);
#endif
}

static void TestMatrixRowScale()
{
    matrix scale_vec;
    matrix mtx_mult_src;

    int row_vec_num = 1;
    int col_vec_num = 4;
    float scale_vec_data[4] = {1.0, 2.0, 3.0, 4.0};
    scale_vec.row = row_vec_num;
    scale_vec.col = col_vec_num;
    scale_vec.data = scale_vec_data;

    int row_mul_num = 4;
    int col_mul_num = 3;
    float mtx_mul_data[12] = {
        11.0, 12.0, 13.0,
        14.0, 15.0, 16.0,
        17.0, 18.0, 19.0,
        20.0, 21.0, 22.0
    };

    mtx_mult_src.row = row_mul_num;
    mtx_mult_src.col = col_mul_num;
    mtx_mult_src.data = mtx_mul_data;

    printf("Scale Vector: \n");
    MatrixPrint(&scale_vec);

    printf("Matrix Multi: \n");
    MatrixPrint(&mtx_mult_src);

    matrix ret_vector_mul_mtx;
    float *ret_matrix = (float *)malloc(row_mul_num * col_mul_num * sizeof(float));
    ret_vector_mul_mtx.row = row_mul_num;
    ret_vector_mul_mtx.col = col_mul_num;
    ret_vector_mul_mtx.data = ret_matrix;

    MatrixRowScale(&mtx_mult_src, &scale_vec, &ret_vector_mul_mtx);
    printf("ret_vector_mul_mtx: \n");
    MatrixPrint(&ret_vector_mul_mtx);

}

static void TestMatrixWgtMulErrMulErrT()
{
    matrix mtx_row_vec;
    matrix mtx_err;

    int row_num_a = 1;
    int col_num_a = 5;
    float mtx_a_data[5] = {0.1, 0.2, 0.2, 0.2, 0.3};
    mtx_row_vec.row = row_num_a;
    mtx_row_vec.col = col_num_a;
    mtx_row_vec.data = mtx_a_data;

    int row_num_b = 2;
    int col_num_b = 5;
    float mtx_b_data[10] = {
        1, 2, 3, 4, 5,
        6, 7, 8, 9, 10
    };

    mtx_err.row = row_num_b;
    mtx_err.col = col_num_b;
    mtx_err.data = mtx_b_data;

    printf("Matrix row vector: \n");
    MatrixPrint(&mtx_row_vec);

    printf("Matrix error: \n");
    MatrixPrint(&mtx_err);

    matrix mtx_dst;
    float *a_mul_b_mul_bt = (float *)malloc(row_num_b * row_num_b * sizeof(float));
    mtx_dst.row = row_num_b;
    mtx_dst.col = row_num_b;
    mtx_dst.data = a_mul_b_mul_bt;
    MatrixWgtMulErrMulErrT(&mtx_row_vec, &mtx_err, &mtx_dst);
    printf("Matrix a_mul_b_mul_bt: \n");
    MatrixPrint(&mtx_dst);
    free(a_mul_b_mul_bt);
}

#if 0
static void TestMatrixTrans()
{
    matrix mtx_src;
    matrix mtx_trans;

    int row_num = 1;
    int col_num = 5;
    float matrix_data[5] = {1, 2, 3, 4, 5};
    mtx_src.row = row_num;
    mtx_src.col = col_num;
    mtx_src.data = matrix_data;

    int row_num_t = col_num;
    int col_num_t = row_num;
    // float mtx_trans_data[5];
    mtx_trans.row = row_num_t;
    mtx_trans.col = col_num_t;
    mtx_trans.data = (float *)malloc(row_num_t * col_num_t * sizeof(float));

    printf("Matrix src: \n");
    MatrixPrint(&mtx_src);

    MatrixTrans(&mtx_src, &mtx_trans);

    printf("Matrix trans: \n");
    MatrixPrint(&mtx_trans);
}
#endif

static void TestTwoDataSum()
{
    int arr[6] = {1, 2, 2, 3, 4, 5};
    int length = 6;
    int target = 8;
    int ret[2] = {-1, -1};
    printf("Source array is: \n");
    PrintArr(arr, length);

    printf("target num is: %d\n", target);

#ifdef TWO_SUM_BY_HASH_TABLE
    int ret_val = TwoElemSumByHashTable(arr, length, target, ret);
#else
    int ret_val = TwoElemSum(arr, length, target, ret);
#endif
    if (0 == ret_val)
    {
        printf("Has two elements !\n");
        printf("Two elements index is: %d, %d\n Two elem data is: %d, %d\n", ret[0], ret[1], arr[ret[0]], arr[ret[1]]);
    }
    else
    {
        printf("Two elements sum is not found\n");
    }
}

static void TestDelInvKth()
{
    int array[8] = {2, 15, 3, 8, 11, 23, 7, 9};
    printf("Create List Node ...\n");
    ListNode *pHead = GenerateList(array, 8);
    printf("Source List Node is:  \n");
    PrintList(pHead);

    int kth = 4;
#ifdef LEETCODE_STYLE
    removeNthFromEnd(pHead, kth);
#else
    DeleteInverseKth(pHead, kth);
#endif
    printf("Delete ListList inverse %d node, LinkList is: \n", kth);
    PrintList(pHead);
}

static void TestMatrixDeterminant()
{
    matrix mtx_src;
#if 1
    float mtx_array[9] = 
    {
        6, 12, 3,
        3, 4, 5,
        5, 6, 7
    };

    mtx_src.row = 3;
    mtx_src.col = 3;
    mtx_src.data = mtx_array;
#else
    float mtx_array[1] = 
    {
        3
    };

    mtx_src.row = 1;
    mtx_src.col = 1;
    mtx_src.data = mtx_array;
#endif
    printf("Matrix src: \n");
    MatrixPrint(&mtx_src);

    int order = 3;
    float det = determinant(&mtx_src, &order);

    printf("Matrx src det is:  %.3f\n", det);
}

static void TestMatrixInverse()
{
    matrix mtx_src;
    matrix mtx_dst;

#if 1
    float src_array[9] = {
        1, 2, 3,
        2, 4, 6, 
        3, 6, 9
    };

    int mtx_order = 3;
    mtx_src.row = mtx_order;
    mtx_src.col = mtx_order;
    mtx_src.data = src_array;

    float *dst_address = (float *)malloc(mtx_order * mtx_order * sizeof(float));
    mtx_dst.row = mtx_order;
    mtx_dst.col = mtx_order;
    mtx_dst.data = dst_address;
#else
    float src_array[9] = {
        1, 2, 3,
        0, 1, 4,
        5, 6, 0
    };

    int mtx_order = 3;
    mtx_src.row = mtx_order;
    mtx_src.col = mtx_order;
    mtx_src.data = src_array;

    float *dst_address = (float *)malloc(mtx_order * mtx_order * sizeof(float));
    mtx_dst.row = mtx_order;
    mtx_dst.col = mtx_order;
    mtx_dst.data = dst_address;
#endif

    printf("Matrix src is:  \n");
    MatrixPrint(&mtx_src);

    MatrixInverse(&mtx_src, &mtx_dst);

    printf("Matrix src inverse matrix is: \n");
    MatrixPrint(&mtx_dst);

    free(dst_address);
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

    /**********************test matrix********************** */

    // TestMatrixTrans();

    // TestReverseList();

    // TestCholesky();

    // TestMatrixScalarMulAt();

    // TestMatrixConcateSigmaPnts();

    // TestMatrixRowVectorMulMatrix();

    // TestMatrixRowScale();

    // TestMatrixSubVectorMtx();
    
    // TestMatrixWgtMulErrMulErrT();

    // TestMatrixDeterminant();

    // TestMatrixInverse();

    // TestMatrixTrans();

    // TestMatrixMultiply();

    /**********************test matrix********************** */


    /**********************test sto********************** */
    // TestTwoDataSum();

    TestDelInvKth();
    /**********************test sto********************** */

    return 0;
}
