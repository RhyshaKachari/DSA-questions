// Remove Outermost Parentheses - Leetcode

// Time Complexity  = O(n)
// Space Complexity =  O(n)

class Solution
{
public:
    string removeOuter(string &s)
    {
        stack<char> st;
        string ans;
        for (auto it : s)
        {
            if (it == '(')
            {
                if (st.size() > 0)
                {
                    ans.push_back(it);
                }
                st.push(it);
            }
            else
            {
                st.pop();
                if (!st.empty())
                {
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};