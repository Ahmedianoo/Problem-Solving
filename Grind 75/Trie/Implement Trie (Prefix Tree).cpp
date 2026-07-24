#include <iostream>
#include <unordered_map>

using namespace std;

struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};


class Trie {
private:
TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        for(char c : word){
            if(!current->children.count(c)){
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;
        for(char c : word){
            if(!current->children.count(c)){
                return false;
            }
            current = current->children[c];
        }   
        return current->endOfWord;   
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for(char c : prefix){
            if(!current->children.count(c)){
                return false;
            }
            current = current->children[c];
        }   
        return true;           
    }
};