// Coin Change - Leetcode

// Approach 1 : Recursion
// Time Complexity - Exponential
// Space Complexity - O(N)

class Solution
{
public:
    int f(int ind, int amo, vector<int> &coins)
    {
        // base case
        if (ind == 0)
        {
            if (amo % coins[ind] == 0)
            {
                return amo / coins[ind];
            }
            else
            {
                return 1e9;
            }
        }

        int notTake = 0 + f(ind - 1, amo, coins);
        int take = 1e9;
        if (coins[ind] <= amo)
        {
            take = 1 + f(ind, amo - coins[ind], coins);
        }
        return min(notTake, take);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int ans = f(n - 1, amount, coins);
        if (ans >= 1e9)
        {
            return -1;
        }
        else
            return ans;
    }
};

// Approach 2 : Memoisation
// Time Complexity - O(n*amount)
// Space Complexity - O(n* amount) + O(n) recursive stack space

class Solution
{
public:
    int f(int ind, int amo, vector<int> &coins, vector<vector<int>> &dp)
    {
        // base case
        if (ind == 0)
        {
            if (amo % coins[ind] == 0)
            {
                return amo / coins[ind];
            }
            else
            {
                return 1e9;
            }
        }
        if (dp[ind][amo] != -1)
        {
            return dp[ind][amo];
        }
        int notTake = 0 + f(ind - 1, amo, coins, dp);
        int take = 1e9;
        if (coins[ind] <= amo)
        {
            take = 1 + f(ind, amo - coins[ind], coins, dp);
        }
        return dp[ind][amo] = min(notTake, take);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n - 1, amount, coins, dp);
        if (ans >= 1e9)
        {
            return -1;
        }
        else
            return ans;
    }
};

// Approach 3 : Tabulation
// Time Complexity - O(n*amount)
// Space Complexity - O(n*amount)

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int j = 0; j <= amount; j++)
        {
            if (j % coins[0] == 0)
            {
                dp[0][j] = j / coins[0];
            }
            else
            {
                dp[0][j] = 1e9;
            }
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int amo = 0; amo <= amount; amo++)
            {
                int notTake = 0 + dp[ind - 1][amo];
                int take = 1e9;
                if (coins[ind] <= amo)
                {
                    take = 1 + dp[ind][amo - coins[ind]];
                }
                dp[ind][amo] = min(notTake, take);
            }
        }

        int ans = dp[n - 1][amount];
        if (ans >= 1e9)
        {
            return -1;
        }
        else
            return ans;
    }
};