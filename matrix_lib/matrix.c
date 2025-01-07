#include "matrix.h"

void MatrixInit(matrix *mtx, int *size, float *data)
{
    mtx->size[0] = size[0];
    mtx->size[1] = size[1];
    mtx->data = data;
    
    return;
}

void MatrixTrans(matrix *mtx_src, matrix *mtx_dst)
{
    int i, j;
    int row = mtx_src->size[0];
    int col = mtx_src->size[1];
    float *src_data = mtx_src->data;
    float *dst_data = mtx_dst->data;
    
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            dst_data[j * row + i] = src_data[i * col + j];
        }
    }
    
    return;
}

void MatrixPrint(matrix *mtx)
{
    int i, j;
    int row = mtx->size[0];
    int col = mtx->size[1];
    float *data = mtx->data;
    
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%f  ", data[i * col + j]);
        }
        printf("\n");
    }
    
    return;
}
