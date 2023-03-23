// Sort Colors - Leetcode

// Approach 1 : Simple sorting
// Time Complexity = O(nlog n)
// Space Complexity = O(1)

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// Approach 2 : Using Counter Variables
// Time Complexity = O(n)
// Space Complexity =  O(1)

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                cnt0++;
            }
            else if (nums[i] == 1)
            {
                cnt1++;
            }
            else
            {
                cnt2++;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt0)
            {
                nums[i] = 0;
                cnt0--;
            }
            else if (cnt1)
            {
                nums[i] = 1;
                cnt1--;
            }
            else
            {
                nums[i] = 2;
                cnt2--;
            }
        }
    }
};

// Approach 3 : Using Dutch National Flag Algorithm

// Time Complexity = O(n)
// Space Complexity  = O(1)

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};