// Alternate positive and negative numbers - GFG

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

class Solution
{
public:
    void rearrange(int arr[], int n)
    {
        vector<int> pos;
        vector<int> neg;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 0)
                pos.push_back(arr[i]);
            else
                neg.push_back(arr[i]);
        }

        int i = 0;
        int j = 0;
        int k = 0;
        while (i < pos.size() && j < neg.size())
        {
            if (k % 2 == 0)
                arr[k++] = pos[i++];
            else
                arr[k++] = neg[j++];
        }

        while (i < pos.size())
            arr[k++] = pos[i++];
        while (j < neg.size())
            arr[k++] = neg[j++];
    }
};
