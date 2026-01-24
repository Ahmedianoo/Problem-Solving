#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int is_killer(string name1, string name2, string suspect, int i, int j, int index, vector<vector<int>>& dp) {
    if (index == (int)suspect.size()) return 1;
    if (dp[i][j] != -1) return dp[i][j];

    int isKiller = 0;
    if (i != (int)name1.size() && name1[i] == suspect[index]) {
        isKiller |= is_killer(name1, name2, suspect, i + 1, j, index + 1, dp);
    }

    if (j != (int)name2.size() && name2[j] == suspect[index]) {
        isKiller |= is_killer(name1, name2, suspect, i, j + 1, index + 1, dp);
    }

    return dp[i][j] = isKiller;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    string name1, name2;
    cin >> name1 >> name2;
    vector<string> suspects(n);
    for (int i = 0; i < n; i++) {
        cin >> suspects[i];
    }


    for (int i = 0; i < n; i++) {
        vector<vector<int>> dp((int)name1.size() + 1, vector<int>((int)name2.size() + 1, -1));
        int isKiller = is_killer(name1, name2, suspects[i], 0, 0, 0, dp);
        cout << isKiller << endl;
    }
    return 0;
}
