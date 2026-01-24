#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define lolo long long

lolo max_values(vector<int>& chests, int n, int index, vector<lolo>& dp) {
    if (index >= n) return 0;
    if (dp[index] != -1) return dp[index];

    lolo current = chests[index] + max_values(chests, n, index + 2, dp);
    lolo skip = max_values(chests, n, index + 1, dp);

    return dp[index] = max(current, skip);

}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> chests(n);
    for (int i = 0; i < n; i++) {
        cin >> chests[i];
    }
    vector<lolo> dp(n, -1);
    cout << max_values(chests, n, 0, dp);


    
    return 0;
}
