#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// time: O(n + k * log(n)), space: O(n)
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> distances;

    for(vector<int> point : points){
        int dist = (point[0] * point[0]) + (point[1] * point[1]);
        distances.push_back({dist, point[0], point[1]});    
    }

    make_heap(distances.begin(), distances.end(), greater<vector<int>>());

    vector<vector<int>> result;

    for(int i = 0; i < k; i++){
        result.push_back({distances[0][1], distances[0][2]});
        pop_heap(distances.begin(), distances.end(), greater<vector<int>>());     
        distances.pop_back();  
    }

    return result;
}


// time: O(n * log(k)), space: O(k) 
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<vector<int>> maxHeap;

    for(vector<int> point : points){
        int dist = (point[0] * point[0]) + (point[1] * point[1]);
        if(maxHeap.size() < k){
            maxHeap.push({dist, point[0], point[1]});
        }else if(dist < maxHeap.top()[0]){
            maxHeap.pop();
            maxHeap.push({dist, point[0], point[1]});
        }
    }

    vector<vector<int>> result;

    while(!maxHeap.empty()){
        result.push_back({maxHeap.top()[1], maxHeap.top()[2]});
        maxHeap.pop();
    }

    return result;
}