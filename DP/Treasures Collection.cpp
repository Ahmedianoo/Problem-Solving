#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define lolo long long

lolo get_max(vector<int>& treasures, int i, int j, vector<vector<lolo>>& dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    //take i
    lolo left = treasures[i] + min(get_max(treasures, i + 2, j, dp), get_max(treasures, i + 1, j - 1, dp));

    //take j
    lolo right = treasures[j] + min(get_max(treasures, i, j - 2, dp), get_max(treasures, i + 1, j - 1, dp));


    return dp[i][j] = max(left, right);
}


lolo get_max_map(vector<int>& treasures, int i, int j, map<pair<int, int>, lolo>& dp_map) {
    if (i > j) return 0;
    if (dp_map.count({ i, j })) return dp_map[{i, j}];

    //take i
    lolo left = treasures[i] + min(get_max_map(treasures, i + 2, j, dp_map),
        get_max_map(treasures, i + 1, j - 1, dp_map));

    //take j
    lolo right = treasures[j] + min(get_max_map(treasures, i, j - 2, dp_map),
        get_max_map(treasures, i + 1, j - 1, dp_map));


    return dp_map[{i, j}] = max(left, right);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> treasures(n);
    for (int i = 0; i < n; i++) {
        cin >> treasures[i];
    }
    vector<vector<lolo>> dp(n, vector<lolo>(n, -1));

    cout << get_max(treasures, 0, n - 1, dp);
    return 0;
}
