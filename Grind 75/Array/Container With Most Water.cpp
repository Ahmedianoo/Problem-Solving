#include <iostream>
#include <vector>

using namespace std;

// time: O(n), space: O(1)
int maxArea(vector<int>& height) {
    int area = 0;
    int left = 0, right = height.size() - 1;

    while(left < right){
        int w = right - left;
        int h = min(height[left], height[right]);
        area = max(area, w * h);

        if(height[left] < height[right]) left++;
        else right--;
    }

    return area;
}

// time: O(n^2), space: O(1)
int maxArea(vector<int>& height) {
    int maxArea = 0;

    for(int i = 0; i < height.size(); i++){
        for(int j = i; j < height.size(); j++){
            int w = j - i;
            int h = min(height[j], height[i]);
            maxArea = max(maxArea, w * h);
        }
    }    

    return maxArea;
}
