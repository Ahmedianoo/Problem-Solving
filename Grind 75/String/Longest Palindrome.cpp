#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//hash set
int longestPalindrome(string s) {
    int result = 0;
    unordered_set<char> freq;

    for(char c : s){
        if(freq.count(c)){
            result += 2;
            freq.erase(c);
        } else {
            freq.insert(c);
        }
    }

    if(!freq.empty()) result += 1;

    return result;
}

// hash map
// int longestPalindrome(string s) {
//     int result = 0;
//     unordered_map<char, int> freq;

//     for(char c : s){
//         if(++freq[c] % 2 == 0) result += 2;
//     }

//     for(pair<char, int> p : freq){
//         if(p.second % 2 == 1) {
//             result++;
//             break;
//         }
//     }

//     return result;
// }