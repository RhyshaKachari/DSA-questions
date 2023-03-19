// Combination Sum  III - Leetcode

// Approach 1 : Finding all the subsets
//  Time Complexity = O(2^9)
//  Space Complexity = O(9*2^9)

class Solution
{
public:
    void solve(int ind, int sum, vector<int> &out, vector<int> &inp, vector<vector<int>> &ans, int target, int sz, int k)
    {
        if (ind == sz)
        {
            if (out.size() == k)
            {
                if (sum == target)
                {
                    ans.push_back(out);
                }
            }
            return;
        }

        // take condition
        out.push_back(inp[ind]);
        solve(ind + 1, sum + inp[ind], out, inp, ans, target, sz, k);
        // not take condition
        out.pop_back();
        solve(ind + 1, sum, out, inp, ans, target, sz, k);
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> inp = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> out;
        vector<vector<int>> ans;
        int target = n;
        int sz = inp.size();
        solve(0, 0, out, inp, ans, target, sz, k);
        return ans;
    }
};

// Approach 2 : Optimised Solution
// Time Complexity = O(2^k)
// Space Complexity = O(k)

class Solution
{
public:
    void combinationSum3(int n, int k, vector<int> &out, vector<vector<int>> &ans, int start, int sum)
    {
        if (out.size() == k)
        {
            if (sum == n)
            {
                ans.push_back(out);
            }
            return;
        }

        for (int i = start; i <= 9; i++)
        {
            // take condition
            out.push_back(i);
            combinationSum3(n, k, out, ans, i + 1, sum + i);
            out.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> out;
        vector<vector<int>> ans;
        combinationSum3(n, k, out, ans, 1, 0);
        return ans;
    }
};