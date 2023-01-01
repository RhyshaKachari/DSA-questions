//Graphs and Vertices - GFG
//Time Complexity = O(1)
//Space Complexity = O(1)

class Solution {
  public:
    long long count(int n) {
        long long a = pow(2 , (n*(n-1)/2));
        return a;
    }
};
