#include "RemoveDuplicates.h"

#if 1
// two pointer method
int removeDuplicates(std::vector<int>& nums) {
    int length = nums.size();
    if (length <= 0)
    {
        return 0;
    }

    int fast = 1;
    int slow = 1;

    while (fast < length)
    {
        if (nums[fast] != nums[fast - 1])
        {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }

    return slow;
}
#else
// sort array
int removeDuplicates(vector<int>& nums) {
    int ret = 0;
    std::vector<int> vec(nums.size());
    vec[0] = nums[0];
    int valid_num = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            vec[valid_num++] = nums[i];
        }
    }

    for (int i = 0; i < valid_num; i++)
    {
        nums[i] = vec[i];
    }

    return valid_num;
}


// unorder array
int removeDuplicates(std::vector<int>& nums) {
    std::vector<int> data_stats;
    int uniqure_num = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int cur_num = nums[i];
        bool new_data = true;
        for (int j = 0; j < uniqure_num; j++)
        {
            if (cur_num == data_stats[j])
            {
                new_data = false;
            }
        }

        if (new_data)
        {
            data_stats.push_back(cur_num);
            uniqure_num++;
        }
    }

    for (int i = 0; i < uniqure_num; i++)
    {
        nums[i] = data_stats[i];
    }

    return uniqure_num;
}
#endif