from functools import reduce

class Solution:
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        list_words = []
        for i in words:
            if self.sum_list_pattern(i) == self.sum_list_pattern(pattern):
                list_words.append(i)
        return list_words


    def pattern_to_dictionary(self, pattern):
        dic_pattern = {}
        list_pattern = list(pattern)

        for i in list_pattern:
            if i not in dic_pattern:
                 dic_pattern[i] = len(dic_pattern) + 1
        return dic_pattern


    def sum_list_pattern(self, pattern):
        list_pattern = list(pattern)
        list_num = []

        for i in list_pattern:
            num = self.pattern_to_dictionary(pattern)[i]
            list_num.append(int(num))

        return reduce(self.add_str, list_num)


    def add_str(self, x, y):
        return str(x) + str(y)
        