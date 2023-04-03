//Count number of subarrays with given xor K  - GFG

//Approach 1 : Using three loops 
//Time Complexity = O(N^3)
//Space Complexity = O(1)


//Approach 2 : Using two loops 
//Time Complexity = O(n^2)
//Space Compleity  = O(1)

//Approach 3 : Using prefix XOR 
//Time Complexity = O(N)
//Space Complexity = O(N)

class Solution{
    public:
    int subsetXOR(vector<int>arr , int N , int K){
        int count = 0 ;
        int xorr = 0;
        unordered_map<int ,int> mp;
        for(int i = 0 ; i < N ; i++){
            xorr = xorr ^ arr[i];
            if(xorr == K){
                count++;
            }

            if(mp.find(xorr^K) != mp.end()){
                count += mp[xorr^K] ;
            }

            mp[xorr] ++ ;
        }
        return count ;
    }
};