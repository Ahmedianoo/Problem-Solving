#include <iostream>
#include <vector>

using namespace std;

// time: O(n), space: O(1)
int trap(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxLeft = height[left];
    int maxRight = height[right];

    int area = 0;

    while(left < right){
        
        if(maxLeft <= maxRight){
            left++;
            maxLeft = max(maxLeft, height[left]);
            area += maxLeft - height[left];
        }else {
            right--; 
            maxRight = max(maxRight, height[right]);
            area += maxRight - height[right];
        }
    }

    return area;
}

