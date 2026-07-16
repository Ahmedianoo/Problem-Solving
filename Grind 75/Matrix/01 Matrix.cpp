#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// time: O(n * m), memory: O(n * m)
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> distances(m, vector<int>(n, INT_MAX));
    queue<pair<int, int>> positions;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 0){
                distances[i][j] = 0;
                positions.push({i, j});
            }
        }
    }

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while(!positions.empty()){
        int i = positions.front().first;
        int j = positions.front().second;
        positions.pop();

        for(pair<int, int> dir : directions){
            int nx = dir.first + i, ny = dir.second + j;

            if(nx < m && nx >= 0 && ny < n && ny >= 0){
                if(distances[nx][ny] > distances[i][j] + 1){
                    distances[nx][ny] = distances[i][j] + 1;
                    positions.push({nx, ny});
                }

            }
        }
    }

    return distances;
}