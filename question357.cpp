// Relocate Marbles - Leetcode
// Time Complexity - O(N) + O(M)
// Space Complexity - O(N + M)

class Solution
{
public:
    vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom, vector<int> &moveTo)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] = 1;
        }
        int m = moveTo.size();
        for (int i = 0; i < m; i++)
        {
            mp[moveFrom[i]] = 0;
            mp[moveTo[i]] = 1;
        }
        vector<int> ans;
        for (auto it : mp)
        {
            if (it.second != 0)
            {
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};