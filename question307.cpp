// Sorting Elements of an Array by Frequency - GFG

// Time Complexity - O(N)
// Space Complexity - O(N)

#include <bits/stdc++.h>;
using namespace std;
bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        unordered_map<int, int> mp;
        for (auto it : arr)
        {
            mp[it]++;
        }
        vector<pair<int, int>> count(mp.begin(), mp.end());
        sort(count.begin(), count.end(), cmp);

        for (auto it : count)
        {
            int freq = it.second;
            int num = it.first;
            while (freq--)
            {
                cout << num << " ";
            }
        }
        cout << endl;
    }
    return 0;
}