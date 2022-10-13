//Reverse and Array through recursion
//Approach -1

// #include<bits/stdc++.h>
// using namespace std;

// void printArray(vector<int> &arr){
//   for(int i =0;i<arr.size() ; i++){
//     cout<<arr[i]<<" ";
//   }
//   cout<<endl;
//   return;
// }

// void insert(vector<int> &arr ,int n){
// if(arr.size()==0){
//   arr.push_back(n);
//   return;
// }
// int val = arr[arr.size()-1];
// arr.pop_back();
// insert(arr,n);
// arr.push_back(val);
// return ;
// }

// void reverseArray(vector<int> &arr ){
//  if(arr.size()==0){
//     return ; 
//  }
//  int temp = arr[arr.size() -1];
//  arr.pop_back();
//  reverseArray(arr); 
//   insert(arr ,temp);
// return ;

//  }

// int main(){
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
//     vector<int> arr ;
//     int n ;
//     cin>>n;
//     for (int  i = 0; i < n; i++)
//     {
//       int x; 
//       cin>>x;
//       arr.push_back(x);

//     }
//    reverseArray(arr);
//    printArray(arr);
    
// return 0;
// }



//Approach 2
#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &v , int l ,int r){
 if (l>=r)
 {
 return;
 }
 swap(v[l], v[r]);
 reverseArray(v,l+1 ,r-1);
 return;
 } 
  
  void printArray(vector<int> &v){
  for (int i = 0; i < v.size(); i++)
  {
   cout<<v[i]<<" ";
  }
  cout<<endl;
  return;
}
  
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int n;
  cin>>n;
  vector<int> v ;

 while (n--)
 {
  int x;
  cin>>x;
  v.push_back(x);
 }
 
 reverseArray(v,0,n-1);
 printArray(v);
  
return 0;
}