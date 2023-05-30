// Longest Substring with At Least K Repeating Characters - Leetcode

// Approach 1:
// Time Complexity = O(n^2)
// Space Complexity = O(1)

// Consider all the possible substrings and count the number of characters in each string and look for the longest possible substring with at least k repeating characters

// Approach 2 : Divide and conquer
// Time Complexity : O(n log n)
// Space Complexity : O(1)

class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int n = s.length();
        if (n == 0 || n < k)
        {
            return 0;
        }
        if (k <= 1)
        {
            return n;
        }

        unordered_map<char, int> mp;
        for (auto it : s)
        {
            mp[s[it] - 'a']++;
        }

        int l = 0;
        while (l < n && mp[s[l]] >= k)
        {
            l++;
        }
        if (l > n - 1)
        {
            return l;
        }
        int ls1 = longestSubstring(s.substr(0, l), k);
        while (l < n && mp[s[l]] < k)
        {
            l++;
        }
        int ls2 = longestSubstring(s.substr(l), k);
        return max(ls1, ls2);
    }
};