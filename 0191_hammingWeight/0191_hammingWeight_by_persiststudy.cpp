/***************************************************************
*   
*
*   文件名称：0191_hammingWeight_by_persiststudy.cpp
*   创 建 者：persiststudy
*   创建日期：2018年12月19日
*   描    述：https://leetcode-cn.com/problems/number-of-1-bits/
*
***************************************************************/

#include <cstdio>

typedef unsigned int uint32_t;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n)
        {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};

int main()
{
    Solution a;
    uint32_t n;
    scanf("%d", &n);
    printf("%d", a.hammingWeight(n));
    return 0;
}
