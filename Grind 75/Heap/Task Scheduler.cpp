#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// time: O(n * m), space: O(n)
int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);

    for(char c : tasks){
        freq[c - 'A']++;
    }

    priority_queue<int> pq;

    for(int count : freq){
        if(count > 0) pq.push(count);
    }   


    queue<pair<int, int>> q;
    int time = 0;

    while(!pq.empty() || !q.empty()){
        time++;

        if(!pq.empty()){
            int count = pq.top() - 1;
            pq.pop();
            if(count != 0) q.push({count, time + n});
        }

        if(!q.empty() && q.front().second == time){
            pq.push(q.front().first);
            q.pop();
        }
    }

    return time;
}
