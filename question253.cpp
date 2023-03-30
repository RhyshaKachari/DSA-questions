// 3Sum - Leetcode

// Approach 1 : We will use three loops and find combinations whose sum is 0 and if we get a combination then we push it in a set

// Time Complexity = O(n^3 log n)
// Space Complexity = O(3*k) where k is the number of triplets

// Approach 2 : We will use hashing . First create a hash map and store the count of each element. Then we will run two loops and see if the third element is present in the map if it does then we will push all the three in a set after sorting

// Time Complexity : O(n^2 log n)
// Space Complexity : O(N) + O(M)

// Approach 3 : Using three pointers

// Time Complexity = O(n^2)
// Space Complexity = O(3*k)

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                int low = i + 1;
                int high = n - 1;
                int sum = 0 - nums[i];
                while (low < high)
                {
                    if (nums[low] + nums[high] == sum)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        while (low < high && nums[low] == nums[low + 1])
                        {
                            low++;
                        }
                        while (low < high && nums[high] == nums[high - 1])
                        {
                            high--;
                        }
                        low++;
                        high--;
                    }

                    else if (nums[low] + nums[high] < sum)
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};