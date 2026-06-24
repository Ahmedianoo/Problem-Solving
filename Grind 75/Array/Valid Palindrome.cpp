#include <iostream>
#include <vector>
    
using namespace std;

bool isAlphanumeric(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return true;
    return false;    
}

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;
    
    while(left < right){

      if(!isAlphanumeric(s[left])){
        left++;
        continue;
      }

      if(!isAlphanumeric(s[right])){
        right--;
        continue;
      }      
        
      if(tolower(s[left]) != tolower(s[right])){
        return false;
      } 

      left++;
      right--;

    }

    return true;
}