#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;


bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> closeToOpen;

    closeToOpen['}'] = '{';
    closeToOpen[']'] = '[';
    closeToOpen[')'] = '(';

    // there are two options either to have open or close
    // you got open, push
    // you got close, pop with conditions
    for(int i = 0; i < s.size(); i++){
        // here we are checking if this is closing, if yes we check that the stack has something
        // and its top maps with the current char, if yes then pop from the stack
        if(closeToOpen.count(s[i])){
            if(!st.empty() && st.top() == closeToOpen[s[i]]){
                st.pop();
            }else{
                return false;
            }
        }else{
            st.push(s[i]);
        }

    }

    if(st.empty()) return true;
    return false;
    
}



// time: O(n), memory: O(n)