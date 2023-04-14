// Reverse words in a given string - GFG

// Approach 1 : Pushing in a stack
// Time Complexity = O(|S|)
// Space Complexity = O(|S|)

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        for (int i = 0; i < s.length(); i++)
        {
            string word = "";
            while (s[i] != '.' && i < s.length())
            {
                word += s[i];
                i++;
            }
            st.push(word);
        }
        string ans = "";
        while (st.size() != 1)
        {
            ans += st.top() + ".";
            st.pop();
        }
        ans = ans + st.top();
        return ans;
    }
}

// Approach 2 : We will start traversing the string from the back and keep storing it in a temp variable until we find a dot and once we find a dot then we simply reverse the temp variable and add it in the answer
// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution
{
public:
    string reverseWords(string S)
    {
        string ans = "";
        string temp = "";
        for (int i = S.length() - 1; i >= 0; i--)
        {
            if (S[i] == '.')
            {
                reverse(temp.begin(), temp.end());
                ans = ans + temp;
                ans.push_back('.');
                temp = "";
            }
            else
            {
                temp.push_back(S[i]);
            }
        }
        reverse(temp.begin(), temp.end());
        ans = ans + temp;
        return ans;
    }
};