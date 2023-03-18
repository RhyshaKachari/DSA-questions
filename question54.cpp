// Combination Sum II - Leetcode

// Time Complexity = O(2^n*k)
// Space Complexity = O(K*x)

class Solution
{
public:
    void solve(int ind, int target, vector<int> &out, vector<int> &inp, vector<vector<int>> &ans, int n)
    {
        if (target == 0)
        {
            ans.push_back(out);
            return;
        }

        for (int i = ind; i < n; i++)
        {
            if (i > ind && inp[i] == inp[i - 1])
            {
                continue;
            }
            if (inp[i] > target)
            {
                break;
            }
            out.push_back(inp[i]);
            solve(i + 1, target - inp[i], out, inp, ans, n);
            out.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        solve(0, target, out, candidates, ans, n);
        return ans;
    }
};