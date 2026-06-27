#include <iostream>
#include <vector>

using namespace std;


// O(n)
// int search(vector<int>& nums, int target) {
//     for(int i = 0; i < nums.size(); i++){
//         if(nums[i] == target) return i;
//     }

//     return -1;
// }

// O( log(n) )
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while(right >= left){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        if(nums[mid] > target) right = mid - 1;
        if(nums[mid] < target) left = mid + 1;
    }

    return -1;
}