

class Solution:
    def findAndReplacePattern(self, words, pattern):
        
            ans = []
            pat_len = len(pattern)
            for w in words:
                if len(w) != pat_len:
                    continue
                mapping1, mapping2 = {}, {}
                flag = True
                for c1, c2 in zip(pattern, w):
                    mapping1.setdefault(c1, c2)
                    mapping2.setdefault(c2, c1) 
                    if mapping1[c1] != c2 or mapping2[c2] != c1:
                        flag = False
                        break
                ans += [w] if flag else []
            return ans