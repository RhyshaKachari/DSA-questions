//Leetcode Easy
//Power Of Four
//Bit Manipulation

class Solution {
public:
    bool isPowerOfFour(int n) {
     int fact = 0b01010101010101010101010101010101;
if(n>0 && (n&(n-1))==0 && (fact&n)>0){
return true;}
        
 else return false;}
};