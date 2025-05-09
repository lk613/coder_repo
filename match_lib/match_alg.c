#include "match_alg.h"

// 掩码矩阵： 记录匹配状态
static char mask_matrix[COST_SQUARE_MATRIX_NUM][COST_SQUARE_MATRIX_NUM];
// 行掩码和列掩码： 记录覆盖状态
static bool row_mask[COST_SQUARE_MATRIX_NUM];
static bool col_mask[COST_SQUARE_MATRIX_NUM];
// 记录当前找到的零元素的行号和列号，用于增广路径的构造
static size_t saverow, savecol;


// 初始化函数
static int Initialize(int rows, int cols, float src_mtx[TRACK_MAX_NUM][TRACK_MAX_NUM], 
        float cost_matrix[TRACK_MAX_NUM][TRACK_MAX_NUM]);

/** 辅助函数 */
// 最小化当前行或列元素
static void MinimizeMatrixByAxis(int rows, int cols, float cost_mtx[COST_SQUARE_MATRIX_NUM][COST_SQUARE_MATRIX_NUM],
    const bool by_col_axis);
// 矩阵中寻找未被覆盖的零。帮助找到潜在匹配点
static bool FindUncoverZeroInMatrix(int rows, int cols, float matrix[COST_SQUARE_MATRIX_NUM][COST_SQUARE_MATRIX_NUM],
    const float elem, size_t *row_p, size_t *col_p); 

static int step1(int rows, int cols, float matrix[COST_SQUARE_MATRIX_NUM][COST_SQUARE_MATRIX_NUM]);
static int step2(int rows, int cols, float matrix[COST_SQUARE_MATRIX_NUM][COST_SQUARE_MATRIX_NUM]);
static int step3(int rows, int cols, float matrix[COST_SQUARE_MATRIX_NUM][COST_SQUARE_MATRIX_NUM]);
static int step4(int rows, int cols, float matrix[COST_SQUARE_MATRIX_NUM][COST_SQUARE_MATRIX_NUM]);
static int step5(int rows, int cols, float matrix[COST_SQUARE_MATRIX_NUM][COST_SQUARE_MATRIX_NUM]);


static int Initialize(int rows, int cols, float src_mtx[TRACK_MAX_NUM][TRACK_MAX_NUM], 
        float cost_matrix[TRACK_MAX_NUM][TRACK_MAX_NUM])
{
    int sqr_mtx_size = (rows > cols) ? rows : cols;

    int max_cost = INT_MIN;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int cur_cost = src_mtx[i][j];
            max_cost = (cur_cost > max_cost) ? cur_cost : max_cost;
        }
    }

    for (int i = 0; i < TRACK_MAX_NUM; i++)
    {
        for (int j = 0; j < TRACK_MAX_NUM; j++)
        {
            cost_matrix[i][j] = max_cost;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cost_matrix[i][j] = src_mtx[i][j];
        }
    }

    memset(mask_matrix, 0, COST_SQUARE_MATRIX_NUM * COST_SQUARE_MATRIX_NUM * sizeof(char));
    memset(row_mask, 0, COST_SQUARE_MATRIX_NUM * sizeof(bool));
    memset(col_mask, 0, COST_SQUARE_MATRIX_NUM * sizeof(bool));
    saverow = savecol = 0;

    return sqr_mtx_size;
}

static void MinimizeMatrixByAxis(int rows, int cols, float cost_mtx[COST_SQUARE_MATRIX_NUM][COST_SQUARE_MATRIX_NUM],
    const bool by_col_axis)
{
    const size_t out_loop_size = (true == by_col_axis) ? cols : rows;
    const size_t inner_loop_size = (true == by_col_axis) ? rows : cols;

    for (int i = 0; i < out_loop_size; i++)
    {
        float min_axis = (by_col_axis) ? cost_mtx[0][i] : cost_mtx[i][0];

        for (int j = 1; j < inner_loop_size; j++)
        {
            if (min_axis > 0)
            {
                min_axis = MIN(min_axis, (by_col_axis == true) ? (cost_mtx[j][i]) : (cost_mtx[i][j]));
            }
        }

        if (min_axis > 0)
        {
            for (size_t j = 0; j < inner_loop_size; j++)
            {
                if (true == by_col_axis)
                {
                    cost_mtx[j][i] -= min_axis;
                }else
                {
                    cost_mtx[i][j] -= min_axis;
                }
            }
        }
    }
}


