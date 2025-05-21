#include "FindAnagrams.h"

vector<int> findAnagrams(string s, string p)
{
    std::vector<int> s_count(26);
    std::vector<int> p_count(26);

    std::vector<int> result;

    if (s.length() < p.length())
    {
        return {};
    }

    for (char p_char : p)
    {
        p_count[p_char - 'a'] += 1;
    }

    int left_win = 0;
    for (int right_win = 0; right_win < s.length(); right_win++)
    {
        s_count[s[right_win] - 'a'] += 1;

        if ((right_win - left_win + 1) == p.length())
        {
            if (s_count == p_count)
            {
                result.push_back(left_win);
            }

            s_count[s[left_win] - 'a'] -= 1;
            left_win++;
        }
    }

    return result;
}