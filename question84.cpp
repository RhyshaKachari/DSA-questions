 //Nearest Smallest to Right - (when circular array is not given) Aditya Verma
//Time Complexity  = O(N)
//Space Complexity = O(N)

class Solution{
public:
vector<int> nsr(vector<int> &nums){
vector<int> v;
stack<int> s;
int n = nums.size() ;
for(int i = n-1 ; i>=0; i --){
int size = s.size();
if(size==0){
v.push_back(-1);
}
else if(size>0 && s.top() < arr[i]){
v.push_back(s.top());
}
else if(size>0 && s.top() >= arr[i]){
while(size>0 && s.top() >= arr[i]){
s.pop();}
if(size==0){v.push_back(-1);}
else {v.push_back(s.top());}
}
s.push(arr[i]);
}
reverse(v.begin() , v.end());
return v;
}
};

