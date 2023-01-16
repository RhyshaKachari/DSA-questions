//Search in a Rotated Array - GFG
//Time Complexity : O(log n)
//Space Complexity : O(1)

class Solution{
    public:
    int search(int a[] , int  l , int  h  , int k){
        while(l<= h ){
            int mid = (l+ h )>>1;
            if(a[mid] == k){
                return mid;
            }
            if(a[l] <= a[mid]){
                if(k>= a[l] && k<= a[mid]){
                    h = mid -1;
                }
                else{
                   l = mid +1;
                }
            }
            else{
                if(a[mid] <= k && a[h]>= k){
                    l = mid +1;
                }
                else{
                    h = mid -1;
                }
            }
        }
        return -1;
    }
};