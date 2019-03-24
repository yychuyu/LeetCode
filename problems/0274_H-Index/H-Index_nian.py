class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        citations.sort(reverse=True)
        maxH = 0
        for i in range(len(citations)):
            if(citations[i]>=i+1):
                maxH = i+1
        return maxH
