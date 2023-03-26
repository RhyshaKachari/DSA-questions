// Minimum Cost of ropes - GFG

// Time Complexity =  O(n log n )
// Space Complexity  = O(n)

class Solution
{
public:
    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for (long long i = 0; i < n; i++)
        {
            minHeap.push(arr[i]);
        }
        long long cost = 0;
        while (minHeap.size() >= 2)
        {
            long long first = minHeap.top();
            minHeap.pop();
            long long second = minHeap.top();
            minHeap.pop();
            cost = cost + first + second;
            minHeap.push(first + second);
        }
        return cost;
    }
};
