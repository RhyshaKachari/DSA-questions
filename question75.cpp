//Remove duplicate elements from sorted array - GFG

//Approach 1
//Time Complexity = O(Nlog N) +O(N)
//Space Complexity = O(N)

class Solution{
public:
int remove_duplicate(int a[],int n){
 set<int> s;
for(int i = 0 ; i < n ; i++){
s.insert(a[i]);
}
 int j= 0;
 for (int x: s) {
    a[j++] = x;
  }
  int k = s.size();
  return k;
    }
};


//Approach 2 - Two Pointer
//Time Complexity = O(N)
//Space Complexity = O(1)

class Solution{
public:
int remove_duplicate(int arr[] , int n ){
int i = 0 ; 
for(int j = 1 ; j < n ; j ++){
if(arr[i] != arr[j]){
i++;
arr[i] = arr[j];
}
}
return i +1;
}
};
