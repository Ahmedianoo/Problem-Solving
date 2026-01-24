#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int get_num_sum(int num) {
    num = abs(num);
    string s = to_string(num);
    int sum = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        sum = sum + s[i] - '0';
    }

    //while (num > 0) {
    //    sum = sum + num % 10;
    //    num = num / 10;
    //}

    return sum;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int l, r;
    cin >> l >> r;
    int max = l;

    for (int i = l; i <= r; i++) {
        if (get_num_sum(i) > get_num_sum(max)) max = i;
        if (get_num_sum(i) == get_num_sum(max))
            if (i < max) max = i;
    }

    cout << max;

    return 0;
}
