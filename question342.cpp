// Partition Equal Subset Sum - GFG

// Approach 1 : Recursion
//  Time Complexity - O(2^n) + O(n)
//  Space Complexity - O(n)

class Solution
{
public:
    bool f(int ind, int target, int arr[])
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
        if (arr[ind] <= target)
        {
            take = f(ind - 1, target - arr[ind], arr);
        }
        return take || notTake;
    }

    bool subsetSum(int arr[], int sum, int n)
    {
        return f(n - 1, sum, arr);
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        if (sum % 2)
        {
            return 0;
        }
        if (subsetSum(arr, sum / 2, N))
        {
            return 1;
        }
        else
            return 0;
    }
};

// Approach 2 : Memoization
// Time Complexity - O(sum*n) + O(n)
// Space Complexity - O(sum*n) + O(n)

class Solution
{
public:
    bool f(int ind, int target, int arr[], vector<vector<int>> &dp)
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
        if (arr[ind] <= target)
        {
            take = f(ind - 1, target - arr[ind], arr, dp);
        }
        return dp[ind][target] = take || notTake;
    }

    bool subsetSum(int arr[], int sum, int n)
    {
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(n - 1, sum, arr, dp);
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        if (sum % 2)
        {
            return 0;
        }
        if (subsetSum(arr, sum / 2, N))
        {
            return 1;
        }
        else
            return 0;
    }
};

// Approach 3 : Tabulation
// Time Complexity - O(N* sum)
// Space Complexity - O(N* sum)

class Solution
{
public:
    bool subsetSum(int arr[], int sum, int n)
    {
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        if (arr[0] <= sum)
        {
            dp[0][arr[0]] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int target = 1; target < sum + 1; target++)
            {
                bool notTake = dp[i - 1][target];
                bool take = false;
                if (arr[i] <= target)
                {
                    take = dp[i - 1][target - arr[i]];
                }
                dp[i][target] = take || notTake;
            }
        }
        return dp[n - 1][sum];
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        if (sum % 2)
        {
            return 0;
        }
        if (subsetSum(arr, sum / 2, N))
        {
            return 1;
        }
        else
            return 0;
    }
};

// Approach 4 : Space Optimisation
// Time Complexity - O(N*sum)
// Space Complexity - O(1)

class Solution
{
public:
    bool subsetSum(int arr[], int sum, int n)
    {
        vector<bool> prev(sum + 1, 0), curr(sum + 1, 0);
        prev[0] = 1;
        curr[0] = 1;
        if (arr[0] <= sum)
        {
            prev[arr[0]] = 1;
        }
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
                curr[target] = take || notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        if (sum % 2)
        {
            return 0;
        }
        if (subsetSum(arr, sum / 2, N))
        {
            return 1;
        }
        else
            return 0;
    }
};