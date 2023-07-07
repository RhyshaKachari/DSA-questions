// Subset Sum Problem - GFG

// Approach 1 : Recursion
// Time Complexity - O(2^n)
// Space Complexity - O(n)

class Solution
{
public:
    bool f(int ind, int target, vector<int> arr)
    {
        if (target == 0)
        {
            return true;
        }
        if (ind == 0)
        {
            return arr[0] == target;
        }

        bool notTake = f(ind - 1, target, arr);
        bool take = false;
        if (target >= arr[ind])
        {
            take = f(ind - 1, target - arr[ind], arr);
        }
        return notTake || take;
    }
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        return f(n - 1, sum, arr);
    }
};

// Approach 2 - Memoization
// Time Complexity - O(N*sum)
// Space Complexity - O(N*sum) + O(N)

class Solution
{
public:
    bool f(int ind, int target, vector<int> arr, vector<vector<int>> &dp)
    {
        if (target == 0)
        {
            return true;
        }
        if (ind == 0)
        {
            return arr[0] == target;
        }

        if (dp[ind][target] != -1)
        {
            return dp[ind][target];
        }
        bool notTake = f(ind - 1, target, arr, dp);
        bool take = false;
        if (target >= arr[ind])
        {
            take = f(ind - 1, target - arr[ind], arr, dp);
        }
        return dp[ind][target] = notTake || take;
    }
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(n - 1, sum, arr, dp);
    }
};

// Approach 3 :
// Time Complexity - O(N*sum)
// Space Complexity - O(N*sum)

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        dp[0][arr[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int target = 1; target < sum + 1; target++)
            {
                bool notTake = dp[i - 1][target];
                bool take = false;
                if (target >= arr[i])
                {
                    take = dp[i - 1][target - arr[i]];
                }
                dp[i][target] = notTake || take;
            }
        }
        return dp[n - 1][sum];
    }
};

// Approach 4 - Space Optimisation
// Time Complexity = O(N*sum)
// Space Complexity = O(1)

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<bool> prev(sum + 1, 0);
        vector<bool> curr(sum + 1, 0);
        prev[0] = true;
        curr[0] = true;
        prev[arr[0]] = true;
        for (int i = 1; i < n; i++)
        {
            for (int target = 1; target < sum + 1; target++)
            {
                bool notTake = prev[target];
                bool take = false;
                if (arr[i] <= target)
                {
                    take = prev[target - arr[i]];
                }
                curr[target] = take | notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }
};