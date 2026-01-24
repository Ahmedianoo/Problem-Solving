#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INT_MAX 2147483647


void move_string_characters(string& s) {
    char c = s[0];
    s.erase(0, 1);
    s = s + c;
}


int isEqual(const vector<string>& strings, int currentStringIndex) {

    int count = 0;

    for (int i = 0; i < strings.size(); i++) {
        if(i != currentStringIndex) {
            if(strings[i] == strings[currentStringIndex]){
                continue;
            }
			string temp = strings[i];
			int tempCount = 0;
            for (int j = 0; j < temp.size(); j++) {
				move_string_characters(temp);
				tempCount++;
                if (temp == strings[currentStringIndex]) {
                    break;
                }
                if(j == temp.size() - 1) return -1;


            }
            count = count + tempCount;

		}

    }

    return count;

}


int String_reArrangement(const vector<string>& strings) {

    int currentCount;
	int minCount = INT_MAX;
    for (int i = 0; i < strings.size(); i++) {
		currentCount = isEqual(strings, i);
        if(currentCount == -1) {
            return -1;
		}
        if (currentCount < minCount) {
			minCount = currentCount;
        }

    }
	return minCount;

}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;

    vector<string> strings(n);
    for(int i = 0; i < n; i++) {
        cin >> strings[i];
	}

	cout << String_reArrangement(strings);




    return 0;
}
