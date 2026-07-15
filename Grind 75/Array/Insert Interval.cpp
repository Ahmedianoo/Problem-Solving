#include <iostream>
#include <vector>

using namespace std;


// time: O(n), memory: O(n)
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    for(int i = 0; i < intervals.size(); i++){
        if(newInterval[1] < intervals[i][0]){
            result.push_back(newInterval);
            result.insert(result.end(), intervals.begin() + i, intervals.end());
            return result;
        }
        else if(newInterval[0] > intervals[i][1]){
            result.push_back(intervals[i]);
        }
        else {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
    }
    result.push_back(newInterval);
    return result;
}