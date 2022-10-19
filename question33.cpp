//17) Find the majority element in an array - Leetcode
//Easy

Approach 1:Brute Force  
Time Complexity = O(n^2) , Space Complexity = O(1)

class Solution {
public:
int majorityElement(vector<int>& nums) {
int n = nums.size() ;
    
if(n ==1){return nums[0] ;}
int number = 0;
for(int i =0 ; i < n ; i++){
int count = 1 ;
for( int j = i+1 ; j<n ; j++){
if(nums[i] == nums[ j]){
count++;}
if(count > (n/2)){
number = nums[j];
break ;}
}
} 
return number;
 
    }
};

Remarks - forgot about the nums.size() = 1 condition

Approach 2 : Sorting 
Time Complexity = O(nlogn) , Space Complexity = O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin() , nums.end());
if(nums.size() ==1){
    return nums[0];
}
int count  = 1;
for(int i = 0 ; i < nums.size() ; i ++ ){
if(nums[i] == nums[i+1]){
count++;}
if(count > nums.size()/2){
return nums[i] ;}
if(nums[i] != nums[i+1]){
count = 1;}

}
return -1;
    }
};

Remarks - forgot about the nums.size() = 1 condition

Approach 3 : Using Hash Map
Time Complexity -  O(n) , Space - O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int , int> hash;
for(int num : nums){
if(hash.find(num) == hash.end()){
hash.insert({num , 1});
}
else {hash[num] ++ ;}
}


for(auto pair : hash){
if(pair.second > nums.size() /2)
return pair.first;
}
return -1;

    }
};

Approach 4 : Moore's Voting Algorithm
Time Complexity  = O(n) , Space Complexity =  O(1)

class Solution{
public:
int majorityElement(vector<int> &nums){
int ans = 0;
int count  = 1;
for(int i = 1 ; i < nums.size() ; i++){
if(nums[i] == nums[ans]){
count ++ ;}
else {count -- ;}
if(count == 0){
ans = i;
count =1;}
}
int c = 0;
for(int i = 0 ; i< nums.size() ; i ++){
if(nums[i] == nums[ans]){
c ++;}
}
if(c > nums.size()/2){
return nums[ans];}

return -1;
}
};


