#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

// time: O(n), space: O(n)
int evalRPN(vector<string>& tokens) {
    stack<int> operands;

    for(string t : tokens){
        if(t == "+" || t == "-" || t == "*" || t == "/"){
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();

            int result;

            if(t == "+"){
                result = a + b;
            } else if(t == "-") {
                result = a - b;
            }  else if(t == "*"){
                result = a * b;
            }   else if(t == "/"){
                result = a / b;
            } 
            
            operands.push(result);
        }else{
            operands.push(stoi(t));
        }
    }

    return operands.top();
}