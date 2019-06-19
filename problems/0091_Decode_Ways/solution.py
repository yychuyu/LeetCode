# 利用动态规划的思想来解决
# 当前的字符串和前一个字符串组合之后的数值如果在解码的范围内
# 就可以把当前的字符串和上一次的独立字符串进行合并
# 合并的结果加上上一个字符串解码的结果就是当前字符串解码的结果
# 如果是0，就需要特殊处理，0如果和前一个字符串组合后在解码范围内
# 新产生的解码串就全部是合并的，没有独立的字符串
# 如果不能和前一个字符串合并的话，那就是无法解码的字符串，直接返回0
class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == '0':
            return 0
        t1 = t2 = 1
        for i in range(1, len(s)):
            su = int(s[i-1] + s[i])
            if su >=1 and su <= 26:
                if s[i] != '0':
                    t3 = t2
                    t2 += t1
                    t1 = t3
                else:
                    t2 = t1
                    t1 = 0
            else:
                if s[i] != '0':
                    t1 = t2
                else:
                    return 0
        return t2
