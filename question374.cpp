// Longest Common Subsequence - Leetcode

// Approach 1 : Recursion
// Time Complexity  : O(2^n) + O(2^m)
// Space Complexity : O(n) + O(m) recursive stack space

class Solution
{
public:
    int f(int ind1, int ind2, string text1, string text2)
    {
        if (ind1 < 0 || ind2 < 0)
        {
            return 0;
        }

        // match condition
        if (text1[ind1] == text2[ind2])
        {
            return 1 + f(ind1 - 1, ind2 - 1, text1, text2);
        }

        // not match condition
        else
        {
            return max(f(ind1 - 1, ind2, text1, text2), f(ind1, ind2 - 1, text1, text2));
        }
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int len1 = text1.length();
        int len2 = text2.length();
        return f(len1 - 1, len2 - 1, text1, text2);
    }
};

// Approach 2 : Memoisation
// Time Complexity - O(N*M)
// Space Complexity - O(N*M) + O(N)

class Solution
{
public:
    int f(int ind1, int ind2, string text1, string text2, vector<vector<int>> &dp)
    {
        if (ind1 < 0 || ind2 < 0)
        {
            return 0;
        }
        if (dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2];
        }
        // match condition
        if (text1[ind1] == text2[ind2])
        {
            return dp[ind1][ind2] = 1 + f(ind1 - 1, ind2 - 1, text1, text2, dp);
        }

        // not match condition
        else
        {
            return dp[ind1][ind2] = max(f(ind1 - 1, ind2, text1, text2, dp), f(ind1, ind2 - 1, text1, text2, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<vector<int>> dp(len1, vector<int>(len2, -1));
        return f(len1 - 1, len2 - 1, text1, text2, dp);
    }
};

// Approach 3 : Memoisation after shifting the index which will help us in further tabulation
// Time Complexity - O(N*M)
// Space Complexity - O(N*M) + O(N+M)

class Solution
{
public:
    int f(int ind1, int ind2, string text1, string text2, vector<vector<int>> &dp)
    {
        if (ind1 == 0 || ind2 == 0)
        {
            return 0;
        }
        if (dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2];
        }
        // match condition
        if (text1[ind1 - 1] == text2[ind2 - 1])
        {
            return dp[ind1][ind2] = 1 + f(ind1 - 1, ind2 - 1, text1, text2, dp);
        }

        // not match condition
        else
        {
            return dp[ind1][ind2] = max(f(ind1 - 1, ind2, text1, text2, dp), f(ind1, ind2 - 1, text1, text2, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1));
        return f(len1, len2, text1, text2, dp);
    }
};

// Approach 4 : Tabulation
// Time Complexity - O(N*M)
// Space Complexity - O(N*M) 


class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 0; i <= len1; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= len2; j++)
        {
            dp[0][j] = 0;
        }
        for (int ind1 = 1; ind1 <= len1; ind1++)
        {
            for (int ind2 = 1; ind2 <= len2; ind2++)
            {
                // match condition
                if (text1[ind1 - 1] == text2[ind2 - 1])
                {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                }

                // not match condition
                else
                {
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                }
            }
        }
        return dp[len1][len2];
    }
};