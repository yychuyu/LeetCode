//买股票的最佳时间
//动态规划
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0,begin = 0,end = 0,delta = 0;
        for(int i =0; i < prices.size();i++)
        {
            end = i;
            delta = prices[end] - prices[begin];
            if(delta <= 0)
            {
                begin = i;
            }
            if(delta > max)
            {
                max = delta;
            }
        }
        return max;
    }
};

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    Solution method;
    cout << method.maxProfit(prices);
    return 0;
}
