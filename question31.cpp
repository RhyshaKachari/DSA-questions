//Generate Parentheses - Leetcode
//Medium

class Solution {
public:
   
    
void solve(int open , int close , string out , vector<string> &v){
if(open == 0 && close == 0){
v.push_back(out);
return;
}
if(open != 0){
string op1 = out;
op1.push_back('(');
solve(open-1 , close ,op1 , v);

}

if(close>open){
string op2 = out;
op2.push_back(')');
solve(open ,close-1 , op2 , v);

}

}

    
    
  vector<string> generateParenthesis(int n) {
int open = n;
int close = n ;
string out = "";
vector<string> v ;
solve(open , close, out , v);
   return v;
    }
};