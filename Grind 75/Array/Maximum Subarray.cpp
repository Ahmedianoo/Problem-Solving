#include <iostream>
#include <vector>

using namespace std;



// kadane's algorithm
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    int currSum = 0;

    for(int n : nums){
        if(currSum < 0){
            currSum = 0;
        }
        currSum += n;         
        // currSum = max(currSum + n, n);
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

