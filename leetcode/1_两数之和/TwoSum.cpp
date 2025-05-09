#include "TwoSum.h"
#include <unordered_map>

#if 1
// 哈希表
vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> hash_table;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = hash_table.find(target - nums[i]);
        if (it != hash_table.end())
        {
            return {i, it->second};
        }
        hash_table[nums[i]] = i;
    }

    return {};
}

#else
vector<int> twoSum(vector<int>& nums, int target) {
    std::vector<int> ret = {-1, -1};
    int length = nums.size();
    if (length < 2)
    {
        return ret;
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (nums[j] == (target - nums[i]))
            {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return ret;
}
#endif