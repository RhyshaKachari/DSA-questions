//Number of 1 Bits - Easy
//Leetcode -    Bit Manipulation
class Solution {
public:
   
int hammingWeight(uint32_t n) {
int count = 0;
while(n!=0){
if(n%2==1)
{
count ++;
}
n= n>>1;
}
return count;

    }
    
};
