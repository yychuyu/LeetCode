/***************************************************************
*   
*
*   文件名称：0069_Sqrtx_by_persiststudy.cpp
*   创 建 者：persiststudy
*   创建日期：2018年12月13日
*   描    述：二分法求根
*
***************************************************************/


#include <cstdio>
typedef long long ll;
class Solution
{
public:
    int mySqrt(int n)
    {
        int l = 0;
        int r = n;
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if ((ll)mid * (ll)mid <= (ll)n)
            {
                if (mid == n || (ll)(mid + 1) * (ll)(mid + 1) > (ll)n)
                {
                    return mid;
                }
                l = mid + 1;
            } else
            {
                r = mid - 1;
            }
        }
    }
};
int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", Solution().mySqrt(n));
    return 0;
}
