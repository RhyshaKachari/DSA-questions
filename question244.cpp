// Set Matrix - Leetcode

//Approach 1 : Brute Force
//Time Complexity = O(n* m) * O(n+m)
//Space Complexity = O(1)


// Approach 2 : Better Approach
// Time Complexity = 2*O(n*m)
// Space Complexity = O(n) + O(m)

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> rows(row, 1);
        vector<int> cols(col, 1);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (rows[i] == 0 || cols[j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Approach 3 : Most Optimal Approach
// Time Complexity = 2*O(n*m)
// Space Complexity = O(1)

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int col0 = 1;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0)
            {
                col0 = 0;
            }
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 1; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
            if (col0 == 0)
            {
                matrix[i][0] = 0;
            }
        }
    }
};