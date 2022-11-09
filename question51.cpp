//Print the count of subsequences of an array whose sum is k
//Recursion

#include<bits/stdc++.h>
using namespace std;

int printS(int ind , int s , int sum , int arr[] , int n){
  //condition not satisfied
  //stricly done if array contains only positive integers
  if (s>sum)
  {
    return 0 ;
  }
  
   if(ind == n )
    {
     if(s == sum){return 1;}
    }
    else return 0;
    
    //take condition
    s += arr[ind];
    l = printS(ind+1 , s ,sum , arr , n);

    //not take condition
    s -= arr[ind];
    r = printS(ind+1 , s, sum , arr , n);
    return l+r;

}    
    
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int arr[] = {1,2,1};
    int n = 3;
    int sum = 2;
    return printS(0 , 0 , sum , arr, n );
return 0;
}