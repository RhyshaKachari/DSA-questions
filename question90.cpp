//Min Stack - Leetcode Aditya Verma 
//Time Complexity = O(1)
//Space Compelxity= O(1)


class MinStack {
public:
long long int minElement = -1000;
stack<long long int> s;

    MinStack() {
        
    }
    
void push(long long int val) {
if(s.size() == 0){
s.push(val);
minElement = val;
}
else{
if(val >= minElement){
s.push(val);
}
else{
s.push(2*val - minElement);
minElement = val;
}

    } }
    
    void pop() {
        if(s.size() == 0){
return ;
}
else{
if(s.top() >= minElement){s.pop() ;}
else{ 
minElement =  2*minElement - s.top();
s.pop() ;}
}

    }
    
    int top() {
       if(s.size() == 0){
return -1;}
else {
if(s.top() >= minElement){return s.top();}
else return minElement;
}
 
    }
    
    int getMin() {
        if(s.size() == 0){
return -1;}
else return minElement;

    }
};