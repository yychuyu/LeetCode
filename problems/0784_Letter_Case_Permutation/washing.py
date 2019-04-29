class Solution(object):
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        str_list = [""]
        for i in range(len(S)):
            length = len(str_list)
            for j in range(length):
                str_list.append(str_list[j] + S[i].lower())
                try:
                    int(S[i])
                except:
                    str_list.append(str_list[j] + S[i].upper())
            str_list = str_list[length:]

        return str_list