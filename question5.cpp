//Array - Reverse Array - code studio easy
//Brute force method 
#include<bits/stdc++.h>
using namespace std;

 void reverseArray(vector<int> &arr , int m){
  int i = m+1 ;
  int j = arr.size() - 1;
  while (i < j)
  {
   swap(arr[i] , arr[j]);
   i++;
   j--;
  }
  for (int k = 0; k <arr.size(); k++)
       {cout<<arr[k]<<" ";
       }
       
 }   
    
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
   int t;
   cin>>t;
   while (t--)
     {
       vector<int> arr ;
       int n;
       cin>>n;
       for (int i = 0; i < n; i++)
       {
       int x;
       cin>>x;
       arr.push_back(x);
       }
       
       int m;
       cin>>m;
       reverseArray(arr , m);
       
     }
    
return 0;
}