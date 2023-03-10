// Contains Duplicate II - Leetcode

// Time Complexity = O(N)
// Space Complexity = O(k)

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int i = 0;
        int j = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        while (j < n)
        {
            if (mp.find(nums[j]) != mp.end())
            {
                return true;
            }
            mp[nums[j]]++;

            if (j - i < k)
            {
                j++;
            }
            else if (abs(j - i) == k)
            {
                mp[nums[i]]--;
                mp.erase(nums[i]);
                i++;
                j++;
            }
        }
        return false;
    }
};