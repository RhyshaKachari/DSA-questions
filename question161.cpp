// Minimum element in a sorted and rotated array - GFG
// Time Complexity = O(log n)
// Space Complexity = O(1)

class Solution
{
public:
    int findMin(int arr[], int n)
    {
        int mini = INT_MAX;
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            if (arr[low] < arr[high])
            {
                mini = min(arr[low], mini);
                break;
            }
            int mid = low + (high - low) / 2;
            if (arr[low] <= arr[mid])
            {
                mini = min(arr[low], mini);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
                mini = min(arr[mid], mini);
            }
        }
        return mini;
    }
};