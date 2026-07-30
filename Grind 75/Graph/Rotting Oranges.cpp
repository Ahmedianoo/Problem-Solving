#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// time: O(m * n), space: O(m * n)
int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int time = 0, fresh = 0;
    int m = grid.size();
    int n = grid[0].size();

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1) fresh++;
            if(grid[i][j] == 2) q.push({i, j});
        }
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while(!q.empty() && fresh > 0){
        int len = q.size();
        time++;

        for(int i = 0; i < len; i++){
            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    fresh--;
                }
            }
        }
    }

    return fresh == 0 ? time : -1;
}