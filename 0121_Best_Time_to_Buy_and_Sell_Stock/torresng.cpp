/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     Torres Ng
*   Create Time 2018/12/07
*
***************************************************************/
/**************************************************************
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

    Input: [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
                 Not 7-1 = 6, as selling price needs to be larger than buying price.

Example 2:

    Input: [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transaction is done, i.e. max profit = 0.
***************************************************************/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = numeric_limits<int>::max(), res = 0;
        for(int price : prices) {
            buy = min(buy, price);
            res = max(res, price - buy);
        }
        return res;
    }
};


int main(void) {
	Solution s = Solution();

    vector<int> vec {7,1,5,3,6,4};
	cout << "Input: [7,1,5,3,6,4]" << endl << "Output: " << s.maxProfit(vec) << endl;
    vec = {7,6,4,3,1};
	cout << "Input: [7,6,4,3,1]" << endl << "Output: " << s.maxProfit(vec) << endl;
	return 0;
}
