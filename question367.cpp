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