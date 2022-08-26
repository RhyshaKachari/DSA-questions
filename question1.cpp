//Arrays
//Unique number of occurences  - Leetcode

#include<bits/stdc++.h>
using namespace std;
    
bool uniqueOccurences(vector<int> & arr){
    map<int ,int> mp;
    for ( auto x : arr)
    {
        mp[x] ++;
    }
    set<int> st;
    for ( auto it : mp)
    {
       if (st.count(it.second) > 0)
       {
        return false;
       
       }
        else st.insert(it.second);
    }
    return true;
}    
    
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int n ;
  cin>>n;
    vector<int> arr;
for (int i = 0; i < n; i++)
{int x;
 cin>>x;
 arr.push_back(x);
}

cout<<uniqueOccurences(arr);

}