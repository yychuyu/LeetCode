class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """

        # if (len(needle)==0):
        #     return 0
        # else:
        #     return haystack.find(needle)

        if (len(needle) == 0):
            return 0

        for i in range(len(haystack) - len(needle) + 1):
            if haystack[i] != needle[0]:
                continue
            elif haystack[i:(len(needle) + i)] == needle:
                return i
        return -1