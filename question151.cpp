// Pascal's Triangle II - Leetcode
// Time Complexity  = O(N^2)
// Space Complexity = O(N^2)

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        int n = rowIndex + 1;
        vector<vector<int>> r(n);
        for (int i = 0; i < n; i++)
        {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
            }
        }
        vector<int> ans;
        for (int j = 0; j < rowIndex + 1; j++)
        {
            ans.push_back(r[rowIndex][j]);
        }
        return ans;
    }
};