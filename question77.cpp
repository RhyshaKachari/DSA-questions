//Quick Left Rotation - GFG
//Approach 1 : Reversal Algo
//Time Complexity = O(N)
//Space Complexity = O(1)


class Solution{

public:
void reverse(int arr[] , int low , int high){
while(low<=high){
int temp = arr[low];
arr[low] = arr[high];
arr[high]= temp;
low++;
high--;
}
}

void leftRotate(int arr[], int k, int n) 
{ int ki = k%n;
 reverse(arr , 0 , ki-1);
reverse(arr, ki , n-1);
reverse(arr , 0 , n-1);
}

};

