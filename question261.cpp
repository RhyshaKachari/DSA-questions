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

// Approach 2 : Here we will fix two pointers and then find the remaining two elements using the two pointer technique as the array will be sorted from the first

// Time Complexity : O(n log n) for sorting the array and O(n^3)
// Space Complexity : O(1)

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        if (nums.empty())
        {
            return result;
        }

        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            long long int target3 = target - nums[i];
            for (int j = i + 1; j < n; j++)
            {
                long long int target2 = target3 - nums[j];
                int front = j + 1;
                int back = n - 1;
                while (front < back)
                {
                    long long int twosum = nums[front] + nums[back];
                    if (twosum < target2)
                    {
                        front++;
                    }
                    else if (twosum > target2)
                    {
                        back--;
                    }
                    else
                    {
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        result.push_back(quadruplet);

                        while (front < back && nums[front] == quadruplet[2])
                        {
                            front++;
                        }
                        while (front < back && nums[back] == quadruplet[3])
                        {
                            back--;
                        }
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j])
                {
                    j++;
                }
            }
            while (i + 1 < n && nums[i + 1] == nums[i])
            {
                i++;
            }
        }
        return result;
    }
};