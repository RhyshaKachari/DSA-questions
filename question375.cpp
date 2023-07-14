// Print Longest Common Subsequence

// Approach 1 : Tabulation
// Time Complexity - O(N*M) + O(N+M)
// Space Complexity - O(N*M)

class Solution
{
public:
    void lcs(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m, 0));
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
                // match condition
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                // not match condition
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int len = dp[n][m];
        int index = len - 1;
        string str = "";
        for (int i = 0; i < len; i++)
        {
            str += "$";
        }

        // iterating in the dp grid
        int i = n;
        int j = m;
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                str[index] = s1[i - 1];
                index--;
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
                j--;
        }
        cout << str << endl;
    }
}