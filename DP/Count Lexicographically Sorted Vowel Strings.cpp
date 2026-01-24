#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int get_count(int n, int v, int in, int jv, vector<vector<int>>& dp) {
    if (in == n) return 1; // no more groups and no more vowels
    if (jv == v) return 0;
    if (dp[in][jv] != -1) return dp[in][jv];

    int repeat = get_count(n, v, in + 1, jv, dp);
    int skip = get_count(n, v, in, jv + 1, dp);

    return dp[in][jv] = repeat + skip;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int v = 5;
    int n; // groups
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(v, -1));
    cout << get_count(n, v, 0, 0, dp);


    return 0;
}
