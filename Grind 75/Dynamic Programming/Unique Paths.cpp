#include <iostream>
#include <vector>

using namespace std;


// bottom up
// time: O(m * n), space: O(n)
int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);

    for(int i = m - 2; i >= 0; i--){
        for(int j = n - 2; j >= 0; j--){
            dp[j] = dp[j] + dp[j + 1];
        }
    }

    return dp[0];
}

// time: O(m * n), space: O(m * n)
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for(int i = 0; i < m; i++){
        dp[i][n - 1] = 1;
    }

    for(int i = 0; i < n; i++){
        dp[m - 1][i] = 1;
    }

    for(int i = m - 2; i >= 0; i--){
        for(int j = n - 2; j >= 0; j--){
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }

    return dp[0][0];
}


// top down
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return countPaths(m, n, 0, 0, dp);
}

// time: O(m * n), space: O(m * n), stack: O(m + n)
int countPaths(int m, int n, int i, int j, vector<vector<int>>& dp) {
    if(i == m - 1 && j == n - 1) return 1;
    if(i >= m || j >= n) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int down = countPaths(m, n, i + 1, j, dp);
    int right = countPaths(m, n, i, j + 1, dp);

    return dp[i][j] = down + right;
}
