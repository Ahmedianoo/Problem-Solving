#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




void count_crying_faces(string s, int n, string currS, int index, int& count) {
    if (currS == "QAQ") {
        count++;
        return;
    }

    if (currS.size() == 3) return;

    for (int i = index; i < n; i++) {
           count_crying_faces(s, n, currS + s[i], i + 1, count);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    cin >> s;
    int n = s.size();

    string currS = "";
    int count = 0;
    

    count_crying_faces(s, n, currS, 0, count);

    cout << count;


    return 0;
}
