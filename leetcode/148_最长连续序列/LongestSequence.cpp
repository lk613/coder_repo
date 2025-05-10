#include "LongestSequence.h"

int longestConsecutive(std::vector<int> &nums)
{
    if (nums.size() < 1)
    {
        return 0;
    }
    int cur_seq_num = 0;
    int max_seq_num = INT_MIN;
    std::unordered_map<int, int> hash_table;
    for (int i = 0; i < nums.size(); i++)
    {
        int cur_elem = nums[i];
        auto it = hash_table.find(cur_elem);
        if (it == hash_table.end())
        {
            hash_table[cur_elem] = i;
        }
    }

    // 遍历哈希表
    for (auto it = hash_table.begin(); it != hash_table.end(); it++)
    {
        cur_seq_num = 0;
        int cur_data = it->first;
        int pre_data = cur_data - 1;
        auto pre_it = hash_table.find(pre_data);
        // 数组中没有当前元素的减一值
        if (pre_it == hash_table.end())
        {
            bool has_cur_elem = true;
            while (has_cur_elem)
            {
                cur_seq_num += 1;
                max_seq_num = (cur_seq_num > max_seq_num) ? cur_seq_num : max_seq_num;
                cur_data = cur_data + 1;
                auto cur_it = hash_table.find(cur_data);
                has_cur_elem = (cur_it != hash_table.end()) ? true : false;
            }
        }
    }

    return max_seq_num;
}