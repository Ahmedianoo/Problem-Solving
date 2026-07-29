#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// time: O(m * n), space: O(m * n)
void bfs(vector<vector<char>>& grid, int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = '0';

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < grid.size() &&
                ny >= 0 && ny < grid[0].size() &&
                grid[nx][ny] == '1') {
                grid[nx][ny] = '0';
                q.push({nx, ny});
            }
        }        
    }  
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == '1'){
                bfs(grid, i, j);
                count++;
            }
        }
    }

    return count;
}

// time: O(m * n), space: O(m * n)
void dfs(vector<vector<char>>& grid, int i, int j){
    if(i < 0 || i >= grid.size() 
        || j < 0 || j >= grid[0].size() 
        || grid[i][j] == '0') return;

    grid[i][j] = '0';

    dfs(grid, i + 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);    

    return;
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == '1'){
                dfs(grid, i, j);
                count++;
            }
        }
    }

    return count;
}

// in the bfs, there is a while loop and a for loop
