// Allocate Books
/*Problem Statement
Given an array 'arr' of integer numbers .  where 'arr[i]' represents the number of pages in the 'i-th' book. There are  'm' number os students and the task is to allocate all the books to their students. Allocate books in such a way that:

1.Each student gets at least one book.
2. Each book should be allocated to a student.
3.Book allocation should be in a contiguous manner.

You have to allocate the book to 'm' students such that the maximum number of pages assigned to a student is minimum.

Example:
Let's consider 'n=4'(number of books) and 'm=2'(number of students
'arr = (10,20 ,30 ,40)'. */

#include <bits/stdc++.h>
using namespace std;


bool isPossible(vector<int> v ,int n , int m , int mid){
    int studentCount = 1;
   int pageCount  = 0;
    for (int i = 0; i < n; i++)
    { 
    if(pageCount + v[i] <= mid){
        pageCount += v[i];
    }
    else {
        studentCount++;
        if (studentCount > m || v[i]>mid)
        {
            return false;
        }
        
       pageCount += v[i];
        }
    }
     return true;
    }
    


int allocateBooks(vector<int> v, int n, int m)
{
    int s = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += v[i];
    }
    int e = sum;
    int ans  = -1;

    int mid = s + (e - s) / 2;
    while (s <= e)
    { 
        if (isPossible(v, n, m, mid))
        {  ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid =  s+ (e-s)/2;
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
        int n, m;
        cin >> n >> m;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }

        cout<<allocateBooks(v, n, m)<<endl;
    }

    return 0;
}