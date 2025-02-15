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

int MatrixSubVectorMtx(matrix *mtx_a, matrix *mtx_b, matrix *mtx_dst)
{
    int row_idx;
    int col_idx;
    int flag;
#ifdef MATRIX_DEBUG
    if ((mtx_a->row != 1) && (mtx_a->col != 1) && (mtx_b->row != 1) && (mtx_b->col != 1))
    {
        printf("Error: mtx_a or mtx_b is not a vector\n");
        return ERROR_MATRIX_OPPORATION_INVALID;
    }
#endif

    if ((mtx_a->row == 1) && (mtx_b->row != 1) && (mtx_a->col == mtx_b->col))
    {
        flag = 0;
    }
    else if ((mtx_a->col == 1) && (mtx_b->col != 1) && (mtx_a->row == mtx_b->row))
    {
        flag = 1;
    }
    else if ((mtx_b->row == 1) && (mtx_a->row != 1) && (mtx_a->col == mtx_b->col))
    {
        flag = 2;
    }else if ((mtx_b->col == 1) && (mtx_a->col != 1) && (mtx_a->row == mtx_b->row))
    {
        flag = 3;
    }else
    {
        printf("Error: mtx_a or mtx_b is not a vector\n");
        return ERROR_MATRIX_OPPORATION_INVALID;
    }

    for (row_idx = 0; row_idx < mtx_dst->row; row_idx++)
    {
        for (col_idx = 0; col_idx < mtx_dst->col; col_idx++)
        {
            switch (flag)
            {
                case 0:
                    mtx_dst->data[row_idx * mtx_dst->col + col_idx] = mtx_a->data[0 * mtx_a->row + col_idx] - mtx_b->data[row_idx * mtx_b->col + col_idx];
                    break;
                case 1:
                    mtx_dst->data[row_idx * mtx_dst->col + col_idx] = mtx_a->data[row_idx * mtx_a->col + 0] - mtx_b->data[row_idx * mtx_b->col + col_idx];
                    break;
                case 2:
                    mtx_dst->data[row_idx * mtx_dst->col + col_idx] = mtx_a->data[row_idx * mtx_a->col + col_idx] - mtx_b->data[0 * mtx_b->row + col_idx];
                    break;
                case 3:
                    mtx_dst->data[row_idx * mtx_dst->col + col_idx] = mtx_a->data[row_idx * mtx_a->col + col_idx] - mtx_b->data[row_idx * mtx_b->col + 0];
                    break;
                default:
                    break;
            }
        }
    }

    return 0;
}

