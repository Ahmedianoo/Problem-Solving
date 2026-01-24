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

#define lolo long long

lolo count_ways(int x, int y, vector<vector<lolo>>& dp) {
    if (x == 0 && y == 0) return 1;
    if (x < 0 || y < 0) return 0;

    if (dp[x][y] != -1) return dp[x][y];

    lolo left = count_ways(x - 1, y, dp);
    lolo down = count_ways(x, y - 1, dp);

    return dp[x][y] = left + down;

}




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int x, y;
    cin >> x >> y;
    int n = max(x, y);
    vector<vector<lolo>> dp(x + 1, vector<lolo>(y + 1, -1));
    cout << count_ways(x, y, dp);


    return 0;
}