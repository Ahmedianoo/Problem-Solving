#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

int min_balls(vector<int>& balls, vector<vector<int>>& dp, int b, int v, int sum, int index) {
    if (sum == v) return 0;
    if (sum > v || index == b) return 1000000;
    if (dp[index][sum] != -1) return dp[index][sum];

    int repeat = 1 + min_balls(balls, dp, b, v, sum + balls[index], index);
    int next = min_balls(balls, dp, b, v, sum, index + 1);


    return dp[index][sum] = min(repeat, next);
}


 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int v, b;
    cin >> v >> b;
    vector<int> balls(b);
    for (int i = 0; i < b; i++) {
        cin >> balls[i];
    }
    
    vector<vector<int>> dp(b, vector<int>(v+1, -1));

    int num_balls = min_balls(balls, dp, b, v, 0, 0);
    if (num_balls >= 1000000) cout << "no solution";
    else cout << num_balls;


    return 0;
}