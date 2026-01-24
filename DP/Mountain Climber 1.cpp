#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int min_cost(vector<vector<int>>& mountain, vector<vector<int>>& dp, int n, int i, int j) {
    if (i == n) return 0;
    
    if (dp[i][j] != -1) return dp[i][j];
    //down
    int down = min_cost(mountain, dp, n, i + 1, j);
    int down_right = min_cost(mountain, dp, n, i + 1, j + 1);
    int min_cost = min(down, down_right);

    return dp[i][j] = mountain[i][j] + min_cost;
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;
    cin >> n;
    vector<vector<int>> mountain(n);
    vector<vector<int>> dp(n);
    int cost;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> cost;
            mountain[i].push_back(cost);
            dp[i].push_back(-1);
        }
    }


    cout << min_cost(mountain, dp, n, 0, 0);

    return 0;
}
