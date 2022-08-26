//Arrays  - Easy
//Intersection of Two Sorted Arrays -  code studio

#include<bits/stdc++.h>
using namespace std;
    
 vector<int> findArray(vector<int> &arr1 , int n , vector<int> &arr2 , int m) {
  int i = 0 ;
  int j = 0;
  vector<int> ans ;
  while (i<n && j <m)
  {
   if(arr1[i] == arr2[j]){
    ans.push_back(arr1[i]);
    i++;
    j++;
   }
   else if(arr1[i]<arr2[j])
   {
    i++;
   }
   else if (arr1[i]>arr2[j])
   {
    j++;
    }
   }
   return ans; 
   }

void print(vector<int> &v){
 for(auto value : v){
    cout<<value<<" ";
 }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
       int n , m ;
       cin>>n>>m;
       vector<int> arr1 , arr2 ;
       for (int i = 0; i < n; i++)
       {int x;
       cin>>x;
       arr1.push_back(x);
       }
       for (int i = 0; i < m; i++)
       {
        int x ;
        cin>>x;
        arr2.push_back(x);
       }

       vector<int> ans =  findArray(arr1 , n , arr2 , m);
      print(ans);
    }
    
return 0;
}