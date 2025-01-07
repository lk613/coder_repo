#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>

typedef struct matrix
{
    int size[2];
    float *data;
}matrix;

void MatrixInit(matrix *mtx, int *size, float *data);

void MatrixTrans(matrix *mtx_src, matrix *mtx_dst);

void MatrixPrint(matrix *mtx);

#endif