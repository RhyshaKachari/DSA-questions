//Recursive Bubble Sort -  GFG

class Solution
{
    public:
    void bubbleSort(int arr[], int n)
    {
     if(n==1){
      return;}
    int endIndex = n-1;
    for(int i = 0 ; i  <endIndex ; i++){
    if(arr[i] > arr[i+1]){
    int temp = arr[i] ; 
    arr[i]= arr[i+1] ;
    arr[i+1] = temp;
     }
   } 
   bubbleSort(arr , n-1);
    }
};
