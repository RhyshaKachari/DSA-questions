// Permutations - Leetcode
// Medium

// Time Complexity = O(n*n!)
// Space Complexity = O(n)+O(n)


1st Approach
class Solution
{

public:
    void recurPermute(vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums, int freq[])
    {
        if (ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                // take condition
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPermute(ds, ans, nums, freq);

                // not take condition
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for (int i = 0; i < nums.size(); i++)
        {
            freq[i] = 0;
        }
        recurPermute(ds, ans, nums, freq);
        return ans;
    }
};