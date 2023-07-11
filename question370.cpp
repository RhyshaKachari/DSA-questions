// Knapsack with Duplicate Items - GFG

// Approach 1 : Recursion
// Time Complexity - exponential
// Space Complexity - O(N)

class Solution
{
public:
    int f(int ind, int W, int val[], int wt[])
    {
        // base case
        if (ind == 0)
        {

            return (W / wt[0]) * val[0];
        }

        int notTake = f(ind - 1, W, val, wt);
        int take = INT_MIN;
        if (wt[ind] <= W)
        {
            take = val[ind] + f(ind, W - wt[ind], val, wt);
        }
        return max(notTake, take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        return f(N - 1, W, val, wt);
    }
};

// Approach 2 : Memoisation
// Time Complexity - O(N* W)
// Space Complexity - O(N*W) + O(N)

class Solution
{
public:
    int f(int ind, int W, int val[], int wt[], vector<vector<int>> &dp)
    {
        // base case
        if (ind == 0)
        {

            return (W / wt[0]) * val[0];
        }
        if (dp[ind][W] != -1)
        {
            return dp[ind][W];
        }

        int notTake = f(ind - 1, W, val, wt, dp);
        int take = INT_MIN;
        if (wt[ind] <= W)
        {
            take = val[ind] + f(ind, W - wt[ind], val, wt, dp);
        }
        return dp[ind][W] = max(notTake, take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W + 1, -1));
        return f(N - 1, W, val, wt, dp);
    }
};

// Approach 3 : Tabulation
// Time Complexity - O(N*W)
// Space Complexity - O(N*W)

class Solution
{
public:
    int f(int ind, int W, int val[], int wt[], vector<vector<int>> &dp)
    {
        // base case
        if (ind == 0)
        {

            return (W / wt[0]) * val[0];
        }
        if (dp[ind][W] != -1)
        {
            return dp[ind][W];
        }

        int notTake = f(ind - 1, W, val, wt, dp);
        int take = INT_MIN;
        if (wt[ind] <= W)
        {
            take = val[ind] + f(ind, W - wt[ind], val, wt, dp);
        }
        return dp[ind][W] = max(notTake, take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W + 1, -1));
        for (int j = 0; j <= W; j++)
        {
            dp[0][j] = (j / wt[0]) * val[0];
        }

        for (int ind = 1; ind < N; ind++)
        {
            for (int j = 0; j <= W; j++)
            {
                int notTake = dp[ind - 1][j];
                int take = INT_MIN;
                if (wt[ind] <= j)
                {
                    take = val[ind] + dp[ind][j - wt[ind]];
                }
                dp[ind][j] = max(notTake, take);
            }
        }
        return dp[N - 1][W];
    }
};
