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
#include <stdio.h>
#include <limits.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int maxProfit(int* prices, int pricesSize) {
    int buy = INT_MAX, res = 0;
    for(int i = 0; i < pricesSize; i++) {
        buy = MIN(buy, prices[i]);
        res = MAX(res, prices[i] - buy);
    }
    return res;
}


int main(void) {
    int vec1[] = {7,1,5,3,6,4};
    int size = 6;
    printf("Input: [7,1,5,3,6,4]\nOutput: %d\n", maxProfit(vec1, size));
    int vec2[] = {7,6,4,3,1};
    size = 5;
    printf("Input: [7,6,4,3,1]\nOutput: %d\n", maxProfit(vec2, size));
	return 0;
}
