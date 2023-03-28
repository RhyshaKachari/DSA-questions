// Valid Parentheses -  Leetcode

// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution
{
public:
    bool isValid(string s)
    {
        int length = s.size();
        stack<char> st;
        for (int i = 0; i < length; i++)
        {
            char a = s[i];
            if (a == '{' || a == '[' || a == '(')
            {
                st.push(a);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                else
                {
                    char t = st.top();
                    if ((a == '}' && t == '{') || (a == ']' && t == '[') || (a == ')' && t == '('))
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};