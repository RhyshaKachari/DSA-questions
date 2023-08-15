//Remove K Digits - Leetcode
//Time Complexity - O(N)
//Space Complexity - O(N)

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        stack<char> st;
        for (char c : num)
        {
            while (!st.empty() && k > 0 && c < st.top())
            {
                st.pop();
                k--;
            }
            if (!st.empty() || c != '0')
            {
                st.push(c);
            }
        }
        // now remove the larger numbers
        while (!st.empty() && k--)
        {
            st.pop();
        }
        if (st.empty())
        {
            return "0";
        }

        string ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};