class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        for i in range(len(s)):
            if(s.find(s[i]) != t.find(t[i])):
                return False
        return True