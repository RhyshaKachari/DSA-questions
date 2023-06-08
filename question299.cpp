// Isomorphic Strings - Leetcode

// Time Complexity : O(|s|)
// Space Complexity : O(|s|) + O(|t|)

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mp;
        unordered_set<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (mp.count(s[i]) == 0 && st.count(t[i]) == 0)
            {
                mp[s[i]] = t[i];
                st.insert(t[i]);
            }
            else if (mp.count(s[i]) == 0 && st.count(t[i]))
            {
                return false;
            }
            else if (mp[s[i]] != t[i])
            {
                return false;
            }
        }
        return true;
    }
};
