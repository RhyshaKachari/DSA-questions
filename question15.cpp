// Leetcode - Easy
// Reverse bits
//Bit Manipulation
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res=0;
for(int i = 0 ;i<32; i++ ){
int bit = (n>>i)&1;
res =  (res<<1)| bit;}
return res;

    }
};