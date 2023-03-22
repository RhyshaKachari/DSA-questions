// Binary Search Trees - GFG

// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution
{
public:
    bool isBSTTraversal(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] >= nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};