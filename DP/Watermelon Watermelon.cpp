#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int max_pieces(int n, int x, int y, int z, int size, vector<int>& dp) {
    if (size == 0) return 0;
    if (size < 0) return INT_MIN;

    if (dp[size] != -1) return dp[size];

    int x_cut = max_pieces(n, x, y, z, size - x, dp);
    int y_cut = max_pieces(n, x, y, z, size - y, dp);
    int z_cut = max_pieces(n, x, y, z, size - z, dp);
    
    int max_cuts = INT_MIN;
    if (!(x_cut < 0 && y_cut < 0 && z_cut < 0)) {
        max_cuts = max(x_cut, y_cut);
        max_cuts = 1 + max(max_cuts, z_cut);
    }

    return dp[size] = max_cuts;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    int x, y, z;
    cin >> x >> y >> z;

    vector<int> dp(n + 1, -1);
    int max_cuts = max_pieces(n, x, y, z, n, dp);
    if (max_cuts < 0) max_cuts = 0;
    cout << max_cuts;

    return 0;
}
