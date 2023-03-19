// N Queens - Leetcode

// Approach 1 :
// Time Complexity : O(n!)
// Space Complexity : O(n^@)

class Solution
{
public:
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        // checking for uppper diagonal
        int duprow = row;
        int dupcol = col;
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }

        // checking for the same row
        row = duprow;
        col = dupcol;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            col--;
        }

        // checking for lower diagonal
        row = duprow;
        col = dupcol;
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row++;
            col--;
        }
        return true;
    }

public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        solve(0, board, ans, n);
        return ans;
    }
};

// Approach 2:

// Time Complexity =  O(n!)
// Space Complexity = O(n^2)

class Solution
{
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (leftRow[row] == 0 && upperDiagonal[row + col] == 0 && lowerDiagonal[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiagonal[row + col] = 1;
                lowerDiagonal[n - 1 + col - row] = 1;
                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[row + col] = 0;
                lowerDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int row = 0; row < n; row++)
        {
            board[row] = s;
        }
        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};