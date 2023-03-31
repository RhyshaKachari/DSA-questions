// Reverse Words in a String - Leetcode

// Approach 1 : Using stack
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        for (int i = 0; i < s.length(); i++)
        {
            string word = "";
            while (s[i] != ' ' && i < s.length())
            {
                word += s[i];
                i++;
            }
            if (word != "")
                st.push(word);
        }

        string ans = "";
        while (st.size() != 1)
        {
            ans += st.top() + " ";
            st.pop();
        }
        ans += st.top();
        return ans;
    }
};

// Approach 2 : Using two pointers
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        int i = 0;
        string result;
        while (i < n)
        {
            while (i < n && s[i] == ' ')
            {
                i++;
            }
            if (i >= n)
            {
                break;
            }
            int j = i + 1;
            while (j < n && s[j] != ' ')
            {
                j++;
            }
            string sub = s.substr(i, j - i);
            if (result.length() == 0)
            {
                result = sub;
            }
            else
            {
                result = sub + " " + result;
            }
            i = j + 1;
        }
        return result;
    }
};