// Winner of an election -GFG

// APPROACH 1
// Time Complexity = O(n logn)
// Space Complexity =O(n)

class Solution
{
public:
    vector<string> winner(string arr[], int n)
    {
        map<string, int> mp;
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        int max = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (max < it->second)
            {
                max = it->second;
            }
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second == max)
            {
                v.push_back(it->first);
                v.push_back(to_string(it->second));
                return v;
            }
        }
    }
};

// APPROACH 2
// Time Complexity =O(n)
// Space Complexity = O(n)

class Solution
{
public:
    vector<string> winner(string arr[], int n)
    {
        unordered_map<string, int> mp;
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        int max = 0;
        string name = "";
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            string key = it->first;
            int val = it->second;

            if (max < val)
            {
                max = val;
                name = key;
            }
            else if (max == val)
            {
                if (name > key)
                {
                    name = key;
                }
            }
        }
        v.push_back(name);
        v.push_back(to_string(max));
        return v;
    }
};
