class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if(strs==[]):
            return ""
        first = strs[0]
        l=0
        flag=0
        while(l<len(first)):
            for item in strs:
                if(l>=len(item)):
                    flag=1
                    break
                if(item[l]!=first[l]):
                    flag=1
                    break
            if(flag==0):
                l+=1
            else:
                break
        return first[:l]
