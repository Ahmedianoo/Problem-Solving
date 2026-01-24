#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

//#define lolo long long


pair<int, int> min_shots(int current_health, vector<int>& weapons, int n, int m, vector<pair<int, int>>& dp_shots, int min_weapon) {
    //min_health = min(min_health, current_health);
    if (current_health == 0) return { 0, 0 };
    /*if (current_health < 0) return INT_MAX;*/
    if (dp_shots[current_health].first != -1) {
        return dp_shots[current_health];
    }

    if (current_health < min_weapon) {
        return dp_shots[current_health] = { 0, current_health };
    }

    int ways = INT_MAX;
    int min_health = current_health;
    for (int i = 0; i < m; i++) {
        if (weapons[i] <= current_health) {
            /*int curr_min_health = current_health - weapons[i];*/
            pair<int, int> sol = min_shots(current_health - weapons[i], weapons, n, m, dp_shots, min_weapon);
            int new_shots = sol.first + 1;
            int new_health = sol.second;

            if (new_health < min_health || (new_shots < ways && new_health == min_health)) {
                ways = new_shots;
                min_health = new_health;
            }
        }

    }

    // if (ways == INT_MAX) {
    //    ways = 0;
    //    min_health = current_health;
    // }


    return dp_shots[current_health] = { ways, min_health };
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> monsters(n);
    int max_monster = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> monsters[i];
        max_monster = max(max_monster, monsters[i]);
    }

    int m;
    cin >> m;
    vector<int> weapons(m);
    for (int i = 0; i < m; i++) {
        cin >> weapons[i];
    }

    vector<int> remove_zeros;
    for (int i = 0; i < m; i++) {
        if (weapons[i] > 0) {
            remove_zeros.push_back(weapons[i]);
        }
    }
    weapons = remove_zeros;
    m = weapons.size();

    int min_weapon = INT_MAX;
    for (int i = 0; i < m; i++) {
        min_weapon = min(min_weapon, weapons[i]);
    }


    /*cout << min_shots(monsters[0], weapons, n, m, dp_shots);*/
    vector<pair<int, int>> dp_shots(max_monster + 1, { -1, -1 });
    for (int i = 0; i < n; i++) {
        /*int min_health = monsters[i];*/
        pair<int, int> count = min_shots(monsters[i], weapons, n, m, dp_shots, min_weapon);
        cout << count.second << " " << count.first << endl;
    }

    return 0;
}
