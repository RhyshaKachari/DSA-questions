// Next Permutation - Leetcode

// Approach 1 : We will generate all the permutations of the given arr and then return the next permutation

// Time Complexity = O(n! * n)
// Space Complexity = O(n)

// Approach 2 : using the built_in next permutation function

// Approach 3 : In linear time complexity

// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int l, k;
        for (k = n - 2; k >= 0; k--)
        {
            if (nums[k] < nums[k + 1])
            {
                break;
            }
        }
        if (k < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (l = n - 1; l >= 0; l--)
            {
                if (nums[l] > nums[k])
                {
                    break;
                }
            }
            swap(nums[l], nums[k]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};