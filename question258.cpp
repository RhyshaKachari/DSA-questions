// Count Inversions in an array - Leetcode

// Approach 1 : Use two loops and find pairs which satisfy the condition
// Time Complexity  = O(n^2)
// Space Complexity = O(1)

// Approach 2 : Using the merge sort technique and checking for the pairs
// Time Complexity = O(n log n)
// Space Complexity = O(n)

class Solution
{
public:
    long long int merge(long long int arr[], long long int temp[], long long int left, long long int mid, long long int right)
    {
        long long int i = left;
        long long int j = mid;
        long long int k = left;
        long long int inv_count = 0;
        while (i <= mid - 1 && j <= right)
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                inv_count += mid - i;
            }
        }

        while (i <= mid - 1)
        {
            temp[k++] = arr[i++];
        }

        while (j <= right)
        {
            temp[k++] = arr[j++];
        }
        for (long long int i = left; i <= right; i++)
        {
            arr[i] = temp[i];
        }
        return inv_count;
    }

    long long int mergeSort(long long int arr[], long long int temp[], long long int left, long long int right)
    {
        long long int mid;
        long long int inv_count = 0;
        if (left < right)
        {
            mid = left + (right - left) / 2;
            inv_count += mergeSort(arr, temp, left, mid);
            inv_count += mergeSort(arr, temp, mid + 1, right);

            inv_count += merge(arr, temp, left, mid + 1, right);
        }

        return inv_count;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        long long int temp[N];
        long long int ans = mergeSort(arr, temp, 0, N - 1);
        return ans;
    }
};
