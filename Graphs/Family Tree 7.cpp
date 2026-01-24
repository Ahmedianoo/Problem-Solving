#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void dfs(vector<vector<int>>& family, int node, vector<bool>& isVisited, stack<int>& st) {
    isVisited[node] = true;
    for (int i = 0; i < (int)family[node].size(); i++) {
        int next = family[node][i];
        if (!isVisited[next]) {
            dfs(family, next, isVisited, st);
        }
    }
    st.push(node);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<vector<int>> family(n);
    for (int i = 0; i < n; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        if (p1 != -1) family[p1].push_back(i);
        if (p2 != -1) family[p2].push_back(i);
    }

    vector<bool> isVisited(n, false);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (!isVisited[i]) dfs(family, i, isVisited, st);
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}