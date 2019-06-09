class Solution:
    def strStr(self, haystack, needle):
        if needle:
            res = haystack.find(needle)
            return res
        else:
            return 0