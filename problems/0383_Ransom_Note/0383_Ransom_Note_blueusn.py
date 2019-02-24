from matplotlib import collections


class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        c=collections.Counter(magazine)
        for i in ransomNote:
            if c[i]==0 or i not in c:
                return False
            else:
                c[i]-=1
        return True