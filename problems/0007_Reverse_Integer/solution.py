# 通过不断循环取余,对应的余数乘以10,然后再累加,就可以得到结果
# 只不过要注意对负数的处理,同时注意数值的取值范围

class Solution:
    def reverse(self, x):
        result = 0
        flag = -1 if x < 0 else 1
        x = abs(x)
        while x != 0:
            pop = x % 10
            x = x / 10
            result = result * 10 + pop
        result *= flag
        if result < - 2 ** 31 or result > 2 ** 31 -1:
            return 0
        return result