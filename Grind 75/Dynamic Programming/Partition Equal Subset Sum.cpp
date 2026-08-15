#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// time: O(n * target), space: O(target)
bool canPartition(vector<int>& nums) {
    int target = 0;
    for(const int& num : nums) target += num;
    if(target % 2 == 1) return false;
    target = target / 2; 

    unordered_set<int> dp;
    dp.insert(0);

    for(const int& num : nums){
        if(num > target) continue;

        unordered_set<int> nextDP;

        for(const int& t : dp){
            if(t + num == target) return true;
            if(t + num < target) nextDP.insert(t + num);
            nextDP.insert(t);
        }

        dp = nextDP;
    }

    return false;
}

// time: O(n * target), space: O(n * target)
bool canPartition(vector<int>& nums) {
    int target = 0;
    for(const int& num : nums) target += num;
    if(target % 2 == 1) return false;
    target = target / 2; 

    vector<vector<int>> dp(nums.size(), vector<int>((target + 1), -1));

    return canFind(nums, dp, 0, target);
}

bool canFind(vector<int>& nums, vector<vector<int>>& dp, int index, int sum){
    if(sum == 0) return true;
    if(index >= nums.size() || sum < 0) return false;

    if(dp[index][sum] != -1) return dp[index][sum];

    bool take = canFind(nums, dp, index + 1, sum - nums[index]);
    bool skip = canFind(nums, dp, index + 1, sum);

    return dp[index][sum] = take || skip;
}