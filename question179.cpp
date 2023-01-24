// Minimum Cost of ropes - GFG
// Time Complexity - O(n log n)
// Space Complexity - O(n)

class Solution
{
public:
    long long minCost(long long arr[], long long n)
    {
        long long cost = 0;
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        while (pq.size() > 1)
        {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            cost = cost + first + second;
            pq.push(first + second);
        }
        return cost;
    }
};