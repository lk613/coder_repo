#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include <iostream>
#include <vector>
/**
 * 参考 leetcode_912题 排序数组
 * 注意： 本代码实现方法出现超时，问题在于固定选取数组第一个元素作为pivot
 * 对于测试用例: [110, 100, 0], 有序数组，其时间复杂度为O(n2);
 * 考虑随机选取数组元素灯作为pivot
 */

void swap(int &a, int &b);

int pivot(std::vector<int> &array, int left, int right);

void quickSort(std::vector<int> &array, int start, int end);

void TestQuickSort();

void PrintArray(std::vector<int> &array);

#endif