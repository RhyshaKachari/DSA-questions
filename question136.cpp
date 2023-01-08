// Geek Jump - GFG

// Approach 1 : Memoization
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution
{
private:
    int solve(int ind, vector<int> &height, vector<int> &dp)
    {
        if (ind == 0)
        {
            return 0;
        }

        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        int jumpOne = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
        int jumpTwo = INT_MAX;

        if (ind > 1)
        {
            jumpTwo = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
        }
        return dp[ind] = min(jumpOne, jumpTwo);
    }

public:
    int minimumEnergy(vector<int> &height, int n)
    {
        vector<int> dp(n + 1, -1);
    }
};


// Approach 2 : Tabulation
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution
{
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int left = dp[i - 1] + abs(height[i] - height[i - 1]);
            int right = INT_MAX;
            if (i > 1)
            {
                right = dp[i - 2] + abs(height[i] - height[i - 2]);
            }
            dp[i] = min(left, right);
        }
        return dp[n - 1];
    }
};


// Approach 3: Space Optimisation
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution
{
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        int prev = 0;
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int jumpOne = prev + abs(height[i - 1] - height[i]);
            int jumpTwo = INT_MAX;
            if (i > 1)
            {
                jumpTwo = prev2 + abs(height[i - 2] - height[i]);
            }
            int curr = min(jumpOne, jumpTwo);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
