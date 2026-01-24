#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


void dfs(vector<vector<int>>& graph, int node, vector<bool>& isVisited, stack<int>& st) {
    isVisited[node] = true;

    for (int i = 0; i < (int)graph[node].size(); i++) {
        int nextNode = graph[node][i];
        if (!isVisited[nextNode]) {
            dfs(graph, nextNode, isVisited, st);
        }
    }
    st.push(node);
}

void dfs_reverse(vector<vector<int>>& reversed_graph, int node, vector<bool>& isVisited) {
    isVisited[node] = true;

    for (int i = 0; i < (int)reversed_graph[node].size(); i++) {
        int nextNode = reversed_graph[node][i];
        if (!isVisited[nextNode]) {
            dfs_reverse(reversed_graph, nextNode, isVisited);
        }
    }
}


int count_scc(int n, vector<vector<int>>& graph, vector<vector<int>>& reversed_graph) {
    vector<bool> isVisited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!isVisited[i]) {
            dfs(graph, i, isVisited, st);
        }
    }
    for (int i = 0; i < n; i++) {
        isVisited[i] = false;
    }


    int count = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!isVisited[node]) {
            dfs_reverse(reversed_graph, node, isVisited);
            count++;
        }
    }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<vector<int>> reversed_graph(n);

    for (int i = 0; i < m; i++) {
        int city1, city2;
        cin >> city1 >> city2;
        graph[city1].push_back(city2);
        reversed_graph[city2].push_back(city1);
    }

    cout << count_scc(n, graph, reversed_graph);



    return 0;
}
