#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }

        int left = i + 1, right = nums.size() - 1;
        while(left < right){
            int threeSum = nums[left] + nums[right] + nums[i];
            if(threeSum == 0){
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                while(nums[left] == nums[left - 1] && left < right){
                    left++;
                }
            }
            else if(threeSum < 0){
                left++;
            }
            else{
                right--;
            }
        }
    }

    return result;
}