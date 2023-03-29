// Row with max 1s - GFG

// Time Complexity = O(n log m)
// Space Complexity = O(1)

class Solution
{
public:
    int noOfOnes(vector<int> &v, int m)
    {
        int low = 0;
        int high = m - 1;
        int res = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (v[mid] == 1)
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (res == -1)
        {
            return 0;
        }
        else
        {
            return (m - res);
        }
    }

    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int mx = -1;
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            int num = noOfOnes(arr[i], m);
            if (num == 0)
            {
                continue;
            }
            if (mx == num)
            {
                continue;
            }
            mx = max(mx, num);
            if (mx == num)
            {
                ans = i;
            }
        }
        return ans;
    }
};