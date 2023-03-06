// Count Occurences of Anagrams - GFG

// Approach 1 : Using maps with sliding window concept
//  Time Complexity : O(n)
//  Space Complexity : O(n)

class Solution
{
public:
    int search(string pat, string txt)
    {
        int ans = 0;
        unordered_map<char, int> mp;
        int i = 0;
        int j = 0;
        int n = txt.size();

        // counting all the characters in the string pat
        for (auto c : pat)
        {
            mp[c]++;
        }
        int count = mp.size();
        int k = pat.size();
        while (j < n)
        {
            // calculation part
            if (mp.find(txt[j]) != mp.end())
            {
                mp[txt[j]]--;
                if (mp[txt[j]] == 0)
                {
                    count--;
                }
            }

            // window length is not achieved yet
            if (j - i + 1 < k)
            {
                j++;
            }

            // window length is achieved , find ans , slide the window
            else if (j - i + 1 == k)
            {
                // finding ans
                if (count == 0)
                {
                    ans++;
                }

                // sliding the window
                if (mp.find(txt[i]) != mp.end())
                {
                    mp[txt[i]]++;
                    if (mp[txt[i]] == 1)
                    {
                        count++;
                    }
                }

                i++;
                j++;
            }
        }
        return ans;
    }
};

// Approach 2 : Using hashing with sliding window
// Time Complexity : O(n)
// Space Complexity : O(26) or O(256)

class Solution
{
public:
    int search(string pat, string txt)
    {
   
        int arr[30] = {0}, rfr[30] = {0};
        for (int i = 0; i < pat.size(); i++)
        {
            arr[txt[i] - 'a']++;
            rfr[pat[i] - 'a']++;
        }
        int flag = 0, ans = 0;
        for (int i = 0; i < 30; i++)
        {
            if (arr[i] != rfr[i])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            ans++;
        }
        for (int i = pat.size(); i < txt.size(); i++)
        {
            arr[txt[i - pat.size()] - 'a']--;
            arr[txt[i] - 'a']++;
            flag = 0;
            for (int i = 0; i < 30; i++)
            {
                if (arr[i] != rfr[i])
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                ans++;
            }
        }
        return (ans);
    }
};