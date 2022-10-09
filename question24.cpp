//Sum of Max And Min - CodeStudio
//Easy

#include <bits/stdc++.h> 
int sumOfMaxMin(int arr[], int n){
int maxi= INT_MIN;
int mini= INT_MAX;
for(int i = 0 ; i< n ; i++){
if(arr[i]<mini){
mini = arr[i];
}
if(arr[i]>maxi){
maxi =arr[i];
}
}
return mini+maxi;

}
