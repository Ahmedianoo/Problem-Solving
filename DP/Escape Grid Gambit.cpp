#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



long long count_escapes(int n, int k, int r, int x, int y, vector<pair<int, int>>& moves, vector<vector<vector<long long>>>& dp) {

    if (x >= n || x < 0 || y >= n || y < 0) return 1;
    if (k == 0) return 0;
    if (dp[x][y][k] != -1) return dp[x][y][k];

    long long count = 0;
    for (int i = 0; i < r; i++) {
        count = count + count_escapes(n, k - 1, r, x + moves[i].first, y + moves[i].second, moves, dp);
    }

    return dp[x][y][k] = count;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k, r, x, y;
    cin >> n >> k >> r >> x >> y;
    vector<pair<int, int>> moves(r);

    for (int i = 0; i < r; i++) {
        cin >> moves[i].first >> moves[i].second;
    }

    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(k + 1, -1)));
    cout << count_escapes(n, k, r, x, y, moves, dp);

    return 0;
}
