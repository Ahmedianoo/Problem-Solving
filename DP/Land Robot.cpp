#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long long max_gold(vector<vector<long long>>& grid, vector<vector<long long>>& dp, int n, int m, int i, int j) {
    if (i == n - 1 && j == m - 1) return grid[i][j];
    if (dp[i][j] != -1) return dp[i][j];


    long long max_path;
    if (j + 1 == m) {
        max_path = max_gold(grid, dp, n, m, i + 1, j); // only down
    }
    else if (i + 1 == n) {
        max_path = max_gold(grid, dp, n, m, i, j + 1); // only right
    }
    else {
        long long right = max_gold(grid, dp, n, m, i, j + 1);
        long long down = max_gold(grid, dp, n, m, i + 1, j);
        long long down_right = max_gold(grid, dp, n, m, i + 1, j + 1);
        max_path = max(right, down);
        max_path = max(max_path, down_right);
    }




    return dp[i][j] = grid[i][j] + max_path;
}




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> grid(n, vector<long long>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<long long>> dp(n, vector<long long>(m, -1));
    cout << max_gold(grid, dp, n, m, 0, 0);


    return 0;
}
