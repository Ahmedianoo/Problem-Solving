#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define lolo long long

int find_set(int node, vector<int>& parent) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = find_set(parent[node], parent);
}


void link(int x, int y, vector<int>& parent, vector<int>& rank) {
    if (rank[x] > rank[y]) {
        parent[y] = x;
    }
    else {
        parent[x] = y;
        if (rank[x] == rank[y]) {
            rank[y] = rank[y] + 1;
        }
    }
}


bool uni(int x, int y, vector<int>& parent, vector<int>& rank) {
    if (find_set(x, parent) == find_set(y, parent)) {
        return false;
    }

    link(find_set(x, parent), find_set(y, parent), parent, rank);
    return true;
}


bool campare(vector<int> x, vector<int> y) {
    return x[2] < y[2];
}



vector<vector<int>> kruskal(int n, 
        vector<vector<int>>& graph, vector<int>& parent, vector<int>& rank) {

    vector<vector<int>> A;

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    sort(graph.begin(), graph.end(), campare);

    for (int i = 0; i < (int)graph.size(); i++) {
        int x = graph[i][0];
        int y = graph[i][1];
        int c = graph[i][2];

        if (find_set(x, parent) != find_set(y, parent)) {
            A.push_back({ x, y, c });
            uni(x, y, parent, rank);
        }
    }
    return A;
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lolo n, m, a;
    cin >> n >> m >> a;
    vector<vector<int>> graph;
    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        if (c < a) graph.push_back({ x, y, c });
    }

    vector<int> parent(n + 1);
    vector<int> rank(n + 1);
    vector<vector<int>> roads;

    lolo cost = 0;
    roads = kruskal(n, graph, parent, rank);
    for (int i = 0; i < (int)roads.size(); i++) {
        cost = cost + roads[i][2];
    }

    lolo hospitalCount = 0;

    for (int i = 1; i <= n; i++) {
        if (find_set(i, parent) == i) {
            hospitalCount++;
        }
    }

    cost = cost + hospitalCount * a;
    cout << cost << " " << hospitalCount;



    return 0;
}
