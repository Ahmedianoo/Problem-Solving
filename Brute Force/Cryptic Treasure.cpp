#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check_if_equal(string s, string k, int index) {
    int j = 0;
    for (int i = index; i < (int)s.size() && j < (int)s.size(); i++) {
        if (k[j] != s[i]) {
            return false;
        }
        j++;
    }

    return true;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    string k;
    cin >> s;
    cin >> k;
    if (k.size() > s.size()) {
        cout << 0;
        return 0;
    }

    
    int lastIndex = (int)s.size() - (int)k.size() + 1;
    int count = 0;

    for (int i = 0; i < lastIndex; i++) {
        if (check_if_equal(s, k, i)) {
            count++;
        }
    }


    cout << count;
    return 0;
}
