// Subset II - GFG

// Time Complexity = O(k*2^n)
// Space Complexity = O(k*2^n)

class Solution
{

public:
    void solve(int ind, int N, vector<int> &out, vector<int> &nums, vector<vector<int>> &ans)
    {

        ans.push_back(out);

        for (int i = ind; i < N; i++)
        {
            if (i > ind && nums[i] == nums[i - 1])
            {
                continue;
            }
            out.push_back(nums[i]);
            solve(i + 1, N, out, nums, ans);
            out.pop_back();
        }
    }
    vector<vector<int>> printUniqueSubsets(vector<int> &nums)
    {
        int N = nums.size();
        vector<vector<int>> ans;
        vector<int> out;
        sort(nums.begin(), nums.end());
        solve(0, N, out, nums, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};