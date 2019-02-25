"""
You have a list of words and a pattern, and you want to know which words in
words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that
after replacing every letter x in the pattern with p(x), we get the desired
word.

Recall that a permutation of letters is a bijection from letters to letters:
    every letter maps to another letter, and no two letters map to the same
    letter.

Return a list of the words in words that match the given pattern.

You may return the answer in any order.
"""


class Solution:
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        def convert_to_index(word):
            word_indices = {}
            indices = [
                word_indices.setdefault(character, len(word_indices))
                for character in word
            ]
            return indices

        answer = [
            word for word in words
            if convert_to_index(word) == convert_to_index(pattern)
        ]

        return answer
