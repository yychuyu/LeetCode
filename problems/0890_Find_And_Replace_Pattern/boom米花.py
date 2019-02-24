class Solution:
    def findAndReplacePattern(self, words, pattern):
        def match(word):
            tmp = {}
 
            for x, y in zip(pattern, word): 
                if tmp.setdefault(x, y) != y: return False

            return len(set(tmp.values())) == len(tmp.values()) 

        return list(filter(match, words)) 


if __name__ == '__main__':
    words = ['abc', 'deq', 'mee', 'aqq', 'dkd', 'ccc']
    pattern = 'abb'
    solu = Solution()
    print(solu.findAndReplacePattern(words, pattern))
