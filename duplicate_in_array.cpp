//Arrays - Easy 
//Duplicates in Array - code studio  
#include<bits/stdc++.h>
using namespace std;

int findDuplicates(vector<int> &arr){
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans^ arr[i];
    }
    for (int i = 1; i < arr.size(); i++)
    {
        ans = ans^ i;
    }
    return ans;
    
}
  
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t ;
    cin>>t;
    while (t--)
    {
       int n ;
       cin>>n;
       vector<int> arr ;
       for (int i = 0; i < n; i++)
       {int x;
       cin>>x;
       arr.push_back(x);

       }

       cout<<findDuplicates(arr)<<endl;
       
    }
    
return 0;
}