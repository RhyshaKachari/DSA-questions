// Rotated - GFG
// Time Complexity = O(log n)
// Space Complexity = O(1)

class Solution
{
public:
    int findKRotation(int arr[], int n)
    {
        int mini = INT_MAX;
        int ans = -1;
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            if (arr[low] < arr[high])
            {
                if (arr[low] < mini)
                {
                    mini = min(arr[low], mini);
                    ans = low;
                }
                break;
            }

            int mid = low + (high - low) / 2;
            if (arr[low] <= arr[mid])
            {
                if (arr[low] < mini)
                {
                    mini = min(arr[low], mini);
                    ans = low;
                }
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
                if (arr[mid] < mini)
                {
                    mini = min(arr[mid], mini);
                    ans = mid;
                }
            }
        }
        return ans;
    }
};