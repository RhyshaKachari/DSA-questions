// 4Sum - Leetcode

// Approach 1 : Using 3 pointers and then Binary Search on the remaining right part of the array
// Time Complexity : O(n log n) for sorting the array , O(n^3 log n) using three loops and binary search

class Solution
{
public:
    bool binarySearch(int low, int high, long long int target, vector<int> &nums)
    {
        while (low <= high)
        {
            long long int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> s;
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                for (int k = j + 1; k < n - 1; k++)
                {
                    long long int x = (long long)target - (long long)nums[i] - (long long)nums[j] - (long long)nums[k];

                    if (binarySearch(k + 1, n - 1, x, nums))
                    {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(x);
                        sort(v.begin(), v.end());
                        s.insert(v);
                    }
                }
            }
        }
        vector<vector<int>> result(s.begin(), s.end());
        return result;
    }
};