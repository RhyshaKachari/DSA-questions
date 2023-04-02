// Reverse Pairs - Leetcode

// Approach 1 : Using two loops and find the pairs which will satisfy the condition
// Time Complexity = O(n^2)
// Space Complexity = O(1)

// Approach 2 : Using Merge Sort Algorithm
// Time Complexity : O(n log n) + O(n) + O(n)
// Space Complexity : O(n)

class Solution
{
public:
    int merge(vector<int> &nums, int left, int mid, int right)
    {
        int total = 0;
        int j = mid + 1;
        for (int i = 0; i <= mid; i++)
        {
            while (j <= right && nums[i] > 2LL * nums[j])
            {
                j++;
            }
            total += j - (mid + 1);
        }
        int i = left;
        j = mid + 1;
        vector<int> t;
        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
            {
                t.push_back(nums[i++]);
            }
            else
            {
                t.push_back(nums[j++]);
            }
        }
        while (i <= mid)
        {
            t.push_back(nums[i++]);
        }
        while (j <= right)
        {
            t.push_back(nums[j++]);
        }

        for (int i = left; i <= right; i++)
        {
            nums[i] = t[i - left];
        }

        return total;
    }

    int mergeSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return 0;
        }
        int mid = left + (right - left) / 2;
        int rev_count = mergeSort(nums, left, mid);
        rev_count += mergeSort(nums, mid + 1, right);
        rev_count += merge(nums, left, mid, right);
        return rev_count;
    }

    int reversePairs(vector<int> &nums)
    {
        int ans = mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
}