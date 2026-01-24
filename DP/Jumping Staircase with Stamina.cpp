#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define lolo long long

lolo get_max(int n, int k, vector<int>& stairs, int index, vector<vector<lolo>>& dp) {
    if (k < 0) return INT_MIN;
    if (index > n) return 0;
    if (dp[index][k] != INT_MIN) return dp[index][k];

    lolo climb1 = get_max(n, k, stairs, index + 1, dp);
    lolo climb2 = get_max(n, k, stairs, index + 2, dp);
    lolo jump = get_max(n, k - 1, stairs, index + 3, dp);
    lolo max_values = max(climb1, climb2);
    max_values = max(max_values, jump);

    return dp[index][k] = stairs[index] + max_values;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin >> n >> k;
    vector<int> stairs(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> stairs[i];
    }

    vector<vector<lolo>> dp(n + 2, vector<lolo>(k + 1, INT_MIN));
    cout << get_max(n, k, stairs, 0, dp);




    return 0;
}
