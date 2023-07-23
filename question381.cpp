// Longest Increasing Subsequence - Leetcode

// Approach 1 : Recursion
// Time Complexity - O(2^N)
// Space Complexity - O(N)

class Solution
{
public:
    int f(int ind, int prev_ind, vector<int> &nums, int n)
    {
        if (ind == n)
        {
            return 0;
        }

        // not take
        int notTake = f(ind + 1, prev_ind, nums, n);
        int take = INT_MIN;
        if (prev_ind == -1 || nums[ind] > nums[prev_ind])
        {
            take = f(ind + 1, ind, nums, n);
        }
        return max(notTake, take);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return f(0, -1, nums, n);
    }
};

// Approach 2 : Memoization
// we will do a coordinate change
// Time Complexity - O(N*N)
// Space Complexity - O(N*N)+ O(N)

class Solution
{
private:
    int f(int ind, int prev, vector<int> &nums, int n, vector<vector<int>> &dp)
    {
        if (ind == n)
        {
            return 0;
        }
        if (dp[ind][prev + 1] != -1)
        {
            return dp[ind][prev + 1];
        }
        int notTake = f(ind + 1, prev, nums, n, dp);
        int take = INT_MIN;
        if (prev == -1 || nums[ind] > nums[prev])
        {
            take = 1 + f(ind + 1, ind, nums, n, dp);
        }
        return dp[ind][prev + 1] = max(notTake, take);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, n, dp);
    }
};

// Approach 3 :  Tabulation
// Time Complexity - O(N*N)
// Space Compelxity - O(N*N)

class Solution
{
public:
    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev = ind - 1; prev >= -1; prev--)
            {
                int notTake = 0 + dp[ind + 1][prev + 1];
                int take = 0;
                if (prev == -1 || (a[ind] > a[prev]))
                {
                    take = 1 + dp[ind + 1][ind + 1];
                }
                dp[ind][prev + 1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};

// Approach 4 : A very beautiful solution
// Time Complexity : O(N*N)
// Space Complexity : O(N)

class Solution
{
public:
    int longestSubsequence(int n, int a[])
    {
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (a[prev] < a[i])
                {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};