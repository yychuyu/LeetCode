class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        phrase = "1"
        for i in range(n-1):
            phrase = self.count(phrase)
        return phrase
            
    def count(self,phrase):
        count=0
        result=""
        curr = phrase[0]
        for i in phrase:
            if(i!=curr):
                result+=str(count)+curr
                count=1
                curr=i
            else:
                count+=1
        result +=str(count)+curr
        return result
