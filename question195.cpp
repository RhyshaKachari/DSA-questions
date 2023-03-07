// Longest Sub- Array with sum K (when the array  consists of only positive elements) - Aditya Verma

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution
{
public:
    int lenOfLongSubarr(int Arr[], int N, int K)
    {
        int mx = 0;
        int i = 0;
        int j = 0;
        while (j < N)
        {
            sum = sum + arr[j];
            if (sum > k)
            {
                while (sum > k)
                {
                    sum = sum - arr[i];
                    i++;
                }
            }

            if (sum == k)
            {
                mx = max(mx, j - i + 1);
            }
            j++;
        }
        return mx;
    }
}