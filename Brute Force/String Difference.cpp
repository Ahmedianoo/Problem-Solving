#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//---------------------------String Difference--------------------------------Brute Force----------------------- 
//4 2 input 
// output
//0011
//0101
//0110
//1001
//1010
//1100

//void printString(vector<int> indexes, int size) {
//    for (int i = 0; i < size; i++) {
//        if (indexes[i] == 0) {
//            cout << "0";
//        }
//        else {
//            cout << "1";
//        }
//    }
//    cout << endl;
//    return;
//}
//
//
//void update_indexes(vector<int> indexes, int N, vector<int> indexToSkip) {
//    for (int i = 0; i < N; i++) {
//        if (i != indexToSkip[i]) {
//            indexes[i] = 1;
//        }
//        else {
//            indexes[i] = 0;
//        }
//    }
//}
//
//
//
//void string_difference(int N, int H, int currentN, vector<int> indexes, vector<int> indexToSkip) {
//    if (currentN == H) {
//        update_indexes(indexes, N, indexToSkip);
//        printString(indexes, N);
//        return;
//    }
//
//    for (int i = 0; i < currentN; i++) {
//        
//        if (i != indexToSkip[i]) {
//            auto newSkip = indexToSkip;
//            newSkip.push_back(currentN - i);
//            string_difference(N, H, currentN - 1, indexes, newSkip);
//        }
//        
//    }
//
//
//
//}



void generateString(int N, int H, string currentString) {

    if (currentString.size() == N) {
        cout << currentString << endl;
        return;
    }


    if (N - currentString.size() > H) {
        generateString(N, H, currentString + "0");
    }

    if (H > 0) {
        generateString(N, H - 1, currentString + "1");
    }
}

int main() {


    int N, H;
    cin >> N >> H;



    generateString(N, H, "");






}