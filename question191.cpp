// First negative integer in every window of size k - GFG

// Time Complexity : O(n)
// Space Complexity : O(k)

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    vector<long long> v;
    queue<int> q;
    long long int i = 0;
    long long int j = 0;
    while (j < N)
    {
        if (A[j] < 0)
        {
            q.push(A[j]);
        }
        if (j - i + 1 < K)
        {
            j++;
            continue;
        }
        else if (j - i + 1 == K)
        {
            if (!q.empty())
            {
                v.push_back(q.front());
            }
            else
            {
                v.push_back(0);
            }
            if (A[i] < 0)
            {
                q.pop();
            }
            i++;
        }
        j++;
    }
    return v;
};