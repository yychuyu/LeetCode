class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        ns = list(s)
        vowels = ['a','e','i','o','u','A','E','I','O','U']
        front = 0
        later = len(ns)-1
        while(front<later):
            while(ns[front] not in vowels and front < later):
                front+=1
            while(ns[later] not in vowels and front < later):
                later-=1
            if later <= front:
                break
            ns[front],ns[later] = ns[later],ns[front]
            front+=1
            later-=1
