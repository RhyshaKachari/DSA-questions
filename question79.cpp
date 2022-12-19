// Move Zeroes - Leetcode

// Approach 1 : Brute Force
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        vector<int> v;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                v.push_back(nums[i]);
            }
        }
        int k = v.size();
        for (int i = 1; i <= n - k; i++)
        {
            v.push_back(0);
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] = v[i];
        }
    }
};

// Approach 2 : Two Pointer Approach
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        for (int j = 1; j < n; j++)
        {
            if (nums[i] != 0)
            {
                i++;
            }
            else if (nums[i] == 0 && nums[j] != 0)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
        }
    }
};