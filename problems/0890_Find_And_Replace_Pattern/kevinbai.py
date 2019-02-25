class Solution:
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        returnList = []

        for word in words:
            permutationDict = {}
            for x, px in zip(pattern, word):
                if x not in permutationDict.keys():
                    permutationDict[x] = px
                if len(set(permutationDict.keys())) != len(set(permutationDict.values())):
                    break
                if permutationDict[x] != px:
                    break
            else:
                returnList.append(word)

        return returnList
