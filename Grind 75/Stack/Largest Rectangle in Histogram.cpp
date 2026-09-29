#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// time: O(n), space: O(n)
int largestRectangleArea(vector<int>& heights) {
    stack<pair<int, int>> st;
    int maxArea = 0;

    for(int i = 0; i < heights.size(); i++){
        int start = i;

        while(!st.empty() && heights[i] < st.top().second){
            auto [index, height] = st.top();
            st.pop();

            maxArea = max(maxArea, height * (i - index));

            start = index;
        }

        st.push({start, heights[i]});
    }

    while(!st.empty()){
        auto [index, height] = st.top();
        st.pop();

        maxArea = max(maxArea, height * ((int)heights.size() - index));
    }

    return maxArea;
}

// solution without using pair
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int ans = 0;

    for (int i = 0; i < heights.size(); i++) {

        while (!st.empty() && heights[st.top()] > heights[i]) {

            int h = heights[st.top()];
            st.pop();

            int left = st.empty() ? -1 : st.top();

            int width = i - left - 1;

            ans = max(ans, h * width);
        }

        st.push(i);
    }

    while (!st.empty()) {

        int h = heights[st.top()];
        st.pop();

        int left = st.empty() ? -1 : st.top();

        int width = heights.size() - left - 1;

        ans = max(ans, h * width);
    }

    return ans;
}