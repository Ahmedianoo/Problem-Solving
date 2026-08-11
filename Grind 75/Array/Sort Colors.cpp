#include <iostream>
#include <vector>

using namespace std;


// time: O(n), space: O(1)
void sortColors(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    int i = 0;

    while(i <= r){
        if(nums[i] == 0){
            swap(nums[l], nums[i]);
            l++;
        }
        else if(nums[i] == 2){
            swap(nums[i], nums[r]);
            r--;
            i--;            
        }
        i++;
    }
}

// time: O(n), space: O(1)
void sortColors(vector<int>& nums) {
    int r = 0;
    int w = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0) r++;
        else if(nums[i] == 1) w++;
    }

    for(int i = 0; i < nums.size(); i++){
        int curr;
        if(r > 0){
            r--;
            curr = 0;
        }else if(w > 0){
            w--;
            curr = 1;
        }else{
            curr = 2;
        }
        nums[i] = curr;
    }
}
