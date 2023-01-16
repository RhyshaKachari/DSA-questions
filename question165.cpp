// Ceil The Floor - GFG
// Time Complexity = O(log n)
// Space Compelxity = O(1)

int getceil(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
