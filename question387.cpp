// Assign Cookies - Leetcode
// Time Complexity - O(max(s1logs1 , s2logs2))
// Space Complexity - O(1)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int s1 = g.size() ;
        int s2 = s.size() ;
        int i = 0 ; 
        int j = 0;
        int cnt = 0 ;
        while(i <s1 && j < s2){
            if(s[j] >= g[i]){
                cnt++ ;
                i++ ;
                j++ ;
            }
            else{
                j++ ;
            }
        }
        return cnt ;
    }
};