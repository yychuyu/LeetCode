class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        ans = 0
        l = s[0]
        for i in s:
            if i not in l:
                l += i
            else:
                ans = len(l) if ans < len(l) else ans
                l = l[l.find(i)+1:] + i
        ans = len(l) if ans < len(l) else ans
        return ans