#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int get_vec_sum(vector<int> vec) {
	int sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		sum = sum + vec[i];
	}

	return sum;
}


void min_machine_alloc(int l, int n, vector<int> tasks, int index, vector<bool> isVisited,
	vector<vector<int>> groups, vector<vector<int>> groups_indexes, int& min, vector<vector<int>>& min_groups) {

	if (index == n) {
		if (min > (int)groups_indexes.size()) {
			min = (int)groups_indexes.size();
			min_groups = groups_indexes;
		}
		return;
	}


	for (int i = 0; i < n; i++) {
		bool newGroup = true;
		if (groups.size() != 0 && get_vec_sum(groups[groups.size() - 1]) + tasks[i] <= l) {
			groups[groups.size() - 1].push_back(tasks[i]);
			groups_indexes[groups_indexes.size() - 1].push_back(i);
			newGroup = false;
		}
		else {
			groups.push_back({ tasks[i] });
			groups_indexes.push_back({ i });
		}

		if (!isVisited[i]) {
			isVisited[i] = true;
			min_machine_alloc(l, n, tasks, index + 1, isVisited, groups, groups_indexes, min, min_groups);
			isVisited[i] = false;
		}

		if (!newGroup) {
			groups[groups.size() - 1].pop_back();
			groups_indexes[groups_indexes.size() - 1].pop_back();
		}
		else {
			groups.pop_back();
			groups_indexes.pop_back();
		}

	}
}


int main() {
	int l, n;
	cin >> l;
	cin >> n;
	vector<int> tasks(n);
	vector<bool> isVisited(n, false);
	vector<vector<int>> groups, groups_indexes;
	vector<vector<int>> min_groups;
	int min = INT_MAX;

	for (int i = 0; i < n; i++) {
		cin >> tasks[i];
	}

	min_machine_alloc(l, n, tasks, 0, isVisited, groups, groups_indexes, min, min_groups);

	cout << min << endl;
	for (int i = 0; i < min_groups.size(); i++) {
		for (int j = 0; j < min_groups[i].size(); j++) {
			cout << min_groups[i][j] << " ";
		}
		cout << endl;
	}



}

