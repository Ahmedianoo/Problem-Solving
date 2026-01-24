#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


long long min_tiles(int n, int sum, int index, vector<vector<long long>>& dp) {
    if (sum == n) return 0;
    if (index > sqrt(n) || sum > n) return INT_MAX;
    if (dp[index][sum] != -1) return dp[index][sum];


    long long repeat = 1 + min_tiles(n, sum + index * index, index, dp);
    long long skip = min_tiles(n, sum, index + 1, dp);

    return dp[index][sum] = min(repeat, skip);
}



long long min_tiles_2(int n, vector<long long>& dp) {
    if (n == 0) return 0;
    if (n < 0) return INT_MAX;
    if (dp[n] != -1) return dp[n];

    long long min_t = INT_MAX;
    for (int i = 1; i <= sqrt(n) + 1; i++) { // i * i <= n
        min_t = min(min_t, 1 + min_tiles_2(n - i * i, dp));
    }

    return dp[n] = min_t;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<vector<long long>> dp(sqrt(n) + 1, vector<long long>(n + 1, -1));
    cout << min_tiles(n, 0, 1, dp);

    //vector<long long> dp(n + 1, -1);
    //cout << min_tiles_2(n, dp);


    return 0;
}
