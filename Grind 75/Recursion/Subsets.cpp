#include <iostream>
#include <vector>

using namespace std;

// time: O(n * (2 ^ n)), space: O(n * (2 ^ n))
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    getPowerSet(nums, result, {}, 0);
}

void getPowerSet(vector<int>& nums, vector<vector<int>>& result, vector<int>& currSet, int index){
    if(index == nums.size()){
        result.push_back(currSet);
        return;
    }

    currSet.push_back(nums[index]);
    getPowerSet(nums, result, currSet, index + 1);
    currSet.pop_back();

    getPowerSet(nums, result, currSet, index + 1);

    return;
}
