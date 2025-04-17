#include "MaxAreaOfIsland.h"

/**
 * @brief 深度优先搜索
 * 
 * @param grid 
 * @param rows 
 * @param cols 
 * @param row_idx 
 * @param col_idx 
 * @return int 
 */
int dfs(int **grid, int rows, int cols, int row_idx, int col_idx)
{
    int ret = 0;
    int lrud_idx[4] = {0, 0,-1, 1};
    int lrud_jdx[4] = {-1, 1, 0, 0};

    if (row_idx < 0 || row_idx >= rows || col_idx < 0 || col_idx >= cols || grid[row_idx][col_idx] == 0)
    {
        return 0;
    }

    if (grid[row_idx][col_idx] == 1)
    {
        grid[row_idx][col_idx] = 0; // 标记为已访问
        ret += 1;

        for (int i = 0; i < 4; i++)
        {
            ret += dfs(grid, rows, cols, row_idx + lrud_idx[i], col_idx + lrud_jdx[i]);
        }
    }

    return ret;
}

/**
 * @brief 计算岛屿的最大面积
 * 
 * @param grid 
 * @param gridSize 
 * @param gridColSize 
 * @return int 
 */
int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize)
{
    int i;
    int j;

    int maxArea = 0;
    int area = 0;
    for (i = 0; i < gridSize; i++)
    {
        for (j = 0; j < *gridColSize; j++)
        {
            if (grid[i][j] == 1)
            {
                area = dfs(grid, gridSize, *gridColSize, i, j);
                maxArea = area > maxArea ? area : maxArea;
            }
        }
    }

    return maxArea;
}
