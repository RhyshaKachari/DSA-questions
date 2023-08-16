// Kth smallest element - GFG
// Time Complexity = O(n log k)
// Space Complexity = O(k)

class Solution
{
public:
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> maxH;
        for (int i = l; i <= r; i++)
        {
            maxH.push(arr[i]);
            if (maxH.size() > k)
            {
                maxH.pop();
            }
        }
        return maxH.top();
    }
};

// Approach 2 : Using quick selection method
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    int partition(vector<int> &arr, int left, int right)
    {
        int pivot = arr[left];
        int l = left + 1;
        int r = right;
        while (l <= r)
        {
            if (arr[l] < pivot && arr[r] > pivot)
            {
                swap(arr[r], arr[l]);
                l++;
                r--;
            }
            else if (arr[l] >= pivot)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        swap(arr[left], arr[r]);
        return r;
    }

    int findKthsmallest(vector<int> &arr, int k)
    {
        int n = arr.size();
        int z = n - k + 1;
        int left = 0;
        int right = n - 1;
        int zth;
        while (1)
        {
            int index = partition(arr, left, right);
            if (index == z - 1)
            {
                kth = arr[index];
                break;
            }
            else if (index < z - 1)
            {
                left = index + 1;
            }
            else
            {
                right = index - 1;
            }
        }
        return zth;
    }
}
