// Max Consecutive Ones III - Leetcode

//  Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int zero = 0;
        int i = 0;
        int j = 0;
        int mx = 0;
        int n = nums.size();
        while (j < n)
        {
            // calculation
            if (nums[j] == 0)
            {
                zero++;
            }

            // condition doesn't statisfy
            while (zero > k)
            {
                if (nums[i] == 0)
                {
                    zero--;
                }
                i++;
            }

            // zero <= k
            mx = max(j - i + 1, mx);
            j++;
        }
        return mx;
    }
};