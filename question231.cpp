// Nth Fibonacci Number - GFG

// Approach 1 : Memoization
// Time Complexity =  O(n)
// Space Complexity = O(n) + O(n) stack space

class Solution
{
public:
    long long int m = 1e9 + 7;
    long long int f(long long int n, vector<long long int> &dp)
    {
        if (n <= 1)
        {
            return n;
        }
        if (dp[n] != -1)
        {
            return dp[n] % m;
        }
        return dp[n] = (f(n - 1, dp) + f(n - 2, dp)) % m;
    }
    long long int nthFibonacci(long long int n)
    {
        vector<long long int> dp(n + 1, -1);
        return f(n, dp) % m;
    }
};

// Approach 2 : Tabulation
// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution
{
public:
    long long int m = 1e9 + 7;
    long long int nthFibonacci(long long int n)
    {
        vector<long long int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}

// Approach 3 : Space Optimisation
// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution
{
public:
    long long int nthFibonacci(long long int n)
    {
        long long int prev2 = 0;
        long long int prev = 1;
        for (int i = 2; i <= n; i++)
        {
            long long int curr = (prev2 + prev) % m;
            prev2 = prev;
            prev = curr;
        }
        return prev % m;
    }
}