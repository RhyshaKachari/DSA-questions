// K Closest Points to Origin - Leetcode
// Time Complexity = 	O(n log k)
// Space Complexity = O(k)

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        int n = points.size();
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
        {
            int key = (points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            pair<int, int> p = {points[i][0], points[i][1]};
            pq.push({key, p});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        while (pq.size() > 0)
        {
            vector<int> v;
            v.push_back(pq.top().second.first);
            v.push_back(pq.top().second.second);
            ans.push_back(v);
            pq.pop();
        }
        return ans;
    }
};
