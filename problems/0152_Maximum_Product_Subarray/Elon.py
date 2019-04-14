class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==1:
            return nums[0]
        tmpMax=0
        tmpMin=0
        Max=0
        for x in nums:
            if x > 0 :
                tmpMax,tmpMin=max(x,x*tmpMax),x*tmpMin
            elif x < 0 :
                tmpMax,tmpMin=x*tmpMin,min(x,x*tmpMax)
            else:
                tmpMax,tmpMin=0,0
            Max = max(Max,tmpMax)
        return Max