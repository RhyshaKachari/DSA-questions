// Two Sum - Leetcode

// Approach 1: Using two loops
// Time Complexity  = O(N^2)
// Space Complexity = O(1) no extra space

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

// Approach 2 :
// Time Complexity  = O(N^2)
// Space Complexity = O(1) no extra space

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

// Approach 3 : Using Hashing

// Time Complexity  =  O(N log N)
// Space Complexity = O(1)

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int more = target - nums[i];
            if (mp.find(more) != mp.end())
            {
                return {mp[more], i};
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};

// Approach 4 : Using Two Pointers

// Time Complexity  = O(n log n)
// Space Complexity = O(1)

class Solution
{
public:
    bool<int> twoSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] == target)
            {
                return true;
            }
            else if (nums[i] + nums[j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};