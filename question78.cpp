// Rotate Array -  LEETCODE
//Time Complexity = O(N)
//Space Complexity = O(1)

class Solution
{
public:
    void reverse(vector<int> &nums, int low, int high)
    {
        while (low <= high)
        {
            int temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
            low++;
            high--;
        }
    }

    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ki = k % n;
        reverse(nums, 0, n - ki - 1);
        reverse(nums, n - ki, n - 1);
        reverse(nums, 0, n - 1);
    }
};