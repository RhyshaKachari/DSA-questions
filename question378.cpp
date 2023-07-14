//Minimum Insertion Steps to Make a String Palindrome - Leetcode 

//Time Complexity -O(N*M) +O(N)
//Space Complexity - O(N*M)

class Solution
{
public:
    int lcs(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }

    int lps(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        int ans = lcs(s, t);
        return ans;
    }

    int minInsertions(string s)
    {
        int n = s.size();
        int p = lps(s);
        return n - p;
    }
};