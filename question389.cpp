// Valid Expression - GFG
// Time Complexity - O(N)
// Space Complexity - O(N)

bool valid(string s)
{
    int n = s.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.size() == 0 || st.top() != '(')
            {
                return false;
            }
            st.pop();
        }
        else if (s[i] == '}')
        {
            if (st.size() == 0 || st.top() != '{')
            {
                return false;
            }
            st.pop();
        }
        else if (s[i] == ']')
        {
            if (st.size() == 0 || st.top() != '[')
            {
                return false;
            }
            st.pop();
        }
    }
    if (st.size() > 0)
    {
        return false;
    }
    return true;
}