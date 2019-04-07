/*
1、把添加符号的操作看做每次加上或者减去数字，
可以加上或者减去的数字分别为 1, x, x^2, x^3, ...。
2、从需要多少个 1 开始考虑，给定了 target，
可以贪心的想一下：如果 target % x 为 0，则我们一定不需要 1；
如果 cur = target % x 不为 0，则我们需要的 1 的个数有两种选择：
一、是加上 cur 个 1，余下为target-cur，可以整除
二、是减去 x - cur 个 1
*/
class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        int pos = 0, neg = 0, y = target, k, pos2, neg2, cur;
        for (k = 0; y > 0; ++k, y = y / x){
            cur = y % x;//取余数，第一次运算时确定1的个数
            if (k > 0){
                pos2 = min(cur*k + pos, (cur + 1)*k + neg);
                neg2 = min((x - cur)*k + pos,(x - cur -1)*k + neg);
                pos = pos2,neg = neg2;
            }
            else{
                pos = cur*2;//
                neg = (x - cur) * 2;//
            }

        }
        return min(pos,k + neg) - 1;
    }
};