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

// Time Complexity : O(N log N) + O(N)
// Space Complexity :O(1)

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        int a = strs.size();
        string n = strs[0], m = strs[a - 1], ans = "";
        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] == m[i])
            {
                ans += n[i];
            }
            else
                break;
        }
        return ans;
    }
};

// Longest Common Prefix in an Array - GFG

// Approach 1 : Vertical Updates
//  Time Complexity: O(N*min(|arri|))
//  Auxiliary Space: O(min(|arri|))

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

// Approach 2 : Horizontal Updates
// Time Complexity : O(N log N) + O(N)
// Space Complexity :O(1)

class Solution
{
public:
    string longestCommonPrefix(string arr[], int N)
    {
        sort(arr, arr + N);
        int count = 0;
        string str1 = arr[0];
        string str2 = arr[N - 1];
        for (int i = 0; i < str1.size(); i++)
        {
            if (str1[i] != str2[i])
            {
                if (count == 0)
                {
                    return "-1";
                }
                return str1.substr(0, count);
            }
            else
            {
                count++;
            }
        }
        return str1.substr(0, count);
    }
};