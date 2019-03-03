class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = s.strip()
        result=""
        end = l = len(s)-1
        if(l==0):
            return s
        while(l>=0):
            if(s[l]==" " and end!=l):
                result+=s[l+1:end+1]
                result+=" "
                end=l
            elif(s[l]!=" " and l!=0):
                l-=1
            elif(s[l]==" " and end==l):
                end-=1
                l-=1
            elif(l==0 and s[l]!=" "):
                result+=s[l:end+1]
                l-=1
            else:
                l-=1
        return result
