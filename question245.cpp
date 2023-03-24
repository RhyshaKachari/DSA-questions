// Pascal's Triangle -  GFG

// Time Complexity = O(N^2)
// Space Complexity  = O(N^2)

class Solution
{
public:
    vector<ll> nthRowOfPascalTriangle(int n)
    {
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i].resize(i + 1);
            v[i][0] = v[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                v[i][j] = (v[i - 1][j - 1] + v[i - 1][j]) % 1000000007;
            }
        }
        vector<ll> ans;
        for (int i = 0; i < v[n - 1].size(); i++)
        {
            ans.push_back(v[n - 1][i]);
        }
        return ans;
    }
};