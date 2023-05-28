// Rearrange Array Elements by Sign - Leetcode

// Approach 1 :  Brute Force
// Time Complexity = O(n) + O(n)
// Space Complexity = O(n)

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> pos;
        vector<int> neg;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                pos.push_back(nums[i]);
            }
            else
            {
                neg.push_back(nums[i]);
            }
        }

        for (int i = 0; i < n / 2; i++)
        {
            nums[i * 2] = pos[i];
            nums[i * 2 + 1] = neg[i];
        }
        return nums;
    }
};

// Approach 2 : Optimal Approach
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIndex = 0;
        int negIndex = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            else
            {
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }
        return ans;
    }
};