// Merge Without Extra Space - GFG

// Approach 1 : Optimal Approach
// Time Complexity = O(N*M)
// Space Complexity = O(1)

class Solution
{
public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int i, j, k;
        for (i = 0; i < n; i++)
        {

            // if condition satisfies
            if (arr1[i] > arr2[0])
            {
                long long int temp = arr1[i];
                arr1[i] = arr2[0];
                arr2[0] = temp;
            }

            // now sorting arr2
            long long int first = arr2[0];
            for (k = 1; k < m && first > arr2[k]; k++)
            {
                arr2[k - 1] = arr2[k];
            }
            arr2[k - 1] = first;
        }
    }
};

// Approach 2 : GAP method
//Time Complexity = O((n+m) log (n+m))
//Space Complexity = O(1)


class Solution
{
public:
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int gap = ceil((float)(n + m) / 2);
        while (gap > 0)
        {
            int i = 0;
            int j = gap;
            while (j < (n + m))
            {
                if ((j < n) && arr1[i] > arr1[j])
                {
                    swap(arr1[i], arr1[j]);
                }
                else if ((j >= n) && (i < n) && arr1[i] > arr2[j - n])
                {
                    swap(arr1[i], arr2[j - n]);
                }
                else if ((j >= n) && (i >= n) && arr2[i - n] > arr2[j - n])
                {
                    swap(arr2[j - n], arr2[i - n]);
                }
                i++;
                j++;
            }
            if (gap == 1)
            {
                gap = 0;
            }
            else
            {
                gap = ceil((float)gap / 2);
            }
        }
    }
};
