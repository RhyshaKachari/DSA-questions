// Sum of Middle Elements of two sorted arrays

// Approach 1 : Using sort function in the merged array
// Time Complexity : O(2*n log 2*n)
// Space Complexity : O(26) = O(1)

// Approach 2 : Make a merged sorted array using if else conditions and return arr[n-1]+arr[n]

class Solution
{
public:
    int findMidSum(int ar1[], int ar2[], int n)
    {
        int k = 0;
        int j = 0;
        int i = 0;
        int arr[2 * n];
        while (j < n && k < n)
        {
            if (ar1[j] <= ar2[k])
            {
                arr[i++] = ar1[j++];
            }
            else
            {
                arr[i++] = ar2[k++];
            }
        }
        if (j < n)
        {
            arr[i++] = ar1[j++];
        }
        if (k < n)
        {
            arr[i++] = ar2[k++];
        }
        return arr[n - 1] + arr[n];
    }
};

// Approach 3 : Using counter variable

class Solution
{
public:
    int findMidSum(int ar1[], int ar2[], int n)
    {
        int k = 0;
        int j = 0;
        int i = 0;
        int cnt = 0;
        // int arr[2 * n];
        while (j < n && k < n)
        {
            if (ar1[j] <= ar2[k])
            {
                arr[i++] = ar1[j++];
            }
            else
            {
                arr[i++] = ar2[k++];
            }
        }
        if (j < n)
        {
            arr[i++] = ar1[j++];
        }
        if (k < n)
        {
            arr[i++] = ar2[k++];
        }
        return arr[n - 1] + arr[n];
    }
};

// Approach 4 : Using Binary Search

// Time Complexity  = O(log n)
// Space Complexity = O(1)

class Solution
{
public:
    int findMidSum(int ar1[], int ar2[], int n)
    {
        int low = 0;
        int high = n;
        while (low <= high)
        {
            int cut1 = (low + high) >> 1;
            int cut2 = n - cut1;

            int l1 = (cut1 == 0 ? INT_MIN : ar1[cut1 - 1]);
            int l2 = (cut2 == 0 ? INT_MIN : ar2[cut2 - 1]);
            int r1 = (cut1 == n ? INT_MAX : ar1[cut1]);
            int r2 = (cut2 == n ? INT_MAX : ar2[cut2]);

            if (l1 <= r2 && l2 <= r1)
            {
                return max(l1, l2) + min(r1, r2);
            }

            else if (l1 > r2)
            {
                high = cut1 - 1;
            }
            else
            {
                low = cut1 + 1;
            }
        }
        return 0;
    }
};