#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


void dfs(int current_task, vector<vector<int>>& robots, vector<bool>& isVisited, stack<int>& st) {
    isVisited[current_task] = true;

    for (int i = 0; i < (int)robots[current_task].size(); i++) {
        int next_task = robots[current_task][i];
        if (!isVisited[next_task]) {
            dfs(next_task, robots, isVisited, st);
        }
    }

    st.push(current_task);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<vector<int>> robots(n);
    for (int i = 0; i < n; i++) {
        int r1, r2;
        cin >> r1 >> r2;
        if (r1 != -1) robots[r1].push_back(i);
        if (r2 != -1) robots[r2].push_back(i);
    }

    stack<int> st;
    vector<bool> isVisited(n, false);
    for (int i = 0; i < n; i++) {
        if (!isVisited[i]) {
            dfs(i, robots, isVisited, st);
        }
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }



    return 0;
}