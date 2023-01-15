// Number of occurence - GFG
// Time Complexity = O(log n)
// Space Complexity = O(1)

class Solution
{
public:
    int firstOccurence(int arr[], int n, int x)
    {
        int low = 0;
        int high = n - 1;
        int res = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x)
            {
                res = mid;
                high = mid - 1;
            }
            else if (arr[mid] < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return res;
    }

    int lastOccurence(int arr[], int n, int x)
    {
        int low = 0;
        int high = n - 1;
        int res = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x)
            {
                res = mid;
                low = mid + 1;
            }
            else if (arr[mid] < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return res;
    }

    int count(int arr[], int n, int x)
    {
        int first = firstOccurence(arr, n, x);
        int last = lastOccurence(arr, n, x);
        if (first == -1)
        {
            return 0;
        }
        int count = last - first + 1;
        return count;
    }
};