#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void count_special_substring(string s, char currentChar, int cuerrentIndex, int n, int& count) {
    if (cuerrentIndex == n) {
        return;
    }

    if (currentChar == s[cuerrentIndex]) {
        count = count + 1;
    }
    count_special_substring(s, currentChar, cuerrentIndex + 1, n, count);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    cin >> s;
    int n = (int)s.size();

    int count = 0;

    for (int i = 0; i < n; i++) {
        count_special_substring(s, s[i], i, n, count);
    }

    cout << count;

    return 0;
}
