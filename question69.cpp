//Bubble Sort  -  GFG
//Time Complexity = O(N^2)
//Space Complexity = O(1)

class Solution{
public:
void bubbleSort(int arr[] , int n){
for(int i = 0 ; i < n-1 ; i ++){
for(int j = 0 ; j<n-i-1 ; j++){
if(arr[j]>arr[j+1]){
int temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
}
}
}
}
};
