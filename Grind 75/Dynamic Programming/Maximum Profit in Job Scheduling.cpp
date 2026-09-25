#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];
}

int binarySearch(const vector<vector<int>>& jobs, int target, int i) {
    int left = i + 1;
    int right = jobs.size();

    while(left < right) {
        int mid = left + (right - left) / 2;

        if(jobs[mid][0] >= target)
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

// bottom up
// time: O(n * log(n)), space: O(n)
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<vector<int>> jobs;
    int jobsCount = startTime.size();

    for(int i = 0; i < jobsCount; i++){
        jobs.push_back({startTime[i], endTime[i], profit[i]});
    }

    sort(jobs.begin(), jobs.end(), compare);

    vector<int> dp(jobsCount + 1, 0);

    for(int i = jobsCount - 1; i >= 0; i--) {

        int next = binarySearch(jobs, jobs[i][1], i);

        int take = jobs[i][2] + dp[next];
        int skip = dp[i + 1];

        dp[i] = max(take, skip);
    }

    return dp[0];
}

// top down
// time: O(n * log(n)), space: O(n)
int maxProfit(const vector<vector<int>>& jobs, vector<int>& dp, int i){
    if(i == jobs.size()) return 0;

    if(dp[i] != -1) return dp[i];

    int next = binarySearch(jobs, jobs[i][1], i);

    int take = jobs[i][2] + maxProfit(jobs, dp, next);
    int skip = maxProfit(jobs, dp, i + 1);

    return dp[i] = max(take, skip);
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<vector<int>> jobs;
    int jobsCount = startTime.size();

    for(int i = 0; i < jobsCount; i++){
        jobs.push_back({startTime[i], endTime[i], profit[i]});
    }

    sort(jobs.begin(), jobs.end(), compare);

    vector<int> dp(jobsCount, -1);

    return maxProfit(jobs, dp, 0);
}

