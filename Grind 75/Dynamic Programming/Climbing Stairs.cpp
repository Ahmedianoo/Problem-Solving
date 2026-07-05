#include <iostream>
#include <vector>

using namespace std;


int climbStairs(int n) {
    // top down call
    // vector<int> dp(n + 1, -1);
    // return getCount(n, dp);

    // bottom up
    int one = 1, two = 1;

    for(int i = 0; i < n - 1; i++){
        int temp = one;
        one = one + two;
        two = temp;
    }

    return one;
}   



// top down
int getCount(int n, vector<int> &dp){
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];

    return dp[n] = getCount(n - 1, dp) + getCount(n - 2, dp);
}

