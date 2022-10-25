First Bad Version - Leetcode
Easy 

class Solution{
public:
  int firstBadVersion(int n ){
int start = 1 ;
int end = n;
int res = 0;
while(start<=end){
int mid = start + (end-start)/2 ;
if(isBadVersion(mid) == 1){res = mid ; end = mid-1 ;}
else {start = mid +1;}
}
return res;
}
};
