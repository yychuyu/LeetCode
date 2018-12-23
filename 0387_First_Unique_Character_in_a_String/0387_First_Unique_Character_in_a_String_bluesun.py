class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        flag_list = []
        for i in range(len(s)):
            if s[i] not in flag_list:
                if s.count(s[i]) == 1:
                    return i
                else:
                    flag_list.append(s[i])
        return -1