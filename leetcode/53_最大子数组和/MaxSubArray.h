#ifndef MAX_SUB_ARRAY_H
#define MAX_SUB_ARRAY_H
#include <vector>
#include <iostream>
#include <climits>

#ifdef BRUTE_FORCE
#define BRUTE_FORCE
#endif

int maxSubArray(std::vector<int> &nums);

void TestLeetcode53();

#endif