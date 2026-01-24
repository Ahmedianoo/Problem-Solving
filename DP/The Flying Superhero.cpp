#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define ll long long
ll min_energy(vector<ll>& buildings, int n, int index, vector<ll>& dp) {
    if (index >= n) return 0;
    if (dp[index] != -1) return dp[index];
    ll current = buildings[index] + min_energy(buildings, n, index + 1, dp);
    ll skip = buildings[index] + min_energy(buildings, n, index + 2, dp);

    return dp[index] = min(current, skip);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<ll> buildings(n);

    for (int i = 0; i < n; i++) {
        cin >> buildings[i];
    }
    if (n == 1) {
        cout << buildings[0]; return 0;
    }
    vector<ll> dp(n, -1);
    vector<ll> dp1(n, -1);
    cout << min(min_energy(buildings, n, 1, dp), min_energy(buildings, n, 0, dp1));
    return 0;
}
