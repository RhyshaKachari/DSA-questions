// Partitions with Given Difference - GFG

// Approach 1 : Recursion
// Time Complexity - O(2^N)
// Space Complexity - O(N)

class Solution
{
public:
    int mod = 1e9 + 7;
    int f(int ind, int sum, vector<int> &arr)
    {
        if (sum == 0)
        {
            return 1;
        }
        if (ind == 0)
        {
            return arr[ind] == sum;
        }

        int notTake = f(ind - 1, sum, arr) % mod;
        int take = 0;
        if (arr[ind] <= sum)
        {
            take = f(ind - 1, sum - arr[ind], arr) % mod;
        }
        return (notTake + take) % mod;
    }
    int countPartitions(int n, int d, vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), greater<int>());
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += arr[i];
        }
        if ((total - d) < 0)
        {
            return 0;
        }
        if ((total - d) % 2)
        {
            return 0;
        }
        int tofind = (total - d) / 2;
        return f(n - 1, tofind, arr) % mod;
    }
};

// Approach 2 : Memoization
// Time Complexity - O(N*sum)
// Space Complexity - O(N*sum) + O(N)

class Solution
{
public:
    int mod = 1e9 + 7;
    int f(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (sum == 0)
        {
            return 1;
        }
        if (ind == 0)
        {
            return arr[ind] == sum;
        }
        if (dp[ind][sum] != -1)
        {
            return dp[ind][sum];
        }
        int notTake = f(ind - 1, sum, arr, dp) % mod;
        int take = 0;
        if (arr[ind] <= sum)
        {
            take = f(ind - 1, sum - arr[ind], arr, dp) % mod;
        }
        return dp[ind][sum] = (notTake + take) % mod;
    }
    int countPartitions(int n, int d, vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), greater<int>());
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += arr[i];
        }
        if ((total - d) < 0)
        {
            return 0;
        }
        if ((total - d) % 2)
        {
            return 0;
        }
        int tofind = (total - d) / 2;
        vector<vector<int>> dp(n, vector<int>(tofind + 1, -1));
        return f(n - 1, tofind, arr, dp) % mod;
    }
};

// Approach 3 : Tabulation
// Time Complexity - O(N*sum)
// Space Complexity - O(N*sum)

class Solution
{
public:
    int mod = 1e9 + 7;
    int countPartitions(int n, int d, vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), greater<int>());
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += arr[i];
        }
        if ((total - d) < 0)
        {
            return 0;
        }
        if ((total - d) % 2)
        {
            return 0;
        }
        int tofind = (total - d) / 2;
        vector<vector<int>> dp(n, vector<int>(tofind + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        if (arr[0] <= tofind)
        {
            dp[0][arr[0]] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < tofind + 1; j++)
            {
                int notTake = dp[i - 1][j] % mod;
                int take = 0;
                if (arr[i] <= j)
                {
                    take = dp[i - 1][j - arr[i]] % mod;
                }
                dp[i][j] = (notTake + take) % mod;
            }
        }
        return dp[n - 1][tofind] % mod;
    }
};

// Approach 4 :
// Time Complexity - O(N*sum)
// Space Complexity - O(1)

class Solution
{
public:
    int mod = 1e9 + 7;
    int countPartitions(int n, int d, vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), greater<int>());
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += arr[i];
        }
        if ((total - d) < 0)
        {
            return 0;
        }
        if ((total - d) % 2)
        {
            return 0;
        }
        int tofind = (total - d) / 2;
        vector<vector<int>> dp(n, vector<int>(tofind + 1, 0));
        int sum = tofind;
        vector<int> prev(sum + 1, 0);
        prev[0] = 1;
        if (arr[0] <= sum)
        {
            prev[arr[0]] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> curr(sum + 1, 0);
            curr[0] = 1;
            for (int j = 1; j < sum + 1; j++)
            {
                int notTake = prev[j] % mod;
                int take = 0;
                if (arr[i] <= j)
                {
                    take = prev[j - arr[i]] % mod;
                }
                curr[j] = (notTake + take) % mod;
            }
            prev = curr;
        }
        return prev[sum] % mod;
    }
};
