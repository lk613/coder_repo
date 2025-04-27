#include "MaxSubArray.h"

#ifdef BRUTE_FORCE
// 暴力解法
int maxSubArray(std::vector<int> &nums)
{
    if (nums.size() <= 0)
    {
        return 0;
    }

    int max_sum = INT_MIN;
    int length = nums.size();

    for (int i = 0; i < length; i++)
    {
        int cur_sum = 0;
        for (int j = i; j < length; j++)
        {
            cur_sum = cur_sum + nums[j];
            max_sum = (cur_sum > max_sum) ? cur_sum : max_sum;
        }
    }

    return max_sum;
}
#endif

#if 0
// Dynamic Programming
int maxSubArray(std::vector<int> &nums)
{
    if (nums.size() <= 0)
    {
        return 0;
    }

    int max_sum = INT_MIN;
    int length = nums.size();
    std::vector<int> dp_vec(nums.size(), 0);
    dp_vec[0] = nums[0];
    max_sum = dp_vec[0];

    for (int i = 1; i < length; i++)
    {
        dp_vec[i] = (nums[i] > (dp_vec[i - 1] + nums[i])) ? nums[i] : (dp_vec[i - 1] + nums[i]);
        max_sum = (max_sum > dp_vec[i]) ? max_sum : dp_vec[i];
    }

    return max_sum;
}
#endif

static int getCrossMax(std::vector<int> &nums, int left, int right)
{
    int mid = left + (right - left) / 2;

    int left_sum = 0;
    int left_max = INT_MIN;

    for (int i = mid; i >= left; i--)
    {
        left_sum += nums[i];
        left_max = (left_sum > left_max) ? left_sum : left_max;
    }

    int right_sum = 0;
    int right_max = INT_MIN;

    for (int i = mid + 1; i <= right; i++)
    {
        right_sum += nums[i];
        right_max = (right_sum > right_max) ? right_sum : right_max;
    }

    int max_sum = left_max + right_max;
    return max_sum;
}

static int getMax(std::vector<int> &nums, int left, int right)
{
    if (left == right)
    {
        return nums[left];
    }

    int mid = left + (right - left) / 2;
    
    int left_max = getMax(nums, left, mid);
    int right_max = getMax(nums, mid + 1, right);
    int cross_max = getCrossMax(nums, left, right);

    int max_sum = (left_max > right_max) ? left_max : right_max;
    max_sum = (max_sum > cross_max) ? max_sum : cross_max;

    return max_sum;
}

// Divide and Conquer
int maxSubArray(std::vector<int> &nums)
{
    if (nums.size() <= 0)
    {
        return 0;
    }

    int max_sum = getMax(nums, 0, nums.size() - 1);
    return max_sum;
}


void TestLeetcode53()
{
#if 0
    int nums[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::vector<int> array(std::begin(nums), std::end(nums));
#else
    // std::vector<int> array = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    std::vector<int> array = {5,4,-1,7,8};
#endif

    std::cout << "输入数组为: " << std::endl;
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    int max_sum = maxSubArray(array);
    std::cout << "当前数组最大子数组和为: " << max_sum << std::endl;

}