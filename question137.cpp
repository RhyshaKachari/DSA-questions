// Minimal Cost - GFG

// Approach 1 : Memoization
// Time Complexity : O(N*K)
// Space Complexity  : O(N) + O(N)

class Solution
{
private:
    int solve(int ind, vector<int> &height, vector<int> &dp, int k)
    {
        if (ind == 0)
        {
            return 0;
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        int mini = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            if (ind - i >= 0)
            {
                int jump = solve(ind - i, height, dp, k) + abs(height[ind - i] - height[ind]);
                mini = min(mini, jump);
            }
        }
        return dp[ind] = mini;
    }

public:
    int minimizeCost(vector<int> &height, int n, int k)
    {
        vector<int> dp(n, -1);
        return solve(n - 1, height, dp, k);
    }
};

// Approach 2 : Tabulation
// Time Complexity = O(N*K)
// Space Complexity = O(N)

class Solution
{
public:
    int minimizeCost(vector<int> &height, int n, int k)
    {
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int mini = INT_MAX;
            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                {
                    int jump = dp[i - j] + abs(height[i - j] - height[i]);
                    mini = min(mini, jump);
                }
            }
            dp[i] = mini;
        }
        return dp[n - 1];
    }
};