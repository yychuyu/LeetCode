/*显然行不通
int trailingZeroes(int n) {
    //求阶乘
    unsigned long long int sum = 1;
    while (n != 0) {
        sum *= n;
        n--;
    }
    printf("%llu\n", sum);
    //拆解数字
    int cnt = 0;
    while (sum != 0) {
        int digit = (int)(sum % 10);  //括号不能漏
        sum /= 10;
        printf("%d ", digit);
        if (digit == 0) cnt++;
        else break;  //遇非零结束
    }
    return cnt;
}
*/

/*
// 将 n! 分解质数, 10=2*5, 2 远多于 5，对 5 计数
int trailingZeroes(int n) {
    int cnt = 0;
    for (; n >= 1; n--) {
        int temp = n;
        while (temp % 5 == 0) {
            cnt++;
            temp /= 5;
        }
    }
    return cnt;
}
*/

// //解释：https://leetcode.com/problems/factorial-trailing-zeroes/discuss/52373/Simple-CC%2B%2B-Solution-(with-detailed-explaination)
// int trailingZeroes(int n) {
//     int sum = 0;
//     while (n != 0) {
//         sum += n / 5;
//         n /= 5;
//     }
//     return sum;
// }

//上面方法的递归形式
int trailingZeroes(int n) {
    return n == 0 ? 0 : n/5 + trailingZeroes(n/5);
}
