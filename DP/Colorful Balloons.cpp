#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define lolo long long

lolo get_sum(int n, int index, vector<pair<int, int>>& ballons, vector<lolo>& dp) {
    if (index >= n) return 0;
    if (dp[index] != -1) return dp[index];
    lolo consider = ballons[index].first + get_sum(n, index + 1 + ballons[index].second, ballons, dp);
    lolo skip = get_sum(n, index + 1, ballons, dp);

    return dp[index] = max(consider, skip);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<pair<int, int>> ballons(n);
    for (int i = 0; i < n; i++) {
        cin >> ballons[i].first >> ballons[i].second;
    }

    vector<lolo> dp(n, -1);
    cout << get_sum(n, 0, ballons, dp);
    return 0;
}
