#include <iostream>
#include <vector>

using namespace std;

// time: O(n * m * 3^L), space: O(L), L = word length 
bool exist(vector<vector<char>>& board, string word) {
    for(int r = 0; r < board.size(); r++){
        for(int c = 0; c < board[0].size(); c++){
            if(dfs(board, word, r, c, 0)){
                return true;
            }
        }
    }

    return false;
}

bool dfs(vector<vector<char>>& board, string word, int r, int c, int i){
    if(board.size() <= r || r < 0
        || board[0].size() <= c || c < 0
        || board[r][c] == '#' || board[r][c] != word[i]){
        
        return false;
    }

    if(i == word.size() - 1){
        return true;
    }    

    char temp = board[r][c];
    board[r][c] = '#';

    bool found = 
        dfs(board, word, r, c + 1, i + 1) ||
        dfs(board, word, r, c - 1, i + 1) ||
        dfs(board, word, r + 1, c, i + 1) ||
        dfs(board, word, r - 1, c, i + 1);

    board[r][c] = temp;

    return found;
}