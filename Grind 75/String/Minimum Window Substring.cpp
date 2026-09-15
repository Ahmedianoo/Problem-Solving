#include <iostream>
#include <unordered_map>

using namespace std;

// time: O(n + m), space: O(n)
string minWindow(string s, string t) {
    int minSize = INT_MAX;
    int bestLeft = 0;

    unordered_map<char, int> tCount, windowCount;

    for(char c : t){
        tCount[c]++;
    } 

    int need = tCount.size(), have = 0; 

    int left = 0;

    for(int right = 0; right < s.size(); right++){

        char rightChar = s[right];

        windowCount[rightChar]++;

        if(tCount.count(rightChar) && windowCount[rightChar] == tCount[rightChar]){
            have++;
        }

        while(have == need){
            if(right - left + 1 < minSize){
                minSize = right - left + 1;
                bestLeft = left;
            }

            char leftChar = s[left];

            windowCount[leftChar]--;

            if(tCount.count(leftChar) && windowCount[leftChar] < tCount[leftChar]){
                have--;
            }                


            left++;
        }
        
    }

    if(minSize == INT_MAX)
        return "";

    return s.substr(bestLeft, minSize);
}