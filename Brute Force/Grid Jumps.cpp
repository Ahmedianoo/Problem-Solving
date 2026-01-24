#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


void grid_jump(vector<vector<int>> grid, vector<vector<bool>> isVisited, int sum, int& max, int index_i, int index_j) {

    isVisited[index_i][index_j] = true;
    sum = sum + grid[index_i][index_j];
    if (index_i == 2 && index_j == 0) {
        if (max < sum) {
            max = sum;
        }
        return;
    }


    if (index_i - 1 >= 0) {
        if (index_j - 1 >= 0 && !isVisited[index_i - 1][index_j - 1]) {//top left
            grid_jump(grid, isVisited, sum, max, index_i - 1, index_j - 1);
        }

        //top
        if (!isVisited[index_i - 1][index_j]) {
            grid_jump(grid, isVisited, sum, max, index_i - 1, index_j);
        }
        

        if (index_j + 1 < 3 && !isVisited[index_i - 1][index_j + 1]) {//top right
            grid_jump(grid, isVisited, sum, max, index_i - 1, index_j + 1);
        }
    }

    if (index_i + 1 < 3) {
        if (index_j - 1 >= 0 && !isVisited[index_i + 1][index_j - 1]) {//down left
            grid_jump(grid, isVisited, sum, max, index_i + 1, index_j - 1);
        }

        //down
        if (!isVisited[index_i + 1][index_j]) {
            grid_jump(grid, isVisited, sum, max, index_i + 1, index_j);
        }
        

        if (index_j + 1 < 3 && !isVisited[index_i + 1][index_j + 1]) {//down right
            grid_jump(grid, isVisited, sum, max, index_i + 1, index_j + 1);
        }
    }
    

    isVisited[index_i][index_j] = false;
    


}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<vector<int>> grid(3, vector<int>(3));
    vector<vector<bool>> isVisited(3, vector<bool>(3, false));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
        }
    }

    int sum = 0, max = INT_MIN;
    grid_jump(grid, isVisited, sum, max, 0, 0);

    cout << max;

    return 0;
}
