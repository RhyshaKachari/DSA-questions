// Sort  an array of 0s , 1s , 2s
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution
{
public:
    void sort012(int a[], int n)
    {
        int low = 0;
        int high = n - 1;
        int mid = low;
        while (mid <= high)
        {
            if (a[mid] == 0)
            {
                swap(a[mid], a[low]);
                mid++;
                low++;
            }
            else if (a[mid] == 1)
            {
                mid++;
            }
            else if (a[mid] == 2)
            {
                swap(a[mid], a[high]);
                high--;
            }
        }
    }
};