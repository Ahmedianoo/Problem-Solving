#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class MedianFinder {
priority_queue<int> smallHeap;  // max Heap
priority_queue<int, vector<int>, greater<int>> largeHeap; // minHeap

public:
    MedianFinder() {
        
    }
    
    // time: O(log(n)), space: O(n)
    void addNum(int num) {
        // smallHeap.push(num);

        // if (!largeHeap.empty() && smallHeap.top() > largeHeap.top()) {
        //     largeHeap.push(smallHeap.top());
        //     smallHeap.pop();
        // } 
               
        if(largeHeap.empty() || num < smallHeap.top()){
            smallHeap.push(num);
        }else{
            largeHeap.push(num);
        }

        if(smallHeap.size() > largeHeap.size() + 1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }else if(largeHeap.size() > smallHeap.size() + 1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if(smallHeap.empty() && largeHeap.empty()){
            return 0.0;
        }

        if(smallHeap.size() > largeHeap.size()){
            return smallHeap.top();
        }    
        
        if(smallHeap.size() < largeHeap.size()){
            return largeHeap.top();
        }         

        return (smallHeap.top() + largeHeap.top()) / 2.0;
    }
};

