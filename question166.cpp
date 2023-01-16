// Search insert position of K in a sorted array
// Time Complexity = O(log n)
// Space Complexity = O(1)

class Solution
{
public:
    int searchInsertK(vector<int> Arr, int N, int k)
    {
        int low = 0;
        int high = N - 1;
        int res = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (Arr[mid] == k)
            {
                return mid;
            }
            else if (Arr[mid] < k)
            {
                res = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return res + 1;
    }
};