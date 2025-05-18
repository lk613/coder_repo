#include "LongestSubstring.h"

int lengthOfLongestSubstring(std::string s)
{
    std::unordered_set<char> hash_table;
    int max_size = 0;
    int length = s.length();

    // slide window
    int left_win = 0;
    for (int right_win = 0; right_win < length; right_win++)
    {
        char cur_str = s[right_win];
        while ((left_win < right_win) && (hash_table.count(cur_str)))
        {
            hash_table.erase(s[left_win++]);
        }

        hash_table.insert(s[right_win]);
        max_size = (hash_table.size() > max_size) ? hash_table.size() : max_size;
    }

    return max_size;
}