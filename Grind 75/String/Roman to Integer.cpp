#include <iostream>
#include <unordered_map>

using namespace std;

// time: O(n), space: O(1)
int romanToInt(string s) {
    unordered_map<char, int> romanNumerals = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int i = 0;
    int number = 0;

    while(i < s.size()){
        if(i + 1 < s.size() && romanNumerals[s[i]] < romanNumerals[s[i + 1]]){
            int curr = romanNumerals[s[i + 1]] - romanNumerals[s[i]];
            number += curr;
            i += 2;

            continue;
        }

        number += romanNumerals[s[i]];
        i++;
    }

    return number;
}