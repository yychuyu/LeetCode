class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        hash_table = {e:index for index, e in enumerate(s)}
        flag=0
        for index,item in enumerate(s):
            if(index==hash_table[item]):
                flag=1
                return index
            else:
                hash_table[item]=-1
        if(flag==0):
            return -1
