#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


#define lolo long long

int max_gold(vector<vector<int>>& grid, int m, int n, int i, int j, vector<vector<lolo>>& dp) {
    if (i == m - 1 && j == n - 1) return grid[i][j];
    if (i >= m || j >= n) return INT_MIN;
    if (dp[i][j] != -1) return dp[i][j];

    //down
    lolo down =  max_gold(grid, m, n, i + 1, j, dp);
    //right
    lolo right = max_gold(grid, m, n, i, j + 1, dp);


    return dp[i][j] = grid[i][j] + max(down, right);

}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<lolo>> dp(m, vector<lolo>(n, -1));
    cout << max_gold(grid, m, n, 0, 0, dp);
    return 0;
}
