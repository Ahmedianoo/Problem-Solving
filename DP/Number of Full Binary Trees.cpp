#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int count_ways(int n, vector<int>& dp) {
    if (n == 1) return 1;
    if (n % 2 == 0) return 0;

    int count = 0;
    for (int i = 0; i < n; i++) {
        count = count + count_ways(i, dp) * count_ways(n - 1 - i, dp);
    }

    return dp[n] = count;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << count_ways(n, dp);

    return 0;
}
