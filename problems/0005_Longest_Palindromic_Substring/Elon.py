class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        maxl , maxi = 0 , 0
        if (len(s)<2):
            return s
        for i in range(len(s)-1):
            l = max(self.extent(s,i,i),self.extent(s,i,i+1))
            if maxl < l:
                maxl = l
                maxi = i
        
        return s[maxi-maxl//2:maxi+(maxl+1)//2+1]
    def extent(self,s,start,end):
        while start >= 0 and end < len(s) and s[start] == s[end]:
            start = start - 1
            end = end +1
        return (end - start-2)
    