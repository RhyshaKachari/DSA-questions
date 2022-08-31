// First and Last Position of an Element In Sorted Array
//code studio

// Array
#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &arr, int n, int k)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] < k)
        {
            start = mid + 1;
        }
        else if (arr[mid] > k)
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int lastOccurence(vector<int> &arr, int n, int k)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (k < arr[mid])
        {
            end = mid - 1;
        }
        else if (k > arr[mid])
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }
    return ans;
}

void firstAndLastPosition(vector<int> &arr ,int n , int k){
pair<int,int> p ;
p.first = firstOccurence(arr , n , k);
p.second = lastOccurence(arr , n , k);
cout<<p.first<<" "<<p.second<<endl;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        int key;
        cin >> key;

        firstAndLastPosition(arr , n , key);
    }

    return 0;
}