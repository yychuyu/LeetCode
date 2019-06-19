class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        s = str(x)
        if s.startswith("-"):
            s = '-' + s[1:][::-1]
        else:
            s = s[::-1]
            
        ans = int(s)
        
        if -2147483648 > ans or 2147483647 < ans:
            ans = 0
        
        return ans