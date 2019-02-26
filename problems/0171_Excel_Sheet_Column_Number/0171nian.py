class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        result=0
        for i in range(len(s)):
            result+= (ord(s[i])-64)*(26**(len(s)-i-1))
        return result
