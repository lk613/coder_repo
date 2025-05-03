#include "MajorityElement.h"

int majorityElement(vector<int>& nums) 
{
    int ret = -1;
    int length = nums.size();
    int hash_size = 0;
    
    std::vector<std::pair<int, int>> hash_table(length);

    for (int i = 0; i < nums.size(); i++)
    {
        int cur_elem = nums[i];
        bool new_data = true;

        for (int j = 0; j < hash_size; j++)
        {
            if (cur_elem == hash_table[j].first)
            {
                new_data = false;
                hash_table[j].second++;
            }           
        }

        if (new_data)
        {
            hash_table[hash_size].first = cur_elem;
            hash_table[hash_size].second = 1;
            hash_size++;
        }
    }

    for (int i = 0; i < hash_size; i++)
    {
        std::pair<int, int> cur_pair = hash_table[i];
        if (cur_pair.second > length / 2)
        {
            ret = cur_pair.first;
            break;
        }
    }

    return ret;
}

void TestLeetcode169()
{
    // std::vector<int> nums = {3,2,3};

    // std::vector<int> nums2 = {2,2,1,1,1,2,2};

    std::vector<int> nums = {8,8,7,7,7};

    std::cout << "数组为： " << std::endl;

    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    int ret = majorityElement(nums);

    std::cout << "数组的多数元素为:  " << ret << std::endl;
}
