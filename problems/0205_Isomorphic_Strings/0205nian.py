class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s_count = dict()
        t_count = dict()
        for i in range(len(s)):
            # 如果字典中没有这个字符，则说明还没有进行过匹配，标为-1
            if(s_count.has_key(s[i])==False):
                s_count[s[i]] = -1    
            if(t_count.has_key(t[i])==False):
                t_count[t[i]] = -1
            if(s_count[s[i]]!=t_count[t[i]]):
                return False
            # 记录下这次匹配的两个字符的下标，用于下次匹配时做判断
            s_count[s[i]]=i
            t_count[t[i]]=i
        return True