static bool FindUncoverZeroInMatrix(int rows, int cols, float matrix[COST_SQUARE_MATRIX_NUM][COST_SQUARE_MATRIX_NUM],
    const float elem, size_t *row_p, size_t *col_p)
{
    for (size_t row = 0; row < rows; row++)
    {
        // 当前行未被覆盖
        if (!row_mask[row])
        {
            for (size_t col = 0; col < cols; col++)
            {
                // 当前列未被覆盖
                if (!col_mask[col])
                {
                    // 未被覆盖的零元素
                    if (matrix[row][col] == elem)
                    {
                        row_p = &row;
                        col_p = &col;
                        return true;        // 存在未被覆盖的0
                    }
                }
            }
        }
    }

    return false;   // 不存在未被覆盖的0
}


// 初始化匹配状态。在每一行找到第一个零，并将其标记为MATURE_ZERO, 为后续匹配提供基础
static int step1(int rows, int cols, float matrix[COST_SQUARE_MATRIX_NUM][COST_SQUARE_MATRIX_NUM])
{
    for (size_t row = 0; row < rows; row++)
    {
        for (size_t col = 0; col < cols; col++)
        {
            if (0 == matrix[row][col])
            {
                for (size_t n_row = 0; n_row < row; n_row++)
                {
                    if (mask_matrix[n_row][col] == MATURE_ZERO)
                    {
                        goto next_column;
                    }

                    mask_matrix[row][col] = MATURE_ZERO;
                    goto next_row;
                }
            }
            next_column:;
        }
        next_row:;
    }

    return 2;
}

/**
 * 检查当前的匹配状态是否已经完成， 为后续提供覆盖状态信息。
 * 通过检测掩码矩阵中MATURE_ZERO零的分布，判断是否所有列都被覆盖。
 * 如果所有列都被覆盖，则匹配完成；否则进入step3；
 */
static int step2(int rows, int cols, float matrix[COST_SQUARE_MATRIX_NUM][COST_SQUARE_MATRIX_NUM])
{
    size_t match_cnt = 0;
    
    for (size_t row = 0; row < rows; row++)
    {
        for (size_t col = 0; col < cols; col++)
        {
            if (MATURE_ZERO == mask_matrix[row][col])
            {
                col_mask[col] = true;
                match_cnt++;
            }
        }
    }

    if (match_cnt > MIN(rows, cols))
    {
        return 0;
    }

    return 3;
}

// 
static int step3(int rows, int cols, float matrix[COST_SQUARE_MATRIX_NUM][COST_SQUARE_MATRIX_NUM])
{
    
    if (FindUncoverZeroInMatrix(rows, cols, matrix, 0, &saverow, &savecol))
    {
        mask_matrix[saverow][savecol] = UNMATCH_ZERO;   //如果存在未覆盖0，标记UNMATURE_ZERO
    }else
    {
        return 5;       // 跳到step5，调整矩阵状态以制造新的0
    }

    // 检查未成熟0所在行是否有成熟0
    for (size_t col = 0; col < cols; col++)
    {
        if (mask_matrix[saverow][col] == MATURE_ZERO)
        {
            row_mask[saverow] = true;       // 覆盖质数零所在的行
            col_mask[col] = false;          // 取消覆盖星号零所在的列
            return 3;
        }
    }

    // 质数0所在行没有星号0，跳到step4 构造增广路径
    /**
     *质数零所在行没有星号零的含义
            1.当前行未被匹配
            (1) 如果质数零所在行没有星号零，说明该行尚未与任何列匹配。
            (2) 这意味着可以通过增广路径将该质数零直接转化为星号零，从而增加匹配的数量。
            
            2.增广路径的起点
            (1) 质数零所在行没有星号零时，当前的质数零是一个未匹配点。
            (2) 这种情况是构造增广路径的起点，增广路径会从这个质数零开始，交替经过星号零和质数零，最终调整匹配状态。

            3.匹配可以扩展
            (1) 匹配的数量可以通过将该质数零转化为星号零来增加。
            (2) 这是匈牙利算法逐步逼近最优匹配的关键步骤。
     * 
     */
    return 4;       
}


