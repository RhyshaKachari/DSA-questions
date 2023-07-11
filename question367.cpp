// 0 - 1 Knapsack Problem - GFG

// Approach 1 : Recursion
// Time Complexity - O(2^n)
// Space Complexity - O(n)

class Solution
{
public:
    int f(int ind, int W, int wt[], int val[])
    {
        if (W == 0)
        {
            return 0;
        }
        if (ind == 0)
        {
            if (wt[ind] <= W)
            {
                return val[ind];
            }
            else
                return 0;
        }

        int notTake = 0 + f(ind - 1, W, wt, val);
        int take = INT_MIN;
        if (wt[ind] <= W)
        {
            take = val[ind] + f(ind - 1, W - wt[ind], wt, val);
        }
        return max(take, notTake);
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        return f(n - 1, W, wt, val);
    }
};

// Appraoch 2 : Memoization
// Time Complexity - O(N*W)
// Space Complexity - O(N*W)

class Solution
{
public:
    int f(int ind, int W, int wt[], int val[], vector<vector<int>> &dp)
    {
        if (W == 0)
        {
            return 0;
        }
        if (ind == 0)
        {
            if (wt[ind] <= W)
            {
                return val[ind];
            }
            else
                return 0;
        }
        if (dp[ind][W] != -1)
        {
            return dp[ind][W];
        }
        int notTake = 0 + f(ind - 1, W, wt, val, dp);
        int take = INT_MIN;
        if (wt[ind] <= W)
        {
            take = val[ind] + f(ind - 1, W - wt[ind], wt, val, dp);
        }
        return dp[ind][W] = max(take, notTake);
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return f(n - 1, W, wt, val, dp);
    }
};

// Approach 3 : Tabulation
// Time Complexity - O(N* W)
// Space Complexity - O(N*W)

class Solution
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {

        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }

        for (int j = wt[0]; j <= W; j++)
        {
            dp[0][j] = val[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                int notTake = 0 + dp[i - 1][j];
                int take = INT_MIN;
                if (wt[i] <= j)
                {
                    take = val[i] + dp[i - 1][j - wt[i]];
                }
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[n - 1][W];
    }
};