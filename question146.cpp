// Find Missing and Repeating  -  GFG
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution
{
public:
    vector<int> findTwoElement(int *arr, int n)
    {
        int x = 0;
        int y = 0;
        int xr = 0;
        for (int i = 0; i < n; i++)
        {
            xr = xr ^ arr[i];
        }
        for (int i = 1; i <= n; i++)
        {
            xr = xr ^ i;
        }
        int setBit = xr & ~(xr - 1);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] & setBit)
            {
                x = x ^ arr[i];
            }
            else
            {
                y = y ^ arr[i];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (i & setBit)
            {
                x = x ^ i;
            }
            else
            {
                y = y ^ i;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
            {
                cnt++;
            }
        }
        if (cnt)
        {
            return {x, y};
        }
        else
            return {y, x};
    }
};
