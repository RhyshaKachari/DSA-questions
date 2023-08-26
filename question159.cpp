// First and Last occurrences of x - GFG
// Time Complexity = O(log n)
// Space Complexity = O(1)

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

vector<int> find(int arr[], int n, int x)
{
    int first = firstOccurence(arr, n, x);
    int last = lastOccurence(arr, n, x);
    vector<int> ans;
    ans.push_back(first);
    ans.push_back(last);
    return ans;
}

// Approach 2 : Lower Bound and Upper Bound Concept
// Time Complexity - O(log n)
// Space Complexity - O(1)

#include <bits/stdc++.h>

int lower_bound(vector<int> &arr, int n, int k)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int upper_bound(vector<int> &arr, int n, int k)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = lower_bound(arr, n, k);
    if (first == -1 || arr[first] != k)
    {
        return {-1, -1};
    }
    else
    {
        return {first, upper_bound(arr, n, k) - 1};
    }
}