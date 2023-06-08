// Longest Common Prefix - Leetcode

// Time Complexity = O(N* mini)
// Space Complexity = O(1)

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        int mini = 1000;
        int count = 0;
        string str;
        for (int i = 0; i < strs.size(); i++)
        {
            int len = strs[i].size();
            if (len < mini)
            {
                str = strs[i];
                mini = len;
            }
        }

        for (int i = 0; i < mini; i++)
        {
            for (int j = 0; j < strs.size(); j++)
            {
                if (strs[j][i] != str[i])
                {
                    return str.substr(0, count);
                }
            }
            count++;
        }
        return str.substr(0, count);
    }
};