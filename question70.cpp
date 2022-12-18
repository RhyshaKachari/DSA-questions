// Insertion Sort
//Time Complexity = O(N^2)
//Space Complexity = O(1)

class Solution{
void insertionSort(int arr[] , int n){
for(int i = 1 ; i < n ; i ++ ){
int curr = arr[i] ;
int j = i-1 ;
while( arr[j] > curr && j>= 0){
arr[j+1] = arr[ j];
j--;
}
arr[j+1] = curr;
}
}
};
