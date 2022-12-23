//Merge Sort - GFG 
//Time Complexity = O(nlog n)
//Space Complexity = O(n)
//Auxillary Space = O(n)

class Solution
{
    public:
    void merge(int arr[], int l, int mid, int r)
    {
        int i = l ;        
        int j = mid + 1;   
        int f = l ;        
        int temp[100000] ; 

        //storing elements in the temporary array in a sorted manner//

        while (i <= mid && j <= r) {
            if (arr[i] < arr[j]) {
                temp[f] = arr[i]  ;
                i++ ;
            }
            else {
                temp[f] = arr[j]  ;
                j++ ;
            }
            f++ ;
        }

        // if elements on the left half are still left //

        if (i > mid) {
            while (j <= r) {
                temp[f] = arr[j]  ;
                f++ ; j++ ;
            }
        }
        else {
            //  if elements on the right half are still left //
            while (i <= mid) {
                temp[f] = arr[i]  ;
                f++ ; i++ ;
            }
        }

        // transfering all elements from temporary to arr //
        for (int f = l ; f <= r; f++) {
            arr[f] = temp[f] ;
        }
    }


    public:
    void mergeSort(int arr[], int l, int r)
    {if(l>=r){return;}
int mid  = l + (r-l)/2;
mergeSort(arr , l , mid);
mergeSort(arr , mid+1 , r);
merge(arr, l , mid, r);
 
        //code here
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}