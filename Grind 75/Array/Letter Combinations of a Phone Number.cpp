#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


// time: O(n * 4^n), space: O(n * 4^n)
void mapNumberstoLetters(unordered_map<char, vector<char>>& phoneNumbersMap){
    phoneNumbersMap['2'] = {'a', 'b', 'c'};
    phoneNumbersMap['3'] = {'d', 'e', 'f'};
    phoneNumbersMap['4'] = {'g', 'h', 'i'};
    phoneNumbersMap['5'] = {'j', 'k', 'l'};
    phoneNumbersMap['6'] = {'m', 'n', 'o'};
    phoneNumbersMap['7'] = {'p', 'q', 'r', 's'};
    phoneNumbersMap['8'] = {'t', 'u', 'v'};
    phoneNumbersMap['9'] = {'w', 'x', 'y', 'z'};
}

void getCombinations(string digits, unordered_map<char, vector<char>>& phoneNumbersMap, 
    vector<string>& result, int index, string& currCombination){
        if(index == digits.size()){
            result.push_back(currCombination);
            return;
        }

        for(int i = 0; i < phoneNumbersMap[digits[index]].size(); i++){
            currCombination.push_back(phoneNumbersMap[digits[index]][i]);

            getCombinations(digits, phoneNumbersMap, result, index + 1, currCombination);

            currCombination.pop_back();
        }
}

vector<string> letterCombinations(string digits) {
    unordered_map<char, vector<char>> phoneNumbersMap;
    mapNumberstoLetters(phoneNumbersMap);
    
    vector<string> result;
    string currCombination = "";

    getCombinations(digits, phoneNumbersMap, result, 0, currCombination);
    
    return result;
}

