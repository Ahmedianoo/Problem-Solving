#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;


bool isAnagram(string s, string t) { 
    if(s.length() != t.length()) return false;

    unordered_map<char, int> s_map, t_map;

    for(int i = 0; i < s.length(); i++){
        s_map[s[i]]++;
        t_map[t[i]]++;
    }

    // for(char c: s){
    //     if(s_map[c] != t_map[c]){
    //         return false;
    //     }
    // }

    // return true;
    return s_map == t_map;
}

// O(1) memory
// you could sort them and compare them together, what about the space and time complexity of sorting?
// bool isAnagram(string s, string t) {
//     sort(s.begin(), s.end());
//     sort(t.begin(), t.end());

//     return s == t;
// }

// bool isAnagram(string s, string t) {
//     if (s.size() != t.size())
//         return false;

//     int freq[26] = {};

//     for (char c : s)
//         freq[c - 'a']++;

//     for (char c : t)
//         freq[c - 'a']--;

//     for (int x : freq)
//         if (x != 0)
//             return false;

//     return true;
// }