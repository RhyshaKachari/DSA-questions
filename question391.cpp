// Largest Number - Leetcode

// Time Complexity - O(N log N)
// Space Complexity - O(N)

class Solution
{
public:
    static bool cmp(int a, int b)
    {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), cmp);
        int n = nums.size();
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            string add = to_string(nums[i]);
            ans += add;
        }
        if (ans[0] == '0')
        {
            return "0";
        }
        return ans;
    }
};