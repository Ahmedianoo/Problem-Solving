#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


long long num_teams(vector<vector<long long>>& dp, int k, int n) {
    if (k == 0 && n == 0) return 1;
    if (n == 0 || k == 0 || k > n) return 0;
    if (dp[n][k] != -1) return dp[n][k];

    long long existing_team = k * num_teams(dp, k, n - 1);
    long long new_team = num_teams(dp, k - 1, n - 1);

    return dp[n][k] = existing_team + new_team;

}




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int k, n;
    cin >> n >> k;


    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));
    cout << num_teams(dp, k, n);

    return 0;
}