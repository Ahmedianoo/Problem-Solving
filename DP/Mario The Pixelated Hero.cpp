#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define lolo long long

lolo get_min(int n, vector<int>& pixels, int index, vector<lolo>& dp) {
    if (index >= n - 1) return 0;
    if (pixels[index] == 0) return INT_MAX;
    if (dp[index] != -1) return dp[index];

    lolo min_jumps = INT_MAX;
    for (int i = 1; i <= pixels[index]; i++) {
        min_jumps = min(min_jumps, get_min(n, pixels, index + i, dp));
    }


    return dp[index] = 1 + min_jumps;


}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> pixels(n);
    for (int i = 0; i < n; i++) {
        cin >> pixels[i];
    }
    vector<lolo> dp(n, -1);
    lolo min_jumps = get_min(n, pixels, 0, dp);
    if (min_jumps == INT_MAX) {
        cout << -1;
    }
    else {
        cout << min_jumps;
    }


    return 0;
}
