//Arrays
//Swap Two Numbers - Easy

#include<bits/stdc++.h>
using namespace std;
 pair<int,int> swap(pair<int,int> &pr) {
int temp = pr.first;
pr.first = pr.second;
pr.second = temp;
return pr;
   } 
    
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        pair<int , int> pr ;
        cin>>pr.first>>pr.second;
        swap(pr);
        cout<<pr.first<<" "<<pr.second;
    }
    
return 0;
}