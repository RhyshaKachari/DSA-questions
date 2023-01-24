// Sum of elements between k1'th and k2'th smallest elements
// Time Complexity = O(n log n)
// Space Complexity = O(n)

class Solution
{
public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2)
    {
        priority_queue<long long int> pq;
        for (int i = 0; i < N; i++)
        {
            pq.push(A[i]);
        }
        long long sum = 0;
        while (pq.size() > = K2)
        {
            pq.pop();
        }

        while (pq.size() > K1)
        {
            sum = sum + pq.top();
            pq.pop();
        }
        return sum;
    }
};
