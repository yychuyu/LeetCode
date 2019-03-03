class Solution(object):
    def isPalindrome(self, s):
        if(len(s)==0 or len(s)==1):
            return True
        ss = [ch for ch in s.lower() if ch.isalpha() or ch.isdigit()]
        l = len(ss)
        for i in range(l/2):
            print(i,l-i-1)
            if(ss[i]!=ss[l-i-1]):
                return False
        return True
