#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define lolo long long


int max_gold(vector<lolo>& chests, vector<lolo>& dp, int n, int index) {
    if (index >= n) return 0;
    if (dp[index] != -1) return dp[index];
    lolo current = chests[index] + max_gold(chests, dp, n, index + 2);
    lolo skip = max_gold(chests, dp, n, index + 1);

    return dp[index] = max(current, skip);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<lolo> chests(n);
    for (int i = 0; i < n; i++) {
        cin >> chests[i];
    }
    vector<lolo> dp(n, -1);
    cout << max_gold(chests, dp, n, 0);


    return 0;
}
