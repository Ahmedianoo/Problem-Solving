#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long long max_treasure(const vector<pair<int, int>>& chests, vector<long long>& dp, int n, int index) {
    if (index >= n) return 0;
    if (dp[index] != -1) return dp[index];

    long long include = chests[index].first + max_treasure(chests, dp, n, index + 1 + chests[index].second);
    long long skip = max_treasure(chests, dp, n, index + 1);
    return dp[index] = max(include, skip);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<pair<int, int>> chests(n);
    for (int i = 0; i < n; i++) {
        cin >> chests[i].first >> chests[i].second;
    }

    vector<long long> dp(n, -1);
    long long max = max_treasure(chests, dp, n, 0);
    cout << max;




    return 0;
}
