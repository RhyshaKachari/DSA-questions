//Array - Easy
//Pair sum
#include<bits/stdc++.h>
using namespace std;
    
    vector<vector<int>> pairSum (vector<int> &arr , int s){
       vector<vector<int>> ans ; 
       for (int i = 0; i < arr.size(); i++)
       {
       for (int j = i+1 ; j<arr.size(); j++)
       {
      if (arr[i] + arr[j] == s)
      {
       vector<int> temp;
       temp.push_back(min(arr[i] ,arr[ j]));
       temp.push_back(max(arr[i] , arr[j]));
       ans.push_back(temp);
      }
    }
}
       return ans; 
       }

void print(vector<vector<int>> &arr){
    for (int i = 0 ; i < arr.size() ; i++)
    {
        cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
    }
    // cout<<endl;
}
    
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int  n , s;
    cin>>n>>s;
    vector<int> v ;
    for (int i = 0; i < n; i++)
    {int x;
    cin>>x;
    v.push_back(x);
     }

    vector<vector<int>> arr =  pairSum(v , s) ;

    print(arr);

    
return 0;
}