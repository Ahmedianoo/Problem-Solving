#include <iostream>
#include <stack>
#include <string>

using namespace std;


// time: O(n), space: O(n)
int calculate(string s) {
    int i = 0;
    int sign = 1;
    int result = 0;

    stack<pair<int, int>> st;
    
    while(i < s.size()){
        if(isdigit(s[i])){
            int num = 0;

            while(i < s.size() && isdigit(s[i])){
                num = 10 * num + sign * (s[i] - '0');
                i++;
            }

            result += num;
        }
        else if(s[i] == '-'){
            i++;
            sign = -1;
        }
        else if(s[i] == '+'){
            i++;
            sign = 1;           
        }
        else if(s[i] == ' '){
            i++;
        }        
        else if(s[i] == '('){
            st.push({result, sign});
            
            i++;
            result = 0;
            sign = 1;
        }
        else if(s[i] == ')'){
            auto [prevResult, prevSign] = st.top();
            st.pop();
            
            result = prevResult + prevSign * result;
            i++;
        }        
    }

    return result;
}

// time: O(n), space: O(n)
int calculate(string s) {
    int i = 0;
    int currSum = 0;
    return evaluate(s, i);
}


int evaluate(string& s, int& i){
    int currSum = 0;
    int sign = 1;


    while(i < s.size()){
        if(isdigit(s[i])){
            int num = 0;
            while(i < s.size() && isdigit(s[i])){
                num = 10 * num + sign * (s[i] - '0');
                i++;
            }

            currSum += num;
        }
        else if(s[i] == '('){
            i++;
            int val = evaluate(s, i);
            currSum += sign * val;            
        }
        else if (s[i] == ')'){
            i++;
            return currSum;
        }
        else if(s[i] == '-'){
            i++;
            sign = -1;
        }
        else if(s[i] == '+'){
            i++;
            sign = 1;           
        }
        else if(s[i] == ' '){
            i++;
        }
    }

    return currSum;
}