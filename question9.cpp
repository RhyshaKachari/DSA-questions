//Peak Index in mountain array
//Leetcode - Medium
#include<bits/stdc++.h>
using namespace std;
    
int  peakIndexInMountainArray(vector<int> &arr){
    int start = 0;
    int end  = arr.size() -1;
    int mid = start + (end-start)/2;
    while (start<end)
    {
        if(arr[mid+1] >arr[mid]){
            start = mid+1;
        }
        else{
            end = mid;
        }
        mid = start + (end-start)/2;
        
    }return start;
    
}

    
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
      int n;
      cin>>n;
      vector<int> m_array;
      for (int i = 0; i < n; i++)
      {
       int x ;
       cin>>x;
       m_array.push_back(x);
      }
      cout<<peakIndexInMountainArray(m_array);
    }
    
return 0;
}