//Find Smallest Letter Greater Than Target - Leetcode
//Time Complexity = O(log n)
//Space Complexity = O(1)

class Solution{
public:
char nextGreatestLetter(vector<char> &letters , char target){
   int low = 0;
   int high = letters.size() -1;
   if(target < letters[0] || target > letters[letters.size() -1]){
    return letters[0];
   }
   int res = -1 ;
   while(low <= high){
    int mid = low + (high-low)/2 ;
    if(letters[mid] == target){
        low = mid+1; 
    }
    else if(letters[mid] > target){
        res = mid;
        high = mid-1;
    }
    else{
        low = mid+1;
}
   }
   return letters[res];
}
};