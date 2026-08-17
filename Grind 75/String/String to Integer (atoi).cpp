#include <iostream>

using namespace std;

// time: O(n), space: O(1)
int myAtoi(string s) {
    int i = 0;

    while(i < s.size() && s[i] == ' '){
        i++;
    }

    if(i == s.size()) return 0;

    int sign = 1;

    if(s[i] == '-'){
        sign = -1;
        i++;
    }
    else if(s[i] == '+') {
        i++;
    }

    if(i == s.size()) return 0;

    int limit = sign == 1 ? 7 : 8;
    int result = 0;
    
    while(i < s.size() && ('0' <= s[i] && s[i] <= '9')){
        int digit = s[i] - '0';

        if(result > INT_MAX / 10 ||
            (result == INT_MAX / 10 && digit >= limit)){
            return sign == 1 ? INT_MAX : INT_MIN; 
        }

        result = result * 10 + digit;
        i++;
    }
    
    return sign * result;  
}