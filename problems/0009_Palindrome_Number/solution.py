# 主要是利用python的切片操作,来实现字符串的反转

class Solution:
    def isPalindrome(self, x):
        if x < 0:
            return False
        else:
            y = str(x)[::-1]
            if y == str(x):
                return True
            else:
                return False