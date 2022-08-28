//Array 
//Sum or Product - Easy 
//Code studio

#include<bits/stdc++.h>
using namespace std;
   

long long int sumOrProduct(long long int n , long long int q){
long long int M = 1e9 + 7;
if (q==1)
{
   long long int ans =0;
    for (int i = 1; i <= n; i++)
    {
       ans += i;
       

    }return ans;
}else if(q==2)
{
   long long ans = 1;
   for (int i = 1; i <= n; i++)
   {
   ans = (ans*i)%M;  
  
    } return ans;
}
}

    
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
       int n ;
       cin>>n;
       int q;
       cin>>q;
    cout<<sumOrProduct(n, q)<<endl;
    }
    
return 0;
}