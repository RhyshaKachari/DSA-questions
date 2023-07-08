// Perfect Sum Problem - GFG

// Approach 1 : Recursion
//  Time Complexity - O(2^N)
//  Space Complexity - O(N)

class Solution
{

public:
	int f(int ind, int sum, int arr[])
	{
		if (sum == 0)
		{
			return 1;
		}
		if (ind == 0)
		{
			return arr[ind] == sum;
		}

		int notTake = f(ind - 1, sum, arr);
		int take = 0;
		if (arr[ind] <= sum)
		{
			take = f(ind - 1, sum - arr[ind], arr);
		}
		return notTake + take;
	}
	int perfectSum(int arr[], int n, int sum)
	{
		sort(arr, arr + n, greater<int>());
		return f(n - 1, sum, arr);
	}
};

// Approach 2 : Memoization
// Time Complexity - O(N* sum)
// Space Complexity - O(N*sum)+O(N)

class Solution
{

public:
	int f(int ind, int sum, int arr[], vector<vector<int>> &dp)
	{
		int mod = 1e9 + 7;
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
	int perfectSum(int arr[], int n, int sum)
	{
		int mod = 1e9 + 7;
		vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
		sort(arr, arr + n, greater<int>());
		return f(n - 1, sum, arr, dp) % mod;
	}
};

// Approach 3: Tabulation
// Time Complexity - O(N*sum)
// Space Complexity - O(N*sum)

class Solution
{

public:
	int perfectSum(int arr[], int n, int sum)
	{
		int mod = 1e9 + 7;
		vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
		sort(arr, arr + n, greater<int>());
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
			for (int j = 1; j < sum + 1; j++)
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
		return dp[n - 1][sum] % mod;
	}
};

// Approach 4: Space Optimisation
// Time Complexity - O(N*sum)
// Space Complexity - O(1)

class Solution
{

public:
	int perfectSum(int arr[], int n, int sum)
	{
		sort(arr, arr + n, greater<int>());
		int mod = 1e9 + 7;
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