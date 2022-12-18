//1)Largest Element in Array -gfg

//Approach 1 :Sorting

//Time Complexity  - O(Nlog N)
//Space Complexity - O(1)
class Solution{
public:
 int largest(vector<int> &arr , int n){
sort(arr.begin() , arr.end());
return arr[arr.size()-1] ;
}
};

//Approach 2 :  Max Variable
//Time Complexity  - O(N)
//Space Complexity - O(1)

class Solution{
public:
int largest(vector<int> &arr , int n ){
int max = 0;
for(int i = 0 ; i < arr.size() ; i++){
if(arr[i] > arr[max]){
max = i ;}
}
return arr[max] ;
}
};
