//Power Of Numbers - GFG
//Time Complexity = O(log N)
//Space Complexity = O(log N)

long long int m = 1e9 + 7;
class Solution{
    public:
    long long power(int N , int R){
        double ans = 1.0;
        long long nn = R ;
        while(nn){
            if(nn%2){
                ans = (ans * N)%m ;
                nn = nn -1;
            }
            else{
                N = N*N;
                nn = nn/2 ;
            }
        }
      return ans;
    }
};