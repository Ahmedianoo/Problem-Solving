#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printPath(const vector<string>& currentPath) {
    for (const auto& name : currentPath) {
        cout << name << " ";
    }
    cout << endl;
}


void chairs_game(const vector<string>& personsNames, vector<string> currentPath, vector<bool> isVisited, int index, int& count) {
    if((int)personsNames.size() == 1) { 
        count++; 
        return;
	}
    
    if (index == (int)personsNames.size()) { 
		//printPath(currentPath);
        count++;
        return;
    }

    //if (index != 0 && index  && currentPath[index - 1].back() == currentPath[index].front()) {
    //    return 0;
    //}

    /*int count = 0;*/
    for (int i = 0; i < (int)personsNames.size(); i++) {
        if (!isVisited[i]) {
            if (index != 0 && tolower(currentPath[index - 1].back()) == tolower(personsNames[i].front())) {
                continue;
            }
            isVisited[i] = true;
			currentPath.push_back(personsNames[i]);
			chairs_game(personsNames, currentPath, isVisited, index + 1, count);
			currentPath.pop_back();
            isVisited[i] = false;
        }
    }


}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
	vector<string> personsNames(N);
    vector<bool> isVisited(N, false);
	vector<string> currentPath;

    for(int i = 0; i < N; i++) {
        cin >> personsNames[i];
	}
    int count = 0;

    chairs_game(personsNames, currentPath, isVisited, 0, count);

    cout << count;
    
    return 0;
}
