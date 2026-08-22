#include <iostream>

using namespace std;

// time: O(n^2), space: O(1)
string longestPalindrome(string s) {
    int longestLeft = 0, longestRight = 0;

    for(int i = 0; i < s.size(); i++){
        int left = i - 1, right = i + 1;
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            if(right - left > longestRight - longestLeft){
                longestLeft = left;
                longestRight = right;
            }
            left--;
            right++;
        }

        left = 0, right = i + 1;
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            if(right - left > longestRight - longestLeft){
                longestLeft = left;
                longestRight = right;
            }
            left--;
            right++;
        }        
    }

    return s.substr(longestLeft, longestRight - longestLeft + 1);
}