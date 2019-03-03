class Solution:
"""
You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern. 

You may return the answer in any order.
Exam:
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
"""
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        def match(word):
            tmp = {}
            for x, y in zip(pattern, word): 
                if tmp.setdefault(x, y) != y:
                    return False
            return len(set(tmp.values())) == len(tmp.values())  

        return list(filter(match, words))
    
if __name__ == '__main__':
    words = ['abc', 'deq', 'mee', 'aqq', 'dkd', 'ccc']
    pattern = 'abb'
    solu = Solution()
    print(solu.findAndReplacePattern(words, pattern))
