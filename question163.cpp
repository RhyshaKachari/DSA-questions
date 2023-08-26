// Search in a Rotated Array - GFG
// Time Complexity : O(log n)
// Space Complexity : O(1)

int search(vector<int> &arr, int n, int k)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        // left array sorted
        else if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // right array is sorted
        else
        {
            if (arr[mid] < k && k <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
