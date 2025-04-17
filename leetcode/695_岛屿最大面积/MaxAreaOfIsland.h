#ifndef MAX_AREA_OF_ISLAND_H
#define MAX_AREA_OF_ISLAND_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @file MaxAreaOfIsland.c
 * @brief 695. 岛屿的最大面积
 * @author leixiuzheng
 * @date 2025-04-15
 * @version 1.0
 * @details DFS & BFS
 * @copyright Copyright (c) 2025
 */

int dfs(int **grid, int rows, int cols, int row_idx, int col_idx);
int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize);

#endif