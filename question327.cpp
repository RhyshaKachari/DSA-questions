// Minimum Value to Get Positive Step by Step Sum - Leetcode

// Time Coplexity -O(N)
// Space Complexity - O(N)

class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pre;
        int psum = 0;
        for (int it : nums)
        {
            psum += it;
            pre.push_back(psum);
        }
        int x = *min_element(pre.begin(), pre.end());

        if (x < 0)
        {
            return abs(x) + 1;
        }
        else
        {
            return 1;
        }
    }
};