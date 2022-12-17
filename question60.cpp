//Union of two arrays - GFG
//Expected Time Complexity : O((n+m)log(n+m))
//Expected Auxilliary Space : O(n+m)

class Solution{
public:
//Function to return the count of number of elements in union of two arrays.
int doUnion(int a[], int n, int b[], int m)  {
unordered_set<int> uset ;
for(int i = 0 ; i < n ; i ++){
uset.insert(a[i]);
}
for(int i = 0 ; i < m ; i++){
uset.insert(b[i]);
}
int siz = uset.size();
return siz;
 //code here
    }
};