#include "inverse_pairs.h"

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P mod 1000000007

数据范围：  对于 50% 的数据, size≤104
对于 100% 的数据, size≤105
数组中所有数字的值满足 0≤val≤1090/*
1230要求：空间复杂度 O(n)，时间复杂度 O(nlogn)
 * 
 * @param nums int整型一维数组 
 * @param numsLen int nums数组长度
 * @return int整型
 */
#if 1
// 归并排序
#define MOD 1000000007
int Merge(int *nums, int left, int mid, int right, int *temp)
{
    int l_idx = left;
    int r_idx = mid + 1;
    int k_idx = 0;

    int count = 0;
    while ((l_idx <= mid) && (r_idx <= right))
    {
        if (nums[l_idx] <= nums[r_idx])
        {
            temp[k_idx++] = nums[l_idx++];
        }else
        {
            temp[k_idx++] = nums[r_idx++];
            count += (mid - l_idx + 1);
            count %= MOD;
        }
    }

    while (l_idx <= mid)
    {
        temp[k_idx++] = nums[l_idx++];
    }
    while (r_idx <= right)
    {
        temp[k_idx++] = nums[r_idx++];
    }

    for (int i = 0; i < k_idx; i++)
    {
        nums[left + i] = temp[i];
    }

    return count;
}

int MergeSort(int *nums, int left, int right, int *temp)
{
    if (left >= right)
    {
        return 0;
    }

    int mid = (left + right) / 2;

    int count = 0;

    count = (count + MergeSort(nums, left, mid, temp)) % MOD;
    count = (count + MergeSort(nums, mid + 1, right, temp)) % MOD;

    count = (count + Merge(nums, left, mid, right, temp)) % MOD;

    return count;
}

int InversePairs(int* nums, int numsLen )
{
    if (nums == NULL || numsLen < 1)
    {
        return 0;
    }

    int *temp = (int *)malloc(numsLen * sizeof(int));
    if (temp == NULL)
    {
        return 0;
    }

    int count = MergeSort(nums, 0, numsLen - 1, temp);
    free(temp);

    return count;
}

#else
 // 暴力算法
int InversePairs(int* nums, int numsLen ) 
{
    // write code here
    int ret_cnt = 0;
    if (nums == NULL || numsLen < 1)
    {
        return ret_cnt;
    }

    for (int i = 0; i < numsLen - 1; i++)
    {
        for (int j = i + 1; j < numsLen; j++)
        {
            if (nums[i] > nums[j])
            {
                ret_cnt++;
            }
        }
    }
    
    return ret_cnt % 1000000007;
}
#endif