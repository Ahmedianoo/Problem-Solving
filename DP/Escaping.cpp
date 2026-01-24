#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define lolo long long
lolo count_ways(int n, int k, int r, int x, int y, vector<pair<int, int>>& moves, vector<vector<vector<lolo>>>& dp) {
    if (x >= n || x < 0 || y >= n || y < 0) return 1;
    if (k == 0) return 0;
    if (dp[x][y][k] != -1) return dp[x][y][k];

    lolo count = 0;
    for (int i = 0; i < r; i++) {
        count = count + count_ways(n, k - 1, r, x + moves[i].first, y + moves[i].second, moves, dp);
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
    vector<vector<vector<lolo>>> dp(n, vector<vector<lolo>>(n, vector<lolo>(k + 1, -1)));
    cout << count_ways(n, k, r, x, y, moves, dp);
    return 0;
}