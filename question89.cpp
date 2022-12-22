//Minimum Element in Stack with Extra Space
//Time Complexity = O(1)
//Space Complexity = O(N)

class MinStack{
public:
stack<int> s;
stack<int> ss;
MinStack(){}

void push(int a){
s.push(a);
if(ss.size() == 0 || ss.top()>a){
ss.push(a);
}
return;
}

int pop(int a){
if(s.size() == 0){
return -1;}
int ans = s.pop();
if(ss.top() == ans){
ss.pop();}
}
int getMin(){
if(ss.size() ==  0){
return -1;}
else return ss.pop();
}
 
}


