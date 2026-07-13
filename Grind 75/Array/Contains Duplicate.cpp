#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


// time: O(n), Memory: O(n)
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> hashSet;

    for(int num : nums){
        if(hashSet.count(num)) return true;
        hashSet.insert(num);
    }

    return false;
}

// time: O(n * log(n)), memory: O(1)
bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 1; i++){
        if(nums[i] == nums[i+1]) return true;
    }

    return false;
}