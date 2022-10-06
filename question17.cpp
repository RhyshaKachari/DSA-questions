// Palindrome Number - Leetcode
//Easy
//Approach 1 - Brute force
class Solution{
public:
bool isPalindrome(int x){
long long int y = x; //making a copy of x so we don't
 actually change the number
int last = 0;
long long rev =0;
while(y!=0){
last = y%10;
rev = rev*10 + last;
y/=10;
}
if(rev != x || x<0){
return  false;}
return true;
}};

//issme rev ko long long isliye lerhe h kyuki
// number me hum sirf 10^8 tk ki hi values store 
//krskte .


// Approach 2- Convert num to string

// class Solution{
// public:
// bool isPalindrome(int x){
// string s = to_string(x);
// for(int i =0 ; i<n;i++){
// if(s[i] != s[n-i-1]){
// return false;}
// }
// return true;
// }
// };
