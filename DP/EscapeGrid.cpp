#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define lolo long long

int get_min(int n, vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
    if (i == n - 1 && (0 <= j && j <= n - 1)) return grid[i][j];
    if (i < 0 || i > n - 1 || j > n - 1 || j < 0) return INT_MAX;
    if (dp[i][j] != INT_MIN) return dp[i][j];



    int min_sum = INT_MAX;
    for (int c = 0; c < n; c++) {
        if (c != j) {
            min_sum = min(min_sum, get_min(n, grid, i + 1, c, dp));
        }
    }


    return dp[i][j] = grid[i][j] + min_sum;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
    int min_sum = INT_MAX;
    for (int c = 0; c < n; c++) {
        min_sum = min(min_sum, get_min(n, grid, 0, c, dp));
    }
    cout << min_sum;

    return 0;
}
