class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        lstr = str.split(" ")
        mpattern = dict()
        mstr = dict()
        if(len(pattern)!=len(lstr)):
            return False
        for i in range(len(lstr)):
            if(pattern[i] not in mpattern):
                mpattern[pattern[i]] = -1
            if(lstr[i] not in mstr):
                mstr[lstr[i]] = -1
            if(mpattern[pattern[i]]!=mstr[lstr[i]]):
                return False
            mpattern[pattern[i]]  =i
            mstr[lstr[i]] = i
        return True
