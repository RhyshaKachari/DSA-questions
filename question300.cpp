// Longest Common Prefix - Leetcode

// Time Complexity = O(N* mini)
// Auxiliary Space: O(min(|arri|))
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

// Longest Common Prefix in an Array - GFG

// Time Complexity: O(N*min(|arri|))
// Auxiliary Space: O(min(|arri|))

class Solution
{
public:
    string longestCommonPrefix(string arr[], int N)
    {
        int mini = 1000;
        string str;
        for (int i = 0; i < N; i++)
        {
            int len = arr[i].length();
            if (len < mini)
            {
                str = arr[i];
                mini = len;
            }
        }

        int count = 0;
        for (int i = 0; i < mini; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (arr[j][i] != str[i])
                {
                    if (count == 0)
                    {
                        return "-1";
                    }
                    else
                    {
                        return str.substr(0, count);
                    }
                }
            }
            count++;
        }

        return str.substr(0, count);
    }
};