// step4是匈牙利匹配算法的核心步骤，该函数主要用于构造增广路径并调整匹配状态
/**
 * 增广路径的构造规则
    1. 起点：增广路径从一个未匹配的质数零（PRIME）开始。
    2. 交替查找：
        (1)从当前质数零，查找同列的星号零。
        (2)从当前星号零，查找同行的质数零。
    3. 路径终止：如果无法找到新的星号零或质数零，增广路径构造终止。
*/
static int step4(int rows, int cols, float matrix[COST_SQUARE_MATRIX_NUM][COST_SQUARE_MATRIX_NUM])
{
    bool augment_path[COST_SQUARE_MATRIX_NUM][COST_SQUARE_MATRIX_NUM] = {false};
    augment_path[saverow][savecol] = true;  // 当前行没有星号零的质数零作为增广路径的起点加入增广路径序列中
    size_t row;
    size_t col = savecol;       //从质数零所在的列开始， 即未匹配边

    bool find_zero;

    do
    {
        find_zero = false;
        // 查找同列的星号零元素，即匹配边
        for (size_t row = 0; row < rows; row++)
        {
            if (mask_matrix[row][col] == MATURE_ZERO)
            {
                if (!augment_path[row][col])
                {
                    find_zero = true;
                    augment_path[row][col] = true;
                    break;
                }
            }
        }

        // 如果没有找到星号零，终止路径构造
        if (!find_zero)
        {
            break;
        }

        find_zero = false;
        // 查找同行的质数零，即未匹配边
        for (size_t col = 0; col < cols; col++)
        {
            if (mask_matrix[row][col] == UNMATCH_ZERO)
            {
                if (!augment_path[row][col])
                {
                    find_zero = true;
                    augment_path[row][col] = true;
                    break;
                }
            }
        }

    } while (find_zero);    //如果无法找到新的星号零或质数零,退出循环

    // 翻转增广路径状态，匹配数目+1
    for (int i = 0; i < COST_SQUARE_MATRIX_NUM; i++)
    {
        for (int j = 0; j < COST_SQUARE_MATRIX_NUM; j++)
        {
            if (!augment_path[i][j])
            {
                continue;
            }

            // 如果零在增广路径中
            if (mask_matrix[i][j] == MATURE_ZERO)
            {
                mask_matrix[i][j] = NORMAL;
            }

            if (mask_matrix[i][j] == UNMATCH_ZERO)
            {
                mask_matrix[i][j] = MATURE_ZERO;
            }
        }
    }

    // 清除所有质数零
    
}

static int step5(int rows, int cols, float matrix[COST_SQUARE_MATRIX_NUM][COST_SQUARE_MATRIX_NUM])
{

}


void HungarianMatch(int rows, int cols, float cost_matrix[TRACK_MAX_NUM][OBJECT_MAX_NUM], 
    float match_matrix[TRACK_MAX_NUM][OBJECT_MAX_NUM])
{
    float cost_mtx_t[MAX(TRACK_MAX_NUM, OBJECT_MAX_NUM)][MAX(TRACK_MAX_NUM, OBJECT_MAX_NUM)];
    int size = Initialize(rows, cols, cost_matrix, cost_mtx_t);

    MinimizeMatrixByAxis(size, size, cost_mtx_t, cols <= rows);
    MinimizeMatrixByAxis(size, size, cost_mtx_t, rows < cols);

    int step = 1;

    while (step)
    {
        switch (step)
        {
            case 1:
                step = step1(size, size, cost_mtx_t);
                break;
            case 2:
                step = step2(size, size, cost_mtx_t);
                break;
            case 3:
                step = step3(size, size, cost_mtx_t);
                break;
            case 4:
                step = step4(size, size, cost_mtx_t);
                break;
            case 5:
                step = step5(size, size, cost_mtx_t);
                break;
            default:
                break;
        }
    }


}

void TestHungarianAlgorithm();