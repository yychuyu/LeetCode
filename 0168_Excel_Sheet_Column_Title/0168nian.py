class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        result=""
        while(n!=0):
            if(n%26==0):
                result+="Z"
                n=n/26-1
            else:
                result+=chr(n%26+64)
                n=n/26
        return result[::-1]
