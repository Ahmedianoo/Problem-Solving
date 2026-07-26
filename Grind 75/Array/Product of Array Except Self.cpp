#include <iostream>
#include <vector>

using namespace std;

// time: O(n), space: O(1)
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> answer(nums.size());

    answer[0] = 1;
    for(int i = 1; i < answer.size(); i++){
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    int post = 1;
    for(int i = answer.size() - 1; i >= 0; i--){
        answer[i] *= post;
        post *=  nums[i];
    }

    return answer;
}