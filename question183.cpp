// Contains Duplicate - Leetcode
// Approach 1:
// Time Complexity = O(n^2)
// Space Complexity = O(1)

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// Approach 2:
// Time Complexity : O(n log n)
// Space Complexity : O(1)

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }
        return false;
    }
};

// Approach 3:
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (auto it : mp)
        {
            if (it.second > 1)
            {
                return true;
            }
        }
        return false;
    }
};
