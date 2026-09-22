#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// time: O(n * m^2), space: O(n * m^2)
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, vector<string>> nei;
    wordList.push_back(beginWord);

    for(string word : wordList){
        for(int i = 0; i < word.size(); i++){
            string pattern = word.substr(0, i) + '*' + word.substr(i + 1, word.size() - 1 - i);
            nei[pattern].push_back(word);
        }             
    }

    unordered_set<string> visited = {beginWord};

    queue<string> q;
    q.push(beginWord);

    int res = 1;

    while(!q.empty()){
        int size = q.size();

        for(int i = 0; i < size; i++){
            string word = q.front();
            q.pop();

            if(word == endWord) return res;

            for(int j = 0; j < word.size(); j++){
                string pattern = word.substr(0, j) + '*' + word.substr(j + 1, word.size() - 1 - j);
                
                for(string neiWord : nei[pattern]){
                    if(!visited.count(neiWord)){
                        visited.insert(neiWord);
                        q.push(neiWord);
                    }
                }
                nei[pattern].clear(); 
            } 
        }

        res++;
    }

    return 0;
}