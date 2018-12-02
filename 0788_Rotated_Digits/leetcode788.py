# !/usr/bin/env python3
# -*- coding:utf-8 -*-

class Solution:     # 76ms
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        res = 0
        for i in range(1, N + 1):
            s_i = str(i)
            if '3' not in s_i and '4' not in s_i and '7' not in s_i:
                if '2' in s_i or '5' in s_i or '6' in s_i or '9' in s_i:
                    res += 1
        return res
    '''
    def rotatedDigits1(self, N):   # 116ms
        """
        :type N: int
        :rtype: int
        """
        def is_valid(n):
            found = False
            while n:
                x = n % 10
                if x in [3, 4, 7]:
                    return False
                if x in [2, 5, 6, 9]:
                    found = True
                n = n // 10
            return found
        res = 0
        for n in range(1, N + 1):
            if is_valid(n):
                res += 1
        return res
    '''
    '''
    def rotatedDigits2(self, N):   # 204ms
        """
        :type N: int
        :rtype: int
        """
        novalid = [3, 4, 7]
        valid = [2, 5, 6,9]
        def isGood(num):
            for x in novalid:
                if str(x) in str(num):
                    return False
            return any(str(y) in str(num) for y in valid)   # 不存在返回False
        return sum(map(int, [isGood(n) for n in range(1, N + 1)]))
    '''