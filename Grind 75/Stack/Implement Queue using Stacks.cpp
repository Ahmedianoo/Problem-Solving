#include <iostream>
#include <stack>

using namespace std;


class MyQueue {
private:
stack<int> st1, st2;

void transfer(){
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
    }    
}

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            transfer();
        }
        int x = st2.top();
        st2.pop();
        return x;
    }
    
    int peek() {
        if(st2.empty()){
            transfer();
        }        
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};