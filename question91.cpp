//Implement Stack using array - GFG
//Time Complexity = O(1)
//Space Complexity = O(1)

class Solution{
void MyStack :: push(int x){
top++;
arr[top] = x ;
}
int MyStack :: pop(){
if(top == -1){
return -1;
}
else {
int x = arr[top];
top--;
return x ;}
}
}

