#include "GroupAnagrams.h"
#include <algorithm>
#include <unordered_map>

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    std::unordered_map<std::string, std::vector<std::string>> hash_table;
    int length = strs.size();

    for (int i = 0; i < length; i++)
    {
        string cur_str = strs[i];
        std::sort(cur_str.begin(), cur_str.end());

        auto it = hash_table.find(cur_str);
        if (it != hash_table.end())
        {
            hash_table[cur_str].push_back(strs[i]);
        }else
        {
            hash_table[cur_str] = {strs[i]};
        }
    }
    
    std::vector<std::vector<std::string>> ret;
    for (auto it = hash_table.begin(); it != hash_table.end(); it++)
    {
        ret.push_back(it->second);
    }

    return ret;
}