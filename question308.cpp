// Maximum Nesting Depth of the Parentheses - Leetcode

// Approach 1 :
// Time Complexity : O(|s|)
// Space Complexity : O(|s|)

class Solution
{
public:
    int maxDepth(string s)
    {
        int mx = 0;
        stack<char> st;
        int curr = 0;
        for (auto it : s)
        {
            if (it == '(')
            {
                st.push(it);
                curr++;
                mx = max(mx, curr);
            }
            else if (it == ')')
            {
                st.pop();
                curr--;
            }
        }
        return mx;
    }
};

// Approach 2 :
// Time Complexity : O(|s|)
// Space Complexity : O(1)

class Solution
{
public:
    int maxDepth(string s)
    {
        int mx = 0;
        int curr = 0;
        for (auto it : s)
        {
            if (it == '(')
            {
                curr++;
                mx = max(mx, curr);
            }
            else if (it == ')')
            {
                curr--;
            }
        }
        return mx;
    }
};