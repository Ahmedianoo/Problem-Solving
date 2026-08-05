#include <iostream>
#include <vector>

using namespace std;

// time: O(n * n!), space: O(n * n!)
vector<vector<int>> permutations;

vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> isVisited(nums.size(), false);
    vector<int> currPath;
    solve(nums, isVisited, currPath);
    return permutations;
}

void solve(vector<int>& nums, vector<bool>& isVisited, vector<int>& currPath){
    if(currPath.size() == nums.size()){
        permutations.push_back(currPath);
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        if(!isVisited[i]){
            isVisited[i] = true;
            currPath.push_back(nums[i]);

            solve(nums, isVisited, currPath);

            currPath.pop_back();
            isVisited[i] = false;
        }
    }
}

// swapping solution
// time: O(n * n!), space: O(n * n!)
vector<vector<int>> permute(vector<int>& nums) {
    solve(nums, 0);
    return permutations;
}

void solve(vector<int>& nums, int first){
    if(first == nums.size()){
        permutations.push_back(nums);
        return;
    }

    for(int i = first; i < nums.size(); i++){
        swap(nums[i], nums[first]);
        solve(nums, first + 1);
        swap(nums[i], nums[first]);
    }
}

// remove and recurse
// time: O(n * n!), space: O(n * n!)
vector<vector<int>> permute(vector<int>& nums) {
    if(nums.size() == 1) {
        return {nums};
    }

    vector<vector<int>> result;

    for(int i = 0; i < nums.size(); i++){
        int n = nums.front();
        nums.erase(nums.begin());

        vector<vector<int>> perms= permute(nums);

        for(vector<int>& perm : perms){
            perm.push_back(n);
        }

        result.insert(result.end(), perms.begin(), perms.end());

        nums.push_back(n);
    }

    return result;
}