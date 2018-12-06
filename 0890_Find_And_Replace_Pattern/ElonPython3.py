class Solution:
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        '''Solution1
        def is_iso(word):
            return len(word) == len(pattern) and len(set(word)) == len(set(pattern)) == len(set(zip(word, pattern)))
        return list(filter(is_iso, words))
        '''
        #Solution2
        result = []
        math_p = self.mathPattern(pattern)
        for word in words:
            if self.mathPattern(word) == math_p:
                result.append(word)
        return result
    
    
    def mathPattern(self, word):
        letterlist = ""
        res = ""

        index = 0
        for letter in word:
            if letter not in letterlist:
                letterlist += letter
                res += str(len(letterlist) + 1)
            else:
                res += str(letterlist.find(letter)+1)
        return res
        
    
        
        
        
        

                
            
