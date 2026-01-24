#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int get_power(int n, unordered_map<int, int>& dp) {
    if (n == 1) return 1;
    if (dp.count(n)) return dp[n];
    int count = 0;
    if (n % 2 == 0) {
        count = count + get_power(n / 2, dp);
    }
    else {
        count = count + get_power(3 * n + 1, dp);
    }

    return dp[n] = 1 + count;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int start, end, target;
    cin >> start >> end >> target;
    unordered_map<int, int> dp;
    vector<pair<int, int>> powers;

    for (int i = start; i <= end; i++) {
        powers.push_back({ get_power(i, dp), i });
    }

    sort(powers.begin(), powers.end());

    cout << powers[target - 1].second;





    return 0;
}
