// Spiral Matrix - GFG

// Time Complexity - O(n*m)
// Space Complexity - O(1)

class Solution
{

public:
    int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int left = 0;
        int right = m - 1;
        int top = 0;
        int bottom = n - 1;
        vector<int> ans;
        int cnt = 0;
        while (left <= right && top <= bottom)
        {
            // right
            for (int i = left; i <= right; i++)
            {

                cnt++;
                if (cnt == k)
                {
                    return a[top][i];
                }
            }
            top++;
            // bottom
            for (int i = top; i <= bottom; i++)
            {

                cnt++;
                if (cnt == k)
                {
                    return a[i][right];
                }
            }
            right--;

            // left
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {

                    cnt++;
                    if (cnt == k)
                    {
                        return a[bottom][i];
                    }
                }
                bottom--;
            }

            // top
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    cnt++;
                    if (cnt == k)
                    {
                        return a[i][left];
                    }
                }
                left++;
            }
        }
        return -1;
    }
};