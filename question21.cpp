//Single Number III
//Medium
class Solution {
public:
vector<int> singleNumber(vector<int>& nums) {
   int xo = 0;
    
    for(int i=0;i<nums.size();i++) {
        
        xo = xo ^ nums[i];
    }
    
    int count = 0;
    while(xo != 0) {
        
        if(xo & 1) {
            
            break;
        }
        
        count++;
        
        xo = (xo >> 1);
    }
    
    vector<int>ans;
    int xor1 = 0;
    int xor2 = 0;
    
    for(int i=0;i<nums.size();i++) {
        
        int mask = 1 << count;
        
        if(nums[i] & mask) {
            
            xor1 = xor1 ^ nums[i];
        }
        else {
            
            xor2 = xor2 ^ nums[i];
        }
    }
    
    
    ans.push_back(xor1);
    ans.push_back(xor2);
    
    return ans;
}
};
