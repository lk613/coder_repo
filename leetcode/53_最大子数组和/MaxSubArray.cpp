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

void TestLeetcode53()
{
#if 0
    int nums[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::vector<int> array(std::begin(nums), std::end(nums));
#else
    std::vector<int> array = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // std::vector<int> array = {5,4,-1,7,8};
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