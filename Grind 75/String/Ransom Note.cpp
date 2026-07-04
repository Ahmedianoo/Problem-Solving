#include <iostream>

using namespace std;


bool canConstruct(string ransomNote, string magazine) {
    if(ransomNote.size() > magazine.size()) return false;

    int freq[26] = {};

    for(char c : magazine){
        freq[c - 'a']++;
    }    
    
    for(char c : ransomNote){
        if(--freq[c - 'a'] < 0) return false;
    }


    return true;
}

// bool canConstruct(string ransomNote, string magazine) {
//     if(ransomNote.size() > magazine.size()) return false;

//     int freq[26] = {};

//     for(char c : ransomNote){
//         freq[c - 'a']++;
//     }

//     for(char c : magazine){
//         freq[c - 'a']--;
//     }    
    
//     for(int x : freq){
//         if(x > 0) return false;
//     }

//     return true;
// }