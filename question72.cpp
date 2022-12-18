//2)Second Largest -GFG
//Approach 1: Sorting
//Time Complexity =O(nlog n)
//Space Complexity = O(1)

//When Duplicates don't exist
class Solution{
public:
int print2largest(int arr[] , int n){
sort(arr , arr +n);
return arr[n-2];
}
};

//Approach 2
//Time Complexity  = O(N)
//Space Complexity = O(1)

class Solution{
public:	
int print2largest(int arr[], int n) {
int large = INT_MIN ;
int large2 = INT_MIN;
for(int i = 0 ; i < n ; i++){
if(arr[i] > large){
large = arr[i] ;
}
}

for(int i =0 ; i  <n ; i ++){
if(arr[i] > large2 && arr[i] != large){
large2 = arr[i] ;}
}
if(large2 == INT_MIN && large != INT_MIN){
return -1;} //edge case

return large2;


	}
};

//Approach 3
//Time Complexity  = O(N)
//Space Complexity  = O(1)

class Solution{
public:
int print2largest(int arr[] , int  n){
int large = INT_MIN;
int large2 = INT_MIN;
for(int i = 0 ; i  <n ; i ++){
if(arr[i] > large){
large2 = large ;
large = arr[i] ;
}
else if(arr[i]>large2 && arr[i]<large){
large2 = arr[i];
}
}
if(large2 == INT_MIN && large != INT_MIN){
return -1;}
else return large2;
}
}; 
