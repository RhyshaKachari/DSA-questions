//Letter Case Permutation - LEETCODE
//MEDIUM

class Solution {
public:
    void solve(string inp ,string out ,vector<string> &v){

//base condition
if(inp.length() == 0){
v.push_back(out);
return;
}

if(isalpha(inp[0])){
string op1 = out;
string op2 = out;
op1.push_back(tolower(inp[0]));
op2.push_back(toupper(inp[0]));
inp.erase(inp.begin() + 0);
solve(inp , op1 , v);
solve(inp , op2 , v);
return;
}
else{
string op1 = out;
op1.push_back(inp[0]);
inp.erase(inp.begin() + 0);
solve(inp , op1 , v);
return;
}}

    vector<string> letterCasePermutation(string s) {
        string inp = s;
string out = "";
vector<string> v ;
solve(inp , out , v);
return v;}
 
    
};