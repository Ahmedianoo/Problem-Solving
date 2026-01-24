#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void recorder(vector<int> songs, int M, int S, int& max, int index, vector<int> isVisited, int sum) {
    
    if (max < sum) {
        max = sum;
    }
    if (index == M) return;


    for (int i = 0; i < S; i++) {
        if (sum + songs[i] > M) {
            continue;
        }
        if (!isVisited[i]) {
            isVisited[i] = true;
            recorder(songs, M, S, max, index + 1, isVisited, sum + songs[i]);
            isVisited[i] = false;
        }
    }
}


void simple_recorder(vector<int> songs, int M, int S, int& max, int index, int sum) {
    if (sum > M) return;
    if (max < sum) {
        max = sum;
    }
    if (index == M) return;
    simple_recorder(songs, M, S, max, index + 1, sum + songs[index]);
    simple_recorder(songs, M, S, max, index + 1, sum);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int M, S;
    cin >> M >> S;
    vector<int> songs(S);
    for (int i = 0; i < S; i++) {
        cin >> songs[i];
    }
    int max = 0;
    vector<int> isVisted(S, false);
    int sum = 0;

    recorder(songs, M, S, max, 0, isVisted, sum);
    //simple_recorder(songs, M, S, max, 0, sum); // more complex
    cout << max;


    return 0;
}
