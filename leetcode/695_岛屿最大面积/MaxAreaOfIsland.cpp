#include <queue>
#include "MaxAreaOfIsland.h"
#if 1

int bfs(std::vector<std::vector<int>> &grid, int rows, int cols, int row_idx, int col_idx)
{
    int ret = 0;
    std::queue<std::pair<int, int>> coor_queue;

    std::vector<std::pair<int, int>> sur_pos_idxes(4);
    sur_pos_idxes[0] = std::make_pair<int, int>(-1, 0);     // up
    sur_pos_idxes[1] = std::make_pair<int, int>(1, 0);     // down
    sur_pos_idxes[2] = std::make_pair<int, int>(0, -1);     // left
    sur_pos_idxes[3] = std::make_pair<int, int>(0, 1);     // right

    ret += 1;
    grid[row_idx][col_idx] = 0;
    std::pair<int, int> cur_pair(row_idx, col_idx);
    coor_queue.push(cur_pair);

    while (!coor_queue.empty())
    {
        std::pair<int, int> front_pair = coor_queue.front();
        coor_queue.pop();

        for (int i = 0; i < sur_pos_idxes.size(); i++)
        {
            cur_pair = std::make_pair<int, int>(front_pair.first + sur_pos_idxes[i].first, 
                front_pair.second + sur_pos_idxes[i].second);
            
            if (cur_pair.first < 0 || cur_pair.first >= rows || cur_pair.second < 0 || cur_pair.second >= cols 
                || grid[cur_pair.first][cur_pair.second] == 0)
            {
                continue;
            }

            if (grid[cur_pair.first][cur_pair.second] == 1)
            {
                ret += 1;
                grid[cur_pair.first][cur_pair.second] = 0;
                coor_queue.push(cur_pair);
            }
        }
    }

    return ret;
}

// 广度有限搜索遍历 BFS二刷(20250506)
int maxAreaOfIslandByBfs(std::vector<std::vector<int>>& grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    if (grid.empty() || rows <= 0 || cols <= 0)
    {
        return 0;
    }

    int max_area = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                int cur_area = bfs(grid, rows, cols, i, j);
                max_area = (cur_area > max_area) ? cur_area : max_area;
            }
        }
    }

    return max_area;
}


int dfs(std::vector<std::vector<int>> &grid, int rows, int cols, int row_idx, int col_idx)
{
    int ret = 0;
    if (row_idx < 0 || row_idx >= rows || col_idx < 0 || col_idx >= cols || grid[row_idx][col_idx] == 0)
    {
        return 0;
    }

    ret += 1;
    grid[row_idx][col_idx] = 0;

    std::vector<std::pair<int, int>> sur_pos_idxes(4);
    sur_pos_idxes[0] = std::make_pair<int, int>(-1, 0); //up
    sur_pos_idxes[1] = std::make_pair<int, int>(1, 0);  //down
    sur_pos_idxes[2] = std::make_pair<int, int>(0, -1); //left
    sur_pos_idxes[3] = std::make_pair<int, int>(0, 1); //right

    for (int i = 0; i <  sur_pos_idxes.size(); i++)
    {
        ret += dfs(grid, rows, cols, row_idx + sur_pos_idxes[i].first, col_idx + sur_pos_idxes[i].second);
    }

    return ret;
}

// dfs alg
int maxAreaOfIsland(std::vector<std::vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    int max_area = INT_MIN;
    
    if (rows <= 0 || grid.empty())
    {
        return 0;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // if (grid[i][j] != 0)
            {
                int cur_area = dfs(grid, rows, cols, i, j);
                max_area = (cur_area > max_area) ? cur_area : max_area;
            }
        }
    }

    return max_area;
}

#else
int Bfs(std::vector<std::vector<int>> &grid, int row_idx, int col_idx)
{
    int ret = 0;
    int lrud_idx[4] = {0, 0,-1, 1};
    int lrud_jdx[4] = {-1, 1, 0, 0};

    std::queue<int> que_rows;
    std::queue<int> que_cols;

    que_rows.push(row_idx);
    que_cols.push(col_idx);
    grid[row_idx][col_idx] = 0; // 标记为已访问

    while (!que_rows.empty())
    {
        int cur_row = que_rows.front();
        int cur_col = que_cols.front();
        que_rows.pop();
        que_cols.pop();
        ret++;

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
                grid[i_row][i_col] = 0; // 标记为已访问
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
#endif

void TestLeetCode_695()
{
    #if 0
    // [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
    // 第一次提交未通过的测试用例，记得重复入队列的元素，导致重复计数
    std::vector<std::vector<int>> grid = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,0,1,1},
        {0,0,0,1,1}
    };

#else
    std::vector<std::vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
#endif
    // int maxArea = maxAreaOfIsland(grid);
    int maxArea = maxAreaOfIslandByBfs(grid);
    std::cout << "Max area of island: " << maxArea << std::endl;
}
