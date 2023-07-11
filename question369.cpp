// Coin change II - Leetcode

// Approach 1 : Recursion
// Time Complexity - exponential
// Space Complexity - O(N) recursive stack space

class Solution
{
public:
    int f(int ind, vector<int> &coins, int amo)
    {
        if (ind == 0)
        {
            return amo % coins[0] == 0;
        }

        int notTake = f(ind - 1, coins, amo);
        int take = 0;
        if (coins[ind] <= amo)
        {
            take = f(ind, coins, amo - coins[ind]);
        }
        return notTake + take;
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        return f(n - 1, coins, amount);
    }
};

// Approach 2 : Memoization
// Time Complexity - O(n*amount)
// Space Complexity - O(n*amount) + O(n) recursive

class Solution
{
public:
    int f(int ind, vector<int> &coins, int amo, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            return amo % coins[0] == 0;
        }
        if (dp[ind][amo] != -1)
        {
            return dp[ind][amo];
        }
        int notTake = f(ind - 1, coins, amo, dp);
        int take = 0;
        if (coins[ind] <= amo)
        {
            take = f(ind, coins, amo - coins[ind], dp);
        }
        return dp[ind][amo] = notTake + take;
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n - 1, coins, amount, dp);
    }
};

// Approach 3 : Tabulation
// Time Complexity - O(n*amount)
// Space Complexity - O(n*amount)

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int j = 0; j <= amount; j++)
        {
            if (j % coins[0] == 0)
            {
                dp[0][j] = 1;
            }
            else
            {
                dp[0][j] = 0;
            }
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int amo = 0; amo <= amount; amo++)
            {
                int notTake = dp[ind - 1][amo];
                int take = 0;
                if (coins[ind] <= amo)
                {
                    take = dp[ind][amo - coins[ind]];
                }
                dp[ind][amo] = notTake + take;
            }
        }
        return dp[n - 1][amount];
    }
};