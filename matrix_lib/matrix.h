#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <math.h>
#include <string.h>

#ifndef MATRIX_DEBUG
#define MATRIX_DEBUG
#endif

#define ERROR_MATRIX_SIZE_NULL -1
#define ERROR_MATRIX_ROW_NULL -2
#define ERROR_MATRIX_COL_NULL -3
#define ERROR_MATRIX_DATA_NULL -4
#define ERROR_MATRIX_NOT_SQUARE_MTX -5
typedef struct matrix
{
    int row;
    int col;
    float *data;
}matrix;

int MatrixInit(matrix *mtx, int *row, int *col, float *data);

int MatrixCholesky(matrix *mtx_src, matrix *mtx_dst);

int MatrixScalarMulAt(matrix *mtx_src, matrix *mtx_dst, float *scalar);

int MatrixConcateSigmaPnts(matrix *mtx_x_mean, matrix *mtx_scalar_l, matrix *mtx_sigma_pnts);

// void MatrixTrans(matrix *mtx_src, matrix *mtx_dst);

void MatrixPrint(matrix *mtx);

#endif