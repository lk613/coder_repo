#include "NumOfIsland.h"

bool hasIsland(vector<vector<int>> &grid, int rows, int cols, int row_idx, int col_idx)
{
    if (row_idx < 0 || row_idx >= rows || col_idx < 0 || col_idx >= cols || grid[row_idx][col_idx] == 0)
    {
        return false;
    }

    std::vector<std::pair<int, int>> tblr_array = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    std::queue<std::pair<int, int>> pos_queue;
    pos_queue.push(std::pair<int, int>(row_idx, col_idx));
    grid[row_idx][col_idx] = 0;

    while (!pos_queue.empty())
    {
        std::pair<int, int> cur_pos = pos_queue.front();
        pos_queue.pop();
        // grid[cur_pos.first][cur_pos.second] = 0;

        for (int i = 0; i < tblr_array.size(); i++)
        {
            std::pair<int, int> sur_pos = std::make_pair(cur_pos.first + tblr_array[i].first, cur_pos.second + tblr_array[i].second);

            int sur_pos_row = sur_pos.first;
            int sur_pos_col = sur_pos.second;

            if (sur_pos_row < 0 || sur_pos_row >= rows || sur_pos_col < 0 || sur_pos_col >= cols)
            {
                continue;
            }

            if (grid[sur_pos_row][sur_pos_col] == 1)
            {
                pos_queue.push(sur_pos);
                grid[sur_pos_row][sur_pos_col] = 0;
            }
        }
    }

    return true;
}


int numIslands(vector<vector<int>> &grid)
{
    if ((grid.size() == 0) || (grid[0].size() == 0))
    {
        return 0;
    }

    int island_num = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (hasIsland(grid, grid.size(), grid[0].size(), i, j))
            {
                island_num += 1;
            }
        }
    }

    return island_num;
}

void TestLeetcode200()
{
#if 1
    std::vector<std::vector<int>> grid_mtx = 
    {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1}
    };
#else
    std::vector<std::vector<int>> grid_mtx = 
    {
        {1,1,1,1,0},
        {1,1,0,1,0},
        {1,1,0,0,0},
        {0,0,0,0,0}
    };
#endif

    std::cout << "grid is: " << std::endl;
    for (int i = 0; i < grid_mtx.size(); i++)
    {
        for (int j = 0; j < grid_mtx[0].size(); j++)
        {
            std::cout << grid_mtx[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int islands = numIslands(grid_mtx);

    std::cout << "岛屿数量为:  " << islands << std::endl;

}