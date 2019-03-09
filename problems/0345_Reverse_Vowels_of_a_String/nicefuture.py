class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = ['a','e','i','o','u','A','E','I','O','U']
        i=0
        j=len(s)-1
        l = list(s)  # python 字符串不可修改
        
        while i < j:
            while i < j and l[i] not in vowels:
                i += 1
            while i < j and l[j] not in vowels:
                j -= 1
            if i < j:
                l[i], l[j] = l[j], l[i]
                i += 1
                j -= 1
        
        s = ''.join(l)  # 所以这里用了一个并不优雅的方式
        return s
            
        
