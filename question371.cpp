// Buy Stock 2 - GFG

// Time Complexity - O(2^N)
// Space Complexity - O(N)

class Solution
{
public:
    long long f(int ind, int buy, vector<long long> &prices, int n)
    {
        if (ind == n)
        {
            return 0;
        }
        long long profit = 0;
        if (buy)
        {
            long long take = -prices[ind] + f(ind + 1, 0, prices, n);
            long long notTake = 0 + f(ind + 1, 1, prices, n);
            profit = max(take, notTake);
        }
        else
        {
            long long take = prices[ind] + f(ind + 1, 1, prices, n);
            long long notTake = 0 + f(ind + 1, 0, prices, n);
            profit = max(take, notTake);
        }
        return profit;
    }
    long long maximumProfit(vector<long long> &prices, int n)
    {
        return f(0, 1, prices, n);
    }
};

// Approach 2 :
// Time Complexity - O(n*2)
// Space complexity - O(N*2) + O(N)

class Solution
{
public:
    long long f(int ind, int buy, vector<long long> &prices, int n, vector<vector<long long>> &dp)
    {
        if (ind == n)
        {
            return 0;
        }
        if (dp[ind][buy] != -1)
        {
            return dp[ind][buy];
        }
        long long profit = 0;
        if (buy)
        {
            long long take = -prices[ind] + f(ind + 1, 0, prices, n, dp);
            long long notTake = 0 + f(ind + 1, 1, prices, n, dp);
            profit = max(take, notTake);
        }
        else
        {
            long long take = prices[ind] + f(ind + 1, 1, prices, n, dp);
            long long notTake = 0 + f(ind + 1, 0, prices, n, dp);
            profit = max(take, notTake);
        }
        return dp[ind][buy] = profit;
    }
    long long maximumProfit(vector<long long> &prices, int n)
    {
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return f(0, 1, prices, n, dp);
    }
};

// Approach 3 : Tabulation
// Time Complexity - O(N*2)
// Space Complexity - O(N*2)

class Solution
{
public:
    long long maximumProfit(vector<long long> &prices, int n)
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        dp[n][0] = dp[n][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {

            for (int buy = 0; buy < 2; buy++)
            {
                long long profit = 0;
                if (buy)
                {
                    long long take = -prices[ind] + dp[ind + 1][0];
                    long long notTake = 0 + dp[ind + 1][1];
                    profit = max(take, notTake);
                }
                else
                {
                    long long take = prices[ind] + dp[ind + 1][1];
                    long long notTake = 0 + dp[ind + 1][0];
                    profit = max(take, notTake);
                }
                dp[ind][buy] = profit;
            }
        }

        return dp[0][1];
    }
};

// Approach 4 : 
//Time Complexity - O(n)
//Space Complexity - O(1)

class Solution
{
public:
    long long maximumProfit(vector<long long> &prices, int n)
    {
        long long profit = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += (prices[i] - prices[i - 1]);
            }
        }
        return profit;
    }
};