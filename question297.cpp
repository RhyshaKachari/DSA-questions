// Valid Anagram - Leetcode

// Time Complexity - O(|s| + |t|)
// Space Complexity - O(Number of distinct characters)

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, int> mp;
        for (auto ch : s)
        {
            mp[ch]++;
        }
        for (auto ch : t)
        {
            if (mp.find(ch) != mp.end())
            {
                mp[ch]--;
                if (mp[ch] == 0)
                {
                    mp.erase(ch);
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};