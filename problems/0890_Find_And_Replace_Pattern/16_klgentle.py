class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        """
        if word is one to one map return the word
        """
        ret = []
        lp = len(pattern)
        for word in words:
            if len(word) != lp:
                continue            
            if self.findPattern(word,pattern):
                ret.append(word)
        print(ret)    
        return ret
    
    def findPattern(self,word:str,pattern:str) -> bool:
        """
        judge if word is one to one map
        """
        d = {}
        for i in range(0,len(pattern)):
            k = pattern[i]
            if k not in d.keys():
                d[k] = word[i]
                # a and b map to the same letter
                if word[i] in word[:i]: 
                    return False
            else:
                # same key same value
                if d[k] != word[i]: 
                    return False
        return True
