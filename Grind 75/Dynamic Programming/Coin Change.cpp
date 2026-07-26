#include <iostream>
#include <vector>

using namespace std;

// bottom up, time: O(coins * amount), space: O(amount)
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for(int a = 1; a <= amount; a++){
        for(int c : coins){
            if(a - c >= 0 && dp[a - c] != INT_MAX){
                dp[a] = min(dp[a], dp[a - c] + 1);
            }
        }
    }

    return dp[amount] != INT_MAX ? dp[amount] : -1;
}

// top down,time: O(coins * amount), space: O(coins * amount) + stack: O(amount)
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