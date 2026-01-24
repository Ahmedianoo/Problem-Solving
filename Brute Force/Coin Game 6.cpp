#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool collect_pounds(const vector<int>& values, int sum, int T, int index) {
    if (sum == T) return true;
    if (index == values.size()) return false;

    bool b1 = collect_pounds(values, sum, T, index + 1);
    bool b2 = collect_pounds(values, sum + values[index], T, index + 1);

    if (b1 || b2) return true;
    else return false;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T, N;
    cin >> T;
    cin >> N;

    vector<int> values(N);

    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }



    cout << collect_pounds(values, 0, T, 0);

    return 0;
}