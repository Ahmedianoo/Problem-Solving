#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define lolo long long

bool compare_penalty(pair<int, int> ass1, pair<int, int> ass2) {
    if (ass1.second > ass2.second) {
        return true;
    }
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<pair<int, int>> assignments(n);
    vector<int> slots(n, 0);

    for (int i =0; i < n; i++) {
        cin >> assignments[i].first;
    }

    for (int i = 0; i < n; i++) {
        cin >> assignments[i].second;
    }

    sort(assignments.begin(), assignments.end(), compare_penalty);
    
    lolo minPenalty = 0;
    for (int i = 0; i < n; i++) {

        int currAssDeadline = assignments[i].first;
        if (slots[currAssDeadline - 1] == 0) { 
            slots[currAssDeadline - 1] = 1;
        }
        else {
            bool found = false;
            for (int j = currAssDeadline - 2; j >= 0; j--) {
                if (slots[j] == 0) {
                    slots[j] = 1;
                    found = true;
                    break;
                }
            }
            if (!found) {
                minPenalty = minPenalty + assignments[i].second;
            }
        }
    }



    
    cout << minPenalty;



    return 0;
}
