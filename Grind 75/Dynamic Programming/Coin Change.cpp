#include <iostream>
#include <vector>

using namespace std;

// bottom up
int coinChange(vector<int>& coins, int amount) {
    
}

// top down
int getMin(vector<int>& coins, vector<vector<int>>& dp, int i, int amount){
    if(amount == 0) return 0;
    if(amount < 0 || i == coins.size()) return INT_MAX;
    if(dp[i][amount] != -1) return dp[i][amount];

    int repeat = getMin(coins, dp, i, amount - coins[i]);
    int skip = getMin(coins, dp, i + 1, amount);

    if(repeat != INT_MAX) repeat++;

    return dp[i][amount] = min(repeat, skip);
}

int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    int minCoins = getMin(coins, dp, 0, amount);
    return minCoins < INT_MAX ? minCoins : -1;
}