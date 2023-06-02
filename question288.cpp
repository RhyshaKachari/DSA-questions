// Ceil The Floor - GFG

// Time Complexity  - O(n)
// Space Complexity -  O(1)

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    int f = INT_MIN;
    int c = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return {x, x};
        }
        else if (arr[i] < x)
        {
            f = max(arr[i], f);
        }
        else
        {
            c = min(c, arr[i]);
        }
    }
    if (f == INT_MIN)
    {
        f = -1;
    }
    if (c == INT_MAX)
    {
        c = -1;
    }
    return {f, c};
}
