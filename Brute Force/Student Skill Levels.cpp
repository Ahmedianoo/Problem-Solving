#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//int get_sum(vector<int> currentLevels, int K) {
//    int sum = 0;
//    for (int i = 0; i < K; i++) {
//        sum = sum + currentLevels[i];
//    }
//
//    return sum;
//}
//
//bool check_string_exist(string s, vector<string> vec) {
//
//    for (int i = 0; i < (int)vec.size(); i++) {
//        if (s == vec[i]) return true;
//
//    }
//
//    return false;
//}
//
//bool check_vec_and_vec(vector<string> current, vector<string> inAllVectors) {
//    for (int i = 0; i < (int)current.size(); i++) {
//        if(check_string_exist(current[i], inAllVectors)) return true;
//    }
//    return false;
//}


int countString(string s, vector<string> vec) {

    int count = 0;
    for (int i = 0; i < (int)vec.size(); i++) {
        if (s == vec[i]) count++;

    }

    return count;
}


bool check_string_duplicate(vector<string> currentNames) {
    
    for (int i = 0; i < (int)currentNames.size(); i++) {
        int count = countString(currentNames[i], currentNames);
        if (count >= 2) {
            return false;
        }
    }

    return true;
}


int get_sum(vector<int> currentLevels, int K) {
    int sum = 0;
    for (int i = 0; i < K; i++) {
        sum = sum + currentLevels[i];
    }

    return sum;
}

void student_skill_level(vector<string> studentsNames, vector<int> studentsLevels, int N, int K, int minL,
    vector<int> isVisited, vector<string> currentNames, vector<int> currentLevels, int index, int& count,
    int startIndex
) {

    if (index == K) {

        if (check_string_duplicate(currentNames)) {
            if (get_sum(currentLevels, K) >= minL) {
                count++;
            }
        }

        return;
    }

    for (int i = startIndex; i < N; i++) {
        if (!isVisited[i]) {
            isVisited[i] = true;
            currentNames.push_back(studentsNames[i]);
            currentLevels.push_back(studentsLevels[i]);
            student_skill_level(studentsNames, studentsLevels, N, K, minL, isVisited, currentNames, currentLevels,
                index + 1, count, i + 1);
            currentNames.pop_back();
            currentLevels.pop_back();
            isVisited[i] = false;
        }
    }

}




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, K, minL;
    cin >> N >> K >> minL;

    vector<string> studentsNames(N);
    vector<int> studentsLevels(N);
    vector<int> isVisited(N, false);
    vector<string> currentNames;
    vector<int> currentLevels;
    vector<vector<string>> currentVectors;
    int count = 0;

    for (int i = 0; i < N; i++) {
        cin >> studentsNames[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> studentsLevels[i];
    }

    student_skill_level(studentsNames, studentsLevels, N, K, minL, isVisited, currentNames, currentLevels, 0,
        count, 0);


    cout << count;







    return 0;
}

