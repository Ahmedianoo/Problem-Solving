#include <iostream>
#include <vector>

using namespace std;

//[7,1,5,3,6,4]
// straight forward is to traverse the array, compare the day with days after it 
//      and create each time update the max profit, it will take like n root(n), too much time

// faster way
// we could save two values. maxProfit and current day
// the ,maxProfit holds the ,maximum profit achieved
// the current day works like that
// at the beginning it holds a day we compare that day to the one after it
// if the next number is larger we subtract and update the max profit and keep the current day not changed
// if it is smaller we update the current day and keep the max profit unchanged
// this achieves O(n)
int maxProfit(vector<int>& prices) {
    int currentDayPrice = prices[0];
    int maxProfit = 0;
    int numOfDays = prices.size();
    for(int i = 1; i < numOfDays; i++){
        int nextDayPrice = prices[i];
        if(nextDayPrice > currentDayPrice){
            maxProfit = max(maxProfit, nextDayPrice - currentDayPrice);
        } else{
            currentDayPrice = nextDayPrice;
        }
    }

    return maxProfit;
}

// it is a two pointers problem
// but this solution took less time on leetcode

int main(){



}