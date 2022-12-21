//Stock Span Problem - GFG Aditya Verma;
//Time Complexity = O(N)
//Space Complexity = O(N)

class Solution
{
public:
vector <int> calculateSpan(int price[], int n)
{ vector<int> v;
stack<pair<int , int>> s;
for(int i = 0 ; i < n ;i++ ){
if(s.empty()){
v.push_back(-1) ;
}
else if(s.top().first > price[i]){
v.push_back(s.top().second);}
else{
while(!s.empty() && s.top().first <=price[i]){s.pop();}
if(s.empty()){
v.push_back(-1);}
else {v.push_back(s.top().second);}
}
s.push({price[i] , i});
}
for(int i =0 ; i < v.size() ; i++){
v[i] = i - v[i];
}
return v;
}
};

 
