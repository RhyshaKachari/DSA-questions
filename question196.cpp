// Longest K unique characters substring - GFG
// Time Complexity  = O(|S|)
// Space Complexity = O(|S|)

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        unordered_map<char, int> mp;
        int mx = -1;
        int i = 0;
        int j = 0;
        while (j < s.length())
        {
            mp[s[j]]++;
            if (mp.size() < k)
            {
                j++;
            }
            else if (mp.size() == k)
            {
                mx = max(mx, j - i + 1);
                j++;
            }
            else if (mp.size() > k)
            {
                while (mp.size() > k)
                {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};
