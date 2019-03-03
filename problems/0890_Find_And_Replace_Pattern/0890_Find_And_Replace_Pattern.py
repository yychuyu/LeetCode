class Solution:
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        res = []
        set_pattern = set(pattern)
        for word in words:
            if len(set(word))!= len(set_pattern):
                continue
            flag = 1
            fx = dict()
            for i,w in enumerate(word):
                if w in fx:
                    if fx[w] != pattern[i]:
                        flag = 0
                        break
                fx[w] =  pattern[i]
            if flag:
                res.append(word)
        return res