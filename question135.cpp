// Climbing Stairs - Leetcode

// Approach 1 :  Tabulation Technique( Bottom Up Approach)
// Time Complexity = O(N)
// Space Complexity  = O(N)

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};


// Approach 2: Space Optimisation
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        int prev2 = 1;
        int prev = 1;
        for (int i = 2; i <= n; i++)
        {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};


// Approach 3 : Memoization
// Time Complexity = O(N)
// Space Complexity = O(N) + O(N) = O(N)

class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        if (dp[n] != 0)
        {
            return dp[n];
        }
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);
        return solve(n, dp);
    }
};