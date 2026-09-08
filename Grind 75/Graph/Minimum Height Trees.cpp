#include <iostream>
#include <vector>
#include<queue>

using namespace std;

// time: O(n), space: O(n)
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if(n == 1) return {0};

    vector<vector<int>> graph(n);
    vector<int> degree(n, 0);
    queue<int> leaves;

    for(const vector<int>& edge : edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);

        degree[edge[0]]++;
        degree[edge[1]]++;
    }

    for(int i = 0; i < n; i++){
        if(degree[i] == 1){
            leaves.push(i);
        }
    }


    while(n > 2){
        int size = leaves.size();

        for(int i = 0; i < size; i++){
            int node = leaves.front();
            leaves.pop();
            n--;

            for(int neighbor : graph[node]){
                degree[neighbor]--;
                if(degree[neighbor] == 1) leaves.push(neighbor);
            }
        }
    }

    vector<int> result;

    while(!leaves.empty()){
        result.push_back(leaves.front());
        leaves.pop();
    }

    return result;
}

