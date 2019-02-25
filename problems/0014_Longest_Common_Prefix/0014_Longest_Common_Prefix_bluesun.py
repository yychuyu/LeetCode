class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        prefix = ""
        if len(strs) == 0:
            return ""
        len_list = []
        for i in range(len(strs)):
            len_list.append(len(strs[i]))

        for i in range(min(len_list)):
            flag = strs[0][i]
            for j in range(len(strs)):
                if flag:
                    if flag != strs[j][i]:
                        return prefix
            prefix += flag
        return prefix