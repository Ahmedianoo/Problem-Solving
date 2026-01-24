class Solution {
public:



    void bfs(int n, vector<vector<int>>& graph, vector<bool>& isVisited, int source) {
        queue<int> q;
        q.push(source);
        isVisited[source] = true;


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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }

        vector<bool> isVisited(n, false);
        bfs(n, graph, isVisited, source);
        return isVisited[destination];




    }
};