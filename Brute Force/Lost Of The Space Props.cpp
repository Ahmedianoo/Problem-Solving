#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INT_MAX 2147483647

int getMinDistance(vector<pair<int, int>> props, int index) {

	int min = INT_MAX;
    for(int i = 0; i < props.size(); i++) {
        if(!(i == index)){
            int x = props[index].first - props[i].first;
            int y = props[index].second - props[i].second;
            int distance = sqrt(x * x + y * y);
            if (distance < min) {
                min = distance;
            }
            
        
        }

	}

	return min;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
	vector<pair<int, int>> propes(n);

    for (int i = 0; i < n; i++) {
		cin >> propes[i].first >> propes[i].second;
    }

    int min = INT_MAX;
    int tempMin;
    for (int i = 0; i < n; i++) {
		tempMin = getMinDistance(propes, i);
        if (tempMin < min) {
			min = tempMin;
        }
    }

    cout << min;
    return 0;
}
