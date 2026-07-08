#include <iostream>
#include <vector>

using namespace std;

// Boyer-Moore
int majorityElement(vector<int>& nums) {
    int count = 0;
    int result;

    for(int i = 0; i < nums.size(); i++){
        if(count == 0) result = nums[i];
        
        if(result == nums[i]) count++;
        else count--;
    }

    return result;
}   