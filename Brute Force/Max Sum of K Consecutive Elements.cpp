#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int get_sum(const vector<int>& A, int currentIndex, int K) {
    int sum = 0;
    for (int i = currentIndex; i < currentIndex + K; i++) {
        sum = sum + A[i];
    }
    return sum;
}

void get_max_sum(int N, int K, const vector<int>& A, int& maxSum) {

    int tempSum = 0;
    for (int i = 0; i < N - K + 1; i++) {
        tempSum = get_sum(A, i, K);
        if (tempSum > maxSum) {
            maxSum = tempSum;
        }
    }

}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, K;
    cin >> N >> K;

	vector<int> A(N);

    for (int i = 0; i < N; i++) {
		cin >> A[i];
    }

    int maxSum = -2000000;

    get_max_sum(N, K, A, maxSum);

    cout << maxSum;





    return 0;
}
