class Solution {
public:


    void bfs(int start, vector<vector<int>>& graph, vector<bool>& isVisited) {
        queue<int> q;
        q.push(start);
        isVisited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 0; i < graph[node].size(); i++) {
                int next = graph[node][i];
                if (!isVisited[next]) {
                    isVisited[next] = true;
                    q.push(next);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    graph[i].push_back(j);
                }
            }
        }
        int count = 0;
        vector<bool> isVisited(n, false);
        for (int i = 0; i < n; i++) {
            if (!isVisited[i]) {
                bfs(i, graph, isVisited);
                count++;
            }
        }

        return count;

    }
};