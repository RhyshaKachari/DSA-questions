// Longest Repeating Character Replacement -  Leetcode

// Time Complexity - O(|S|)
// Space Complexity - O(1)

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int i = 0;
        int j = 0;
        int ans = 0;
        int cnt[26] = {};
        for (j = 0; j < s.length(); j++)
        {
            cnt[s[j] - 'A']++;
            while (j - i + 1 - *max_element(cnt, cnt + 26) > k)
            {
                cnt[s[i] - 'A']--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};