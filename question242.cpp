// Find all pairs with a given sum - GFG
// Time Complexity  = O(n log n)
// Space Complexity = O(1)

class Solution
{
public:
    vector<pair<int, int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        vector<vector<int>> ans;
        sort(A, A + N);
        sort(B, B + M);
        int i = 0;
        int j = M - 1;
        while (i < N && j >= 0)
        {
            if (A[i] + B[j] == X)
            {
                ans.push_back({A[i], B[j]});
                i++;
                j--;
            }
            else if (A[i] + B[j] < X)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return ans;
    }
};
