#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int get_sum(int first, int n) {
    int newNumber = 0;
    int sum = 0;

    while (newNumber <= n) {
        newNumber = newNumber + first;
        sum = sum + newNumber;
    }

    if (newNumber > n) {
        sum = sum - newNumber;
    }

    return sum;


}

int max_factory_output(int& sum, int n) {
    int tempSum = 0;
    int index = 2;
    
    vector<int> indexes(n+3);

    for (int i = 2; i <= n; i++) {

        tempSum = get_sum(i, n);
        if (tempSum > sum) {
            sum = tempSum;
            index = i;
        }
    }

    return index;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    int sum = 0;

    cout << max_factory_output(sum, n);

   


    


    return 0;
}
