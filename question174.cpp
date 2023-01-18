// Nearly Sorted - GFG
// Time Complexity = O(n log k)
// Space Complexity = O(n)

class Solution
{
public:
    vector<int> nearlySorted(int arr[], int num, int K)
    {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i <= K; i++)
        {
            pq.push(arr[i]);
        }
        for (int i = K + 1; i < n; i++)
        {
            ans.push_back(pq.top());
            pq.pop();
            pq.push(arr[i]);
        }
        while (pq.size() > 0)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
