// Combination Sum - GFG

// Time Complexity = O(X^2 * 2^N) where X is average of summation B/arri for every number in the array
// Space Complexity = O(X*2^N)

class Solution
{
public:
    void solve(int ind, int target, vector<int> &out, vector<int> &inp, vector<vector<int>> &ans, int n)
    {
        if (ind >= n)
        {
            if (target == 0)
            {
                ans.push_back(out);
            }
            return;
        }
        // taking case
        if (inp[ind] <= target)
        {
            out.push_back(inp[ind]);
            solve(ind, target - inp[ind], out, inp, ans, n);
            out.pop_back();
        }
        // not taking case
        solve(ind + 1, target, out, inp, ans, n);
    }

    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        vector<vector<int>> ans;
        vector<int> out;

        // most important line of the whole code
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        vector<int> inp = A;

        int n = A.size();
        solve(0, B, out, inp, ans, n);

        return ans;
    }
};