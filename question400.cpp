// Asteroid Collision -  Leetcode

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[i] < 0 && st.top() > 0)
            {
                int sum = st.top() + nums[i];
                if (sum < 0)
                {
                    st.pop();
                }
                else if (sum > 0)
                {
                    nums[i] = 0;
                }
                else
                {
                    st.pop();
                    nums[i] = 0;
                }
            }

            if (nums[i] != 0)
            {
                st.push(nums[i]);
            }
        }

        int sz = st.size();
        vector<int> ans(sz, 0);
        int i = 0;
        while (!st.empty())
        {
            ans[sz - i - 1] = st.top();
            st.pop();
            i++;
        }
        return ans;
    }
};