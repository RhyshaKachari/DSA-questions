//First Repeating Element
//Expected Time Complexity: O(n)
//Expected Auxilliary Space: O(n)

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
unordered_map<int , int> umap;
for (int i = 0 ; i < n ; i++){
int key = arr[i] ;
umap[key]++;
}

for(int i = 0 ; i < n ; i++){
int key = arr[i];
if(umap[key]!=1){
return i+1;}}
return -1;

  // code here
    }
};