#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


void dfs(vector<vector<int>>& blocks, int node, vector<bool>& isVisited, stack<int>& st) {
    isVisited[node] = true;
    for (int i = 0; i < (int)blocks[node].size(); i++) {
        int nextNode = blocks[node][i];
        if (!isVisited[nextNode]) {
            dfs(blocks, nextNode, isVisited, st);
        }
    }

    st.push(node);
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<vector<int>> blocks(n);
    for (int i = 0; i < n; i++) {
        int b1, b2;
        cin >> b1 >> b2;
        if (b1 != -1) blocks[b1].push_back(i);
        if (b2 != -1) blocks[b2].push_back(i);
    }

    vector<bool> isVisited(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (!isVisited[i]) dfs(blocks, i, isVisited, st);
    }



    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }


    return 0;
}
