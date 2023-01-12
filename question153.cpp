// Majority Element II - Leetcode
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int count1 = 0;
        int count2 = 0;
        int ele1 = 0;
        int ele2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (ele1 == nums[i])
            {
                count1++;
            }
            else if (ele2 == nums[i])
            {
                count2++;
            }
            else if (count1 == 0)
            {
                ele1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                ele2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == ele1)
            {
                count1++;
            }
            if (nums[i] == ele2)
            {
                count2++;
            }
        }

        int n = nums.size();
        if (count1 > n / 3 && ele1 != ele2)
        {
            v.push_back(ele1);
        }
        if (count2 > n / 3)
        {
            v.push_back(ele2);
        }
        return v;
    }
};