// Longest Consecutive Sequence -  Leetcode

// Approach 1 : We will sort the array and check for the longest sequence present
// Time Complexity : O(n log n) for sorting + O(n) for linear iteration

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        if (nums.size() == 1)
        {
            return 1;
        }
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int mx = INT_MIN;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                cnt++;
            }
            else if (nums[i] != nums[i - 1])
            {
                cnt = 1;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};

// Approach 2 : Using HashSet
// Time Complexity = O(n) + O(n) + O(n)
// Space Complexity = O(n)


class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        int longest = 0;
        set<int> hashset;
        for (auto num : nums)
        {
            hashset.insert(num);
        }
        for (auto num : nums)
        {
            if (!hashset.count(num - 1))
            {
                int currstreak = 1;
                int currnum = num;
                while (hashset.count(currnum + 1))
                {
                    currnum++;
                    currstreak++;
                }
                longest = max(longest, currstreak);
            }
        }
        return longest;
    }
};