#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define lolo long long

vector<int> two_sum(vector<int>& nums, int target){
    
    unordered_map<int, int> map;
    vector<int> sol;
    for(int i = 0; i < nums.size(); i++){
        // if the (terget - current number) exists in the hash map then return the index of the current number(i),
        // and the value in the hash map
        int diff = target - nums[i];
        if(map.count(diff)){
            sol = {map[diff], i};
            break;
        }
        map.insert({nums[i], i});
    }

    return sol;
}



// time: O(n), memory: O(n)

