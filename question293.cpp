// Max Sum without Adjacents - GFG

// Approach 1 : Memoization
// Time Complexity - O(n)
// Space Complexity - O(n) + O(n)

class Solution
{
public:
    int f(int ind, vector<int> &dp, int *arr)
    {
        if (ind == 0)
        {
            return arr[ind];
        }
        if (ind < 0)
        {
            return 0;
        }

        if (dp[ind] != -1)
        {
            return dp[ind];
        }

        int pick = arr[ind] + f(ind - 2, dp, arr);
        int notpick = 0 + f(ind - 1, dp, arr);
        return dp[ind] = max(pick, notpick);
    }
    int findMaxSum(int *arr, int n)
    {
        vector<int> dp(n, -1);
        return f(n - 1, dp, arr);
    }
};

// Approach 2 : Tabulation
// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution
{
public:
    int findMaxSum(int *arr, int n)
    {

        vector<int> dp(n);
        dp[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            int pick = arr[i];
            if (i - 2 >= 0)
            {
                pick += dp[i - 2];
            }

            int notpick = dp[i - 1];
            dp[i] = max(pick, notpick);
        }
        return dp[n - 1];
    }
};

// Approach 3 : Space Optimisation
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution
{
public:
    int findMaxSum(int *arr, int n)
    {

        int prev = arr[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int pick = arr[i];
            if (i - 2 >= 0)
            {
                pick += prev2;
            }

            int notpick = prev;
            int curr = max(pick, notpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};