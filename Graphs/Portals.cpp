#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

void apply_dijkstra(int n, int s, vector<vector<pair<int, int>>>& graph, vector<int>& distance) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorityQueue;
    priorityQueue.push({ 0, s });

    while (!priorityQueue.empty()) {
        int currentDistance = priorityQueue.top().first;
        int node = priorityQueue.top().second;
        priorityQueue.pop();

        if (currentDistance > distance[node]) {
            continue;
        }

        for (int i = 0; i < (int)graph[node].size(); i++) {
            int nextNode = graph[node][i].first;
            int cost = graph[node][i].second;
            if (distance[node] + cost < distance[nextNode]) {
                distance[nextNode] = distance[node] + cost;
                priorityQueue.push({ distance[nextNode] , nextNode });
            }
        }

    }

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++) {
        int city1, city2, health;
        cin >> city1 >> city2 >> health;
        graph[city1].push_back({ city2, health });
    }

    vector<int> distance(n, INT_MAX);
    distance[s] = 0;
    apply_dijkstra(n, s, graph, distance);


    int reachableCities = 0, furthestCityHealth = 0;
    for (int i = 0; i < n; i++) {
        if (distance[i] < INT_MAX) {
            reachableCities++;
            furthestCityHealth = max(furthestCityHealth, distance[i]);
        }
    }

    cout << reachableCities << " " << furthestCityHealth;

    return 0;
}
