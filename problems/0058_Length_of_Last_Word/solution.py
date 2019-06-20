# 此题难度角度，主要就是依据空格对字符串进行分词
# 在此过程中，需要注意的是需要把字符串默认的空格去掉
class Solution:
    def lengthOfLastWord(self, s):
        cnt, tail = 0, len(s) - 1
        while tail >= 0 and s[tail] == ' ':
            tail -= 1
        while tail >= 0 and s[tail] != ' ':
            cnt += 1
            tail -= 1
        return cnt
