//Printing the subsets of a string using recursion

//Used input output method of aditya verma
#include<bits/stdc++.h>
using namespace std;

void solve(string inp , string out){
    if (inp.length()== 0)
    {
        cout<<out<<endl;
        return;
    }
    string op1 = out;
    string op2 = out;
    op2.push_back(inp[0]);
    inp.erase(inp.begin()+0);
    solve(inp , op1);
    solve(inp,op2);
    return;
    
}    
    
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    string inp;
    cin>>inp;
    string out = " ";
    solve(inp ,out);
    
return 0;
}