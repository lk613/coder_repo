// #include <math.h>
#include "matrix.h"

int MatrixInit(matrix *mtx, int *row, int *col, float *data)
{
#ifdef MATRIX_DEBUG
    if (row == NULL)
    {
        printf("Error: row is NULL\n");
        return ERROR_MATRIX_ROW_NULL;
    }
    if (col == NULL)
    {
        printf("Error: col is NULL\n");
        return ERROR_MATRIX_COL_NULL;
    }
    if (data == NULL)
    {
        printf("Error: data is NULL\n");
        return ERROR_MATRIX_DATA_NULL;
    }
#endif

    mtx->row = *row;
    mtx->col = *col;
    mtx->data = data;
    
    return 0;
}


int MatrixCholesky(matrix *mtx_src, matrix *mtx_dst)
{
#ifdef MATRIX_DEBUG
    if (mtx_src == NULL)
    {
        printf("Error: mtx_src is NULL\n");
        return ERROR_MATRIX_SIZE_NULL;
    }
    if (mtx_dst == NULL)
    {
        printf("Error: mtx_dst is NULL\n");
        return ERROR_MATRIX_SIZE_NULL;
    }

    if (mtx_src->row != mtx_src->col || mtx_dst->row != mtx_dst->col || mtx_src->row != mtx_dst->row || mtx_src->row != mtx_dst->col)
    {
        printf("Error: mtx_src is not a square matrix\n");
        return ERROR_MATRIX_NOT_SQUARE_MTX;
    }
    
    if (mtx_src->row < 1)
    {
        printf("Error: mtx_src is not a valid matrix\n");
        return ERROR_MATRIX_ROW_NULL;
    }
    
    if (mtx_src->col < 1)
    {
        printf("Error: mtx_src is not a valid matrix\n");
        return ERROR_MATRIX_COL_NULL;
    }
#endif

    /* calculate diag elem for L matrix : L[j][j] */

    int n = mtx_src->row;
    int j;
    int k;
    int i;
    for (j = 0; j < n; j++)    // calculate by column
    {
        /* calculate diag elem */
        int sum_diag = 0.0f;
        for (k = 0; k < j; k++)
        {
            sum_diag = sum_diag + (mtx_dst->data[j * n + k] * mtx_dst->data[j * n + k]);
        }
        float a_jj = mtx_src->data[j * n + j];
        float diag_elem = a_jj - sum_diag;

        if (diag_elem <= 0)
        {
            printf("Error: mtx_src is not a positive definite matrix\n");
            return -1;
        }

        mtx_dst->data[j * n + j] = sqrt(diag_elem);

        /* calculate undiag elem */
        for (i = j + 1; i < n; i++)
        {
            int sum_undiag = 0.0f;
            for (k = 0; k < j; k++)
            {
                sum_undiag = sum_undiag + (mtx_dst->data[i * n + k] * mtx_dst->data[j * n + k]);
            }
            float a_ij = mtx_src->data[i * n + j];
            mtx_dst->data[i * n + j] = (a_ij - sum_undiag) / mtx_dst->data[j * n + j];
        }
    }

    return 0;
}

int MatrixScalarMulAt(matrix *mtx_src, matrix *mtx_dst, float *scalar)
{
    int row_idx, col_idx;
    int row = mtx_src->row;
    int col = mtx_src->col;
    float *data_src = mtx_src->data;
    float *data_dst = mtx_dst->data;

    for (row_idx = 0; row_idx < row; row_idx++)
    {
        for (col_idx = 0; col_idx < col; col_idx++)
        {
            data_dst[row_idx * row + col_idx] = (*scalar) * data_src[col_idx * col + row_idx];
        }
    }

    return 0;
}

int MatrixConcateSigmaPnts(matrix *mtx_x_mean, matrix *mtx_scalar_l, matrix *mtx_sigma_pnts)
{
    int x_mean_row = mtx_x_mean->row;
    int x_mean_col = mtx_x_mean->col;
    int scalar_l_row = mtx_scalar_l->row;
    int scalar_l_col = mtx_scalar_l->col;
    int sigma_pnts_row = mtx_sigma_pnts->row;
    int sigma_pnts_col = mtx_sigma_pnts->col;
    // matrix mtx_mean_cpy;
    // memcpy(&mtx_mean_cpy, mtx_x_mean, sizeof(matrix));

    int row_idx, col_idx;

    for (row_idx = 0; row_idx <sigma_pnts_row; row_idx++)
    {
        for (col_idx = 0; col_idx < x_mean_col; col_idx++)
        {
            mtx_sigma_pnts->data[row_idx * sigma_pnts_col + col_idx] = mtx_x_mean->data[row_idx * x_mean_col + col_idx];
        }

        for (col_idx = 0; col_idx < scalar_l_col; col_idx++)
        {
            mtx_sigma_pnts->data[row_idx * sigma_pnts_col + x_mean_col + col_idx] = mtx_x_mean->data[row_idx * x_mean_col + 0] + 
                mtx_scalar_l->data[row_idx * scalar_l_col + col_idx];
        }

        for (col_idx = 0; col_idx < scalar_l_col; col_idx++)
        {
            mtx_sigma_pnts->data[row_idx * sigma_pnts_col + x_mean_col + scalar_l_col + col_idx] = mtx_x_mean->data[row_idx * x_mean_col + 0] - 
                mtx_scalar_l->data[row_idx * scalar_l_col + col_idx];
        }
    }

    return 0;
}

/**
 * @brief row vector (1 x n) multiply matrix (n X m)
 * 
 * @param mtx_vec : row vector (1 x n)
 * @param mtx_src : matrix (n X m)
 * @param mtx_dst : matrix (1 X m)
 * @return int 
 */
int MatrixRowVectorMulMatrix(matrix *mtx_vec, matrix *mtx_src, matrix *mtx_dst)
{
#ifdef MATRIX_DEBUG

#endif

    int i;
    int j;
    int mtx_row = mtx_src->row;
    int ret_col = mtx_src->col; // mtx_vec->col;

    mtx_dst->row = mtx_vec->row;
    mtx_dst->col = ret_col;

    for (i = 0; i< ret_col; i++)
    {
        float dot_product = 0.0f;
        for (j = 0; j < mtx_row; j++)
        {
            dot_product += mtx_vec->data[0 * mtx_vec->row + j] * mtx_src->data[j * mtx_src->col + i]; 
        }
        mtx_dst->data[0 * mtx_dst->row + i] = dot_product;
    }

    return 0;
}

void MatrixPrint(matrix *mtx)
{
    int i, j;
    int row = mtx->row;
    int col = mtx->col;
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
