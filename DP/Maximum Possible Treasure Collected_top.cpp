#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




long long max_treasure(vector<int>& chests, vector<long long>& dp, int n, int index) {
    if (index >= n) {
        return 0;
    }
    if (dp[index] != -1) return dp[index];
    
    long long include = chests[index] + max_treasure(chests, dp, n, index + 2);
    long long skip = max_treasure(chests, dp, n, index + 1);

    
    return dp[index] = max(include, skip);

}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   int n;
   cin >> n;
   vector<long long> dp(n, -1);
   vector<int> chests(n);
   for (int i = 0; i < n; i++) {
       cin >> chests[i];
   }

   long long max = max_treasure(chests, dp, n, 0);
   cout << max;



    return 0;
}
