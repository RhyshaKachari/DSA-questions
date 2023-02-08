// Remove Element - Leetcode
// Time Complexity = O(n log n )
// Space Complexity = O(n)

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == val)
            {
                count++;
            }
        }
        if (count == 0)
        {
            return n;
        }

        if (count == n)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = n - 1;
        while (nums[i] != val)
        {
            i++;
        }
        while (nums[j] != val)
        {
            j--;
        }
        int k = n - 1 - j;
        while (k > 0)
        {
            nums[i] = nums[j + 1];
            k--;
            i++;
            j++;
        }
        return n - count;
    }
};