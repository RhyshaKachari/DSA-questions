//Valid Palindrome - Leetcode
//Easy 

class Solution {
public:
bool isPalindrome(string s) {
    //pushing alphanumeric characters in the vector v
vector<int> v;
for(int i =0 ; i<s.size() ; i++){
if((s[i]>='0') && (s[i]<='9')){
v.push_back(s[i]);
}
else if((s[i] >= 'A') && (s[i]<= 'Z')){
v.push_back(s[i]-'A' + 'a');
}
else if((s[i] >= 'a') && (s[i]<='z')){
v.push_back(s[i]);
}
}

//making a new vector
vector<int> temp = v;

//now reversing the vector
int i =0 ;
int j  = v.size() - 1;
while(i<= j){
swap(v[i],v[j]);
i++;
j--;}

//now checking if it is a apalindrome
if(v == temp){return true;}
else{return false;}

 
    }
};