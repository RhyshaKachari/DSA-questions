// Frequency Sort - Aditya Verma
// Time Complexity = O(n log k)
// Space Complexity = O(k)

class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto it : mp)
        {
            int freq = it.second;
            int ele = it.first;
            pq.push({freq, ele});
        }

        while (pq.size() > 0)
        {
            int freq = pq.top().first;
            int ele = pq.top().second;
            for (int i = 1; i <= freq; i++)
            {
                ans.push_back(ele);
            }
            pq.pop();
        }
        return ans;
    }
};