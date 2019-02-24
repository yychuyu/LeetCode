class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) > len(t): return False
        if not s: return True
        
        i = 0
        for c in t:
            if c == s[i]:
                if i == len(s) - 1: return True
                else: i += 1
        return False