int MatrixRowScale(matrix *mtx_src, matrix *scale_vector, matrix *mtx_dst)
{
#ifdef MATRIX_DEBUG
    if ((mtx_src->row == 1) || (mtx_src->col == 1))
    {
        printf("Error: mtx_src is not a matrix\n");
        return ERROR_MATRIX_OPPORATION_INVALID;
    }
    if ((scale_vector->row != 1)  || (scale_vector->col != mtx_src->row))
    {
        printf("Error: scale_vector is not a valid vector\n");
        return ERROR_MATRIX_OPPORATION_INVALID;
    }
#endif

    int row_idx;
    int col_idx;
    for (row_idx = 0; row_idx < mtx_dst->row; row_idx++)
    {
        for (col_idx = 0; col_idx < mtx_dst->col; col_idx++)
        {
            mtx_dst->data[row_idx * mtx_dst->col + col_idx] = mtx_src->data[row_idx * mtx_src->col + col_idx] 
                    * scale_vector->data[row_idx];
        }
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

/**
 * @brief A x B x B^T
 * 
 * @param mtx_wgt : [1 x n]
 * @param mtx_err : [n x 2n+1]
 * @param mtx_dst : [n x n]
 * @return int 
 */
int MatrixWgtMulErrMulErrT(matrix *mtx_wgt, matrix *mtx_err, matrix *mtx_dst)
{
#ifdef MATRIX_DEBUG
    if (mtx_wgt->row != 1)
    {
        printf("Error: mtx_wgt is not a row vector\n");
        return ERROR_MATRIX_SIZE_NOT_MATCH;
    }

    if (mtx_wgt->col != mtx_err->col)
    {
        printf("Error: mtx_wgt and mtx_err is not a valid matrix\n");
        return ERROR_MATRIX_SIZE_NOT_MATCH;
    }
#endif
    
    int i;
    int j;
    int k;

    for (i = 0; i < mtx_dst->row; i++)
    {
        for (j = 0; j < mtx_dst->col; j++)
        {
            for (k = 0; k < mtx_wgt->col; k++)
            {
                mtx_dst->data[i * mtx_dst->col + j] += mtx_wgt->data[k] * mtx_err->data[k * mtx_err->col + i] * mtx_err->data[k * mtx_err->col + j];
            }
        }
    }

    return 1;
}

int MatrixAdd(matrix *mtx_a, matrix *mtx_b, matrix *mtx_dst)
{

#ifdef MATRIX_DEBUG
    if ((mtx_a->row != mtx_b->row) || (mtx_a->col != mtx_b->col))
    {
        printf("Error: mtx_a and mtx_b is not a valid matrix\n");
        return ERROR_MATRIX_SIZE_NOT_MATCH;
    }
#endif

    int row_idx;
    int col_idx;

    for (row_idx = 0; row_idx < mtx_dst->row; row_idx++)
    {
        for (col_idx = 0; col_idx < mtx_dst->col; col_idx++)
        {
            mtx_dst->data[row_idx * mtx_dst->col + col_idx] = mtx_a->data[row_idx * mtx_a->col + col_idx] + mtx_b->data[row_idx * mtx_b->col + col_idx];
        }
    }

    return 0;
}

int MatrixSubtraction(matrix *mtx_a, matrix *mtx_b, matrix *mtx_diff)
{
#ifdef MATRIX_DEBUG
    if (mtx_a->row != mtx_b->row || mtx_a->col != mtx_b->col)
    {
        printf("Matrix size unmatch for matrix substraction ! \n");
        return ERROR_MATRIX_SIZE_NOT_MATCH;
    }
#endif

    int row_idx, col_idx;
    int row_num, col_num;

    row_num = mtx_a->row;
    col_num = mtx_b->col;

    for (row_idx = 0; row_idx < row_num; row_idx++)
    {
        for (col_idx = 0; col_idx < col_num; col_idx++)
        {
            mtx_diff->data[row_idx * mtx_a->col + col_idx] = mtx_a->data[row_idx * mtx_a->col + col_idx] + mtx_b->data[row_idx * mtx_b->col + col_idx];
        }
    }

    return 0;
}

int MatrixCopy(matrix *mtx_src, matrix *mtx_dst)
{
    int row_idx;
    int col_idx;

    for (row_idx = 0; row_idx < mtx_dst->row; row_idx++)
    {
        for (col_idx = 0; col_idx < mtx_dst->col; col_idx++)
        {
            mtx_dst->data[row_idx * mtx_dst->col + col_idx] = mtx_src->data[row_idx * mtx_src->col + col_idx];
        }
    }

    return 0;
}

int MatrixTrans(matrix *mtx_src, matrix *mtx_dst)
{
#ifdef MATRIX_DEBUG
    if ((mtx_src->row < 1) || (mtx_src->col < 1) || (mtx_dst->row < 1) || (mtx_dst->col < 1))
    {
        printf("MATRIX INPUT SIZE INVALID !\n");
        return ERROR_MATRIX_OPPORATION_INVALID;
    }

    if ((mtx_src->data == NULL) || (mtx_dst->data == NULL))
    {
        printf("MATRIX IS NULL ! \n");
        return ERROR_MATRIX_DATA_NULL;
    }
#endif

    int row_num = mtx_src->row;
    int col_num = mtx_src->col;
    int row_idx, col_idx;

    for (row_idx = 0; row_idx < row_num; row_idx++)
    {
        for (col_idx = 0; col_idx < col_num; col_idx++)
        {
            mtx_dst->data[col_idx * row_num + row_idx] = mtx_src->data[row_idx * col_num + col_idx];
        }
    }

    return 0;
}


int MatrixMultiply(matrix *mtx_a, matrix *mtx_b, matrix *mtx_dst)
{
#ifdef MATRIX_DEBUG
    if ((mtx_a->row < 1) || (mtx_a->col < 1) || (mtx_b->row < 1) || (mtx_b->col < 1))
    {
        return ERROR_MATRIX_SIZE_NOT_MATCH;
    }

    if (mtx_a->col != mtx_b->row)
    {
        return ERROR_MATRIX_SIZE_NOT_MATCH;
    }

    if ((mtx_a->data == NULL) || (mtx_b->data == NULL))
    {
        return ERROR_MATRIX_DATA_NULL;
    }
#endif

    int row_num = mtx_a->row;
    int col_num = mtx_b->col;
    int row_idx, col_idx, k;
    float sum;
    
    for (row_idx = 0; row_idx < row_num; row_idx++)
    {
        for (col_idx = 0; col_idx < col_num; col_idx++)
        {
            sum = 0.f;
            for (k = 0; k < mtx_a->col; k++)
            {
                sum += mtx_a->data[row_idx * mtx_a->col + k] * mtx_b->data[k * col_num + col_idx];
            }
            mtx_dst->data[row_idx * col_num + col_idx] = sum;
        }
    }

    return 0;
}

/**
 * @brief calculate matrix determiant
 * 
 * @param mtx 
 * @param order 
 * @return float 
 */
float determinant(matrix *mtx, int *order)
{
    static float cofactor_array[4];
    float det;
    int m, i, j;
    int order_t;

    det = 0;
    if (1 == *order)
    {
        det = mtx->data[0];
    }else if (2 == *order)
    {
        det = mtx->data[3] * mtx->data[0] - mtx->data[1] * mtx->data[2];
    }else
    {
        int n_order = *order - 1;
        matrix mtx_tmp;
        MatrixInit(&mtx_tmp, &n_order, &n_order, cofactor_array);

        for (m = 0; m < *order; m++)
        {
            int cur_i = 0;
            for (i = 1; i < *order; i++)
            {
                int cur_j = 0;
                for (j = 0; j < *order; j++)
                {
                    if (j != m)
                    {
                        mtx_tmp.data[cur_i * mtx_tmp.col + cur_j] = mtx->data[i * mtx->col + j];
                        cur_j++;
                    }
                }
                cur_i++;
            }
            
            order_t = *order - 1;
            det += ((m % 2 == 1) ? -1 : 1) * mtx->data[0 * mtx->col + m] * determinant(&mtx_tmp, &order_t);
        }
    }

    return det;
}

/**
 * @brief Get the Cofactor object
 * 
 * @param mtx_src 
 * @param row 
 * @param col 
 * @param order 
 * @param mtx_dst 
 */
void GetCofactor(matrix *mtx_src, int *row, int *col, int *order, matrix *mtx_dst)
{
    int cur_i, cur_j;
    int row_idx, col_idx;
    cur_i = 0, cur_j = 0;

    for (row_idx = 0; row_idx < *order; row_idx++)
    {
        for (col_idx = 0; col_idx < *order; col_idx++)
        {
            if ((row_idx != *row) && (col_idx != *col))
            {
                mtx_dst->data[cur_i * mtx_dst->col + cur_j++] = mtx_src->data[row_idx * mtx_src->col + col_idx];
                if (cur_j == (*order - 1))
                {
                    cur_j = 0;
                    cur_i++;        /* break inside for loop*/
                }
            }
        }
    }
}

/**
 * @brief calculate matrix adjugate matrix;
 * 
 * @param mtx_src 
 * @param mtx_dst 
 */
void MatrixAdjugate(matrix *mtx_src, int *order, matrix *mtx_dst)
{
#ifdef MATRIX_DEBUG
    if (mtx_src->row != mtx_src->col)
    {
        printf("INPUT MATRIX MUST SQUARE MATRIX !\n");
        return;
    }
#endif

    if (1 == (*order))
    {
        mtx_dst->data[0] = mtx_src->data[0];
        return;
    }

    int det_tmp;
    int sign;
    float mtx_arr_t[4] = {0};
    matrix mtx_temp;
    int order_t = (*order) - 1;
    MatrixInit(&mtx_temp, &order_t, &order_t, mtx_arr_t);

    int row_idx, col_idx;
    for (row_idx = 0; row_idx < *order; row_idx++)
    {
        for(col_idx = 0; col_idx < *order; col_idx++)
        {
            GetCofactor(mtx_src, &row_idx, &col_idx, order, &mtx_temp);
            sign = ((row_idx + col_idx) % 2 == 0) ? 1 : -1;
            /*mtx[j][i] = (-1)^(i+j) * det */
            mtx_dst->data[col_idx * mtx_src->col + row_idx] = sign * determinant(&mtx_temp, &order_t);
        }
    }
#ifdef CODE_DEBUG
    printf("mtx src adj matrix is: \n");
    MatrixPrint(mtx_dst);
#endif
}

/**
 * @brief calculate source matrix inverse matrix\
 * @param mtx_src : source matrix
 * @param mtx_dst : inverse matrix result
 * @result int 
 */
int MatrixInverse(matrix *mtx_src, matrix *mtx_dst)
{
#ifdef MATRIX_DEBUG
    if (mtx_src->row != mtx_src->col)
    {
        printf("INPUT MATRIX MUST SQUARE MATRIX !\n");
        return -1;
    }
#endif

    int order;
    int det;
    float det_recip;
    int row_idx, col_idx;
    matrix mtx_tmp;
    float mtx_arr[9] = {0};

    order = 3;
    det = determinant(mtx_src, &order);
    if (0 == det)
    {
        printf("mtx_src det value is: 0 . Input matrix cant be inversed ! \n");
        return -1;
    }

    MatrixInit(&mtx_tmp, &order, &order, mtx_arr);

#ifdef CODE_DEBUG
    printf("mtx_src is: \n");
    MatrixPrint(mtx_src);
    printf("mtx_tmp init is: \n");
    MatrixPrint(&mtx_tmp);
#endif

    MatrixAdjugate(mtx_src, &order, &mtx_tmp);

#ifdef CODE_DEBUG
    printf("mtx_tmp matrix is adj matrix for mtx_src: \n");
    MatrixPrint(&mtx_tmp);
#endif

    det_recip = 1.f / det;

    for (row_idx = 0; row_idx < order; row_idx++)
    {
        for (col_idx = 0; col_idx < order; col_idx++)
        {
            mtx_dst->data[row_idx * mtx_dst->col + col_idx] = det_recip * mtx_tmp.data[row_idx * mtx_tmp.col + col_idx];
        }
    }

#ifdef CODE_DEBUG
    printf("mtx_src inverse matrix is: \n");
    MatrixPrint(mtx_dst);
#endif

    return 0;
}

