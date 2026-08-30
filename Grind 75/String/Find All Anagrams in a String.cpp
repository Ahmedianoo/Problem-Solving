#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


// time: O(s), space: O(1)
vector<int> findAnagrams(string s, string p) {
    if(p.size() > s.size()) return {};

    unordered_map<char, int> pCount;
    unordered_map<char, int> sCount;
    for(int i = 0; i < p.size(); i++){
        sCount[s[i]]++;
        pCount[p[i]]++;
    } 

    int left = 0, right = p.size() - 1;

    vector<int> result;
    if(sCount == pCount) result.push_back(0);

    for(int right = p.size(); right < s.size(); right++){
        sCount[s[right]]++;
        sCount[s[left]]--;        
        
        if(sCount[s[left]] == 0) sCount.erase(s[left]);

        left++;

        if(sCount == pCount) result.push_back(left);        
    }

    return result;
}