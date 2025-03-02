#include "binary_search.h"


/**
 * @brief  请实现无重复数字的升序数组的二分查找
        给定一个 元素升序的、无重复数字的整型数组 nums 和一个目标值 target ，
        写一个函数搜索 nums 中的 target，
        如果目标值存在返回下标（下标从 0 开始），否则返回 -1。
    数据范围：0≤len(nums)≤2×1050≤len(nums)≤2×105 ， 数组中任意值满足 ∣val∣≤109∣val∣≤109
    进阶：时间复杂度 O(log⁡n) ，空间复杂度 O(1)
 *  % PASS %
 * @param nums 
 * @param numsLen 
 * @param target 
 * @return int 
 */
int SearchTarget(int* nums, int numsLen, int target )
{
    if (nums== NULL || numsLen < 1)
    {
        return -1;
    }
    int left = 0;
    int right = numsLen - 1;
    int mid = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] > target)
        {
            right = mid - 1;
        }else if (nums[mid] < target)
        {
            left = mid + 1;
        }else
        {
            return mid;
        }
    }

    return -1;
}