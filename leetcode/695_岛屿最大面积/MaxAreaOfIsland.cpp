#include <queue>
#include "MaxAreaOfIsland.h"

int Bfs(std::vector<std::vector<int>> &grid, int row_idx, int col_idx)
{
    int ret = 0;
    int lrud_idx[4] = {0, 0,-1, 1};
    int lrud_jdx[4] = {-1, 1, 0, 0};

    std::queue<int> que_rows;
    std::queue<int> que_cols;

    que_rows.push(row_idx);
    que_cols.push(col_idx);

    while (!que_rows.empty())
    {
        ret += 1;
        int cur_row = que_rows.front();
        int cur_col = que_cols.front();
        que_rows.pop();
        que_cols.pop();
        grid[cur_row][cur_col] = 0; // 标记为已访问

        for (int i = 0; i < 4; i++)
        {
            int i_row = cur_row + lrud_idx[i];
            int i_col = cur_col + lrud_jdx[i];
            
            if (i_row < 0 || i_row >= grid.size() || i_col < 0 || i_col >= grid[0].size())
            {
                continue;
            }

            if (grid[i_row][i_col] == 1)
            {
                que_rows.push(i_row);
                que_cols.push(i_col);
            }
        }
    }
    
    return ret;
}

/**
 * @brief complish by BFS
 * 
 * @param grid 
 * @param gridSize 
 * @param gridColSize 
 * @return int 
 */
int maxAreaOfIslandByBfs(std::vector<std::vector<int>>& grid)
{
    int maxArea = 0;
    
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                int area = Bfs(grid, i, j);
                maxArea = (area > maxArea) ? area : maxArea;
            }
        }
    }

    return maxArea;
}
