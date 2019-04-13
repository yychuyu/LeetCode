class Solution:
    def isIsomorphic(self, s, t):
        for i in range(len(s)):
            if(s.find(s[i]) != t.find(t[i])):
                return False
        return True