// Fruit into Baskets - Leetcode

// Time Complexity = O(n)
// Space Complexity  = O(1)

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int i = 0;
        int j = 0;
        int mx = 2;
        int N = fruits.size();
        if (fruits.size() == 1)
        {
            return 1;
        }
        unordered_map<int, int> mp;
        while (j < N)
        {
            mp[fruits[j]]++;
            // if(mp.size() < 2){
            //     j++;
            // }
            if (mp.size() <= 2)
            {
                mx = max(mx, j - i + 1);
                j++;
            }
            else
            {
                while (mp.size() > 2)
                {
                    mp[fruits[i]]--;
                    if (mp[fruits[i]] == 0)
                    {
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};