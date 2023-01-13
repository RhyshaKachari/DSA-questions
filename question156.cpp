//Rotate by 90 degree - GFG
//Time Complexity = O(N^2)
//Space Complexity = O(1)

class Solution{
public:
void rotateby90(vector<vector<int>> &matrix , int n ){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            swap(matrix[i][j] , matrix[j][i]);
        }
    }

    for(int i = 0 ; i < n/2 ; i++){
        for(int j = 0 ; j < n ; j++){
            swap(matrix[i][j] , matrix[n-i-1][j]);
        }
    }
} 

};