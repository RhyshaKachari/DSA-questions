//Allocate Books
//Code Studio -  medium level
#include <bits/stdc++.h>
using namespace std;

bool ifPossible(vector<int> time, int n, int m, long long int mid)
{
  int dayCount = 1;
   long long  int chapCount = 0;
    for ( int i = 0; i < m; i++)
    {
        if (chapCount + time[i] <= mid)
        {
            chapCount += time[i];
        }
        else
        {
            dayCount++;
            if (dayCount > n || time[i] > mid)
            {
                return false;
            }
            chapCount= time[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector< int> time)
{
    long long int s = 0;
    long long int sum = 0;

    for (int i = 0; i < m; i++)
    {
        sum += time[i];
    }
    long long int e = sum;
    long long int ans = -1;
    
    while (s <= e)
    {  long long mid = s + (e - s) / 2;
        if (ifPossible(time, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
      
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long int m, n;
        cin >> n >> m;
        vector< int> v;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        cout << ayushGivesNinjatest(n, m, v) << endl;
    }

    return 0;
}