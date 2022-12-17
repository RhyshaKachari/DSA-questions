// Pairs with Positive Negative Values
// Time Complexity = O(nlog(n))
// Space Complexity = O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> PosNegPair(int a[], int n)
    {
        vector<int> v;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                v.push_back(a[i]);
            }
            else
                mp[a[i]]++;
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for (int i = (int)v.size() - 1; i >= 0; i--)
        {
            int key = abs(v[i]);
            if (mp[key] > 0)
            {
                ans.push_back(v[i]);
                ans.push_back(mp[key]);
                mp[key] -= 1;
            }
        }
        return ans;
    }
};