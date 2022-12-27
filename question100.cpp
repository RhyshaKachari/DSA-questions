//Find the repeating and missing numbers - GFG
//Approach 1 :  Hashing
//Time Complexity = O(N)
//Space Complexity =O(N)

class Solution{
public:
vector<int> missing_repeated_number(vector<int> &nums){
int n = nums.size() +1;
vector<int>sub(n , 0);
for(int i =0 ; i < nums.size() ; i++){
sub[nums[i]]++;
}
vector<int> ans;
for(int i =1 ; i < sub.size() ; i++){
if(sub[i] == 0 || sub[i] >1){
ans.push_back();}
} return ans;

}
};

//Approach 2: Bit Manipulation
//Time Complexity = O(N)
//Space Complexity = O(1)

class Solution{
public:
vector<int> missing_repeated(vector<int> &nums){
int set = 0;
int xor = 0 ;
int x = 0 ;
int  y = 0;
for(int i = 0 ; i < nums.size() ; i++){
xor = xor^nums[i];
}
for(int i = 1 ; i <= nums.size() ; i++){
xor = xor^i;
}

//to find the rightmost set bit
set = xor&~(xor-1);

//dividing into two buckets
for(int i = 0 ; i < nums.size() ; i++){
if(set&nums[i]){
x = x^arr[i];}
else{y = y^nums[i];}
}

for(int i =1 ; i <= nums.size() ; i++){
if(set&i){
x = x^i ;}
else{
y = y ^i;}
}

int xcount = 0;
vector<int>ans;
for(int i = 0 ; i < nums.size() ; i++){
if(nums[i] == x){xcount++ ;}
}
if(xcount == 0){
ans.push_back(x);
ans.push_back(y);}

else{
ans.push_back(y);
ns.push_back(x);}

return ans;
}
};
