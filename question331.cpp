// Floyd Warshall - GFG
// Time Complexity - O(n^3)
// Space Complexity - O(1)

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // setting 1e9 where no path
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 1e9;
                }
                matrix[i][i] = 0;
            }
        }

        // now checkig for all the n nodes

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j], (matrix[i][k] + matrix[k][j]));
                }
            }
        }

        // to detect negative cycle
        // for(int i = 0 ; i < n ; i++){
        //     if(matrix[i][i] < 0){
        //         return something according to the question
        //     }
        // }

        // now redoing the impossible paths
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1e9)
                {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};