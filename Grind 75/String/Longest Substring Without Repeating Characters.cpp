#include <iostream>
#include <unordered_set>

using namespace std;


// time: O(n), space: O(n)
int lengthOfLongestSubstring(string s) {
    unordered_set<char> charSet;
    int maxLength = 0;
    int left = 0;

    for(int right = 0; right < s.size(); right++){
        while(charSet.count(s[right])){
            charSet.erase(s[left]);
            left++;
        }

        charSet.insert(s[right]);
        maxLength = max(maxLength, (int)charSet.size()); // r - l + 1
    }

    return maxLength;
}