class Solution:
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        answer = [
            word for word in words
            if self.convert_to_index(word) == self.convert_to_index(pattern)
        ]
        return answer
    def convert_to_index(self, word):
        word_indices = {}
        indices = [
            word_indices.setdefault(character, len(word_indices))
            for character in word
        ]
        return indices