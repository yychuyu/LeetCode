class Solution:
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        def convert_to_index(word):
            word_indices = {}
            indices = [word_indices.setdefault(character, len(word_indices)) for character in word]
            return indices
        
        answers = [
            word for word in words if convert_to_index(word) == convert_to_index(pattern)
        ]
        return answers
