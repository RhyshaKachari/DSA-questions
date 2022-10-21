Find Smallest Letter Greater Than Target
Easy

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0 ;
int end = letters.size() - 1;
int res =0 ;
if(target < letters[start]){return letters[start];}
if(target > letters[end]){return letters[start];}
while(start<=end){
int mid = start + (end-start)/2 ;
 if(letters[mid] == target && mid ==letters.size() -1){return letters[0];}
else if(target < letters[mid]){ res = mid ;  end = mid -1;}
else{start = mid+1;}
}
return letters[res];

    }
};

