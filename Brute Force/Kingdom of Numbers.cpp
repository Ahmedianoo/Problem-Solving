#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check_validity(vector<int> currentValidGroup, int newValue) {
	if(currentValidGroup.empty()) {
		return true;
	}

	for(int i = 0; i < (int)currentValidGroup.size(); i++) {
		if (!(currentValidGroup[i] % newValue == 0 || newValue % currentValidGroup[i] == 0)) {
			return false;
		}
	}

	return true;


}

void kingdom_of_numbers(int N, int index, const vector<int>& numbers, vector<bool> isVisited,
	 vector<int> currentValidGroup, vector<int>& maxValidGroup) {

	if (index == N) {
		return;
	}


	for (int i = 0; i < N; i++) {

		if (!isVisited[i]) {
			if (!check_validity(currentValidGroup, numbers[i])) {
				continue;
			}
			if (currentValidGroup.size() + 1  > maxValidGroup.size()) {
				maxValidGroup = currentValidGroup;
				maxValidGroup.push_back(numbers[i]);
			}


			isVisited[i] = true;
			currentValidGroup.push_back(numbers[i]);
			kingdom_of_numbers(N, index + 1, numbers, isVisited, currentValidGroup, maxValidGroup);
			currentValidGroup.pop_back();
			isVisited[i] = false;
		}
	}


}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
	cin >> N;
	vector<int> numbers(N);
	vector<bool> isVisited(N, false);
	vector<int> cuerrentValidGroup;
	vector<int> maxValidGroup;
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	kingdom_of_numbers(N, 0, numbers, isVisited, cuerrentValidGroup, maxValidGroup);

	for(int i = 0; i < (int)maxValidGroup.size(); i++) {
		cout << maxValidGroup[i] << " ";
	}



    return 0;
}
