// Find K closest Elements - Leetcode
// Time Complexity =  O(n log k)
// Space Complexity = O(log k )

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> v;
        priority_queue<pair<int, int>> maxH;
        for (int i = 0; i < arr.size(); i++)
        {
            maxH.push({abs(arr[i] - x), arr[i]});
            if (maxH.size() > k)
            {
                maxH.pop();
            }
        }
        while (maxH.size() > 0)
        {
            v.push_back(maxH.top().second);
            maxH.pop();
        }
        sort(v.begin(), v.end());
        return v;
    }
};
