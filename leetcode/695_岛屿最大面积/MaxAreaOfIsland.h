#ifndef MAX_AREA_OF_ISLAND_H
#define MAX_AREA_OF_ISLAND_H
#include <iostream>
#include <vector>
#include <climits>

int maxAreaOfIsland(std::vector<std::vector<int>>& grid);

int maxAreaOfIslandByBfs(std::vector<std::vector<int>>& grid);

// int maxAreaOfIslandByDfs(std::vector<std::vector<int>>& grid);

void TestLeetCode_695();

#endif