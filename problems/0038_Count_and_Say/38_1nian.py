class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if(n==1):
            return "1"
        else:
            return self.count(self.countAndSay(n-1))
    def count(self,phrase):
        result = ""
        count=0
        curr = phrase[0]
        for i in phrase:
            if(i!=curr):
                result+=str(count)+curr
                count=1
                curr=i
            else:
                count+=1
        result+=str(count)+curr
        return result
