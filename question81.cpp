//NGR - Next Greater Element to Right (when circular array is not given) -  Aditya Verma
//Time Complexity = O(N)
//Space Complexity = O(N)


class Solution{
public:

vector<int> ngl(vector<int> nums){
vector<int> v;
stack<int> s;
int n = nums.size();
for(int i = n-1 ; i >= 0 ; i--){
if(s.size() == 0){
v.push_back(-1);
}
else if(s.size() >0 && s.top() > arr[i]){
v.push_back(s.top());
}
else if(s.size() > 0 && s.top() <= arr[i]){
while(s.size>0 && s.top() <= arr[i]){
s.pop() ;
}
if(s.size() == 0){
v.push_back(-1) ;
}
else {
v.push_back(s.top());
}
}
s.push(arr[i]);
}
reverse(v.begin() , v .end());
return v;
}
};
