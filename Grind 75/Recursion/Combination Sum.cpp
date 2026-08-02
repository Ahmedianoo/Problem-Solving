#include <iostream>
#include <vector>

using namespace std;

// time: O(2 ^ (n + target)), space: O(n + target)
vector<vector<int>> result;

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> currPath;
    dfs(candidates, currPath, 0, 0, target);
    return result;
}

void dfs(vector<int>& candidates, vector<int>& currPath, int i, int currSum, int target) {
    if(currSum == target) {
        result.push_back(currPath);
        return;
    }
    if(i == candidates.size() || currSum > target) return;

    dfs(candidates, currPath, i + 1, currSum, target);

    currPath.push_back(candidates[i]);
    dfs(candidates, currPath, i, currSum + candidates[i], target);
    currPath.pop_back();

    return;
}