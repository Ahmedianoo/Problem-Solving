#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    
    vector<int> chests(n);
    for (int i = 0; i < n; i++) {
        cin >> chests[i];
    }

    if (n == 1) cout << chests[0];

    vector<long long> dp(n);
    dp[n - 1] = chests[n - 1];
    dp[n - 2] = max(dp[n - 1], (long long)chests[n-2]);
    for (int i = n - 3; i >= 0; i--) {
        dp[i] = max(dp[i + 1], chests[i] + dp[i + 2]);
    }


    cout << dp[0];





    return 0;
}
